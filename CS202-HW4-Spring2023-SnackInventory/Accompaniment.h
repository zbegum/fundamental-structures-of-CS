/**
* Title: Balanced search trees and hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS202 - 1
* Homework : 4
* Description : Definition of an accompaniment object
*/

#include "SnackHashing.h"

class Accompaniment{
private:
    string name;
    Snack* snackPtr1;
    Snack* snackPtr2;

public:
    Accompaniment();
    Accompaniment(Snack* snack1, Snack* snack2);
    string getName();
    Snack* getSnackPtr1();
    Snack* getSnackPtr2();

};

