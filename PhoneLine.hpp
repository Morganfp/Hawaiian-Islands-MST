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
    // Instance variables
    std::string _islandOne;
    std::string _islandTwo;
    int _distance;
 

public:
    // Default constructor
    PhoneLine(std::string islandOne, std::string islandTwo, int distance) : _islandOne(islandOne), _islandTwo(islandTwo), _distance(distance) {}

    // Accessor methods
    std::string islandOne() { return _islandOne; }
    std::string islandTwo() { return _islandTwo; }
    int distance() { return _distance; }
};


#endif
