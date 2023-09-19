/**
* Title: Algorithm analysis & Sorting
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Homework : 1
* Description: Header file of insertion, bubble, merge, quick and hybrid sort algorithms and helper functions
*/

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

// Sorting Methods
void insertionSort(int* arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int* arr, const int size, int &compCount, int &moveCount);
void mergeSort(int* arr, const int size, int &compCount, int &moveCount);
void quickSort(int* arr, const int size, int &compCount, int &moveCount);
void hybridSort(int* arr, const int size, int &compCount, int &moveCount);

// Analysis Methods
void createRandomArrays(int* arr1, int* arr2, int* arr3, int* arr4, int* arr5, const int size);
void createAscArrays(int* arr1, int* arr2, int* arr3, int* arr4, int* arr5, const int size);
void createDscArrays(int* arr1, int* arr2, int* arr3, int* arr4, int* arr5, const int size);
void reset(double &time, int &comp, int &move);

// Helper Methods
void mergesortHelper( int theArray[], int first, int last, int &compCount, int &moveCount);
void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount);
void quicksortHelper(int theArray[], int first, int last, int &compCount, int &moveCount);
void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void hybridsortHelper(int theArray[], int first, int last, int &compCount, int &moveCount);
void swap(int &num1, int &num2, int &moveCount);

