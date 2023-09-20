/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Implementation of 2-3-4 Tree Class
*/

#include "TwoThreeFourTree.h"
#include <iostream>

TwoThreeFourTree::TwoThreeFourTree() { root = NULL; numOfNodes = 0; }

void TwoThreeFourTree::construct234Tree(RBNode* treeptr){
    if(treeptr != NULL ){
        if(treeptr->nodeColor == 1){
            if ((treeptr->leftChildPtr == NULL || treeptr->leftChildPtr->nodeColor == 1) && (treeptr->rightChildPtr == NULL || (treeptr->rightChildPtr)->nodeColor == 1)){
                insertItem(root, treeptr->nodeItem , -1, -1); //insert 2 node
            }
            else if ((treeptr->leftChildPtr == NULL || (treeptr->leftChildPtr)->nodeColor == 1) && (treeptr->rightChildPtr != NULL && (treeptr->rightChildPtr)->nodeColor == 0)){
                insertItem(root, treeptr->nodeItem , (treeptr->rightChildPtr)->nodeItem, -1); //insert 3 node
            }
            else if ((treeptr->leftChildPtr != NULL && treeptr->leftChildPtr->nodeColor == 0) && (treeptr->rightChildPtr == NULL || (treeptr->rightChildPtr)->nodeColor == 1)){
                insertItem(root, treeptr->nodeItem , (treeptr->leftChildPtr)->nodeItem, -1); //insert 3 node
            }
            else if ((treeptr->leftChildPtr != NULL && treeptr->leftChildPtr->nodeColor == 0) && (treeptr->rightChildPtr != NULL && (treeptr->leftChildPtr)->nodeColor == 0)){
                insertItem(root,(treeptr->leftChildPtr)->nodeItem, treeptr->nodeItem, (treeptr->rightChildPtr)->nodeItem); //insert 4 node
            }
        }
        construct234Tree(treeptr->leftChildPtr);
        construct234Tree(treeptr->rightChildPtr);
    }
}

void TwoThreeFourTree::insertItem(TreeNode*& treePtr, int smallItem, int middleItem, int largeItem){
    if (treePtr == NULL) { // Empty tree
        treePtr = new TreeNode(smallItem, middleItem, largeItem, NULL, NULL, NULL, NULL, -1);
        cout << "node inserted to 234: " << smallItem << " "  << middleItem << " " << largeItem << endl;
    }
    // Else search for the insertion position
    else{
        int maxItem = largeItem;
        //find max item in a 2 3 4 node
        if(middleItem > largeItem){
            maxItem = middleItem;
        }
        if(smallItem > largeItem){
            maxItem = smallItem;
        }
        if (treePtr->nodeType == 2){
            if(maxItem < treePtr -> smallItem){
                insertItem(treePtr->leftChildPtr, smallItem, middleItem, largeItem);
            }
            else{
                insertItem(treePtr->lMidChildPtr, smallItem, middleItem, largeItem);
            }
        }
        else if (treePtr->nodeType == 3) {
            if(maxItem < treePtr-> smallItem){
                insertItem(treePtr->leftChildPtr, smallItem, middleItem, largeItem);
            }
            else if ( smallItem > treePtr-> middleItem ){
                insertItem(treePtr->rMidChildPtr, smallItem, middleItem, largeItem);
            }
            else{
                insertItem(treePtr->lMidChildPtr, smallItem, middleItem, largeItem);
            }

        }
        else if(treePtr->nodeType == 4){
            if(maxItem < treePtr -> smallItem){
                insertItem(treePtr->leftChildPtr, smallItem, middleItem, largeItem);
            }
            else if ( smallItem > treePtr-> largeItem ){
                insertItem(treePtr->rightChildPtr, smallItem, middleItem, largeItem);
            }
            else if(maxItem < treePtr -> middleItem){
                insertItem(treePtr->lMidChildPtr, smallItem, middleItem, largeItem);
            }
            else{
                insertItem(treePtr->rMidChildPtr, smallItem, middleItem, largeItem);
            }

        }
    }
}

void TwoThreeFourTree::printInorder(TreeNode* treePtr){
    if (treePtr == NULL)
        return;

    printInorder(treePtr->leftChildPtr);
    printInorder(treePtr->lMidChildPtr);

    cout << treePtr->index << "\t";
    cout << treePtr->smallItem << " " << treePtr->middleItem << " " << treePtr->largeItem << " ";
    if (treePtr->leftChildPtr != NULL) { cout << (treePtr->leftChildPtr)->index << " "; }
    else { cout << -1 << " "; }
    if (treePtr->lMidChildPtr != NULL) { cout << (treePtr->lMidChildPtr)->index << " "; }
    else { cout << -1 << " "; }
    if (treePtr->rMidChildPtr != NULL) { cout << (treePtr->rMidChildPtr)->index << " "; }
    else { cout << -1 << " "; }
    if (treePtr->rightChildPtr != NULL) { cout << (treePtr->rightChildPtr)->index << " "; }
    else { cout << -1 << " "; }
    cout << endl;

    printInorder(treePtr->rMidChildPtr);
    printInorder(treePtr->rightChildPtr);

}

void TwoThreeFourTree::out(TreeNode* treePtr, string& res){
    if (treePtr == NULL)
        return;

    out(treePtr->leftChildPtr, res);
    out(treePtr->lMidChildPtr, res);

    res = res + to_string(treePtr->index) + " ";
    res = res + to_string(treePtr->smallItem) + " " + to_string(treePtr->middleItem) + " " + to_string(treePtr->largeItem) + " ";
    if (treePtr->leftChildPtr != NULL) { res = res + to_string((treePtr->leftChildPtr)->index) + " "; }
    else { res = res + to_string(-1) + " "; }
    if (treePtr->lMidChildPtr != NULL) { res = res + to_string((treePtr->lMidChildPtr)->index) + " "; }
    else { res = res + to_string(-1) + " "; }
    if (treePtr->rMidChildPtr != NULL) { res = res + to_string((treePtr->rMidChildPtr)->index) + " "; }
    else { res = res + to_string(-1) + " "; }
    if (treePtr->rightChildPtr != NULL) { res = res + to_string((treePtr->rightChildPtr)->index) + " "; }
    else { res = res + to_string(-1) + " "; }
    res = res + "\n";

    out(treePtr->rMidChildPtr, res);
    out(treePtr->rightChildPtr, res);
}

void TwoThreeFourTree::traverse(TreeNode* treePtr, int& index){
    if (treePtr == NULL)
        return;
    treePtr->index = index;
    index++;
    if (treePtr->leftChildPtr != NULL) {(treePtr->leftChildPtr)->index = index; }
    if (treePtr->lMidChildPtr != NULL) {(treePtr->lMidChildPtr)->index = index;}
    if (treePtr->rMidChildPtr != NULL) {(treePtr->rMidChildPtr)->index = index;}
    if (treePtr->rightChildPtr != NULL) {(treePtr->rightChildPtr)->index = index;}

    traverse(treePtr->leftChildPtr, index);
    traverse(treePtr->lMidChildPtr, index);
    traverse(treePtr->rMidChildPtr, index);
    traverse(treePtr->rightChildPtr, index);
}


