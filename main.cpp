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
// Include the necessary header files
#include "PhoneLine.hpp"
#include "mergeSort.hpp"


int findMST(std::vector<PhoneLine> &lines)
{   
    // The mst cost
    int cost = 0;

    // Find it
    

    // Return the mst cost
    return cost;
}


int main(int argc, char **argv)
{
    // Pull the name of the input file from the command line
    // std::ifstream ifile(argv[1]);
    std::ifstream ifile("if.txt");

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
        while(ifile >> islandOne >> islandTwo >> distance)
        {
            // Push a PhoneLine object into the vector
            PhoneLine* line = new PhoneLine(islandOne, islandTwo, distance);
            line->setParent(*line);
            lines.push_back(*line);
        }

        // for (PhoneLine l : lines)
        // {
        //     std::cout << l.islandOne() << " " << l.islandTwo() << " - " << l.distance() << "\n";
        // }

        // std::cout << "-----------------------\n";
        // Sort the phone lines by distance
        mergeSort(lines);

        for (PhoneLine l : lines)
        {
            std::cout << l.islandOne() << " " << l.islandTwo() << " - " << l.distance() << "\n";
        }
        std::cout << "\n\n";

        std::cout << lines[0].islandOne() << " " << lines[0].islandTwo() << " - " << lines[0].distance() << "\n";
        std::cout << lines[0].parent().islandOne() << " " << lines[0].parent().islandTwo() << " - " << lines[0].parent().distance() << "\n";
        lines[0].setParent(lines[1]);
        std::cout << lines[0].parent().islandOne() << " " << lines[0].parent().islandTwo() << " - " << lines[0].parent().distance() << "\n";
        std::cout << lines[0].parent().parent().islandOne() << " " << lines[0].parent().parent().islandTwo() << " - " << lines[0].parent().parent().distance() << "\n";
        lines[1].setParent(lines[2]);
        lines[2].setParent(lines[3]);
        std::cout << lines[0].parent().parent().islandOne() << " " << lines[0].parent().parent().islandTwo() << " - " << lines[0].parent().parent().distance() << "\n";
        std::cout << lines[0].forestParent().islandOne() << " " << lines[0].forestParent().islandTwo() << " - " << lines[0].forestParent().distance() << "\n";
        // std::cout << lines[2].islandOne() << " " << lines[2].islandTwo() << " - " << lines[2].distance() << "\n";


        // std::cout << findMST(lines);
    }


    return 0;
}
