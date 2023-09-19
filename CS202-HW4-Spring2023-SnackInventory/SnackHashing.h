/**
* Title: Balanced search trees and hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS202 - 1
* Homework : 4
* Description : This class includes a hash table
*               which stores Snack objects using hashFunction -> sum of the ASCII values of the snack name
*               separate chaining is used if there exist collisions
*/

#include "Snack.h"

using namespace std;

class SnackHashing{
private:
    const int TABLE_SIZE = 11;
    struct SnackNode {          //nodes for separate chaining
        Snack* snack;
        SnackNode* next;
    };
    SnackNode** table;

public:
    SnackHashing();
    int hashFunction(string snackName);
    void insertSnack(Snack* snack);
    Snack* findSnack(string snackName);

};


