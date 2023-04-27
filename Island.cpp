/*
* FILE: PhoneLine.cpp
* AUTHOR: Morgan Purcell
* DATE: 04/2023
* PURPOSE: Define Island methods
*/

// Import the necessary header files
#include "Island.hpp"

// Recursive method to find the root node
Island& 
Island::findRoot()
{
    // Check if the islands parent is itself
    if (_parent == this)
        return *this;
    else 
        // Recursively call findRoot() on the parent
        return _parent->findRoot();
}
