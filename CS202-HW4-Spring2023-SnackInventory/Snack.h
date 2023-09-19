/**
* Title: Balanced search trees and hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS202 - 1
* Homework : 4
* Description : Definition of a Snack object,
*               to avoid circular dependency struct SnackNode is being utilized in linked list of accompaniments
*/

#include <string>
#include <iostream>

using namespace std;

class Snack{
private:
    string name;
    struct SnackNode {
        Snack* snack;
        SnackNode* next;
    };
    SnackNode* accompaniments;

public:
    Snack();
    Snack(string name);
    void insertAccompaniyingSnack(Snack* snack);
    void deleteAccompaniyingSnack(Snack* snack);
    Snack* findAccompaniyingSnack(string snackName);
    void listAccompaniments();
    string getName();
};

