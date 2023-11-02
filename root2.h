#ifndef __MY_ROOT_2_H__
#define __MY_ROOT_2_H__

#include "TObject.h"

class your_class : public TObject {
public:
    your_class(); // default constructor
    your_class(Int_t variable); // some other constructor
    virtual ~your_class(); // destructor

private:
    // some private members

    ClassDef(your_class, 1); // your_class
};

#endif // __MY_ROOT_2_H__
