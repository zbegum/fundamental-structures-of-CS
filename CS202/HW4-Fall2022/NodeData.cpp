/**
* Title : Balanced Search Trees and Hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 4
* Description : Implementation of Node Data Class
*/

#include "NodeData.h"

NodeData::NodeData(){}

NodeData::NodeData(int nodeItem, int leftChildItem, int rightChildItem, int nodeColor){
    item = nodeItem;
    left = leftChildItem;
    right = rightChildItem;
    color = nodeColor;
  /*  if( left > 0 && right > 0){
        hasTwoChild = true;
        hasOneChild = false;
        isLeaf = false;
    }
    else if ( left < 0 && right < 0){
        hasTwoChild = false;
        hasOneChild = false;
        isLeaf = true;
    }
    else {
        hasTwoChild = false;
        hasOneChild = true;
        isLeaf = false;
    }*/
}

