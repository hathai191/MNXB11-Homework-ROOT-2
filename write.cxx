#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"  
#include "TRandom3.h"
#include "my_root_program.h"  

void write() {
    TFile* file = new TFile("tree_file.root", "RECREATE");
    TTree* tree = new TTree("tree", "My TTree");
    
    AHParticle* obj = new AHParticle(); 
    
    tree->Branch("myObject", "AHParticle", &obj);
    
    Int_t nEvents = 100;  

    for (Int_t i = 0; i < nEvents; i++) {
        Double_t px = gRandom->Gaus(0, 0.02);
        Double_t py = gRandom->Gaus(0, 0.02);
        Double_t pz = gRandom->Gaus(0, 0.02);

        obj->SetPxPyPz(px, py, pz);

        Double_t magnitude = obj->GetMagnitude();
        std::cout << "Event " << i << " - Momentum Magnitude: " << magnitude << std::endl;

        tree->Fill();
    }

    file->Write();
    file->Close();
}

