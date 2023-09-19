/**
* Title : Heaps and Priority Queues
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 3
* Description : Heap based implementation of prioity queue
*/

#include "PriorityQueue.h"
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue(){ }

PriorityQueue::PriorityQueue(bool prioritizeMax){
    if(prioritizeMax){
        maxHeap = new MaxHeap();
        minHeap = NULL;
    }
    else{
        minHeap = new MinHeap();
        maxHeap = NULL;
    }
    isMaxHeap = prioritizeMax;
}

PriorityQueue::~PriorityQueue(){
    if(isMaxHeap){
        delete maxHeap;
    }
    else{
        delete minHeap;
    }

}

bool PriorityQueue::isEmpty(){
    if(isMaxHeap){
        return maxHeap->isEmpty();
    }
    else{
        return minHeap->isEmpty();
    }
}

void PriorityQueue::enqueue(const Food& food){
    if(isMaxHeap){
        maxHeap->heapInsert(food);
    }
    else{
        minHeap->heapInsert(food);
    }
}

void PriorityQueue::dequeue(Food& food){
    if(isMaxHeap){
        maxHeap->heapDelete(food);
    }
    else{
        minHeap->heapDelete(food);
    }
}

Food PriorityQueue::peek(){
    if(isMaxHeap && maxHeap->getNumberOfNodes() != 0){
        return maxHeap->getItems()[0];
    }
    else if (!isMaxHeap && minHeap->getNumberOfNodes() != 0){
        return minHeap->getItems()[0];
    }
    else{
        cout << "--Invalid request" << endl;
        return Food();
    }
}

int PriorityQueue::getNumberOfNodes(){
    if(isMaxHeap){
        return maxHeap->getNumberOfNodes();
    }
    else{
        return minHeap->getNumberOfNodes();
    }
}
