/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Representation of a Node in 2-3-4 Tree
*/

class TreeNode {
public:
    TreeNode();
    TreeNode(int smallItem, int middleItem, int largeItem,
             TreeNode *leftChildPtr, TreeNode *lMidChildPtr, TreeNode *rMidChildPtr, TreeNode *rightChildPtr, int index);

private:
    int smallItem, middleItem, largeItem;
    TreeNode *leftChildPtr, *lMidChildPtr;
    TreeNode *rMidChildPtr, *rightChildPtr;
    int nodeType;
    int index;
    friend class TwoThreeFourTree;
};
