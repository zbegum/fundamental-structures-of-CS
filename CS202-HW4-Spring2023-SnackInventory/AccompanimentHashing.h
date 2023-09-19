/**
* Title: Balanced search trees and hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS202 - 1
* Homework : 4
* Description : This class includes a hash table
*               which stores Accompaniment objects using hashFunction -> sum of the ASCII values of the snack name
*               quadratic probing is used if there exist collisions
*/

#include "Accompaniment.h"

using namespace std;

class AccompanimentHashing{
private:
    const int TABLE_SIZE = 71;
    Accompaniment** table;

public:
    AccompanimentHashing();
    int hashFunction(string accompanimentName);
    void insertAccompaniment(Accompaniment* accompaniment);
    void deleteAccompaniment(Accompaniment* accompaniment);
    Accompaniment* findAccompaniment(string accompanimentName);
};
