/*
 *  BNL1T efficiency fit header file.
 *
 *  Author: Guang Yang
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <sstream>
#include <TList.h>

#include <TROOT.h>
#include <TCanvas.h>
#include <TApplication.h>
#include <TH1.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TFile.h>
#include <TRint.h>
#include <TH2.h>
#include <TFormula.h>
#include <TF1.h>
#include <TSpline.h>

#include <TF2.h>
#include <TMath.h>
#include <Math/DistFunc.h>
#include <TLine.h>
#include <TTree.h>
#include <TGraph.h>
#include <TRandom.h>
#include <TRandom2.h>
#include <TRandom3.h>
#include <TGraphErrors.h>
#include <TVirtualFFT.h>
#include <TFoamIntegrand.h>
#include <TMatrixD.h>
#include <TVectorT.h>
#include <TDecompChol.h>

#include <RooFit.h>
#include "RooGlobalFunc.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include "RooRealVar.h"
#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooDataSet.h"
#include "RooArgList.h"
#include "RooArgSet.h"
#include "RooGaussian.h"
#include "RooProdPdf.h"
#include "RooWorkspace.h"
#include "RooMinuit.h"
#include "RooNLLVar.h"
#include "RooFitResult.h"
#include "RooPlot.h"
#include "RooDataSet.h"
#include "RooExtendPdf.h"
#include "RooChi2Var.h"
#include "RooMinuit.h"
#include "RooDataHist.h"
#include "RooHistPdf.h"
#include "RooRandom.h"
#include <RooMsgService.h>
#include <RooHist.h>
#include <RooTrace.h>
#include <RooCategory.h>
#include "RooConstVar.h"
#include "RooBinning.h"
#include "TStopwatch.h"
#include "TFile.h"
#include "TMinuit.h"
#include "TGraph2D.h"

#include "RooFit.h"
#include "RooMinuit.h"
#include "RooFitResult.h"
#include "TMinuit.h"
#include <RooRealVar.h>

using namespace RooFit;

  class bnlFit : public RooAbsReal {

  public:

    bnlFit (const char* name);

    bnlFit (const bnlFit & other, const char* name = 0): RooAbsReal(other,name) {};
    virtual TObject* clone(const char* newname) const {return new bnlFit (*this, newname);};
    virtual ~bnlFit () ;
    bnlFit (const bnlFit & bnlFit );

    bnlFit & operator=(const bnlFit & rhs);

    RooFormulaVar* Chi2() ;

    Double_t FillEv(RooListProxy* _pulls) const;

    void Fillup(RooListProxy* _pulls);

    Double_t ExtraPull(RooListProxy* _pulls) const;

    void setPull(TH1D* pullvecCV) ;
    void setPullUnc(TH1D* pullvecUnc) ;
    Double_t getPullUnc(Int_t pN) ;

    RooRealVar Par1 ;
    RooRealVar Par2 ;
    RooRealVar Par3 ;
    RooRealVar Par4 ;
    RooRealVar Par5 ;
    RooRealVar Par6 ;
    RooRealVar Par7 ;
    RooRealVar Par8 ;
    RooRealVar Par9 ;

    Double_t _par1;
    Double_t _par2;
    Double_t _par3;
    Double_t _par4;
    Double_t _par5;
    Double_t _par6;
    Double_t _par7;
    Double_t _par8;
    Double_t _par9;
    
    bool shape_only;
    double _data_rate;
    void set_shape_only(bool shapeonly=false) {shape_only = shapeonly;}
    void set_data_rate(double rate = 1e9) {_data_rate = rate;}

    Double_t getPar(int i) ;

    RooRealVar* getParVar(int i) ;
    RooListProxy* getParVar() ;

    RooArgList _parlist;
    RooListProxy* _pulls;

    TVectorD* pullCV;
    TVectorD* pullUnc;
    void setup() const;

    RooListProxy* getPullList() const { return _pulls; }

    TH1F* ratiox1[30];
    TH1F* ratiox2[30];
    TH1F* ratiox3[30];
    TH1F* ratiox4[30];
    TH1F* ratiox5[30];
    TH1F* ratiox6[30];
    TH1F* ratiox7[30];
    TH1F* ratiox8[30];
    TH1F* ratiox9[30];
    TH1F* ratiox10[30];
    TH1F* ratiox11[30];
    TH1F* ratiox12[30];
    TH1F* ratiox13[30];
    TH1F* ratiox14[30];
    TH1F* ratiox15[30];
    TH1F* ratiox16[30];
    TH1F* ratiox17[30];
    TH1F* ratiox18[30];
    TH1F* ratiox19[30];
    TH1F* ratiox20[30];
    TH1F* ratiox21[30];
    TH1F* ratiox22[30];
    TH1F* ratiox23[30];
    TH1F* ratiox24[30];
    TH1F* ratiox25[30];
    TH1F* ratiox26[30];
    TH1F* ratiox27[30];
    TH1F* ratiox28[30];
    TH1F* ratiox29[30];
    TH1F* ratiox30[30];
    TH1F* h1_ch[30];

    //in data
    double adc_b1_ch12[50] = {0.,   0.,   0.,   0.,  27., 319., 649., 492., 205.,  89.,  21.,
           4.,   2.,   0.,   1.,   0.,   2.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch13[50] = { 0.,   0.,   0.,   0.,   0.,  29., 141., 280., 414., 362., 264.,
         178.,  72.,  33.,  15.,  16.,   2.,   3.,   1.,   1.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch14[50] = {0.,   0.,   0.,   0.,   0.,  10.,  25.,  62., 105., 174., 249.,
         232., 221., 185., 139., 103.,  82.,  53.,  38.,  33.,  26.,  17.,
          14.,  12.,   7.,   7.,   7.,   4.,   3.,   0.,   0.,   1.,   1.,
           0.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch15[50] = {0.,   0.,   0.,   0.,   2.,   2.,  16.,  67.,  85., 107., 150.,
         169., 160., 131., 133., 121., 110.,  94.,  81.,  77.,  60.,  59.,
          38.,  35.,  20.,  15.,  15.,  20.,  13.,   7.,   4.,   4.,   3.,
           2.,   0.,   1.,   2.,   3.,   1.,   2.,   0.,   0.,   0.,   1.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch0[50] = {0.,   0.,   0.,   0.,   1.,  11.,  37., 130., 189., 238., 213.,
         230., 187., 165.,  91.,  87.,  62.,  53.,  31.,  18.,  21.,  11.,
           9.,   6.,   9.,   2.,   1.,   0.,   2.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   1.,   1.,   0.,   0.,   0.,   0.,   1.,   0.,
           0.,   1.,   0.,   0.,   0.,   0.};
    double adc_b2_ch1[50] = {0.,   0.,   0.,   0.,   2.,   5.,  21.,  38.,  89., 131., 206.,
         222., 231., 205., 165., 142.,  93.,  68.,  58.,  44.,  28.,  23.,
          11.,   3.,   3.,   3.,   1.,   1.,   1.,   1.,   2.,   0.,   3.,
           1.,   1.,   1.,   0.,   0.,   1.,   0.,   0.,   0.,   1.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch2[50] = {0.,   0.,   0.,   0.,   2.,  11.,  62., 171., 269., 362., 330.,
         227., 174.,  95.,  52.,  19.,  15.,   8.,   3.,   2.,   3.,   1.,
           0.,   3.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch3[50] = {0.,   0.,   0.,   0.,   2.,  17., 109., 257., 382., 374., 300.,
         185.,  91.,  47.,  24.,  10.,   4.,   2.,   3.,   0.,   0.,   0.,
           2.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};


    double adc_b1_ch1[50] = { 0.,   0.,   0.,   0.,   1.,  18., 108., 235., 313., 370., 294.,
         212., 125.,  72.,  33.,  14.,   6.,   4.,   4.,   1.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch2[50] = {0.,   0.,   0.,   0.,   0.,  15.,  50., 179., 276., 371., 352.,
         232., 164.,  95.,  37.,  19.,   9.,   7.,   1.,   3.,   0.,   0.,
           0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch3[50] = {0.,   0.,   0.,   0.,   1.,   7.,  35., 124., 241., 304., 359.,
         299., 181., 138.,  61.,  35.,  13.,   3.,   4.,   2.,   0.,   1.,
           0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch4[50] = {0.,   0.,   0.,   0.,   3.,  88., 315., 459., 406., 261., 154.,
          81.,  22.,  12.,   4.,   2.,   1.,   0.,   0.,   1.,   0.,   0.,
           0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch5[50] = {0.,   0.,   0.,   0.,   0.,  57., 193., 349., 428., 384., 218.,
         108.,  41.,  22.,   7.,   4.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch6[50] = {0.,   0.,   0.,   0.,   3.,  38., 223., 404., 434., 370., 193.,
          95.,  35.,  14.,   2.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch7[50] = {0.,   0.,   0.,   0.,   2.,  21., 104., 248., 370., 391., 308.,
         180., 102.,  48.,  22.,   5.,   6.,   3.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   1.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b1_ch8[50] = {0.,   0.,   0.,   0.,   1.,   9.,  23.,  68., 136., 204., 259.,
         250., 255., 200., 152.,  93.,  59.,  38.,  25.,  12.,   5.,   5.,
           5.,   1.,   1.,   2.,   0.,   0.,   1.,   1.,   0.,   0.,   0.,
           0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   2.,   0};
    double adc_b1_ch9[50] = {0.,   0.,   0.,   0.,   1.,   4.,   2.,   7.,  28.,  42.,  95.,
         118., 186., 195., 233., 195., 155., 134.,  90.,  64.,  56.,  55.,
          29.,  13.,  15.,  12.,   7.,   7.,   2.,   8.,   3.,   3.,   2.,
           5.,   6.,   2.,   3.,   2.,   3.,   3.,   3.,   1.,   0.,   1.,
           7.,   0.,   1.,   0.,   0.,   1.};
    double adc_b1_ch10[50] = { 0.,   0.,   0.,   0.,   1.,  29.,   8.,  31.,  85., 163., 242.,
         281., 261., 187., 157., 103.,  86.,  58.,  33.,  24.,   7.,  10.,
           6.,   7.,   6.,   4.,   2.,   2.,   1.,   1.,   0.,   2.,   2.,
           0.,   2.,   0.,   1.,   1.,   0.,   1.,   1.,   1.,   0.,   0.,
           0.,   1.,   0.,   0.,   0.,   0.};
    double adc_b1_ch11[50] = {0.,   0.,   0.,   0.,   2.,   1.,   8.,  51., 138., 238., 318.,
         317., 237., 165., 118.,  89.,  59.,  29.,  12.,  10.,   4.,   5.,
           2.,   1.,   2.,   0.,   1.,   1.,   1.,   0.,   0.,   0.,   1.,
           0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch4[50] = {0.,   0.,   0.,   0.,  35., 385., 584., 448., 238.,  96.,  20.,
           5.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch5[50] = {0.,   0.,   0.,   0.,   6., 132., 324., 446., 371., 237., 135.,
          79.,  39.,  25.,   7.,   5.,   1.,   1.,   2.,   1.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch6[50] = { 0.,   0.,   0.,   0.,   2.,  10.,  31.,  63., 126., 201., 216.,
         204., 174., 167., 113.,  88.,  83.,  70.,  48.,  45.,  39.,  30.,
          20.,  15.,  19.,  18.,   3.,   8.,   4.,   4.,   1.,   3.,   2.,
           2.,   1.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch7[50] = {0.,   0.,   0.,   0.,   3.,  33., 134., 239., 347., 317., 253.,
         146., 101.,  69.,  48.,  30.,  25.,  11.,  13.,   4.,  15.,   3.,
           4.,   8.,   1.,   1.,   4.,   0.,   0.,   0.,   1.,   1.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch8[50] = {0.,   0.,   0.,   0.,   0.,   3.,   8.,  25.,  66., 137., 199.,
         226., 239., 240., 191., 148., 123.,  93.,  47.,  26.,  15.,   9.,
           5.,   5.,   5.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch9[50] = { 0.,   0.,   0.,   0.,   3.,  92., 375., 509., 436., 233., 106.,
          39.,   8.,   3.,   6.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch10[50] = {0.,   0.,   0.,   0.,   4.,  48., 250., 438., 460., 310., 169.,
          84.,  27.,  15.,   4.,   0.,   2.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch11[50] = {0.,   0.,   0.,   0.,  30., 421., 620., 463., 201.,  55.,  17.,
           3.,   1.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch12[50] = {0.,   0.,   0.,   0.,  12., 238., 502., 528., 312., 147.,  50.,
          18.,   2.,   2.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch13[50] = {0.,   0.,   0.,   0.,   8., 120., 364., 569., 411., 224.,  77.,
          20.,  11.,   3.,   2.,   0.,   0.,   2.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};
    double adc_b2_ch14[50] = {0.,   0.,   0.,   0.,   2.,  82., 363., 490., 416., 286., 109.,
          44.,  16.,   0.,   2.,   0.,   0.,   0.,   1.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,   0.,
           0.,   0.,   0.,   0.,   0.,   0.};

    //  private:

   virtual  Double_t evaluate() const;

   protected:
  };

