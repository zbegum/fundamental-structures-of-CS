/**
* Title: Balanced search trees and hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS202 - 1
* Homework : 4
* Description : Implementation of snack object, accompaniying snacks property is being stored as a linked list
*/

#include "Snack.h"

Snack::Snack(){
    name = "";
    accompaniments = NULL;
}

Snack::Snack(string name){
    this->name = name;
    accompaniments = NULL;
}

void Snack::insertAccompaniyingSnack(Snack* snack){
    if(findAccompaniyingSnack(snack->getName()) == nullptr) {
        if(snack->getName() == this->name) { return; }      // an snack cannot be accompaniying of that snack, its already itself
        SnackNode* newNode = new SnackNode;
        newNode->snack = snack;
        newNode->next = accompaniments;
        accompaniments = newNode;                           // insert into beginning of the list
    }
}

void Snack::deleteAccompaniyingSnack(Snack* snack){
    if(snack->getName() == this->name) { return; }
    SnackNode* curr = accompaniments;
    SnackNode* prev = nullptr;

    // traverse the accompaniments
    while (curr != nullptr) {
        // search item to be deleted
        if (curr->snack == snack) {
            if (prev != nullptr) { prev->next = curr->next; } // delete internal node
            else { accompaniments = curr->next; }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

Snack* Snack::findAccompaniyingSnack(string snackName){
    SnackNode* curr = accompaniments;
    while (curr != nullptr) {
        if (curr->snack->getName() == snackName) {
            return curr->snack;
        }
        curr = curr->next;
    }
    return nullptr;
}

void Snack::listAccompaniments(){
    SnackNode* curr = accompaniments;
    while (curr != nullptr) {
        cout << curr->snack->getName() << " ";
        curr = curr->next;
    }
    cout << endl;
}

string Snack::getName(){
    return name;
}
