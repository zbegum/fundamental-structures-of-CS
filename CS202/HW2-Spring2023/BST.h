/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Pointer based representation of Binary Search Tree
*/

#include "BSTNode.h"
#include <iostream>

class BST {

    public:
        BST();
        BST( const BST& tree );
        ~BST();
        void insertItem(int key);
        void deleteItem(int key);
        int* inorderTraversal(int& length);
        bool hasSequence(int* seq, int length);
        int getNodeCount() const;
        int getRootData();
        BSTNode* getRoot();
        BSTNode* getLeftSubtree();
        BSTNode* getRightSubtree();
        bool isEmpty();

    private:
        BSTNode* root;
        int numberOfNodes;

        //HELPER METHODS
        void copyTree(BSTNode* treePtr, BSTNode*& newTreePtr) const;
        void destroyTree(BSTNode*& treePtr);
        void helperInsertItem(BSTNode*& treePtr, const int& newItem);
        void helperDeleteItem(BSTNode*& treePtr, int searchKey);
        void deleteNodeItem(BSTNode*& nodePtr);
        void processLeftmost(BSTNode*& nodePtr, int& treeItem);
        void inorderTraversalHelper(BSTNode*& treePtr, int*& arr, int& i);
        void hasSequenceHelper(BSTNode*& treePtr, const int& searchedNum, const int& length, int& count, bool& flag, int* arr);
};



