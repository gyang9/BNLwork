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

/*
  double ttsx[1000] = {-15.00000,-14.90596,-14.81191,-14.71787,-14.62382,-14.52978,-14.43574,-14.34169,-14.24765,-14.15361,-14.05956,-13.96552,-13.87147,-13.77743,-13.68339,-13.58934,-13.49530,-13.40125,-13.30721,-13.21317,-13.11912,-13.02508,-12.93103,-12.83699,-12.74295,-12.64890,-12.55486,-12.46082,-12.36677,-12.27273,-12.17868,-12.08464,-11.99060,-11.89655,-11.80251,-11.70846,-11.61442,-11.52038,-11.42633,-11.33229,-11.23824,-11.14420,-11.05016,-10.95611,-10.86207,-10.76803,-10.67398,-10.57994,-10.48589,-10.39185,-10.29781,-10.20376,-10.10972,-10.01567,-9.92163,-9.82759,-9.73354,-9.63950,-9.54545,-9.45141,-9.35737,-9.26332,-9.16928,-9.07524,-8.98119,-8.88715,-8.79310,-8.69906,-8.60502,-8.51097,-8.41693,-8.32288,-8.22884,-8.13480,-8.04075,-7.94671,-7.85266,-7.75862,-7.66458,-7.57053,-7.47649,-7.38245,-7.28840,-7.19436,-7.10031,-7.00627,-6.91223,-6.81818,-6.72414,-6.63009,-6.53605,-6.44201,-6.34796,-6.25392,-6.15987,-6.06583,-5.97179,-5.87774,-5.78370,-5.68966,-5.59561,-5.50157,-5.40752,-5.31348,-5.21944,-5.12539,-5.03135,-4.93730,-4.84326,-4.74922,-4.65517,-4.56113,-4.46708,-4.37304,-4.27900,-4.18495,-4.09091,-3.99687,-3.90282,-3.80878,-3.71473,-3.62069,-3.52665,-3.43260,-3.33856,-3.24451,-3.15047,-3.05643,-2.96238,-2.86834,-2.77429,-2.68025,-2.58621,-2.49216,-2.39812,-2.30408,-2.21003,-2.11599,-2.02194,-1.92790,-1.83386,-1.73981,-1.64577,-1.55172,-1.45768,-1.36364,-1.26959,-1.17555,-1.08150,-0.98746,-0.89342,-0.79937,-0.70533,-0.61129,-0.51724,-0.42320,-0.32915,-0.23511,-0.14107,-0.04702,0.04702,0.14107,0.23511,0.32915,0.42320,0.51724,0.61129,0.70533,0.79937,0.89342,0.98746,1.08150,1.17555,1.26959,1.36364,1.45768,1.55172,1.64577,1.73981,1.83386,1.92790,2.02194,2.11599,2.21003,2.30408,2.39812,2.49216,2.58621,2.68025,2.77429,2.86834,2.96238,3.05643,3.15047,3.24451,3.33856,3.43260,3.52665,3.62069,3.71473,3.80878,3.90282,3.99687,4.09091,4.18495,4.27900,4.37304,4.46708,4.56113,4.65517,4.74922,4.84326,4.93730,5.03135,5.12539,5.21944,5.31348,5.40752,5.50157,5.59561,5.68966,5.78370,5.87774,5.97179,6.06583,6.15987,6.25392,6.34796,6.44201,6.53605,6.63009,6.72414,6.81818,6.91223,7.00627,7.10031,7.19436,7.28840,7.38245,7.47649,7.57053,7.66458,7.75862,7.85266,7.94671,8.04075,8.13480,8.22884,8.32288,8.41693,8.51097,8.60502,8.69906,8.79310,8.88715,8.98119,9.07524,9.16928,9.26332,9.35737,9.45141,9.54545,9.63950,9.73354,9.82759,9.92163,10.01567,10.10972,10.20376,10.29781,10.39185,10.48589,10.57994,10.67398,10.76803,10.86207,10.95611,11.05016,11.14420,11.23824,11.33229,11.42633,11.52038,11.61442,11.70846,11.80251,11.89655,11.99060,12.08464,12.17868,12.27273,12.36677,12.46082,12.55486,12.64890,12.74295,12.83699,12.93103,13.02508,13.11912,13.21317,13.30721,13.40125,13.49530,13.58934,13.68339,13.77743,13.87147,13.96552,14.05956,14.15361,14.24765,14.34169,14.43574,14.52978,14.62382,14.71787,14.81191,14.90596,15.00000};
  //this will be integrated and normalized
  double time_prob[1000] ={ 0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00001,0.00001,0.00001,0.00001,0.00002,0.00003,0.00004,0.00005,0.00007,0.00010,0.00013,0.00017,0.00023,0.00030,0.00039,0.00052,0.00067,0.00087,0.00111,0.00142,0.00181,0.00228,0.00287,0.00359,0.00446,0.00552,0.00679,0.00830,0.01010,0.01223,0.01472,0.01762,0.02097,0.02483,0.02924,0.03425,0.03989,0.04622,0.05325,0.06102,0.06955,0.07883,0.08887,0.09965,0.11112,0.12324,0.13595,0.14914,0.16273,0.17659,0.19059,0.20458,0.21840,0.23189,0.24488,0.25719,0.26865,0.27910,0.28837,0.29634,0.30287,0.30786,0.31123,0.31293,0.31293,0.31123,0.30786,0.30287,0.29634,0.28837,0.27910,0.26865,0.25719,0.24488,0.23189,0.21840,0.20458,0.19059,0.17659,0.16273,0.14914,0.13595,0.12324,0.11112,0.09965,0.08887,0.07883,0.06955,0.06102,0.05325,0.04622,0.03989,0.03425,0.02924,0.02483,0.02097,0.01762,0.01472,0.01223,0.01010,0.00830,0.00679,0.00552,0.00446,0.00359,0.00287,0.00228,0.00181,0.00142,0.00111,0.00087,0.00067,0.00052,0.00039,0.00030,0.00023,0.00017,0.00013,0.00010,0.00007,0.00005,0.00004,0.00003,0.00002,0.00001,0.00001,0.00001,0.00001,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000,0.00000};

  TGraph* g1 = new TGraph(1000);
  for (int i=0;i<1000;i++){
    g1->SetPoint(i,ttsx[i],time_prob[i]);
  }
  //new TCanvas();
  //g1->Draw();

  // default rise time in ratpac-two: 0.270
  // decay time: [-2.22, -17.7 ] with fractions [0.956, 0.044], testing -2.22 only,

  TF1* f1[30];
  for (int i=0;i<20;i++){ 
    f1[i] = new TF1("f1","[3]*(exp(-(x-[0])/[1]) - exp(-(x-[0])/[2]))/([1]-[2])",-0.1,40);
    f1[i]->FixParameter(0, 0);
    f1[i]->FixParameter(1, 2.22);
    f1[i]->FixParameter(2, 0.01 + i*0.05);
    f1[i]->FixParameter(3, 35);
  }  

  //new TCanvas();
  //f1[0]->Draw();
  //for (int i=1;i<20;i++)
    //f1[i]->Draw("same");


  TF1* f2[30];
  for (int i=0;i<20;i++){
    f2[i] = new TF1("f2","[3]*(exp(-(x-[0])/[1]) - exp(-(x-[0])/[2]))/([1]-[2])",-0.1,40);
    f2[i]->FixParameter(0, 0);
    f2[i]->FixParameter(1, 0.1+0.5*i);
    f2[i]->FixParameter(2, 0.27);
    f2[i]->FixParameter(3, 35);
  }


  TF1* flog[30];
  for (int i=0;i<20;i++){
    flog[i] = new TF1("flog","TMath::LogNormal(x, [0])",-10,40);
    flog[i]->FixParameter(0, 50 + i*5);
  }

  //new TCanvas();
  //f2[0]->Draw();
  //for (int i=1;i<20;i++)
    //f2[i]->Draw("same");

  TCanvas* c0 = new TCanvas();
  flog[0]->Draw();
  for (int i=1;i<20;i++)
    flog[i]->Draw("same");
*/
  //exit(0);
  //
  int nevents = 1000;

  TH1F* h_test1[10];
  TH1F* h_test2[10];
  TH1F* h_test3[10];
  TH1F* h_test4[10];
  TH1F* h_test5[10];
  TH1F* h_test6[10];
  TH1F* h_test7[10];
  for (int i=0;i<10;i++){
    h_test1[i] = new TH1F("","decay time variation (no tts); T0; Density",50,50,100);
    h_test2[i] = new TH1F("","rise time variation (no tts); T0; Density",50,50,100);
    h_test3[i] = new TH1F("","decay time variation (tts); T0; Density",50,50,100);
    h_test4[i] = new TH1F("","rise time variation (tts); T0 ; Density",50,50,100);
    h_test5[i] = new TH1F("","pulse width variation (tts); T0 ; Density",50,50,100);
    h_test6[i] = new TH1F("","rise time variation (tts); T0 ; Density",1000,61,64);
    h_test7[i] = new TH1F("","pulse width variation (tts); T0 ; Density",100,61,64);
  }
  TF1* ff = new TF1("ff","[3]*(exp(-((x-[0]>0)? x-[0]: 0)/[1]) - exp(-((x-[0]>0)? x-[0]: 0)/[2]))/([1]-[2]) ",50,80);
  ff->SetParameter(0, 60);
  ff->SetParameter(1, 2.22);
  ff->SetParameter(2, 0.27);
  ff->SetParameter(3, 5);

  TF1* ff2 = new TF1("ff2","[3]*(exp(-((x-[0]>0)? x-[0]: 0)/[1]) - exp(-((x-[0]>0)? x-[0]: 0)/[2]))/([1]-[2]) ",50,80);
  ff2->SetParameter(0, 60);
  ff2->SetParameter(1, 2.22);
  ff2->SetParameter(2, 0.27);
  ff2->SetParameter(3, 10);

  TF1* ff3 = new TF1("ff3","[3]*(exp(-((x-[0]>0)? x-[0]: 0)/[1]) - exp(-((x-[0]>0)? x-[0]: 0)/[2]))/([1]-[2]) ",50,80);
  ff3->SetParameter(0, 60);
  ff3->SetParameter(1, 2.22);
  ff3->SetParameter(2, 0.27);
  ff3->SetParameter(3, 10);

  double r_decay[10]={};
  double r_rise[10]={};
  double r_decay_tts[10]={};
  double r_rise_tts[10]={};
  double r_width_tts[10]={};
  TH1F* h1; TH1F* h12;
  TH1F* hh; TH1F* hh2;
  //TFile infile("bnl1t_waveform_temp.root");
  //cout<<"DECAY-VARIED NOTTS WBLS1PCT:"<<endl;

  for (int i=0;i<10;i++){
    TFile infile(Form("bnl1t_waveform_bnl_p_120mev_y57_z-640_upward_notts_wbls1pct_riseD_decay%d.root",i));
    //if (!infile) continue;
    double r_tot =0;
    double r_n = 0;
    for (int j=0;j<nevents;j++){ 
      if (! infile.Get(Form("waveform2_%d",j)) ) continue;
      h1 = (TH1F*)infile.Get(Form("waveform2_%d",j));
      hh = (TH1F*)infile.Get(Form("waveform1_%d",j));
      for (int ii=0;ii<hh->GetNbinsX();ii++){
        hh->SetBinContent(ii+1, -1 * (h1->GetBinContent(ii+1)-1800)/60.);
	if (hh->GetBinContent(ii+1) <= 0 ){ hh->SetBinError(ii+1, 1e6);}
	//else hh->SetBinError(ii+1, hh->GetBinContent(ii+1)*0.2);
      }
      //ff->SetParameter(1, 2.22);
      //ff->SetParameter(2, 0.27);
      hh->Fit("ff","EQ");
      r_tot += ff->GetParameter(0);
      r_n ++;
      h_test1[i] ->Fill(ff->GetParameter(0));
    }
    r_decay[i] = r_tot/r_n;
    cout<<"   mean t0 for decay time "<<i<<" "<<r_tot/r_n<<endl;
  }
  //exit(0);
  //cout<<"RISE-VARIED NOTTS WBLS1PCT:"<<endl;
  for (int i=0;i<10;i++){
    TFile infile3(Form("bnl1t_waveform_bnl_p_120mev_y57_z-640_upward_notts_wbls1pct_rise%d_decayD.root",i));
    //if (!infile3) continue;
    double r_tot =0;
    double r_n = 0;
    for (int j=0;j<nevents;j++){
      if (! infile3.Get(Form("waveform2_%d",j)) ) continue;
      h1 = (TH1F*)infile3.Get(Form("waveform2_%d",j));
      hh = (TH1F*)infile3.Get(Form("waveform1_%d",j));
      for (int ii=0;ii<hh->GetNbinsX();ii++){
        hh->SetBinContent(ii+1, -1 * (h1->GetBinContent(ii+1)-1800)/60.);
      }
      //ff->SetParameter(1, 2.22);
      //ff->SetParameter(2, 0.27);      
      hh->Fit("ff","EQ");
      r_tot += ff->GetParameter(0);
      r_n ++;
      h_test2[i] ->Fill(ff->GetParameter(0));
    }
    r_rise[i] = r_tot/r_n;
    //cout<<"   mean t0 for rise time "<<i<<" "<<r_tot/r_n<<endl;
  }

  for (int i=0;i<10;i++){
    TFile infile2(Form("bnl1t_waveform_bnl_p_120mev_y57_z-640_upward_wtts_wbls1pct_riseD_decay%d.root",i));
    //if (!infile) continue;
    double r_tot =0;
    double r_n = 0;
    for (int j=0;j<nevents;j++){
      if (! infile2.Get(Form("waveform2_%d",j)) ) continue;
      h1 = (TH1F*)infile2.Get(Form("waveform2_%d",j));
      hh = (TH1F*)infile2.Get(Form("waveform1_%d",j));
      for (int ii=0;ii<hh->GetNbinsX();ii++){
        hh->SetBinContent(ii+1, -1 * (h1->GetBinContent(ii+1)-1800)/60.);
      }
      //ff->SetParameter(1, 2.22);
      //ff->SetParameter(2, 0.27);
      hh->Fit("ff","EQ");
      r_tot += ff->GetParameter(0);
      r_n ++;
      h_test3[i] ->Fill(ff->GetParameter(0));
    }
    r_decay_tts[i] = r_tot/r_n;
    //cout<<"   mean t0 for decay time "<<i<<" "<<r_tot/r_n<<endl;
  }
  //cout<<"RISE-VARIED NOTTS WBLS1PCT:"<<endl;
  for (int i=0;i<10;i++){
    TFile infile4(Form("bnl1t_waveform_bnl_p_120mev_y57_z-640_upward_wtts_wbls1pct_rise%d_decayD.root",i));
    //if (!infile3) continue;
    double r_tot =0;
    double r_n = 0;
    for (int j=0;j<nevents;j++){
      if (! infile4.Get(Form("waveform2_%d",j)) ) continue;
      h1 = (TH1F*)infile4.Get(Form("waveform2_%d",j));
      hh = (TH1F*)infile4.Get(Form("waveform1_%d",j));
      for (int ii=0;ii<hh->GetNbinsX();ii++){
        hh->SetBinContent(ii+1, -1 * (h1->GetBinContent(ii+1)-1800)/60.);
      }
      //ff->SetParameter(1, 2.22);
      //ff->SetParameter(2, 0.27);      
      hh->Fit("ff","EQ");
      r_tot += ff->GetParameter(0);
      r_n ++;
      h_test4[i]->Fill(ff->GetParameter(0));
    }
    r_rise_tts[i] = r_tot/r_n;
    //cout<<"   mean t0 for rise time "<<i<<" "<<r_tot/r_n<<endl;
  }

  for (int i=0;i<6;i++){
    int il = 50 + 20*i;
    TFile infile5(Form("bnl1t_waveform_bnl_p_120mev_y57_z-640_upward_wtts_wbls1pct_riseD_decayD_width%d.root",il));
    //if (!infile3) continue;
    double r_tot =0;
    double r_n = 0;
    for (int j=0;j<nevents;j++){
      if (! infile5.Get(Form("waveform1_%d",j)) ) continue;
      h1 = (TH1F*)infile5.Get(Form("waveform2_%d",j));
      hh = (TH1F*)infile5.Get(Form("waveform1_%d",j));
      for (int ii=0;ii<hh->GetNbinsX();ii++){
	//cout<<ii<<" "<<hh->GetBinContent(ii+1)<<endl;
        hh->SetBinContent(ii+1, -1 * (hh->GetBinContent(ii+1)-1800)/60.);
      }
      //ff2->SetParameter(1, 2.22);
      //ff2->SetParameter(2, 0.27);      
      hh->Fit("ff2","EQ");
      //cout<<j<<" "<<ff2->GetParameter(0)<<endl;
      r_tot += ff2->GetParameter(0);
      r_n ++;
      h_test5[i]->Fill(ff2->GetParameter(0));
    }
    r_width_tts[i] = r_tot/r_n;
    cout<<"   mean t0 for rise time "<<i<<" "<<r_tot/r_n<<endl;
    //exit(0);
  }
  TFile infile6("bnl1t_waveform_bnl_mu_500mev_z-400_downward_notts_water.root");
  for (int j=0;j<nevents;j++){
    if (! infile6.Get(Form("waveform1_%d",j)) ) continue;
    h1 = (TH1F*)infile6.Get(Form("waveform2_%d",j));
    hh = (TH1F*)infile6.Get(Form("waveform1_%d",j));
    for (int ii=0;ii<hh->GetNbinsX();ii++){
      hh->SetBinContent(ii+1, -1 * (hh->GetBinContent(ii+1)-1800)/60.);
    }
    //ff2->SetParameter(1, 2.22);
    //ff2->SetParameter(2, 0.27);
    hh->Fit("ff3","Q");
    h_test6[0]->Fill(ff3->GetParameter(0));
    cout<<j<<" "<<ff3->GetParameter(0)<<endl;
  }

  TFile infile7("bnl1t_waveform_bnl_mu_500mev_z-400_downward_notts_water.root");
  for (int j=0;j<nevents;j++){
    if (! infile7.Get(Form("waveform1_%d",j)) ) continue;
    h1 = (TH1F*)infile7.Get(Form("waveform2_%d",j));
    hh = (TH1F*)infile7.Get(Form("waveform1_%d",j));
    for (int ii=0;ii<hh->GetNbinsX();ii++){
      hh->SetBinContent(ii+1, -1 * (hh->GetBinContent(ii+1)-1800)/60.);
    }
    //ff2->SetParameter(1, 2.22);
    //ff2->SetParameter(2, 0.27);
    hh->Fit("ff3","EQ");
    h_test7[0]->Fill(ff3->GetParameter(0));
  }
  

  double mean1[10][5]= {};
  double mean2[10][5]= {};
  double mean3[10][5]= {};
  double mean4[10][5]= {};
  double std1[10][5]= {};
  double std2[10][5]= {};
  double std3[10][5]= {};
  double std4[10][5]= {};  
  for (int i=0; i< 10;i++){
    mean1[i][0]=h_test1[i]->GetMean();
    std1[i][0]=h_test1[i]->GetRMS();
    mean1[i][1]=h_test2[i]->GetMean();
    std1[i][1]=h_test2[i]->GetRMS();
    mean1[i][2]=h_test3[i]->GetMean();
    std1[i][2]=h_test3[i]->GetRMS();
    mean1[i][3]=h_test4[i]->GetMean();
    std1[i][3]=h_test4[i]->GetRMS(); 
    mean1[i][4]=h_test5[i]->GetMean();
    std1[i][4]=h_test5[i]->GetRMS();    
  }
  
  TGraph* gg1[5];
  TGraph* gg2[5];
  for (int i=0;i<5;i++){
    gg1[i] = new TGraph(10);
    gg2[i] = new TGraph(10);
  }
  for (int i=0;i<10;i++){
      if (mean1[i][0] > 50&& mean1[i][0]<80){
        gg1[0]->SetPoint(i, 1 +i*1, mean1[i][0]);
        gg2[0]->SetPoint(i, 1 +i*1, std1[i][0]);
      }
      if (mean1[i][1] > 50&& mean1[i][1]<80){      
        gg1[1]->SetPoint(i, 1 +i*1, mean1[i][1]);
        gg2[1]->SetPoint(i, 1 +i*1, std1[i][1]);
      }
      if (mean1[i][2] > 50&& mean1[i][2]<80){      
        gg1[2]->SetPoint(i, 1 +i*1, mean1[i][2]);
        gg2[2]->SetPoint(i, 1 +i*1, std1[i][2]);
      }
      if (mean1[i][3] > 50&& mean1[i][3]<80){      
        gg1[3]->SetPoint(i, 1 +i*1, mean1[i][3]);
        gg2[3]->SetPoint(i, 1 +i*1, std1[i][3]);      
      }
      if (mean1[i][4] > 50&& mean1[i][4]<80){
	//if (i != 3){
          gg1[4]->SetPoint(i, 50 +i*20, mean1[i][4]);
          gg2[4]->SetPoint(i, 50 +i*20, std1[i][4]);
	//}
	//else{
          //gg1[4]->SetPoint(i, 50 +50, mean1[i][4]);
          //gg2[4]->SetPoint(i, 50 +50, std1[i][4]);	
	//}
      }      
  }

  new TCanvas();
  gg1[0]->SetTitle("Scintillation time variation; Rise time (0.1 ns)/Decay time (1 ns)  ;T0 Mean");
  gg1[0]->SetMarkerStyle(20);
  gg1[0]->SetMarkerSize(4);
  gg1[0]->SetMarkerColor(1);
  gg1[1]->SetMarkerStyle(20);
  gg1[1]->SetMarkerSize(4);
  gg1[1]->SetMarkerColor(2);
  gg1[2]->SetMarkerStyle(20);
  gg1[2]->SetMarkerSize(4);
  gg1[2]->SetMarkerColor(3);
  gg1[3]->SetMarkerStyle(20);
  gg1[3]->SetMarkerSize(4);
  gg1[3]->SetMarkerColor(4);
  gg1[0]->Draw("PAL");
  gg1[1]->Draw("same");
  gg1[2]->Draw("same");
  //gg1[3]->Draw("same ");
  TLegend* leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(gg1[0],"Decay variation no TTS","p");
  leg->AddEntry(gg1[1] ,"Rise variation no TTS","p");
  leg->AddEntry(gg1[2] ,"Decay variation w/ TTS","p");
  leg->Draw();

  new TCanvas();
  gg2[0]->SetTitle("Scintillation time variation; Rise time (0.1 ns)/Decay time (1 ns)  ;T0 std. dev.") ;  
  gg2[0]->SetMarkerStyle(20);
  gg2[0]->SetMarkerSize(4);
  gg2[0]->SetMarkerColor(1);
  gg2[1]->SetMarkerStyle(20);
  gg2[1]->SetMarkerSize(4);
  gg2[1]->SetMarkerColor(2);
  gg2[2]->SetMarkerStyle(20);
  gg2[2]->SetMarkerSize(4);
  gg2[2]->SetMarkerColor(3);
  gg2[3]->SetMarkerStyle(20);
  gg2[3]->SetMarkerSize(4);
  gg2[3]->SetMarkerColor(4);
  gg2[0]->Draw("PAL");
  gg2[1]->Draw("same");
  gg2[2]->Draw("same");
  //gg2[3]->Draw("same ");
  leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(gg2[0],"Decay variation no TTS","p");
  leg->AddEntry(gg2[1] ,"Rise variation no TTS","p");
  leg->AddEntry(gg2[2] ,"Decay variation w/ TTS","p");
  leg->Draw();

  new TCanvas();
  gg1[4]->SetTitle("Pulse width variation; Pulse width ;T0 mean") ;
  gg1[4]->SetMarkerStyle(20);
  gg1[4]->SetMarkerSize(4);
  gg1[4]->SetMarkerColor(1);
  gg1[4]->Draw("PAL");

  new TCanvas();
  gg2[4]->SetTitle("Pulse width variation; Pulse width ;T0 std. dev.") ;
  gg2[4]->SetMarkerStyle(20);
  gg2[4]->SetMarkerSize(4);
  gg2[4]->SetMarkerColor(1);
  gg2[4]->Draw("PAL");


  cout<<"DECAY-VARIED NOTTS WBLS1PCT:"<<endl;
  for (int i=0;i<10;i++){
	  cout<<"   mean t0 for decay time "<<i<<" "<<r_decay[i]<<endl;
          cout<<"   rms t0 for decay time "<<i<<" "<<h_test1[i]->GetRMS()<<endl;
  }
  cout<<"RISE-VARIED NOTTS WBLS1PCT:"<<endl;
  for (int i=0;i<10;i++){
          cout<<"   mean t0 for rise time "<<i<<" "<<r_rise[i]<<endl;
          cout<<"   rms t0 for decay time "<<i<<" "<<h_test2[i]->GetRMS()<<endl;  
  }
  cout<<"DECAY-VARIED WTTS WBLS1PCT:"<<endl;
  for (int i=0;i<10;i++){
          cout<<"   mean t0 for decay time "<<i<<" "<<r_decay_tts[i]<<endl;
          cout<<"   rms t0 for decay time "<<i<<" "<<h_test3[i]->GetRMS()<<endl;
  }	  
  cout<<"RISE-VARIED WTTS WBLS1PCT:"<<endl;
  for (int i=0;i<10;i++){
          cout<<"   mean t0 for rise time "<<i<<" "<<r_rise_tts[i]<<endl;
          cout<<"   rms t0 for rise time "<<i<<" "<<h_test4[i]->GetRMS()<<endl;
  }	  


  TCanvas* c1 = new TCanvas();
  c1->Divide(3,3);
  c1->cd(1);
  h_test1[0]->Draw();
  for (int i=1;i<9;i++){
    c1->cd(i+1);
    h_test1[i]->Draw();
  }
  TCanvas* c2 = new TCanvas();
  c2->Divide(3,3);
  c2->cd(1);
  h_test2[0]->Draw();
  for (int i=1;i<9;i++){
    c2->cd(i+1);
    h_test2[i]->Draw();
  } 

  TCanvas* c3 = new TCanvas();
  c3->Divide(3,3);
  c3->cd(1);
  h_test5[0]->Draw();
  for (int i=1;i<6;i++){
    c3->cd(i+1);
    h_test5[i]->Draw();
  }

  TCanvas* c4 = new TCanvas();
  h_test6[0]->SetLineWidth(3);
  h_test6[0]->SetLineWidth(3);
  h_test6[0]->SetLineColor(2);
  h_test7[0]->SetLineColor(4);
  h_test6[0]->Draw();
  //h_test7[0]->Draw("same");

/*
  TFile infile2("bnl1t_waveform_bnl_p_120mev_y57_z-640_upward_wtts_wbls1pct_rise2_decayD.root");
  for (int j=0;j<nevents;j++){
    if (! infile2.Get(Form("waveform1_%d",j)) ) continue;
    h12 = (TH1F*)infile2.Get(Form("waveform1_%d",j));
    //cout<<h1->GetNbinsX()<<endl;
    //h1->Fit("ff");
    hh2 = (TH1F*)infile2.Get(Form("waveform1_%d",j));
    for (int i=0;i<hh2->GetNbinsX();i++){
      hh2->SetBinContent(i+1, -1 * (h12->GetBinContent(i+1)-1800)/60.);
    }
    break;
  }
  hh2->Fit("ff2");
  TCanvas* c1 = new TCanvas();
  //c1->cd();
  hh2->SetLineColor(2);
  ff2->SetLineColor(2);
  hh2->Draw();
  //hh->Fit("ff");
  ff2->Draw("same");
  hh->SetLineColor(4);
  ff->SetLineColor(4);
  hh->Draw("same");
  ff->Draw("same");
*/

  //TCanvas* c2 = new TCanvas();
  //c2->cd();
  //h1->Fit("ff");
  //ff->Draw();
  //h1->Draw();
  //ff->Draw("same");


}
