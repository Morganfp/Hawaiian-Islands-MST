/*
* FILE: PhoneLine.cpp
* AUTHOR: Morgan Purcell
* DATE: 04/2023
* PURPOSE: Define PhoneLine methods
*/

// Import the necessary header files
#include "PhoneLine.hpp"

// Recursive method to find the 'root' node
PhoneLine& 
PhoneLine::forestParent()
{
    if (_parent == this)
        return *this; // This is the root of the forest
    else 
        // Recursively call forestParent() on the parent
        return _parent->forestParent();
}
