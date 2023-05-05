void row1()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Oct 25 19:56:06 2022) by ROOT version 6.16/00
   TCanvas *c1 = new TCanvas("c1", "c1",67,57,700,500);
   c1->Range(-25.25,-6.956251,127.25,62.60625);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__1 = new TH1F("htemp__1","pulse_area_row1_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-10,112);
   htemp__1->SetBinContent(9,9);
   htemp__1->SetBinContent(10,25);
   htemp__1->SetBinContent(11,39);
   htemp__1->SetBinContent(12,47);
   htemp__1->SetBinContent(13,51);
   htemp__1->SetBinContent(14,53);
   htemp__1->SetBinContent(15,41);
   htemp__1->SetBinContent(16,18);
   htemp__1->SetBinContent(17,19);
   htemp__1->SetBinContent(18,9);
   htemp__1->SetBinContent(19,9);
   htemp__1->SetBinContent(20,2);
   htemp__1->SetBinContent(21,2);
   htemp__1->SetBinContent(22,3);
   htemp__1->SetBinContent(23,1);
   htemp__1->SetBinContent(24,1);
   htemp__1->SetBinContent(27,1);
   htemp__1->SetBinContent(30,1);
   htemp__1->SetBinContent(31,1);
   htemp__1->SetBinContent(32,2);
   htemp__1->SetBinContent(34,1);
   htemp__1->SetBinContent(93,1);
   htemp__1->SetEntries(336);
   htemp__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("htemp");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 336    ");
   ptstats_LaTex = ptstats->AddText("Mean  =  6.689");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  6.778");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__1->SetLineColor(ci);
   htemp__1->GetXaxis()->SetTitle("pulse_area_row1_pe");
   htemp__1->GetXaxis()->SetRange(1,100);
   htemp__1->GetXaxis()->SetLabelFont(42);
   htemp__1->GetXaxis()->SetLabelSize(0.035);
   htemp__1->GetXaxis()->SetTitleSize(0.035);
   htemp__1->GetXaxis()->SetTitleOffset(1);
   htemp__1->GetXaxis()->SetTitleFont(42);
   htemp__1->GetYaxis()->SetLabelFont(42);
   htemp__1->GetYaxis()->SetLabelSize(0.035);
   htemp__1->GetYaxis()->SetTitleSize(0.035);
   htemp__1->GetYaxis()->SetTitleFont(42);
   htemp__1->GetZaxis()->SetLabelFont(42);
   htemp__1->GetZaxis()->SetLabelSize(0.035);
   htemp__1->GetZaxis()->SetTitleSize(0.035);
   htemp__1->GetZaxis()->SetTitleOffset(1);
   htemp__1->GetZaxis()->SetTitleFont(42);
   htemp__1->Draw("");
   
   TPaveText *pt = new TPaveText(0.15,0.9338535,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("pulse_area_row1_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
