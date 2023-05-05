{
  TFile f(Form("%s",gApplication->Argv(4)));
  //TFile f("bnl1t_file_1000mev_plus10deg.root");
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

  tree->SetBranchAddress("col1sum",&col1sum);
  tree->SetBranchAddress("col2sum",&col2sum);
  tree->SetBranchAddress("col3sum",&col3sum);
  tree->SetBranchAddress("col4sum",&col4sum);
  tree->SetBranchAddress("botsum",&botsum);

  tree->SetBranchAddress("row1sum",&row1sum);
  tree->SetBranchAddress("row2sum",&row2sum);
  tree->SetBranchAddress("row3sum",&row3sum);
  tree->SetBranchAddress("row4sum",&row4sum);

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

  TFile ff(Form("%s",gApplication->Argv(5)));
  //TFile f("bnl1t_file_1000mev_plus10deg.root");
  TTree* treee = (TTree*) ff.Get("tree");

  treee->SetBranchAddress("col1sum",&col1sum);
  treee->SetBranchAddress("col2sum",&col2sum);
  treee->SetBranchAddress("col3sum",&col3sum);
  treee->SetBranchAddress("col4sum",&col4sum);
  treee->SetBranchAddress("botsum",&botsum);

  treee->SetBranchAddress("row1sum",&row1sum);
  treee->SetBranchAddress("row2sum",&row2sum);
  treee->SetBranchAddress("row3sum",&row3sum);
  treee->SetBranchAddress("row4sum",&row4sum);

  treee->SetBranchAddress("allhit_id",&allhit_id);
  treee->SetBranchAddress("allhit_x",&allhit_x);
  treee->SetBranchAddress("allhit_y",&allhit_y);
  treee->SetBranchAddress("allhit_z",&allhit_z);
  treee->SetBranchAddress("allhit_t",&allhit_t);

  treee->SetBranchAddress("firsthit_id",&firsthit_id);
  treee->SetBranchAddress("firsthit_x",&firsthit_x);
  treee->SetBranchAddress("firsthit_y",&firsthit_y);
  treee->SetBranchAddress("firsthit_z",&firsthit_z);
  treee->SetBranchAddress("firsthit_t",&firsthit_t);

  TH3F* h3[10];
  for (int i=0;i<10;i++){
    h3[i] = new TH3F("","",100,-600,600,100,-600,600,100,-800,800);
  }

  TH2F* h2[10];
  TH1F* hid[10];
  for (int i=0;i<10;i++){
    h2[i] = new TH2F("","",100,-600,600,100,-600,600);
    hid[i] = new TH1F("","id; PMT id; Counts",47,0,47);
  }

  for (int i=0; i< tree->GetEntries(); i++){
    tree->GetEntry(i);
    for (int j=0;j<3000;j++){
      if (allhit_x[j] == 0 && allhit_z[j] == 0) break;
      h3[0]->Fill(allhit_x[j], allhit_y[j], allhit_z[j]);
      h2[0]->Fill(allhit_x[j], allhit_y[j]);
      if (allhit_id[j] != 0 )
        hid[0]->Fill(allhit_id[j]);
    }
    for (int j=0;j<3000;j++){
      if (firsthit_x[j] == 0 && firsthit_z[j] == 0) break;
      	h3[1]->Fill(firsthit_x[j], firsthit_y[j], firsthit_z[j]);
	h2[1]->Fill(firsthit_x[j], firsthit_y[j]);
	if (firsthit_id[j] != 0)
	  hid[1]->Fill(firsthit_id[j]);
    }
  }

  for (int i=0; i< treee->GetEntries(); i++){
    treee->GetEntry(i);
    for (int j=0;j<3000;j++){ 
      if (allhit_x[j] == 0 && allhit_z[j] == 0) break;
      h3[2]->Fill(allhit_x[j], allhit_y[j], allhit_z[j]);
      h2[2]->Fill(allhit_x[j], allhit_y[j]);
      if (allhit_id[j] != 0)
        hid[2]->Fill(allhit_id[j]);
    }
    for (int j=0;j<3000;j++){
      if (firsthit_x[j] == 0 && firsthit_z[j] == 0) break;
        h3[3]->Fill(firsthit_x[j], firsthit_y[j], firsthit_z[j]);
        h2[3]->Fill(firsthit_x[j], firsthit_y[j]);
        if (firsthit_id[j] != 0)
          hid[3]->Fill(firsthit_id[j]);
    }
  }  
  
  TCanvas* c1 = new TCanvas();
  c1->Divide(1,2);
  c1->cd(1);
  h3[0]->Draw("colz");
  c1->cd(2);
  h3[2]->Draw("colz");

  TCanvas* c2 = new TCanvas();
  c2->Divide(1,2);
  c2->cd(1);
  h3[1]->Draw("colz");
  c2->cd(2);
  h3[3]->Draw("colz");

  TCanvas* c3 = new TCanvas();
  c3->Divide(1,2);
  c3->cd(1);
  h2[0]->Draw("colz");
  c3->cd(2);
  h2[2]->Draw("colz");

  TCanvas* c4 = new TCanvas();
  c4->Divide(1,2);
  c4->cd(1);
  h2[1]->Draw("colz");
  c4->cd(2);
  h2[3]->Draw("colz");

  TCanvas* c5 = new TCanvas();
  c5->Divide(1,2);
  c5->cd(1);
  hid[0]->Draw();
  c5->cd(2);
  hid[2]->Draw();

  TCanvas* c6 = new TCanvas();
  c6->Divide(1,2);
  c6->cd(1);
  hid[1]->Draw();
  c6->cd(2);
  hid[3]->Draw();

}
