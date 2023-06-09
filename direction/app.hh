using namespace std;
double mcx;
double mcy;
double mcz;
double mcu;
double mcv;
double mcw;
double mcke;
int evid;
int subev;
long nanotime;
int mcpcount;
int mcpecount;
int mcnhits;
int nentries;
std::vector<int>* pdgcodes;
std::vector<double>* mcKEnergies;
std::vector<double>* mcPosx;
std::vector<double>* mcPosy;
std::vector<double>* mcPosz;
std::vector<double>* mcDirx;
std::vector<double>* mcDiry;
std::vector<double>* mcDirz;
std::vector<int>*  hitPMTID;
std::vector<double>* hitPMTTime;
std::vector<double>* hitPMTDigitizedTime;
std::vector<double>* hitPMTCharge;
std::vector<double>* hitPMTDigitizedCharge;
std::vector<int>* mcPMTID;
std::vector<int>* mcPEIndex;
std::vector<double>* mcPETime;
std::vector<int>* mcPEProcess;
TTree* ttree;

void read_ntuple(std::string str){
  TFile ftemp(str.c_str());
  ttree = (TTree*)ftemp.Get("output");
  nentries = ttree->GetEntries();
  ttree->Print();
  ttree->SetBranchAddress("mcx", &mcx);
  ttree->SetBranchAddress("mcy", &mcy);
  ttree->SetBranchAddress("mcz", &mcz);
  ttree->SetBranchAddress("mcu", &mcu);
  ttree->SetBranchAddress("mcv", &mcv);
  ttree->SetBranchAddress("mcw", &mcw);
  ttree->SetBranchAddress("mcke", &mcke);
  ttree->SetBranchAddress("evid", &evid);
  ttree->SetBranchAddress("subev", &subev);
  ttree->SetBranchAddress("nanotime", &nanotime);
  ttree->SetBranchAddress("mcpcount", &mcpcount);
  ttree->SetBranchAddress("mcpecount", &mcpecount);
  ttree->SetBranchAddress("mcnhits", &mcnhits);
  ttree->SetBranchAddress("pdgcodes", &pdgcodes);
  ttree->SetBranchAddress("mcKEnergies", &mcKEnergies);
  ttree->SetBranchAddress("mcPosx", &mcPosx);
  ttree->SetBranchAddress("mcPosy", &mcPosy);
  ttree->SetBranchAddress("mcPosz", &mcPosz);
  ttree->SetBranchAddress("mcDirx", &mcDirx);
  ttree->SetBranchAddress("mcDiry", &mcDiry);
  ttree->SetBranchAddress("mcDirz", &mcDirz);
  ttree->SetBranchAddress("hitPMTID", &hitPMTID);
  ttree->SetBranchAddress("hitPMTTime", &hitPMTTime);
  ttree->SetBranchAddress("hitPMTDigitizedTime", &hitPMTDigitizedTime);
  ttree->SetBranchAddress("hitPMTCharge", &hitPMTCharge);
  ttree->SetBranchAddress("hitPMTDigitizedCharge", &hitPMTDigitizedCharge);
  ttree->SetBranchAddress("mcPMTID", &mcPMTID);
  ttree->SetBranchAddress("mcPEIndex", &mcPEIndex);
  ttree->SetBranchAddress("mcPETime", &mcPETime);
  ttree->SetBranchAddress("mcPEProcess", &mcPEProcess);
}
