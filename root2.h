#ifndef __MY_ROOT_2_H__
#define __MY_ROOT_2_H__

#include "TObject.h"

class particle : public TObject {
public:
    particle(); // default constructor
    particle(Double_t px, Double_t py, Double_t pz); // constructor with momentum
    virtual ~particle(); // destructor

    Double_t GetPx() const { return px; }
    Double_t GetPy() const { return py; }
    Double_t GetPz() const { return pz; }

    Double_t GetMagnitude() const { return magnitude; }

private:
    Double_t px;  // Member for momentum in x direction
    Double_t py;  // Member for momentum in y direction
    Double_t pz;  // Member for momentum in z direction
    Double_t magnitude; // Member for the magnitude of the momentum vector

    ClassDef(particle, 1); // particle
};

#endif // __MY_ROOT_2_H__
