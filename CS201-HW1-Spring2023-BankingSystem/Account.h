/**
* Title : Banking System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 2
* Assignment : 1
* Description : Representation of an Account
*/

#include "Customer.h"
#include "Branch.h"

class Account{
    private:
        static int keyCounter;
        int id;
        Branch* branch;
        Customer* customer;
        double deposit;

    public:
        Account();
        Account( Branch* branch, Customer* customer, double deposit );
        ~Account();
        int getId();
        Branch* getBranch();
        Customer* getCustomer();
        double getDeposit();
};

