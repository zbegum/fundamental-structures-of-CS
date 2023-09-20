/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Implementation of Red-Black Tree Class
*/

#include "RBTree.h"
#include <iostream>

RBTree::RBTree(){root = NULL; numOfNodes = 0;}

void RBTree::constructTree( int rootNodeItem, NodeData** data, int numOfNodes){
    if (rootNodeItem != -1){
        cout << "new item inserted: " << rootNodeItem << endl;
        NodeData* node = findNodeData(rootNodeItem, data, numOfNodes);
        insertItem( root, node );
        constructTree ( node->left, data, numOfNodes );
        constructTree ( node->right, data, numOfNodes );
    }
}

void RBTree::insertItem(RBNode*& treePtr, NodeData* newItem){
    if (treePtr == NULL) { // Empty tree
        treePtr = new RBNode(newItem->item, NULL, NULL, newItem->color);
        numOfNodes++;
    }
    // Else search for the insertion position
    else if (newItem->item < treePtr->nodeItem){
        insertItem(treePtr->leftChildPtr, newItem);
    }
    else{
        insertItem(treePtr->rightChildPtr, newItem);
    }
}

NodeData* RBTree::findNodeData(int key, NodeData** nodes, int countNodes){
    for( int i = 0; i < countNodes; i++){
        if(nodes[i]->item == key){
            return nodes[i];
        }
    }
    return NULL;
}

void RBTree::printInorder(RBNode*& treePtr){
    if (treePtr == NULL)
        return;

    printInorder(treePtr->leftChildPtr);

    cout << treePtr->nodeItem << " ";
    if (treePtr->leftChildPtr != NULL) { cout << (treePtr->leftChildPtr)->nodeItem << " "; }
    else { cout << -1 << " "; }
    if (treePtr->rightChildPtr != NULL) { cout << (treePtr->rightChildPtr)->nodeItem << " "; }
    else { cout << -1 << " "; }
    cout << treePtr->nodeColor << endl;

    printInorder(treePtr->rightChildPtr);
}
