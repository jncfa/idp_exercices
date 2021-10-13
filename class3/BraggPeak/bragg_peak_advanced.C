#include "TROOT.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TH2F.h"

void bragg_peak_advanced(){
    
    TCanvas *c1 = new TCanvas();
    
    TTree *bragg = new TTree("Bragg Peak","Bragg Peak");
    bragg->ReadFile("BraggPeak.out","length:edep:step");
    
    TH2F *h200 = new TH2F("h200","Bragg Peak for alpha particles",100,0.,5.,100,0.,3.5);
    bragg->Draw("edep/step:length>>h200","","colz");
    h200->GetXaxis()->SetTitle("Range (cm)");
    h200->GetYaxis()->SetTitle("dE/dx (MeV/cm)");
    c1->SetLogz();
    c1->SaveAs("BraggPeak.pdf");
/*
    TH2F *h201 = new TH2F("h201","Energy loss for alpha particles",100,0.,6.,100,0.,3.5);
    bragg->Draw("edep/step:e>>h201","","col");
    h201->GetXaxis()->SetTitle("Energy (MeV)");
    h201->GetYaxis()->SetTitle("dE/dx (MeV/cm)");
    c1->SaveAs("EnergyLoss.pdf");
*/
    
}
