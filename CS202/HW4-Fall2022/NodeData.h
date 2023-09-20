/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Implementation of Red-Black Node
*/

class NodeData {
public:
    NodeData();
    NodeData(int nodeItem, int leftChildItem, int rightChildItem, int nodeColor);
    int left, right, item, color;
 //   bool hasTwoChild, hasOneChild, isLeaf;

    friend class RBTree;
};

