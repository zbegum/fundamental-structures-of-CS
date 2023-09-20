/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Implementation of a 2-3-4 Node Class
*/

#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode() {
        smallItem = -1;
        middleItem = -1;
        largeItem = -1;
        leftChildPtr = NULL;
        rightChildPtr = NULL;
        lMidChildPtr = NULL;
        rMidChildPtr = NULL;
        nodeType = 1;
        index = -1;}

TreeNode::TreeNode(int smallItem, int middleItem, int largeItem,
                   TreeNode *leftChildPtr, TreeNode *lMidChildPtr, TreeNode *rMidChildPtr, TreeNode *rightChildPtr, int index){
        this->smallItem = smallItem;
        this->middleItem = middleItem;
        this->largeItem = largeItem;
        this->leftChildPtr = leftChildPtr;
        this->rightChildPtr = rightChildPtr;
        this->lMidChildPtr = lMidChildPtr;
        this->rMidChildPtr = rMidChildPtr;
        if (smallItem == -1 && middleItem == -1 && largeItem == -1) { nodeType = 1; }
        else if (smallItem != -1 && middleItem == -1 && largeItem == -1){ nodeType = 2; }
        else if (smallItem != -1 && middleItem != -1 && largeItem == -1) { nodeType = 3; }
        else { nodeType = 4; }
        this->index = index;
    }




