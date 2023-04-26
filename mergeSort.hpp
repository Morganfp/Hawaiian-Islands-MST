/*
* FILE: mergeSort.hpp
* AUTHOR: Morgan Purcell
* DATE: 04/2023
* PURPOSE: Declares functions for sorting the phone lines using merge sort
*/

// Inlcude the necessary lobraries
#include <vector>
// Include the necessary header files
#include "PhoneLine.hpp"


// Helper function to merge the vectors
void merge(std::vector<PhoneLine> &sortedLines, std::vector<PhoneLine> leftLines, std::vector<PhoneLine> rightLines);

// Function to implement merge sort
void mergeSort(std::vector<PhoneLine> &lines);