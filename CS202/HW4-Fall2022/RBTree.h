/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Representation of Red-Black Tree
*/

#include "RBNode.h"
#include "NodeData.h"

using namespace std;

class RBTree{
public:
    RBTree();
    RBNode* root;
    int numOfNodes;

    //Helper Methods
    void insertItem(RBNode*& treePtr, NodeData* newItem);
    void constructTree(int rootNodeItem, NodeData** data, int numOfNodes);
    void printInorder(RBNode*& treePtr);
    NodeData* findNodeData(int key, NodeData** nodes, int countNodes);
};
