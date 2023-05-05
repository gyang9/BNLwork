#include "dirFit.hh"
#include "TMath.h"
#include "TH3F.h"

#include "RooArgList.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include "RooRealVar.h"
#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "TString.h"
#include <TVectorD.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TFrame.h>

using namespace std;

TString pmtLocation;
TString inputTxt;
TString outputTxt;
TString outputRoot;
int detMass;

//int main(int argc, char**argv){
int RunDirFit(){

  TH3F* h3 = new TH3F("","", 100,-1200,1200, 100, -1200,1200,100,-1200,1200);
  TH3F* h4 = new TH3F("","", 100,-1200,1200, 100, -1200,1200,100,-1200,1200);

  TH1F* hc = new TH1F("","",50,0,50);  
  TH1F* hhx[1000];
  TH1F* hhz[1000];
  for (int i=0;i<1000;i++){
    hhx[i] = new TH1F("","",20,0,1);
    hhz[i] = new TH1F("","",20,-1200,1200);
  }

  ifstream in;
  //in.open(Form("pmtlocation_%dton.txt", atoi(argv[1])) );
  in.open(pmtLocation.Data());
  double pmtx[264]={};
  double pmty[264]={};
  double pmtz[264]={};

  int aa, ee;
  double bb,cc,dd;
  while (!in.eof()){
    in>>aa>>bb>>cc>>dd>>ee;
    cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" "<<ee<<endl;
    pmtx[aa] = bb;
    pmty[aa] = cc;
    pmtz[aa] = dd;
    //h3->Fill(bb,cc,dd,1);
  }

  //new TCanvas();
  //h3->SetMarkerSize(1.5);
  //h3->SetMarkerStyle(4);
  //h3->Draw();

  //TFile* outfile = TFile::Open(Form("output_ntuple_%dton_%dpct_full.root",atoi(argv[1]),atoi(argv[2]) ), "recreate");
  TFile* outfile = TFile::Open( outputRoot.Data(), "recreate");
  TTree tree("tree","tree");
  double trueDir[3], recoDir[3];
  int nPMT; double PMTid[264]; double PMTtime[264]; double PMTangle[264];
  tree.Branch("trueDir",&trueDir);
  tree.Branch("recoDir",&recoDir);
  tree.Branch("nPMT",&nPMT);
  tree.Branch("PMTid",&PMTid);
  tree.Branch("PMTtime",&PMTtime);
  tree.Branch("PMTangle",&PMTangle);

  std::vector<std::vector<double> > pmtlist;
  std::vector<std::vector<std::vector<double> > > fitlist(10000);
  ifstream in2;
  //in2.open(Form("eventPMT_%dton_%dpct_full.root.txt",atoi(argv[1]),atoi(argv[2])));
  //cout<<"reading file "<<Form("eventPMT_%dton_%dpct_full.root.txt",atoi(argv[1]),atoi(argv[2]))<<endl;
  in2.open(inputTxt.Data());
  cout<<"reading file "<<inputTxt.Data()<<endl;

  int aaa,bbb,ddd,eee;
  double ccc;
  int current=0;
  int counter[10000]={};
  double iniX[10000] = {};
  double iniY[10000] = {};
  double iniZ[10000] = {};

  while (!in2.eof() ){
    // event id, pmt id, time, light category  
    in2>>aaa>>bbb>>ccc>>ddd>>eee;
    //if (aaa != atoi(argv[1])) continue;
    //if (ddd != 0) continue;
    if (eee == 1 ) continue;
    // event branch eee == 1;  mc branch eee == 0
    std::vector<double> pmtloc;
    pmtloc.push_back(pmtx[bbb]);
    pmtloc.push_back(pmty[bbb]);
    pmtloc.push_back(pmtz[bbb]);
    pmtloc.push_back(ccc);
    //double locX = gRandom->Gaus();
    double locX = 0; double locY = 0; double locZ = 0;
    // true location x, y, z
    pmtloc.push_back(locX); pmtloc.push_back(locY); pmtloc.push_back(locZ);
    // true time, theta, phi
    pmtloc.push_back(0); pmtloc.push_back(TMath::Pi()/2.); pmtloc.push_back(0);
    pmtlist.push_back(pmtloc);
    fitlist[aaa].push_back(pmtloc);
    if (iniX[aaa] == 0 && iniY[aaa] == 0 && iniZ[aaa] == 0)
      iniX[aaa] = pmtx[bbb]; iniY[aaa] = pmty[bbb]; iniZ[aaa] = pmtz[bbb];
/*
    _hitlist[i].x = num[i].at(0);
    _hitlist[i].y = num[i].at(1);
    _hitlist[i].z = num[i].at(2);
    _hitlist[i].t = num[i].at(3);
    _hitlist[i].trX = num[i].at(4);
    _hitlist[i].trY = num[i].at(5);
    _hitlist[i].trZ = num[i].at(6);
    _hitlist[i].trTime = num[i].at(7);
    _hitlist[i].trTheta = num[i].at(8);
    _hitlist[i].trPhi = num[i].at(9);
*/
    pmtloc.clear();
    //h4->Fill(pmtx[bbb],pmty[bbb],pmtz[bbb]);
    //hhx[0] -> Fill (pmty[bbb]/TMath::Sqrt(pmtx[bbb]*pmtx[bbb]+pmty[bbb]*pmty[bbb] ));
    //hhz[aaa] -> Fill (pmtz[bbb]);
    counter[aaa]++;
  }
  cout<<"event induced PMT loaded "<<endl;
  //for (int i=0;i<1000;i++)
  //  hc->Fill(counter[i]);

  RooFitResult* res;
  char formula[10];
  dirFit * rep = new dirFit ("_rep");

  // 1 ton time cut 4.5, 2.4 ton time cut 5.5, 5 ton time cut 6.5

  if (detMass == 1)
    rep->SetPromptCut(4.5);
  if (detMass == 2)
    rep->SetPromptCut(5.5);
  if (detMass == 5 || detMass == 4)
    rep->SetPromptCut(6.5);  

  //rep->SetPromptCut(1e9);
  cout<<"reading processing events"<<endl;
  std::vector<double> iniVertex(3);
  wbPDF* pdfs =  rep->Reading_Processing_Events(pmtlist,"pdf", iniVertex );
  rep->SetPDFs(pdfs);
  cout<<"getting pdfs"<<endl;
  TH1F* timepdf = pdfs->GetTimePDF();
  TH1F* thetapdf = pdfs->GetThetaPDF();
  cout<<"pdf obtained"<<endl;

  //TFile* f = TFile::Open(Form("finepdf_alllight_event_%dton_%dpct.root",atoi(argv[1]),atoi(argv[2])),"recreate");
  //timepdf->Write("timepdf");
  //thetapdf->Write("thetapdf");
  //exit(1);

  TCanvas* c1 = new TCanvas();
  timepdf->Draw();

  TCanvas* c2 = new TCanvas();
  thetapdf->Draw();
  c1->SaveAs("timepdf.png");
  c2->SaveAs("thetapdf.png");

/*  
  cout<<"start to set up a target event "<<endl;
  ifstream in3;
  in3.open(Form("eventPMT_%dton_%dpct.root.txt",atoi(argv[1]),atoi(argv[2])));

  int count = 0;
  double iniX = 0;
  double iniY = 0;
  double iniZ = 0;
  while (!in3.eof() ){
    // event id, pmt id, time, light category  
    in3>>aaa>>bbb>>ccc>>ddd;
    if (count == 0) {iniX = pmtx[bbb]; iniY = pmty[bbb]; iniZ = pmtz[bbb]; }
    count ++ ;
    if (aaa != atoi(argv[3])) continue;
    //if (ddd != 0) continue;
    std::vector<double> pmtloc;
    pmtloc.push_back(pmtx[bbb]);
    pmtloc.push_back(pmty[bbb]);
    pmtloc.push_back(pmtz[bbb]);
    pmtloc.push_back(ccc);
    fitlist.push_back(pmtloc);
    pmtloc.clear();
  }
  wbPDF* nothing =  rep->Reading_Processing_Events(fitlist,"event", iniVertex );
*/
  //rep->SetVertex(0,0,0);
  //rep->SetDetectorSize (1100,1100);

  for (Int_t aaa = 0;aaa< 10000; aaa++){

    wbPDF* nothing =  rep->Reading_Processing_Events(fitlist[aaa],"event", iniVertex );

    RooArgList list("list");
    list.add(*rep);
    sprintf(formula,"%s","@0");
    RooFormulaVar* fcn = new RooFormulaVar("fit","fit",formula,list);

    rep->getParVar(0)->setConstant(false);
    rep->getParVar(1)->setConstant(false);
    rep->getParVar(2)->setConstant(false);

    rep->getParVar(0)->setVal(iniX[aaa]/ sqrt(iniX[aaa]*iniX[aaa]+iniY[aaa]*iniY[aaa]+iniZ[aaa]*iniZ[aaa]));  
    rep->getParVar(1)->setVal(iniY[aaa]/ sqrt(iniX[aaa]*iniX[aaa]+iniY[aaa]*iniY[aaa]+iniZ[aaa]*iniZ[aaa]));
    rep->getParVar(2)->setVal(iniZ[aaa]/ sqrt(iniX[aaa]*iniX[aaa]+iniY[aaa]*iniY[aaa]+iniZ[aaa]*iniZ[aaa]));

    ofstream out;
    //out.open(Form("output_result_timecut_finepdf_%dton_%dpct_full.txt",atoi(argv[1]),atoi(argv[2])),std::ofstream::out | std::ofstream::app);
    out.open(outputTxt.Data(), std::ofstream::out | std::ofstream::app);
/*
  double finalRes = 1e9;
  double dirX = -1, dirY = -1, dirZ = -1;
  double scanningSize = 10;
  for (int i=0;i<scanningSize * 2;i++){
    for (int j=0;j<scanningSize * 2;j++){
      for (int k=0;k<scanningSize * 2;k++){
        rep->getParVar(0)->setVal(-1* i/scanningSize + 1);
	rep->getParVar(1)->setVal(-1* j/scanningSize + 1);
	rep->getParVar(2)->setVal(-1* k/scanningSize + 1);
	if (i == scanningSize && j == scanningSize && k == scanningSize) continue;
	double currRes = rep-> directionMatching (rep->getPullList(), false);
	//cout<<":::::::::::::::::::::::::::::::::::::::: "<<i<<" "<<j<<" "<<k<<" "<<-1* i/scanningSize + 1<<" "<<-1* j/scanningSize + 1<<" "<<-1* k/scanningSize + 1<<" "<<currRes<<endl;
	if (currRes < finalRes){
	  finalRes = currRes;
	  dirX = -1* i/scanningSize + 1;
	  dirY = -1* j/scanningSize + 1;
	  dirZ = -1* k/scanningSize + 1;
	}
      }
    }
  }
  double squareSum = sqrt(dirX*dirX + dirY*dirY + dirZ*dirZ);
  cout<<"final result "<<finalRes<<"  with x y z direction:  "<<dirX/squareSum<<" "<<dirY/squareSum<<" "<<dirZ/squareSum<<endl;
  //cout<<dirX/squareSum<<" "<<dirY/squareSum<<" "<<dirZ/squareSum<<" "<<finalRes<<endl;
  out<<dirX/squareSum<<" "<<dirY/squareSum<<" "<<dirZ/squareSum<<" "<<finalRes<<endl;
*/
    //rep->getParVar(0)->setVal(5);
    //cout<<"setting function"<<endl;
    RooMinuit m(*fcn);
    m.setStrategy(2);
    Double_t callsEDM[2] = {10500., 1.e-6};
    Int_t irf = 0;

    //cout<<"ready to perform the fit"<<endl;
    gMinuit->mnexcm("MIGRAD",callsEDM,2,irf);
    m.migrad();
    //m.hesse();
    //m.minos();
    res = m.save();
    double bestFit = res->minNll();
    std::cout<<"fit status code is : "<< res->status()<<std::endl;
    cout<<"directional results: "<<rep->getParVar(0)->getVal()<<" "<<rep->getParVar(1)->getVal()<<" "<<rep->getParVar(2)->getVal()<<endl;

    if (res->status() == 0 ){
      out<<rep->getParVar(0)->getVal()<<" "<<rep->getParVar(1)->getVal()<<" "<<rep->getParVar(2)->getVal()<<" "<<bestFit<<endl;
    }
  }
}


