/**
* Title : Banking System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 2
* Assignment : 1
* Description : Representation of a Customer in Bank
*/

#include <string>
#include <iostream>

using namespace std;

class Customer{
    private:
        string name;
        int id;

    public:
        Customer();
        Customer( int customerId, string customerName );
        ~Customer();
        string getName();
        int getId();
};
