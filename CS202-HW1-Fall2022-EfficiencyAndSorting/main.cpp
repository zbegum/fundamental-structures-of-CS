/*
 * Title: Sorting and Algorithm Efficiency
 * Author:Zeynep Begum Kara
 * ID: 22003880
 * Section: 1
 * Assignment: 1
 * Description: This program aims to examine the complexity of bubble, merge and quick sort algorithms
 *              it shows the number of moves, number of comparisons and time elapsed when sorting an array
 */
#include <iostream>
#include "sorting.h"
#include <ctime>

int main()
{
    int arrSize = 16;
    int moveC;
    int compC;

    int arr1[arrSize] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31, 33, 26};
    int arr2[arrSize] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31, 33, 26};
    int arr3[arrSize] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31, 33, 26};
    int arr4[arrSize] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31, 33, 26};

    moveC = 0;
    compC = 0;
    cout << "Executing bubbleSort..." << endl;
    bubbleSort(arr1, arrSize, compC, moveC);
    displayArray(arr1, arrSize);
    cout << "Comparison count: " << compC << endl;
    cout << "Move count: " << moveC << endl;
    cout << endl;

    moveC = 0;
    compC = 0;
    cout << "Executing mergeSort..." << endl;
    mergeSort(arr2, arrSize, compC, moveC);
    displayArray(arr2, arrSize);
    cout << "Comparison count: " << compC << endl;
    cout << "Move count: " << moveC << endl;
    cout << endl;

    moveC = 0;
    compC = 0;
    cout << "Executing quickSort..." << endl;
    quickSort(arr3, arrSize, compC, moveC);
    displayArray(arr3, arrSize);
    cout << "Comparison count: " << compC << endl;
    cout << "Move count: " << moveC << endl;
    cout << endl;


    performanceAnalysis();

}
