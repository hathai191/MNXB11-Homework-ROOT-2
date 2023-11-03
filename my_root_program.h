#ifndef __MY_ROOT_2_H__
#define __MY_ROOT_2_H__

#include "TObject.h"

class AHParticle : public TObject {
public:
    AHParticle(); // default constructor
    AHParticle(Double_t px, Double_t py, Double_t pz); // constructor with momentum
    virtual ~AHParticle(); // destructor

    Double_t GetPx() const { return px; }
    Double_t GetPy() const { return py; }
    Double_t GetPz() const { return pz; }

    Double_t GetMagnitude() const { return magnitude; }

    void SetPxPyPz(Double_t px, Double_t py, Double_t pz);

private:
    Double_t px;  
    Double_t py;  
    Double_t pz;  
    Double_t magnitude; 

    ClassDef(AHParticle, 1); 
};

#endif // __MY_ROOT_2_H__

