/**
* Title: Balanced search trees and hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS202 - 1
* Homework : 4
* Description : Implementation of Accompaniment object
*/

#include "Accompaniment.h"

Accompaniment::Accompaniment(){
    name = "";
    snackPtr1 = nullptr;
    snackPtr2 = nullptr;
}


Accompaniment::Accompaniment(Snack* snack1, Snack* snack2){
    name = snack1->getName() + snack2->getName();
    snackPtr1 = snack1->findAccompaniyingSnack(snack2->getName());
    snackPtr2 = snack2->findAccompaniyingSnack(snack1->getName());
}

string Accompaniment::getName(){
    return name;
}

Snack* Accompaniment::getSnackPtr1(){
    return snackPtr1;
}

Snack* Accompaniment::getSnackPtr2(){
    return snackPtr2;
}

