/**
* Title : Banking System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 2
* Assignment : 1
* Description : Implementation of functionalities of an Account
*/

#include "Account.h"

int Account::keyCounter = 1;

Account::Account(){
    id = 0;
    branch = NULL;
    customer = NULL;
    deposit = 0;
}

Account::Account( Branch* branch, Customer* customer, double deposit ){
    this->branch = branch;
    this->customer = customer;
    this->deposit = deposit;
    id = keyCounter;
    keyCounter++;
}

Account::~Account(){}

int Account::getId(){
    return id;
}

double Account::getDeposit(){
    return deposit;
}

Branch* Account::getBranch(){
    return branch;
}

Customer* Account::getCustomer(){
    return customer;
}
