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

BST* merge(const BST& tree1, const BST& tree2);

int main(){

    cout << "\nCreating a tree..." << endl;
    BST* bst = new BST();
    int size = 12;
    int nodeValues[size] = {8, 4, 3, 1, 2, 6, 5, 13, 12, 10, 15, 14};

    cout << "\nInserting items..." << endl;
    for(int i = 0; i < size; i++){
        cout << "Item " << nodeValues[i] << " inserted" << endl;
        bst->insertItem(nodeValues[i]);
    }
    cout << "Insertion done" << endl;

    cout << "\nInorder traversal..." << endl;
    size = bst->getNodeCount();
    int* arr = bst->inorderTraversal(size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
    cout << endl;

    cout << "\nDelete item 5" << endl;
    bst->deleteItem(5);
    cout << "Item deleted" << endl;
    cout << "\nDelete item 8" << endl;
    bst->deleteItem(8);
    cout << "Item deleted" << endl;

    cout << "\nInorder traversal..." << endl;
    size = bst->getNodeCount();
    arr = bst->inorderTraversal(size);
    for(int i = 0; i < bst->getNodeCount(); i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
    cout << endl;
    cout << "\nSearching sequence {1, 2, 3, 4, 6} in the BST..." << endl;
    int ex1[] = {1, 2, 3, 4, 6};
    cout << bst->hasSequence(ex1, 5) << endl;

    cout << "\nSearching sequence {6, 7, 8, 10} in the BST..." << endl;
    int ex2[] = {6, 7, 8, 10};
    cout << bst->hasSequence(ex2, 4) << endl;

    cout << "\nInsert item 7" << endl;
    bst->insertItem(7);
    cout << "Item inserted" << endl;

    cout << "\nInsert item 8" << endl;
    bst->insertItem(8);
    cout << "Item inserted" << endl;

    cout << "\nSearching sequence {6, 7, 8, 10} in the BST..." << endl;
    cout << bst->hasSequence(ex2, 4) << endl;

    cout << "\nInorder traversal..." << endl;
    size = bst->getNodeCount();
    arr = bst->inorderTraversal(size);
    for(int i = 0; i < bst->getNodeCount(); i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
    cout << endl;

    cout << "\nSearching sequence {2, 4, 7} in the BST..." << endl;
    int ex3[] = {2, 4, 7};
    cout << bst->hasSequence(ex3, 3) << endl;

    cout << "\nDelete item 3" << endl;
    bst->deleteItem(3);
    cout << "Item deleted" << endl;
    cout << "\nDelete item 6" << endl;
    bst->deleteItem(6);
    cout << "Item deleted" << endl;

    cout << "\nSearching sequence {2, 4, 7} in the BST..." << endl;
    cout << bst->hasSequence(ex3, 3) << endl;

    cout << "\nInorder traversal..." << endl;
    size = bst->getNodeCount();
    arr = bst->inorderTraversal(size);
    for(int i = 0; i < bst->getNodeCount(); i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Creating another tree..." << endl;
    BST* bst2 = new BST();
    int size2 = 10;
    int nodeValues2[size2] = {11, 16, 3, 20, 19, 18, 9, 6, 5, 17};
    cout << "\nInserting items..." << endl;
    for(int i = 0; i < size; i++){
        cout << "Item " << nodeValues2[i] << " inserted" << endl;
        bst2->insertItem(nodeValues2[i]);
    }
    cout << "Insertion done" << endl;

    cout << "\nSearching sequence {15, 16, 17, 18, 19, 20} in new BST..." << endl;
    int ex4[] = {15, 16, 17, 18, 19, 20};
    cout << bst2->hasSequence(ex4, 6) << endl;

    cout << "\nInorder traversal tree1..." << endl;
    size = bst->getNodeCount();
    arr = bst->inorderTraversal(size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
    cout << endl;

    cout << "\nInorder traversal tree2..." << endl;
    size = bst2->getNodeCount();
    arr = bst2->inorderTraversal(size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
    cout << endl;

    cout << "\nMerge two trees..." << endl;
    BST* mergedTree = merge(*bst, *bst2);
    cout << "Merge operation done" << endl;

    cout << "\nSearching sequence {15, 16, 17, 18, 19, 20} in merged BST..." << endl;
    cout << mergedTree->hasSequence(ex4, 6) << endl;

    cout << "\nInorder traversal of mergedTree..." << endl;
    size = mergedTree->getNodeCount();
    arr = mergedTree->inorderTraversal(size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
    cout << endl;

    cout << "\nDeleting merged tree..." << endl;
    for(int i = 20; i > 0; i--){
        mergedTree->deleteItem(i);
        cout << "Item " << i << " deleted" << endl;
    }

    cout << "\nInorder traversal merged tree..." << endl;
    size = mergedTree->getNodeCount();
    arr = mergedTree->inorderTraversal(size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
    delete mergedTree;
    cout << endl;

    int itemsToBeDeleted[] = {1, 2, 4, 7, 8, 10, 12, 13, 14, 15};
    cout << "\nDeleting tree 1..." << endl;
    for(int i = 9; i >= 0; i--){
        bst->deleteItem(itemsToBeDeleted[i]);
        cout << "Item " << itemsToBeDeleted[i] << " deleted" << endl;
    }
    delete bst;


    cout << "\nDeleting tree 2..." << endl;
    for(int i = 9; i >= 0; i--){
        bst2->deleteItem(nodeValues2[i]);
        cout << "Item " << nodeValues2[i] << " deleted" << endl;
    }
    delete bst2;

    cout << endl;
    cout << "==============TESTS ARE DONE==============" << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    timeAnalysis();

    return 0;
}

BST* merge(const BST& tree1, const BST& tree2){
    BST* copyTree1 = new BST(tree1);
    int size1 = copyTree1->getNodeCount();
    int* arr1 = copyTree1->inorderTraversal(size1);

    BST* mergedTree = new BST(tree2);
    for(int i = 0; i < size1; i++){
        mergedTree->insertItem(arr1[i]);
    }
    return mergedTree;

}
