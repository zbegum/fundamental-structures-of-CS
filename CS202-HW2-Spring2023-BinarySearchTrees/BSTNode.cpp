/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Implementation of BST Node
*/

#include "BSTNode.h"

BSTNode::BSTNode(){ }

BSTNode::BSTNode(const int& nodeItem, BSTNode *left, BSTNode *right){
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
}

int BSTNode::getItem(){
    return item;
}

BSTNode* BSTNode::getLeftChild(){
    return leftChildPtr;
}

BSTNode* BSTNode::getRightChild(){
    return rightChildPtr;
}
