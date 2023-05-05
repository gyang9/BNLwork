void data_col3_water()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Oct 17 20:25:53 2022) by ROOT version 6.16/00
   TCanvas *c1 = new TCanvas("c1", "c1",67,57,1782,1263);
   c1->Range(-15.5,-3.54375,139.5,31.89375);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__2 = new TH1F("htemp__2","pulse_area_col3_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,0,124);
   htemp__2->SetBinContent(1,1);
   htemp__2->SetBinContent(2,3);
   htemp__2->SetBinContent(4,1);
   htemp__2->SetBinContent(5,4);
   htemp__2->SetBinContent(6,6);
   htemp__2->SetBinContent(7,6);
   htemp__2->SetBinContent(8,7);
   htemp__2->SetBinContent(9,15);
   htemp__2->SetBinContent(10,17);
   htemp__2->SetBinContent(11,11);
   htemp__2->SetBinContent(12,24);
   htemp__2->SetBinContent(13,21);
   htemp__2->SetBinContent(14,27);
   htemp__2->SetBinContent(15,23);
   htemp__2->SetBinContent(16,13);
   htemp__2->SetBinContent(17,22);
   htemp__2->SetBinContent(18,17);
   htemp__2->SetBinContent(19,10);
   htemp__2->SetBinContent(20,15);
   htemp__2->SetBinContent(21,15);
   htemp__2->SetBinContent(22,12);
   htemp__2->SetBinContent(23,10);
   htemp__2->SetBinContent(24,6);
   htemp__2->SetBinContent(25,9);
   htemp__2->SetBinContent(26,3);
   htemp__2->SetBinContent(27,6);
   htemp__2->SetBinContent(28,3);
   htemp__2->SetBinContent(29,4);
   htemp__2->SetBinContent(30,3);
   htemp__2->SetBinContent(31,4);
   htemp__2->SetBinContent(32,1);
   htemp__2->SetBinContent(33,1);
   htemp__2->SetBinContent(35,1);
   htemp__2->SetBinContent(36,1);
   htemp__2->SetBinContent(37,4);
   htemp__2->SetBinContent(38,2);
   htemp__2->SetBinContent(39,1);
   htemp__2->SetBinContent(41,2);
   htemp__2->SetBinContent(47,2);
   htemp__2->SetBinContent(48,1);
   htemp__2->SetBinContent(70,1);
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
   ptstats_LaTex = ptstats->AddText("Mean  =  21.05");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  11.43");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__2->SetLineColor(ci);
   htemp__2->GetXaxis()->SetTitle("pulse_area_col3_pe");
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
   
   TPaveText *pt = new TPaveText(0.15,0.9366532,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("pulse_area_col3_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
