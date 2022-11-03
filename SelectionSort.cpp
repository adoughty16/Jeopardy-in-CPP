//
// Created by Lisa Dion on 10/10/22.
//

#include "SelectionSort.h"

void selectionSortSecond(vector<Question>& vec) {
    int swapIndex, i, minIndex;
    Question temp;
    for (swapIndex = 0; swapIndex < vec.size()-1; ++swapIndex) {
        // Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex+1; i < vec.size(); ++i) {
            if (vec[i].getValue() < vec[minIndex].getValue()) {
                // We have a new minimum
                minIndex = i;
            }
        }
        // Swap min value into swapIndex spot in vector
        if (swapIndex != minIndex) {
            temp = vec[swapIndex];
            vec[swapIndex] = vec[minIndex];
            vec[minIndex] = temp;
        }
    }
}