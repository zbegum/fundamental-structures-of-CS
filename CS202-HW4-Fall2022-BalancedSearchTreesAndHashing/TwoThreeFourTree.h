/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Representation of a 2-3-4 Tree
*/

#include "TreeNode.h"
#include "RBTree.h"
#include <iostream>
#include <fstream>

class TwoThreeFourTree {
public:
    TwoThreeFourTree();
    TreeNode* root;
    int numOfNodes;

    //Helper Methods
    void construct234Tree(RBNode* treeptr);
    void insertItem(TreeNode*& treePtr, int smallItem, int middleItem, int largeItem);
    void printInorder(TreeNode* tree);
    void out(TreeNode* treePtr, string& res);
    void traverse(TreeNode* tree, int& index);


};
