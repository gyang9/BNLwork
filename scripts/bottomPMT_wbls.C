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
  float indpmt[46];
  //cout<<"tfile"<<endl;
  //TFile f("bnl1t_water_x_0_y_0_1gev_newwater.root");
  //TFile f("bnl1t_newwater2_x_-14_y_0_1gev.root"); 
  TFile f("bnl1t_wbls_x_0_y_0_second.root");
  //cout<<"ttree"<<endl;
  TTree* ttree = (TTree*)f.Get("tree");
  ttree->Print();
  float botsumo;
  float row3sumo;
  float row4sumo;
  TH1F* h_botsumo = new TH1F("","",100,0,1000);
  TH1F* h_botsumo_c = new TH1F("","",100,0,1000);  
  TH1F* h_row3sumo = new TH1F("","",50,0,100);

  //cout<<"reading the tree"<<endl;
  ttree->SetBranchAddress("indpmt", &indpmt);
  ttree->SetBranchAddress("botsum", &botsumo);
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
  for (int i=0; i<1000; i++){
    ttree->GetEntry(i);
    //cout<<indpmt[11]<<endl;
    double tot1 = 0;
    for (int i=0;i<30;i++){ 
      tot1 += indpmt[i] / scaling_pmtid11[i];
      indpmt[i] *= scaling_pmtid11[i] ;
    }
    indpmt[11] /= 1.;
    //cout<<"compare two total on the bottom, sum and botsum "<<tot1<<" "<<botsumo<<endl;
    h_botsumo->Fill(botsumo);
    h_botsumo_c->Fill(tot1);
    h_row3sumo->Fill(row3sumo+row4sumo);
 
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

      ratiox[j] -> Fill(indpmt[j]/indpmt[0]);
      ratiox2[j] -> Fill(indpmt[j]/indpmt[1]);
      ratiox3[j] -> Fill(indpmt[j]/indpmt[2]);
      ratiox4[j] -> Fill(indpmt[j]/indpmt[3]);
      ratiox5[j] -> Fill(indpmt[j]/indpmt[4]);
      ratiox6[j] -> Fill(indpmt[j]/indpmt[5]);
      ratiox7[j] -> Fill(indpmt[j]/indpmt[6]);
      ratiox8[j] -> Fill(indpmt[j]/indpmt[7]);
      ratiox9[j] -> Fill(indpmt[j]/indpmt[8]);
      ratiox10[j] -> Fill(indpmt[j]/indpmt[9]);
      ratiox11[j] -> Fill(indpmt[j]/indpmt[10]);
      ratiox12[j] -> Fill(indpmt[j]/indpmt[11]);
      ratiox13[j] -> Fill(indpmt[j]/indpmt[12]);
      ratiox14[j] -> Fill(indpmt[j]/indpmt[13]);
      ratiox15[j] -> Fill(indpmt[j]/indpmt[14]);
      ratiox16[j] -> Fill(indpmt[j]/indpmt[15]);
      ratiox17[j] -> Fill(indpmt[j]/indpmt[16]);
      ratiox18[j] -> Fill(indpmt[j]/indpmt[17]);
      ratiox19[j] -> Fill(indpmt[j]/indpmt[18]);
      ratiox20[j] -> Fill(indpmt[j]/indpmt[19]);
      ratiox21[j] -> Fill(indpmt[j]/indpmt[20]);
      ratiox22[j] -> Fill(indpmt[j]/indpmt[21]);
      ratiox23[j] -> Fill(indpmt[j]/indpmt[22]);
      ratiox24[j] -> Fill(indpmt[j]/indpmt[23]);
      ratiox25[j] -> Fill(indpmt[j]/indpmt[24]);
      ratiox26[j] -> Fill(indpmt[j]/indpmt[25]);
      ratiox27[j] -> Fill(indpmt[j]/indpmt[26]);
      ratiox28[j] -> Fill(indpmt[j]/indpmt[27]);      
      ratiox29[j] -> Fill(indpmt[j]/indpmt[28]);
      ratiox30[j] -> Fill(indpmt[j]/indpmt[29]);     

      if (indpmt[j]/indpmt[30] > 0)
      ratiox31[j] -> Fill(indpmt[j]/indpmt[30]);
      if (indpmt[j]/indpmt[31] > 0)
      ratiox32[j] -> Fill(indpmt[j]/indpmt[31]);
      if (indpmt[j]/indpmt[32] > 0)
      ratiox33[j] -> Fill(indpmt[j]/indpmt[32]);
      if (indpmt[j]/indpmt[33] > 0)
      ratiox34[j] -> Fill(indpmt[j]/indpmt[33]);
      if (indpmt[j]/indpmt[34] > 0)
      ratiox35[j] -> Fill(indpmt[j]/indpmt[34]);
      if (indpmt[j]/indpmt[35] > 0)
      ratiox36[j] -> Fill(indpmt[j]/indpmt[35]);
      if (indpmt[j]/indpmt[36] > 0)
      ratiox37[j] -> Fill(indpmt[j]/indpmt[36]);
      if (indpmt[j]/indpmt[37] > 0)
      ratiox38[j] -> Fill(indpmt[j]/indpmt[37]);
      if (indpmt[j]/indpmt[38] > 0)
      ratiox39[j] -> Fill(indpmt[j]/indpmt[38]);
      if (indpmt[j]/indpmt[39] > 0)
      ratiox40[j] -> Fill(indpmt[j]/indpmt[39]);
      if (indpmt[j]/indpmt[40] > 0)
      ratiox41[j] -> Fill(indpmt[j]/indpmt[40]);
      if (indpmt[j]/indpmt[41] > 0)
      ratiox42[j] -> Fill(indpmt[j]/indpmt[41]);
      if (indpmt[j]/indpmt[42] > 0)
      ratiox43[j] -> Fill(indpmt[j]/indpmt[42]);
      if (indpmt[j]/indpmt[43] > 0)
      ratiox44[j] -> Fill(indpmt[j]/indpmt[43]);
      if (indpmt[j]/indpmt[44] > 0)
      ratiox45[j] -> Fill(indpmt[j]/indpmt[44]);
      if (indpmt[j]/indpmt[45] > 0)
      ratiox46[j] -> Fill(indpmt[j]/indpmt[45]);      
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


  cout<<2<<endl;
  TH1F* h1_ch[46]; 
  for (int i=0;i<46;i++)
    h1_ch[i] = new TH1F("","",50,-10,90);

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
  }
 
  cout<<3<<endl;
  // pmt id: 14 16 2 28
  TGraphErrors* g1[46]; for (int i=0;i<46;i++) g1[i] = new TGraphErrors(46);
  TGraphErrors* g2[46]; for (int i=0;i<46;i++) g2[i] = new TGraphErrors(46); 
  TGraphErrors* gg3[46]; for (int i=0;i<46;i++) gg3[i] = new TGraphErrors(46); 
  for (int i=0;i<46;i++){
    g1[0]->SetPoint(i, 1+i, ratiox[i]->GetMean());
    g1[0]->SetPointError(i, 0, ratiox[i]->GetRMS());
    g2[0]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[0]->GetMean());

    g1[1]->SetPoint(i, 1+i, ratiox2[i]->GetMean());
    g1[1]->SetPointError(i, 0, ratiox2[i]->GetRMS());
    g2[1]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[1]->GetMean());

    g1[2]->SetPoint(i, 1+i, ratiox3[i]->GetMean());
    g1[2]->SetPointError(i, 0, ratiox3[i]->GetRMS());
    g2[2]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[2]->GetMean());

    g1[3]->SetPoint(i, 1+i, ratiox4[i]->GetMean());
    g1[3]->SetPointError(i, 0, ratiox4[i]->GetRMS());
    g2[3]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[3]->GetMean());

    g1[4]->SetPoint(i, 1+i, ratiox5[i]->GetMean());
    g1[4]->SetPointError(i, 0, ratiox5[i]->GetRMS());
    g2[4]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[4]->GetMean());

    g1[5]->SetPoint(i, 1+i, ratiox6[i]->GetMean());
    g1[5]->SetPointError(i, 0, ratiox6[i]->GetRMS());
    g2[5]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[5]->GetMean());

    g1[6]->SetPoint(i, 1+i, ratiox7[i]->GetMean());
    g1[6]->SetPointError(i, 0, ratiox7[i]->GetRMS());
    g2[6]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[6]->GetMean());

    g1[7]->SetPoint(i, 1+i, ratiox8[i]->GetMean());
    g1[7]->SetPointError(i, 0, ratiox8[i]->GetRMS());
    g2[7]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[7]->GetMean());

    g1[8]->SetPoint(i, 1+i, ratiox9[i]->GetMean());
    g1[8]->SetPointError(i, 0, ratiox9[i]->GetRMS());
    g2[8]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[8]->GetMean());

    g1[9]->SetPoint(i, 1+i, ratiox10[i]->GetMean());
    g1[9]->SetPointError(i, 0, ratiox10[i]->GetRMS());
    g2[9]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[9]->GetMean());

    g1[10]->SetPoint(i, 1+i, ratiox11[i]->GetMean());
    g1[10]->SetPointError(i, 0, ratiox11[i]->GetRMS());
    g2[10]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[10]->GetMean());

    g1[11]->SetPoint(i, 1+i, ratiox12[i]->GetMean());
    g1[11]->SetPointError(i, 0, ratiox12[i]->GetRMS());
    g2[11]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[11]->GetMean());

    g1[12]->SetPoint(i, 1+i, ratiox13[i]->GetMean());
    g1[12]->SetPointError(i, 0, ratiox13[i]->GetRMS());
    g2[12]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[12]->GetMean());

    g1[13]->SetPoint(i, 1+i, ratiox14[i]->GetMean());
    g1[13]->SetPointError(i, 0, ratiox14[i]->GetRMS());
    g2[13]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[13]->GetMean());

    g1[14]->SetPoint(i, 1+i, ratiox15[i]->GetMean());
    g1[14]->SetPointError(i, 0, ratiox15[i]->GetRMS());
    g2[14]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[14]->GetMean());

    g1[15]->SetPoint(i, 1+i, ratiox16[i]->GetMean());
    g1[15]->SetPointError(i, 0, ratiox16[i]->GetRMS());
    g2[15]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[15]->GetMean());

    g1[16]->SetPoint(i, 1+i, ratiox17[i]->GetMean());
    g1[16]->SetPointError(i, 0, ratiox17[i]->GetRMS());
    g2[16]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[16]->GetMean());

    g1[17]->SetPoint(i, 1+i, ratiox18[i]->GetMean());
    g1[17]->SetPointError(i, 0, ratiox18[i]->GetRMS());
    g2[17]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[17]->GetMean());

    g1[18]->SetPoint(i, 1+i, ratiox19[i]->GetMean());
    g1[18]->SetPointError(i, 0, ratiox19[i]->GetRMS());
    g2[18]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[18]->GetMean());

    g1[19]->SetPoint(i, 1+i, ratiox20[i]->GetMean());
    g1[19]->SetPointError(i, 0, ratiox20[i]->GetRMS());
    g2[19]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[19]->GetMean());

    g1[20]->SetPoint(i, 1+i, ratiox21[i]->GetMean());
    g1[20]->SetPointError(i, 0, ratiox21[i]->GetRMS());
    g2[20]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[20]->GetMean());

    g1[21]->SetPoint(i, 1+i, ratiox22[i]->GetMean());
    g1[21]->SetPointError(i, 0, ratiox22[i]->GetRMS());
    g2[21]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[21]->GetMean());

    g1[22]->SetPoint(i, 1+i, ratiox23[i]->GetMean());
    g1[22]->SetPointError(i, 0, ratiox23[i]->GetRMS());
    g2[22]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[22]->GetMean());

    g1[23]->SetPoint(i, 1+i, ratiox24[i]->GetMean());
    g1[23]->SetPointError(i, 0, ratiox24[i]->GetRMS());
    g2[23]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[23]->GetMean());
    
    g1[24]->SetPoint(i, 1+i, ratiox25[i]->GetMean());
    g1[24]->SetPointError(i, 0, ratiox25[i]->GetRMS());
    g2[24]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[24]->GetMean());

    g1[25]->SetPoint(i, 1+i, ratiox26[i]->GetMean());
    g1[25]->SetPointError(i, 0, ratiox26[i]->GetRMS());
    g2[25]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[25]->GetMean());

    g1[26]->SetPoint(i, 1+i, ratiox27[i]->GetMean());
    g1[26]->SetPointError(i, 0, ratiox27[i]->GetRMS());
    g2[26]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[26]->GetMean());

    g1[27]->SetPoint(i, 1+i, ratiox28[i]->GetMean());
    g1[27]->SetPointError(i, 0, ratiox28[i]->GetRMS());
    g2[27]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[27]->GetMean());

    g1[28]->SetPoint(i, 1+i, ratiox29[i]->GetMean());
    g1[28]->SetPointError(i, 0, ratiox29[i]->GetRMS());
    g2[28]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[28]->GetMean());

    g1[29]->SetPoint(i, 1+i, ratiox30[i]->GetMean());
    g1[29]->SetPointError(i, 0, ratiox30[i]->GetRMS());
    g2[29]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[29]->GetMean());  

    g1[30]->SetPoint(i, 1+i, ratiox31[i]->GetMean());
    g1[30]->SetPointError(i, 0, ratiox31[i]->GetRMS());
    g2[30]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[30]->GetMean());

    g1[31]->SetPoint(i, 1+i, ratiox32[i]->GetMean());
    g1[31]->SetPointError(i, 0, ratiox32[i]->GetRMS());
    g2[31]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[31]->GetMean());

    g1[32]->SetPoint(i, 1+i, ratiox33[i]->GetMean());
    g1[32]->SetPointError(i, 0, ratiox33[i]->GetRMS());
    g2[32]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[32]->GetMean());

    g1[33]->SetPoint(i, 1+i, ratiox34[i]->GetMean());
    g1[33]->SetPointError(i, 0, ratiox34[i]->GetRMS());
    g2[33]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[33]->GetMean());

    g1[34]->SetPoint(i, 1+i, ratiox35[i]->GetMean());
    g1[34]->SetPointError(i, 0, ratiox35[i]->GetRMS());
    g2[34]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[34]->GetMean());

    g1[35]->SetPoint(i, 1+i, ratiox36[i]->GetMean());
    g1[35]->SetPointError(i, 0, ratiox36[i]->GetRMS());
    g2[35]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[35]->GetMean());

    g1[36]->SetPoint(i, 1+i, ratiox37[i]->GetMean());
    g1[36]->SetPointError(i, 0, ratiox37[i]->GetRMS());
    g2[36]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[36]->GetMean());

    g1[37]->SetPoint(i, 1+i, ratiox38[i]->GetMean());
    g1[37]->SetPointError(i, 0, ratiox38[i]->GetRMS());
    g2[37]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[37]->GetMean());

    g1[38]->SetPoint(i, 1+i, ratiox39[i]->GetMean());
    g1[38]->SetPointError(i, 0, ratiox39[i]->GetRMS());
    g2[38]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[38]->GetMean());

    g1[39]->SetPoint(i, 1+i, ratiox40[i]->GetMean());
    g1[39]->SetPointError(i, 0, ratiox40[i]->GetRMS());
    g2[39]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[39]->GetMean());    

    g1[40]->SetPoint(i, 1+i, ratiox41[i]->GetMean());
    g1[40]->SetPointError(i, 0, ratiox41[i]->GetRMS());
    g2[40]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[40]->GetMean());

    g1[41]->SetPoint(i, 1+i, ratiox42[i]->GetMean());
    g1[41]->SetPointError(i, 0, ratiox42[i]->GetRMS());
    g2[41]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[41]->GetMean());

    g1[42]->SetPoint(i, 1+i, ratiox43[i]->GetMean());
    g1[42]->SetPointError(i, 0, ratiox43[i]->GetRMS());
    g2[42]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[42]->GetMean());

    g1[43]->SetPoint(i, 1+i, ratiox44[i]->GetMean());
    g1[43]->SetPointError(i, 0, ratiox44[i]->GetRMS());
    g2[43]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[43]->GetMean());
    
    g1[44]->SetPoint(i, 1+i, ratiox45[i]->GetMean());
    g1[44]->SetPointError(i, 0, ratiox45[i]->GetRMS());
    g2[44]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[44]->GetMean());
    
    g1[45]->SetPoint(i, 1+i, ratiox46[i]->GetMean());
    g1[45]->SetPointError(i, 0, ratiox46[i]->GetRMS());
    g2[45]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[45]->GetMean());
  }

  for (int i=0;i<30;i++){
    for (int j=0;j<30;j++){
      if (i != j) gg3[i]->SetPoint(j, j+1, g1[i]->Eval(j+1)/g2[i]->Eval(j+1) * (1./1.));
      else gg3[i]->SetPoint(j, j+1, g1[i]->Eval(j+1)/g2[i]->Eval(j+1) );
      if (i == 40 && j == 44) cout<<"sim and data (44 base) : "<<g1[i]->Eval(j+1)<<" "<<g2[i]->Eval(j+1) <<" "<<g1[i]->Eval(j+1)/g2[i]->Eval(j+1) <<endl;
      if (j == 40 && i == 44) cout<<"sim and data (40 base) : "<<g2[i]->Eval(j+1)<<" "<<g1[i]->Eval(j+1)<<" "<<g1[i]->Eval(j+1)/g2[i]->Eval(j+1) <<endl;
      gg3[i]->SetPointError(j, 0, g1[i]->GetErrorY(j)/g1[i]->Eval(j+1));
    }
  }
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

  TFile f2("bnl1t_water_x_0_y_0_1gev_tracking.root");
  TH2F* th_c[46];
  TH2F* th_r[46];
  TH2F* th_r2[46];
  TH2F* th_s[46];

  double fraction_loc[46]={};
  for (int i=0;i<46;i++){
    th_c[i] = (TH2F*)f2.Get(Form("th_c_%d",i));
    th_r[i] = (TH2F*)f2.Get(Form("th_r_%d",i));
    th_s[i] = (TH2F*)f2.Get(Form("th_s_%d",i));
    th_r2[i] = (TH2F*)f2.Get(Form("th_r2_%d",i));    
    fraction_loc[i] = (th_r[i]->Integral()+th_r2[i]->Integral())/(th_c[i]->Integral()+th_r[i]->Integral()+th_s[i]->Integral()+th_r2[i]->Integral());
  }
  TGraph* g3 = new TGraph(8);
  for (int i=0;i<8;i++){
    g3->SetPoint(i,12+i,fraction_loc[i+11]);
  }
  new TCanvas();
  g3->SetTitle("Reflection; PMT id; Reflection fraction");
  g3->SetMarkerSize(4);
  g3->SetMarkerColor(1);
  g3->SetMarkerStyle(20);
  g3->Draw();


  TH1F* h_fc[5];
  for (int i=0;i<5;i++) h_fc[i] = new TH1F("","",100,0,1000);

  TFile* fc1[5];
  TTree* tt[5];
  float botsum;
  for (int i=0;i<5;i++){
    fc1[i] = new TFile(Form("bnl1t_water_x_0_y_0_1gev_cookie_z_%d.root",i));
    tt[i] = (TTree*)fc1[i]->Get("tree");
    tt[i] ->SetBranchAddress("botsum",&botsum);
    cout<<tt[i]->GetEntries()<<endl;
    for (int iev = 0;iev< tt[i]->GetEntries(); iev++){
      tt[i]->GetEntry(iev);
      h_fc[i]->Fill(botsum);
      //cout<<botsum<<endl;
    }
  }
  new TCanvas();
  h_fc[0]->SetTitle("Bottom cookie comparison; PE; Counts");
  h_fc[0]->SetLineColor(7);
  h_fc[0]->SetLineWidth(4);
  h_fc[0]->Scale(1/h_fc[0]->Integral());
  h_fc[0]->Draw();
  for (int i=1;i<5;i++){
    h_fc[i]->SetLineColor(i);
    h_fc[i]->SetLineWidth(4);
    h_fc[i]->Scale(1./h_fc[i]->Integral());
    h_fc[i]->Draw("same");
  }
  h_botsumo->SetLineColor(1);
  h_botsumo->SetLineWidth(4);
  h_botsumo->SetLineStyle(2);
  h_botsumo->Scale(1./h_botsumo->Integral());
  h_botsumo->Draw("same");

  TLegend* leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h_botsumo ,"Original cookie (3.175 mm thickness)","l");
  for (int i=0;i<5;i++)
    leg->AddEntry(h_fc[i] ,Form("Cookie thickness %d.0001 mm",i),"l");
  leg->SetBorderSize(2);
  leg->SetTextFont(62);
  leg->SetFillColor(1);
  leg->SetLineColor(1);
  leg->SetShadowColor(0);
  leg->SetLineStyle(1);
  leg->SetLineWidth(2);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->Draw();


  //bottom data
  double list_data[100] = {1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   2.,   1.,   1.,   2.,   5.,   5.,
        13.,  22.,  39.,  62., 101., 139., 150., 170., 180., 157., 168.,
       140., 107.,  76.,  58.,  45.,  32.,  33.,  23.,  17.,   7.,  11.,
         5.,  10.,   7.,   4.,   3.,   3.,   2.,   5.,   1.,   0.,   3.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
         0.};
  auto h_data1 = new TH1F("","",100,0,1000);
  for (int i=0;i<h_data1->GetNbinsX();i++) h_data1->SetBinContent(i+1,list_data[i]);
  h_data1->Scale(1./h_data1->Integral());
  new TCanvas();
  h_botsumo->SetTitle("PMT efficiency correction test; PE; Counts");
  h_botsumo->Draw();
  h_botsumo_c->SetLineColor(4);
  h_botsumo_c->SetLineWidth(6);
  h_botsumo_c->SetLineStyle(1);
  h_botsumo_c->Scale(1./h_botsumo_c->Integral());
  h_botsumo_c->Draw("same");
  h_data1->SetLineColor(2);
  h_data1->SetLineWidth(6);
  h_data1->Draw("same");
  leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h_botsumo ,"Default","l");
  leg->AddEntry(h_botsumo_c ,"PMT efficiency scaled","l");
  leg->AddEntry(h_data1, "Data", "l");
  leg->SetBorderSize(2);
  leg->SetTextFont(62);
  leg->SetFillColor(1);
  leg->SetLineColor(1);
  leg->SetShadowColor(0);
  leg->SetLineStyle(1);
  leg->SetLineWidth(2);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->Draw();


  TH1F* h_fc2[5];
  for (int i=0;i<5;i++) h_fc2[i] = new TH1F("","",50,0,100);

  TFile* fc2[5];
  TTree* tt2[5];
  float row3sum; float row4sum;
  for (int i=0;i<5;i++){
    fc2[i] = new TFile(Form("bnl1t_water_x_0_y_0_1gev_side_cookie_z_%d.root",i));
    tt2[i] = (TTree*)fc2[i]->Get("tree");
    tt2[i] ->SetBranchAddress("row3sum",&row3sum);
    tt2[i] ->SetBranchAddress("row4sum",&row4sum);
    cout<<tt2[i]->GetEntries()<<endl;
    for (int iev = 0;iev< tt2[i]->GetEntries(); iev++){
      tt2[i]->GetEntry(iev);
      h_fc2[i]->Fill(row3sum+row4sum);
      //cout<<botsum<<endl;
    }
  }
  new TCanvas();
  h_fc2[0]->SetTitle("Side cookie comparison; PE; Counts");
  h_fc2[0]->SetLineColor(7);
  h_fc2[0]->SetLineWidth(4);
  h_fc2[0]->Scale(1/h_fc2[0]->Integral());
  h_fc2[0]->Draw();
  for (int i=1;i<5;i++){
    h_fc2[i]->SetLineColor(i);
    h_fc2[i]->SetLineWidth(4);
    h_fc2[i]->Scale(1./h_fc2[i]->Integral());
    h_fc2[i]->Draw("same");
  }
  h_row3sumo->SetLineColor(1);
  h_row3sumo->SetLineWidth(4);
  h_row3sumo->SetLineStyle(3);
  h_row3sumo->Scale(1./h_row3sumo->Integral());
  h_row3sumo->Draw("same");

  leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h_row3sumo ,"Original cookie (3.175 mm thickness)","l");
  for (int i=0;i<5;i++)
    leg->AddEntry(h_fc2[i] ,Form("Cookie thickness %d.0001 mm",i),"l");
  leg->SetBorderSize(2);
  leg->SetTextFont(62);
  leg->SetFillColor(1);
  leg->SetLineColor(1);
  leg->SetShadowColor(0);
  leg->SetLineStyle(1);
  leg->SetLineWidth(2);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->Draw();


}
