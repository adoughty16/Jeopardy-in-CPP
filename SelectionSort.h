//
// Created by Abraham Doughty on 4/6/22.
//
#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H

#include "vector"
#include "Question.h"

using namespace::std;

template<typename Comparable>

//This is a modified version of a sorting algorithm I took from a class in data structures/algos.
//I didn't write 98% of this code.

void selectionSort(vector<Comparable>& vec) {
    int swapIndex, i, minIndex;
    Comparable temp;
    for (swapIndex = 0; swapIndex < vec.size()-1; ++swapIndex) {
        // Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex+1; i < vec.size(); ++i) {
            if (vec[i] < vec[minIndex]) {
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

void selectionSortSecond(vector<Question>& vec);

#endif