/*
* FILE: mergeSort.cpp
* AUTHOR: Morgan Purcell
* DATE: 04/2023
* PURPOSE: Define mergeSort functions
*/

// Include the necessary header files
#include "mergeSort.hpp"
#include <iostream>


// Helper function to merge the vectors
void merge(std::vector<PhoneLine> &sortedLines, std::vector<PhoneLine> leftLines, std::vector<PhoneLine> rightLines)
{
    // Iterators for the sorted, left, and right lines
    int i = 0, l = 0, r = 0;

    // Iterate through the left and right lines
    while(l < leftLines.size() && r < rightLines.size())
    {
        if (leftLines[l].distance() < rightLines[r].distance())
            sortedLines[i++] = leftLines[l++];

        else //(rightLines[l].distance() <= leftLines[r].distance())
            sortedLines[i++] = rightLines[r++];
    }

    // Add the remaining elements to the sorted vector
    while (l < leftLines.size())
        sortedLines[i++] = leftLines[l++];
    while (r < rightLines.size())
        sortedLines[i++] = rightLines[r++];

    return;
}

// Function to implement merge sort
void mergeSort(std::vector<PhoneLine> &lines)
{
    // Base case - 1 or less elements in the vector
    if (lines.size() <= 1)
        return;

    // Find the middle of the vector
    int middle = lines.size() / 2;

    // Initalize left and right sub vectors
    std::vector<PhoneLine> leftLines(lines.begin(), lines.begin() + middle);
    std::vector<PhoneLine> rightLines(lines.begin() + middle, lines.end());

    // Further break down the vectors into subvectors
    mergeSort(leftLines);
    mergeSort(rightLines);

    // Merge the vectors
    merge(lines, leftLines, rightLines);
    

    return;
}
