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

  TFile f("bnl1t_newwater2_x_0_y_0_traj.root");
  TH1F* h_inner_wavelength = (TH1F*)f.Get("h_inner_wavelength");
  TH1F* h_pmt_dynode_wavelength = (TH1F*)f.Get("h_pmt_dynode_wavelength");
  TH1F* h_pmt_cookie = (TH1F*)f.Get("h_pmt_cookie");
  TH1F* h_liquid_tank = (TH1F*)f.Get("h_liquid_tank");
  TH1F* h_tank_world = (TH1F*)f.Get("h_tank_world");
  TH1F* h_tank = (TH1F*)f.Get("h_tank");
  TH1F* h_world = (TH1F*)f.Get("h_world");
  TH1F* h_pmt_dynode_wavelength_ref = (TH1F*)f.Get("h_pmt_dynode_wavelength_ref");
  TH1F* h_pmt_cookie_ref = (TH1F*)f.Get("h_pmt_cookie_ref");
  TH1F* h_liquid_tank_ref = (TH1F*)f.Get("h_liquid_tank_ref");
  TH1F* h_tank_world_ref = (TH1F*)f.Get("h_tank_world_ref");
  TH1F* h_detected_wavelength = (TH1F*)f.Get("h_detected_wavelength");
  TH1F* h_detected_lambda = (TH1F*)f.Get("h_detected_lambda");

  h_inner_wavelength->SetLineColor(1);
  h_pmt_dynode_wavelength->SetLineColor(2);
  h_pmt_cookie->SetLineColor(3);  
  h_liquid_tank->SetLineColor(4);
  h_tank_world->SetLineColor(1);  
  h_tank_world->SetLineStyle(3);
  h_tank->SetLineColor(2);  
  h_tank->SetLineStyle(2);
  h_world->SetLineColor(4);  
  h_world->SetLineStyle(2);
  h_pmt_dynode_wavelength_ref->SetLineColor(8);
  h_pmt_cookie_ref->SetLineColor(9);  
  h_liquid_tank_ref->SetLineColor(14);
  h_tank_world_ref->SetLineColor(20);  
  h_detected_lambda->SetLineColor(2);
  h_detected_lambda->SetLineStyle(2);

  h_inner_wavelength->SetLineWidth(4);
  h_pmt_dynode_wavelength->SetLineWidth(4);
  h_pmt_cookie->SetLineWidth(4);
  h_liquid_tank->SetLineWidth(4);
  h_tank_world->SetLineWidth(4);
  h_tank_liquid->SetLineWidth(4);
  h_world_tank->SetLineWidth(4);
  h_tank->SetLineWidth(4);
  h_world->SetLineWidth(4);
  h_pmt_dynode_wavelength_ref->SetLineWidth(4);
  h_pmt_cookie_ref->SetLineWidth(4);
  h_liquid_tank_ref->SetLineWidth(4);
  h_tank_world_ref->SetLineWidth(4);
  h_detected_lambda->SetLineWidth(4);

  h_inner_wavelength->Rebin(5);
  h_pmt_dynode_wavelength->Rebin(5);
  h_pmt_cookie->Rebin(5);
  h_liquid_tank->Rebin(5);
  h_tank_world->Rebin(5);
  h_tank->Rebin(5);
  h_world->Rebin(5);
  h_pmt_dynode_wavelength_ref->Rebin(5);
  h_pmt_cookie_ref->Rebin(5);
  h_liquid_tank_ref->Rebin(5);
  h_tank_world_ref->Rebin(5);
  h_detected_lambda->Rebin(5);

  h_inner_wavelength->Scale(1./h_inner_wavelength->Integral());
  h_pmt_dynode_wavelength->Scale(1./h_pmt_dynode_wavelength->Integral());
  h_pmt_cookie->Scale(1./h_pmt_cookie->Integral());
  h_liquid_tank->Scale(1./h_liquid_tank->Integral());
  h_tank_world->Scale(1./h_tank_world->Integral());  
  h_tank->Scale(1./h_tank->Integral());
  h_world->Scale(1./h_world->Integral()); 
  h_pmt_dynode_wavelength_ref->Scale(1./h_pmt_dynode_wavelength_ref->Integral());
  h_pmt_cookie_ref->Scale(1./h_pmt_cookie_ref->Integral());
  h_liquid_tank_ref->Scale(1./h_liquid_tank_ref->Integral());
  h_tank_world_ref->Scale(1./h_tank_world_ref->Integral());  
  h_detected_lambda->Scale(1./h_detected_lambda->Integral());

  new TCanvas();
  //h_inner_wavelength->Draw("hist");
  //h_pmt_dynode_wavelength->Draw("hist");
  h_pmt_cookie->Draw("same");
  h_liquid_tank->Draw("same");
  h_tank_world->Draw("same");
  h_detected_lambda->Draw("same");
  //h_tank->Draw("same");
  //h_world->Draw("same");

  TLegend* leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  //leg->AddEntry(h_inner_wavelength ,"Inner Acrylic","l");
  //leg->AddEntry(h_pmt_dynode_wavelength ,"pmt dynode","l");
  leg->AddEntry(h_pmt_cookie ,"pmt cookie","l");
  leg->AddEntry(h_liquid_tank ,"liquid-tank surface","l");
  leg->AddEntry(h_tank_world ,"tank-world surface","l");  
  leg->AddEntry(h_detected_lambda, "detected", "l");
  //leg->AddEntry(h_tank ,"at first tank","l");
  //leg->AddEntry(h_world ,"at first world","l");  
  leg->Draw();

  new TCanvas();
  //h_inner_wavelength->Draw("hist");
  h_pmt_dynode_wavelength->Draw("hist");
  h_pmt_cookie->Draw("same");
  h_pmt_dynode_wavelength_ref->Draw("same");
  h_pmt_cookie_ref->Draw("same");
  //h_tank->Draw("same");
  //h_world->Draw("same");

  leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  //leg->AddEntry(h_inner_wavelength ,"Inner Acrylic","l");
  leg->AddEntry(h_pmt_dynode_wavelength ,"pmt dynode","l");
  leg->AddEntry(h_pmt_cookie ,"pmt cookie","l");
  leg->AddEntry(h_pmt_dynode_wavelength_ref ,"pmt dynode ref.","l");
  leg->AddEntry(h_pmt_cookie_ref ,"pmt cookie ref.","l");
  //leg->AddEntry(h_tank ,"at first tank","l");
  //leg->AddEntry(h_world ,"at first world","l");  
  leg->Draw();

  new TCanvas();
  //h_inner_wavelength->Draw("hist");
  h_liquid_tank_ref->Draw("hist");
  //h_tank_world_ref->Draw("same");
  h_liquid_tank->Draw("same");
  //h_tank_world->Draw("same");
  //h_tank->Draw("same");
  //h_world->Draw("same");

  leg = new TLegend(0.6,0.68,0.9,0.9,NULL,"brNDC");
  //leg->AddEntry(h_inner_wavelength ,"Inner Acrylic","l");
  leg->AddEntry(h_liquid_tank_ref ,"liquid-tank surface reflected","l");
  //leg->AddEntry(h_tank_world_ref ,"tank-world surface ref.","l");
  leg->AddEntry(h_liquid_tank ,"liquid-tank surface","l");
  //leg->AddEntry(h_tank_world ,"tank-world surface","l");
  //leg->AddEntry(h_tank ,"at first tank","l");
  //leg->AddEntry(h_world ,"at first world","l");  
  leg->Draw();
  

}
