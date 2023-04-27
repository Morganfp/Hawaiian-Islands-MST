/*
* FILE: PhoneLine.hpp
* AUTHOR: Morgan Purcell
* DATE: 04/2023
* PURPOSE: Describes an individual island
*/

#ifndef _Island_HPP_
#define _Island_HPP_

// Include the necessary libraries
#include <string>


class Island
{
private:
    // Instance variables
    std::string _islandName;
    Island *_parent;
    int _rank;

public:
    // Default constructor
    Island(std::string islandName) : _islandName(islandName), _rank(0) {}

    // Accessor methods
    std::string islandName() { return _islandName; }
    Island& parent() { return *_parent; }
    int& rank() { return _rank; }
    Island& findRoot();

    // Modifier method to set an islands parent
    void setParent(Island& parent) { _parent = &parent; }
};


#endif
