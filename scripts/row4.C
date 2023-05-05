void row4()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Oct 25 19:56:56 2022) by ROOT version 6.16/00
   TCanvas *c1 = new TCanvas("c1", "c1",67,57,700,500);
   c1->Range(-42.5,-5.90625,232.5,53.15625);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__4 = new TH1F("htemp__4","pulse_area_row4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-15,205);
   htemp__4->SetBinContent(7,1);
   htemp__4->SetBinContent(8,2);
   htemp__4->SetBinContent(11,2);
   htemp__4->SetBinContent(12,7);
   htemp__4->SetBinContent(13,11);
   htemp__4->SetBinContent(14,28);
   htemp__4->SetBinContent(15,30);
   htemp__4->SetBinContent(16,36);
   htemp__4->SetBinContent(17,34);
   htemp__4->SetBinContent(18,45);
   htemp__4->SetBinContent(19,31);
   htemp__4->SetBinContent(20,35);
   htemp__4->SetBinContent(21,22);
   htemp__4->SetBinContent(22,13);
   htemp__4->SetBinContent(23,9);
   htemp__4->SetBinContent(24,7);
   htemp__4->SetBinContent(25,3);
   htemp__4->SetBinContent(26,4);
   htemp__4->SetBinContent(27,3);
   htemp__4->SetBinContent(28,2);
   htemp__4->SetBinContent(29,1);
   htemp__4->SetBinContent(30,2);
   htemp__4->SetBinContent(31,1);
   htemp__4->SetBinContent(33,1);
   htemp__4->SetBinContent(37,2);
   htemp__4->SetBinContent(41,1);
   htemp__4->SetBinContent(70,1);
   htemp__4->SetBinContent(71,1);
   htemp__4->SetBinContent(94,1);
   htemp__4->SetEntries(336);
   htemp__4->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("htemp");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 336    ");
   ptstats_LaTex = ptstats->AddText("Mean  =  25.19");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  15.59");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__4->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__4);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__4->SetLineColor(ci);
   htemp__4->GetXaxis()->SetTitle("pulse_area_row4_pe");
   htemp__4->GetXaxis()->SetRange(1,100);
   htemp__4->GetXaxis()->SetLabelFont(42);
   htemp__4->GetXaxis()->SetLabelSize(0.035);
   htemp__4->GetXaxis()->SetTitleSize(0.035);
   htemp__4->GetXaxis()->SetTitleOffset(1);
   htemp__4->GetXaxis()->SetTitleFont(42);
   htemp__4->GetYaxis()->SetLabelFont(42);
   htemp__4->GetYaxis()->SetLabelSize(0.035);
   htemp__4->GetYaxis()->SetTitleSize(0.035);
   htemp__4->GetYaxis()->SetTitleFont(42);
   htemp__4->GetZaxis()->SetLabelFont(42);
   htemp__4->GetZaxis()->SetLabelSize(0.035);
   htemp__4->GetZaxis()->SetTitleSize(0.035);
   htemp__4->GetZaxis()->SetTitleOffset(1);
   htemp__4->GetZaxis()->SetTitleFont(42);
   htemp__4->Draw("");
   
   TPaveText *pt = new TPaveText(0.15,0.9338535,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("pulse_area_row4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
