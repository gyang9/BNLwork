{

      
  double ratio_col14[25]={};
  double ratio_col14c[25]={};
  double ratio_col23[25]={};
  double ratio_col23c[25]={};

  double ratio_colb[25] = {};
  double ratio_colbc[25] = {};
  double ratio_row34[25] = {};
  double ratio_row34c[25] = {};

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

  for (int i=0;i<25;i++){
    TFile f(Form("bnl1t_1pct_x_0_y_%d_muon_oldwater.root",i));
    TTree* tree = (TTree*) f.Get("tree");

    int allhit_id[3000];
    double allhit_x[3000];
    double allhit_y[3000];
    double allhit_z[3000];
    double allhit_t[3000];

    int firsthit_id[3000];
    double firsthit_x[3000];
    double firsthit_y[3000];
    double firsthit_z[3000];
    double firsthit_t[3000];

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

    tree->SetBranchAddress("firsthit_id",&firsthit_id);
    tree->SetBranchAddress("firsthit_x",&firsthit_x);
    tree->SetBranchAddress("firsthit_y",&firsthit_y);
    tree->SetBranchAddress("firsthit_z",&firsthit_z);
    tree->SetBranchAddress("firsthit_t",&firsthit_t);

    for (int j=0;j<tree->GetEntries();j++){
      tree->GetEntry(j);
      ratio_col14[i] = col1sum/col4sum;
      ratio_col14c[i] = col1sumc/col4sumc;
      ratio_col23[i] = col2sum/col3sum;
      ratio_col23c[i] = col2sumc/col3sumc;      
      ratio_colb[i] = (col1sum+col2sum+col3sum+col4sum)/botsum;
      ratio_colbc[i] = (col1sumc+col2sumc+col3sumc+col4sumc)/botsumc;
      ratio_row34[i] = (row1sum+row2sum)/(row3sum+row4sum);
      ratio_row34c[i] = (row1sumc+row2sumc)/(row3sumc+row4sumc);
      cout<<"total col and row sums: "<<col1sum+col2sum+col3sum+col4sum<<" "<<row1sum+row2sum+row3sum+row4sum<<endl;
    }
   
  }

  double xx[25]={};
  for (int i=0;i<25;i++){
    xx[i] = TMath::ATan(i/100.)*57;
  }

  auto g1 = new TGraphErrors(25, xx, ratio_col14, 0 ,0);
  auto g2 = new TGraphErrors(25, xx, ratio_col14c, 0 ,0);

  new TCanvas();
  g1->SetLineColor(1);
  g2->SetLineColor(4);
  g1->SetLineWidth(3);
  g2->SetLineWidth(3);  
  g2->SetTitle(";Tilting angle (deg.); col1/col4");
  g2->Draw("AL");
  g1->Draw("same");

  auto gg1 = new TGraphErrors(25, xx, ratio_col23, 0 ,0);
  auto gg2 = new TGraphErrors(25, xx, ratio_col23c, 0 ,0);

  new TCanvas();
  gg1->SetLineColor(1);
  gg2->SetLineColor(4);
  gg1->SetLineWidth(3);
  gg2->SetLineWidth(3);
  gg2->SetTitle(";Tilting angle (deg.); col2/col3");
  gg2->Draw("AL");
  gg1->Draw("same");

  auto g3 = new TGraphErrors(25, xx, ratio_colb, 0 ,0);
  auto g4 = new TGraphErrors(25, xx, ratio_colbc, 0 ,0);
  auto g5 = new TGraphErrors(25, xx, ratio_row34, 0 ,0);
  auto g6 = new TGraphErrors(25, xx, ratio_row34c, 0 ,0);

  new TCanvas();
  g3->SetLineColor(1);
  g4->SetLineColor(4);
  g3->SetLineWidth(3);
  g4->SetLineWidth(3);
  g3->SetTitle(";Tilting angle (deg.); col_all/bot_all");
  g3->Draw("AL");
  g4->Draw("same");

  new TCanvas();
  g5->SetLineColor(1);
  g6->SetLineColor(4);
  g5->SetLineWidth(3);
  g6->SetLineWidth(3);
  g5->SetTitle(";Tilting angle (deg.); row1+2/row3+4");
  g5->Draw("AL");
  g6->Draw("same");



}
