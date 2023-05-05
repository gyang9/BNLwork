void data_bottom_water()
{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Oct 17 20:23:26 2022) by ROOT version 6.16/00
   TCanvas *c1 = new TCanvas("c1", "c1",67,57,1844,1317);
   c1->Range(-162.5,-6.956251,1462.5,62.60625);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__1 = new TH1F("htemp__1","pulse_area_bot_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,0,1300);
   htemp__1->SetBinContent(5,1);
   htemp__1->SetBinContent(7,1);
   htemp__1->SetBinContent(8,1);
   htemp__1->SetBinContent(14,1);
   htemp__1->SetBinContent(15,1);
   htemp__1->SetBinContent(16,2);
   htemp__1->SetBinContent(17,1);
   htemp__1->SetBinContent(18,7);
   htemp__1->SetBinContent(19,11);
   htemp__1->SetBinContent(20,21);
   htemp__1->SetBinContent(21,37);
   htemp__1->SetBinContent(22,33);
   htemp__1->SetBinContent(23,53);
   htemp__1->SetBinContent(24,43);
   htemp__1->SetBinContent(25,37);
   htemp__1->SetBinContent(26,18);
   htemp__1->SetBinContent(27,15);
   htemp__1->SetBinContent(28,12);
   htemp__1->SetBinContent(29,6);
   htemp__1->SetBinContent(30,10);
   htemp__1->SetBinContent(31,3);
   htemp__1->SetBinContent(32,5);
   htemp__1->SetBinContent(33,3);
   htemp__1->SetBinContent(35,1);
   htemp__1->SetBinContent(36,1);
   htemp__1->SetBinContent(37,4);
   htemp__1->SetBinContent(44,1);
   htemp__1->SetBinContent(46,2);
   htemp__1->SetBinContent(49,1);
   htemp__1->SetBinContent(50,1);
   htemp__1->SetBinContent(75,1);
   htemp__1->SetBinContent(84,1);
   htemp__1->SetBinContent(92,1);
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
   ptstats_LaTex = ptstats->AddText("Mean  =  313.3");
   ptstats_LaTex = ptstats->AddText("Std Dev   =   96.6");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__1->SetLineColor(ci);
   htemp__1->GetXaxis()->SetTitle("pulse_area_bot_pe");
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
   TText *pt_LaTex = pt->AddText("pulse_area_bot_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
