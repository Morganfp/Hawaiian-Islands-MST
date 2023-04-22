/*
* FILE: main.cpp
* AUTHOR: Morgan Purcell
* DATE: 04/2023
* PURPOSE: main function for finding the minimum spanning tree
*/

// Include the necessary libraries
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "PhoneLine.cpp"


int main(int argc, char **argv)
{
    // Pull the name of the input file from the command line
    std::ifstream ifile(argv[1]);

    // If the file couldn't be opened, alert the user
    if (!ifile.is_open())
    {
        std::cerr << "Error: couldn't open file";
        return 1;
    }
    else
    {
        // Vector to hold the phone line objects
        std::vector<PhoneLine> lines;

        // Variables to hold the island names and distance between them
        std::string islandOne, islandTwo;
        int distance;

        // Iterate over the input file
        while(ifile)
        {
            // Initalize the variables with the file data
            ifile >> islandOne >> islandTwo >> distance;
            // Push a PhoneLine object into the vector
            lines.push_back(PhoneLine(islandOne, islandTwo, distance));
        }
    }


    return 0;
}
