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
TString outputTxt;
TString outputRoot;
TString pdf_filename; 
int detMass;
bool ifOutputRoot = false;
double trueOriginX = 0, trueOriginY = 0, trueOriginZ = 0;
double trueDirX = 0, trueDirY = 0, trueDirZ = -1;
int evtNum = 10000;
int branchSelection = 0;
bool inNtuple = false;
bool all_light = false;
bool true_light = false;
float vertexSmear = 0;
int scinPct = 0;
bool digitize = false;
bool oTxt = true;
float sometime = 0;
bool do2Dpdf = false;
bool doCharge = false;
bool doCos = false;
bool doScan = false;
bool doFitVertex = false;
int upperEvt = evtNum;
int lowerEvt = 0;
int orient=0;
int specialConfig = 0;
int nbins = 10;
double zlowercut = 1e6;
bool perPMT = false;
int evtBase = 0;
bool externalPDF = false;
bool do3D = false;
bool perDir = false;
double timeInterval = 0.5;
double uppertime = 5;
int hitNumLimit = 1e6;
int npmt_bin = 252; 
int ntime_bin = 30;
int ndir_bin = 400;
float timeCorrection = 0;
bool debug = false;
int yinput = 0;
int xinput = 0;

int allhit_id[3000];
double allhit_x[3000];
double allhit_y[3000];
double allhit_z[3000];
double allhit_t[3000];
int firsthit_id[3000];
double firsthit_x[3000];
double firsthit_y[3000];
double firsthit_z[3000];
double firsthit_t[3000];

float col1sum;
float col2sum;
float col3sum;
float col4sum;
float botsum;
float row1sum;
float row2sum;
float row3sum;
float row4sum;
float col1sumc;
float col2sumc;
float col3sumc;
float col4sumc;
float botsumc;
float row1sumc;
float row2sumc;
float row3sumc;
float row4sumc;
float indpmt[46];

void parseArguments(int argc, char**argv)
{
  cout<<"inside parse"<<endl;
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
      cout << "   --orient          PDF building orientation, -999 means isotropic" <<endl;
      cout << "   --charge          Doing charge ?" <<endl;
      cout << "   --cos             PDF in cos ?" <<endl;
      cout << "   --scanning        Using space scanning instead of MINUIT?" <<endl;
      cout << "   --originZ         Z location of the source" <<endl;
      cout << "   --specialConfig   Special configuration? Any numbers not 1-4 means no special config." <<endl;
      cout << "   --nbins           Number of bins in PDF "<<endl;
      cout << "   --zlowercut       Z hit location lower cut? Ignore if don't want such a cut" <<endl;
      cout << "   --fitVertex       Fitting vertex at the same time?" <<endl;
      cout << "   --perPMT          Run per-PMT likelihood?" <<endl;
      cout << "   --externalPDF     Input PDF for fitting" <<endl;
      cout << "   --do3D            Do we want time slice? Always set this!" <<endl;
      cout << "   --perDir          Per-direction fit? This is the best so far." <<endl;
      cout << "   --timeInterval    What is the time step?" <<endl;
      cout << "   --uppertime       Upper limit for the residual time?" <<endl;
      cout << "   --hitNumLimit     Upper limit for the number of hits" <<endl;
      cout << "   --npmt            How many pmts in the detector? " <<endl;
      cout << "   --ntime           Number of bins for the time dimension" <<endl;
      cout << "   --ndir            Number of direction options" <<endl;
      cout << "   --timeCorrection     Time correction for all the residual time" <<endl;
      cout << "   --input_ntuple    input format is ntuple" <<endl;
      cout << "**************************************" << endl;
      exit(0);
    }


    else if (string( argv[iarg])=="-i" || string( argv[iarg])=="--input" )
    {
      iarg++;
      inputTxt = argv[iarg];
      if (inputTxt.Contains(".txt") || inputTxt.Contains(".root"))
      {
        cout << "Input txt file ok" << endl;
      }
      else {
        cerr << "input file must be a txt or ntuple file!" << endl;
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
      oTxt = true;
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
    else if ( string( argv[iarg])=="--evtBase" )
    {
      iarg++;
      evtBase = atoi(argv[iarg]);
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
    else if (string( argv[iarg])=="--orient" )
    {
      iarg++;
      orient = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="--digitize" )
    {
      digitize = true;
    }    
    else if (string( argv[iarg])=="--2Dpdf" )
    {
      do2Dpdf = true;
    }   
    else if (string( argv[iarg])=="--charge" )
    {
      doCharge = true;
    }
    else if (string( argv[iarg])=="--cos" )
    {
      doCos = true;
    }
    else if (string( argv[iarg])=="--scanning" )
    {
      doScan = true;
    }
    else if (string( argv[iarg])=="--originX" )
    {
      iarg++;
      trueOriginX = atof(argv[iarg]);
    }
    else if (string( argv[iarg])=="--originY" )
    {
      iarg++;
      trueOriginY = atof(argv[iarg]);
    }    
    else if (string( argv[iarg])=="--originZ" )
    {
      iarg++;
      trueOriginZ = atof(argv[iarg]);
    }
    else if (string( argv[iarg])=="--specialConfig" )
    {
      iarg++;
      specialConfig = atof(argv[iarg]);
    }
    else if (string( argv[iarg])=="--nbins" )
    {
      iarg++;
      nbins = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="--zlowercut" )
    {
      iarg++;
      zlowercut = atof(argv[iarg]);
    }
    else if (string( argv[iarg])=="--fitVertex" )
    {
      doFitVertex = true;
    }
    else if (string( argv[iarg])=="--perPMT" )
    {
      perPMT = true;
    }
    else if (string( argv[iarg])=="--externalPDF" )
    {
      externalPDF = true;
      iarg++;
      pdf_filename = argv[iarg];
    }
    else if (string( argv[iarg])=="--do3D" )
    {
      do3D = true;
    }
    else if (string( argv[iarg])=="--perDir" )
    {
      perDir = true;
    }    
    else if (string( argv[iarg])=="--timeInterval" )
    {
      iarg++;
      timeInterval = atof(argv[iarg]);
    }

    else if (string( argv[iarg])=="--uppertime" )
    {
      iarg++;
      uppertime = atof(argv[iarg]);
    }
    
    else if (string( argv[iarg])=="--hitNumLimit" )
    {
      iarg++;
      hitNumLimit = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="--npmt" )
    {
      iarg++;
      npmt_bin = atoi(argv[iarg]);
    }    
    else if (string( argv[iarg])=="--ntime" )
    {
      iarg++;
      ntime_bin = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="--ndir" )
    {
      iarg++;
      ndir_bin = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="--timeCorrection" )
    {
      iarg++;
      timeCorrection = atof(argv[iarg]);
    }
    else if (string( argv[iarg]) == "--input_ntuple" ){
      inNtuple = true;
    }
    else if (string( argv[iarg]) == "--debug" ){
      debug = true;
    }
    else if (string( argv[iarg])=="--yinput" )
    {
      iarg++;
      yinput = atoi(argv[iarg]);
    }
    else if (string( argv[iarg])=="--xinput" )
    {
      iarg++;
      xinput = atoi(argv[iarg]);
    }
  }
}

int main(int argc, char**argv){
//int main(){

  cout<<"starting.."<<endl;
  parseArguments( argc, argv);
  if (ifOutputRoot) cout<<"output root file : "<<outputRoot.Data()<<endl;
  cout<<"pmt location and detector mass : "<<pmtLocation.Data()<<" "<<detMass<<endl;

  //if (ifOutputRoot) {cout<<"output root is not supported!"<<endl; exit(1);}
  if (perPMT || !perDir) {cout<<"only support perDir!"<<endl; exit(1);}
  if (sometime< 8) {cout<<"too short sometime setup"<<endl; exit(1);}

  TFile* outfile;  
  std::vector<std::vector<double> > pmtlist;
  std::vector<std::vector<std::vector<double> > > fitlist(10000);
  double ggg[10000],hhh[10000],mmm[10000];
  double iniX[10000] = {};
  double iniY[10000] = {};
  double iniZ[10000] = {};
  int eventTaker[10000] = {};
  int bbb;

  ifstream in;
  //in.open(Form("pmtlocation_%dton.txt", atoi(argv[1])) );
  in.open(pmtLocation.Data());
  double pmtx[264]={};
  double pmty[264]={};
  double pmtz[264]={};

  int aa, ee;
  double bb,cc,dd;
  if (!inNtuple){
    while (!in.eof()){
      in>>aa>>bb>>cc>>dd>>ee;
      pmtx[aa] = bb;
      pmty[aa] = cc;
      pmtz[aa] = dd;
    }
  }

  TH1F* h_times = new TH1F("","",100,-5,15);
  TH1F* h_timec = new TH1F("","",125,-10,15);
  TH1F* h_pmtzs = new TH1F("","",30,-1500,1500);
  TH1F* h_pmtzc = new TH1F("","",30,-1500,1500);
  TH1F* h_charges = new TH1F("","",200,0,1000);
  TH1F* h_chargec = new TH1F("","",200,0,1000);
  TH1F* h_mcpcount = new TH1F("","",300,0,300);
  TH1F* h_mcpecount = new TH1F("","",600,0,600);
  TH1F* h_mcnhits = new TH1F("","",300,0,300);
  TH1F* h_mcpecountc = new TH1F("","",600,0,600);
  TH1F* h_mcnhitsc = new TH1F("","",300,0,300);
  TH2F* h_timeVSprocess = new TH2F("","",100,-5,15,5,0,5);
  TH2F* h_timeVSpos = new TH2F("","",100,-10,15,30,-1500,1500);

  cout<<"inNtuple "<<inNtuple<<endl;
  /////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////// using the ntuple input file
  // PDF:
  // 1. pmt locx 2. pmt locy 3. pmt locz 4. time 5. true locx 6. true locy 7. true locz
  //                         |  pmt id
  // 8. constant 0 9. theta 10. phi 11. charge 
  // fitting:
  // same thing

  if(inNtuple){
    //read_ntuple(inputTxt.Data());
      
    TFile f(Form("bnl1t_1pct_x_%d_y_%d_muon_oldwater.root",xinput,yinput));
    TTree* tree = (TTree*) f.Get("tree");

    tree->SetBranchAddress("col1sum",&col1sum);
    tree->SetBranchAddress("col2sum",&col2sum);
    tree->SetBranchAddress("col3sum",&col3sum);
    tree->SetBranchAddress("col4sum",&col4sum);
    tree->SetBranchAddress("botsum",&botsum);

    tree->SetBranchAddress("row1sum",&row1sum);
    tree->SetBranchAddress("row2sum",&row2sum);
    tree->SetBranchAddress("row3sum",&row3sum);
    tree->SetBranchAddress("row4sum",&row4sum);

    tree->SetBranchAddress("col1sumc",&col1sumc);
    tree->SetBranchAddress("col2sumc",&col2sumc);
    tree->SetBranchAddress("col3sumc",&col3sumc);
    tree->SetBranchAddress("col4sumc",&col4sumc);
    tree->SetBranchAddress("botsumc",&botsumc);

    tree->SetBranchAddress("row1sumc",&row1sumc);
    tree->SetBranchAddress("row2sumc",&row2sumc);
    tree->SetBranchAddress("row3sumc",&row3sumc);
    tree->SetBranchAddress("row4sumc",&row4sumc);

    tree->SetBranchAddress("allhit_id",&allhit_id);
    tree->SetBranchAddress("allhit_x",&allhit_x);
    tree->SetBranchAddress("allhit_y",&allhit_y);
    tree->SetBranchAddress("allhit_z",&allhit_z);
    tree->SetBranchAddress("allhit_t",&allhit_t);

    tree->SetBranchAddress("firsthit_id",&firsthit_id);
    tree->SetBranchAddress("firsthit_x",&firsthit_x);
    tree->SetBranchAddress("firsthit_y",&firsthit_y);
    tree->SetBranchAddress("firsthit_z",&firsthit_z);
    tree->SetBranchAddress("firsthit_t",&firsthit_t);

    tree->SetBranchAddress("indpmt", &indpmt);

    int nentries = tree->GetEntries();
    cout<<"ntuple entries "<<nentries<<endl;
    int counter[10000] = {};
    int pecounter[10000] = {};

    for (int i=0;i<nentries;i++){
      tree->GetEntry(i);
     
      if(i > evtNum || i< evtBase) continue;
      std::vector<double> pmtloc;
      double theta = -1; double phi = -1;

      for (int ihit = 0; ihit< 500; ihit++){
      
	if (allhit_id[ihit] == 0 && allhit_t[ihit] == 0) break;

        pmtloc.push_back(pmtx[allhit_id[ihit]]);
	pmtloc.push_back(pmty[allhit_id[ihit]]);
	pmtloc.push_back(allhit_id[ihit]);
        double ccc = allhit_t[ihit];
        double locx = 0;
	double locy = 0;
	double locz = 0;
        
        pmtloc.push_back(ccc);
        pmtloc.push_back(locx);
        pmtloc.push_back(locy);
        pmtloc.push_back(locz);
        pmtloc.push_back(0);

	double gridx = xinput;
	double gridy = yinput;

	double mcu = gridx+0.0000000000001;
	double mcv = gridy+0.0000000000001;
	double mcw = -100;

        ggg[i] = mcu / sqrt(mcu*mcu + mcv*mcv + mcw*mcw);
        hhh[i] = mcv / sqrt(mcu*mcu + mcv*mcv + mcw*mcw);
        mmm[i] = mcw / sqrt(mcu*mcu + mcv*mcv + mcw*mcw);
        if (mmm[i]>0){
            pmtloc.push_back(TMath::ATan(sqrt(ggg[i]*ggg[i]+hhh[i]*hhh[i])/abs(mmm[i])));
            theta = TMath::ATan(sqrt(ggg[i]*ggg[i]+hhh[i]*hhh[i])/abs(mmm[i]));
        }
        else {
            pmtloc.push_back(TMath::Pi() - TMath::ATan(sqrt(ggg[i]*ggg[i]+hhh[i]*hhh[i])/abs(mmm[i])));
            theta = TMath::Pi() - TMath::ATan(sqrt(ggg[i]*ggg[i]+hhh[i]*hhh[i])/abs(mmm[i]));
        }
        if (ggg[i]>=0 && hhh[i]>0) {pmtloc.push_back(TMath::ATan(hhh[i]/ggg[i])); phi = TMath::ATan(hhh[i]/ggg[i]);}
        else if (ggg[i]<0 && hhh[i]>=0) {pmtloc.push_back(TMath::ATan(hhh[i]/ggg[i])+TMath::Pi()); phi = TMath::ATan(hhh[i]/ggg[i])+TMath::Pi();}
        else if (ggg[i]<0 && hhh[i]<0) {pmtloc.push_back(TMath::ATan(hhh[i]/ggg[i])+ TMath::Pi()); phi = TMath::ATan(hhh[i]/ggg[i])+ TMath::Pi();}
        else if (ggg[i]>=0 && hhh[i]<=0) {pmtloc.push_back(TMath::Pi()*2 -TMath::ATan(abs(hhh[i])/ggg[i])); phi = TMath::Pi()*2 -TMath::ATan(abs(hhh[i])/ggg[i]); }

	pmtloc.push_back(1);
        pmtlist.push_back(pmtloc);
        if (i>= lowerEvt && i< upperEvt ){
          if (theta > -999){
            fitlist[i].push_back(pmtloc);
            eventTaker[i] = 1;
          }
          if (iniX[i] == 0 && iniY[i] == 0 && iniZ[i] == 0)
            iniX[i] = pmtx[bbb]; iniY[i] = pmty[bbb]; iniZ[i] = pmtz[bbb];
        }
        pmtloc.clear();
      }
    }
  }
  ////////////////////////////////////////////// end of using ntuple input file
  /////////////////////////////////////////////////////////////////////////////////////////////

  if (ifOutputRoot){
    outfile = TFile::Open( outputRoot.Data(), "recreate");
  }

  cout<<"event induced PMT loaded "<<endl;

  RooFitResult* res;
  char formula[10];
  dirFit * rep = new dirFit ("_rep");
  
  // 1 ton time cut 4.5, 2.4 ton time cut 5.5, 5 ton time cut 6.5
  cout<<"doing digitize ? "<<digitize<<"  adding sometime ? "<<sometime<<endl;

  rep->SetPromptCut(1.01+sometime/10.);

  rep->SetNbins(nbins);
  rep->SetIfDoCharge(doCharge);
  rep->SetIfDoCharge(doCos);
  rep->SetFitVertex(doFitVertex);
  rep->SetIfDo2dpdf(false);
  rep->SetDo3D(do3D);
  if (do2Dpdf) rep->SetIfDo2dpdf(true);
  if (perPMT) rep->SetPerPMT(true);
  else rep->SetPerPMT(false);
  if (perDir) rep->SetPerDir(true);
  else rep->SetPerDir(false);
  //if (all_light)
    //rep->SetPromptCut(10);

  if (!perDir)
    ntime_bin = uppertime/timeInterval;

  cout<<"reading processing events"<<endl;
  std::vector<double> iniVertex(3);
  wbPDF* pdfs;
  //std::vector<wbPDF*> pdfss;
  std::vector<wbPDF*> pdfss(500);
  for (int ipmt = 0; ipmt< 500;ipmt++){
    pdfss[ipmt] = new wbPDF("_wbpdf");
    if (!perDir)  pdfss[ipmt]->SetPMTPDFBinning(nbins,0,3.14,nbins,0,6.28);
    else pdfss[ipmt]->SetDirPDFBinning(npmt_bin,0,npmt_bin,ntime_bin,-10,10);
  }
  cout<<"constructing 3D structure .. "<<endl;
  std::vector<std::vector<wbPDF*>> pdfsss(ntime_bin, std::vector<wbPDF*>(npmt_bin));
  if (perPMT && do3D && !perDir){
    for (int itime = 0; itime< pdfsss.size(); itime++){
      for (int ipmt = 0; ipmt< pdfsss[itime].size(); ipmt++){
        cout<<"time slice and pmt id "<<itime<<" "<<ipmt<<endl;
        pdfsss[itime][ipmt] = new wbPDF("_wbpdf");
        pdfsss[itime][ipmt]->SetPMTPDFBinning(nbins,0,3.14,nbins,0,6.28);
      }
    }
  }

  cout<<"extracting pdfs .. "<<endl;

  TH1F* timepdf;
  TH1F* thetapdf;
  TH2F* timeThetapdf;
  TH2F* pmtpdf[500];
  TH2F* pmtpdff[100][500];
  TH2F* dirpdf[500];
  if (!perPMT && !perDir){
    pdfs =  rep->Reading_Processing_Events(pmtlist,"pdf", iniVertex, do2Dpdf, doCharge, doCos );
    rep->SetPDFs(pdfs);
    cout<<"getting pdfs"<<endl;
    timepdf = pdfs->GetTimePDF();
    thetapdf = pdfs->GetThetaPDF();
    timeThetapdf = pdfs->GetTimeThetaPDF();
    cout<<"pdf obtained"<<endl;
  }
  else if(perDir){
    cout<<"reading perPMT PDFs .. "<<endl;
    rep->SetNbins_time(ntime_bin);
    rep->SetNdir(ndir_bin);
    rep->SetNbins_pmt(npmt_bin);
    if (!externalPDF){
      cout<<"doing a perDir pdf generation.."<<endl;
      pdfss = rep->Reading_Processing_Events_PerDir(pmtlist,"dirpdf", iniVertex, do2Dpdf, doCharge, doCos );
      cout<<"checking pdfss, size, and size of individual pdfss element:  "<<pdfss.size()<<" "<<pdfss[1]->GetDirPDF()->GetNbinsX()<<" "<<pdfss[1]->GetDirPDF()->GetNbinsY()<<endl;
      for (int iii=0;iii<pdfss[1]->GetDirPDF()->GetNbinsX(); iii++){
        for (int jjj=0;jjj<pdfss[1]->GetDirPDF()->GetNbinsY(); jjj++){
	   if (pdfss[368]->GetDirPDF()->GetBinContent(iii+1,jjj+1)>0) cout<<"in app2 iii, jjj, pdfss[1] element: "<<iii<<" "<<jjj<<" "<<pdfss[368]->GetDirPDF()->GetBinContent(iii+1,jjj+1)<<endl;
        }
      }
    }
    else{
        TFile fepdf(pdf_filename.Data());
        for (int iir=0;iir<ndir_bin;iir++){
          TH2F* hpdf = (TH2F*)fepdf.Get(Form("output_dir_%d",iir));
	  //if (iir == 1) cout<<"ckecking set dir "<<hpdf->Integral()<<endl;
          pdfss[iir]->SetDirPDF(hpdf);
	  //if (iir == 1) cout<<"pdfss integral "<<pdfss[1]->GetDirPDF()->Integral()<<endl;
        }
        fepdf.Close();
	rep->SetDirPDFs(pdfss);
	//cout<<"testing here (dir 1 integral) "<<rep->GetDirPDFs().at(1)->GetDirPDF()->Integral()<<endl;
    }
    if (ifOutputRoot){
      for (int ipmt = 0; ipmt<pdfss.size() ; ipmt++){
        if (perDir){
          dirpdf[ipmt] = pdfss[ipmt]->GetDirPDF();
	  if (dirpdf[ipmt]->Integral()> 0) cout<<"ipmt "<<ipmt<<" was filled.."<<endl;
          dirpdf[ipmt]->Write(Form("output_dir_%d",ipmt));
        }
      }
    }
  } 
  else{
    cout<<"reading perPMT PDFs .. "<<endl;
    if (!externalPDF){
      if (!do3D){
        pdfss = rep->Reading_Processing_Events_PerPMT(pmtlist,"pmtpdf", iniVertex, do2Dpdf, doCharge, doCos );
      } 
      else{
	cout<<"doing a 3D pdf generation.."<<endl;
        rep->SetTimeInterval(timeInterval);
	pdfsss = rep->Reading_Processing_Events_PerPMT_timeSlice(pmtlist,"pmtpdf", iniVertex, do2Dpdf, doCharge, doCos, uppertime );
      }
    }
    else{
      if (!do3D){
        TFile fepdf(pdf_filename.Data());
        for (int iir=0;iir<npmt_bin;iir++){
          TH2F* hpdf = (TH2F*)fepdf.Get(Form("output_%d",iir));
          pdfss[iir]->SetPMTPDF(hpdf);
        }
        fepdf.Close();
      }
      else {
	rep->SetTimeInterval(timeInterval);      
        TFile fepdf(pdf_filename.Data());
        for (int iir=0;iir<npmt_bin;iir++){
	  for (int iit =0; iit< ntime_bin; iit++){
            TH2F* hpdf = (TH2F*)fepdf.Get(Form("output_%d_timeSlice_%d",iir,iit));
            pdfsss[iit][iir]->SetPMTPDF(hpdf);
	  }
        }
        fepdf.Close();      
      }
    }	
    if (!do3D && !perDir) rep->SetPDFs(pdfss);
    else rep->SetPDFS(pdfsss);
    std::vector<std::vector<wbPDF*>> set_pdfs = rep->GetPMTPDFS();
    cout<<"checking the setup pmt pdf info. "<<set_pdfs[0][0]->GetPMTPDF()->GetNbinsX()<<endl;
    cout<<"pmt pdf obtained"<<endl;
  }

  if (ifOutputRoot){
    outfile->Write();
  }


  if (!externalPDF) { cout<<"just getting pdf, not performing fit .. "<<endl; exit(1);}

  for (Int_t aaa = lowerEvt;aaa< upperEvt; aaa++){

    //cout<<aaa<<" taker "<<eventTaker[aaa]<<endl;
    if (eventTaker[aaa] == 0 ) continue;
    wbPDF* nothing =  rep->Reading_Processing_Events(fitlist[aaa],"event", iniVertex, do2Dpdf, doCharge, doCos );

    cout<<1<<endl;
    RooArgList list("list");
    list.add(*rep);
    sprintf(formula,"%s","@0");
    RooFormulaVar* fcn = new RooFormulaVar("fit","fit",formula,list);

    cout<<2<<endl;
    rep->getParVar(0)->setConstant(false);
    rep->getParVar(1)->setConstant(false);
    rep->getParVar(2)->setConstant(false);

    cout<<3<<endl;
    rep->getParVar(0)->setVal(iniX[aaa]/ sqrt(iniX[aaa]*iniX[aaa]+iniY[aaa]*iniY[aaa]+iniZ[aaa]*iniZ[aaa]));  
    rep->getParVar(1)->setVal(iniY[aaa]/ sqrt(iniX[aaa]*iniX[aaa]+iniY[aaa]*iniY[aaa]+iniZ[aaa]*iniZ[aaa]));
    rep->getParVar(2)->setVal(iniZ[aaa]/ sqrt(iniX[aaa]*iniX[aaa]+iniY[aaa]*iniY[aaa]+iniZ[aaa]*iniZ[aaa]));
    rep->ifScan(false);
    if (doScan){
      rep->ifScan(true);
      rep->getParVar(2)->setVal(-1);
      rep->getParVar(2)->setConstant(true);
    }
    rep->SetHitNumLimit(hitNumLimit);
    if (hitNumLimit < 1e5) {cout<<"--------------------- setting hit number limit !!! "<<endl; }

    cout<<4<<endl;
    ofstream out;
    //out.open(Form("output_result_timecut_finepdf_%dton_%dpct_full.txt",atoi(argv[1]),atoi(argv[2])),std::ofstream::out | std::ofstream::app);
    if (oTxt)
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
    cout<<"setting function"<<endl;
    double bestFit=1e9;
    double currX=1e9;
    double currY=1e9;
    double currZ=1e9;
    if (doScan){
      /*	    
      double currRes = 1e9;
      for (int xloop =0;xloop<48;xloop++){
        for (int yloop=0;yloop<48;yloop++){
	  rep->getParVar(0)->setVal(xloop/12.-2);	
	  rep->getParVar(1)->setVal(yloop/12.-2);
	  rep->getParVar(0)->setConstant(true);
	  rep->getParVar(1)->setConstant(true);
	  double res = rep->evaluate();
	  cout<<"currX currY "<<xloop/12.-2<<" "<<yloop/12.-2<<"  res "<<res<<endl;
	  out<<xloop<<" "<<yloop<<" "<<res<<endl;
	  if (res < currRes) {
	    currRes = res;
	    currX = xloop/12.-2;
	    currY = yloop/12.-2;
	  }
	}
      }
      bestFit = currRes;
      */
      double currRes = 1e9;
      for (int xloop = 0;xloop<8;xloop++){
        for (int yloop=19;yloop<20;yloop++){
          //rep->getParVar(0)->setVal((double)xloop* (3.14/20.));       
          //rep->getParVar(1)->setVal((double)yloop* (6.28/20.));
          rep->getParVar(0)->setVal(xloop);
          rep->getParVar(1)->setVal(yloop);
	  rep->getParVar(0)->setConstant(true);
          rep->getParVar(1)->setConstant(true);
          double res = rep->evaluate();

          //cout<<"currX currY "<<xloop/50.-4<<" "<<yloop/50.-4<<"  res "<<res<<endl;
	  cout<<aaa<<" "<<xloop<<" "<<yloop<<" "<<res<<endl;
          if (oTxt)
	    out<<aaa<<" "<<xloop<<" "<<yloop<<" "<<res<<endl;
          if (res < currRes) {
            currRes = res;
            currX = xloop;
            currY = yloop;
          }
        }
      }
      bestFit = currRes;
    }

    else{
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
      currX = rep->getParVar(0)->getVal();
      currY = rep->getParVar(1)->getVal();
    }
    currZ = rep->getParVar(2)->getVal();

    //if (res->status() == 0 ){
    //cout<<"abs(bestFit) "<<abs(bestFit)<<" "<<" abs(rep->getParVar(0)->getVal()) "<<abs(rep->getParVar(0)->getVal())<<endl;
    if (!doScan){
      if (abs(bestFit) > 0 && abs(rep->getParVar(0)->getVal())>0 ){
        //cout<<rep->getParVar(0)->getVal()<<" "<<rep->getParVar(1)->getVal()<<" "<<rep->getParVar(2)->getVal()<<" "<<bestFit<<endl;
        //out<<rep->getParVar(0)->getVal()<<" "<<rep->getParVar(1)->getVal()<<" "<<rep->getParVar(2)->getVal()<<" "<<bestFit<<endl;
        cout<<"directional vector and bestFit: "<<currX<<" "<<currY<<" "<<currZ<<" "<<bestFit<<endl;
        if (oTxt)
          out<<currX<<" "<<currY<<" "<<currZ<<" "<<bestFit<<endl;
      }
    }
    else{
        cout<<"directional vector and bestFit: "<<currX<<" "<<currY<<" "<<currZ<<" "<<bestFit<<"   angle between true and reco. "<<endl;
        if (oTxt)
          out<<currX<<" "<<currY<<" "<<currZ<<" "<<bestFit<<endl;
    }
  }
  if (ifOutputRoot){
    outfile->Write();
  }
}
