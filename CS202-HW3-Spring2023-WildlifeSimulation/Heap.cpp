/**
* Title : Heaps and Priority Queues
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 3
* Description : Implementations of max and min heaps
*/

#include "Heap.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap(){
    items = new Food[MAX_ITEMS];
    size = 0;
}

MinHeap::~MinHeap(){
    delete [] items;
}

int MinHeap::getLeftChildIndex(int nodeIndex) const{
    return 2 * nodeIndex + 1;
}

int MinHeap::getRightChildIndex(int nodeIndex) const{
    return 2 * nodeIndex + 2;
}

int MinHeap::getParentIndex(int nodeIndex) const{
    return (nodeIndex - 1) / 2;
}

bool MinHeap::isLeaf(int nodeIndex) const{
    return (nodeIndex >= size / 2) && (nodeIndex < size);
}

void MinHeap::heapRebuild(int root){
    int child = 2 * root + 1; // index of root's left child, if any
    if ( child < size ) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1; // index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChild < size) && (items[rightChild].spawnTime < items[child].spawnTime) )
            child = rightChild; // index of smaller child
        // If root’s item is bigger than smaller child, swap values
        if ( items[root].spawnTime > items[child].spawnTime ) {
            Food temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}

bool MinHeap::isEmpty(){
    return size == 0;
}

int MinHeap::getNumberOfNodes(){
    return size;
}

Food* MinHeap::getItems(){
    return items;
}

void MinHeap::heapInsert(const Food& newItem){
    if (size >= MAX_ITEMS) { cout << "HeapException: Heap full" << endl; }
    else{
        // Place the new item at the end of the heap
        items[size] = newItem;
        // Trickle new item up to its proper position
        int place = size;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place].spawnTime < items[parent].spawnTime) ) {
        Food temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;
        place = parent;
        parent = (place - 1)/2;
        }
        ++size;
    }
}

void MinHeap::heapDelete(Food& rootItem){
	if (size == 0) { cout << "HeapException: Heap empty" << endl; }
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	}
}

//==================================================================
MaxHeap::MaxHeap(){
    items = new Food[MAX_ITEMS];
    size = 0;
}

MaxHeap::~MaxHeap(){
    delete [] items;
}

int MaxHeap::getLeftChildIndex(int nodeIndex) const{
    return 2 * nodeIndex + 1;
}

int MaxHeap::getRightChildIndex(int nodeIndex) const{
    return 2 * nodeIndex + 2;
}

int MaxHeap::getParentIndex(int nodeIndex) const{
    return (nodeIndex - 1) / 2;
}

bool MaxHeap::isLeaf(int nodeIndex) const{
    return (nodeIndex >= size / 2) && (nodeIndex < size);
}

void MaxHeap::heapRebuild(int root){
    int child = 2 * root + 1; // index of root's left child, if any
    if ( child < size ) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1; // index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChild < size) && (items[rightChild].quality > items[child].quality) )
            child = rightChild; // index of larger child
        // If root’s item is smaller than larger child, swap values
        if ( items[root].quality < items[child].quality ) {
            Food temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}

bool MaxHeap::isEmpty(){
    return size == 0;
}

int MaxHeap::getNumberOfNodes(){
    return size;
}

Food* MaxHeap::getItems(){
    return items;
}

void MaxHeap::heapInsert(const Food& newItem){
    if (size >= MAX_ITEMS) { cout << "HeapException: Heap full" << endl; }
    else{
        // Place the new item at the end of the heap
        items[size] = newItem;
        // Trickle new item up to its proper position
        int place = size;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place].quality >= items[parent].quality) ) {
        Food temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;
        place = parent;
        parent = (place - 1)/2;
        }
        ++size;
    }
}

void MaxHeap::heapDelete(Food& rootItem){
	if (size == 0) { cout << "HeapException: Heap empty" << endl; }
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	}
}
