#include "root2.h"

// Default constructor
particle::particle() : TObject(), px(0), py(0), pz(0) {
    // Initialize all members to zero in the default constructor
}

// Constructor with momentum
particle::particle(Double_t px, Double_t py, Double_t pz) : TObject(), px(px), py(py), pz(pz) {
    // Calculate the magnitude
    magnitude = TMath::Sqrt(px * px + py * py + pz * pz);
}

// Destructor
particle::~particle() {
    // Implement any necessary cleanup or resource management here
}

