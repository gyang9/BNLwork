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
#include "TVector3.h"
#include <TVectorD.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TFrame.h>

using namespace std;

TString pmtLocation;
TString inputTxt;
TString inputTxt2;
TString outputTxt;
TString outputRoot;
int detMass;
bool ifOutputRoot = false;
double trueOriginX = 0, trueOriginY = 0, trueOriginZ = 800;
double trueDirX = 0, trueDirY = 0, trueDirZ = -1;
int evtNum = 10000;
int branchSelection = 0;
bool all_light = false;
bool true_light = false;
float vertexSmear = 0;
int scinPct = 0;
bool digitize = false;
float sometime = 0;
bool do2Dpdf = false;
int upperEvt = evtNum;
int lowerEvt = 0;

void parseArguments(int argc, char**argv)
{
  //cout<<"inside parse"<<endl;
  for (int iarg=0; iarg<argc; iarg++)
  {
    //cout<<iarg<<endl;
    if (string( argv[iarg])=="-h" || string( argv[iarg])=="--help" )
    {
      cout << "**************************************" << endl;
      cout << "Macros run options:" << endl;
      cout << "   -h || --help      Print help info." << endl;
      cout << "   -i || --input     Input event file in txt format" << endl;
      cout << "   -p || --pmt       Input pmt location file in txt format" << endl;
      cout << "   -o || --outTxt    Output txt file" << endl;
      cout << "   -r || --outRoot   Output root file" << endl;
      cout << "   -m || --detMass   Detector mass" << endl;
      cout << "   -n || --evtNum    Event number" << endl;
      cout << "   -b || --branch    Branch Selection (event branch 1; mc branch 0)" << endl;
      cout << "   -s || --smearV    vertex smearing" << endl;
      cout << "   -a || --allLight  if all light included" << endl;
      cout << "   -t || --trueLight if only true light included" << endl;
      cout << "   -c || --scinPct   Scintillator concentration" << endl;
      cout << "   --upper   	    event number upper limit" << endl;
      cout << "   --lower   	    event number lower limit" << endl;
      cout << "   --sometime        Adding some time to prompt time cut" << endl;
      cout << "   --digitize        Using digitized simulation" <<endl;
      cout << "   --2Dpdf           Doing 2D PDFs" <<endl;
      cout << "**************************************" << endl;
      exit(0);
    }
    else if (string( argv[iarg])=="-i" || string( argv[iarg])=="--input" )
    {
      iarg++;
      inputTxt = argv[iarg];
      if (inputTxt.Contains(".txt"))
      {
        cout << "Input txt file ok" << endl;
      }
      else {
        cerr << "input file must be a txt file!" << endl;
        exit(1);
      }
    }
    else if (string( argv[iarg])=="--input2" )
    {
      iarg++;
      inputTxt2 = argv[iarg];
      if (inputTxt2.Contains(".txt"))
      {
        cout << "Input txt file 2 ok" << endl;
      }
      else {
        cerr << "input file 2 must be a txt file!" << endl;
        exit(1);
      }
    }

    else if (string( argv[iarg])=="-p" || string( argv[iarg])=="--pmt" )
    {
      iarg++;
      pmtLocation = argv[iarg];
    }
    else if (string( argv[iarg])=="-o" || string( argv[iarg])=="--outTxt" )
    {
      iarg++;
      outputTxt = argv[iarg];
    }
    else if (string( argv[iarg])=="-r" || string( argv[iarg])=="--outRoot" )
    {
      iarg++;
      outputRoot = argv[iarg];
      ifOutputRoot = true;
    }
    else if (string( argv[iarg])=="-m" || string( argv[iarg])=="--mass" )
    {
      iarg++;
      detMass = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="-n" || string( argv[iarg])=="--evtNum" )
    {
      iarg++;
      evtNum = atoi(argv[iarg]);
    }    
    else if (string( argv[iarg])=="-b" || string( argv[iarg])=="--branch" )
    {
      iarg++;
      branchSelection = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="-s" || string( argv[iarg])=="--smearV" )
    {
      iarg++;
      vertexSmear = atof(argv[iarg]);
    }    
    else if (string( argv[iarg])=="-a" || string( argv[iarg])=="--allLight" )
    {
      all_light = true;
    }
    else if (string( argv[iarg])=="-t" || string( argv[iarg])=="--trueLight" )
    {
      true_light = true;
    }
    else if (string( argv[iarg])=="--upper" )
    {
      iarg++;
      upperEvt = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="--lower" )
    {
      iarg++;
      lowerEvt = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="-c" || string( argv[iarg])=="--scinPct" )
    {
      iarg++;
      scinPct = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="--sometime" )
    {
      iarg++;
      sometime = atof(argv[iarg]);
    }
    else if (string( argv[iarg])=="--digitize" )
    {
      digitize = true;
    }    
    else if (string( argv[iarg])=="--2Dpdf" )
    {
      do2Dpdf = true;
    }    
  }
}


int main(int argc, char**argv){
//int main(){

  parseArguments( argc, argv);
  cout<<"intput and output txt : "<<inputTxt.Data()<<" "<<outputTxt.Data()<<endl;
  if (ifOutputRoot) cout<<"output root file : "<<outputRoot.Data()<<endl;
  cout<<"pmt location and detector mass : "<<pmtLocation.Data()<<" "<<detMass<<endl;

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
    //cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" "<<ee<<endl;
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
  TFile* outfile;
  TTree tree("tree","tree");
  double trueDir[3], recoDir[3];
  int nPMT; double PMTid[264][3]; double PMTtime[264]; double PMTangle[264];

  if (ifOutputRoot){
    outfile = TFile::Open( outputRoot.Data(), "recreate");
    tree.Branch("trueDir",&trueDir,"trueDir[3]/D");
    tree.Branch("recoDir",&recoDir,"recoDir[3]/D");
    tree.Branch("nPMT",&nPMT,"nPMT/I");
    tree.Branch("PMTid",&PMTid,"PMTid[264][3]/D");
    tree.Branch("PMTtime",&PMTtime,"PMTtime[264]/D");
    tree.Branch("PMTangle",&PMTangle,"PMTangle[264]/D");
  }

  std::vector<std::vector<double> > pmtlist;
  std::vector<std::vector<std::vector<double> > > fitlist(200000);
  ifstream in2;
  ifstream in22;
  //in2.open(Form("eventPMT_%dton_%dpct_full.root.txt",atoi(argv[1]),atoi(argv[2])));
  //cout<<"reading file "<<Form("eventPMT_%dton_%dpct_full.root.txt",atoi(argv[1]),atoi(argv[2]))<<endl;
  in2.open(inputTxt.Data());
  cout<<"reading file "<<inputTxt.Data()<<endl;

  in22.open(inputTxt2.Data());
  cout<<"reading file "<<inputTxt2.Data()<<endl;

  int aaa,bbb,ddd,eee;
  double ccc;
  int current=0;
  int counter[200000]={};
  double iniX[200000] = {};
  double iniY[200000] = {};
  double iniZ[200000] = {};

  if (digitize && branchSelection == 0 ){
    cout<<"  --- be careful! You can't do digitization and true branch at the same time !! ---"<<endl;
    exit(0);
  }
  while (!in22.eof() ){
    in22>>aaa>>bbb>>ccc>>ddd>>eee;
    cout<<aaa<<" "<<bbb<<" "<<ccc<<" "<<ddd<<" "<<eee<<endl;
    if(aaa > evtNum) continue;
    if (true_light && ddd != 0) continue;
    if (eee != branchSelection ) continue;

    std::vector<double> pmtloc;
    pmtloc.push_back(pmtx[bbb]);
    pmtloc.push_back(pmty[bbb]);
    pmtloc.push_back(pmtz[bbb]);
    pmtloc.push_back(ccc);
    double locX = trueOriginX + gRandom->Gaus(0, vertexSmear);
    double locY = trueOriginY + gRandom->Gaus(0, vertexSmear);
    double locZ = trueOriginZ + gRandom->Gaus(0, vertexSmear);
    pmtloc.push_back(locX); pmtloc.push_back(locY); pmtloc.push_back(locZ);
    pmtloc.push_back(0); pmtloc.push_back(TMath::Pi()/2.); pmtloc.push_back(0);
    pmtlist.push_back(pmtloc);
    pmtloc.clear();
  }


  while (!in2.eof() ){
    in2>>aaa>>bbb>>ccc>>ddd>>eee;
    cout<<aaa<<" "<<bbb<<" "<<ccc<<" "<<ddd<<" "<<eee<<endl;
    if(aaa > evtNum) continue;
    if (true_light && ddd != 0) continue;
    if (eee != branchSelection ) continue;

    std::vector<double> pmtloc;
    pmtloc.push_back(pmtx[bbb]);
    pmtloc.push_back(pmty[bbb]);
    pmtloc.push_back(pmtz[bbb]);
    pmtloc.push_back(ccc);
    double locX = trueOriginX + gRandom->Gaus(0, vertexSmear); 
    double locY = trueOriginY + gRandom->Gaus(0, vertexSmear); 
    double locZ = trueOriginZ + gRandom->Gaus(0, vertexSmear);
    pmtloc.push_back(locX); pmtloc.push_back(locY); pmtloc.push_back(locZ);
    pmtloc.push_back(0); pmtloc.push_back(TMath::Pi()/2.); pmtloc.push_back(0);
    //pmtlist.push_back(pmtloc);
    if (aaa>= lowerEvt && aaa< upperEvt && eee == 1){
    fitlist[aaa].push_back(pmtloc);
    if (iniX[aaa] == 0 && iniY[aaa] == 0 && iniZ[aaa] == 0)
      iniX[aaa] = pmtx[bbb]; iniY[aaa] = pmty[bbb]; iniZ[aaa] = pmtz[bbb]; 
    }
    pmtloc.clear();
    counter[aaa]++;
  }
  cout<<"event induced PMT loaded "<<endl;
  //for (int i=0;i<1000;i++)
  //  hc->Fill(counter[i]);

  RooFitResult* res;
  char formula[10];
  dirFit * rep = new dirFit ("_rep");
  
  // 1 ton time cut 4.5, 2.4 ton time cut 5.5, 5 ton time cut 6.5
  cout<<"doing digitize ? "<<digitize<<"  adding sometime ? "<<sometime<<endl;

  if (!digitize){
    if (detMass == 1)
      //rep->SetPromptCut(4.5+sometime);
      rep->SetPromptCut(4.5+sometime/10.);
      //rep->SetPromptCut(5.5);
    if (detMass == 2)
      rep->SetPromptCut(5.5+sometime/10.);
    if (detMass == 3)
      rep->SetPromptCut(6+sometime/10.);
    if (detMass == 5 || detMass == 4)
      //rep->SetPromptCut(6.5+sometime);
      rep->SetPromptCut(6.5+sometime/10.);  
  }
  else{
      rep->SetPromptCut(1.01+sometime/10.);
  }

  rep->SetIfDo2dpdf(false);
  if (do2Dpdf) rep->SetIfDo2dpdf(true);
  //if (all_light)
    //rep->SetPromptCut(10);

  cout<<"reading processing events"<<endl;
  std::vector<double> iniVertex(3);
  wbPDF* pdfs =  rep->Reading_Processing_Events(pmtlist,"pdf", iniVertex, do2Dpdf, false, false );
  rep->SetPDFs(pdfs);
  cout<<"getting pdfs"<<endl;
  TH1F* timepdf = pdfs->GetTimePDF();
  TH1F* thetapdf = pdfs->GetThetaPDF();
  TH2F* timeThetapdf = pdfs->GetTimeThetaPDF();
  cout<<"pdf obtained"<<endl;
/*
  //outfile->Close();
  TFile* f; 
  if (!do2Dpdf){	  
    if (true_light)
      f = TFile::Open(Form("finepdf_truelight_event_%dton_%dpct_scintillator.root", detMass, scinPct),"recreate");
    if (all_light)
      f = TFile::Open(Form("finepdf_alllight_event_%dton_%dpct_scintillator.root", detMass, scinPct),"recreate");
    if (!true_light && !all_light)
      f = TFile::Open(Form("finepdf_timecut_event_%dton_%dpct_scintillator.root", detMass, scinPct),"recreate");
    //if (branchSelection == 1 && (all_light == 1 || true_light == 1)) { cout<<"something wrong in the input. "<<endl; exit(0);}
    //if (all_light && !true_light) f = TFile::Open(Form("finepdf_alllight_event_%dton_%dpct.root", detMass, scinPct),"recreate");
    //if (all_light && true_light) f = TFile::Open(Form("finepdf_truelight_event_%dton_%dpct.root", detMass, scinPct),"recreate");
    //if (branchSelection == 1) f = TFile::Open(Form("finepdf_timecut_event_%dton_%dpct.root", detMass, scinPct),"recreate");
    timepdf->Write("timepdf");
    thetapdf->Write("thetapdf");
    exit(0);
  }
  else {
    if (true_light)
      f = TFile::Open(Form("finepdf_truelight_event_%dton_%dpct_2Dpdf.root", detMass, scinPct),"recreate");
    if (all_light)
      f = TFile::Open(Form("finepdf_alllight_event_%dton_%dpct_2Dpdf.root", detMass, scinPct),"recreate");
    if (!true_light && !all_light)
      f = TFile::Open(Form("finepdf_timecut_event_%dton_%dpct_2Dpdf.root", detMass, scinPct),"recreate");
    //if (branchSelection == 1 && (all_light == 1 || true_light == 1)) { cout<<"something wrong in the input. "<<endl; exit(0);}
    //if (all_light && !true_light) f = TFile::Open(Form("finepdf_alllight_event_%dton_%dpct.root", detMass, scinPct),"recreate");
    //if (all_light && true_light) f = TFile::Open(Form("finepdf_truelight_event_%dton_%dpct.root", detMass, scinPct),"recreate");
    //if (branchSelection == 1) f = TFile::Open(Form("finepdf_timecut_event_%dton_%dpct.root", detMass, scinPct),"recreate");
    timeThetapdf->Write("timethetapdf");
    f->Close();
    exit(0);  
  }
*/
  //TCanvas* c1 = new TCanvas();
  //timepdf->Draw();

  //TCanvas* c2 = new TCanvas();
  //thetapdf->Draw();
  //c1->SaveAs("timepdf.png");
  //c2->SaveAs("thetapdf.png");

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

  for (Int_t aaa = lowerEvt;aaa< upperEvt; aaa++){

    wbPDF* nothing =  rep->Reading_Processing_Events(fitlist[aaa],"event", iniVertex, do2Dpdf, false, false );

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

    if (ifOutputRoot){
      recoDir[0] = rep->getParVar(0)->getVal();
      recoDir[1] = rep->getParVar(1)->getVal();
      recoDir[2] = rep->getParVar(2)->getVal();
      trueDir[0] = trueDirX;
      trueDir[1] = trueDirY;
      trueDir[2] = trueDirZ;
      nPMT = fitlist[aaa].size();
      for (int i = 0; i<fitlist[aaa].size(); i++){
        PMTid[i][0] = fitlist[aaa].at(i).at(0);
        PMTid[i][1] = fitlist[aaa].at(i).at(1);
        PMTid[i][2] = fitlist[aaa].at(i).at(2);
        PMTtime[i] = fitlist[aaa].at(i).at(3);	
	TVector3 temp1  (PMTid[i][0] - trueOriginX, PMTid[i][1] - trueOriginY, PMTid[i][2] - trueOriginZ);
	TVector3 temp2  (trueDirX, trueDirY, trueDirZ);
	PMTangle[i] = temp1.Angle(temp2);
      }
      tree.Fill();
    }

    //if (res->status() == 0 ){
    cout<<"abs(bestFit) "<<abs(bestFit)<<" "<<" abs(rep->getParVar(0)->getVal()) "<<abs(rep->getParVar(0)->getVal())<<endl;
    if (abs(bestFit) > 0 && abs(rep->getParVar(0)->getVal())>0 ){
      cout<<rep->getParVar(0)->getVal()<<" "<<rep->getParVar(1)->getVal()<<" "<<rep->getParVar(2)->getVal()<<" "<<bestFit<<endl;
      out<<rep->getParVar(0)->getVal()<<" "<<rep->getParVar(1)->getVal()<<" "<<rep->getParVar(2)->getVal()<<" "<<bestFit<<endl;
    }
    //}
  }
  if (ifOutputRoot){ 
    timepdf->Write("timepdf");
    thetapdf->Write("thetapdf");	  
    tree.Write(); 
    outfile->Write();
  }
}


