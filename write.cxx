#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"  
#include "TRandom3.h"
#include "root2.h"  

void write() {
    // Initialize your object as a pointer
    particle* obj = new particle();

    // Create your ROOT file
    TFile* file = new TFile("tree_file.root", "RECREATE");

    // Create your TTree
    TTree* tree = new TTree("tree", "My TTree");

    // Add branches to the TTree
    tree->Branch("myObject", "particle", &obj);

    // Define the number of events you want
    Int_t nEvents = 100;  // For example

    for (Int_t i = 0; i < nEvents; i++) {
        // Create a new particle object in each iteration
        particle* obj = new particle();
        
        // Generate random momentum values
        Double_t px = gRandom->Gaus(0, 0.02);
        Double_t py = gRandom->Gaus(0, 0.02);
        Double_t pz = gRandom->Gaus(0, 0.02);

        // Set the momentum values in your object
        obj->SetPxPyPz(px, py, pz);

        // Calculate and print the magnitude of the momentum vector
        Double_t magnitude = obj->GetMagnitude();
        std::cout << "Event " << i << " - Momentum Magnitude: " << magnitude << std::endl;

        // Fill the tree with the object
        tree->Fill();

        // Don't forget to delete the object to avoid memory leaks
        delete obj;
    }

    // Write the TTree to the ROOT file
    file->Write();

    // Close the ROOT file
    file->Close();

}

