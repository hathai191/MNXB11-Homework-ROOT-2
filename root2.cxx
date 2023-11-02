#include "root2.h"  // Include the header file that declares your_class

// Default constructor
your_class::your_class() : TObject() {
    // Initialize your class members here, e.g., set the initial values
}

// Another constructor
your_class::your_class(Int_t variable) : TObject() {
    // Initialize your class members here based on the "variable" argument
}

// Destructor
your_class::~your_class() {
    // Implement any necessary cleanup or resource management here
}

ClassImp(your_class); 