/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : This program constructs a binary tree and performs BST operations on it
*/

#include "BST.h"
#include "analysis.h"
#include <iostream>
using namespace std;



int main(){
    BST* bst = new BST();
    int size = 10;
    int nodeValues[size] = {30, 40, 35, 20, 50, 45, 10, 25, 5, 15};

    cout << "\nInserting items..." << endl;

    for(int i = 0; i < size; i++){
        bst->insert(nodeValues[i]);
    }

    cout << "\nHeight of BST with " << bst->getNodeCount() << " nodes: " << bst->getHeight() << endl;

    bst->deleteKey(35);
    cout << "Node 35 deleted" << endl;
    bst->deleteKey(40);
    cout << "Node 40 deleted" << endl;


    cout << "Median of BST: " << bst->medianOfBST() << endl;

    bst->rangeSearch(5, 43);

    heightAnalysis();

    return 0;
}
