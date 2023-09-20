/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Pointer based implementation of Binary Search Tree
                with the help of CS202 lecture notes
*/

#include "BST.h"
#include <iostream>
using namespace std;


BST::BST(){
    root = NULL;
    numberOfNodes = 0;
}

BST::BST(const BST& tree){
    copyTree(tree.root, root);
}

BST::~BST(){
    destroyTree(root);
}

int BST::getNodeCount(){
    return numberOfNodes;
}

/** Inserts an integer to BST
 *  item to be inserted has the same search key with item value
 */
void BST::insert(int key){
    insertItem(root, key);
    numberOfNodes++;
}

/** Deletes an integer from BST
 *  item to be deleted has the same search key with item value
 */
void BST::deleteKey(int key){
    deleteItem(root, key);
    numberOfNodes--;
}

/** Returns the height of the BST by calling heightHelper(TreeNode* root)
 *  recall that height of a tree is the number of nodes in longest path
 */
int BST::getHeight(){
    TreeNode* rootPtr = root;
    return heightHelper(rootPtr);
}

/** Returns the median of the BST by traversing the BST inorder
 *  the median of it is the middle element in such traversal
 *  Median of a even number n of element sequence is assumed to be the (n/2 + 1)^th number
 */
double BST::medianOfBST(){
    int arr[numberOfNodes];
    int i = 0;
    inorder(root, arr, i);
    return arr[numberOfNodes / 2];      // if number of nodes are even then the median is at index numberOfNodes / 2
}

/** Prints the elements of BST in the range of (a, b)
 *  by calling rangeSearchHelper(TreeNode* root, int a, int b)
 */
void BST::rangeSearch(int a, int b){
    cout << "\nItems in the range of (" << a << "," << b << "): " << endl;
    rangeSearchHelper(root, a, b);
    cout << endl;
}

//----------------------------------------------------------------
//-----------------------HELPER METHODS---------------------------
//----------------------------------------------------------------

void BST::destroyTree(TreeNode*& treePtr){
    if(treePtr != NULL){
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
    }
}

void BST::copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const {
    if (treePtr != NULL) { // copy node
        newTreePtr = new TreeNode(treePtr->item, NULL, NULL);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
}
    else {
        newTreePtr = NULL; // copy empty tree
    }
}

void BST::insertItem(TreeNode*& treePtr, const int& newItem) {
    if (treePtr == NULL) { // Empty tree
        treePtr = new TreeNode(newItem, NULL, NULL);
    }
    // Else search for the insertion position
    else if (newItem < treePtr->item){
        insertItem(treePtr->leftChildPtr, newItem);
    }
    else{
        insertItem(treePtr->rightChildPtr, newItem);
    }
}

void BST::deleteItem(TreeNode*& treePtr, int searchKey) {
    if (treePtr == NULL) // Empty tree
        cout << "DELETE FAILED -- EMPTY TREE" << endl;
    // Position of deletion found
    else if (searchKey == treePtr->item){
        deleteNodeItem(treePtr);
    }
    // Else search for the deletion position
    else if (searchKey < treePtr->item){
        deleteItem(treePtr->leftChildPtr, searchKey);
    }
    else{
        deleteItem(treePtr->rightChildPtr, searchKey);
    }
}

void BST::deleteNodeItem(TreeNode*& nodePtr) {
    TreeNode *delPtr;
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

void BST::processLeftmost(TreeNode*& nodePtr, int& treeItem){
    if (nodePtr->leftChildPtr == NULL) {
        treeItem = nodePtr->item;
        TreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else {
        processLeftmost(nodePtr->leftChildPtr, treeItem);
    }
}

int BST::heightHelper(TreeNode*& treePtr){
    if (treePtr == NULL){
        return 0;
    }
    else {
        return 1 + max(heightHelper(treePtr->leftChildPtr), heightHelper(treePtr->rightChildPtr));
    }
}

int BST::max(int x, int y){
   if( y <= x ){ return x; }
   else { return y; }
}

void BST::inorder(TreeNode* treePtr, int* arr, int& i){
    if( treePtr != NULL){
        inorder(treePtr->leftChildPtr, arr, i);
        arr[i] = treePtr->item;
        i++;
        inorder(treePtr->rightChildPtr, arr, i);
    }
}

void BST::rangeSearchHelper(TreeNode* root, int rangeBegin, int rangeEnd){
    if(root == NULL) return;
    if(rangeBegin < root->item) { rangeSearchHelper(root->leftChildPtr, rangeBegin, rangeEnd); }
    if(rangeBegin <= root->item && root->item <= rangeEnd) { cout << root->item << " "; }
    if(rangeEnd > root->item ) { rangeSearchHelper(root->rightChildPtr, rangeBegin, rangeEnd); }
}
