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
  gStyle->SetOptStat(1111);
  //gStyle->SetOptStat(000000);

  double ratio_col14[25]={};
  double ratio_col14c[25]={};

  double ratio_colb[25] = {};
  double ratio_colbc[25] = {};
  double ratio_row34[25] = {};
  double ratio_row34c[25] = {};

  auto h_time_bot = new TH1F("","bot. time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_time_side = new TH1F("","side time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_time_spec1 = new TH1F("","spec1 time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_time_spec2 = new TH1F("","spec2 time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_time_spec3 = new TH1F("","spec3 time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_time_spec4 = new TH1F("","spec4 time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_side_bot = new TH1F("","side_bot; time [ns]; Counts (A.U.)", 30 , -20,40);
  auto h_diff1 = new TH1F("","diff1; time [ns]; Counts (A.U.)", 30 , -20,40);
  auto h_diff2 = new TH1F("","diff2; time [ns]; Counts (A.U.)", 30 , -20,40);

  auto h_ftime_bot = new TH1F("","fbot. time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_ftime_side = new TH1F("","fside time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_ftime_spec1 = new TH1F("","fspec1 time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_ftime_spec2 = new TH1F("","fspec2 time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_ftime_spec3 = new TH1F("","fspec3 time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_ftime_spec4 = new TH1F("","fspec4 time; time [ns]; Counts (A.U.)",30,-20,40);
  auto h_fside_bot = new TH1F("","fside_bot; time [ns]; Counts (A.U.)", 30 , -20,40);
  auto h_fdiff1 = new TH1F("","fdiff1; time [ns]; Counts (A.U.)", 30 , -20,40);
  auto h_fdiff2 = new TH1F("","fdiff2; time [ns]; Counts (A.U.)", 30 , -20,40);


  //particle starting location from the chimney: 106,106,647mm
  //liquid level z 641.35 mm
  double origx = 106;
  double origy = 106;
  double origz = 641.35;
  //double origx = 0;
  //double origy = 0;
  //double origz = 0;


  for (int i=1;i<19;i++){
    TFile f(Form("bnl1t_1pct_x_0_y_%d_1gev_new3.root",i));
    //TFile f("bnl1t_1pct_x_0_y_0_2mevElec_new3.root");
    TTree* tree = (TTree*) f.Get("tree");

    double angle1 = TMath::ATan((double)(i-1)/100.);
    double angle2 = TMath::ATan((double)i/100.);
    double areaC = TMath::Pi()*TMath::Power(1.*TMath::Tan(angle2),2) - TMath::Pi()*TMath::Power(1.*TMath::Tan(angle1),2) ;
    //areaC = 1;
    cout<<"for "<<i<<" event number "<<tree->GetEntries()<<endl;
    int allhit_id[3000];
    double allhit_x[3000];
    double allhit_y[3000];
    double allhit_z[3000];
    double allhit_t[3000];
    double allhit_ft[3000];

    int firsthit_id[3000];
    double firsthit_x[3000];
    double firsthit_y[3000];
    double firsthit_z[3000];
    double firsthit_t[3000];
    double firsthit_ft[3000];

    float col1sum;
    float col2sum;
    float col3sum;
    float col4sum;
    float botsum;
    float row1sum;
    float row2sum;
    float row3sum;
    float row4sum;
    float col1sumc;
    float col2sumc;
    float col3sumc;
    float col4sumc;
    float botsumc;
    float row1sumc;
    float row2sumc;
    float row3sumc;
    float row4sumc;

    tree->SetBranchAddress("col1sum",&col1sum);
    tree->SetBranchAddress("col2sum",&col2sum);
    tree->SetBranchAddress("col3sum",&col3sum);
    tree->SetBranchAddress("col4sum",&col4sum);
    tree->SetBranchAddress("botsum",&botsum);

    tree->SetBranchAddress("row1sum",&row1sum);
    tree->SetBranchAddress("row2sum",&row2sum);
    tree->SetBranchAddress("row3sum",&row3sum);
    tree->SetBranchAddress("row4sum",&row4sum);

    tree->SetBranchAddress("col1sumc",&col1sumc);
    tree->SetBranchAddress("col2sumc",&col2sumc);
    tree->SetBranchAddress("col3sumc",&col3sumc);
    tree->SetBranchAddress("col4sumc",&col4sumc);
    tree->SetBranchAddress("botsumc",&botsumc);

    tree->SetBranchAddress("row1sumc",&row1sumc);
    tree->SetBranchAddress("row2sumc",&row2sumc);
    tree->SetBranchAddress("row3sumc",&row3sumc);
    tree->SetBranchAddress("row4sumc",&row4sumc);

    tree->SetBranchAddress("allhit_id",&allhit_id);
    tree->SetBranchAddress("allhit_x",&allhit_x);
    tree->SetBranchAddress("allhit_y",&allhit_y);
    tree->SetBranchAddress("allhit_z",&allhit_z);
    tree->SetBranchAddress("allhit_t",&allhit_t);
    tree->SetBranchAddress("allhit_ft",&allhit_ft);

    tree->SetBranchAddress("firsthit_id",&firsthit_id);
    tree->SetBranchAddress("firsthit_x",&firsthit_x);
    tree->SetBranchAddress("firsthit_y",&firsthit_y);
    tree->SetBranchAddress("firsthit_z",&firsthit_z);
    tree->SetBranchAddress("firsthit_t",&firsthit_t);
    tree->SetBranchAddress("firsthit_ft",&firsthit_ft); 

    for (int j=0;j<tree->GetEntries();j++){
      tree->GetEntry(j);
      ratio_col14[i] = col1sum/col4sum;
      ratio_col14c[i] = col1sumc/col4sumc;
      ratio_colb[i] = (col1sum+col2sum+col3sum+col4sum)/botsum;
      ratio_colbc[i] = (col1sumc+col2sumc+col3sumc+col4sumc)/botsumc;
      ratio_row34[i] = (row1sum+row2sum)/(row3sum+row4sum);
      ratio_row34c[i] = (row1sumc+row2sumc)/(row3sumc+row4sumc);
      cout<<"total col and row sums: "<<col1sum+col2sum+col3sum+col4sum<<" "<<row1sum+row2sum+row3sum+row4sum<<endl;
      double curr_side = 1e9;
      double curr_bot = 1e9;
      double time_spec1 = -1;
      double time_spec2 = -1;
      double time_spec3 = -1;
      double time_spec4 = -1;
      double fcurr_side = 1e9;
      double fcurr_bot = 1e9;
      double ftime_spec1 = -1;
      double ftime_spec2 = -1;
      double ftime_spec3 = -1;
      double ftime_spec4 = -1;
      
      for (int jj=0;jj<500;jj++){
	 if (firsthit_x[jj] == 0 && firsthit_y[jj] == 0) continue;

	 if (firsthit_id[jj] < 30) h_time_bot ->Fill(firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200., areaC);
	 else h_time_side ->Fill(firsthit_t[jj] -sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200., areaC);
	 if (firsthit_id[jj] == 0) { time_spec1 = firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.; h_time_spec1->Fill(firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.);}
	 if (firsthit_id[jj] == 10){ time_spec2 = firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;  h_time_spec2->Fill(firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.);}
	 if (firsthit_id[jj] == 20){ time_spec3 = firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;  h_time_spec3->Fill(firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.);}
	 if (firsthit_id[jj] == 40){ time_spec4 = firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;  h_time_spec4->Fill(firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.);}
         if ( firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200 < curr_side && firsthit_id[jj] < 30 ) curr_side = firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;
	 if ( firsthit_t[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200 < curr_bot &&firsthit_id[jj] >= 30) curr_bot = firsthit_t[jj] - sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;


         if (firsthit_id[jj] < 30) h_ftime_bot ->Fill(firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200., areaC);
         else h_ftime_side ->Fill(firsthit_ft[jj] -sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200., areaC);

	 if (firsthit_id[jj] == 0) { ftime_spec1 = firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.; h_ftime_spec1->Fill(firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.);}

	 if (firsthit_id[jj] == 10){ ftime_spec2 = firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;  h_ftime_spec2->Fill(firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.);}

	 if (firsthit_id[jj] == 20){ ftime_spec3 = firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;  h_ftime_spec3->Fill(firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.);}

	 if (firsthit_id[jj] == 40){ ftime_spec4 = firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;  h_ftime_spec4->Fill(firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.);}

	 if ( firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200 < fcurr_side && firsthit_id[jj] < 30 ) fcurr_side = firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;

	 if ( firsthit_ft[jj]-sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200 < fcurr_bot && firsthit_id[jj] >= 30) fcurr_bot = firsthit_ft[jj] - sqrt(TMath::Power(firsthit_x[jj]-origx,2) + TMath::Power(firsthit_y[jj]-origy,2)+TMath::Power(firsthit_z[jj]-origz,2))/200.;

/*
         if (firsthit_id[jj] < 30) h_time_bot ->Fill(firsthit_t[jj], areaC);
         else h_time_side ->Fill(firsthit_t[jj] , areaC);
         if (firsthit_id[jj] == 0) { time_spec1 = firsthit_t[jj]; h_time_spec1->Fill(firsthit_t[jj]);}
         if (firsthit_id[jj] == 10){ time_spec2 = firsthit_t[jj];  h_time_spec2->Fill(firsthit_t[jj]);}
         if (firsthit_id[jj] == 20){ time_spec3 = firsthit_t[jj];  h_time_spec3->Fill(firsthit_t[jj]);}
         if (firsthit_id[jj] == 40){ time_spec4 = firsthit_t[jj];  h_time_spec4->Fill(firsthit_t[jj]);}
         if ( firsthit_t[jj] < curr_side && firsthit_id[jj] < 30 ) curr_side = firsthit_t[jj];
         if ( firsthit_t[jj] < curr_bot &&firsthit_id[jj] >= 30) curr_bot = firsthit_t[jj] ;

         if (firsthit_id[jj] < 30) h_ftime_bot ->Fill(firsthit_ft[jj], areaC);
         else h_ftime_side ->Fill(firsthit_ft[jj] , areaC);
         if (firsthit_id[jj] == 0) { ftime_spec1 = firsthit_ft[jj]; h_ftime_spec1->Fill(firsthit_ft[jj]);}
         if (firsthit_id[jj] == 10){ ftime_spec2 = firsthit_ft[jj];  h_ftime_spec2->Fill(firsthit_ft[jj]);}
         if (firsthit_id[jj] == 20){ ftime_spec3 = firsthit_ft[jj];  h_ftime_spec3->Fill(firsthit_ft[jj]);}
         if (firsthit_id[jj] == 40){ ftime_spec4 = firsthit_ft[jj];  h_ftime_spec4->Fill(firsthit_ft[jj]);}
         if ( firsthit_ft[jj] < fcurr_side && firsthit_id[jj] < 30 ) fcurr_side = firsthit_ft[jj];
         if ( firsthit_ft[jj] < fcurr_bot &&firsthit_id[jj] >= 30) fcurr_bot = firsthit_ft[jj] ;
*/
      }
      cout<<"side and bottom time : "<<curr_side<<" "<<curr_bot<<endl;
      h_side_bot->Fill(curr_side - curr_bot, areaC);
      h_diff1 ->Fill(time_spec1-time_spec2, areaC);
      h_diff2 ->Fill(time_spec3-time_spec4, areaC);
      h_fside_bot->Fill(fcurr_side - fcurr_bot, areaC);
      h_fdiff1 ->Fill(ftime_spec1-ftime_spec2, areaC);
      h_fdiff2 ->Fill(ftime_spec3-ftime_spec4, areaC);
      
    }    
  }

  new TCanvas();
  h_time_bot->Draw("bar");
  h_time_bot->SetFillColor(kGreen);

  new TCanvas();
  h_time_side->Draw("bar");
  h_time_side->SetFillColor(kGreen);

  h_time_spec1->SetFillColor(kGreen);
  h_time_spec2->SetFillColor(kGreen);
  h_time_spec3->SetFillColor(kGreen);
  h_time_spec4->SetFillColor(kGreen);
  h_side_bot->SetFillColor(kGreen);  
  h_diff1->SetFillColor(kGreen);
  h_diff2->SetFillColor(kGreen);

  h_ftime_spec1->SetFillColor(kGreen);
  h_ftime_spec2->SetFillColor(kGreen);
  h_ftime_spec3->SetFillColor(kGreen);
  h_ftime_spec4->SetFillColor(kGreen);
  h_fside_bot->SetFillColor(kGreen);
  h_fdiff1->SetFillColor(kGreen);
  h_fdiff2->SetFillColor(kGreen);

  TCanvas* c1 = new TCanvas();
  c1->Divide(2,2);
  c1->cd(1);
  h_time_spec1->Draw("bar");
  c1->cd(2);
  h_time_spec2->Draw("bar");
  c1->cd(3);
  h_time_spec3->Draw("bar");
  c1->cd(4);
  h_time_spec4->Draw("bar");

  TCanvas* c2 = new TCanvas();
  c2->Divide(2,2);
  c2->cd(1);
  h_side_bot->Draw("bar");
  c2->cd(2);
  h_diff1->Draw("bar");
  c2->cd(3);
  h_diff2->Draw("bar");

  TCanvas* c3 = new TCanvas();
  c3->Divide(2,2);
  c3->cd(1);
  h_ftime_spec1->Draw("bar");
  c3->cd(2);
  h_ftime_spec2->Draw("bar");
  c3->cd(3);
  h_ftime_spec3->Draw("bar");
  c3->cd(4);
  h_ftime_spec4->Draw("bar");

  TCanvas* c4 = new TCanvas();
  c4->Divide(2,2);
  c4->cd(1);
  h_fside_bot->Draw("bar");
  c4->cd(2);
  h_fdiff1->Draw("bar");
  c4->cd(3);
  h_fdiff2->Draw("bar");




}
