/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Representation of a node of a binary search tree
*               assume that search key is item value
*/

class BSTNode {
    public:
        int getItem();
        BSTNode* getLeftChild();
        BSTNode* getRightChild();


    private:
        BSTNode();
        BSTNode(const int& nodeItem, BSTNode *left, BSTNode *right);
        int item;               // a data item in the tree
        BSTNode *leftChildPtr; // pointers to children
        BSTNode *rightChildPtr;

    // friend class - can access private parts
    friend class BST;

};
