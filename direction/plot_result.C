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

  TH2F* h2_x = new TH2F("","Fitting result (1D X); True angle (deg.); Reco. angle (deg.)", 8,0,20,8,0,20);

  TH2F* h2_y = new TH2F("","Fitting result (1D Y); True angle (deg.); Reco. angle (deg.)", 8,0,20,8,0,20);

  TH1F* h1_x[10];
  TH1F* h1_y[10];

  TGraph* gx = new TGraph(7);
  gx ->SetTitle("1D Resolution; True direction (deg.); Resolution (deg.)");
  TGraph* gy = new TGraph(7);
  gy ->SetTitle("1D Resolution; True direction (deg.); Resolution (deg.)");


  for (int i=0;i<7;i++){
    ifstream in;
    in.open(Form("first_result_x_%d.txt",i*5));
    int aa,bb,cc; double dd;
    h1_x[i] = new TH1F("","",10,0,20);
    while (!in.eof())  {
      in>>aa>>bb>>cc>>dd;
      if (cc == -1) {
        h2_x->Fill( TMath::ATan(5.*i/100.)*57, TMath::ATan(5.*aa/100.)*57);
        h1_x[i]->Fill(abs(TMath::ATan(5.*aa/100.)*57 - TMath::ATan(5.*i/100.)*57) );
      }
    }
    TGraph hh(h1_x[i]);
    double factor = 30.;
    double r1[1000]={};
    double to1 = 0;
    for (int i=0;i<1000; i++){
      r1[i] = hh.Eval(factor/1000.* (i));
      to1 += hh.Eval(factor/1000.* (i));
      //cout<<i<<" "<<r1[i]<<endl;
    }
    double cu1 = 0;
    double check = 0;
    for (int i = 0; i< 1000; i++){
      cu1 += r1[i];
      if (cu1 / to1 > 0.68) {
        check = factor/1000.*i;
        break;
      }
    }
    gx->SetPoint(i,TMath::ATan(5.*i/100.)*57, check);
    cout<<"x location "<<i<<" resoltion "<<check<<endl;
  }

  for (int i=0;i<7;i++){
    ifstream in;
    in.open(Form("first_result_y_%d.txt",i*5));
    int aa,bb,cc; double dd;
    h1_y[i] = new TH1F("","",10,0,20);
    while (!in.eof())  {
      in>>aa>>bb>>cc>>dd;
      if (cc == -1) {
        h2_y->Fill( TMath::ATan(5.*i/100.)*57, TMath::ATan(5.*aa/100.)*57);
        h1_y[i]->Fill(TMath::ATan(5.*aa/100.)*57 - TMath::ATan(5.*i/100.)*57);
      }
    }
    TGraph hh2(h1_y[i]);
    double factor = 30.;
    double r1[1000]={};
    double to1 = 0;
    for (int i=0;i<1000; i++){
      r1[i] = hh2.Eval(factor/1000.* (i));
      to1 += hh2.Eval(factor/1000.* (i));
      //cout<<i<<" "<<r1[i]<<endl;
    }
    double cu1 = 0;
    double check = 0;
    for (int i = 0; i< 1000; i++){
      cu1 += r1[i];
      if (cu1 / to1 > 0.68) {
        check = factor/1000.*i;
        break;
      }
    }
    gy->SetPoint(i,TMath::ATan(5.*i/100.)*57, check);
  }

  new TCanvas();
  h2_x->Draw("colz");

  new TCanvas();
  h2_y->Draw("colz");

  TCanvas* c1 = new TCanvas();
  c1->Divide(2,3);
  for (int i=0;i<6;i++){
    c1->cd(i+1);
    h1_x[i]->SetTitle(Form("x location %d; Reco. angle (deg.); counts",i*5));
    h1_x[i]->Draw();
  }

  TCanvas* c2 = new TCanvas();
  c2->Divide(2,3);
  for (int i=0;i<6;i++){
    c2->cd(i+1);
    h1_y[i]->SetTitle(Form("x location %d; Reco. angle (deg.); counts",i*5));
    h1_y[i]->Draw();
  }

  new TCanvas();
  gx->SetMarkerColor(2);
  gy->SetMarkerColor(4);
  gx->SetMarkerSize(4);
  gy->SetMarkerSize(4);
  gx->SetMarkerStyle(20);
  gy->SetMarkerStyle(20);
  gy->Draw("PAL");
  gx->Draw("same");
  TLegend* leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(gx ,"Along X","p");
  leg->AddEntry(gy ,"Along Y","p");
  leg->Draw();

}
