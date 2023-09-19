/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Zeynep Begum Kara
 * ID: 22003880
 * Section: 1
 * Assignment: 1
 * Description: The implementations of bubble sort, merge sort,
 *         and quick sort algorithms shown in lectures
 *          and display/create functions on an array
 */

#include "sorting.h"
#include <iostream>
#include <ctime>
using namespace std;


/**
 * Sorts array using bubble sort algorithm
 * and counts the num of comparisons and num of moves.
 * Source code has taken from CS202 lecture notes
 * compCount and moveCount added.
 */
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
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
 * Calls helper of it to sort the array using merge sort algorithm
 * and count the num of comparisons and num of moves.
 */
void mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    int last = size - 1;
    mergesortHelper( arr, 0, last, compCount, moveCount );
}

/**
 * Calls helper of it to sort the array using quick sort algorithm
 * and count the num of comparisons and num of moves.
 */
void quickSort(int *arr, const int size, int &compCount, int &moveCount){
    int last = size - 1;
    quicksortHelper(arr, 0, last, compCount, moveCount);
}

/**
 * Recursive implementation of merge sort algorithm
 * source code has taken from CS202 lecture notes
 * compCount and moveCount added.
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
 * Merges two sorted arrays
 * source code has taken from CS202 lecture notes
 * compCount and moveCount added.
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
 * Recursive implementation of quick sort algorithm
 * source code has taken from CS202 lecture notes
 * compCount and moveCount added.
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
 * Chooses a pivot and divides array into subarrays
 * pivot has choosen as the first element of the array
 * source code has taken from CS202 lecture notes
 * compCount and moveCount added.
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


void swap(int &num1, int &num2, int &moveCount)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    moveCount = moveCount + 3;
}

void displayArray(const int *arr, const int size){
    if (size == 0){
        cout << "[ ]\n" << endl;
    }
    else{
        cout << "[ ";
        for (int i = 0; i < size - 1; ++i){
            cout << arr[i] << ", ";
        }
        cout << arr[size - 1] << " ]" << endl;
    }
}


void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    for (int i = 0; i < size; i++){
        arr1[i] = int(rand());
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    arr1[0] = int(rand());
    arr2[0] = arr1[0];
    arr3[0] = arr1[0];
    int num;
    for (int i = 1; i < size; i++){
        num = int(rand());
        if( arr1[i - 1] < num){
            arr1[i] = num;
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
        }
        else{
            arr1[i] = num + arr1[i - 1];
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
        }
    }
}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    arr1[size - 1] = int(rand());
    arr2[size - 1] = arr1[size - 1];
    arr3[size - 1] = arr1[size - 1];
    int num;
    for (int i = size - 2; i > -1; i--){
        num = int(rand());
        if( arr1[i + 1] < num){
            arr1[i] = num;
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
        }
        else{
            arr1[i] = num + arr1[i + 1];
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
        }
    }

}

void performanceAnalysis(){

    srand(time(0));
    int sizes[12] = { 4000, 8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000, 40000, 44000, 48000 };
    double *timeArr = new double[108];
    int *compCountArr = new int[108];
    int *moveCountArr = new int [108];

    for ( int i = 0; i < 12; i++ ){

        int size = sizes[i];

        int *a1 = new int[size];
        int *a2 = new int[size];
        int *a3 = new int[size];


        createRandomArrays(a1, a2, a3, size);
        testBubbleSort(a1, size, 0, timeArr, compCountArr, moveCountArr, i); // 0: random array
        testMergeSort(a2, size, 0, timeArr, compCountArr, moveCountArr, i);
        testQuickSort(a3, size, 0, timeArr, compCountArr, moveCountArr, i);


        createAscendingArrays(a1, a2, a3, size);

        testBubbleSort(a1, size, 1, timeArr, compCountArr, moveCountArr, i); // 1: ascending array
        testMergeSort(a2, size, 1, timeArr, compCountArr, moveCountArr, i);
        testQuickSort(a3, size, 1, timeArr, compCountArr, moveCountArr, i);

        createDescendingArrays(a1, a2, a3, size);

        testBubbleSort(a1, size, 2, timeArr, compCountArr, moveCountArr, i); // 2: descending array
        testMergeSort(a2, size, 2, timeArr, compCountArr, moveCountArr, i);
        testQuickSort(a3, size, 2, timeArr, compCountArr, moveCountArr, i);

        delete [] a1;
        delete [] a2;
        delete [] a3;
    }

    printResults( timeArr, compCountArr, moveCountArr );
}

void testBubbleSort(int *&a1, int size, int arrType, double*&timeArr, int*&moveArr, int*&compArr, int row){
    int compCount = 0;
    int moveCount = 0;
    double time;

    clock_t startTime = clock();
    bubbleSort(a1, size, compCount, moveCount);
    time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
    timeArr[12 * arrType + row ] = time;
    moveArr[12 * arrType + row ] = moveCount;
    compArr[12 * arrType + row ] = compCount;

}

void testMergeSort(int *&a1, int size, int arrType, double*&timeArr, int*&moveArr, int*&compArr, int row){
    int compCount = 0;
    int moveCount = 0;
    double time;

    clock_t startTime = clock();
    mergeSort(a1, size, compCount, moveCount);
    time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
    timeArr[12 * arrType + row + 35] = time;
    moveArr[12 * arrType + row + 35] = moveCount;
    compArr[12 * arrType + row + 35] = compCount;
}

void testQuickSort(int *&a1, int size, int arrType, double*&timeArr, int*&moveArr, int*&compArr, int row){
    int compCount = 0;
    int moveCount = 0;
    double time;

    clock_t startTime = clock();
    quickSort(a1, size, compCount, moveCount);
    time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
    timeArr[12 * arrType + row + 70] = time;
    moveArr[12 * arrType + row + 70] = moveCount;
    compArr[12 * arrType + row + 70] = compCount;

}

void printResults( double* timeArr, int* compArr, int* moveArr ){
    for (int i = 0; i < 3; i++){
        if( i == 0 ){
            cout << "-----------------------------------------------------" << endl;
            cout << "Analysis of Bubble Sort\nArray Size\t\tElapsed Time\t\t\tmoveCount\t\t\tcompCount" << endl;
            for(int j = 0; j < 3; j++){
                cout << endl;
                for( int k = 0; k < 12; k++){
                    cout << 4000 * (k + 1)  << "\t\t\t";
                    cout << timeArr[ j * 12 + k] << "ms\t\t\t\t" ;
                    cout << compArr[ j * 12 + k]<< "\t\t\t\t" ;
                    cout << moveArr[ j * 12 + k] << "\t\t\t\t" ;
                    cout << endl;
                }
            }
        }
        else if (i == 1){
            cout << "-----------------------------------------------------" << endl;
            cout << "Analysis of Merge Sort\nArray Size\t\tElapsed Time\t\t\tmoveCount\t\tcompCount" << endl;
            for(int j = 0; j < 3; j++){
                cout << endl;
                for( int k = 0; k < 12; k++){
                    cout << 4000 * (k + 1)  << "\t\t\t";
                    cout << timeArr[ j * 12 + k + 35] << "ms\t\t\t\t" ;
                    cout << compArr[ j * 12 + k + 35]<< "\t\t\t" ;
                    cout << moveArr[ j * 12 + k + 35] << "\t\t\t" ;
                    cout << endl;
                }
            }
        }
        else{
            cout << "-----------------------------------------------------" << endl;
            cout << "Analysis of Quick Sort\nArray Size\t\tElapsed Time\t\t\tmoveCount\t\tcompCount" << endl;
            for(int j = 0; j < 3; j++){
                cout << endl;
                for( int k = 0; k < 12; k++){
                    cout << 4000 * (k + 1)  << "\t\t\t";
                    cout << timeArr[ j * 12 + k + 70] << "ms\t\t\t\t" ;
                    cout << compArr[ j * 12 + k + 70]<< "\t\t\t" ;
                    cout << moveArr[ j * 12 + k + 70] << "\t\t\t" ;
                    cout << endl;
                }
            }
        }

    }
    cout << "-----------------------------------------------------" << endl;
}


