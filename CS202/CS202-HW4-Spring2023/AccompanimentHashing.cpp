/**
* Title: Balanced search trees and hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS202 - 1
* Homework : 4
* Description : Implementation of Accompaniment Hashing, quadratic probing is used and table is 71 for the purposes of this assignment
*/

#include "AccompanimentHashing.h"

AccompanimentHashing::AccompanimentHashing(){
    table = new Accompaniment*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = nullptr;
}

/**  hashFunction -> sum of the ASCII values of the snack name  **/
int AccompanimentHashing::hashFunction(string accompanimentName){
    int sum = 0;
    for (char ch : accompanimentName) {
        sum += (int)ch;
    }
    return sum % TABLE_SIZE;
}

void AccompanimentHashing::insertAccompaniment(Accompaniment* accompaniment) {
    // avoid to insert existing accompaniment
    if(findAccompaniment(accompaniment->getName()) == nullptr){
        int index = hashFunction(accompaniment->getName());
        int i = 0;

        // if insertion place is empty, insert
        // else prob insertion place quadratically
        while (table[index] != nullptr) {
            // quadratic probing
            index = (index + i * i) % TABLE_SIZE;
            i++;

            // if the table is full, exit the loop
            if (i >= TABLE_SIZE){
                cout << "Table is full" << endl;
                return;
            }
        }
        table[index] = accompaniment;
    }
}

void AccompanimentHashing::deleteAccompaniment(Accompaniment* accompaniment){
    string accompanimentName = accompaniment->getName();
    int index = hashFunction(accompanimentName);
    int i = 0;

    while (table[index] != nullptr) {
        // quadratic probing
        index = (index + i * i) % TABLE_SIZE;
        i++;

        // avoid infinite loop when table is full
        // or the accompaniment is found, delete it
        if (i >= TABLE_SIZE || table[index]->getName() == accompanimentName) {
            delete table[index];
            table[index] = nullptr;
            return;

        }
    }
}

Accompaniment* AccompanimentHashing::findAccompaniment(string accompanimentName) {
    int index = hashFunction(accompanimentName);
    int i = 0;
    while (i < TABLE_SIZE) {
        // quadratic probing
        index = (index + i * i) % TABLE_SIZE;
        i++;

        // if the accompaniment is found, return it
        if (table[index] != nullptr && table[index]->getName() == accompanimentName) {
            return table[index];
        }
        else if(table[index] != nullptr){
            return nullptr;  // not found
        }
    }
    return nullptr;  // not found
}
