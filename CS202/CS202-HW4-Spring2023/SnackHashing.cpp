/**
* Title: Balanced search trees and hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS202 - 1
* Homework : 4
* Description : Implementation of Snack Hashing, separate chaining is used and table is 11 for the purposes of this assignment
*/

#include "SnackHashing.h"
#include <iostream>

SnackHashing::SnackHashing(){
    table = new SnackNode* [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = nullptr;
}

/**  hashFunction -> sum of the ASCII values of the snack name  **/
int SnackHashing::hashFunction(string snackName){
    int sum = 0;
    for (char ch : snackName) {
        sum += (int)ch;
    }
    return sum % TABLE_SIZE;
}

void SnackHashing::insertSnack(Snack* snack) {
    // create node
    SnackNode* newNode = new SnackNode;
    newNode->snack = snack;
    newNode->next = nullptr;

    // find index to be inserted
    int index = hashFunction(snack->getName());

    if (table[index] == nullptr) { table[index] = newNode; }    // if the place is occupied, make chain
    else {
        SnackNode* cur = table[index];                         // insert new node to the end of the linked list of the slot table[index]
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    cout << "Snack '" << snack->getName() << "' created" << endl;
}


Snack* SnackHashing::findSnack(string snackName) {
    int index = hashFunction(snackName);

    // traverse the linked list at the slot table[index]
    SnackNode* cur = table[index];
    while (cur != nullptr) {
        if (cur->snack->getName() == snackName) {
            return cur->snack;
        }
        cur = cur->next;
    }

    return nullptr;    // not found
}
