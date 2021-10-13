#include "TROOT.h"
#include "TTree.h"
#include "TH2F.h"

void bragg_peak(){
    TTree *bragg = new TTree("Bragg Peak","Bragg Peak");
    bragg->ReadFile("BraggPeak.out","length:edep:step:e");
    
    bragg->Draw("edep/step:length");
    
}
