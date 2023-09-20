/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Implementation of Tree Node
*/

#include "TreeNode.h"
#include <iostream>


TreeNode::TreeNode(){ }

TreeNode::TreeNode(const int& nodeItem, TreeNode *left, TreeNode *right){
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
}
