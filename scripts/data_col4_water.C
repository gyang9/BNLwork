void data_col4_water()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Oct 17 20:26:20 2022) by ROOT version 6.16/00
   TCanvas *c1 = new TCanvas("c1", "c1",67,57,1782,1263);
   c1->Range(-31.25,-6.956251,161.25,62.60625);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__3 = new TH1F("htemp__3","pulse_area_col4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-12,142);
   htemp__3->SetBinContent(8,3);
   htemp__3->SetBinContent(9,9);
   htemp__3->SetBinContent(10,25);
   htemp__3->SetBinContent(11,53);
   htemp__3->SetBinContent(12,52);
   htemp__3->SetBinContent(13,52);
   htemp__3->SetBinContent(14,38);
   htemp__3->SetBinContent(15,30);
   htemp__3->SetBinContent(16,23);
   htemp__3->SetBinContent(17,16);
   htemp__3->SetBinContent(18,5);
   htemp__3->SetBinContent(19,7);
   htemp__3->SetBinContent(20,2);
   htemp__3->SetBinContent(21,2);
   htemp__3->SetBinContent(22,1);
   htemp__3->SetBinContent(23,2);
   htemp__3->SetBinContent(24,2);
   htemp__3->SetBinContent(25,2);
   htemp__3->SetBinContent(26,1);
   htemp__3->SetBinContent(27,2);
   htemp__3->SetBinContent(28,3);
   htemp__3->SetBinContent(31,2);
   htemp__3->SetBinContent(38,1);
   htemp__3->SetBinContent(48,1);
   htemp__3->SetBinContent(65,1);
   htemp__3->SetBinContent(93,1);
   htemp__3->SetEntries(336);
   htemp__3->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("htemp");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 336    ");
   ptstats_LaTex = ptstats->AddText("Mean  =  9.247");
   ptstats_LaTex = ptstats->AddText("Std Dev   =   10.3");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__3->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__3);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__3->SetLineColor(ci);
   htemp__3->GetXaxis()->SetTitle("pulse_area_col4_pe");
   htemp__3->GetXaxis()->SetRange(1,100);
   htemp__3->GetXaxis()->SetLabelFont(42);
   htemp__3->GetXaxis()->SetLabelSize(0.035);
   htemp__3->GetXaxis()->SetTitleSize(0.035);
   htemp__3->GetXaxis()->SetTitleOffset(1);
   htemp__3->GetXaxis()->SetTitleFont(42);
   htemp__3->GetYaxis()->SetLabelFont(42);
   htemp__3->GetYaxis()->SetLabelSize(0.035);
   htemp__3->GetYaxis()->SetTitleSize(0.035);
   htemp__3->GetYaxis()->SetTitleFont(42);
   htemp__3->GetZaxis()->SetLabelFont(42);
   htemp__3->GetZaxis()->SetLabelSize(0.035);
   htemp__3->GetZaxis()->SetTitleSize(0.035);
   htemp__3->GetZaxis()->SetTitleOffset(1);
   htemp__3->GetZaxis()->SetTitleFont(42);
   htemp__3->Draw("");
   
   TPaveText *pt = new TPaveText(0.15,0.9366532,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("pulse_area_col4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
