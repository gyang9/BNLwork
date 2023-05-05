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

  TFile f(Form("%s",gApplication->Argv(4)));
  //TFile f("bnl1t_file_1000mev_plus10deg.root");
  TTree* tree = (TTree*) f.Get("tree");

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

  int nentries = tree->GetEntries();

  TChain f2("event");
  f2.Add("phase0_muon_water_rq.root");
  //TFile f2("phase0_muon_water_220917T0835_rq.root");
  //TTree* tree2 = (TTree*) f2.Get("event");

/*
-rw-r--r-- 1 guang guang  23769746 Sep 26 23:10 phase0_muon_water_220916T0109_rq.root
-rw-r--r-- 1 guang guang   1733122 Sep 26 23:11 phase0_muon_water_220916T0908_rq.root
-rw-r--r-- 1 guang guang  17183488 Sep 26 23:15 phase0_muon_water_220916T1826_rq.root
-rw-r--r-- 1 guang guang  24280470 Sep 26 23:22 phase0_muon_water_220917T0020_rq.root
-rw-r--r-- 1 guang guang  15872815 Sep 26 23:27 phase0_muon_water_220917T0835_rq.root
-rw-r--r-- 1 guang guang  12489777 Sep 26 23:31 phase0_muon_water_220918T0002_rq.root
-rw-r--r-- 1 guang guang  18148046 Sep 26 23:36 phase0_muon_water_220918T0854_rq.root
-rw-r--r-- 1 guang guang  33516985 Sep 26 23:58 phase0_muon_water_220915T0955_rq.root
-rw-r--r-- 1 guang guang  11892334 Sep 27 00:01 phase0_muon_water_220915T2110_rq.root
*/

  //assert(CHAR_BIT * sizeof (float) == 32);

  long int pulse_area_col1_pe;
  long int pulse_area_col2_pe;
  long int pulse_area_col3_pe;
  long int pulse_area_col4_pe;
  long int pulse_area_bot_pe;
  long int pulse_area_max_frac;
  long int event_sanity;
  long int pulse_id;
  long int event_saturated;
  long int pulse_ptime_ns;
  long int npulse;

  f2.SetBranchAddress("pulse_area_max_frac", &pulse_area_max_frac);
  f2.SetBranchAddress("event_sanity",&event_sanity );
  f2.SetBranchAddress("event_saturated",&event_saturated );
  f2.SetBranchAddress("pulse_id",&pulse_id );
  f2.SetBranchAddress("pulse_ptime_ns",&pulse_ptime_ns );
  f2.SetBranchAddress("npulse",&npulse);
  f2.SetBranchAddress("pulse_area_col1_pe",&pulse_area_col1_pe);
  f2.SetBranchAddress("pulse_area_col2_pe",&pulse_area_col2_pe);
  f2.SetBranchAddress("pulse_area_col3_pe",&pulse_area_col3_pe);
  f2.SetBranchAddress("pulse_area_col4_pe",&pulse_area_col4_pe);
  f2.SetBranchAddress("pulse_area_bot_pe",&pulse_area_bot_pe);  

  TH1F* h1[10];
  TH1F* h2[10];
  TH1F* hh1[10];
  TH1F* hh2[10];
  TH1F* h3[10];
  TH1F* hh3[10];
  TH1F* h4[10];
  TH1F* h5[10];
  for (int i=0;i<10;i++){
    if (i != 4){
      h1[i] = new TH1F("","data",100,0,100);
      h2[i] = new TH1F("","simulation",100,0,100);
      h3[i] = new TH1F("","simulation tilted",100,0,100);
    }
    else{
      h1[i] = new TH1F("","data",100,0,1000);
      h2[i] = new TH1F("","simulation",100,0,1000);
      h3[i] = new TH1F("","simulation tilted",100,0,1000);
    }
    hh1[i] = new TH1F("","data ratio",30,0,0.3);
    hh2[i] = new TH1F("","simulation ratio",30,0,0.3);
    hh3[i] = new TH1F("","simulation tilted",30,0,0.3);
    h4[i] = new TH1F("","simulation",20,0,2);
    h5[i] = new TH1F("","simulation",20,0,2);
  }

  for (int i=0;i<nentries; i++){
    tree->GetEntry(i);
    cout<<"tree1 "<<i<<" "<<col1sum<<endl;
    h2[0]->Fill(col1sum);    
    h2[1]->Fill(col2sum);
    h2[2]->Fill(col3sum);
    h2[3]->Fill(col4sum);
    h2[4]->Fill(botsum);
  
    h2[5]->Fill(row1sum);
    h2[6]->Fill(row2sum);
    h2[7]->Fill(row3sum);
    h2[8]->Fill(row4sum);

    h4[0]->Fill(row1sum/row4sum);
    h4[1]->Fill(row2sum/row4sum);
    h4[2]->Fill(row3sum/row4sum);
    h4[3]->Fill((row1sum+row2sum)/(row3sum+row4sum));

    hh2[0]->Fill(col1sum/botsum);
    hh2[1]->Fill(col2sum/botsum);
    hh2[2]->Fill(col3sum/botsum);
    hh2[3]->Fill(col4sum/botsum);
  }

  for (int i=0;i<treee->GetEntries(); i++){
    treee->GetEntry(i);
    h3[0]->Fill(col1sum);    
    h3[1]->Fill(col2sum);
    h3[2]->Fill(col3sum);
    h3[3]->Fill(col4sum);
    h3[4]->Fill(botsum);
  
    h3[5]->Fill(row1sum);
    h3[6]->Fill(row2sum);
    h3[7]->Fill(row3sum);
    h3[8]->Fill(row4sum);

    h5[0]->Fill(row1sum/row4sum);
    h5[1]->Fill(row2sum/row4sum);
    h5[2]->Fill(row3sum/row4sum);
    h5[3]->Fill((row1sum+row2sum)/(row3sum+row4sum));

    hh3[0]->Fill(col1sum/botsum);
    hh3[1]->Fill(col2sum/botsum);
    hh3[2]->Fill(col3sum/botsum);
    hh3[3]->Fill(col4sum/botsum);
  }

  int nentries2 = f2.GetEntries();
  for (int i=0;i<0;i++){
    if (i == 363 || i == 477 || i == 1336 || i == 1337 || i == 1338 || i == 1420 || i == 1419 || i == 1418) continue;
    f2.GetEntry(i);
    if (pulse_area_max_frac> 0.18 || pulse_ptime_ns > 395 || pulse_ptime_ns< 365 || event_sanity != 0 || event_saturated != 0 || pulse_id != 0 || npulse <=0) continue;
    cout<<"tree2 "<<i<<" "<<pulse_area_col1_pe<<endl;
    h1[0]->Fill(pulse_area_col1_pe);
    h1[1]->Fill(pulse_area_col2_pe);
    h1[2]->Fill(pulse_area_col3_pe);
    h1[3]->Fill(pulse_area_col4_pe);
    h1[4]->Fill(pulse_area_bot_pe);

    hh1[0]->Fill(pulse_area_col1_pe/pulse_area_bot_pe);
    hh1[1]->Fill(pulse_area_col2_pe/pulse_area_bot_pe);
    hh1[2]->Fill(pulse_area_col3_pe/pulse_area_bot_pe);
    hh1[3]->Fill(pulse_area_col4_pe/pulse_area_bot_pe);    
  }

  //bottom data
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


  //col1 data
   TH1F *htemp__2 = new TH1F("htemp__2","pulse_area_col1_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-12,150);
   htemp__2->SetBinContent(8,1);
   htemp__2->SetBinContent(10,1);
   htemp__2->SetBinContent(11,3);
   htemp__2->SetBinContent(12,8);
   htemp__2->SetBinContent(13,7);
   htemp__2->SetBinContent(14,8);
   htemp__2->SetBinContent(15,19);
   htemp__2->SetBinContent(16,19);
   htemp__2->SetBinContent(17,21);
   htemp__2->SetBinContent(18,37);
   htemp__2->SetBinContent(19,41);
   htemp__2->SetBinContent(20,35);
   htemp__2->SetBinContent(21,28);
   htemp__2->SetBinContent(22,25);
   htemp__2->SetBinContent(23,15);
   htemp__2->SetBinContent(24,20);
   htemp__2->SetBinContent(25,10);
   htemp__2->SetBinContent(26,14);
   htemp__2->SetBinContent(27,2);
   htemp__2->SetBinContent(28,3);
   htemp__2->SetBinContent(29,1);
   htemp__2->SetBinContent(30,5);
   htemp__2->SetBinContent(31,3);
   htemp__2->SetBinContent(34,1);
   htemp__2->SetBinContent(36,1);
   htemp__2->SetBinContent(38,1);
   htemp__2->SetBinContent(39,1);
   htemp__2->SetBinContent(42,2);
   htemp__2->SetBinContent(46,1);
   htemp__2->SetBinContent(56,1);
   htemp__2->SetBinContent(86,1);
   htemp__2->SetBinContent(92,1);
   htemp__2->SetEntries(336);
   htemp__2->SetDirectory(0);

   // col2 data
   TH1F *htemp__3 = new TH1F("htemp__3","pulse_area_col2_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-14,162);
   htemp__3->SetBinContent(8,2);
   htemp__3->SetBinContent(9,1);
   htemp__3->SetBinContent(10,4);
   htemp__3->SetBinContent(11,22);
   htemp__3->SetBinContent(12,36);
   htemp__3->SetBinContent(13,57);
   htemp__3->SetBinContent(14,60);
   htemp__3->SetBinContent(15,38);
   htemp__3->SetBinContent(16,41);
   htemp__3->SetBinContent(17,20);
   htemp__3->SetBinContent(18,16);
   htemp__3->SetBinContent(19,9);
   htemp__3->SetBinContent(20,8);
   htemp__3->SetBinContent(21,7);
   htemp__3->SetBinContent(22,1);
   htemp__3->SetBinContent(23,4);
   htemp__3->SetBinContent(24,2);
   htemp__3->SetBinContent(25,2);
   htemp__3->SetBinContent(31,1);
   htemp__3->SetBinContent(33,1);
   htemp__3->SetBinContent(34,1);
   htemp__3->SetBinContent(36,1);
   htemp__3->SetBinContent(40,1);
   htemp__3->SetBinContent(93,1);
   htemp__3->SetEntries(336);
   htemp__3->SetDirectory(0);

   //col3 data
   TH1F *htemp__4 = new TH1F("htemp__4","pulse_area_col3_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,0,124);
   htemp__4->SetBinContent(1,1);
   htemp__4->SetBinContent(2,3);
   htemp__4->SetBinContent(4,1);
   htemp__4->SetBinContent(5,4);
   htemp__4->SetBinContent(6,6);
   htemp__4->SetBinContent(7,6);
   htemp__4->SetBinContent(8,7);
   htemp__4->SetBinContent(9,15);
   htemp__4->SetBinContent(10,17);
   htemp__4->SetBinContent(11,11);
   htemp__4->SetBinContent(12,24);
   htemp__4->SetBinContent(13,21);
   htemp__4->SetBinContent(14,27);
   htemp__4->SetBinContent(15,23);
   htemp__4->SetBinContent(16,13);
   htemp__4->SetBinContent(17,22);
   htemp__4->SetBinContent(18,17);
   htemp__4->SetBinContent(19,10);
   htemp__4->SetBinContent(20,15);
   htemp__4->SetBinContent(21,15);
   htemp__4->SetBinContent(22,12);
   htemp__4->SetBinContent(23,10);
   htemp__4->SetBinContent(24,6);
   htemp__4->SetBinContent(25,9);
   htemp__4->SetBinContent(26,3);
   htemp__4->SetBinContent(27,6);
   htemp__4->SetBinContent(28,3);
   htemp__4->SetBinContent(29,4);
   htemp__4->SetBinContent(30,3);
   htemp__4->SetBinContent(31,4);
   htemp__4->SetBinContent(32,1);
   htemp__4->SetBinContent(33,1);
   htemp__4->SetBinContent(35,1);
   htemp__4->SetBinContent(36,1);
   htemp__4->SetBinContent(37,4);
   htemp__4->SetBinContent(38,2);
   htemp__4->SetBinContent(39,1);
   htemp__4->SetBinContent(41,2);
   htemp__4->SetBinContent(47,2);
   htemp__4->SetBinContent(48,1);
   htemp__4->SetBinContent(70,1);
   htemp__4->SetBinContent(92,1);
   htemp__4->SetEntries(336);
   htemp__4->SetDirectory(0);   
   
   //col4 data
   TH1F *htemp__5 = new TH1F("htemp__5","pulse_area_col4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-12,142);
   htemp__5->SetBinContent(8,3);
   htemp__5->SetBinContent(9,9);
   htemp__5->SetBinContent(10,25);
   htemp__5->SetBinContent(11,53);
   htemp__5->SetBinContent(12,52);
   htemp__5->SetBinContent(13,52);
   htemp__5->SetBinContent(14,38);
   htemp__5->SetBinContent(15,30);
   htemp__5->SetBinContent(16,23);
   htemp__5->SetBinContent(17,16);
   htemp__5->SetBinContent(18,5);
   htemp__5->SetBinContent(19,7);
   htemp__5->SetBinContent(20,2);
   htemp__5->SetBinContent(21,2);
   htemp__5->SetBinContent(22,1);
   htemp__5->SetBinContent(23,2);
   htemp__5->SetBinContent(24,2);
   htemp__5->SetBinContent(25,2);
   htemp__5->SetBinContent(26,1);
   htemp__5->SetBinContent(27,2);
   htemp__5->SetBinContent(28,3);
   htemp__5->SetBinContent(31,2);
   htemp__5->SetBinContent(38,1);
   htemp__5->SetBinContent(48,1);
   htemp__5->SetBinContent(65,1);
   htemp__5->SetBinContent(93,1);
   htemp__5->SetEntries(336);
   htemp__5->SetDirectory(0);

   TH1F *htemp__10 = new TH1F("htemp_10","pulse_area_col1_pe/pulse_area_bot_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-0.015,0.21);
   htemp__10->SetBinContent(7,1);
   htemp__10->SetBinContent(15,1);
   htemp__10->SetBinContent(16,4);
   htemp__10->SetBinContent(17,3);
   htemp__10->SetBinContent(18,1);
   htemp__10->SetBinContent(19,4);
   htemp__10->SetBinContent(20,2);
   htemp__10->SetBinContent(21,4);
   htemp__10->SetBinContent(22,4);
   htemp__10->SetBinContent(23,9);
   htemp__10->SetBinContent(24,8);
   htemp__10->SetBinContent(25,5);
   htemp__10->SetBinContent(26,5);
   htemp__10->SetBinContent(27,5);
   htemp__10->SetBinContent(28,6);
   htemp__10->SetBinContent(29,6);
   htemp__10->SetBinContent(30,25);
   htemp__10->SetBinContent(31,10);
   htemp__10->SetBinContent(32,21);
   htemp__10->SetBinContent(33,15);
   htemp__10->SetBinContent(34,14);
   htemp__10->SetBinContent(35,16);
   htemp__10->SetBinContent(36,19);
   htemp__10->SetBinContent(37,11);
   htemp__10->SetBinContent(38,14);
   htemp__10->SetBinContent(39,15);
   htemp__10->SetBinContent(40,9);
   htemp__10->SetBinContent(41,13);
   htemp__10->SetBinContent(42,7);
   htemp__10->SetBinContent(43,9);
   htemp__10->SetBinContent(44,9);
   htemp__10->SetBinContent(45,5);
   htemp__10->SetBinContent(46,5);
   htemp__10->SetBinContent(47,9);
   htemp__10->SetBinContent(48,8);
   htemp__10->SetBinContent(49,6);
   htemp__10->SetBinContent(50,3);
   htemp__10->SetBinContent(51,3);
   htemp__10->SetBinContent(52,5);
   htemp__10->SetBinContent(53,3);
   htemp__10->SetBinContent(54,2);
   htemp__10->SetBinContent(55,2);
   htemp__10->SetBinContent(56,1);
   htemp__10->SetBinContent(58,1);
   htemp__10->SetBinContent(59,1);
   htemp__10->SetBinContent(63,2);
   htemp__10->SetBinContent(69,1);
   htemp__10->SetBinContent(70,2);
   htemp__10->SetBinContent(75,1);
   htemp__10->SetBinContent(92,1);
   htemp__10->SetEntries(336);

   TH1F *htemp__11 = new TH1F("htemp_11","pulse_area_col2_pe/pulse_area_bot_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-0.025,0.295);
   htemp__11->SetBinContent(8,1);
   htemp__11->SetBinContent(9,2);
   htemp__11->SetBinContent(11,1);
   htemp__11->SetBinContent(12,3);
   htemp__11->SetBinContent(13,10);
   htemp__11->SetBinContent(14,19);
   htemp__11->SetBinContent(15,21);
   htemp__11->SetBinContent(16,26);
   htemp__11->SetBinContent(17,31);
   htemp__11->SetBinContent(18,28);
   htemp__11->SetBinContent(19,35);
   htemp__11->SetBinContent(20,35);
   htemp__11->SetBinContent(21,26);
   htemp__11->SetBinContent(22,18);
   htemp__11->SetBinContent(23,21);
   htemp__11->SetBinContent(24,8);
   htemp__11->SetBinContent(25,13);
   htemp__11->SetBinContent(26,10);
   htemp__11->SetBinContent(27,4);
   htemp__11->SetBinContent(28,3);
   htemp__11->SetBinContent(29,5);
   htemp__11->SetBinContent(30,2);
   htemp__11->SetBinContent(31,2);
   htemp__11->SetBinContent(32,4);
   htemp__11->SetBinContent(35,1);
   htemp__11->SetBinContent(36,2);
   htemp__11->SetBinContent(40,2);
   htemp__11->SetBinContent(51,1);
   htemp__11->SetBinContent(79,1);
   htemp__11->SetBinContent(93,1);
   htemp__11->SetEntries(336);
   htemp__11->SetDirectory(0);

   TH1F *htemp__12 = new TH1F("htemp__12","pulse_area_col3_pe/pulse_area_bot_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,0,0.205);
   htemp__12->SetBinContent(1,1);
   htemp__12->SetBinContent(3,1);
   htemp__12->SetBinContent(8,1);
   htemp__12->SetBinContent(10,1);
   htemp__12->SetBinContent(11,2);
   htemp__12->SetBinContent(12,4);
   htemp__12->SetBinContent(13,8);
   htemp__12->SetBinContent(14,2);
   htemp__12->SetBinContent(15,6);
   htemp__12->SetBinContent(16,4);
   htemp__12->SetBinContent(17,7);
   htemp__12->SetBinContent(18,12);
   htemp__12->SetBinContent(19,10);
   htemp__12->SetBinContent(20,3);
   htemp__12->SetBinContent(21,5);
   htemp__12->SetBinContent(22,11);
   htemp__12->SetBinContent(23,11);
   htemp__12->SetBinContent(24,17);
   htemp__12->SetBinContent(25,11);
   htemp__12->SetBinContent(26,9);
   htemp__12->SetBinContent(27,5);
   htemp__12->SetBinContent(28,9);
   htemp__12->SetBinContent(29,15);
   htemp__12->SetBinContent(30,8);
   htemp__12->SetBinContent(31,8);
   htemp__12->SetBinContent(32,9);
   htemp__12->SetBinContent(33,9);
   htemp__12->SetBinContent(34,11);
   htemp__12->SetBinContent(35,8);
   htemp__12->SetBinContent(36,10);
   htemp__12->SetBinContent(37,4);
   htemp__12->SetBinContent(38,6);
   htemp__12->SetBinContent(39,11);
   htemp__12->SetBinContent(40,4);
   htemp__12->SetBinContent(41,4);
   htemp__12->SetBinContent(42,8);
   htemp__12->SetBinContent(43,7);
   htemp__12->SetBinContent(44,4);
   htemp__12->SetBinContent(45,1);
   htemp__12->SetBinContent(46,7);
   htemp__12->SetBinContent(47,2);
   htemp__12->SetBinContent(48,4);
   htemp__12->SetBinContent(49,2);
   htemp__12->SetBinContent(50,4);
   htemp__12->SetBinContent(51,4);
   htemp__12->SetBinContent(52,6);
   htemp__12->SetBinContent(53,3);
   htemp__12->SetBinContent(54,4);
   htemp__12->SetBinContent(55,2);
   htemp__12->SetBinContent(56,2);
   htemp__12->SetBinContent(57,3);
   htemp__12->SetBinContent(58,2);
   htemp__12->SetBinContent(59,2);
   htemp__12->SetBinContent(60,2);
   htemp__12->SetBinContent(61,3);
   htemp__12->SetBinContent(62,1);
   htemp__12->SetBinContent(63,2);
   htemp__12->SetBinContent(64,1);
   htemp__12->SetBinContent(66,2);
   htemp__12->SetBinContent(68,1);
   htemp__12->SetBinContent(69,1);
   htemp__12->SetBinContent(70,3);
   htemp__12->SetBinContent(72,1);
   htemp__12->SetBinContent(75,2);
   htemp__12->SetBinContent(76,1);
   htemp__12->SetBinContent(84,1);
   htemp__12->SetBinContent(91,1);
   htemp__12->SetEntries(336);
   htemp__12->SetDirectory(0);

   TH1F *htemp__13 = new TH1F("htemp__13","pulse_area_col4_pe/pulse_area_bot_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-0.03,0.365);
   htemp__13->SetBinContent(8,3);
   htemp__13->SetBinContent(9,6);
   htemp__13->SetBinContent(10,13);
   htemp__13->SetBinContent(11,32);
   htemp__13->SetBinContent(12,36);
   htemp__13->SetBinContent(13,47);
   htemp__13->SetBinContent(14,43);
   htemp__13->SetBinContent(15,43);
   htemp__13->SetBinContent(16,26);
   htemp__13->SetBinContent(17,25);
   htemp__13->SetBinContent(18,12);
   htemp__13->SetBinContent(19,12);
   htemp__13->SetBinContent(20,9);
   htemp__13->SetBinContent(21,7);
   htemp__13->SetBinContent(22,5);
   htemp__13->SetBinContent(23,1);
   htemp__13->SetBinContent(24,2);
   htemp__13->SetBinContent(25,3);
   htemp__13->SetBinContent(27,1);
   htemp__13->SetBinContent(28,1);
   htemp__13->SetBinContent(30,3);
   htemp__13->SetBinContent(31,1);
   htemp__13->SetBinContent(33,1);
   htemp__13->SetBinContent(34,1);
   htemp__13->SetBinContent(38,1);
   htemp__13->SetBinContent(48,1);
   htemp__13->SetBinContent(93,1);
   htemp__13->SetEntries(336);
   htemp__13->SetDirectory(0);

  ////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////
  // row 1
   TH1F *htempp__1 = new TH1F("htemp__1","pulse_area_row1_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-10,112);
   htempp__1->SetBinContent(9,9);
   htempp__1->SetBinContent(10,25);
   htempp__1->SetBinContent(11,39);
   htempp__1->SetBinContent(12,47);
   htempp__1->SetBinContent(13,51);
   htempp__1->SetBinContent(14,53);
   htempp__1->SetBinContent(15,41);
   htempp__1->SetBinContent(16,18);
   htempp__1->SetBinContent(17,19);
   htempp__1->SetBinContent(18,9);
   htempp__1->SetBinContent(19,9);
   htempp__1->SetBinContent(20,2);
   htempp__1->SetBinContent(21,2);
   htempp__1->SetBinContent(22,3);
   htempp__1->SetBinContent(23,1);
   htempp__1->SetBinContent(24,1);
   htempp__1->SetBinContent(27,1);
   htempp__1->SetBinContent(30,1);
   htempp__1->SetBinContent(31,1);
   htempp__1->SetBinContent(32,2);
   htempp__1->SetBinContent(34,1);
   htempp__1->SetBinContent(93,1);
   htempp__1->SetEntries(336);

   // row 2
   TH1F *htempp__2 = new TH1F("htemp__2","pulse_area_row2_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-7,84);
   htempp__2->SetBinContent(8,4);
   htempp__2->SetBinContent(9,10);
   htempp__2->SetBinContent(10,18);
   htempp__2->SetBinContent(11,24);
   htempp__2->SetBinContent(12,27);
   htempp__2->SetBinContent(13,36);
   htempp__2->SetBinContent(14,34);
   htempp__2->SetBinContent(15,46);
   htempp__2->SetBinContent(16,22);
   htempp__2->SetBinContent(17,18);
   htempp__2->SetBinContent(18,21);
   htempp__2->SetBinContent(19,16);
   htempp__2->SetBinContent(20,12);
   htempp__2->SetBinContent(21,10);
   htempp__2->SetBinContent(22,5);
   htempp__2->SetBinContent(23,3);
   htempp__2->SetBinContent(24,7);
   htempp__2->SetBinContent(25,2);
   htempp__2->SetBinContent(26,2);
   htempp__2->SetBinContent(27,3);
   htempp__2->SetBinContent(28,1);
   htempp__2->SetBinContent(29,1);
   htempp__2->SetBinContent(30,2);
   htempp__2->SetBinContent(31,1);
   htempp__2->SetBinContent(33,2);
   htempp__2->SetBinContent(38,2);
   htempp__2->SetBinContent(45,1);
   htempp__2->SetBinContent(49,2);
   htempp__2->SetBinContent(55,1);
   htempp__2->SetBinContent(59,1);
   htempp__2->SetBinContent(65,1);
   htempp__2->SetBinContent(93,1);

   // row 3
   TH1F *htempp__3 = new TH1F("htemp__3","pulse_area_row3_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,0,164);
   htempp__3->SetBinContent(1,1);
   htempp__3->SetBinContent(3,2);
   htempp__3->SetBinContent(4,3);
   htempp__3->SetBinContent(5,2);
   htempp__3->SetBinContent(6,3);
   htempp__3->SetBinContent(7,7);
   htempp__3->SetBinContent(8,16);
   htempp__3->SetBinContent(9,15);
   htempp__3->SetBinContent(10,21);
   htempp__3->SetBinContent(11,31);
   htempp__3->SetBinContent(12,12);
   htempp__3->SetBinContent(13,36);
   htempp__3->SetBinContent(14,32);
   htempp__3->SetBinContent(15,29);
   htempp__3->SetBinContent(16,23);
   htempp__3->SetBinContent(17,29);
   htempp__3->SetBinContent(18,18);
   htempp__3->SetBinContent(19,12);
   htempp__3->SetBinContent(20,11);
   htempp__3->SetBinContent(21,7);
   htempp__3->SetBinContent(22,7);
   htempp__3->SetBinContent(23,6);
   htempp__3->SetBinContent(24,1);
   htempp__3->SetBinContent(25,1);
   htempp__3->SetBinContent(27,1);
   htempp__3->SetBinContent(28,2);
   htempp__3->SetBinContent(29,1);
   htempp__3->SetBinContent(30,1);
   htempp__3->SetBinContent(34,1);
   htempp__3->SetBinContent(37,2);
   htempp__3->SetBinContent(46,1);
   htempp__3->SetBinContent(67,1);
   htempp__3->SetBinContent(92,1);

   // row 4
   TH1F *htempp__4 = new TH1F("htemp__4","pulse_area_row4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-15,205);
   htempp__4->SetBinContent(7,1);
   htempp__4->SetBinContent(8,2);
   htempp__4->SetBinContent(11,2);
   htempp__4->SetBinContent(12,7);
   htempp__4->SetBinContent(13,11);
   htempp__4->SetBinContent(14,28);
   htempp__4->SetBinContent(15,30);
   htempp__4->SetBinContent(16,36);
   htempp__4->SetBinContent(17,34);
   htempp__4->SetBinContent(18,45);
   htempp__4->SetBinContent(19,31);
   htempp__4->SetBinContent(20,35);
   htempp__4->SetBinContent(21,22);
   htempp__4->SetBinContent(22,13);
   htempp__4->SetBinContent(23,9);
   htempp__4->SetBinContent(24,7);
   htempp__4->SetBinContent(25,3);
   htempp__4->SetBinContent(26,4);
   htempp__4->SetBinContent(27,3);
   htempp__4->SetBinContent(28,2);
   htempp__4->SetBinContent(29,1);
   htempp__4->SetBinContent(30,2);
   htempp__4->SetBinContent(31,1);
   htempp__4->SetBinContent(33,1);
   htempp__4->SetBinContent(37,2);
   htempp__4->SetBinContent(41,1);
   htempp__4->SetBinContent(70,1);
   htempp__4->SetBinContent(71,1);
   htempp__4->SetBinContent(94,1);

   // row 1/ row 4
   TH1F *htemppp__1 = new TH1F("htemp__1","pulse_area_row1_pe/pulse_area_row4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,0,15.6);
   htemppp__1->SetBinContent(1,85);
   htemppp__1->SetBinContent(2,146);
   htemppp__1->SetBinContent(3,62);
   htemppp__1->SetBinContent(4,25);
   htemppp__1->SetBinContent(5,8);
   htemppp__1->SetBinContent(6,2);
   htemppp__1->SetBinContent(7,4);
   htemppp__1->SetBinContent(9,1);
   htemppp__1->SetBinContent(10,1);
   htemppp__1->SetBinContent(13,1);
   htemppp__1->SetBinContent(92,1);
   htemppp__1->SetEntries(336);
   htemppp__1->SetDirectory(0);

   // row 2 / row 4
   TH1F *htemppp__2 = new TH1F("htemp__2","pulse_area_row2_pe/pulse_area_row4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-2,22);
   htemppp__2->SetBinContent(9,76);
   htemppp__2->SetBinContent(10,186);
   htemppp__2->SetBinContent(11,47);
   htemppp__2->SetBinContent(12,15);
   htemppp__2->SetBinContent(13,5);
   htemppp__2->SetBinContent(14,1);
   htemppp__2->SetBinContent(15,2);
   htemppp__2->SetBinContent(17,1);
   htemppp__2->SetBinContent(18,1);
   htemppp__2->SetBinContent(20,1);
   htemppp__2->SetBinContent(92,1);

   // row 3 / row 4
   TH1F *htemppp__3 = new TH1F("htemp__3","pulse_area_row3_pe/pulse_area_row4_pe {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,-1.8,11);
   htemppp__3->SetBinContent(8,1);
   htemppp__3->SetBinContent(16,1);
   htemppp__3->SetBinContent(17,3);
   htemppp__3->SetBinContent(18,10);
   htemppp__3->SetBinContent(19,25);
   htemppp__3->SetBinContent(20,48);
   htemppp__3->SetBinContent(21,60);
   htemppp__3->SetBinContent(22,58);
   htemppp__3->SetBinContent(23,36);
   htemppp__3->SetBinContent(24,22);
   htemppp__3->SetBinContent(25,20);
   htemppp__3->SetBinContent(26,16);
   htemppp__3->SetBinContent(27,14);
   htemppp__3->SetBinContent(28,11);
   htemppp__3->SetBinContent(29,3);
   htemppp__3->SetBinContent(31,2);
   htemppp__3->SetBinContent(32,3);
   htemppp__3->SetBinContent(36,1);
   htemppp__3->SetBinContent(72,1);
   htemppp__3->SetBinContent(92,1);

   // row 12 / row 34
   TH1F *htemppp__4 = new TH1F("htemp__4","(pulse_area_row1_pe+pulse_area_row2_pe)/(pulse_area_row4_pe+pulse_area_row3_pe) {aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0}",100,0,10.2);
   htemppp__4->SetBinContent(1,15);
   htemppp__4->SetBinContent(2,80);
   htemppp__4->SetBinContent(3,121);
   htemppp__4->SetBinContent(4,65);
   htemppp__4->SetBinContent(5,29);
   htemppp__4->SetBinContent(6,10);
   htemppp__4->SetBinContent(7,4);
   htemppp__4->SetBinContent(8,5);
   htemppp__4->SetBinContent(10,1);
   htemppp__4->SetBinContent(12,1);
   htemppp__4->SetBinContent(17,1);
   htemppp__4->SetBinContent(22,1);
   htemppp__4->SetBinContent(28,1);
   htemppp__4->SetBinContent(31,1);
   htemppp__4->SetBinContent(92,1);


  TCanvas* c1 = new TCanvas();
  c1->Divide(4,4);
  for (int i=0;i<5;i++){
    c1->cd(i+1);
    h1[i]->Draw();
  }
  for (int i=0;i<5;i++){
    c1->cd(i+6);
    h2[i]->SetLineColor(1);
    h2[i]->Draw();
    //if (i == 4) f2.Draw("pulse_area_bot_pe","aux_ch_area_mV[0] > 350 && pulse_area_max_frac< 0.18 && pulse_ptime_ns< 395 && pulse_ptime_ns> 365 && event_sanity == 0 && event_saturated == 0 && pulse_id == 0 && npulse >0");
    if (i == 4) htemp__1->Draw("same");
    if (i == 0) htemp__2->Draw("same");    
    if (i == 1) htemp__3->Draw("same");
    if (i == 2) htemp__4->Draw("same");
    if (i == 3) htemp__5->Draw("same");
  }
  for (int i=0;i<4;i++){
    c1->cd(i+11);
    h2[i+5]->Draw();
  }
  
  TCanvas* c3 = new TCanvas();
  c3->Divide(2,2);
  c3->cd(1);
  h2[0]->SetLineWidth(4);
  h3[0]->SetLineWidth(4);
  htemp__2->SetLineWidth(4);
  h2[0]->SetLineColor(1);
  h3[0]->SetLineColor(2);
  htemp__2->SetLineColor(4);
  h2[0]->Scale(1./h2[0]->Integral());
  h3[0]->Scale(1./h3[0]->Integral());
  htemp__2->Scale(1./htemp__2->Integral());
  h2[0]->SetTitle("Column 1; PE; Counts");
  h2[0]->Draw();
  h3[0]->Draw("same");
  htemp__2->Draw("same");
  TLegend* leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[4] ,"straight downward 1GeV","l");
  leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(htemp__1 ,"data","l");
  leg->Draw();

  c3->cd(2);
  h2[1]->SetLineWidth(4);
  h3[1]->SetLineWidth(4);
  htemp__3->SetLineWidth(4);
  h2[1]->SetLineColor(1);
  h3[1]->SetLineColor(2);
  htemp__3->SetLineColor(4);
  h2[1]->Scale(1./h2[1]->Integral());
  h3[1]->Scale(1./h3[1]->Integral());
  htemp__3->Scale(1./htemp__3->Integral());
  h2[1]->SetTitle("Column 2; PE; Counts");
  h2[1]->Draw();
  h3[1]->Draw("same");
  htemp__3->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[4] ,"straight downward 1GeV","l");
  leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(htemp__1 ,"data","l");
  leg->Draw();

  c3->cd(3);
  h2[2]->SetLineWidth(4);
  h3[2]->SetLineWidth(4);
  htemp__4->SetLineWidth(4);
  h2[2]->SetLineColor(1);
  h3[2]->SetLineColor(2);
  htemp__4->SetLineColor(4);
  h2[2]->Scale(1./h2[2]->Integral());
  h3[2]->Scale(1./h3[2]->Integral());
  htemp__4->Scale(1./htemp__4->Integral());
  h2[2]->SetTitle("Column 3; PE; Counts");
  h2[2]->Draw();
  h3[2]->Draw("same");
  htemp__4->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[4] ,"straight downward 1GeV","l");
  leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(htemp__1 ,"data","l");
  leg->Draw();

  c3->cd(4);
  h2[3]->SetLineWidth(4);
  h3[3]->SetLineWidth(4);
  htemp__5->SetLineWidth(4);
  h2[3]->SetLineColor(1);
  h3[3]->SetLineColor(2);
  htemp__5->SetLineColor(4);
  h2[3]->Scale(1./h2[3]->Integral());
  h3[3]->Scale(1./h3[3]->Integral());
  htemp__5->Scale(1./htemp__5->Integral());
  h2[3]->SetTitle("Column 4; PE; Counts");
  h2[3]->Draw();
  h3[3]->Draw("same");
  htemp__5->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[4] ,"straight downward 1GeV","l");
  leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(htemp__1 ,"data","l");
  leg->Draw(); 

  new TCanvas();
  h2[4]->SetLineWidth(4);
  h3[4]->SetLineWidth(4);
  htemp__1->SetLineWidth(4);
  h2[4]->SetLineColor(1);
  h3[4]->SetLineColor(2);
  htemp__1->SetLineColor(4);
  h2[4]->Scale(1./h2[4]->Integral());
  h3[4]->Scale(1./h3[4]->Integral());
  htemp__1->Scale(1./htemp__1->Integral());
  h2[4]->SetTitle("Column 4; PE; Counts");
  h2[4]->Draw();
  h3[4]->Draw("same");
  htemp__1->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[4] ,"straight downward 1GeV","l");
  leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(htemp__1 ,"data","l");
  leg->Draw();

  TCanvas* c4 = new TCanvas();
  c4->Divide(2,2);
  c4->cd(1);
  hh2[0]->SetLineWidth(4);
  hh3[0]->SetLineWidth(4);
  htemp__10->SetLineWidth(4);
  hh2[0]->SetLineColor(1);
  hh3[0]->SetLineColor(2);
  htemp__10->SetLineColor(4);
  hh2[0]->Scale(1./hh2[0]->Integral());
  hh3[0]->Scale(1./hh3[0]->Integral());
  htemp__10->Scale(1./htemp__10->Integral());
  hh2[0]->SetTitle("Column 1;  Col/Bottom fraction; Counts");
  hh2[0]->Draw();
  hh3[0]->Draw("same");
  htemp__10->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[4] ,"straight downward 1GeV","l");
  leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(htemp__1 ,"data","l");
  leg->Draw();

  c4->cd(2);
  hh2[1]->SetLineWidth(4);
  hh3[1]->SetLineWidth(4);
  htemp__11->SetLineWidth(4);
  hh2[1]->SetLineColor(1);
  hh3[1]->SetLineColor(2);
  htemp__11->SetLineColor(4);
  hh2[1]->Scale(1./hh2[1]->Integral());
  hh3[1]->Scale(1./hh3[1]->Integral());
  htemp__11->Scale(1./htemp__11->Integral());
  hh2[1]->SetTitle("Column 2;  Col/Bottom fraction; Counts");
  hh2[1]->Draw();
  hh3[1]->Draw("same");
  htemp__11->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[4] ,"straight downward 1GeV","l");
  //leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(h3[4] ,"straight downward 20GeV","l");
  leg->AddEntry(htemp__1 ,"data","l");
  leg->Draw();

  c4->cd(3);
  hh2[2]->SetLineWidth(4);
  hh3[2]->SetLineWidth(4);
  htemp__12->SetLineWidth(4);
  hh2[2]->SetLineColor(1);
  hh3[2]->SetLineColor(2);
  htemp__12->SetLineColor(4);
  hh2[2]->Scale(1./hh2[2]->Integral());
  hh3[2]->Scale(1./hh3[2]->Integral());
  htemp__12->Scale(1./htemp__12->Integral());
  hh2[2]->SetTitle("Column 3;  Col/Bottom fraction; Counts");
  hh2[2]->Draw();
  hh3[2]->Draw("same");
  htemp__12->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[4] ,"straight downward 1GeV","l");
  //leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(h3[4] ,"straight downward 20GeV","l");
  leg->AddEntry(htemp__1 ,"data","l");
  leg->Draw();

  c4->cd(4);
  hh2[3]->SetLineWidth(4);
  hh3[3]->SetLineWidth(4);
  htemp__13->SetLineWidth(4);
  hh2[3]->SetLineColor(1);
  hh3[3]->SetLineColor(2);
  htemp__13->SetLineColor(4);
  hh2[3]->Scale(1./hh2[3]->Integral());
  hh3[3]->Scale(1./hh3[3]->Integral());
  htemp__13->Scale(1./htemp__13->Integral());
  hh2[3]->SetTitle("Column 4;  Col/Bottom fraction; Counts");
  hh2[3]->Draw();
  hh3[3]->Draw("same");
  htemp__13->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[4] ,"straight downward 1GeV","l");
  //leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(h3[4] ,"straight downward 20GeV","l");
  leg->AddEntry(htemp__1 ,"data","l");
  leg->Draw();

  h3[5]->Scale (1./h3[5]->Integral());
  h3[6]->Scale (1./h3[6]->Integral());
  h3[7]->Scale (1./h3[7]->Integral());
  h3[8]->Scale (1./h3[8]->Integral());

  h4[0]->Scale (1./h4[0]->Integral());
  h4[1]->Scale (1./h4[1]->Integral());
  h4[2]->Scale (1./h4[2]->Integral());
  h4[3]->Scale (1./h4[3]->Integral());

  h2[5]->Scale (1./h2[5]->Integral());
  h2[6]->Scale (1./h2[6]->Integral());
  h2[7]->Scale (1./h2[7]->Integral());
  h2[8]->Scale (1./h2[8]->Integral());

  h5[0]->Scale (1./h5[0]->Integral());
  h5[1]->Scale (1./h5[1]->Integral());
  h5[2]->Scale (1./h5[2]->Integral());
  h5[3]->Scale (1./h5[3]->Integral());

  TCanvas* c5 = new TCanvas();
  c5->Divide(2,2);
  c5->cd(1);
  h2[5]->SetLineWidth(4);
  h3[5]->SetLineWidth(4);
  htempp__1->SetLineWidth(4);
  h2[5]->SetLineColor(1);
  h3[5]->SetLineColor(2);
  htempp__1->SetLineColor(4);
  htempp__1->Scale(1./htempp__1->Integral());
  h2[5]->SetTitle("Row 1; Row 1 PE; Counts");
  h2[5]->Draw();
  h3[5]->Draw("same");
  htempp__1->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[5] ,"straight downward 1GeV","l");
  leg->AddEntry(h3[5] ,"tilted minus 10 deg.","l");
  leg->AddEntry(htempp__1 ,"data","l");
  leg->Draw();

  c5->cd(2);
  h2[6]->SetLineWidth(4);
  h3[6]->SetLineWidth(4);
  htempp__2->SetLineWidth(4);
  h2[6]->SetLineColor(1);
  h3[6]->SetLineColor(2);
  htempp__2->SetLineColor(4);
  htempp__2->Scale(1./htempp__2->Integral());
  h2[6]->SetTitle("Row 2; Row 2 PE; Counts");
  h2[6]->Draw();
  h3[6]->Draw("same");
  htempp__2->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[6] ,"straight downward 1GeV","l");
  //leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(h3[6] ,"tilted minus 10 deg.","l");
  leg->AddEntry(htempp__2 ,"data","l");
  leg->Draw();

  c5->cd(3);
  h2[7]->SetLineWidth(4);
  h3[7]->SetLineWidth(4);
  htempp__3->SetLineWidth(4);
  h2[7]->SetLineColor(1);
  h3[7]->SetLineColor(2);
  htempp__3->SetLineColor(4);
  htempp__3->Scale(1./htempp__3->Integral());
  h2[7]->SetTitle("Row 3; Row 3 PE; Counts");
  h2[7]->Draw();
  h3[7]->Draw("same");
  htempp__3->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[7] ,"straight downward 1GeV","l");
  //leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(h3[7] ,"tilted minus 10 deg.","l");
  leg->AddEntry(htempp__3 ,"data","l");
  leg->Draw();

  c5->cd(4);
  h2[8]->SetLineWidth(4);
  h3[8]->SetLineWidth(4);
  htempp__4->SetLineWidth(4);
  h2[8]->SetLineColor(1);
  h3[8]->SetLineColor(2);
  htempp__4->SetLineColor(4);
  htempp__4->Scale(1./htempp__4->Integral());
  h2[8]->SetTitle("Row 4; Row 4 PE; Counts");
  h2[8]->Draw();
  h3[8]->Draw("same");
  htempp__4->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h2[8] ,"straight downward 1GeV","l");
  //leg->AddEntry(h3[4] ,"staight downward 20GeV","l");
  leg->AddEntry(h3[8] ,"tilted minus 10 deg.","l");
  leg->AddEntry(htempp__4 ,"data","l");
  leg->Draw();


  TCanvas* c6 = new TCanvas();
  c6->Divide(2,2);
  c6->cd(1);
  h4[0]->SetLineWidth(4);
  h5[0]->SetLineWidth(4);
  htemppp__1->SetLineWidth(4);
  h4[0]->SetLineColor(1);
  h5[0]->SetLineColor(2);
  htemppp__1->SetLineColor(4);
  htemppp__1->Scale(1./htemppp__1->Integral());
  h4[0]->SetTitle(";  Row1/Row4 fraction; Counts");
  h4[0]->Draw();
  h5[0]->Draw("same");
  htemppp__1->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h4[0] ,"straight downward 1GeV","l");
  leg->AddEntry(h5[0] ,"tilted minus 10 deg.","l");
  leg->AddEntry(htemppp__1 ,"data","l");
  leg->Draw();

  c6->cd(2);
  h4[1]->SetLineWidth(4);
  h5[1]->SetLineWidth(4);
  htemppp__2->SetLineWidth(4);
  h4[1]->SetLineColor(1);
  h5[1]->SetLineColor(2);
  htemppp__2->SetLineColor(4);
  htemppp__2->Scale(1./htemppp__2->Integral());
  h4[1]->SetTitle("; Row2/Row4 fraction; Counts");
  h4[1]->Draw();
  h5[1]->Draw("same");
  htemppp__2->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h4[1] ,"straight downward 1GeV","l");
  //leg->AddEntry(h5[4] ,"staight downward 20GeV","l");
  leg->AddEntry(h5[1] ,"tilted minus 10 deg.","l");
  leg->AddEntry(htemppp__2 ,"data","l");
  leg->Draw();

  c6->cd(3);
  h4[2]->SetLineWidth(4);
  h5[2]->SetLineWidth(4);
  htemppp__3->SetLineWidth(4);
  h4[2]->SetLineColor(1);
  h5[2]->SetLineColor(2);
  htemppp__3->SetLineColor(4);
  htemppp__3->Scale(1./htemppp__3->Integral());
  h4[2]->SetTitle("; Row3/Row4 fraction; Counts");
  h4[2]->Draw();
  h5[2]->Draw("same");
  htemppp__3->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h4[2] ,"straight downward 1GeV","l");
  //leg->AddEntry(h5[4] ,"staight downward 20GeV","l");
  leg->AddEntry(h5[2] ,"tilted minus 10 deg.","l");
  leg->AddEntry(htemppp__3 ,"data","l");
  leg->Draw();

  c6->cd(4);
  h4[3]->SetLineWidth(4);
  h5[3]->SetLineWidth(4);
  htemppp__4->SetLineWidth(4);
  h4[3]->SetLineColor(1);
  h5[3]->SetLineColor(2);
  htemppp__4->SetLineColor(4);
  h4[3]->Scale(1./h4[3]->Integral());
  h5[3]->Scale(1./h5[3]->Integral());
  htemppp__4->Scale(1./htemppp__4->Integral());
  h4[3]->SetTitle(";  Row1+2/Row3+4 fraction; Counts");
  h4[3]->Draw();
  h5[3]->Draw("same");
  htemppp__4->Draw("same");
  leg = new TLegend(0.56,0.68,0.9,0.9,NULL,"brNDC");
  leg->AddEntry(h4[3] ,"straight downward 1GeV","l");
  //leg->AddEntry(h5[4] ,"staight downward 20GeV","l");
  leg->AddEntry(h5[3] ,"tilted minus 10 deg.","l");
  leg->AddEntry(htemppp__4 ,"data","l");
  leg->Draw();


  TCanvas* c2 = new TCanvas();
  c2->Divide(3,4);
  for (int i=0;i<4;i++){
    c2->cd(i+1);
    hh1[i]->Draw();
  }
  for (int i=0;i<5;i++){
    c2->cd(i+5);
    hh2[i]->Draw();
  }

}
