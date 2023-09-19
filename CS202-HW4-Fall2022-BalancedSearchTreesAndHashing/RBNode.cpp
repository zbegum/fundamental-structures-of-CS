/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Implementation of Red-Black Node Class
*/

#include "RBNode.h"

RBNode::RBNode(){}

RBNode::RBNode( int nodeItem, RBNode* leftChildPtr,  RBNode* rightChildPtr, int nodeColor){
    this->nodeItem = nodeItem;
    this->leftChildPtr = leftChildPtr;
    this->rightChildPtr = rightChildPtr;
    this->nodeColor = nodeColor;
}

