/**
* Title: Algorithm analysis & Sorting
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Homework : 1
* Description: This program aims to examine and compare the complexity of different sorting algorithms
*              Note that pseudo codes of sorting algorithms has taken from CS202 lecture notes.
*              Lecture notes are available at https://docs.google.com/presentation/d/19w69JGqiSEt9xu84Xyj3L3uVHlTtPgVKkYjxCPPNXFs/edit#slide=id.p1
*/


#include "22003880_ZeynepBegum_Kara_hw1_sorting.h"
#include <ctime>

int main(){

    int sizes[4] = {1000, 5000, 10000, 20000};
    int size;

    for(int j = 0; j < 3; j++){
        if(j == 0){ cout << "\t\t\tPart 2-b-1: Performance analysis of random integers array" << endl; }
        else if (j == 1){ cout << "\t\t\tPart 2-b-2: Performance analysis of partially ascending integers array" << endl; }
        else { cout << "\t\t\tPart 2-b-3: Performance analysis of partially descending integers array" << endl; }

        for(int i = 0; i < 4; i++){
            cout << "---------------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\tElapsed Time(ms)\t\tmoveCount\t\tcompCount" << endl;
            size = sizes[i];
            cout << "Array size: " << size << endl;
            double time;
            int move;
            int comp;

            int* arr1 = new int[size];
            int* arr2 = new int[size];
            int* arr3 = new int[size];
            int* arr4 = new int[size];
            int* arr5 = new int[size];

            if( j == 0 ){ createRandomArrays(arr1, arr2, arr3, arr4, arr5, size); }
            else if ( j == 1 ) { createAscArrays(arr1, arr2, arr3, arr4, arr5, size); }
            else { createDscArrays(arr1, arr2, arr3, arr4, arr5, size); }

            reset(time, move, comp);
            clock_t startTime = clock();
            insertionSort(arr1, size, comp, move);
            time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
            cout << "Insertion Sort\t\t" << time << "\t\t\t\t" << move << "\t\t\t" << comp << endl;

            reset(time, move, comp);
            startTime = clock();
            bubbleSort(arr2, size, comp, move);
            time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
            cout << "Bubble Sort\t\t" << time << "\t\t\t\t" << move << "\t\t\t" << comp << endl;

            reset(time, move, comp);
            startTime = clock();
            mergeSort(arr3, size, comp, move);
            time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
            cout << "Merge Sort\t\t" << time << "\t\t\t\t" << move << "\t\t\t" << comp << endl;

            reset(time, move, comp);
            startTime = clock();
            quickSort(arr4, size, comp, move);
            time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
            cout << "Quick Sort\t\t" << time << "\t\t\t\t" << move << "\t\t\t" << comp << endl;

            reset(time, move, comp);
            startTime = clock();
            hybridSort(arr5, size, comp, move);
            time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
            cout << "Hybrid Sort\t\t" << time << "\t\t\t\t" << move << "\t\t\t" << comp << endl;

            delete[] arr1;
            delete[] arr2;
            delete[] arr3;
            delete[] arr4;
            delete[] arr5;

            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
