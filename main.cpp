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
#include "Island.hpp"
#include "mergeSort.hpp"


// Check if an island from the PhoneLines object is already in the islands vector
// Return the index of the island in the island vector or 0 if the island was not found in the islands vector
int islandInPhonelines(std::vector<Island> &islands, std::string islandName)
{
    int i = 0;
    for (Island island : islands)
    {
        if (islandName == island.islandName())
            return i;
        i+=1;
    }

    // The island was not found
    return -1;
}


// A function for finding the MST cost
int findMST(std::vector<PhoneLine> &lines)
{   
    // The MST cost
    int cost = 0;
    // Number of edges processed
    int m = 0;

    // Vector to hold individual islands
    std::vector<Island> islands;

    // Iterate through the PhoneLine objects in the lines vector
    for (PhoneLine& line : lines)
    {
        // If n-1 edges have been processed, the MST has been found
        m+=1;
        if (m == lines.size()-1)
            return cost;

        // If islandOne hasn't been added to the islands vector yet, add it
        if (islandInPhonelines(islands, line.islandOne()) == -1)
        {
            Island* island = new Island(line.islandOne());
            island->setParent(*island);
            islands.push_back(*island);
        }
        // If islandTwo hasn't been added to the islands vector yet, add it
        if (islandInPhonelines(islands, line.islandTwo()) == -1)
        {
            Island* island = new Island(line.islandTwo());
            island->setParent(*island);
            islands.push_back(*island);
        }

        // Store the index of islandOne and islandTwo from the islands vector
        int islandOneIndex = islandInPhonelines(islands, line.islandOne());
        int islandTwoIndex = islandInPhonelines(islands, line.islandTwo());

        // Check the roots of islandOne and islandTwo in the islands vector
        // If they are in the same set / have the same roots there is already a path between them
        // adding another path would create a cycle
        if (islands[islandOneIndex].findRoot().islandName() == islands[islandTwoIndex].findRoot().islandName())
            continue;

        // A path can be made from islandOne and islandTwo
        else
        {
            // Increment the MST cost
            cost += line.distance();

            // Check if the rank of islandOne's root is greater than islandTwo's root
            if (islands[islandOneIndex].findRoot().rank() > islands[islandTwoIndex].findRoot().rank())
            {
                // Increment islandOne's roots rank by 1
                islands[islandOneIndex].findRoot().rank()+=1;

                // Set islandTwo's roots parent equal to islandOne's root
                islands[islandTwoIndex].findRoot().parent() = islands[islandOneIndex].findRoot();
            }
            // The rank of islandTwo's root is greater or equal to islandOne's root
            else
            {
                // Check if the roots have an equal rank
                if (!(islands[islandOneIndex].findRoot().rank() == islands[islandTwoIndex].findRoot().rank()))
                    // Increment islandTwo's roots rank by 1
                    islands[islandTwoIndex].findRoot().rank()+=1;

                // Set islandOne's roots parent equal to islandOne's root
                islands[islandOneIndex].findRoot().parent() = islands[islandTwoIndex].findRoot();
            }

        }
    }
    
    // Return the MST cost
    return cost;
}


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
        // Vector to hold the phone line objects (two islands and the distance between them)
        std::vector<PhoneLine> lines;

        // Variables to hold the island names and distance between them
        std::string islandOne, islandTwo;
        int distance;

        // Iterate over the input file
        while(ifile >> islandOne >> islandTwo >> distance)
        {
            // Push a PhoneLine object into the vector
            PhoneLine* line = new PhoneLine(islandOne, islandTwo, distance);
            lines.push_back(*line);
        }

        // If there's only two islands, return the distance between them
        if (lines.size() == 1)
            return lines[0].distance();

        // Sort the phone lines in ascending order
        mergeSort(lines);

        for (PhoneLine line : lines)
        {
            std::cout << line.islandOne() << " " << line.islandTwo() << " - " << line.distance() << "\n";
        }

        // Print the MST cost
        std::cout << "\n" << findMST(lines);
    }


    return 0;
}
