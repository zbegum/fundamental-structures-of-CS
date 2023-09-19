/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Implementation of heightAnalysis() function
*/

#include "analysis.h"
#include "BST.h"
#include <iostream>
#include <ctime>

using namespace std;

void heightAnalysis(){

    srand(time(0));


    //create random array
    int size = 30000;
    int checkpoint = 1500;
    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i] = int(rand());
    }

    //create an empty bst and fill nodes
    BST* tree = new BST();
    cout << "\nPart d - Analysis of BST height - part 1" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Tree Size\t\tTreeHeigth" << endl;
    cout << 0 << "\t\t\t" << tree->getHeight() << endl;
    for(int j = 0; j < size; j++){
        if (j % checkpoint == checkpoint - 1){
            cout << j + 1 << "\t\t\t" << tree->getHeight() << endl;
        }
        tree->insert(arr[j]);
    }

    //shuffle array
    for( int i  = 0; i < 20000; i++ ){
        int index1 = rand() % 30000;
        int index2 = rand() % 30000;

        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }


    //delete nodes
    cout << "\nPart d - Analysis of BST height - part 2" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Tree Size\t\tTreeHeigth" << endl;
    for(int j = size; j > 0; j--){
        if (j % checkpoint == checkpoint - 1){
            cout << j + 1 << "\t\t\t" << tree->getHeight() << endl;
        }
        tree->deleteKey(arr[j-1]);
    }
    cout << 0 << "\t\t\t" << tree->getHeight() << endl;

    delete [] arr;
}


