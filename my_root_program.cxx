#include "my_root_program.h"
#include "TMath.h"

AHParticle::AHParticle() {
    px = 0.0;
    py = 0.0;
    pz = 0.0;
    magnitude = 0.0;  // You may initialize magnitude to zero by default
}

void AHParticle::SetPxPyPz(Double_t x, Double_t y, Double_t z) {
    px = x;
    py = y;
    pz = z;
    magnitude = TMath::Sqrt(px * px + py * py + pz * pz);
}

// Destructor
AHParticle::~AHParticle() {}
