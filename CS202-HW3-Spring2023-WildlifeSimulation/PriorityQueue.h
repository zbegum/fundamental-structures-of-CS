/**
* Title : Heaps and Priority Queues
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 3
* Description : A priority queue for Foods
*               It is possible to prioritize both food.quality (maxHeap) and food.spawnTime (minHeap) using related heaps
*               by specifying it in the constructor
*/

#include "Heap.h"

class PriorityQueue{
public:
    PriorityQueue();
    PriorityQueue(bool prioritizeMax);
    ~PriorityQueue();
    bool isEmpty();
    void enqueue(const Food& food);
    void dequeue(Food& food);
    Food peek();
    int getNumberOfNodes();

private:
    MaxHeap* maxHeap;
    MinHeap* minHeap;
    bool isMaxHeap;
};
