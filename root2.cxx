#include "root2.h"  // Include the header file that declares your_class

// default constructor
your_class::your_class() : TObject(), variable(0) {
    // Initialize your class members here, e.g., set the initial values
}

// another constructor
your_class::your_class(Int_t variable) : TObject(), variable(variable) {
    // Initialize your class members here based on the "variable" argument
}

// destructor
your_class::~your_class() {
    // Implement any necessary cleanup or resource management here
}
