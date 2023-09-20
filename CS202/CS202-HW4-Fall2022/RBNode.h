/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Representation of a Red-Black Node
*/

using namespace std;

class RBNode {
public:
    RBNode();
    RBNode( int nodeItem, RBNode* leftChildPtr,  RBNode* rightChildPtr, int nodeColor);
    RBNode* leftChildPtr;
    RBNode* rightChildPtr;
    int nodeItem;
    int nodeColor;  // 0 : red   1 : black

    friend class RBTree;
};
