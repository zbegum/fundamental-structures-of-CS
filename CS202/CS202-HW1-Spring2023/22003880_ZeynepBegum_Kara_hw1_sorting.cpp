/**
* Title: Algorithm analysis & Sorting
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Homework : 1
* Description: Implementation file of insertion, bubble, merge, quick and hybrid sort algorithms
*              Besides sorting, every algorithm counts the number of data moves, number of key comparisons for comparing purposes
*/

#include "22003880_ZeynepBegum_Kara_hw1_sorting.h"
#include <cmath>


//========================== SORTING METHODS =============================
/**
 * Sorts given array arr of size using insertion sort algorithm
 * @param arr
 * @param size
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void insertionSort( int* arr, const int size, int &compCount, int &moveCount){
    for (int unsorted = 1; unsorted < size; ++unsorted){
        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;
        for (; (loc > 0) && (arr[loc - 1] > nextItem); --loc){
            compCount++;
            arr[loc] = arr[loc - 1];
            moveCount++;
        }
        if(loc != 0) { compCount++; }     // count the last comparison which has lead to break the loop
        arr[loc] = nextItem;
        moveCount++;
    }
}

/**
 * Sorts array arr of size using bubble sort algorithm
 * @param arr
 * @param size
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void bubbleSort( int* arr, const int size, int &compCount, int &moveCount){
    bool sorted = false;
    for (int pass = 1; (pass < size) && !sorted; ++pass) {
        sorted = true;
        for (int index = 0; index < size - pass; ++index) {
            int nextIndex = index + 1;
            compCount++;
            if (arr[index] > arr[nextIndex]) {
                swap(arr[index], arr[nextIndex], moveCount);
                sorted = false;
            }
        }
    }
}

/**
 * Sorts array arr of size using merge sort algorithm
 * @param arr
 * @param size
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void mergeSort( int* arr, const int size, int &compCount, int &moveCount){
    int last = size - 1;
    mergesortHelper( arr, 0, last, compCount, moveCount );
}

/**
 * Sorts array arr of size using quick sort algorithm
 * @param arr
 * @param size
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void quickSort( int* arr, const int size, int &compCount, int &moveCount){
    int last = size - 1;
    quicksortHelper(arr, 0, last, compCount, moveCount);
}

/**
 * Sorts array arr of size using hybrid sort algorithm
 * Note that hybrid sort algorithm starts with the quick sort,
 * but when the partition size becomes less than or equal to 20,
 * sorts that partition with the bubble sort.
 * @param arr
 * @param size
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void hybridSort( int* arr, const int size, int &compCount, int &moveCount){
    int last = size - 1;
    hybridsortHelper(arr, 0, last, compCount, moveCount);
}

//========================== ANALYSIS METHODS =============================
/**
 * Creates five copies of a random array
 * @param arr1, arr2, arr3, arr4, arr5
 * @param size
 */
void createRandomArrays(int* arr1, int* arr2, int* arr3, int* arr4, int* arr5, const int size){
    for (int i = 0; i < size; i++){
        int num = rand();
        arr1[i] = num;
        arr2[i] = num;
        arr3[i] = num;
        arr4[i] = num;
        arr5[i] = num;
    }
}

/**
 * Creates five copies of a partially ascending array
 * @param arr1, arr2, arr3, arr4, arr5
 * @param size
 */
void createAscArrays(int* arr1, int* arr2, int* arr3, int* arr4, int* arr5, const int size){
    int sizeOfSubArr = (int) log2(size);
    int numOfSubArr = size / sizeOfSubArr;
    int remaining = size - sizeOfSubArr * (numOfSubArr);
    for(int i = 0; i < numOfSubArr - 1; i++){
        for(int j = 0; j < sizeOfSubArr; j++){
            int index = i * sizeOfSubArr + j;
            int num = (rand() % sizeOfSubArr) + i * sizeOfSubArr;
            arr1[index] = num;
            arr2[index] = num;
            arr3[index] = num;
            arr4[index] = num;
            arr5[index] = num;
        }
    }
    for(int j = (numOfSubArr - 1) * sizeOfSubArr; j < size; j++){
            int num = (rand() % sizeOfSubArr) + (numOfSubArr - 1) * sizeOfSubArr;
            arr1[j] = num;
            arr2[j] = num;
            arr3[j] = num;
            arr4[j] = num;
            arr5[j] = num;
        }
}

/**
 * Creates five copies of a partially descending array
 * @param arr1, arr2, arr3, arr4, arr5
 * @param size
 */
void createDscArrays(int* arr1, int* arr2, int* arr3, int* arr4, int* arr5, const int size){
    int sizeOfSubArr = (int) log2(size);
    int numOfSubArr = size / sizeOfSubArr;
    int remaining = size - sizeOfSubArr * (numOfSubArr);
    for(int i = 0; i < numOfSubArr - 1; i++){
        for(int j = 0; j < sizeOfSubArr; j++){
            int index = i * sizeOfSubArr + j;
            int num = (rand() % sizeOfSubArr) + (numOfSubArr - 1 - i) * sizeOfSubArr;
            arr1[index] = num;
            arr2[index] = num;
            arr3[index] = num;
            arr4[index] = num;
            arr5[index] = num;
        }
    }
    for(int j = (numOfSubArr - 1) * sizeOfSubArr; j < size; j++){
            int num = (rand() % sizeOfSubArr);
            arr1[j] = num;
            arr2[j] = num;
            arr3[j] = num;
            arr4[j] = num;
            arr5[j] = num;
        }
}

/**
 * A function to reset arguments
 * @param time
 * @param comp
 * @param move
 */
void reset(double &time, int &comp, int &move){
    time = -1;
    move = -1;
    comp = -1;
}
//=========================== HELPER METHODS ==============================
/**
 * A helper function which allows to recursive calls for merge sort
 * @param theArray
 * @param first Beginning index of array passed
 * @param last Ending index of array passed
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void mergesortHelper( int theArray[], int first, int last, int &compCount, int &moveCount){
    if (first < last) {
        int mid = (first + last) / 2;
        mergesortHelper(theArray, first, mid, compCount, moveCount);
        mergesortHelper(theArray, mid + 1, last, compCount, moveCount);
        merge(theArray, first, mid, last, compCount, moveCount);
    }
}
/**
 * A helper function to merge two sorted arrays
 * @param theArray
 * @param first Beginning index of array passed
 * @param mid Middle index of array passed
 * @param last Ending index of array passed
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount) {
    int tempArray[50000];               // temporary array MAX_SIZE = 50000
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        ++compCount;
        if (theArray[first1] < theArray[first2]) {
            tempArray[index] = theArray[first1];
            ++moveCount;
            ++first1;
        }
        else {
            tempArray[index] = theArray[first2];
            ++moveCount;
            ++first2;
        }
    }
    for (; first1 <= last1; ++first1, ++index){
        tempArray[index] = theArray[first1];
        ++moveCount;

    }
    for (; first2 <= last2; ++first2, ++index){
        tempArray[index] = theArray[first2];
        ++moveCount;
    }
    for (index = first; index <= last; ++index){
        theArray[index] = tempArray[index];
        ++moveCount;
    }
}

/**
 * A helper function which allows to recursive calls for quick sort
 * @param theArray
 * @param first Beginning index of array passed
 * @param last Ending index of array passed
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void quicksortHelper(int theArray[], int first, int last, int &compCount, int &moveCount) {
    int pivotIndex;
    if (first < last) {
        partition(theArray, first, last, pivotIndex, compCount, moveCount);
        quicksortHelper(theArray, first, pivotIndex - 1, compCount, moveCount);
        quicksortHelper(theArray, pivotIndex + 1, last, compCount, moveCount);
    }
}

/**
 * A helper function which allows to recursive calls for hybrid sort
 * @param theArray
 * @param first Beginning index of array passed
 * @param last Ending index of array passed
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void hybridsortHelper(int theArray[], int first, int last, int &compCount, int &moveCount) {
    int size = last - first  + 1;
    int pivotIndex;
    if (size > 20) {
        partition(theArray, first, last, pivotIndex, compCount, moveCount);
        hybridsortHelper(theArray, first, pivotIndex - 1, compCount, moveCount);
        hybridsortHelper(theArray, pivotIndex + 1, last, compCount, moveCount);
    }
    else {
        bubbleSort(theArray, size, compCount, moveCount);
    }
}

/**
 * A helper function to create partitions
 * @param theArray
 * @param first Beginning index of array passed
 * @param last Ending index of array passed
 * @param compCount Number of key comparisons
 * @param moveCount Number of data moves
 */
void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    int pivot = theArray[first];
    ++moveCount;
    int lastS1 = first;
    int firstUnknown = first + 1;
    for ( ; firstUnknown <= last; ++firstUnknown ) {
        ++compCount;
        if (theArray[firstUnknown] < pivot) {
            ++lastS1;
            swap(theArray[firstUnknown], theArray[lastS1], moveCount);
        }
    }
    swap(theArray[first], theArray[lastS1], moveCount);
    pivotIndex = lastS1;
}

/**
 * A helper function to swap two elements
 * recall that each swap operation is three moves
 * @param num1
 * @param num2
 * @param moveCount Number of data moves
 */
void swap(int &num1, int &num2, int &moveCount){
    int temp = num1;
    num1 = num2;
    num2 = temp;
    moveCount = moveCount + 3;
}
