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

  //TFile f("bnl1t_file_x_0_y_0_500mev_new2.root");
  TFile f("bnl1t_file_center_4gev_new2.root");
  TH2F* th_c = (TH2F*)f.Get("th_c");
  TH2F* th_s = (TH2F*)f.Get("th_s");
  TH2F* th_r = (TH2F*)f.Get("th_r");
  TH2F* th_r2 = (TH2F*)f.Get("th_r2");

  th_c->SetTitle("Cherenkov hits; Z location (mm); Time (ns)");
  th_s->SetTitle("Scintillation hits; Z location (mm); Time (ns)");
  th_r->SetTitle("Reflection hits; Z location (mm); Time (ns)");
  th_r2->SetTitle("Reflection2 hits; Z location (mm); Time (ns)");

  cout<<"total counts for c, s, r, r2: "<<th_c->Integral()<<" "<<th_s->Integral()<<" "<<th_r->Integral()<<" "<<th_r2->Integral()<<endl;
  cout<<"ratio "<<th_r->Integral()/(th_c->Integral()+th_s->Integral())<<" "<<th_r2->Integral()/(th_c->Integral()+th_s->Integral())<<endl;
  TCanvas* c1 = new TCanvas();
  c1->Divide(2,2);
  c1->cd(1);
  c1->SetLogz();
  th_c->Draw("colz");
  c1->cd(2);
  th_s->Draw("colz");
  c1->cd(3);
  th_r->Draw("colz");
}
