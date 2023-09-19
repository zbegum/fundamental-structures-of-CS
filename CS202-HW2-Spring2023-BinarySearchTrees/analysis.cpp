/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Implementation of timeAnalysis() function
*/

#include "analysis.h"
#include "BST.h"
#include <iostream>
#include <ctime>

using namespace std;


void timeAnalysis(){

    srand(time(0));

    //create random array
    int size = 15000;
    int checkpoint = 1500;
    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i] = int(rand());
    }

    //create an empty bst and fill nodes
    BST* tree = new BST();
    cout << "\nPart e - Time Analysis of Binary Search Tree - part 1" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Tree Size\t\tTime Elapsed (ms)" << endl;
    double time;
    clock_t startTime = clock();
    for(int j = 0; j < size; j++){
        if (j % checkpoint == checkpoint - 1){
            time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
            cout << j + 1 << "\t\t\t" << time << endl;
            startTime = clock();
        }
        tree->insertItem(arr[j]);
    }

    //shuffle array
    for( int i  = 0; i < 20000; i++ ){
        int index1 = rand() % 15000;
        int index2 = rand() % 15000;

        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }


    //delete nodes
    cout << "\nPart e - Time Analysis of Binary Search Tree - part 2" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Tree Size\t\tTime Elapsed (ms)" << endl;
    startTime = clock();
    for(int j = 0; j < size; j++){
        if (j % checkpoint == checkpoint - 1){
            time = (1000 * double(clock() - startTime) / CLOCKS_PER_SEC);
            cout << 16500 - (j + 1) << "\t\t\t" << time << endl;
            startTime = clock();
        }
        tree->deleteItem(arr[j]);
    }
    delete [] arr;
}


