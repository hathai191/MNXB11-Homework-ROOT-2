#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TBrowser.h"
#include "root2.h"

void read() {
    // Initialize your object
    particle* my_particle = new particle();

    // Open your file
    TFile* file = new TFile("tree_file.root", "READ");

    // Get your TTree
    TTree* tree = (TTree*)file->Get("tree");

    // Set the branch address
    tree->SetBranchAddress("myObject", &my_particle);

    // Create a TH2 histogram for px and py
    TH2F* hist = new TH2F("hist", "Momentum Distribution;px;py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    // Loop over the entire tree
    Int_t N = tree->GetEntries();
    for (Int_t i = 0; i < N; i++) {
        tree->GetEntry(i);

        // Access the px and py values from the my_particle object
        Double_t px = my_particle->GetPx();
        Double_t py = my_particle->GetPy();

        // Fill the TH2 histogram
        hist->Fill(px, py);
    }

    // Create a canvas to draw the histogram
    TCanvas* c1 = new TCanvas("c1", "Momentum Distribution");
    hist->Draw("COLZ");

    // Save the histogram as a PNG
    c1->SaveAs("momentum_distribution.png");

    // Clean up
    delete my_particle;
    file->Close();
}


