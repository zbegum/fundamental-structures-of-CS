/**
* Title : Banking System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 2
* Assignment : 1
* Description : Implementation of functionalities of a Customer in Banking System
*/

#include "Customer.h"

Customer::Customer(){
    name = "";
    id = 0;
}

Customer::Customer( int customerId, string customerName ){
    name = customerName;
    id = customerId;
}

Customer::~Customer(){}


int Customer::getId(){
    return id;
}

string Customer::getName(){
    return name;
}
