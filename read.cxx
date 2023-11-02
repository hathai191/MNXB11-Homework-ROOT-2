#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TBrowser.h"
#include "root2.h"

void read() {
    particle* my_particle = new particle();

    TFile* file = new TFile("tree_file.root", "READ");

    TTree* tree = (TTree*)file->Get("tree");

    tree->SetBranchAddress("myObject", &my_particle);

    TH2F* hist_momentum = new TH2F("hist_momentum", "Momentum Distribution;px;py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    TH2F* hist_scatter = new TH2F("hist_scatter", "Scatter Plot;px*py;pz", 100, -0.02, 0.02, 100, -0.02, 0.02);

    TString cut = "my_particle.GetMagnitude() > 0.01";

    tree->Draw("px*py:pz", cut);

    Int_t N = tree->GetEntries();
    for (Int_t i = 0; i < N; i++) {
        tree->GetEntry(i);

        Double_t px = my_particle->GetPx();
        Double_t py = my_particle->GetPy();
        Double_t pz = my_particle->GetPz();

        hist_momentum->Fill(px, py);

        hist_scatter->Fill(px * py, pz);
    }

    TCanvas* c1 = new TCanvas("c1", "Momentum Distribution");
    TCanvas* c2 = new TCanvas("c2", "Scatter Plot");

    c1->cd();
    hist_momentum->Draw("COLZ");

    c2->cd();
    hist_scatter->Draw("COLZ");

    c1->SaveAs("momentum_distribution.png");
    c2->SaveAs("scatter_plot.png");

    delete my_particle;
    file->Close();
}
