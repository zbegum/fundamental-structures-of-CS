/**
* Title : Binary Search Trees
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 2
* Description : Pointer based representation of Binary Search Tree
*/

#include "TreeNode.h"

class BST {

    public:
        BST();
        BST( const BST& tree );
        ~BST();
        void insert(int key);
        void deleteKey(int key);
        int getHeight();
        int getNodeCount();
        double medianOfBST();
        void rangeSearch(int a, int b);

    private:
        TreeNode* root;
        int numberOfNodes;


        //HELPER METHODS
        void copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const;
        void destroyTree(TreeNode*& treePtr);
        void insertItem(TreeNode*& treePtr, const int& newItem);
        void deleteItem(TreeNode*& treePtr, int searchKey);
        void deleteNodeItem(TreeNode*& nodePtr);
        void processLeftmost(TreeNode *&nodePtr, int& treeItem);
        int heightHelper(TreeNode*& treePtr);
        int max(int x, int y);
        void inorder(TreeNode* treePtr, int* arr, int& i);
        void rangeSearchHelper(TreeNode* root, int rangeBegin, int rangeEnd);

};



