{
  gROOT->SetStyle("Plain");
  gStyle->SetTitleBorderSize(0);
  gStyle->SetOptStat("");

  gStyle->SetLabelFont(102,"");
  gStyle->SetLabelSize(0.06,"");
  gStyle->SetLabelFont(102,"xyz");
  gStyle->SetLabelSize(0.04,"xyz");
  gStyle->SetLabelOffset(0.001,"x");
  gStyle->SetLabelOffset(0.01,"y");

  gStyle->SetTitleFont(42,"xyz");
  gStyle->SetTitleFontSize(0.06);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleSize(0.06,"xyz");
  gStyle->SetTitleOffset(0.9,"x");
  gStyle->SetTitleOffset(1.2,"y");

  gStyle->SetStripDecimals(kFALSE);

  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadBottomMargin(0.15);

  gStyle->SetStatW(0.35);
  gStyle->SetStatH(0.25);

  gStyle->SetPadTickX(kTRUE);
  gStyle->SetPadTickY(kTRUE);

  gStyle->SetPalette(1);
  gStyle->SetNumberContours(99);

  gStyle->SetHistLineWidth(2);
  gStyle->SetFrameLineWidth(2);
  gStyle->SetFuncWidth(2);

  gStyle->SetStatFont(42);
  gStyle->SetOptFit(1111);
  gStyle->SetOptStat(0);
  gStyle->SetOptStat(000000);

  cout<<"start"<<endl;	
/*	
11 0 -400.05  -677.1 1
12 0 -285.75  -677.1 1
13 0 -171.45  -677.1 1
14 0 -57.15  -677.1 1
15 0 57.15  -677.1 1
16 0 171.45  -677.1 1
17 0 285.75  -677.1 1
18 0 400.05  -677.1 1
*/

  float indpmtw[46];
  //cout<<"tfile"<<endl;
  //TFile f("bnl1t_water_x_0_y_0_1gev_newwater.root");
  //TFile f("bnl1t_newwater2_x_-14_y_0_1gev.root"); 
  //TFile fw("bnl1t_oldwater2_x_0_y_0.root");
  //TFile fw("bnl1t_x_0_y_0_muon_bnlwater2.root");
  TFile fw("bnl1t_x_0_y_0_muon_random_bnlwater.root");
  //cout<<"ttree"<<endl;
  TTree* ttreew = (TTree*)fw.Get("tree");
  ttreew->Print();
  float botsumow;
  float row1sumow;
  float row2sumow;
  float row3sumow;
  float row4sumow;
  TH1F* h_botsumow = new TH1F("","",100,0,1000);
  TH1F* h_botsumo_cw = new TH1F("","",100,0,1000);  
  TH1F* h_row1sumow = new TH1F("","",50,0,100);
  TH1F* h_row2sumow = new TH1F("","",50,0,100);
  TH1F* h_row3sumow = new TH1F("","",50,0,100);
  TH1F* h_row4sumow = new TH1F("","",50,0,100);

  //cout<<"reading the tree"<<endl;
  ttreew->SetBranchAddress("indpmt", &indpmtw);
  ttreew->SetBranchAddress("botsum", &botsumow);
  ttreew->SetBranchAddress("row3sum",&row3sumow);
  ttreew->SetBranchAddress("row4sum",&row4sumow);
  ttreew->SetBranchAddress("row1sum",&row1sumow);
  ttreew->SetBranchAddress("row2sum",&row2sumow);  

  //cout<<"defining histograms"<<endl;
  TH1F* ratioxw[46];
  TH1F* ratiox2w[46];
  TH1F* ratiox3w[46];
  TH1F* ratiox4w[46];
  TH1F* ratiox5w[46];
  TH1F* ratiox6w[46];
  TH1F* ratiox7w[46];
  TH1F* ratiox8w[46];
  TH1F* ratiox9w[46];
  TH1F* ratiox10w[46];
  TH1F* ratiox11w[46];
  TH1F* ratiox12w[46];
  TH1F* ratiox13w[46];
  TH1F* ratiox14w[46];
  TH1F* ratiox15w[46];
  TH1F* ratiox16w[46];
  TH1F* ratiox17w[46];
  TH1F* ratiox18w[46];
  TH1F* ratiox19w[46];
  TH1F* ratiox20w[46];
  TH1F* ratiox21w[46];
  TH1F* ratiox22w[46];
  TH1F* ratiox23w[46];
  TH1F* ratiox24w[46];
  TH1F* ratiox25w[46];
  TH1F* ratiox26w[46];
  TH1F* ratiox27w[46];
  TH1F* ratiox28w[46];
  TH1F* ratiox29w[46];
  TH1F* ratiox30w[46];
  TH1F* ratiox31w[46];
  TH1F* ratiox32w[46];
  TH1F* ratiox33w[46];
  TH1F* ratiox34w[46];
  TH1F* ratiox35w[46];
  TH1F* ratiox36w[46];
  TH1F* ratiox37w[46];
  TH1F* ratiox38w[46];
  TH1F* ratiox39w[46];
  TH1F* ratiox40w[46];
  TH1F* ratiox41w[46];
  TH1F* ratiox42w[46];
  TH1F* ratiox43w[46];
  TH1F* ratiox44w[46];
  TH1F* ratiox45w[46];
  TH1F* ratiox46w[46];

  for (int i=0;i<46;i++){ 
    ratioxw[i] = new TH1F("","",1000,0,4000);
    ratiox2w[i] = new TH1F("","",1000,0,4000);
    ratiox3w[i] = new TH1F("","",1000,0,4000);
    ratiox4w[i] = new TH1F("","",1000,0,4000);
    ratiox5w[i] = new TH1F("","",1000,0,4000);
    ratiox6w[i] = new TH1F("","",1000,0,4000);
    ratiox7w[i] = new TH1F("","",1000,0,4000);
    ratiox8w[i] = new TH1F("","",1000,0,4000);
    ratiox9w[i] = new TH1F("","",1000,0,4000);
    ratiox10w[i] = new TH1F("","",1000,0,4000);
    ratiox11w[i] = new TH1F("","",1000,0,4000);
    ratiox12w[i] = new TH1F("","",1000,0,4000);
    ratiox13w[i] = new TH1F("","",1000,0,4000);
    ratiox14w[i] = new TH1F("","",1000,0,4000);
    ratiox15w[i] = new TH1F("","",1000,0,4000);
    ratiox16w[i] = new TH1F("","",1000,0,4000);
    ratiox17w[i] = new TH1F("","",1000,0,4000);
    ratiox18w[i] = new TH1F("","",1000,0,4000);
    ratiox19w[i] = new TH1F("","",1000,0,4000);
    ratiox20w[i] = new TH1F("","",1000,0,4000);
    ratiox21w[i] = new TH1F("","",1000,0,4000);
    ratiox22w[i] = new TH1F("","",1000,0,4000);
    ratiox23w[i] = new TH1F("","",1000,0,4000);
    ratiox24w[i] = new TH1F("","",1000,0,4000);
    ratiox25w[i] = new TH1F("","",1000,0,4000);
    ratiox26w[i] = new TH1F("","",1000,0,4000);
    ratiox27w[i] = new TH1F("","",1000,0,4000);
    ratiox28w[i] = new TH1F("","",1000,0,4000);    
    ratiox29w[i] = new TH1F("","",1000,0,4000);
    ratiox30w[i] = new TH1F("","",1000,0,4000);    
    ratiox31w[i] = new TH1F("","",1000,0,4000);
    ratiox32w[i] = new TH1F("","",1000,0,4000);
    ratiox33w[i] = new TH1F("","",1000,0,4000);
    ratiox34w[i] = new TH1F("","",1000,0,4000);
    ratiox35w[i] = new TH1F("","",1000,0,4000);
    ratiox36w[i] = new TH1F("","",1000,0,4000);
    ratiox37w[i] = new TH1F("","",1000,0,4000);
    ratiox38w[i] = new TH1F("","",1000,0,4000);
    ratiox39w[i] = new TH1F("","",1000,0,4000);
    ratiox40w[i] = new TH1F("","",1000,0,4000);
    ratiox41w[i] = new TH1F("","",1000,0,4000);
    ratiox42w[i] = new TH1F("","",1000,0,4000);
    ratiox43w[i] = new TH1F("","",1000,0,4000);
    ratiox44w[i] = new TH1F("","",1000,0,4000);
    ratiox45w[i] = new TH1F("","",1000,0,4000);
    ratiox46w[i] = new TH1F("","",1000,0,4000);
  }

  float indpmt[46];
  //cout<<"tfile"<<endl;
  //TFile f("bnl1t_water_x_0_y_0_1gev_newwater.root");
  //TFile f("bnl1t_newwater2_x_-14_y_0_1gev.root"); 
  //TFile f("bnl1t_wbls_x_0_y_0_second.root");
  TFile f("bnl1t_x_0_y_0_muon_wbls100ly.root");
  //cout<<"ttree"<<endl;
  TTree* ttree = (TTree*)f.Get("tree");
  //ttree->Print();
  float botsumo;
  float row1sumo;
  float row2sumo;
  float row3sumo;
  float row4sumo;
  TH1F* h_botsumo = new TH1F("","",100,0,1000);
  TH1F* h_botsumo_c = new TH1F("","",100,0,1000);  
  TH1F* h_row1sumo = new TH1F("","",50,0,100);
  TH1F* h_row2sumo = new TH1F("","",50,0,100);
  TH1F* h_row3sumo = new TH1F("","",50,0,100);
  TH1F* h_row4sumo = new TH1F("","",50,0,100);

  //cout<<"reading the tree"<<endl;
  ttree->SetBranchAddress("indpmt", &indpmt);
  ttree->SetBranchAddress("botsum", &botsumo);
  ttree->SetBranchAddress("row1sum",&row1sumo);
  ttree->SetBranchAddress("row2sum",&row2sumo);
  ttree->SetBranchAddress("row3sum",&row3sumo);
  ttree->SetBranchAddress("row4sum",&row4sumo);

  //cout<<"defining histograms"<<endl;
  TH1F* ratiox[46];
  TH1F* ratiox2[46];
  TH1F* ratiox3[46];
  TH1F* ratiox4[46];
  TH1F* ratiox5[46];
  TH1F* ratiox6[46];
  TH1F* ratiox7[46];
  TH1F* ratiox8[46];
  TH1F* ratiox9[46];
  TH1F* ratiox10[46];
  TH1F* ratiox11[46];
  TH1F* ratiox12[46];
  TH1F* ratiox13[46];
  TH1F* ratiox14[46];
  TH1F* ratiox15[46];
  TH1F* ratiox16[46];
  TH1F* ratiox17[46];
  TH1F* ratiox18[46];
  TH1F* ratiox19[46];
  TH1F* ratiox20[46];
  TH1F* ratiox21[46];
  TH1F* ratiox22[46];
  TH1F* ratiox23[46];
  TH1F* ratiox24[46];
  TH1F* ratiox25[46];
  TH1F* ratiox26[46];
  TH1F* ratiox27[46];
  TH1F* ratiox28[46];
  TH1F* ratiox29[46];
  TH1F* ratiox30[46];
  TH1F* ratiox31[46];
  TH1F* ratiox32[46];
  TH1F* ratiox33[46];
  TH1F* ratiox34[46];
  TH1F* ratiox35[46];
  TH1F* ratiox36[46];
  TH1F* ratiox37[46];
  TH1F* ratiox38[46];
  TH1F* ratiox39[46];
  TH1F* ratiox40[46];
  TH1F* ratiox41[46];
  TH1F* ratiox42[46];
  TH1F* ratiox43[46];
  TH1F* ratiox44[46];
  TH1F* ratiox45[46];
  TH1F* ratiox46[46];

  for (int i=0;i<46;i++){ 
    ratiox[i] = new TH1F("","",1000,0,4000);
    ratiox2[i] = new TH1F("","",1000,0,4000);
    ratiox3[i] = new TH1F("","",1000,0,4000);
    ratiox4[i] = new TH1F("","",1000,0,4000);
    ratiox5[i] = new TH1F("","",1000,0,4000);
    ratiox6[i] = new TH1F("","",1000,0,4000);
    ratiox7[i] = new TH1F("","",1000,0,4000);
    ratiox8[i] = new TH1F("","",1000,0,4000);
    ratiox9[i] = new TH1F("","",1000,0,4000);
    ratiox10[i] = new TH1F("","",1000,0,4000);
    ratiox11[i] = new TH1F("","",1000,0,4000);
    ratiox12[i] = new TH1F("","",1000,0,4000);
    ratiox13[i] = new TH1F("","",1000,0,4000);
    ratiox14[i] = new TH1F("","",1000,0,4000);
    ratiox15[i] = new TH1F("","",1000,0,4000);
    ratiox16[i] = new TH1F("","",1000,0,4000);
    ratiox17[i] = new TH1F("","",1000,0,4000);
    ratiox18[i] = new TH1F("","",1000,0,4000);
    ratiox19[i] = new TH1F("","",1000,0,4000);
    ratiox20[i] = new TH1F("","",1000,0,4000);
    ratiox21[i] = new TH1F("","",1000,0,4000);
    ratiox22[i] = new TH1F("","",1000,0,4000);
    ratiox23[i] = new TH1F("","",1000,0,4000);
    ratiox24[i] = new TH1F("","",1000,0,4000);
    ratiox25[i] = new TH1F("","",1000,0,4000);
    ratiox26[i] = new TH1F("","",1000,0,4000);
    ratiox27[i] = new TH1F("","",1000,0,4000);
    ratiox28[i] = new TH1F("","",1000,0,4000);    
    ratiox29[i] = new TH1F("","",1000,0,4000);
    ratiox30[i] = new TH1F("","",1000,0,4000);    
    ratiox31[i] = new TH1F("","",1000,0,4000);
    ratiox32[i] = new TH1F("","",1000,0,4000);
    ratiox33[i] = new TH1F("","",1000,0,4000);
    ratiox34[i] = new TH1F("","",1000,0,4000);
    ratiox35[i] = new TH1F("","",1000,0,4000);
    ratiox36[i] = new TH1F("","",1000,0,4000);
    ratiox37[i] = new TH1F("","",1000,0,4000);
    ratiox38[i] = new TH1F("","",1000,0,4000);
    ratiox39[i] = new TH1F("","",1000,0,4000);
    ratiox40[i] = new TH1F("","",1000,0,4000);
    ratiox41[i] = new TH1F("","",1000,0,4000);
    ratiox42[i] = new TH1F("","",1000,0,4000);
    ratiox43[i] = new TH1F("","",1000,0,4000);
    ratiox44[i] = new TH1F("","",1000,0,4000);
    ratiox45[i] = new TH1F("","",1000,0,4000);
    ratiox46[i] = new TH1F("","",1000,0,4000);
  }

  TH1F* ratioxx[46];
  TH1F* ratioxx2[46];
  TH1F* ratioxx3[46];
  TH1F* ratioxx4[46];
  TH1F* ratioxx5[46];
  TH1F* ratioxx6[46];
  TH1F* ratioxx7[46];
  TH1F* ratioxx8[46];
  TH1F* ratioxx9[46];
  TH1F* ratioxx10[46];
  TH1F* ratioxx11[46];
  TH1F* ratioxx12[46];
  TH1F* ratioxx13[46];
  TH1F* ratioxx14[46];
  TH1F* ratioxx15[46];
  TH1F* ratioxx16[46];
  TH1F* ratioxx17[46];
  TH1F* ratioxx18[46];
  TH1F* ratioxx19[46];
  TH1F* ratioxx20[46];
  TH1F* ratioxx21[46];
  TH1F* ratioxx22[46];
  TH1F* ratioxx23[46];
  TH1F* ratioxx24[46];
  TH1F* ratioxx25[46];
  TH1F* ratioxx26[46];
  TH1F* ratioxx27[46];
  TH1F* ratioxx28[46];
  TH1F* ratioxx29[46];
  TH1F* ratioxx30[46];
  TH1F* ratioxx31[46];
  TH1F* ratioxx32[46];
  TH1F* ratioxx33[46];
  TH1F* ratioxx34[46];
  TH1F* ratioxx35[46];
  TH1F* ratioxx36[46];
  TH1F* ratioxx37[46];
  TH1F* ratioxx38[46];
  TH1F* ratioxx39[46];
  TH1F* ratioxx40[46];
  TH1F* ratioxx41[46];
  TH1F* ratioxx42[46];
  TH1F* ratioxx43[46];
  TH1F* ratioxx44[46];
  TH1F* ratioxx45[46];
  TH1F* ratioxx46[46];

  for (int i=0;i<46;i++){
    ratioxx[i] = new TH1F("","",1000,0,4000);
    ratioxx2[i] = new TH1F("","",1000,0,4000);
    ratioxx3[i] = new TH1F("","",1000,0,4000);
    ratioxx4[i] = new TH1F("","",1000,0,4000);
    ratioxx5[i] = new TH1F("","",1000,0,4000);
    ratioxx6[i] = new TH1F("","",1000,0,4000);
    ratioxx7[i] = new TH1F("","",1000,0,4000);
    ratioxx8[i] = new TH1F("","",1000,0,4000);
    ratioxx9[i] = new TH1F("","",1000,0,4000);
    ratioxx10[i] = new TH1F("","",1000,0,4000);
    ratioxx11[i] = new TH1F("","",1000,0,4000);
    ratioxx12[i] = new TH1F("","",1000,0,4000);
    ratioxx13[i] = new TH1F("","",1000,0,4000);
    ratioxx14[i] = new TH1F("","",1000,0,4000);
    ratioxx15[i] = new TH1F("","",1000,0,4000);
    ratioxx16[i] = new TH1F("","",1000,0,4000);
    ratioxx17[i] = new TH1F("","",1000,0,4000);
    ratioxx18[i] = new TH1F("","",1000,0,4000);
    ratioxx19[i] = new TH1F("","",1000,0,4000);
    ratioxx20[i] = new TH1F("","",1000,0,4000);
    ratioxx21[i] = new TH1F("","",1000,0,4000);
    ratioxx22[i] = new TH1F("","",1000,0,4000);
    ratioxx23[i] = new TH1F("","",1000,0,4000);
    ratioxx24[i] = new TH1F("","",1000,0,4000);
    ratioxx25[i] = new TH1F("","",1000,0,4000);
    ratioxx26[i] = new TH1F("","",1000,0,4000);
    ratioxx27[i] = new TH1F("","",1000,0,4000);
    ratioxx28[i] = new TH1F("","",1000,0,4000);
    ratioxx29[i] = new TH1F("","",1000,0,4000);
    ratioxx30[i] = new TH1F("","",1000,0,4000);
    ratioxx31[i] = new TH1F("","",1000,0,4000);
    ratioxx32[i] = new TH1F("","",1000,0,4000);
    ratioxx33[i] = new TH1F("","",1000,0,4000);
    ratioxx34[i] = new TH1F("","",1000,0,4000);
    ratioxx35[i] = new TH1F("","",1000,0,4000);
    ratioxx36[i] = new TH1F("","",1000,0,4000);
    ratioxx37[i] = new TH1F("","",1000,0,4000);
    ratioxx38[i] = new TH1F("","",1000,0,4000);
    ratioxx39[i] = new TH1F("","",1000,0,4000);
    ratioxx40[i] = new TH1F("","",1000,0,4000);
    ratioxx41[i] = new TH1F("","",1000,0,4000);
    ratioxx42[i] = new TH1F("","",1000,0,4000);
    ratioxx43[i] = new TH1F("","",1000,0,4000);
    ratioxx44[i] = new TH1F("","",1000,0,4000);
    ratioxx45[i] = new TH1F("","",1000,0,4000);
    ratioxx46[i] = new TH1F("","",1000,0,4000);
  }

  //straight downward 1 GeV muons
  //double scaling_pmtid11[30] = {1.15456, 1.25897, 1.25699, 2.03868, 1.27977, 1.89503, 2.14115, 1.82487, 1.5078, 1.39495, 1, 2.13052, 1.43292, 2.18741, 1.54075, 2.07495, 1.66603, 1.72719, 1.44723, 1.95145, 2.00126, 1.43227, 2.37127, 1.15177, 2.41452, 1.63869, 1.98263, 1.78194, 1.59309, 1.4528};
  //8-deg tilting 1 GeV muons
  double scaling_pmtid11[30] = {1.08095, 1.10511, 1.05898, 1.81545, 1.42441, 1.96832, 2.00764, 1.36913, 0.894162, 1.12228, 1, 2.72562, 1.81012, 2.27849, 1.00268, 2.91366, 2.23304, 2.20798, 1.82661, 2.06973, 2.54872, 0.861322, 1.89988, 1.12561, 3.18414, 1.96858, 1.98091, 1.44023, 1.14214, 1.07418};
  for (int i=0;i<30;i++) scaling_pmtid11[i] = 1;
  // this is from the fitted result
  //scaling_pmtid11[11] = 0.768;
  //scaling_pmtid11[12] = 1.143;
  //scaling_pmtid11[13] = 0.676;
  //scaling_pmtid11[14] = 0.999;
  //scaling_pmtid11[15] = 0.755;  
 
  // 2-PMT fitting based on PMT12: works
  //scaling_pmtid11[12] = 1.37;
  //scaling_pmtid11[13] = 0.84;

  // 7-PMT fitting based on PMT12: works
  //scaling_pmtid11[12] = 1.284;
  //scaling_pmtid11[13] = 0.799;
  //scaling_pmtid11[14] = 1.138;
  //scaling_pmtid11[15] = 0.847;
  //scaling_pmtid11[16] = 1.050;
  //scaling_pmtid11[17] = 1.048;
  //scaling_pmtid11[18] = 1.258;

  // 3-PMT fitting based on all: works
  //scaling_pmtid11[12] = 1.485;
  //scaling_pmtid11[13] = 0.889;
  //scaling_pmtid11[14] = 1.306;
  //scaling_pmtid11[15] = 0.937;

  // 7-PMT fitting bsed on all: 
  //scaling_pmtid11[12] = 1.486;
  //scaling_pmtid11[13] = 0.893;  
  //scaling_pmtid11[14] = 1.310;
  //scaling_pmtid11[15] = 0.981;  
  //scaling_pmtid11[16] = 1.203;
  //scaling_pmtid11[17] = 1.208;
  //scaling_pmtid11[18] = 1.466;  

  // 14-PMT fitting based on all:
  //scaling_pmtid11[12] = 1.485;
  //scaling_pmtid11[13] = 0.900;
  //scaling_pmtid11[14] = 1.316;
  //scaling_pmtid11[15] = 0.988;
  //scaling_pmtid11[16] = 1.212;
  //scaling_pmtid11[17] = 1.221;
  //scaling_pmtid11[18] = 1.469;
  //scaling_pmtid11[19] = 1.195;
  //scaling_pmtid11[20] = 1.097;
  //scaling_pmtid11[21] = 1.463;
  //scaling_pmtid11[22] = 0.870;
  //scaling_pmtid11[23] = 1.828;
  //scaling_pmtid11[24] = 0.879;
  //scaling_pmtid11[25] = 1.309;

  // full 29-PMT bottom except PMT12, based on PMT12: works, show this on Mar 29 2023 meeting.
  scaling_pmtid11[0] = 1.478;
  scaling_pmtid11[1] = 1.360;
  scaling_pmtid11[2] = 1.350;
  scaling_pmtid11[3] = 0.825;
  scaling_pmtid11[4] = 1.321;
  scaling_pmtid11[5] = 0.910;
  scaling_pmtid11[6] = 0.795;
  scaling_pmtid11[7] = 0.919;
  scaling_pmtid11[8] = 1.017;
  scaling_pmtid11[9] = 1.182;
  scaling_pmtid11[10] = 1.566;
  scaling_pmtid11[12] = 1.176;
  scaling_pmtid11[13] = 0.722;
  scaling_pmtid11[14] = 1.043;
  scaling_pmtid11[15] = 0.776;
  scaling_pmtid11[16] = 0.961;
  scaling_pmtid11[17] = 0.960;
  scaling_pmtid11[18] = 1.152;
  scaling_pmtid11[19] = 0.870;
  scaling_pmtid11[20] = 0.835;
  scaling_pmtid11[21] = 1.165;
  scaling_pmtid11[22] = 0.696;
  scaling_pmtid11[23] = 1.462;
  scaling_pmtid11[24] = 0.697;
  scaling_pmtid11[25] = 1.013;
  scaling_pmtid11[26] = 0.845;
  scaling_pmtid11[27] = 0.944;
  scaling_pmtid11[28] = 1.055;
  scaling_pmtid11[29] = 1.172;

/*
  // full 29-PMT bottom except PMT12, based on all:
  scaling_pmtid11[0] = 1.868;
  scaling_pmtid11[1] = 1.714;
  scaling_pmtid11[2] = 1.708;
  scaling_pmtid11[3] = 1.040; 
  scaling_pmtid11[4] = 1.671;
  scaling_pmtid11[5] = 1.150;
  scaling_pmtid11[6] = 0.992;
  scaling_pmtid11[7] = 1.135;
  scaling_pmtid11[8] = 1.275;
  scaling_pmtid11[9] = 1.464;
  scaling_pmtid11[10] = 1.951;
  scaling_pmtid11[12] = 1.478;
  scaling_pmtid11[13] = 0.885;
  scaling_pmtid11[14] = 1.299;
  scaling_pmtid11[15] = 0.980;
  scaling_pmtid11[16] = 1.194;
  scaling_pmtid11[17] = 1.202;
  scaling_pmtid11[18] = 1.461;
  scaling_pmtid11[19] = 1.097;
  scaling_pmtid11[20] = 1.056;
  scaling_pmtid11[21] = 1.447;
  scaling_pmtid11[22] = 0.865;
  scaling_pmtid11[23] = 1.813;
  scaling_pmtid11[24] = 0.870;
  scaling_pmtid11[25] = 1.281;
  scaling_pmtid11[26] = 1.077;
  scaling_pmtid11[27] = 1.193;
  scaling_pmtid11[28] = 1.334;
  scaling_pmtid11[29] = 1.495;

  // 20-PMT bottom except PMT12, based on all:
  scaling_pmtid11[0] = 1.68007;
  scaling_pmtid11[1] = 1.54883;
  scaling_pmtid11[2] = 1.51518;
  scaling_pmtid11[3] = 1.02098; 
  scaling_pmtid11[4] = 1.52294;
  scaling_pmtid11[5] = 1.03683;
  scaling_pmtid11[6] = 0.952049;
  scaling_pmtid11[7] = 1.04781;
  scaling_pmtid11[8] = 1.23576;
  scaling_pmtid11[9] = 1.43632;
  scaling_pmtid11[10] = 1.81838;
  scaling_pmtid11[12] = 1.34608;
  scaling_pmtid11[13] = 0.850148;
  scaling_pmtid11[14] = 1.25722;
  scaling_pmtid11[15] = 0.953567;
  scaling_pmtid11[16] = 1.18140;
  scaling_pmtid11[17] = 1.17833;
  scaling_pmtid11[18] = 1.43686;
  scaling_pmtid11[19] = 0.994735;
*/
  //scaling_pmtid11[14] = 1.073;
  //scaling_pmtid11[15] = 0.452; 
  //scaling_pmtid11[16] = 0.820;
  //scaling_pmtid11[17] = 0.817;
  //scaling_pmtid11[18] = 1.033;
  //scaling_pmtid11[19] = 1.034;
  //scaling_pmtid11[20] = 0.966; 

  //for (int i=0;i<ttree->GetEntries();i++){

  for (int i=0; i<ttreew->GetEntries(); i++){
    ttreew->GetEntry(i);
    //cout<<indpmt[11]<<endl;
    double tot1 = 0;
    for (int i=0;i<30;i++){ 
      tot1 += indpmtw[i] * scaling_pmtid11[i];
      indpmtw[i] *= scaling_pmtid11[i] ;
    }
    indpmtw[11] /= 1.;
    //cout<<"compare two total on the bottom, sum and botsum "<<tot1<<" "<<botsumo<<endl;
    h_botsumow->Fill(botsumow);
    h_botsumo_cw->Fill(tot1);
    h_row1sumow->Fill(row1sumow);
    h_row3sumow->Fill(row3sumow);
    h_row2sumow->Fill(row2sumow);
    h_row4sumow->Fill(row4sumow);
 
      double temp1 = indpmtw[30];
      double temp2 = indpmtw[31];
      double temp3 = indpmtw[32];
      double temp4 = indpmtw[33];
      double temp5 = indpmtw[34];
      double temp6 = indpmtw[35];
      double temp7 = indpmtw[36];
      double temp8 = indpmtw[37];
      double temp9 = indpmtw[38];
      double temp10 = indpmtw[39];
      double temp11 = indpmtw[40];
      double temp12 = indpmtw[41];
      double temp13 = indpmtw[42];
      double temp14 = indpmtw[43];
      double temp15 = indpmtw[44];
      double temp16 = indpmtw[45];

      indpmtw[30] = temp6;
      indpmtw[31] = temp5;
      indpmtw[32] = temp10;
      indpmtw[33] = temp9;
      indpmtw[34] = temp14;
      indpmtw[35] = temp13;
      indpmtw[36] = temp2;
      indpmtw[37] = temp1;

      indpmtw[38] = temp8;
      indpmtw[39] = temp7;
      indpmtw[40] = temp12;
      indpmtw[41] = temp11;
      indpmtw[42] = temp16;
      indpmtw[43] = temp15;
      indpmtw[44] = temp4;
      indpmtw[45] = temp3;
 
    for (int j=0;j<46;j++){

      ratioxw[j] -> Fill(indpmtw[j]);
      ratiox2w[j] -> Fill(indpmtw[j]);
      ratiox3w[j] -> Fill(indpmtw[j]);
      ratiox4w[j] -> Fill(indpmtw[j]);
      ratiox5w[j] -> Fill(indpmtw[j]);
      ratiox6w[j] -> Fill(indpmtw[j]);
      ratiox7w[j] -> Fill(indpmtw[j]);
      ratiox8w[j] -> Fill(indpmtw[j]);
      ratiox9w[j] -> Fill(indpmtw[j]);
      ratiox10w[j] -> Fill(indpmtw[j]);
      ratiox11w[j] -> Fill(indpmtw[j]);
      ratiox12w[j] -> Fill(indpmtw[j]);
      ratiox13w[j] -> Fill(indpmtw[j]);
      ratiox14w[j] -> Fill(indpmtw[j]);
      ratiox15w[j] -> Fill(indpmtw[j]);
      ratiox16w[j] -> Fill(indpmtw[j]);
      ratiox17w[j] -> Fill(indpmtw[j]);
      ratiox18w[j] -> Fill(indpmtw[j]);
      ratiox19w[j] -> Fill(indpmtw[j]);
      ratiox20w[j] -> Fill(indpmtw[j]);
      ratiox21w[j] -> Fill(indpmtw[j]);
      ratiox22w[j] -> Fill(indpmtw[j]);
      ratiox23w[j] -> Fill(indpmtw[j]);
      ratiox24w[j] -> Fill(indpmtw[j]);
      ratiox25w[j] -> Fill(indpmtw[j]);
      ratiox26w[j] -> Fill(indpmtw[j]);
      ratiox27w[j] -> Fill(indpmtw[j]);
      ratiox28w[j] -> Fill(indpmtw[j]);      
      ratiox29w[j] -> Fill(indpmtw[j]);
      ratiox30w[j] -> Fill(indpmtw[j]);     

      if (indpmtw[j]/indpmtw[30] > 0)
      ratiox31w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[31] > 0)
      ratiox32w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[32] > 0)
      ratiox33w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[33] > 0)
      ratiox34w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[34] > 0)
      ratiox35w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[35] > 0)
      ratiox36w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[36] > 0)
      ratiox37w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[37] > 0)
      ratiox38w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[38] > 0)
      ratiox39w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[39] > 0)
      ratiox40w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[40] > 0)
      ratiox41w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[41] > 0)
      ratiox42w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[42] > 0)
      ratiox43w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[43] > 0)
      ratiox44w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[44] > 0)
      ratiox45w[j] -> Fill(indpmtw[j]);
      if (indpmtw[j]/indpmtw[45] > 0)
      ratiox46w[j] -> Fill(indpmtw[j]);      
    }
  }


  for (int i=0; i<ttree->GetEntries(); i++){
    ttree->GetEntry(i);
    //cout<<indpmt[11]<<endl;
    double tot1 = 0;
    for (int i=0;i<30;i++){ 
      tot1 += indpmt[i] * scaling_pmtid11[i];
      indpmt[i] *= scaling_pmtid11[i] ;
    }
    indpmt[11] /= 1.;
    //cout<<"compare two total on the bottom, sum and botsum "<<tot1<<" "<<botsumo<<endl;
    h_botsumo->Fill(botsumo);
    h_botsumo_c->Fill(tot1);
 
    h_row1sumo->Fill(row1sumo);
    h_row3sumo->Fill(row3sumo);
    h_row2sumo->Fill(row2sumo);
    h_row4sumo->Fill(row4sumo);

      double temp1 = indpmt[30];
      double temp2 = indpmt[31];
      double temp3 = indpmt[32];
      double temp4 = indpmt[33];
      double temp5 = indpmt[34];
      double temp6 = indpmt[35];
      double temp7 = indpmt[36];
      double temp8 = indpmt[37];
      double temp9 = indpmt[38];
      double temp10 = indpmt[39];
      double temp11 = indpmt[40];
      double temp12 = indpmt[41];
      double temp13 = indpmt[42];
      double temp14 = indpmt[43];
      double temp15 = indpmt[44];
      double temp16 = indpmt[45];

      indpmt[30] = temp6;
      indpmt[31] = temp5;
      indpmt[32] = temp10;
      indpmt[33] = temp9;
      indpmt[34] = temp14;
      indpmt[35] = temp13;
      indpmt[36] = temp2;
      indpmt[37] = temp1;

      indpmt[38] = temp8;
      indpmt[39] = temp7;
      indpmt[40] = temp12;
      indpmt[41] = temp11;
      indpmt[42] = temp16;
      indpmt[43] = temp15;
      indpmt[44] = temp4;
      indpmt[45] = temp3;
 
    for (int j=0;j<46;j++){

      ratiox[j] -> Fill(indpmt[j]);
      ratiox2[j] -> Fill(indpmt[j]);
      ratiox3[j] -> Fill(indpmt[j]);
      ratiox4[j] -> Fill(indpmt[j]);
      ratiox5[j] -> Fill(indpmt[j]);
      ratiox6[j] -> Fill(indpmt[j]);
      ratiox7[j] -> Fill(indpmt[j]);
      ratiox8[j] -> Fill(indpmt[j]);
      ratiox9[j] -> Fill(indpmt[j]);
      ratiox10[j] -> Fill(indpmt[j]);
      ratiox11[j] -> Fill(indpmt[j]);
      ratiox12[j] -> Fill(indpmt[j]);
      ratiox13[j] -> Fill(indpmt[j]);
      ratiox14[j] -> Fill(indpmt[j]);
      ratiox15[j] -> Fill(indpmt[j]);
      ratiox16[j] -> Fill(indpmt[j]);
      ratiox17[j] -> Fill(indpmt[j]);
      ratiox18[j] -> Fill(indpmt[j]);
      ratiox19[j] -> Fill(indpmt[j]);
      ratiox20[j] -> Fill(indpmt[j]);
      ratiox21[j] -> Fill(indpmt[j]);
      ratiox22[j] -> Fill(indpmt[j]);
      ratiox23[j] -> Fill(indpmt[j]);
      ratiox24[j] -> Fill(indpmt[j]);
      ratiox25[j] -> Fill(indpmt[j]);
      ratiox26[j] -> Fill(indpmt[j]);
      ratiox27[j] -> Fill(indpmt[j]);
      ratiox28[j] -> Fill(indpmt[j]);      
      ratiox29[j] -> Fill(indpmt[j]);
      ratiox30[j] -> Fill(indpmt[j]);     

      if (indpmt[j] > 0)
      ratiox31[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox32[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox33[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox34[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox35[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox36[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox37[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox38[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox39[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox40[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox41[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox42[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox43[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox44[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox45[j] -> Fill(indpmt[j]);
      if (indpmt[j] > 0)
      ratiox46[j] -> Fill(indpmt[j]);      


      if (indpmt[j]/indpmt[0] > 0)
      ratioxx[j] -> Fill(indpmt[j]/indpmt[0]);
      if (indpmt[j]/indpmt[1] > 0)
      ratioxx2[j] -> Fill(indpmt[j]/indpmt[1]);
      if (indpmt[j]/indpmt[2] > 0)
      ratioxx3[j] -> Fill(indpmt[j]/indpmt[2]);
      if (indpmt[j]/indpmt[3] > 0)
      ratioxx4[j] -> Fill(indpmt[j]/indpmt[3]);
      if (indpmt[j]/indpmt[4] > 0)
      ratioxx5[j] -> Fill(indpmt[j]/indpmt[4]);
      if (indpmt[j]/indpmt[5] > 0)
      ratioxx6[j] -> Fill(indpmt[j]/indpmt[5]);
      if (indpmt[j]/indpmt[6] > 0)
      ratioxx7[j] -> Fill(indpmt[j]/indpmt[6]);
      if (indpmt[j]/indpmt[7] > 0)
      ratioxx8[j] -> Fill(indpmt[j]/indpmt[7]);
      if (indpmt[j]/indpmt[8] > 0)
      ratioxx9[j] -> Fill(indpmt[j]/indpmt[8]);
      if (indpmt[j]/indpmt[9] > 0)
      ratioxx10[j] -> Fill(indpmt[j]/indpmt[9]);
      if (indpmt[j]/indpmt[10] > 0)
      ratioxx11[j] -> Fill(indpmt[j]/indpmt[10]);
      if (indpmt[j]/indpmt[11] > 0)
      ratioxx12[j] -> Fill(indpmt[j]/indpmt[11]);
      if (indpmt[j]/indpmt[12] > 0)
      ratioxx13[j] -> Fill(indpmt[j]/indpmt[12]);
      if (indpmt[j]/indpmt[13] > 0)
      ratioxx14[j] -> Fill(indpmt[j]/indpmt[13]);
      if (indpmt[j]/indpmt[14] > 0)
      ratioxx15[j] -> Fill(indpmt[j]/indpmt[14]);
      if (indpmt[j]/indpmt[15] > 0)
      ratioxx16[j] -> Fill(indpmt[j]/indpmt[15]);
      if (indpmt[j]/indpmt[16] > 0)
      ratioxx17[j] -> Fill(indpmt[j]/indpmt[16]);
      if (indpmt[j]/indpmt[17] > 0)
      ratioxx18[j] -> Fill(indpmt[j]/indpmt[17]);
      if (indpmt[j]/indpmt[18] > 0)
      ratioxx19[j] -> Fill(indpmt[j]/indpmt[18]);
      if (indpmt[j]/indpmt[19] > 0)
      ratioxx20[j] -> Fill(indpmt[j]/indpmt[19]);
      if (indpmt[j]/indpmt[20] > 0)
      ratioxx21[j] -> Fill(indpmt[j]/indpmt[20]);
      if (indpmt[j]/indpmt[21] > 0)
      ratioxx22[j] -> Fill(indpmt[j]/indpmt[21]);
      if (indpmt[j]/indpmt[22] > 0)
      ratioxx23[j] -> Fill(indpmt[j]/indpmt[22]);
      if (indpmt[j]/indpmt[23] > 0)
      ratioxx24[j] -> Fill(indpmt[j]/indpmt[23]);
      if (indpmt[j]/indpmt[24] > 0)
      ratioxx25[j] -> Fill(indpmt[j]/indpmt[24]);
      if (indpmt[j]/indpmt[25] > 0)
      ratioxx26[j] -> Fill(indpmt[j]/indpmt[25]);
      if (indpmt[j]/indpmt[26] > 0)
      ratioxx27[j] -> Fill(indpmt[j]/indpmt[26]);
      if (indpmt[j]/indpmt[27] > 0)
      ratioxx28[j] -> Fill(indpmt[j]/indpmt[27]);
      if (indpmt[j]/indpmt[28] > 0)
      ratioxx29[j] -> Fill(indpmt[j]/indpmt[28]);
      if (indpmt[j]/indpmt[29] > 0)
      ratioxx30[j] -> Fill(indpmt[j]/indpmt[29]);
      if (indpmt[j]/indpmt[30] > 0)
      ratioxx31[j] -> Fill(indpmt[j]/indpmt[30]);
      if (indpmt[j]/indpmt[31] > 0)
      ratioxx32[j] -> Fill(indpmt[j]/indpmt[31]);
      if (indpmt[j]/indpmt[32] > 0)
      ratioxx33[j] -> Fill(indpmt[j]/indpmt[32]);
      if (indpmt[j]/indpmt[33] > 0)
      ratioxx34[j] -> Fill(indpmt[j]/indpmt[33]);
      if (indpmt[j]/indpmt[34] > 0)
      ratioxx35[j] -> Fill(indpmt[j]/indpmt[34]);
      if (indpmt[j]/indpmt[35] > 0)
      ratioxx36[j] -> Fill(indpmt[j]/indpmt[35]);
      if (indpmt[j]/indpmt[36] > 0)
      ratioxx37[j] -> Fill(indpmt[j]/indpmt[36]);
      if (indpmt[j]/indpmt[37] > 0)
      ratioxx38[j] -> Fill(indpmt[j]/indpmt[37]);
      if (indpmt[j]/indpmt[38] > 0)
      ratioxx39[j] -> Fill(indpmt[j]/indpmt[38]);
      if (indpmt[j]/indpmt[39] > 0)
      ratioxx40[j] -> Fill(indpmt[j]/indpmt[39]);
      if (indpmt[j]/indpmt[40] > 0)
      ratioxx41[j] -> Fill(indpmt[j]/indpmt[40]);
      if (indpmt[j]/indpmt[41] > 0)
      ratioxx42[j] -> Fill(indpmt[j]/indpmt[41]);
      if (indpmt[j]/indpmt[42] > 0)
      ratioxx43[j] -> Fill(indpmt[j]/indpmt[42]);
      if (indpmt[j]/indpmt[43] > 0)
      ratioxx44[j] -> Fill(indpmt[j]/indpmt[43]);
      if (indpmt[j]/indpmt[44] > 0)
      ratioxx45[j] -> Fill(indpmt[j]/indpmt[44]);
      if (indpmt[j]/indpmt[45] > 0)
      ratioxx46[j] -> Fill(indpmt[j]/indpmt[45]);

    }
  }

  cout<<"checking 40 and 44: " << ratiox41[44]->GetMean()<<" "<<ratiox45[40]->GetMean()<<endl;
  TCanvas* c1 = new TCanvas();
  c1->Divide(3,3);
  c1->cd(1);
  ratiox4[0]->SetTitle("Light ratio; pmt x/ pmt 4; Ratio");
  ratiox4[0]->Draw();
  for (int i=1; i<9;i++){
    c1->cd(i+1);
    ratiox4[i]->Draw();
  }
  TCanvas* c2 = new TCanvas();
  c2->Divide(3,3);
  c2->cd(1);
  ratiox9[0]->SetTitle("Light ratio; pmt x/ pmt 9; Ratio");
  ratiox9[0]->Draw();
  for (int i=1; i<9;i++){
    c2->cd(i+1);
    ratiox9[i]->Draw();
  }

  cout<<1<<endl;
  //in data

  double adc_b1_ch12w[50] = {0.,   0.,   0.,   0.,  27., 319., 649., 492., 205.,  89.,  21.,
         4.,   2.,   0.,   1.,   0.,   2.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch13w[50] = { 0.,   0.,   0.,   0.,   0.,  29., 141., 280., 414., 362., 264.,
       178.,  72.,  33.,  15.,  16.,   2.,   3.,   1.,   1.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch14w[50] = {0.,   0.,   0.,   0.,   0.,  10.,  25.,  62., 105., 174., 249.,
       232., 221., 185., 139., 103.,  82.,  53.,  38.,  33.,  26.,  17.,
        14.,  12.,   7.,   7.,   7.,   4.,   3.,   0.,   0.,   1.,   1.,
         0.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch15w[50] = {0.,   0.,   0.,   0.,   2.,   2.,  16.,  67.,  85., 107., 150.,
       169., 160., 131., 133., 121., 110.,  94.,  81.,  77.,  60.,  59.,
        38.,  35.,  20.,  15.,  15.,  20.,  13.,   7.,   4.,   4.,   3.,
         2.,   0.,   1.,   2.,   3.,   1.,   2.,   0.,   0.,   0.,   1.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch0w[50] = {0.,   0.,   0.,   0.,   1.,  11.,  37., 130., 189., 238., 213.,
       230., 187., 165.,  91.,  87.,  62.,  53.,  31.,  18.,  21.,  11.,
         9.,   6.,   9.,   2.,   1.,   0.,   2.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   1.,   1.,   0.,   0.,   0.,   0.,   1.,   0.,
         0.,   1.,   0.,   0.,   0.,   0.};
  double adc_b2_ch1w[50] = {0.,   0.,   0.,   0.,   2.,   5.,  21.,  38.,  89., 131., 206.,
       222., 231., 205., 165., 142.,  93.,  68.,  58.,  44.,  28.,  23.,
        11.,   3.,   3.,   3.,   1.,   1.,   1.,   1.,   2.,   0.,   3.,
         1.,   1.,   1.,   0.,   0.,   1.,   0.,   0.,   0.,   1.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch2w[50] = {0.,   0.,   0.,   0.,   2.,  11.,  62., 171., 269., 362., 330.,
       227., 174.,  95.,  52.,  19.,  15.,   8.,   3.,   2.,   3.,   1.,
         0.,   3.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch3w[50] = {0.,   0.,   0.,   0.,   2.,  17., 109., 257., 382., 374., 300.,
       185.,  91.,  47.,  24.,  10.,   4.,   2.,   3.,   0.,   0.,   0.,
         2.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch1w[50] = { 0.,   0.,   0.,   0.,   1.,  18., 108., 235., 313., 370., 294.,
       212., 125.,  72.,  33.,  14.,   6.,   4.,   4.,   1.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch2w[50] = {0.,   0.,   0.,   0.,   0.,  15.,  50., 179., 276., 371., 352.,
       232., 164.,  95.,  37.,  19.,   9.,   7.,   1.,   3.,   0.,   0.,
         0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch3w[50] = {0.,   0.,   0.,   0.,   1.,   7.,  35., 124., 241., 304., 359.,
       299., 181., 138.,  61.,  35.,  13.,   3.,   4.,   2.,   0.,   1.,
         0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch4w[50] = {0.,   0.,   0.,   0.,   3.,  88., 315., 459., 406., 261., 154.,
        81.,  22.,  12.,   4.,   2.,   1.,   0.,   0.,   1.,   0.,   0.,
         0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch5w[50] = {0.,   0.,   0.,   0.,   0.,  57., 193., 349., 428., 384., 218.,
       108.,  41.,  22.,   7.,   4.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch6w[50] = {0.,   0.,   0.,   0.,   3.,  38., 223., 404., 434., 370., 193.,
        95.,  35.,  14.,   2.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch7w[50] = {0.,   0.,   0.,   0.,   2.,  21., 104., 248., 370., 391., 308.,
       180., 102.,  48.,  22.,   5.,   6.,   3.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch8w[50] = {0.,   0.,   0.,   0.,   1.,   9.,  23.,  68., 136., 204., 259.,
       250., 255., 200., 152.,  93.,  59.,  38.,  25.,  12.,   5.,   5.,
         5.,   1.,   1.,   2.,   0.,   0.,   1.,   1.,   0.,   0.,   0.,
         0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   2.,   0};
  double adc_b1_ch9w[50] = {0.,   0.,   0.,   0.,   1.,   4.,   2.,   7.,  28.,  42.,  95.,
       118., 186., 195., 233., 195., 155., 134.,  90.,  64.,  56.,  55.,
        29.,  13.,  15.,  12.,   7.,   7.,   2.,   8.,   3.,   3.,   2.,
         5.,   6.,   2.,   3.,   2.,   3.,   3.,   3.,   1.,   0.,   1.,
         7.,   0.,   1.,   0.,   0.,   1.};
  double adc_b1_ch10w[50] = { 0.,   0.,   0.,   0.,   1.,  29.,   8.,  31.,  85., 163., 242.,
       281., 261., 187., 157., 103.,  86.,  58.,  33.,  24.,   7.,  10.,
         6.,   7.,   6.,   4.,   2.,   2.,   1.,   1.,   0.,   2.,   2.,
         0.,   2.,   0.,   1.,   1.,   0.,   1.,   1.,   1.,   0.,   0.,
         0.,   1.,   0.,   0.,   0.,   0.};
  double adc_b1_ch11w[50] = {0.,   0.,   0.,   0.,   2.,   1.,   8.,  51., 138., 238., 318.,
       317., 237., 165., 118.,  89.,  59.,  29.,  12.,  10.,   4.,   5.,
         2.,   1.,   2.,   0.,   1.,   1.,   1.,   0.,   0.,   0.,   1.,
         0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch4w[50] = {0.,   0.,   0.,   0.,  35., 385., 584., 448., 238.,  96.,  20.,
         5.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch5w[50] = {0.,   0.,   0.,   0.,   6., 132., 324., 446., 371., 237., 135.,
        79.,  39.,  25.,   7.,   5.,   1.,   1.,   2.,   1.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch6w[50] = { 0.,   0.,   0.,   0.,   2.,  10.,  31.,  63., 126., 201., 216.,
       204., 174., 167., 113.,  88.,  83.,  70.,  48.,  45.,  39.,  30.,
        20.,  15.,  19.,  18.,   3.,   8.,   4.,   4.,   1.,   3.,   2.,
         2.,   1.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch7w[50] = {0.,   0.,   0.,   0.,   3.,  33., 134., 239., 347., 317., 253.,
       146., 101.,  69.,  48.,  30.,  25.,  11.,  13.,   4.,  15.,   3.,
         4.,   8.,   1.,   1.,   4.,   0.,   0.,   0.,   1.,   1.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch8w[50] = {0.,   0.,   0.,   0.,   0.,   3.,   8.,  25.,  66., 137., 199.,
       226., 239., 240., 191., 148., 123.,  93.,  47.,  26.,  15.,   9.,
         5.,   5.,   5.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch9w[50] = { 0.,   0.,   0.,   0.,   3.,  92., 375., 509., 436., 233., 106.,
        39.,   8.,   3.,   6.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch10w[50] = {0.,   0.,   0.,   0.,   4.,  48., 250., 438., 460., 310., 169.,
        84.,  27.,  15.,   4.,   0.,   2.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch11w[50] = {0.,   0.,   0.,   0.,  30., 421., 620., 463., 201.,  55.,  17.,
         3.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch12w[50] = {0.,   0.,   0.,   0.,  12., 238., 502., 528., 312., 147.,  50.,
        18.,   2.,   2.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch13w[50] = {0.,   0.,   0.,   0.,   8., 120., 364., 569., 411., 224.,  77.,
        20.,  11.,   3.,   2.,   0.,   0.,   2.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch14w[50] = {0.,   0.,   0.,   0.,   2.,  82., 363., 490., 416., 286., 109.,
        44.,  16.,   0.,   2.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch2w[50] = { 0.,   0.,   0.,   0.,   0.,  40., 147., 309., 379., 360., 283.,
       150.,  80.,  34.,  18.,   6.,   2.,   1.,   2.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch3w[50] = {0.,   0.,   0.,   0.,   1.,  19., 109., 256., 361., 355., 305.,
       173.,  96.,  55.,  28.,  15.,  17.,   7.,   5.,   2.,   4.,   2.,
         0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch6w[50] = {0.,   0.,   0.,   0.,  11., 300., 606., 452., 260., 107.,  42.,
        23.,   5.,   1.,   4.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch7w[50] = {0.,   0.,   0.,   0.,  13., 222., 533., 533., 287., 136.,  42.,
        31.,   6.,   3.,   2.,   3.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch10w[50] = {0.,   0.,   0.,   0.,   2., 124., 333., 407., 374., 250., 172.,
        77.,  36.,  19.,   7.,   5.,   2.,   1.,   2.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch11w[50] = {0.,   0.,   0.,   0.,  11., 157., 384., 412., 322., 206., 136.,
        68.,  59.,  27.,  11.,  12.,   3.,   1.,   0.,   0.,   1.,   0.,
         1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch14w[50] = {0.,   0.,   0.,   0.,  69., 569., 595., 309., 138.,  70.,  36.,
        14.,   7.,   2.,   2.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch15w[50] = { 0.,   0.,   0.,   0., 207., 879., 421., 161.,  70.,  40.,  16.,
         6.,   2.,   5.,   0.,   4.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};

  double adc_b3_ch0w[50] = {0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 2.000e+02, 1.022e+03,
       4.460e+02, 1.130e+02, 1.900e+01, 7.000e+00, 1.000e+00, 2.000e+00,
       0.000e+00, 1.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00};
  double adc_b3_ch1w[50] = {0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 2.270e+02, 1.022e+03,
       4.050e+02, 1.010e+02, 3.400e+01, 1.100e+01, 5.000e+00, 1.000e+00,
       1.000e+00, 2.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       1.000e+00, 0.000e+00, 0.000e+00, 1.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00};
  double adc_b3_ch4w[50] = {0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 1.820e+02, 1.075e+03,
       4.670e+02, 7.500e+01, 9.000e+00, 2.000e+00, 1.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00};
  double adc_b3_ch5w[50] = {0.,    0.,    0.,    0.,  255., 1103.,  333.,   95.,   20.,
          2.,    3.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,
          0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,
          0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,
          0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,
          0.,    0.,    0.,    0.,    0.};
  double adc_b3_ch8w[50] = {0.,   0.,   0.,   0., 164., 941., 496., 149.,  41.,  15.,   2.,
         2.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch9w[50] = {0.,   0.,   0.,   0., 175., 994., 444., 143.,  32.,   9.,   4.,
         4.,   4.,   0.,   1.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch12w[50] = {0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 2.140e+02, 1.094e+03,
       4.110e+02, 7.400e+01, 1.500e+01, 0.000e+00, 0.000e+00, 2.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 1.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00,
       0.000e+00, 0.000e+00};
  double adc_b3_ch13w[50] = {0.,   0.,   0.,   0., 156., 853., 544., 203.,  43.,   8.,   3.,
         1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_botw[50] = {2.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   2.,   2.,
         7.,  14.,  47., 101., 234., 294., 311., 291., 195., 112.,  66.,
        51.,  25.,  14.,  17.,   9.,   6.,   6.,   2.,   3.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  
  double adc_row1w[50] = {0.,   0.,   0.,   0.,   5.,  90., 353., 472., 407., 237., 133.,
        62.,  23.,  14.,   4.,   4.,   4.,   1.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   1.,   1.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_row2w[50] = {0.,   0.,   0.,   0.,   7., 110., 322., 440., 359., 253., 158.,
        64.,  40.,  19.,  11.,   9.,   5.,   6.,   3.,   1.,   1.,   1.,
         1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_row3w[50] = {0.,   0.,   0.,   0.,   0.,   1.,   1.,   1.,   5.,  18.,  48.,
        76., 110., 183., 202., 228., 210., 182., 147., 130.,  71.,  65.,
        47.,  25.,  16.,  13.,   9.,   8.,   7.,   3.,   1.,   2.,   1.,
         1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_row4w[50] = {0.,   0.,   0.,   0.,   0.,   1.,   2.,   0.,   8.,  25.,  48.,
        87., 138., 166., 175., 206., 227., 181., 147., 115.,  87.,  58.,
        40.,  25.,  18.,  18.,   4.,   8.,  11.,   3.,   3.,   3.,   2.,
         4.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};


  double adc_b1_ch12[50] = {0.,   0.,   0.,   0.,  13., 206., 721., 876., 651., 342., 143.,
        48.,  15.,   9.,   1.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch13[50] = {0.,   0.,   0.,   0.,   0.,  23., 100., 293., 456., 536., 557.,
       419., 283., 166., 100.,  44.,  26.,   8.,   6.,   2.,   5.,   1.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   1.,   0.,   0.,   0.};
  double adc_b1_ch14[50] = {0.,   0.,   0.,   0.,   0.,   5.,  58., 139., 297., 418., 497.,
       478., 334., 295., 168., 110.,  70.,  50.,  35.,  22.,  23.,  13.,
         5.,   5.,   3.,   1.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b1_ch15[50] = {0.,   0.,   0.,   0.,   0.,   0.,   9.,  42.,  90., 159., 248.,
       305., 273., 259., 255., 252., 231., 167., 162., 128., 109.,  81.,
        64.,  56.,  28.,  25.,  17.,  17.,  10.,   7.,   6.,   8.,   2.,
         3.,   1.,   0.,   1.,   1.,   1.,   1.,   0.,   0.,   1.,   0.,
         0.,   1.,   2.,   0.,   0.,   0.};
  double adc_b2_ch0[50] = {0.,   0.,   0.,   0.,   0.,   2.,  32.,  92., 202., 281., 367.,
       356., 368., 314., 263., 195., 129., 117.,  83.,  62.,  44.,  30.,
        20.,  12.,  13.,   6.,   6.,   5.,   3.,   3.,   3.,   4.,   0.,
         2.,   1.,   2.,   1.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   2.};
  double adc_b2_ch1[50] = {0.,   0.,   0.,   0.,   0.,   2.,  17.,  56., 100., 161., 255.,
       380., 389., 376., 315., 258., 233., 138., 100.,  67.,  55.,  29.,
        17.,  17.,  16.,   9.,   4.,   4.,   3.,   3.,   0.,   2.,   1.,
         4.,   1.,   2.,   0.,   1.,   1.,   1.,   1.,   3.,   2.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch2[50] = {0.,   0.,   0.,   0.,   0.,   4.,  29., 123., 293., 492., 582.,
       492., 421., 234., 172.,  71.,  46.,  24.,  11.,   7.,   6.,   0.,
         3.,   2.,   0.,   2.,   2.,   2.,   0.,   0.,   3.,   0.,   0.,
         0.,   1.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch3[50] = {0.,   0.,   0.,   0.,   0.,   1.,  23., 103., 226., 389., 495.,
       545., 450., 307., 202., 144.,  56.,  40.,  19.,  10.,  10.,   0.,
         2.,   2.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         1.,   0.,   0.,   0.,   1.,   0.};

////////////////////////////////////////////////////////////////////
//
//
  double adc_b1_ch1[50] = {0.,   0.,   0.,   0.,   2.,  19.,  95., 253., 418., 500., 550.,
       402., 302., 194., 136.,  79.,  40.,  16.,  10.,   4.,   4.,   0.,
         0.,   1.,   0.,   0.,   0.,   1.,   0.,   0.,   1.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b1_ch2[50] = {0.,   0.,   0.,   0.,   0.,  11.,  51., 204., 403., 584., 584.,
       489., 317., 203.,  95.,  40.,  24.,   8.,   5.,   5.,   1.,   1.,
         0.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b1_ch3[50] = {0.,   0.,   0.,   0.,   0.,   0.,  14.,  62., 145., 314., 395.,
       504., 489., 400., 284., 176.,  99.,  51.,  41.,  28.,  11.,   4.,
         3.,   2.,   1.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,
         0.,   0.,   0.,   0.,   0.,   1. };
  double adc_b1_ch4[50] = {0.,   0.,   0.,   0.,   2.,  40., 200., 392., 597., 584., 449.,
       358., 185., 105.,  54.,  27.,  12.,  10.,   4.,   2.,   2.,   1.,
         1.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b1_ch5[50] = {0.,   0.,   0.,   0.,   0.,  19.,  97., 287., 490., 586., 582.,
       426., 243., 148.,  82.,  33.,  16.,   9.,   5.,   1.,   2.,   0.,
         0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b1_ch6[50] = {0.,   0.,   0.,   0.,   1.,  17.,  90., 276., 493., 590., 572.,
       429., 256., 162.,  65.,  41.,  19.,   7.,   3.,   4.,   2.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b1_ch7[50] = { 0.,   0.,   0.,   0.,   1.,  17.,  83., 223., 469., 534., 597.,
       419., 314., 183.,  93.,  47.,  21.,  11.,   7.,   4.,   1.,   0.,
         1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   1.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b1_ch8[50] = {0.,   0.,   0.,   0.,   0.,   1.,  11.,  45., 113., 198., 295.,
       359., 411., 378., 327., 252., 212., 126.,  94.,  64.,  45.,  21.,
        16.,  13.,   9.,   7.,   2.,   4.,   2.,   1.,   2.,   4.,   3.,
         2.,   0.,   0.,   1.,   1.,   1.,   1.,   0.,   0.,   0.,   1.,
         0.,   0.,   0.,   1.,   0.,   0. };
  double adc_b1_ch9[50] = {0.,   0.,   0.,   0.,   0.,   1.,   0.,   4.,   7.,  28.,  46.,
        70., 133., 160., 225., 239., 268., 260., 244., 234., 196., 147.,
       145., 116.,  86.,  81.,  51.,  44.,  34.,  32.,  24.,  19.,  18.,
         6.,   8.,   6.,   7.,   4.,   3.,   7.,   3.,   4.,   4.,   7.,
         1.,   2.,   2.,   1.,   4.,   4. };
  double adc_b1_ch10[50] = {0.,   0.,   0.,   0.,   0.,   0.,   3.,  11.,  34.,  99., 177.,
       296., 362., 417., 371., 345., 234., 177., 150.,  89.,  56.,  53.,
        38.,  19.,  20.,  12.,  11.,  11.,   6.,   7.,   5.,   3.,   1.,
         2.,   0.,   4.,   3.,   2.,   0.,   0.,   0.,   1.,   0.,   0.,
         0.,   0.,   1.,   1.,   0.,   1. };  
  double adc_b1_ch11[50] = {0.,   0.,   0.,   0.,   0.,   0.,   3.,  19.,  61., 135., 210.,
       309., 381., 411., 409., 316., 236., 167., 115.,  80.,  50.,  41.,
        18.,  18.,   8.,  11.,   6.,   1.,   3.,   3.,   4.,   0.,   3.,
         0.,   0.,   2.,   0.,   0.,   0.,   3.,   0.,   1.,   0.,   0.,
         0.,   1.,   0.,   0.,   0.,   0. };

  double adc_b2_ch4[50] = {0.,   0.,   0.,   0.,  20., 362., 852., 855., 560., 262.,  78.,
        24.,  11.,   3.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b2_ch5[50] = {0.,   0.,   0.,   0.,   3.,  94., 347., 602., 664., 511., 358.,
       212., 110.,  65.,  31.,  16.,   5.,   4.,   3.,   0.,   1.,   1.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };  
  double adc_b2_ch6[50] = {0.,   0.,   0.,   0.,   0.,   2.,  20., 104., 187., 314., 378.,
       412., 375., 280., 202., 155., 134., 105., 101.,  62.,  50.,  38.,
        21.,  34.,  20.,   8.,   8.,   7.,   5.,   2.,   2.,   0.,   0.,
         0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b2_ch7[50] = {0.,   0.,   0.,   0.,   0.,  13., 105., 224., 363., 462., 504.,
       382., 282., 205., 135.,  85.,  64.,  51.,  40.,  21.,  31.,  17.,
        13.,   8.,   6.,   5.,   4.,   3.,   0.,   2.,   0.,   0.,   0.,
         1.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b2_ch8[50] = {0.,   0.,   0.,   0.,   0.,   1.,   4.,  16.,  55., 131., 221.,
       295., 377., 390., 374., 296., 244., 194., 153., 100.,  71.,  47.,
        22.,  16.,   8.,   4.,   2.,   0.,   0.,   1.,   0.,   1.,   1.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };  
  double adc_b2_ch9[50] = {0.,   0.,   0.,   0.,   1., 153., 666., 941., 747., 330., 133.,
        40.,   7.,   4.,   2.,   2.,   0.,   1.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b2_ch10[50] = { 0.,   0.,   0.,   0.,   0.,  40., 193., 446., 679., 624., 485.,
       301., 131.,  83.,  26.,  10.,   6.,   2.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b2_ch11[50] = {0.,   0.,   0.,   0.,  20., 344., 842., 868., 588., 245.,  75.,
        28.,   9.,   4.,   3.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b2_ch12[50] = {0.,   0.,   0.,   0.,  13., 233., 718., 835., 630., 333., 169.,
        66.,  20.,   7.,   1.,   1.,   0.,   1.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };  
  double adc_b2_ch13[50] = {0.,   0.,   0.,   0.,   2., 166., 668., 988., 731., 316., 112.,
        30.,  11.,   2.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };
  double adc_b2_ch14[50] = {0.,   0.,   0.,   0.,   0.,  67., 359., 652., 719., 593., 381.,
       157.,  56.,  28.,   6.,   4.,   1.,   3.,   1.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0. };

  double adc_b3_ch2[50] = {0.,   0.,   0.,   0.,   0.,   1.,   9.,  16.,  53., 149., 221.,
       352., 425., 446., 387., 293., 229., 137.,  99.,  74.,  47.,  31.,
        13.,  14.,  17.,   5.,   1.,   4.,   1.,   1.,   1.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch3[50] = {0.,   0.,   0.,   0.,   0.,   0.,   2.,  10.,  46., 108., 192.,
       310., 400., 439., 380., 329., 252., 171., 118.,  94.,  43.,  45.,
        26.,  16.,  11.,   8.,   6.,   7.,   1.,   4.,   1.,   1.,   1.,
         2.,   1.,   0.,   2.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch6[50] = {0.,   0.,   0.,   0.,   0.,   9.,  32., 138., 289., 396., 532.,
       471., 384., 301., 196., 124.,  61.,  39.,  22.,  11.,   7.,   7.,
         2.,   3.,   0.,   0.,   1.,   1.,   0.,   1.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch7[50] = {0.,   0.,   0.,   0.,   0.,   5.,  54., 224., 437., 587., 535.,
       485., 305., 172.,  96.,  66.,  28.,  15.,   8.,   3.,   2.,   0.,
         0.,   3.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch10[50] = {0.,   0.,   0.,   0.,   1.,   5.,  35.,  86., 192., 313., 453.,
       449., 419., 374., 236., 175., 111.,  61.,  48.,  27.,  14.,   8.,
        11.,   5.,   2.,   1.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch11[50] = {0.,   0.,   0.,   0.,   0.,  15.,  27., 154., 253., 336., 438.,
       417., 407., 304., 228., 159.,  97.,  58.,  53.,  26.,  21.,   9.,
         9.,   3.,   4.,   0.,   0.,   3.,   3.,   1.,   0.,   0.,   0.,
         1.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch14[50] = {0.,   0.,   0.,   0.,   0.,  39., 239., 453., 671., 599., 428.,
       263., 172.,  83.,  36.,  21.,  13.,   4.,   4.,   0.,   1.,   1.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch15[50] = {0.,   0.,   0.,   0.,   7., 135., 479., 728., 681., 481., 251.,
       134.,  64.,  28.,  24.,   6.,   3.,   3.,   2.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};

  double adc_b3_ch0[50] = {0.,   0.,   0.,   0.,   0.,  12., 101., 308., 541., 631., 560.,
       376., 246., 119.,  54.,  42.,  10.,   9.,   7.,   1.,   2.,   1.,
         1.,   4.,   0.,   1.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch1[50] = {0.,   0.,   0.,   0.,   0.,  15., 100., 263., 416., 577., 571.,
       421., 276., 175., 104.,  47.,  30.,  11.,   7.,   5.,   4.,   2.,
         0.,   0.,   0.,   0.,   0.,   1.,   0.,   0.,   1.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch4[50] = {0.,   0.,   0.,   0.,   0.,  89., 414., 737., 751., 546., 287.,
       124.,  47.,  20.,   4.,   3.,   3.,   0.,   1.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch5[50] = {0.,   0.,   0.,   0.,   1., 124., 478., 802., 742., 489., 234.,
       101.,  43.,   6.,   4.,   2.,   1.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch8[50] = {0.,   0.,   0.,   0.,   0.,   1.,   4.,  24.,  54., 121., 149.,
       243., 237., 283., 307., 301., 250., 210., 228., 144., 131.,  99.,
        63.,  45.,  31.,  29.,  17.,   9.,  11.,  10.,   3.,   5.,   9.,
         3.,   1.,   1.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,
         1.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch9[50] = {0.,   0.,   0.,   0.,   0.,  10.,  78., 234., 453., 636., 581.,
       420., 276., 153.,  73.,  43.,  35.,  13.,   8.,   5.,   3.,   2.,
         1.,   0.,   2.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch12[50] = {0.,   0.,   0.,   0.,   1.,  55., 234., 510., 687., 563., 438.,
       253., 158.,  74.,  29.,   9.,   7.,   5.,   1.,   0.,   1.,   0.,
         0.,   1.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_b3_ch13[50] = {0.,   0.,   0.,   0.,   2.,  39., 210., 423., 637., 613., 461.,
       287., 187.,  92.,  45.,  12.,   8.,   2.,   2.,   2.,   0.,   2.,
         0.,   1.,   0.,   0.,   1.,   0.,   0.,   0.,   1.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};

  double adc_bot[50] = {0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   2.,   9.,   7.,  32.,  91., 235., 375., 451., 473., 410.,
       301., 195., 117.,  90.,  64.,  37.,  40.,  24.,  20.,  15.,   8.,
        15.,   4.,   7.,   4.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.};
  double adc_row1[50] = {0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   1.,   2.,   3.,   6.,   8.,  26.,  46.,  58., 104., 129.,
       149., 164., 189., 203., 237., 205., 207., 210., 166., 147., 148.,
       106.,  92.,  70.,  70.,  39.,  39.,  36.,  23.,  24.,  11.,  18.,
        24.,  10.,  11.,   9.,   4.,   4.};
  double adc_row2[50] = {0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         2.,   1.,  10.,  29.,  46.,  66., 116., 166., 196., 238., 274.,
       280., 300., 268., 231., 180., 138., 113.,  89.,  71.,  48.,  35.,
        25.,  17.,  15.,  14.,  13.,  12.,   5.,   6.,   3.,   3.,   3.,
         4.,   1.,   2.,   0.,   2.,   0.};
  double adc_row3[50] = {0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,
         1.,   0.,   2.,   1.,   2.,   1.,   4.,   8.,  10.,  22.,  31.,
        39.,  77.,  94., 106., 162., 186., 187., 231., 244., 191., 252.,
       170., 184., 138., 121.,  93.,  84.,  56.,  59.,  57.,  33.,  26.,
        28.,  22.,  23.,  15.,   8.,   9.};
  double adc_row4[50] = {0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         1.,   2.,   3.,   4.,   3.,   7.,   9.,  11.,  25.,  37.,  64.,
        77., 124., 131., 168., 200., 226., 238., 222., 220., 199., 184.,
       142., 133.,  93.,  92.,  84.,  40.,  47.,  35.,  27.,  28.,  29.,
        13.,  17.,  17.,  11.,  13.,   6.};

  cout<<2<<endl;
  TH1F* h1_ch[46]; 
  for (int i=0;i<46;i++)
    h1_ch[i] = new TH1F("","",50,-10,90);

  TH1F* h1_bot = new TH1F("","",50,-10,900);
  TH1F* h1_row1 = new TH1F("","",50,-10,90);
  TH1F* h1_row2 = new TH1F("","",50,-10,90);
  TH1F* h1_row3 = new TH1F("","",50,-10,90);
  TH1F* h1_row4 = new TH1F("","",50,-10,90);
  for (int i=0;i<50;i++){
    h1_ch[0]->SetBinContent(i+1, adc_b1_ch1[i]);
    h1_ch[1]->SetBinContent(i+1, adc_b1_ch2[i]);
    h1_ch[2]->SetBinContent(i+1, adc_b1_ch3[i]);
    h1_ch[3]->SetBinContent(i+1, adc_b1_ch4[i]);
    h1_ch[4]->SetBinContent(i+1, adc_b1_ch5[i]);
    h1_ch[5]->SetBinContent(i+1, adc_b1_ch6[i]);
    h1_ch[6]->SetBinContent(i+1, adc_b1_ch7[i]);    
    h1_ch[7]->SetBinContent(i+1, adc_b1_ch8[i]);
    h1_ch[8]->SetBinContent(i+1, adc_b1_ch9[i]);
    h1_ch[9]->SetBinContent(i+1, adc_b1_ch10[i]);
    h1_ch[10]->SetBinContent(i+1, adc_b1_ch11[i]);
    h1_ch[11]->SetBinContent(i+1, adc_b1_ch12[i]);
    h1_ch[12]->SetBinContent(i+1, adc_b1_ch13[i]);
    h1_ch[13]->SetBinContent(i+1, adc_b1_ch14[i]);
    h1_ch[14]->SetBinContent(i+1, adc_b1_ch15[i]);

    h1_ch[15]->SetBinContent(i+1, adc_b2_ch0[i]);
    h1_ch[16]->SetBinContent(i+1, adc_b2_ch1[i]);
    h1_ch[17]->SetBinContent(i+1, adc_b2_ch2[i]);
    h1_ch[18]->SetBinContent(i+1, adc_b2_ch3[i]);
    h1_ch[19]->SetBinContent(i+1, adc_b2_ch4[i]);
    h1_ch[20]->SetBinContent(i+1, adc_b2_ch5[i]);
    h1_ch[21]->SetBinContent(i+1, adc_b2_ch6[i]);
    h1_ch[22]->SetBinContent(i+1, adc_b2_ch7[i]);
    h1_ch[23]->SetBinContent(i+1, adc_b2_ch8[i]);
    h1_ch[24]->SetBinContent(i+1, adc_b2_ch9[i]);
    h1_ch[25]->SetBinContent(i+1, adc_b2_ch10[i]);
    h1_ch[26]->SetBinContent(i+1, adc_b2_ch11[i]);
    h1_ch[27]->SetBinContent(i+1, adc_b2_ch12[i]);
    h1_ch[28]->SetBinContent(i+1, adc_b2_ch13[i]);
    h1_ch[29]->SetBinContent(i+1, adc_b2_ch14[i]);

    h1_ch[30]->SetBinContent(i+1, adc_b3_ch2[i]);
    h1_ch[31]->SetBinContent(i+1, adc_b3_ch3[i]);
    h1_ch[32]->SetBinContent(i+1, adc_b3_ch6[i]);
    h1_ch[33]->SetBinContent(i+1, adc_b3_ch7[i]);
    h1_ch[34]->SetBinContent(i+1, adc_b3_ch10[i]);
    h1_ch[35]->SetBinContent(i+1, adc_b3_ch11[i]);
    h1_ch[36]->SetBinContent(i+1, adc_b3_ch14[i]);
    h1_ch[37]->SetBinContent(i+1, adc_b3_ch15[i]);

    h1_ch[38]->SetBinContent(i+1, adc_b3_ch0[i]);
    h1_ch[39]->SetBinContent(i+1, adc_b3_ch1[i]);
    h1_ch[40]->SetBinContent(i+1, adc_b3_ch4[i]);
    h1_ch[41]->SetBinContent(i+1, adc_b3_ch5[i]);
    h1_ch[42]->SetBinContent(i+1, adc_b3_ch8[i]);
    h1_ch[43]->SetBinContent(i+1, adc_b3_ch9[i]);
    h1_ch[44]->SetBinContent(i+1, adc_b3_ch12[i]);
    h1_ch[45]->SetBinContent(i+1, adc_b3_ch13[i]);

    h1_bot->SetBinContent(i+1, adc_bot[i]);

    h1_row1->SetBinContent(i+1,adc_row1[i]);
    h1_row2->SetBinContent(i+1,adc_row2[i]);
    h1_row3->SetBinContent(i+1,adc_row3[i]);
    h1_row4->SetBinContent(i+1,adc_row4[i]);
  }

  cout<<"3.1"<<endl;
  TH1F* h1_chw[46];
  for (int i=0;i<46;i++)
    h1_chw[i] = new TH1F("","",50,-10,90);

  TH1F* h1_botw = new TH1F("","",50,-10,900);
  TH1F* h1_row1w = new TH1F("","",50,-10,90);
  TH1F* h1_row2w = new TH1F("","",50,-10,90);
  TH1F* h1_row3w = new TH1F("","",50,-10,90);
  TH1F* h1_row4w = new TH1F("","",50,-10,90);

  for (int i=0;i<46;i++){
    h1_chw[0]->SetBinContent(i+1, adc_b1_ch1w[i]);
    h1_chw[1]->SetBinContent(i+1, adc_b1_ch2w[i]);
    h1_chw[2]->SetBinContent(i+1, adc_b1_ch3w[i]);
    h1_chw[3]->SetBinContent(i+1, adc_b1_ch4w[i]);
    h1_chw[4]->SetBinContent(i+1, adc_b1_ch5w[i]);
    h1_chw[5]->SetBinContent(i+1, adc_b1_ch6w[i]);
    h1_chw[6]->SetBinContent(i+1, adc_b1_ch7w[i]);
    h1_chw[7]->SetBinContent(i+1, adc_b1_ch8w[i]);
    h1_chw[8]->SetBinContent(i+1, adc_b1_ch9w[i]);
    h1_chw[9]->SetBinContent(i+1, adc_b1_ch10w[i]);
    h1_chw[10]->SetBinContent(i+1, adc_b1_ch11w[i]);
    h1_chw[11]->SetBinContent(i+1, adc_b1_ch12w[i]);
    h1_chw[12]->SetBinContent(i+1, adc_b1_ch13w[i]);
    h1_chw[13]->SetBinContent(i+1, adc_b1_ch14w[i]);
    h1_chw[14]->SetBinContent(i+1, adc_b1_ch15w[i]);

    h1_chw[15]->SetBinContent(i+1, adc_b2_ch0w[i]);
    h1_chw[16]->SetBinContent(i+1, adc_b2_ch1w[i]);
    h1_chw[17]->SetBinContent(i+1, adc_b2_ch2w[i]);
    h1_chw[18]->SetBinContent(i+1, adc_b2_ch3w[i]);
    h1_chw[19]->SetBinContent(i+1, adc_b2_ch4w[i]);
    h1_chw[20]->SetBinContent(i+1, adc_b2_ch5w[i]);
    h1_chw[21]->SetBinContent(i+1, adc_b2_ch6w[i]);
    h1_chw[22]->SetBinContent(i+1, adc_b2_ch7w[i]);
    h1_chw[23]->SetBinContent(i+1, adc_b2_ch8w[i]);
    h1_chw[24]->SetBinContent(i+1, adc_b2_ch9w[i]);
    h1_chw[25]->SetBinContent(i+1, adc_b2_ch10w[i]);
    h1_chw[26]->SetBinContent(i+1, adc_b2_ch11w[i]);
    h1_chw[27]->SetBinContent(i+1, adc_b2_ch12w[i]);
    h1_chw[28]->SetBinContent(i+1, adc_b2_ch13w[i]);
    h1_chw[29]->SetBinContent(i+1, adc_b2_ch14w[i]);

    h1_chw[30]->SetBinContent(i+1, adc_b3_ch2w[i]);
    h1_chw[31]->SetBinContent(i+1, adc_b3_ch3w[i]);
    h1_chw[32]->SetBinContent(i+1, adc_b3_ch6w[i]);
    h1_chw[33]->SetBinContent(i+1, adc_b3_ch7w[i]);
    h1_chw[34]->SetBinContent(i+1, adc_b3_ch10w[i]);
    h1_chw[35]->SetBinContent(i+1, adc_b3_ch11w[i]);
    h1_chw[36]->SetBinContent(i+1, adc_b3_ch14w[i]);
    h1_chw[37]->SetBinContent(i+1, adc_b3_ch15w[i]);

    h1_chw[38]->SetBinContent(i+1, adc_b3_ch0w[i]);
    h1_chw[39]->SetBinContent(i+1, adc_b3_ch1w[i]);
    h1_chw[40]->SetBinContent(i+1, adc_b3_ch4w[i]);
    h1_chw[41]->SetBinContent(i+1, adc_b3_ch5w[i]);
    h1_chw[42]->SetBinContent(i+1, adc_b3_ch8w[i]);
    h1_chw[43]->SetBinContent(i+1, adc_b3_ch9w[i]);
    h1_chw[44]->SetBinContent(i+1, adc_b3_ch12w[i]);
    h1_chw[45]->SetBinContent(i+1, adc_b3_ch13w[i]);

    h1_botw->SetBinContent(i+1, adc_botw[i]);

    h1_row1w->SetBinContent(i+1,adc_row1w[i]);
    h1_row2w->SetBinContent(i+1,adc_row2w[i]);
    h1_row3w->SetBinContent(i+1,adc_row3w[i]);
    h1_row4w->SetBinContent(i+1,adc_row4w[i]);

  }


  // from water, the relative-efficiency-corrected total bottom PE mean in MC / Data
  double grand_ratio = h1_botw->GetMean()/658.;

  // mean PE in water data on the bottom 313, wbls 
  cout<<"-----------------------------------------------------------------------"<<endl;
  cout<<" -------------  average data scint: "<<h1_bot->GetMean()-h1_botw->GetMean()<<endl;
  cout<<" -------------  average MC   scint: "<<h_botsumo_c->GetMean()-h_botsumo_cw->GetMean()<<endl;
  cout<<" -------------  DATA all and water: "<<h1_bot->GetMean()<<" "<<h1_botw->GetMean()<<endl;
  cout<<" -------------  MC   all and water: "<<h_botsumo_c->GetMean()<<" "<<h_botsumo_cw->GetMean()<<endl;
  cout<<" -------------  grand ratio       : "<<grand_ratio<<endl;
  cout<<" -------------- final light yield : "<< (h1_bot->GetMean()-h1_botw->GetMean()) * 234./((h_botsumo_c->GetMean() - h_botsumo_cw->GetMean())*grand_ratio)<<endl;

  new TCanvas();
  h1_bot->SetLineWidth(4);
  h1_botw->SetLineWidth(4);
  h_botsumo_c->SetLineWidth(4);
  h_botsumo_cw->SetLineWidth(4);
  h1_bot->SetLineColor(1);
  h1_botw->SetLineColor(1);
  h_botsumo_c->SetLineColor(2);
  h_botsumo_cw->SetLineColor(2);
  h1_botw->SetLineStyle(2);
  h_botsumo_cw->SetLineStyle(2);
  h1_bot->Scale(1./h1_bot->Integral());
  h1_botw->Scale(1./h1_botw->Integral());
  h_botsumo_c->Scale(1./h_botsumo_c->Integral());
  h_botsumo_cw->Scale(1./h_botsumo_cw->Integral());
  h_botsumo_cw->SetTitle(";PE number;Counts");
  h_botsumo_cw->Draw("");
  h1_botw->Draw("same");
  //h1_bot->Draw("same");
  //h_botsumo_c->Draw("same");

  TLegend* leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  //leg1->AddEntry(h1_bot ,"Data WbLS","l");
  leg1->AddEntry(h1_botw ,"Data Water","l");
  //leg1->AddEntry(h_botsumo_c ,"MC WbLS","l");
  leg1->AddEntry(h_botsumo_cw ,"MC Water","l");
  leg1->SetBorderSize(2);
  leg1->SetTextFont(62);
  leg1->SetFillColor(1);
  leg1->SetLineColor(1);
  leg1->SetShadowColor(0);
  leg1->SetLineStyle(1);
  leg1->SetLineWidth(2);
  leg1->SetFillColor(0);
  leg1->SetFillStyle(1001);
  leg1->Draw();

  new TCanvas();
  h_botsumo->SetLineWidth(4);
  h_botsumow->SetLineWidth(4);
  h_botsumo->SetLineColor(2);
  h_botsumow->SetLineColor(2);
  h_botsumow->SetLineStyle(2);
  h_botsumo->Scale(1./h_botsumo_c->Integral());
  h_botsumow->Scale(1./h_botsumo_cw->Integral());
  h_botsumow->SetTitle(";Direct PE number;Counts");
  h_botsumow->Draw("");
  h1_botw->Draw("same");
  //h1_bot->Draw("same");
  //h_botsumo->Draw("same");

  leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  //leg1->AddEntry(h1_bot ,"Data WbLS","l");
  leg1->AddEntry(h1_botw ,"Data Water","l");
  //leg1->AddEntry(h_botsumo_c ,"MC WbLS","l");
  leg1->AddEntry(h_botsumo_cw ,"MC Water","l");
  leg1->SetBorderSize(2);
  leg1->SetTextFont(62);
  leg1->SetFillColor(1);
  leg1->SetLineColor(1);
  leg1->SetShadowColor(0);
  leg1->SetLineStyle(1);
  leg1->SetLineWidth(2);
  leg1->SetFillColor(0);
  leg1->SetFillStyle(1001);
  leg1->Draw();
    
  new TCanvas();
  h1_row1->SetLineWidth(4);
  h1_row1w->SetLineWidth(4);
  h_row1sumo->SetLineWidth(4);
  h_row1sumow->SetLineWidth(4);
  h1_row1->SetLineColor(1);
  h1_row1w->SetLineColor(1);
  h_row1sumo->SetLineColor(2);
  h_row1sumow->SetLineColor(2);
  h1_row1w->SetLineStyle(2);
  h_row1sumow->SetLineStyle(2);
  h1_row1->Scale(1./h1_row1->Integral());
  h1_row1w->Scale(1./h1_row1w->Integral());
  h_row1sumo->Scale(1./h_row1sumo->Integral());
  h_row1sumow->Scale(1./h_row1sumow->Integral());
  h1_row1w->SetTitle(";Row 1 PE number;Counts");
  //h1_row1->Draw("");
  h1_row1w->Draw("");
  //h_row1sumo->Draw("same");
  h_row1sumow->Draw("same");
  leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg1->AddEntry(h1_botw ,"Data Water","l");
  leg1->AddEntry(h_botsumo_cw ,"MC Water","l");
  leg1->SetBorderSize(2);
  leg1->SetTextFont(62);
  leg1->SetFillColor(1);
  leg1->SetLineColor(1);
  leg1->SetShadowColor(0);
  leg1->SetLineStyle(1);
  leg1->SetLineWidth(2);
  leg1->SetFillColor(0);
  leg1->SetFillStyle(1001);
  leg1->Draw();

  new TCanvas();
  h1_row2->SetLineWidth(4);
  h1_row2w->SetLineWidth(4);
  h_row2sumo->SetLineWidth(4);
  h_row2sumow->SetLineWidth(4);
  h1_row2->SetLineColor(1);
  h1_row2w->SetLineColor(1);
  h_row2sumo->SetLineColor(2);
  h_row2sumow->SetLineColor(2);
  h1_row2w->SetLineStyle(2);
  h_row2sumow->SetLineStyle(2);
  h1_row2->Scale(1./h1_row2->Integral());
  h1_row2w->Scale(1./h1_row2w->Integral());
  h_row2sumo->Scale(1./h_row2sumo->Integral());
  h_row2sumow->Scale(1./h_row2sumow->Integral());
  h1_row2w->SetTitle(";Row 2 PE number;Counts");
  //h1_row2->Draw("");
  h1_row2w->Draw("");
  //h_row2sumo->Draw("same");
  h_row2sumow->Draw("same");
  leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg1->AddEntry(h1_botw ,"Data Water","l");
  leg1->AddEntry(h_botsumo_cw ,"MC Water","l");
  leg1->SetBorderSize(2);
  leg1->SetTextFont(62);
  leg1->SetFillColor(1);
  leg1->SetLineColor(1);
  leg1->SetShadowColor(0);
  leg1->SetLineStyle(1);
  leg1->SetLineWidth(2);
  leg1->SetFillColor(0);
  leg1->SetFillStyle(1001);
  leg1->Draw();

  new TCanvas();
  h1_row3->SetLineWidth(4);
  h1_row3w->SetLineWidth(4);
  h_row3sumo->SetLineWidth(4);
  h_row3sumow->SetLineWidth(4);
  h1_row3->SetLineColor(1);
  h1_row3w->SetLineColor(1);
  h_row3sumo->SetLineColor(2);
  h_row3sumow->SetLineColor(2);
  h1_row3w->SetLineStyle(2);
  h_row3sumow->SetLineStyle(2);
  h1_row3->Scale(1./h1_row3->Integral());
  h1_row3w->Scale(1./h1_row3w->Integral());
  h_row3sumo->Scale(1./h_row3sumo->Integral());
  h_row3sumow->Scale(1./h_row3sumow->Integral());
  h1_row3w->SetTitle(";Row 3 PE number;Counts");
  //h1_row3->Draw("");
  h1_row3w->Draw("");
  //h_row3sumo->Draw("same");
  h_row3sumow->Draw("same");
  leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg1->AddEntry(h1_botw ,"Data Water","l");
  leg1->AddEntry(h_botsumo_cw ,"MC Water","l");
  leg1->SetBorderSize(2);
  leg1->SetTextFont(62);
  leg1->SetFillColor(1);
  leg1->SetLineColor(1);
  leg1->SetShadowColor(0);
  leg1->SetLineStyle(1);
  leg1->SetLineWidth(2);
  leg1->SetFillColor(0);
  leg1->SetFillStyle(1001);
  leg1->Draw();

  new TCanvas();
  h1_row4->SetLineWidth(4);
  h1_row4w->SetLineWidth(4);
  h_row4sumo->SetLineWidth(4);
  h_row4sumow->SetLineWidth(4);
  h1_row4->SetLineColor(1);
  h1_row4w->SetLineColor(1);
  h_row4sumo->SetLineColor(2);
  h_row4sumow->SetLineColor(2);
  h1_row4w->SetLineStyle(2);
  h_row4sumow->SetLineStyle(2);
  h1_row4->Scale(1./h1_row4->Integral());
  h1_row4w->Scale(1./h1_row4w->Integral());
  h_row4sumo->Scale(1./h_row4sumo->Integral());
  h_row4sumow->Scale(1./h_row4sumow->Integral());
  h1_row4w->SetTitle(";Row 4 PE number;Counts");
  //h1_row4->Draw("");
  h1_row4w->Draw("");
  //h_row4sumo->Draw("same");
  h_row4sumow->Draw("same");

  leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg1->AddEntry(h1_botw ,"Data Water","l");
  leg1->AddEntry(h_botsumo_cw ,"MC Water","l");
  leg1->SetBorderSize(2);
  leg1->SetTextFont(62);
  leg1->SetFillColor(1);
  leg1->SetLineColor(1);
  leg1->SetShadowColor(0);
  leg1->SetLineStyle(1);
  leg1->SetLineWidth(2);
  leg1->SetFillColor(0);
  leg1->SetFillStyle(1001);
  leg1->Draw();

  cout<<"3.2"<<endl;
  TGraphErrors* g_scint = new TGraphErrors(46);
  for (int i=0;i<46;i++){
    cout<<"i "<<i<<" wbls and water means: "<<h1_ch[i]->GetMean()<<" "<<h1_chw[i]->GetMean()<<endl;
    g_scint ->SetPoint(i, 1+i, h1_ch[i]->GetMean()-h1_chw[i]->GetMean());
    g_scint ->SetPointError(i,0, TMath::Sqrt(TMath::Power(h1_ch[i]->GetRMS(),2) + TMath::Power(h1_chw[i]->GetRMS(),2)));
  }

  cout<<3<<endl;
  // pmt id: 14 16 2 28
  TGraphErrors* g1[46]; for (int i=0;i<46;i++) g1[i] = new TGraphErrors(46);
  TGraphErrors* g2[46]; for (int i=0;i<46;i++) g2[i] = new TGraphErrors(46); 
  TGraphErrors* gg3[46]; for (int i=0;i<46;i++) gg3[i] = new TGraphErrors(46); 
  for (int i=0;i<46;i++){
 
    //h_diff_abs->Fill((ratiox[i]->GetMean() - ratioxw[i]->GetMean())*0.432 - (h1_ch[i]->GetMean()-h1_chw[i]->GetMean()) );

    cout<<i<<endl;
    g1[0]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[0]->GetMean() - ratioxw[0]->GetMean()) );
    g1[0]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[0]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[0]->GetMean()- h1_chw[0]->GetMean()));

    g1[1]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[1]->GetMean() - ratioxw[1]->GetMean()) );
    g1[1]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[1]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[1]->GetMean()- h1_chw[1]->GetMean()));

    g1[2]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[2]->GetMean() - ratioxw[2]->GetMean()) );
    g1[2]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[2]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[2]->GetMean()- h1_chw[2]->GetMean()));

    g1[3]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[3]->GetMean() - ratioxw[3]->GetMean()) );
    g1[3]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[3]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[3]->GetMean()- h1_chw[3]->GetMean()));

    g1[4]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[4]->GetMean() - ratioxw[4]->GetMean()) );
    g1[4]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[4]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[4]->GetMean()- h1_chw[4]->GetMean()));
    
    g1[5]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[5]->GetMean() - ratioxw[5]->GetMean()) );
    g1[5]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[5]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[5]->GetMean()- h1_chw[5]->GetMean()));

    g1[6]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[6]->GetMean() - ratioxw[6]->GetMean()) );
    g1[6]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[6]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[6]->GetMean()- h1_chw[6]->GetMean()));

    g1[7]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[7]->GetMean() - ratioxw[7]->GetMean()) );
    g1[7]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[7]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[7]->GetMean()- h1_chw[7]->GetMean()));
    
    g1[8]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[8]->GetMean() - ratioxw[8]->GetMean()) );
    g1[8]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[8]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[8]->GetMean()- h1_chw[8]->GetMean()));

    g1[9]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[9]->GetMean() - ratioxw[9]->GetMean()) );
    g1[9]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[9]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[9]->GetMean()- h1_chw[9]->GetMean()));

    g1[10]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[10]->GetMean() - ratioxw[10]->GetMean()) );
    g1[10]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[10]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[10]->GetMean()- h1_chw[10]->GetMean()));
    
    g1[11]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[11]->GetMean() - ratioxw[11]->GetMean()) );
    g1[11]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[11]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[11]->GetMean()- h1_chw[11]->GetMean()));

    g1[12]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[12]->GetMean() - ratioxw[12]->GetMean()) );
    g1[12]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[12]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[12]->GetMean()- h1_chw[12]->GetMean()));

    g1[13]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[13]->GetMean() - ratioxw[13]->GetMean()) );
    g1[13]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[13]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[13]->GetMean()- h1_chw[13]->GetMean()));

    g1[14]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[14]->GetMean() - ratioxw[14]->GetMean()) );
    g1[14]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[14]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[14]->GetMean()- h1_chw[14]->GetMean()));
    
    g1[15]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[15]->GetMean() - ratioxw[15]->GetMean()) );
    g1[15]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[15]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[15]->GetMean()- h1_chw[15]->GetMean()));

    g1[16]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[16]->GetMean() - ratioxw[16]->GetMean()) );
    g1[16]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[16]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[16]->GetMean()- h1_chw[16]->GetMean()));

    g1[17]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[17]->GetMean() - ratioxw[17]->GetMean()) );
    g1[17]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[17]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[17]->GetMean()- h1_chw[17]->GetMean()));

    g1[18]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[18]->GetMean() - ratioxw[18]->GetMean()) );
    g1[18]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[18]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[18]->GetMean()- h1_chw[18]->GetMean()));

    g1[19]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[19]->GetMean() - ratioxw[19]->GetMean()) );
    g1[19]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[19]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[19]->GetMean()- h1_chw[19]->GetMean()));
    
    g1[20]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[20]->GetMean() - ratioxw[20]->GetMean()) );
    g1[20]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[20]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[20]->GetMean()- h1_chw[20]->GetMean()));

    g1[21]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[21]->GetMean() - ratioxw[21]->GetMean()) );
    g1[21]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[21]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[21]->GetMean()- h1_chw[21]->GetMean()));

    g1[22]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[22]->GetMean() - ratioxw[22]->GetMean()) );
    g1[22]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[22]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[22]->GetMean()- h1_chw[22]->GetMean()));

    g1[23]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[23]->GetMean() - ratioxw[23]->GetMean()) );
    g1[23]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[23]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[23]->GetMean()- h1_chw[23]->GetMean()));
    
    g1[24]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[24]->GetMean() - ratioxw[24]->GetMean()) );
    g1[24]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[24]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[24]->GetMean()- h1_chw[24]->GetMean()));

    g1[25]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[25]->GetMean() - ratioxw[25]->GetMean()) );
    g1[25]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[25]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[25]->GetMean()- h1_chw[25]->GetMean()));

    g1[26]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[26]->GetMean() - ratioxw[26]->GetMean()) );
    g1[26]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[26]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[26]->GetMean()- h1_chw[26]->GetMean()));
    
    g1[27]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[27]->GetMean() - ratioxw[27]->GetMean()) );
    g1[27]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[27]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[27]->GetMean()- h1_chw[27]->GetMean()));

    g1[28]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[28]->GetMean() - ratioxw[28]->GetMean()) );
    g1[28]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[28]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[28]->GetMean()- h1_chw[28]->GetMean()));

    g1[29]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[29]->GetMean() - ratioxw[29]->GetMean()) );
    g1[29]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[29]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[29]->GetMean()- h1_chw[29]->GetMean()));

    g1[30]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[30]->GetMean() - ratioxw[30]->GetMean()) );
    g1[30]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[30]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[30]->GetMean()- h1_chw[30]->GetMean()));

    g1[31]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[31]->GetMean() - ratioxw[31]->GetMean()) );
    g1[31]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[31]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[31]->GetMean()- h1_chw[31]->GetMean()));
 
    g1[32]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[32]->GetMean() - ratioxw[32]->GetMean()) );
    g1[32]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[32]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[32]->GetMean()- h1_chw[32]->GetMean()));

    g1[33]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[33]->GetMean() - ratioxw[33]->GetMean()) );
    g1[33]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[33]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[33]->GetMean()- h1_chw[33]->GetMean()));

    g1[34]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[34]->GetMean() - ratioxw[34]->GetMean()) );
    g1[34]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[34]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[34]->GetMean()- h1_chw[34]->GetMean()));

    g1[35]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[35]->GetMean() - ratioxw[35]->GetMean()) );
    g1[35]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[35]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[35]->GetMean()- h1_chw[35]->GetMean()));

    g1[36]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[36]->GetMean() - ratioxw[36]->GetMean()) );
    g1[36]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[36]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[36]->GetMean()- h1_chw[36]->GetMean()));

    g1[37]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[37]->GetMean() - ratioxw[37]->GetMean()) );
    g1[37]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[37]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[37]->GetMean()- h1_chw[37]->GetMean()));

    g1[38]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[38]->GetMean() - ratioxw[38]->GetMean()) );
    g1[38]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[38]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[38]->GetMean()- h1_chw[38]->GetMean()));

    g1[39]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[39]->GetMean() - ratioxw[39]->GetMean()) );
    g1[39]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[39]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[39]->GetMean()- h1_chw[39]->GetMean()));

    g1[40]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[40]->GetMean() - ratioxw[40]->GetMean()) );
    g1[40]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[40]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[40]->GetMean()- h1_chw[40]->GetMean()));

    g1[41]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[41]->GetMean() - ratioxw[41]->GetMean()) );
    g1[41]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[41]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[41]->GetMean()- h1_chw[41]->GetMean()));

    g1[42]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[42]->GetMean() - ratioxw[42]->GetMean()) );
    g1[42]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[42]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[42]->GetMean()- h1_chw[42]->GetMean()));

    g1[43]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[43]->GetMean() - ratioxw[43]->GetMean()) );
    g1[43]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[43]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[43]->GetMean()- h1_chw[43]->GetMean()));

    g1[44]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[44]->GetMean() - ratioxw[44]->GetMean()) );
    g1[44]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[44]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[44]->GetMean()- h1_chw[44]->GetMean()));

    g1[45]->SetPoint(i, 1+i, (ratiox[i]->GetMean() - ratioxw[i]->GetMean())/(ratiox[45]->GetMean() - ratioxw[45]->GetMean()) );
    g1[45]->SetPointError(i, 0, ratioxx[i]->GetRMS());
    g2[45]->SetPoint(i, 1+i, (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())/(h1_ch[45]->GetMean()- h1_chw[45]->GetMean()));

  }

  TGraph* g_rad = new TGraph(46);
  ifstream in;
  in.open("pmtlocation_4ton_index_0.txt");
  int aa, ee;
  double pmtx[46], pmty[46], pmtz[46];
  double cdist[46];
  double bb,cc,dd;
  while (!in.eof()){
    in>>aa>>bb>>cc>>dd>>ee;
    pmtx[aa] = bb;
    pmty[aa] = cc;
    pmtz[aa] = dd;
    cdist[aa] = sqrt(TMath::Power(abs(bb-106),2) + TMath::Power(abs(cc-106),2));
  }
  for (int i=0;i<30;i++){
    cout<<"i, cdist and diff "<<i<<" "<<cdist[i]<<" "<<(ratiox[i]->GetMean() - ratioxw[i]->GetMean())*0.5 - (h1_ch[i]->GetMean()-h1_chw[i]->GetMean())<<endl;
    g_rad->SetPoint(i, cdist[i], (ratiox[i]->GetMean() - ratioxw[i]->GetMean()) - (h1_ch[i]->GetMean()-h1_chw[i]->GetMean()));
  }
  cout<<4<<endl;
  TH1F* h_dis_ratio = new TH1F("","; Scint. light MC/Data ratio; Counts", 50,-4,4);
  TH1F* h_dis_diff = new TH1F("","; Scint. light MC/Data difference; Counts", 50,-4,4);

  TH1F* h_data = new TH1F("","; Scint. light ratio Data; Counts", 500,-400,400);
  TH1F* h_mc = new TH1F("","; Scint. light ratio MC; Counts", 500,-400,400);

  for (int i=0;i<30;i++){
    for (int j=0;j<30;j++){
      if (i != j) gg3[i]->SetPoint(j, j+1, g1[i]->Eval(j+1)/g2[i]->Eval(j+1) * (1./1.));
      else gg3[i]->SetPoint(j, j+1, g1[i]->Eval(j+1)/g2[i]->Eval(j+1) );
      if (i == 40 && j == 44) cout<<"sim and data (44 base) : "<<g1[i]->Eval(j+1)<<" "<<g2[i]->Eval(j+1) <<" "<<g1[i]->Eval(j+1)/g2[i]->Eval(j+1) <<endl;
      if (j == 40 && i == 44) cout<<"sim and data (40 base) : "<<g2[i]->Eval(j+1)<<" "<<g1[i]->Eval(j+1)<<" "<<g1[i]->Eval(j+1)/g2[i]->Eval(j+1) <<endl;
      gg3[i]->SetPointError(j, 0, g1[i]->GetErrorY(j)/g1[i]->Eval(j+1));
      if (g2[i]->Eval(j+1)<0) continue;
      h_dis_ratio->Fill(g1[i]->Eval(j+1)/g2[i]->Eval(j+1));
      h_dis_diff->Fill(g1[i]->Eval(j+1)-g2[i]->Eval(j+1));
      h_mc->Fill(g1[i]->Eval(j+1));
      h_data->Fill(g2[i]->Eval(j+1));
    }
  }
  new TCanvas();
  h_data->Draw("");
  new TCanvas();
  h_mc->Draw("");

  new TCanvas();
  g_rad->SetMarkerColor(2);
  g_rad->SetMarkerStyle(20);
  g_rad->SetMarkerSize(4);
  g_rad->SetTitle(";PMT distance to paddle on XY (mm); MC-Data difference");
  g_rad->Draw("PA");

  cout<<5<<endl;
  h_dis_ratio->SetLineColor(2);
  h_dis_ratio->SetLineWidth(4);
  h_dis_diff->SetLineColor(2);
  h_dis_diff->SetLineWidth(2);
  new TCanvas();
  h_dis_ratio->Draw();
  new TCanvas();
  h_dis_diff->Draw();

  g_scint->SetLineColor(2);
  g_scint->SetLineWidth(4);
  new TCanvas();
  g_scint->SetTitle(";PMT ID; Scint. light");
  g_scint->Draw("ALP");

  TF1* line1 = new TF1("","1",0,30);
  TCanvas* c_eff = new TCanvas();
  c_eff->Divide(5,6);
  for (int i=0;i<30;i++){
    gg3[i]->SetTitle(Form("MC-based efficiency referring to PMT-%d; PMT ID; Efficiency to PMT-%d",i+1,i+1));
    gg3[i]->SetMarkerSize(3);
    gg3[i]->SetMarkerColor(4);
    gg3[i]->SetMarkerStyle(20);
    gg3[i]->SetLineWidth(3);
  }
  line1->SetLineColor(1);
  line1->SetLineWidth(3);
  c_eff->cd(1);
  gg3[0]->Draw("PA");
  line1->Draw("same");
  for (int i=1;i<29;i++){
    c_eff->cd(i+1);
    gg3[i]->Draw("PA");
    line1->Draw("same");
  }

  TCanvas* c_eff2 = new TCanvas();
  c_eff2->Divide(2,2);
  for (int i=0;i<38;i++){
    gg3[i]->SetTitle(Form("MC-based efficiency referring to PMT-%d; PMT ID; Efficiency to PMT-%d",i+1,i+1));
    gg3[i]->SetMarkerSize(3);
    gg3[i]->SetMarkerColor(4);
    gg3[i]->SetMarkerStyle(20);
    gg3[i]->SetLineWidth(3);
  }
  line1->SetLineColor(1);
  line1->SetLineWidth(3);
  c_eff2->cd(1);
  gg3[7]->Draw("PA");
  line1->Draw("same");
  c_eff2->cd(2);
  gg3[8]->Draw("PA");
  line1->Draw("same");
  c_eff2->cd(3);
  gg3[13]->Draw("PA");
  line1->Draw("same");
  c_eff2->cd(4);
  gg3[23]->Draw("PA");
  line1->Draw("same");

  TCanvas* c_eff3 = new TCanvas();
  c_eff3->Divide(1,2);
  for (int i=0;i<46;i++){
    gg3[i]->SetTitle(Form("MC-based efficiency referring to PMT-%d; PMT ID; Efficiency to PMT-%d",i+1,i+1));
    gg3[i]->SetMarkerSize(3);
    gg3[i]->SetMarkerColor(4);
    gg3[i]->SetMarkerStyle(20);
    gg3[i]->SetLineWidth(3);
  }
  c_eff3->cd(1);
  gg3[28]->Draw("PA");
  line1->Draw("same");
  c_eff3->cd(2);
  gg3[40]->Draw("PA");
  line1->Draw("same");

/*
  cout<<"11th pmt ratio: "<<endl;
  for (int i=0;i<46;i++){
    cout<<gg3[10]->Eval(i+1)<<", ";
  }
  cout<<endl;
  cout<<4<<endl;
  TCanvas* c_full[10];
  TLegend* leg1;
  for (int ii=0;ii<11;ii++){
    c_full[ii] = new TCanvas();
    for (int i=0;i<4;i++){
      g1[ii*4+i]->SetMarkerSize(4);
      g2[ii*4+i]->SetMarkerSize(4);
      g1[ii*4+i]->SetMarkerColor(1);
      g2[ii*4+i]->SetMarkerColor(4);
      g1[ii*4+i]->SetMarkerStyle(20);
      g2[ii*4+i]->SetMarkerStyle(20);
      g1[ii*4+i]->SetLineWidth(4);
      g2[ii*4+i]->SetLineWidth(4);
    }
    c_full[ii]->Divide(2,2);
    c_full[ii]->cd(1);
    g1[ii*4+0]->Draw("PA");
    g2[ii*4+0]->Draw("same");
    g1[ii*4+0]->SetTitle(Form("Light ratio (to PMT-%d); PMT-x/PMT-%d; Light ratio",ii*4+1,ii*4+1));
    leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
    leg1->AddEntry(g1[ii*4+0] ,"Simulation","p");
    leg1->AddEntry(g2[ii*4+0] ,"Data","p");
    leg1->SetBorderSize(2);
    leg1->SetTextFont(62);
    leg1->SetFillColor(1);
    leg1->SetLineColor(1);
    leg1->SetShadowColor(0);
    leg1->SetLineStyle(1);
    leg1->SetLineWidth(2);
    leg1->SetFillColor(0);
    leg1->SetFillStyle(1001);
    leg1->Draw();
    c_full[ii]->cd(2);
    g1[ii*4+1]->Draw("PA");
    g2[ii*4+1]->Draw("same");
    g1[ii*4+1]->SetTitle(Form("Light ratio (to PMT-%d); PMT-x/PMT-%d; Light ratio",ii*4+2, ii*4+2));
    leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
    leg1->AddEntry(g1[ii*4+1] ,"Simulation","p");
    leg1->AddEntry(g2[ii*4+1] ,"Data","p");
    leg1->SetBorderSize(2);
    leg1->SetTextFont(62);
    leg1->SetFillColor(1);
    leg1->SetLineColor(1);
    leg1->SetShadowColor(0);
    leg1->SetLineStyle(1);
    leg1->SetLineWidth(2);
    leg1->SetFillColor(0);
    leg1->SetFillStyle(1001);
    leg1->Draw();
    c_full[ii]->cd(3);
    g1[ii*4+2]->Draw("PA");
    g2[ii*4+2]->Draw("same");
    g1[ii*4+2]->SetTitle(Form("Light ratio (to PMT-%d); PMT-x/PMT-%d; Light ratio",ii*4+3, ii*4+3));
    leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
    leg1->AddEntry(g1[ii*4+2] ,"Simulation","p");
    leg1->AddEntry(g2[ii*4+2] ,"Data","p");
    leg1->SetBorderSize(2);
    leg1->SetTextFont(62);
    leg1->SetFillColor(1);
    leg1->SetLineColor(1);
    leg1->SetShadowColor(0);
    leg1->SetLineStyle(1);
    leg1->SetLineWidth(2);
    leg1->SetFillColor(0);
    leg1->SetFillStyle(1001);
    leg1->Draw();
    c_full[ii]->cd(4);
    g1[ii*4+3]->Draw("PA");
    g2[ii*4+3]->Draw("same");
    g1[ii*4+3]->SetTitle(Form("Light ratio (to PMT-%d); PMT-x/PMT-%d; Light ratio",ii*4+4, ii*4+4));
    leg1 = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
    leg1->AddEntry(g1[ii*4+3] ,"Simulation","p");
    leg1->AddEntry(g2[ii*4+3] ,"Data","p");
    leg1->SetBorderSize(2);
    leg1->SetTextFont(62);
    leg1->SetFillColor(1);
    leg1->SetLineColor(1);
    leg1->SetShadowColor(0);
    leg1->SetLineStyle(1);
    leg1->SetLineWidth(2);
    leg1->SetFillColor(0);
    leg1->SetFillStyle(1001);
    leg1->Draw();
  }

  /////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
*/

}
