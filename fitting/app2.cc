#include "bnlFit.hh"
#include "TMath.h"
#include "TH3F.h"

#include "RooArgList.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include "RooRealVar.h"
#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "TString.h"
#include "TVector3.h"
#include <TVectorD.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TFrame.h>

using namespace std;

int main(int argc, char**argv){

  cout<<"starting.."<<endl;

  RooFitResult* res;
  char formula[10];
  bnlFit * rep = new bnlFit ("_rep");

  rep->setup();

  RooArgList list("list");
  list.add(*rep);
  sprintf(formula,"%s","@0");
  RooFormulaVar* fcn = new RooFormulaVar("fit","fit",formula,list);

  rep->getParVar(0)->setConstant(false);
  rep->getParVar(1)->setConstant(false);
  rep->getParVar(2)->setConstant(false);
  rep->getParVar(3)->setConstant(false);
  rep->getParVar(4)->setConstant(false);
  rep->getParVar(5)->setConstant(false);
  rep->getParVar(6)->setConstant(false);
  rep->getParVar(7)->setConstant(false);
  rep->getParVar(8)->setConstant(false);
  rep->getParVar(9)->setConstant(false);
  rep->getParVar(10)->setConstant(false);
  rep->getParVar(11)->setConstant(true);
  rep->getParVar(12)->setConstant(false);
  rep->getParVar(13)->setConstant(false);
  rep->getParVar(14)->setConstant(false);
  rep->getParVar(15)->setConstant(false);
  rep->getParVar(16)->setConstant(false);
  rep->getParVar(17)->setConstant(false);
  rep->getParVar(18)->setConstant(false);

  rep->getParVar(19)->setConstant(false);

  rep->getParVar(20)->setConstant(true);
  rep->getParVar(21)->setConstant(true);
  rep->getParVar(22)->setConstant(true);
  rep->getParVar(23)->setConstant(true);
  rep->getParVar(24)->setConstant(true);
  rep->getParVar(25)->setConstant(true);

  rep->getParVar(26)->setConstant(true);
  rep->getParVar(27)->setConstant(true);
  rep->getParVar(28)->setConstant(true);
  rep->getParVar(29)->setConstant(true);
  rep->getParVar(30)->setConstant(true);

  rep->set_shape_only(true);

  RooMinuit m(*fcn);
  m.setStrategy(2);
  Double_t callsEDM[2] = {10500., 1.e-6};
  Int_t irf = 0;

  cout<<"ready to perform the fit"<<endl;
  gMinuit->mnexcm("MIGRAD",callsEDM,2,irf);
  m.migrad();
  m.hesse();
  //m.minos();
  res = m.save();
  double bestFit = res->minNll();
  std::cout<<"fit status code is : "<< res->status()<<std::endl;
  // total number of data events: 1811
}
