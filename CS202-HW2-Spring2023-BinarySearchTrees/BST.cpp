/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Pointer based implementation of Binary Search Tree
*               with the help of CS202 lecture notes
*               Lecture notes are available at https://docs.google.com/presentation/d/1PQrbcH14saUwybtHmz27XT7n_7sfJJJxZlCHUV-o4A8/edit#slide=id.p33
*/

#include "BST.h"
using namespace std;

BST::BST(){
    root = NULL;
    numberOfNodes = 0;
}

BST::BST(const BST& tree){
    copyTree(tree.root, root);
    numberOfNodes = tree.numberOfNodes;
}

BST::~BST(){
    destroyTree(root);
}

int BST::getNodeCount() const{
    return numberOfNodes;
}

int BST::getRootData(){
    return root->item;
}

BSTNode* BST::getRoot(){
    return root;
}

BSTNode* BST::getLeftSubtree(){
    return root->leftChildPtr;
}

BSTNode* BST::getRightSubtree(){
    return root->rightChildPtr;
}

bool BST::isEmpty(){
    return numberOfNodes == 0;
}

void BST::insertItem(int key){
    helperInsertItem(root, key);
    numberOfNodes++;
}

void BST::deleteItem(int key){
    helperDeleteItem(root, key);
    numberOfNodes--;
}

int* BST::inorderTraversal(int& length){
    int* inorderArr = new int[length];
    int index = 0;
    inorderTraversalHelper(root, inorderArr, index);
    return inorderArr;
}

bool BST::hasSequence(int* seq, int length){
    int counter = 0;
    int arr[length] = {0};
    bool flag = false;
    if(length == 0) { return true; }
    int searched = seq[0];
    hasSequenceHelper(root, searched, length, counter, flag, arr);
    for(int i = 0; i < length; i++){
        if(arr[i] != seq[i]){ return false; }
    }
    return true;
}

//----------------------------------------------------------------
//-----------------------HELPER METHODS---------------------------
//----------------------------------------------------------------

void BST::copyTree(BSTNode* treePtr, BSTNode*& newTreePtr) const {
    if (treePtr != NULL) { // copy node
        newTreePtr = new BSTNode(treePtr->item, NULL, NULL);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
}
    else {
        newTreePtr = NULL; // copy empty tree
    }
}

void BST::destroyTree(BSTNode*& treePtr){
    if(treePtr != NULL){
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
    }
}

void BST::helperInsertItem(BSTNode*& treePtr, const int& newItem) {
    if (treePtr == NULL) { // Empty tree
        treePtr = new BSTNode(newItem, NULL, NULL);
    }
    // Else search for the insertion position
    else if (newItem < treePtr->item){
        helperInsertItem(treePtr->leftChildPtr, newItem);
    }
    else{
        helperInsertItem(treePtr->rightChildPtr, newItem);
    }
}

void BST::helperDeleteItem(BSTNode*& treePtr, int searchKey) {
    if (treePtr == NULL) // Empty tree
        cout << "DELETE FAILED -- EMPTY TREE" << endl;
    // Position of deletion found
    else if (searchKey == treePtr->item){
        deleteNodeItem(treePtr);
    }
    // Else search for the deletion position
    else if (searchKey < treePtr->item){
        helperDeleteItem(treePtr->leftChildPtr, searchKey);
    }
    else{
        helperDeleteItem(treePtr->rightChildPtr, searchKey);
    }
}

void BST::deleteNodeItem(BSTNode*& nodePtr) {
    BSTNode* delPtr;
    int replacementItem;
    // (1) Test for a leaf
    if ( (nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL) ) {
        delete nodePtr;
        nodePtr = NULL;
    }
    // (2) Test for no left child
    else if (nodePtr->leftChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    // (3) Test for no right child
    else if (nodePtr->rightChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
    // (4) There are two children:
    // Retrieve and delete the inorder successor
    else {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}

void BST::processLeftmost(BSTNode*& nodePtr, int& treeItem){
    if (nodePtr->leftChildPtr == NULL) {
        treeItem = nodePtr->item;
        BSTNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else {
        processLeftmost(nodePtr->leftChildPtr, treeItem);
    }
}

void BST::inorderTraversalHelper(BSTNode*& treePtr, int*& arr, int& i){
    if(treePtr != NULL){
        inorderTraversalHelper(treePtr->leftChildPtr, arr, i);
        arr[i] = treePtr->item;
        i++;
        inorderTraversalHelper(treePtr->rightChildPtr, arr, i);
    }
}

void BST::hasSequenceHelper(BSTNode*& treePtr, const int& searchedNum, const int& length, int& count, bool& flag, int* arr) {
    if(treePtr != NULL && count < length){
        if(searchedNum < treePtr->item) { hasSequenceHelper(treePtr->leftChildPtr, searchedNum, length, count, flag, arr); }
        if(searchedNum == treePtr->item){ flag = true; }
        if(flag || searchedNum > treePtr->item) {
            if(flag) {arr[count] = treePtr->item; count++;}
            hasSequenceHelper(treePtr->rightChildPtr, searchedNum, length, count, flag, arr);
        }
    }
}
