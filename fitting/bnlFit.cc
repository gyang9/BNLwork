#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>

#include "bnlFit.hh"
#include "TMath.h"
#include "RooArgList.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include "RooRealVar.h"
#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "TString.h"
#include <TVectorD.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TFrame.h>
#include <TFile.h>
#include <TGraph.h>
#include <TF1.h>
#include <TH1D.h>
#include <TVector3.h>

using namespace std;

bnlFit ::bnlFit (const char* name)
  : RooAbsReal(name,name)
{
  _pulls     = new RooListProxy("_pulls","_pulls",this);
  RooRealVar* Par1 = new RooRealVar("par1","par1",1,0,2);
  RooRealVar* Par2 = new RooRealVar("par2","par2",1,0,2);
  RooRealVar* Par3 = new RooRealVar("par3","par3",1,0,2);
  RooRealVar* Par4 = new RooRealVar("par4","par4",1,0,2);
  RooRealVar* Par5 = new RooRealVar("par5","par5",1,0,2);
  RooRealVar* Par6 = new RooRealVar("par6","par6",1,0,2); 
  RooRealVar* Par7 = new RooRealVar("par7","par7",1,0,2);
  RooRealVar* Par8 = new RooRealVar("par8","par8",1,0,2);
  RooRealVar* Par9 = new RooRealVar("par9","par9",1,0,2);
  RooRealVar* Par10 = new RooRealVar("par10","par10",1,0,2);
  RooRealVar* Par11 = new RooRealVar("par11","par11",1,0,2);
  RooRealVar* Par12 = new RooRealVar("par12","par12",1,0,2);
  RooRealVar* Par13 = new RooRealVar("par13","par13",1,0,2);
  RooRealVar* Par14 = new RooRealVar("par14","par14",1,0,2);
  RooRealVar* Par15 = new RooRealVar("par15","par15",1,0,2); 
  RooRealVar* Par16 = new RooRealVar("par16","par16",1,0,2);
  RooRealVar* Par17 = new RooRealVar("par17","par17",1,0,2);
  RooRealVar* Par18 = new RooRealVar("par18","par18",1,0,2);
  RooRealVar* Par19 = new RooRealVar("par19","par19",1,0,2);
  RooRealVar* Par20 = new RooRealVar("par20","par20",1,0,2);
  RooRealVar* Par21 = new RooRealVar("par21","par21",1,0,2);
  RooRealVar* Par22 = new RooRealVar("par22","par22",1,0,2);
  RooRealVar* Par23 = new RooRealVar("par23","par23",1,0,2);
  RooRealVar* Par24 = new RooRealVar("par24","par24",1,0,2); 
  RooRealVar* Par25 = new RooRealVar("par25","par25",1,0,2);
  RooRealVar* Par26 = new RooRealVar("par26","par26",1,0,2);
  RooRealVar* Par27 = new RooRealVar("par27","par27",1,0,2);
  RooRealVar* Par28 = new RooRealVar("par28","par28",1,0,2);
  RooRealVar* Par29 = new RooRealVar("par29","par29",1,0,2);
  RooRealVar* Par30 = new RooRealVar("par30","par30",1,0,2);
  RooRealVar* Par31 = new RooRealVar("par31","par31",1,0,2);

  Par1->setConstant(false);
  Par2->setConstant(false);
  Par3->setConstant(false);
  Par4->setConstant(false);
  Par5->setConstant(false);
  Par6->setConstant(false);
  Par7->setConstant(false);
  Par8->setConstant(false);
  Par9->setConstant(false);
  Par10->setConstant(false);
  Par11->setConstant(false);
  Par12->setConstant(false);
  Par13->setConstant(false);
  Par14->setConstant(false);
  Par15->setConstant(false);
  Par16->setConstant(false);
  Par17->setConstant(false);
  Par18->setConstant(false);
  Par19->setConstant(false);
  Par20->setConstant(false);
  Par21->setConstant(false);
  Par22->setConstant(false);
  Par23->setConstant(false);
  Par24->setConstant(false);
  Par25->setConstant(false);
  Par26->setConstant(false);
  Par27->setConstant(false);
  Par28->setConstant(false);
  Par29->setConstant(false);
  Par30->setConstant(false);
  Par31->setConstant(false);

  _parlist.add(*Par1);
  _parlist.add(*Par2);
  _parlist.add(*Par3);
  _parlist.add(*Par4);
  _parlist.add(*Par5);
  _parlist.add(*Par6);
  _parlist.add(*Par7);
  _parlist.add(*Par8);
  _parlist.add(*Par9);
  _parlist.add(*Par10);
  _parlist.add(*Par11);
  _parlist.add(*Par12);
  _parlist.add(*Par13);
  _parlist.add(*Par14);
  _parlist.add(*Par15);
  _parlist.add(*Par16);
  _parlist.add(*Par17);
  _parlist.add(*Par18);
  _parlist.add(*Par19);
  _parlist.add(*Par20);
  _parlist.add(*Par21);
  _parlist.add(*Par22);
  _parlist.add(*Par23);
  _parlist.add(*Par24);
  _parlist.add(*Par25);
  _parlist.add(*Par26);
  _parlist.add(*Par27);
  _parlist.add(*Par28);
  _parlist.add(*Par29);
  _parlist.add(*Par30);
  _parlist.add(*Par31);

  _pulls->add(_parlist);

  this->addServerList(*_pulls);

  for (int i=0;i<30;i++){
    ratiox1[i] = new TH1F("","",2500,0,100);
    ratiox2[i] = new TH1F("","",2500,0,100);
    ratiox3[i] = new TH1F("","",2500,0,100);
    ratiox4[i] = new TH1F("","",2500,0,100);
    ratiox5[i] = new TH1F("","",2500,0,100);
    ratiox6[i] = new TH1F("","",2500,0,100);
    ratiox7[i] = new TH1F("","",2500,0,100);
    ratiox8[i] = new TH1F("","",2500,0,100);
    ratiox9[i] = new TH1F("","",2500,0,100);
    ratiox10[i] = new TH1F("","",2500,0,100);
    ratiox11[i] = new TH1F("","",2500,0,100);
    ratiox12[i] = new TH1F("","",2500,0,100);
    ratiox13[i] = new TH1F("","",2500,0,100);
    ratiox14[i] = new TH1F("","",2500,0,100);
    ratiox15[i] = new TH1F("","",2500,0,100);
    ratiox16[i] = new TH1F("","",2500,0,100);
    ratiox17[i] = new TH1F("","",2500,0,100);
    ratiox18[i] = new TH1F("","",2500,0,100);
    ratiox19[i] = new TH1F("","",2500,0,100);
    ratiox20[i] = new TH1F("","",2500,0,100);
    ratiox21[i] = new TH1F("","",2500,0,100);
    ratiox22[i] = new TH1F("","",2500,0,100);
    ratiox23[i] = new TH1F("","",2500,0,100);
    ratiox24[i] = new TH1F("","",2500,0,100);
    ratiox25[i] = new TH1F("","",2500,0,100);
    ratiox26[i] = new TH1F("","",2500,0,100);
    ratiox27[i] = new TH1F("","",2500,0,100);
    ratiox28[i] = new TH1F("","",2500,0,100);
    ratiox29[i] = new TH1F("","",2500,0,100);
    ratiox30[i] = new TH1F("","",2500,0,100);
  }
  for (int i=0;i<30;i++){
    h1_ch[i] = new TH1F("","",50,-10,90);
  }

}

bnlFit ::~bnlFit ()
{;}


Double_t bnlFit ::getPar(int i) {
(((RooAbsReal*)_pulls->at(i))->getVal());
}

RooRealVar* bnlFit ::getParVar(int i) {
return ((RooRealVar*)_pulls->at(i));
}

void bnlFit :: setPull(TH1D* pullvecCV){
  pullCV = new TVectorD(11);
  for(Int_t i=0;i<11;i++){
    (*pullCV)[i] =  pullvecCV->GetBinContent(i+1);
  }
}

void bnlFit :: setPullUnc(TH1D* pullvecUnc){
  pullUnc = new TVectorD(11);
  for(Int_t i=0;i<11;i++){
    (*pullUnc)[i] = pullvecUnc->GetBinContent(i+1);
  }
}

Double_t bnlFit::getPullUnc(Int_t pN){
  return (*pullUnc)[pN];
}

Double_t bnlFit::ExtraPull (RooListProxy* _pulls) const
{
  return 0;
}

void bnlFit::setup() const
{
}

Double_t bnlFit::evaluate() const
{
  cout<<"evaluating .. "<<endl;

  for (int i=0;i<50;i++){
    h1_ch[0]->SetBinContent(i+1, adc_b1_ch1[i]);
    h1_ch[1]->SetBinContent(i+1, adc_b1_ch2[i]);
    h1_ch[2]->SetBinContent(i+1, adc_b1_ch3[i]);
    h1_ch[3]->SetBinContent(i+1, adc_b1_ch4[i]);
    h1_ch[4]->SetBinContent(i+1, adc_b1_ch5[i]);
    h1_ch[5]->SetBinContent(i+1, adc_b1_ch6[i]);
    h1_ch[6]->SetBinContent(i+1, adc_b1_ch7[i]);
    h1_ch[7]->SetBinContent(i+1, adc_b1_ch8[i]);
    h1_ch[8]->SetBinContent(i+1, adc_b1_ch9[i]);
    h1_ch[9]->SetBinContent(i+1, adc_b1_ch10[i]);
    h1_ch[10]->SetBinContent(i+1, adc_b1_ch11[i]);
    h1_ch[11]->SetBinContent(i+1, adc_b1_ch12[i]);
    h1_ch[12]->SetBinContent(i+1, adc_b1_ch13[i]);
    h1_ch[13]->SetBinContent(i+1, adc_b1_ch14[i]);
    h1_ch[14]->SetBinContent(i+1, adc_b1_ch15[i]);

    h1_ch[15]->SetBinContent(i+1, adc_b2_ch0[i]);
    h1_ch[16]->SetBinContent(i+1, adc_b2_ch1[i]);
    h1_ch[17]->SetBinContent(i+1, adc_b2_ch2[i]);
    h1_ch[18]->SetBinContent(i+1, adc_b2_ch3[i]);
    h1_ch[19]->SetBinContent(i+1, adc_b2_ch4[i]);
    h1_ch[20]->SetBinContent(i+1, adc_b2_ch5[i]);
    h1_ch[21]->SetBinContent(i+1, adc_b2_ch6[i]);
    h1_ch[22]->SetBinContent(i+1, adc_b2_ch7[i]);
    h1_ch[23]->SetBinContent(i+1, adc_b2_ch8[i]);
    h1_ch[24]->SetBinContent(i+1, adc_b2_ch9[i]);
    h1_ch[25]->SetBinContent(i+1, adc_b2_ch10[i]);
    h1_ch[26]->SetBinContent(i+1, adc_b2_ch11[i]);
    h1_ch[27]->SetBinContent(i+1, adc_b2_ch12[i]);
    h1_ch[28]->SetBinContent(i+1, adc_b2_ch13[i]);
    h1_ch[29]->SetBinContent(i+1, adc_b2_ch14[i]);
  }
  TFile f("../bnl1t_newwater2_x_0_y_0_1gev.root");
  //cout<<"ttree"<<endl;
  TTree* ttree = (TTree*)f.Get("tree");
  //ttree->Print();
  float botsumo;
  float row3sumo;
  float row4sumo;
  TH1F* h_botsumo = new TH1F("","",100,0,1000);
  TH1F* h_botsumo_c = new TH1F("","",100,0,1000);
  TH1F* h_row3sumo = new TH1F("","",50,0,100);
  float indpmt[46];

  cout<<"reading the tree"<<endl;
  ttree->SetBranchAddress("indpmt", &indpmt);
  ttree->SetBranchAddress("botsum", &botsumo);
  ttree->SetBranchAddress("row3sum",&row3sumo);
  ttree->SetBranchAddress("row4sum",&row4sumo);

  for (int j=0;j<30;j++){
    ratiox1[j]->Reset();
    ratiox2[j]->Reset();
    ratiox3[j]->Reset();
    ratiox4[j]->Reset();
    ratiox5[j]->Reset();
    ratiox6[j]->Reset();
    ratiox7[j]->Reset();
    ratiox8[j]->Reset();
    ratiox9[j]->Reset();
    ratiox10[j]->Reset();
    ratiox11[j]->Reset();
	  
    ratiox12[j]->Reset();
    ratiox13[j]->Reset();
    ratiox14[j]->Reset();
    ratiox15[j]->Reset();
    ratiox16[j]->Reset();
    ratiox17[j]->Reset();
    ratiox18[j]->Reset();
    ratiox19[j]->Reset();

    ratiox20[j]->Reset();
    ratiox21[j]->Reset();
    ratiox22[j]->Reset();
    ratiox23[j]->Reset();
    ratiox24[j]->Reset();
    ratiox25[j]->Reset();
    ratiox26[j]->Reset();

    ratiox27[j]->Reset();
    ratiox28[j]->Reset();
    ratiox29[j]->Reset();
    ratiox30[j]->Reset();
  }

  cout<<"total MC event number: "<<ttree->GetEntries()<<endl;
  //cout<<"pull at 13 and 15 "<<((RooAbsReal*)_pulls->at(12))->getVal()<<" "<<((RooAbsReal*)_pulls->at(14))->getVal()<<endl;
  //for (int i=0;i<ttree->GetEntries();i++){
  for (int i=0;i<3000; i++){	  
    ttree->GetEntry(i);
    double tot1 = 0;
    //cout<<i<<" "<<indpmt[15]<<endl;
    for (int j=0;j<30;j++){
      if (shape_only){	    

      	ratiox1[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[0]*((RooAbsReal*)_pulls->at(0))->getVal()));
      	ratiox2[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[1]*((RooAbsReal*)_pulls->at(1))->getVal()));
        ratiox3[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[2]*((RooAbsReal*)_pulls->at(2))->getVal()));
        ratiox4[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[3]*((RooAbsReal*)_pulls->at(3))->getVal()));
        ratiox5[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[4]*((RooAbsReal*)_pulls->at(4))->getVal()));
        ratiox6[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[5]*((RooAbsReal*)_pulls->at(5))->getVal()));
        ratiox7[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[6]*((RooAbsReal*)_pulls->at(6))->getVal()));
        ratiox8[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[7]*((RooAbsReal*)_pulls->at(7))->getVal()));
      	ratiox9[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[8]*((RooAbsReal*)_pulls->at(8))->getVal()));
      	ratiox10[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[9]*((RooAbsReal*)_pulls->at(9))->getVal()));
        ratiox11[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[10]*((RooAbsReal*)_pulls->at(10))->getVal()));

      	ratiox12[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[11]*((RooAbsReal*)_pulls->at(11))->getVal()));
      	ratiox12[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[11]*((RooAbsReal*)_pulls->at(11))->getVal()));
        ratiox13[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[12]*((RooAbsReal*)_pulls->at(12))->getVal()));
        ratiox14[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[13]*((RooAbsReal*)_pulls->at(13))->getVal()));
        ratiox15[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[14]*((RooAbsReal*)_pulls->at(14))->getVal()));
        ratiox16[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[15]*((RooAbsReal*)_pulls->at(15))->getVal()));
        ratiox17[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[16]*((RooAbsReal*)_pulls->at(16))->getVal()));
        ratiox18[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[17]*((RooAbsReal*)_pulls->at(17))->getVal()));
        ratiox19[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[18]*((RooAbsReal*)_pulls->at(18))->getVal()));

        ratiox20[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[19]*((RooAbsReal*)_pulls->at(19))->getVal()));
        ratiox21[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[20]*((RooAbsReal*)_pulls->at(20))->getVal()));
        ratiox22[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[21]*((RooAbsReal*)_pulls->at(21))->getVal()));
        ratiox23[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[22]*((RooAbsReal*)_pulls->at(22))->getVal()));
        ratiox24[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[23]*((RooAbsReal*)_pulls->at(23))->getVal()));
        ratiox25[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[24]*((RooAbsReal*)_pulls->at(24))->getVal()));
        ratiox26[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[25]*((RooAbsReal*)_pulls->at(25))->getVal()));	

	ratiox27[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[26]*((RooAbsReal*)_pulls->at(26))->getVal()));
        ratiox28[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[27]*((RooAbsReal*)_pulls->at(27))->getVal()));
        ratiox29[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[28]*((RooAbsReal*)_pulls->at(28))->getVal()));
        ratiox30[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal()/(indpmt[29]*((RooAbsReal*)_pulls->at(29))->getVal()));
      }      
      else {
        ratiox12[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox13[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox14[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox15[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox16[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox17[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox18[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox19[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());	 

        ratiox20[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox21[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox22[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox23[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox24[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox25[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
        ratiox26[j] -> Fill(indpmt[j]*((RooAbsReal*)_pulls->at(j))->getVal());
      }
    }
  }
  

  TGraphErrors* g1[30]; for (int i=0;i<30;i++) g1[i] = new TGraphErrors(30);
  TGraphErrors* g2[30]; for (int i=0;i<30;i++) g2[i] = new TGraphErrors(30);
  double value = 0;
  //cout<<"testing "<<ratiox15[13]->GetMean()<<" "<<h1_ch[13]->GetMean()/h1_ch[15]->GetMean()<<endl;

  for (int i=0;i<20;i++){
    g1[11]->SetPoint(i, 1+i, ratiox12[i]->GetMean());
    g1[11]->SetPointError(i, 0, ratiox12[i]->GetRMS());
    g2[11]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[11]->GetMean());

    g1[12]->SetPoint(i, 1+i, ratiox13[i]->GetMean());
    g1[12]->SetPointError(i, 0, ratiox13[i]->GetRMS());
    g2[12]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[12]->GetMean());

    g2[13]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[13]->GetMean());

    g1[14]->SetPoint(i, 1+i, ratiox15[i]->GetMean());
    g1[14]->SetPointError(i, 0, ratiox15[i]->GetRMS());
    g2[14]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[14]->GetMean());

    g1[15]->SetPoint(i, 1+i, ratiox16[i]->GetMean());
    g1[15]->SetPointError(i, 0, ratiox16[i]->GetRMS());
    g2[15]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[15]->GetMean());

    g1[16]->SetPoint(i, 1+i, ratiox17[i]->GetMean());
    g1[16]->SetPointError(i, 0, ratiox17[i]->GetRMS());
    g2[16]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[16]->GetMean());

    g1[17]->SetPoint(i, 1+i, ratiox18[i]->GetMean());
    g1[17]->SetPointError(i, 0, ratiox18[i]->GetRMS());
    g2[17]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[17]->GetMean());

    g1[18]->SetPoint(i, 1+i, ratiox19[i]->GetMean());
    g1[18]->SetPointError(i, 0, ratiox19[i]->GetRMS());
    g2[18]->SetPoint(i, 1+i, h1_ch[i]->GetMean()/h1_ch[18]->GetMean());


    if (shape_only){

      if (ratiox1[i]->GetRMS() && i != 10)
      value += TMath::Power(abs(ratiox1[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[0]->GetMean()) / (ratiox1[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox2[i]->GetRMS() && i != 1)
      value += TMath::Power(abs(ratiox2[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[1]->GetMean()) / (ratiox2[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox3[i]->GetRMS() && i != 2)
      value += TMath::Power(abs(ratiox3[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[2]->GetMean()) / (ratiox3[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox4[i]->GetRMS() && i != 3)
      value += TMath::Power(abs(ratiox4[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[3]->GetMean()) / (ratiox4[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox5[i]->GetRMS() && i != 4)
      value += TMath::Power(abs(ratiox5[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[4]->GetMean()) / (ratiox5[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox6[i]->GetRMS() && i != 5)
      value += TMath::Power(abs(ratiox6[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[5]->GetMean()) / (ratiox6[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox7[i]->GetRMS() && i != 6)
      value += TMath::Power(abs(ratiox7[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[6]->GetMean()) / (ratiox7[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox8[i]->GetRMS() && i != 7)
      value += TMath::Power(abs(ratiox8[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[7]->GetMean()) / (ratiox8[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox9[i]->GetRMS() && i != 8)
      value += TMath::Power(abs(ratiox9[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[8]->GetMean()) / (ratiox9[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox10[i]->GetRMS() && i != 9)
      value += TMath::Power(abs(ratiox10[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[9]->GetMean()) / (ratiox10[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox11[i]->GetRMS() && i != 10)
      value += TMath::Power(abs(ratiox11[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[10]->GetMean()) / (ratiox11[i]->GetRMS()* 1.4),1 ) ;

      if (ratiox12[i]->GetRMS() && i != 11)
      value += TMath::Power(abs(ratiox12[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[11]->GetMean()) / (ratiox12[i]->GetRMS()* 1.4),1 ) ;

      if (ratiox13[i]->GetRMS() && i != 12)
      value += TMath::Power(abs(ratiox13[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[12]->GetMean()) / (ratiox13[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox14[i]->GetRMS() && i != 13)
      value += TMath::Power(abs(ratiox14[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[13]->GetMean()) / (ratiox14[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox15[i]->GetRMS() && i != 14)
      value += TMath::Power(abs(ratiox15[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[14]->GetMean()) / (ratiox15[i]->GetRMS()* 1.4),1 ) ;

      if (ratiox16[i]->GetRMS() && i != 15)
      value += TMath::Power(abs(ratiox16[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[15]->GetMean()) / (ratiox16[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox17[i]->GetRMS() && i != 16)
      value += TMath::Power(abs(ratiox17[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[16]->GetMean()) / (ratiox17[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox18[i]->GetRMS() && i != 17)
      value += TMath::Power(abs(ratiox18[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[17]->GetMean()) / (ratiox18[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox19[i]->GetRMS() && i != 18)
      value += TMath::Power(abs(ratiox19[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[18]->GetMean()) / (ratiox19[i]->GetRMS()* 1.4),1 ) ;    

      if (ratiox20[i]->GetRMS() && i != 19)
      value += TMath::Power(abs(ratiox20[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[19]->GetMean()) / (ratiox20[i]->GetRMS()* 1.4),1 ) ;
/*
      if (ratiox21[i]->GetRMS() && i != 20)
      value += TMath::Power(abs(ratiox21[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[20]->GetMean()) / (ratiox21[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox22[i]->GetRMS() && i != 21)
      value += TMath::Power(abs(ratiox22[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[21]->GetMean()) / (ratiox22[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox23[i]->GetRMS() && i != 22)
      value += TMath::Power(abs(ratiox23[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[22]->GetMean()) / (ratiox23[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox24[i]->GetRMS() && i != 23)
      value += TMath::Power(abs(ratiox24[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[23]->GetMean()) / (ratiox24[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox25[i]->GetRMS() && i != 24)
      value += TMath::Power(abs(ratiox25[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[24]->GetMean()) / (ratiox25[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox26[i]->GetRMS() && i != 25)
      value += TMath::Power(abs(ratiox26[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[25]->GetMean()) / (ratiox26[i]->GetRMS()* 1.4),1 ) ;

      if (ratiox27[i]->GetRMS() && i != 26)
      value += TMath::Power(abs(ratiox27[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[26]->GetMean()) / (ratiox27[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox28[i]->GetRMS() && i != 27)
      value += TMath::Power(abs(ratiox28[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[27]->GetMean()) / (ratiox28[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox29[i]->GetRMS() && i != 28)
      value += TMath::Power(abs(ratiox29[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[28]->GetMean()) / (ratiox29[i]->GetRMS()* 1.4),1 ) ;
      if (ratiox30[i]->GetRMS() && i != 29)
      value += TMath::Power(abs(ratiox30[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[29]->GetMean()) / (ratiox30[i]->GetRMS()* 1.4),1 ) ;
*/
    }
    else {
      if (ratiox12[i]->GetRMS())
      value += TMath::Power(abs(ratiox12[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox12[i]->GetRMS()* 1.),1 ) ;
      if (ratiox13[i]->GetRMS())
      value += TMath::Power(abs(ratiox13[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox13[i]->GetRMS()* 1.),1 ) ;
      if (ratiox14[i]->GetRMS())
      value += TMath::Power(abs(ratiox14[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox14[i]->GetRMS()* 1.),1 ) ;
      if (ratiox15[i]->GetRMS())
      value += TMath::Power(abs(ratiox15[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox15[i]->GetRMS()* 1.),1 ) ;
      if (ratiox16[i]->GetRMS())
      value += TMath::Power(abs(ratiox16[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox16[i]->GetRMS()* 1.),1 ) ;
      if (ratiox17[i]->GetRMS())
      value += TMath::Power(abs(ratiox17[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox17[i]->GetRMS()* 1.),1 ) ;
      if (ratiox18[i]->GetRMS())
      value += TMath::Power(abs(ratiox18[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox18[i]->GetRMS()* 1.),1 ) ;
      if (ratiox19[i]->GetRMS())
      value += TMath::Power(abs(ratiox19[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox19[i]->GetRMS()* 1.),1 ) ;    

      if (ratiox20[i]->GetRMS())
      value += TMath::Power(abs(ratiox20[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox20[i]->GetRMS()* 1.),1 ) ;
      if (ratiox21[i]->GetRMS())
      value += TMath::Power(abs(ratiox21[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox21[i]->GetRMS()* 1.),1 ) ;
      if (ratiox22[i]->GetRMS())
      value += TMath::Power(abs(ratiox22[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox22[i]->GetRMS()* 1.),1 ) ;
      if (ratiox23[i]->GetRMS())
      value += TMath::Power(abs(ratiox23[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox23[i]->GetRMS()* 1.),1 ) ;
      if (ratiox24[i]->GetRMS())
      value += TMath::Power(abs(ratiox24[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox24[i]->GetRMS()* 1.),1 ) ;
      if (ratiox25[i]->GetRMS())
      value += TMath::Power(abs(ratiox25[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox25[i]->GetRMS()* 1.),1 ) ;
      if (ratiox26[i]->GetRMS())
      value += TMath::Power(abs(ratiox26[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()) / (ratiox26[i]->GetRMS()* 1.),1 ) ;
    }
    //cout<<"pmt 15 mc and data rates:   "<<ratiox15[i]->GetMean()<<" "<<h1_ch[15]->GetMean()<<endl;
    //cout<<"testing (1st same 2nd not): "<<ratiox12[i]->GetMean()<<" "<<h1_ch[12]->GetMean()<<endl;
    //cout<<" ::: base "<<i<<endl;
    //cout<<"original indpmt : "<<ratiox12[i]->GetMean()<<" "<<ratiox13[i]->GetMean()<<endl;
    //cout<<" updated        : "<<ratiox12[i]->GetMean()<<" "<<
    //cout<<"data point      : "<<h1_ch[i]->GetMean()/h1_ch[11]->GetMean()<<" "<<h1_ch[i]->GetMean()/h1_ch[12]->GetMean()<<endl;
    //cout<<"two pulls: "<<((RooAbsReal*)_pulls->at(11))->getVal() << " "<<((RooAbsReal*)_pulls->at(12))->getVal()<<endl;
    //cout<<"differences (value and chi2): "<<abs(ratiox12[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[11]->GetMean())<<" "<<abs(ratiox13[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[12]->GetMean())<<endl;
    //cout<<"                              "<<TMath::Power(abs(ratiox12[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[11]->GetMean()) / (ratiox12[i]->GetRMS()* 1.4),1 )<<" "<<abs(ratiox13[i] ->GetMean()*((RooAbsReal*)_pulls->at(30))->getVal() - h1_ch[i]->GetMean()/h1_ch[12]->GetMean()) / (ratiox13[i]->GetRMS()* 1.4)<<endl;
    //cout<<"middle "<<value<<endl;
  }

  cout<<"return value: "<<value<<endl;
  return value;
}




