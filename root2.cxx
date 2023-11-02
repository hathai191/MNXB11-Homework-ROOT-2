#include "root2.h"
#include "TMath.h"

// Constructor with momentum components
particle::particle(Double_t x, Double_t y, Double_t z) : TObject() {
    px = x;
    py = y;
    pz = z;
    magnitude = TMath::Sqrt(px * px + py * py + pz * pz);
}

// Setter method for momentum components
void particle::SetPxPyPz(Double_t x, Double_t y, Double_t z) {
    px = x;
    py = y;
    pz = z;
    magnitude = TMath::Sqrt(px * px + py * py + pz * pz);
}

// Destructor
particle::~particle() {
    // Implement any necessary cleanup or resource management here
}
