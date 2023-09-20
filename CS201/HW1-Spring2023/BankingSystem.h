/**
* Title : Banking System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 2
* Assignment : 1
* Description : Representation of a banking system
*/

#include "Account.h"

class BankingSystem {
private:
    Branch** branches;
    Customer** customers;
    Account** accounts;
    int numOfBranches;
    int numOfCustomers;
    int numOfAccounts;
    int MAX_BRANCHES = 5;
    int MAX_CUSTOMERS = 5;
    int MAX_ACCOUNTS = 5;

public:
    BankingSystem();
    ~BankingSystem();
    void addBranch( const int branchId, const string branchName );
    void deleteBranch( const int branchId );
    void addCustomer( const int customerId, const string customerName );
    void deleteCustomer( const int customerId );
    int  addAccount( const int branchId, const int customerId, const double amount );
    void deleteAccount( const int accountId );
    void showAllAccounts();
    void showBranch( const int branchId );
    void showCustomer( const int customerId );
    //helper functions
    void enlargeBranches();
    int searchBranch( int branchId );
    void enlargeCustomers();
    int searchCustomer( int customerId );
    void enlargeAccounts();
    int searchAccount( int accountId );
};
