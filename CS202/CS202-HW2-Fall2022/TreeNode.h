/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Representation of a TreeNode
*               search keys are assumed to be as the same as item value for this project
*/

class TreeNode {
    private:
        TreeNode();
        TreeNode(const int& nodeItem,TreeNode *left, TreeNode *right);
        int item;               // a data item in the tree
        TreeNode *leftChildPtr; // pointers to children
        TreeNode *rightChildPtr;

    // friend class - can access private parts
    friend class BST;

};

