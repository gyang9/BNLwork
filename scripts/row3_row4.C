void row3_row4()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Oct 25 19:52:43 2022) by ROOT version 6.16/00
   TCanvas *c1 = new TCanvas("c1", "c1",939,275,700,500);
   c1->Range(-3.4,-7.875001,12.6,70.875);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__3 = new TH1F("htemp__3","pulse_area_row3_pe/pulse_area_row4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-1.8,11);
   htemp__3->SetBinContent(8,1);
   htemp__3->SetBinContent(16,1);
   htemp__3->SetBinContent(17,3);
   htemp__3->SetBinContent(18,10);
   htemp__3->SetBinContent(19,25);
   htemp__3->SetBinContent(20,48);
   htemp__3->SetBinContent(21,60);
   htemp__3->SetBinContent(22,58);
   htemp__3->SetBinContent(23,36);
   htemp__3->SetBinContent(24,22);
   htemp__3->SetBinContent(25,20);
   htemp__3->SetBinContent(26,16);
   htemp__3->SetBinContent(27,14);
   htemp__3->SetBinContent(28,11);
   htemp__3->SetBinContent(29,3);
   htemp__3->SetBinContent(31,2);
   htemp__3->SetBinContent(32,3);
   htemp__3->SetBinContent(36,1);
   htemp__3->SetBinContent(72,1);
   htemp__3->SetBinContent(92,1);
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
   ptstats_LaTex = ptstats->AddText("Mean  =  1.043");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.7067");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__3->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__3);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__3->SetLineColor(ci);
   htemp__3->GetXaxis()->SetTitle("pulse_area_row3_pe/pulse_area_row4_pe");
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
   
   TPaveText *pt = new TPaveText(0.15,0.9338535,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("pulse_area_row3_pe/pulse_area_row4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
