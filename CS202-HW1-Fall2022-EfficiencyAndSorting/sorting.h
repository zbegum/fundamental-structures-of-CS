/*
 * Title: Sorting and Algorithm Efficiency
 * Author:Zeynep Begum Kara
 * ID: 22003880
 * Section: 1
 * Assignment: 1
 * Description: Prototypes for bubble sort, merge sort, and quick sort algorithms
 */

 #include <string>

 using namespace std;

void performanceAnalysis();

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);

// HELPER METHODS
void swap(int &num1, int &num2, int &moveCount);
void merge( int *theArray, int first, int mid, int last, int &compCount, int &moveCount );
void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void mergesortHelper( int *theArray, int first, int last, int &compCount, int &moveCount);
void quicksortHelper( int *theArray, int first, int last, int &compCount, int &moveCount);
void printResults( double* tim, int* comp, int* mov );
void testBubbleSort (int *&a1, int size, int arrType, double*&tim, int*&comp, int*&mov, int row);
void testMergeSort(int *&a1, int size, int arrType, double*&tim, int*&comp, int*&mov, int row);
void testQuickSort(int *&a1, int size, int arrType, double*&tim, int*&comp, int*&mov, int row);
