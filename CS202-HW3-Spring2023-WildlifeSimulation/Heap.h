/**
* Title : Heaps and Priority Queues
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 3
* Description : This file includes the struct Food and Max/Min Heap definitions for Food
*               Key for Max Heap: quality
*               Key for Min Heap: spawnTime
*/

struct Food{
    int id;
    double x_coordinate;
    double y_coordinate;
    int quality;
    int spawnTime;
};

class MinHeap{
private:
    Food* items;
    int size;
    int MAX_ITEMS = 30;

    int getLeftChildIndex(int nodeIndex) const;
    int getRightChildIndex(int nodeIndex) const;
    int getParentIndex(int nodeIndex) const;
    bool isLeaf(int nodeIndex) const;
    void heapRebuild(int root);

public:
    MinHeap();
    ~MinHeap();
    bool isEmpty();
    int getNumberOfNodes();
    void heapInsert(const Food& newItem);
    void heapDelete(Food& rootItem);
    Food* getItems();
};

class MaxHeap{
private:
    Food* items;
    int size;
    int MAX_ITEMS = 30;

    int getLeftChildIndex(int nodeIndex) const;
    int getRightChildIndex(int nodeIndex) const;
    int getParentIndex(int nodeIndex) const;
    bool isLeaf(int nodeIndex) const;
    void heapRebuild(int root);

public:
    MaxHeap();
    ~MaxHeap();
    bool isEmpty();
    int getNumberOfNodes();
    void heapInsert(const Food& newItem);
    void heapDelete(Food& rootItem);
    Food* getItems();
};


