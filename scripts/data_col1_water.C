void data_col1_water()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Oct 17 20:24:40 2022) by ROOT version 6.16/00
   TCanvas *c1 = new TCanvas("c1", "c1",67,57,1844,1317);
   c1->Range(-32.25,-5.38125,170.25,48.43125);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__2 = new TH1F("htemp__2","pulse_area_col1_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-12,150);
   htemp__2->SetBinContent(8,1);
   htemp__2->SetBinContent(10,1);
   htemp__2->SetBinContent(11,3);
   htemp__2->SetBinContent(12,8);
   htemp__2->SetBinContent(13,7);
   htemp__2->SetBinContent(14,8);
   htemp__2->SetBinContent(15,19);
   htemp__2->SetBinContent(16,19);
   htemp__2->SetBinContent(17,21);
   htemp__2->SetBinContent(18,37);
   htemp__2->SetBinContent(19,41);
   htemp__2->SetBinContent(20,35);
   htemp__2->SetBinContent(21,28);
   htemp__2->SetBinContent(22,25);
   htemp__2->SetBinContent(23,15);
   htemp__2->SetBinContent(24,20);
   htemp__2->SetBinContent(25,10);
   htemp__2->SetBinContent(26,14);
   htemp__2->SetBinContent(27,2);
   htemp__2->SetBinContent(28,3);
   htemp__2->SetBinContent(29,1);
   htemp__2->SetBinContent(30,5);
   htemp__2->SetBinContent(31,3);
   htemp__2->SetBinContent(34,1);
   htemp__2->SetBinContent(36,1);
   htemp__2->SetBinContent(38,1);
   htemp__2->SetBinContent(39,1);
   htemp__2->SetBinContent(42,2);
   htemp__2->SetBinContent(46,1);
   htemp__2->SetBinContent(56,1);
   htemp__2->SetBinContent(86,1);
   htemp__2->SetBinContent(92,1);
   htemp__2->SetEntries(336);
   htemp__2->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("htemp");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 336    ");
   ptstats_LaTex = ptstats->AddText("Mean  =  20.67");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  12.16");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__2->SetLineColor(ci);
   htemp__2->GetXaxis()->SetTitle("pulse_area_col1_pe");
   htemp__2->GetXaxis()->SetRange(1,100);
   htemp__2->GetXaxis()->SetLabelFont(42);
   htemp__2->GetXaxis()->SetLabelSize(0.035);
   htemp__2->GetXaxis()->SetTitleSize(0.035);
   htemp__2->GetXaxis()->SetTitleOffset(1);
   htemp__2->GetXaxis()->SetTitleFont(42);
   htemp__2->GetYaxis()->SetLabelFont(42);
   htemp__2->GetYaxis()->SetLabelSize(0.035);
   htemp__2->GetYaxis()->SetTitleSize(0.035);
   htemp__2->GetYaxis()->SetTitleFont(42);
   htemp__2->GetZaxis()->SetLabelFont(42);
   htemp__2->GetZaxis()->SetLabelSize(0.035);
   htemp__2->GetZaxis()->SetTitleSize(0.035);
   htemp__2->GetZaxis()->SetTitleOffset(1);
   htemp__2->GetZaxis()->SetTitleFont(42);
   htemp__2->Draw("");
   
   TPaveText *pt = new TPaveText(0.15,0.9353727,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("pulse_area_col1_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
