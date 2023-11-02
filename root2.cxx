#include "root2.h"
#include "TMath.h"

// Constructor
particle::particle(Double_t x, Double_t y, Double_t z) : TObject() {
    px = x;
    py = y;
    pz = z;
    magnitude = TMath::Sqrt(px * px + py * py + pz * pz);
}

void particle::SetPxPyPz(Double_t x, Double_t y, Double_t z) {
    px = x;
    py = y;
    pz = z;
    magnitude = TMath::Sqrt(px * px + py * py + pz * pz);
}

// Destructor
particle::~particle() {}
