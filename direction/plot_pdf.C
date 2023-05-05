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

  ifstream in;
  in.open("pmtlocation_4ton_index_0.txt");
  int aa, ee;
  double pmtx[46], pmty[46], pmtz[46];
  double bb,cc,dd;
  while (!in.eof()){
    in>>aa>>bb>>cc>>dd>>ee;
    pmtx[aa] = bb;
    pmty[aa] = cc;
    pmtz[aa] = dd;
  }

  TH2F* h2d[10];
  TH2F* h2d2[10];
  for (int i=0;i<10;i++){
    h2d[i] = new TH2F("","",10,-600, 600,10,-600,600);
    h2d2[i] = new TH2F("","",10,-600, 600,10,-600,600);
  }
  TH2F* hh[10];
  TH2F* hh2[10];

  TFile f("pdf_oldwater.root");

  for (int ii=0;ii<8;ii++){
    hh[ii] = (TH2F*)f.Get(Form("output_dir_%d",ii));

    TH1D* h1 = hh[ii]->ProjectionX();

    for (int i=0;i<46;i++){
      int ibin = -1;
      int jbin = -1;
      for (ibin = 0; ibin < 9; ibin++){
        if (pmtx[i]>= -600 + (600+600)/10.*ibin && pmtx[i]< -600 + (600+600)/10.*(ibin+1)){
	  break;
        }
      }
      for (jbin = 0; jbin < 9; jbin++){
        if (pmty[i]>= -600 + (600+600)/10.*jbin && pmty[i]< -600 + (600+600)/10.*(jbin+1)){
          break;
        }
      }
      cout<<"pmt id "<<i<<" pmt location x and y "<<pmtx[i]<<" "<<pmty[i]<<" bin location x and y "<<ibin<<" "<<jbin<<endl;
      h2d[ii] -> SetBinContent(ibin+1, jbin+1 , h1->GetBinContent(i+1));
    }
  }

  TCanvas* c1 = new TCanvas();
  c1->Divide(3,3);
  for (int i=0;i<8;i++){
    c1->cd(i+1);
    h2d[i]->SetTitle(Form("Step %d along X; Bottom X (mm); Bottom Y (mm)",i));
    h2d[i]->Draw("colz");
  }


  for (int ii=0;ii<8;ii++){
    hh2[ii] = (TH2F*)f.Get(Form("output_dir_%d",380+ii));

    TH1D* h2 = hh2[ii]->ProjectionX();

    for (int i=0;i<46;i++){
      int ibin = -1;
      int jbin = -1;
      for (ibin = 0; ibin < 9; ibin++){
        if (pmtx[i]>= -600 + (600+600)/10.*ibin && pmtx[i]< -600 + (600+600)/10.*(ibin+1)){
          break;
        }
      }
      for (jbin = 0; jbin < 9; jbin++){
        if (pmty[i]>= -600 + (600+600)/10.*jbin && pmty[i]< -600 + (600+600)/10.*(jbin+1)){
          break;
        }
      }
      cout<<"pmt id "<<i<<" pmt location x and y "<<pmtx[i]<<" "<<pmty[i]<<" bin location x and y "<<ibin<<" "<<jbin<<endl;
      h2d2[ii] -> SetBinContent(ibin+1, jbin+1 , h2->GetBinContent(i+1));
    }
    if (ii == 7){
      new TCanvas();
      h2->Scale(1./h2->Integral());
      h2->SetTitle("Example PDF for tilting angle 16 deg. along Y; PMT ID; Density ");
      h2->Draw();
    }
  }

  TCanvas* c2 = new TCanvas();
  c2->Divide(3,3);
  for (int i=0;i<8;i++){
    c2->cd(i+1);
    h2d2[i]->SetTitle(Form("Step %d along X; Bottom X (mm); Bottom Y (mm)",i));
    h2d2[i]->Draw("colz");
  }




}
