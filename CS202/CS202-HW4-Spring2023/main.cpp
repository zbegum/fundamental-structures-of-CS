/**
* Title: Balanced search trees and hashing
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : CS202 - 1
* Homework : 4
* Description : A simple snack inventory application for a kindergarten.
*               Program terminates when input is invalid
*               Assumed any snack name mentioned in an C, D, L, or Q command has been already created by a S command.
*/

#include "AccompanimentHashing.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char** args){

    string filename = args[1];
    ifstream input_file(filename);
    string line;
    if (!input_file.is_open()) {
        cout << "Could not open the file - '" << filename << "'" << endl;
    }

    string command;
    string snackName1;
    string snackName2;
    SnackHashing* snackHashing = new SnackHashing();
    AccompanimentHashing* accompanimentHashing = new AccompanimentHashing();

    do{
        input_file >> command;

        if (command == "S") {
            input_file >> snackName1;
            Snack* newSnack = new Snack(snackName1);
            snackHashing->insertSnack(newSnack);
        }

        else if(command == "C"){
            input_file >> snackName1 >> snackName2;  // assume they are created previously
            if(snackName1 != snackName2){
                Snack* s1 = snackHashing->findSnack(snackName1);
                Snack* s2 = snackHashing->findSnack(snackName2);
                s1->insertAccompaniyingSnack(s2);
                s2->insertAccompaniyingSnack(s1);
                if(accompanimentHashing->findAccompaniment(s1->getName() + s2->getName()) == nullptr
                   && accompanimentHashing->findAccompaniment(s2->getName() + s1->getName()) == nullptr){
                    Accompaniment* acc = new Accompaniment(s1, s2);
                    accompanimentHashing->insertAccompaniment(acc);
                }
            }
        }

        else if(command == "D"){
            input_file >> snackName1 >> snackName2;  // assume they are created previously
            Accompaniment* acc = accompanimentHashing->findAccompaniment(snackName1 + snackName2);
            if (acc != nullptr){
                (acc->getSnackPtr1())->deleteAccompaniyingSnack(acc->getSnackPtr2());
                (acc->getSnackPtr2())->deleteAccompaniyingSnack(acc->getSnackPtr1());
                accompanimentHashing->deleteAccompaniment(acc);
            }
            else{
                Accompaniment* acc = accompanimentHashing->findAccompaniment(snackName2 + snackName1);
                if (acc != nullptr){
                    (acc->getSnackPtr1())->deleteAccompaniyingSnack(acc->getSnackPtr2());
                    (acc->getSnackPtr2())->deleteAccompaniyingSnack(acc->getSnackPtr1());
                    accompanimentHashing->deleteAccompaniment(acc);
                }
            }
        }
        else if(command == "L"){
            input_file >> snackName1;
            (snackHashing->findSnack(snackName1))->listAccompaniments();
        }

        else if (command == "Q"){
            input_file >> snackName1 >> snackName2;  // assume they are created previously
            string str = snackName1 + snackName2;
            string strRev = snackName2 + snackName1;
            if(accompanimentHashing->findAccompaniment(str) == nullptr){
                if(accompanimentHashing->findAccompaniment(strRev) == nullptr){ cout << "No" << endl; }
                else{cout << "Yes" << endl;}
            }
            else{ cout << "Yes" << endl; }
        }

        else if(command == "X") { break; }

        else{
            cout << "command not found -- program has terminated" << endl;
        }

    }while(command == "S" ||command == "C" || command == "D" || command == "L" || command == "Q");

    return 0;
}
