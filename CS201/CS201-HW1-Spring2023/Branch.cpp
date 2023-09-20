/**
* Title : Banking System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 2
* Assignment : 1
* Description : Implementation of functionalities in a Branch
*/

#include "Branch.h"

Branch::Branch(){
    name = "";
    id = 0;
}

Branch::Branch(int branchId, string branchName){
    name = branchName;
    id = branchId;
}

Branch::~Branch(){}

string Branch::getName(){
    return name;
}

int Branch::getId(){
    return id;
}
