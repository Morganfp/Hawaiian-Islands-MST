/*
* FILE: PhoneLine.hpp
* AUTHOR: Morgan Purcell
* DATE: 04/2023
* PURPOSE: Describes a phone line between two islands
*/

#ifndef _PHONE_LINE_HPP_
#define _PHONE_LINE_HPP_

// Include the necessary libraries
#include <string>

class PhoneLine
{
private:
    std::string _islandOne;
    std::string _islandTwo;
    int _distance;
    PhoneLine *_parent;
    int _rank;

public:
    // Default constructor
    // PhoneLine(std::string islandOne, std::string islandTwo, int distance) { _islandOne = islandOne; _islandTwo = islandTwo; _distance = distance; }
    PhoneLine(std::string islandOne, std::string islandTwo, int distance) : _islandOne(islandOne), _islandTwo(islandTwo), _distance(distance), _rank(0) {}

    // Accessor methods
    std::string islandOne() { return _islandOne; }
    std::string islandTwo() { return _islandTwo; }
    int distance() { return _distance; }
    PhoneLine& parent() { return *_parent; }
    int rank() { return _rank; }
    PhoneLine& forestParent();

    // Modifier method
    void setParent(PhoneLine& parent) { _parent = &parent; }
};


#endif
