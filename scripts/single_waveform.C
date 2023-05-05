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

  TF1* ff[10];

  for (int i=0;i<10;i++){
    ff[i] = new TF1(Form("ff%d",i),"[3]*(exp(-((x-[0]>0)? x-[0]: 0)/[1]) - exp(-((x-[0]>0)? x-[0]: 0)/[2]))/([1]-[2]) ",50,100);
    ff[i]->SetParameter(0, 62);
    ff[i]->SetParameter(1, 2.22);
    ff[i]->SetParameter(2, 1.27);
    ff[i]->SetParameter(3, 2);
  }

  double r_decay[10]={};
  double r_rise[10]={};
  double r_decay_tts[10]={};
  double r_rise_tts[10]={};
  TH1F* hh[10];
  TH1F* hh2[10];
  //TFile infile("bnl1t_waveform_temp.root");
  //cout<<"DECAY-VARIED NOTTS WBLS1PCT:"<<endl;
  //for (int i=1;i<2;i++){
    int i =2;
    TFile infile(Form("bnl1t_waveform_bnl_p_120mev_y57_z-640_upward_notts_wbls1pct_riseD_decay%d.root",i));
    //if (!infile) continue;
    double r_tot =0;
    double r_n = 0;
    cout<<111<<endl;
    for (int j=0;j<1;j++){ 
      if (! infile.Get(Form("waveform1_%d",j)) ) continue;
      hh[i] = (TH1F*)infile.Get(Form("waveform1_%d",j));
      cout<<222<< " "<<j<<endl;
      cout<<hh[i]->GetNbinsX()<<endl;
      for (int ii=0;ii<hh[i]->GetNbinsX();ii++){
        hh[i]->SetBinContent(ii+1, -1 * (hh[i]->GetBinContent(ii+1)-1800)/60.);
      }
      cout<<333<<endl;
      hh[i]->Scale(1./hh[i]->Integral());
      hh[i]->Fit(Form("ff%d",i));
      //break;
    }

    i =8;
    TFile infile2(Form("bnl1t_waveform_bnl_p_120mev_y57_z-640_upward_notts_wbls1pct_riseD_decay%d.root",i));
    //if (!infile) continue;
    r_tot =0;
    r_n = 0;
    cout<<111<<endl;
    for (int j=0;j<1;j++){
      if (! infile2.Get(Form("waveform1_%d",j)) ) continue;
      hh[i] = (TH1F*)infile2.Get(Form("waveform1_%d",j));
      cout<<222<< " "<<j<<endl;
      cout<<hh[i]->GetNbinsX()<<endl;
      for (int ii=0;ii<hh[i]->GetNbinsX();ii++){
        hh[i]->SetBinContent(ii+1, -1 * (hh[i]->GetBinContent(ii+1)-1800)/60.);
      }
      cout<<333<<endl;
      hh[i]->Scale(1./hh[i]->Integral());
      hh[i]->Fit(Form("ff%d",i));
      //break;
    }

    i = 2;
    TFile infile3(Form("bnl1t_waveform_bnl_p_120mev_y57_z-640_upward_wtts_wbls1pct_riseD_decay%d.root",i));
    //if (!infile) continue;
    r_tot =0;
    r_n = 0;
    cout<<111<<endl;
    for (int j=0;j<1;j++){
      if (! infile3.Get(Form("waveform1_%d",j)) ) continue;
      hh2[i] = (TH1F*)infile3.Get(Form("waveform1_%d",j));
      cout<<222<< " "<<j<<endl;
      cout<<hh2[i]->GetNbinsX()<<endl;
      for (int ii=0;ii<hh2[i]->GetNbinsX();ii++){
        hh2[i]->SetBinContent(ii+1, -1 * (hh2[i]->GetBinContent(ii+1)-1800)/60.);
      }
      cout<<333<<endl;
      hh2[i]->Scale(1./hh2[i]->Integral());
      hh2[i]->Fit(Form("ff%d",i+1));
      //break;
    }

    //infile.Close();
  //}
  cout<<555<<endl;

  cout<<hh[2]->Integral()<<endl;
  new TCanvas();
  hh[2]->SetLineWidth(4);
  hh[8]->SetLineWidth(4);
  hh2[2]->SetLineWidth(4);
  hh[2]->SetLineColor(1);
  hh[8]->SetLineColor(2);
  hh2[2]->SetLineColor(4);
  ff[2]->SetLineColor(1);
  ff[2]->SetLineWidth(4);
  ff[8]->SetLineColor(2);
  ff[8]->SetLineWidth(4);
  ff[3]->SetLineColor(4);
  ff[3]->SetLineWidth(4);  
  hh[2]->Draw("hist");
  hh[8]->Draw("same hist");
  hh2[2]->Draw("same hist");
  ff[2]->Draw("same");
  ff[8]->Draw("same");
  ff[3]->Draw("same");
  TLegend* leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(hh[2],"Decay 2 ns no TTS","l");
  leg->AddEntry(hh[8] ,"Decay 8 ns no TTS","l");
  leg->AddEntry(hh2[2] ,"Decay 2 ns w/ TTS","l");
  leg->Draw();


  //TCanvas* c1 = new TCanvas();
  //c1->Divide(3,3);
  //c1->cd(1);
  //hh[1]->Draw();
  //ff[2]->Draw("same");
  //ff[8]->Draw("same");
  //ff[3]->Draw("same");
/*
  for (int i=2;i<10;i++){
    cout<<i<<endl;
    c1->cd(i);
    cout<<33<<endl;
    hh[i]->Draw("same");
    cout<<55<<endl;
    ff[i]->Draw("same");
  }
*/
}
