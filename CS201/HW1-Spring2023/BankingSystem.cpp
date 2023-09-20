/**
* Title : Banking System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 2
* Assignment : 1
* Description : Implementation of the functionalities of a banking system
*/

#include <iomanip>
#include "BankingSystem.h"

BankingSystem::BankingSystem(){
    branches = new Branch*[MAX_BRANCHES];
    customers = new Customer*[MAX_CUSTOMERS];
    accounts = new Account*[MAX_ACCOUNTS];
    numOfBranches = 0;
    numOfCustomers = 0;
    numOfAccounts = 0;
}

BankingSystem::~BankingSystem(){
    for(int i = 0; i < numOfBranches; i++){
        delete branches[i];
    }
    for(int i = 0; i < numOfCustomers; i++){
        delete customers[i];
    }
    for(int i = 0; i < numOfAccounts; i++){
        delete accounts[i];
    }
    delete [] branches;
    delete [] customers;
    delete [] accounts;
}

void BankingSystem::addBranch( const int branchId, const string branchName ){
    if(searchBranch(branchId) != -1) {
        cout << "Branch " << branchId << " already exists" << endl;
    }
    else{
        if(numOfBranches >= MAX_BRANCHES){ enlargeBranches(); }
        branches[numOfBranches] = new Branch(branchId, branchName);
        numOfBranches++;
        cout << "Branch " << branchId << " has been added" << endl;
    }
}

void BankingSystem::deleteBranch( const int branchId ){
    int index = searchBranch(branchId);
    if(index != -1) {
        //delete all accounts in this branch
        for(int i = 0; i < numOfAccounts; i++){
            if((accounts[i]->getBranch())->getId() == branchId){
                delete accounts[i];
                // shift elements to the left
                for(int j = i; j < numOfAccounts - 1; j++){
                    accounts[j] = accounts[j + 1];
                }
                numOfAccounts--;
                i--; // skip over the shifted element
            }
        }

        //delete branch
        delete branches[index];
        branches[index] = branches[numOfBranches - 1];
        numOfBranches--;
        cout << "Branch " << branchId << " has been deleted" << endl;
    }
    else{
        cout << "Branch " << branchId << " does not exist" << endl;
    }
}

void BankingSystem::addCustomer( const int customerId, const string customerName ){
    if(searchCustomer(customerId) != -1) {
        cout << "Customer " << customerId << " already exists"<< endl;
    }
    else{
        if(numOfCustomers >= MAX_CUSTOMERS){ enlargeCustomers(); }
        customers[numOfCustomers] = new Customer(customerId, customerName);
        numOfCustomers++;
        cout << "Customer " << customerId << " has been added" << endl;
    }
}

void BankingSystem::deleteCustomer( const int customerId ){
    int index = searchCustomer(customerId);
    if(index != -1) {
        // delete all accounts of customer
        for(int i = 0; i < numOfAccounts; i++){
            if((accounts[i]->getCustomer())->getId() == customerId){
                delete accounts[i];
                // shift elements to the left
                for(int j = i; j < numOfAccounts - 1; j++){
                    accounts[j] = accounts[j + 1];
                }
                numOfAccounts--;
                i--; // skip over the shifted element
            }
        }
        //delete customer
        delete customers[index];
        customers[index] = customers[numOfCustomers - 1];
        numOfCustomers--;
        cout << "Customer " << customerId << " has been deleted" << endl;
    }
    else{
        cout << "Customer " << customerId << " does not exist" << endl;
    }
}


int BankingSystem::addAccount( const int branchId, const int customerId, const double amount ){
    int branchIndex = searchBranch(branchId);
    if (branchIndex == -1) {
        cout << "Branch " << branchId << " does not exist" << endl;
        return -1;
    }
    int customerIndex = searchCustomer(customerId);
    if (customerIndex == -1) {
        cout << "Customer " << customerId << " does not exist" << endl;
        return -1;
    }
    if(numOfAccounts >= MAX_ACCOUNTS){ enlargeAccounts(); }
    Account* newAcc = new Account(branches[branchIndex], customers[customerIndex], amount);
    accounts[numOfAccounts] = newAcc;
    numOfAccounts++;
    cout << "Account " << newAcc->getId() << " added for customer " << customerId << " at branch " << branchId << endl;
    return accounts[numOfAccounts-1]->getId();
}

void BankingSystem::deleteAccount( const int accountId ){
    int accountIndex = -1;
    for(int i = 0; i < numOfAccounts; i++){
        if (accounts[i]->getId() == accountId) {
            accountIndex = i;
            break;
        }
    }
    if(accountIndex == -1) { cout << "Account " << accountId << " does not exist" << endl; }
    else{
        delete accounts[accountIndex];
        // shift elements to the left
        for(int i = accountIndex; i < numOfAccounts - 1; i++){
              accounts[i] = accounts[i + 1];
        }
        numOfAccounts--;
        cout << "Account " << accountId << " has been deleted" << endl;
    }
}

void BankingSystem::showAllAccounts(){
    cout << "Account id Branch id Branch name Customer id Customer name Balance" << endl;
    for(int i = 0; i < numOfAccounts; i++){
        int id = accounts[i]->getId();
        int b_id = (accounts[i]->getBranch())->getId();;
        string b_name = branches[searchBranch(b_id)]->getName();
        int c_id = (accounts[i]->getCustomer())->getId();
        string c_name = customers[searchCustomer(c_id)]->getName();
        double bal = accounts[i]->getDeposit();
        std::cout << std::fixed << std::showpoint;
        std::cout << std::setprecision(2);
        cout << id << " " << b_id << " " << b_name << " " << c_id << " " << c_name << " " <<  bal << endl;
    }
}

void BankingSystem::showBranch( const int branchId ){
    int index = searchBranch(branchId);
    if( index == -1 ) { cout << "Branch " << branchId << " does not exist" << endl; }
    else{
        Branch* myBranch = branches[index];
        int totalAccInBranch = 0;
        for(int i = 0; i < numOfAccounts; i++){
            if((accounts[i]->getBranch())->getId() == branchId){
                totalAccInBranch = totalAccInBranch + 1;
            }
        }
        cout << "Branch id: " << branchId << " Branch name: " <<  myBranch->getName() << " Number of accounts: " << totalAccInBranch << endl;
        if(totalAccInBranch != 0){
            cout << "Accounts at this branch:" << endl;
            cout << "Account id Customer id Customer name Balance" << endl;
            for(int i = 0; i < numOfAccounts; i++){
                if((accounts[i]->getBranch())->getId() == branchId){
                    int id = accounts[i]->getId();
                    int c_id = (accounts[i]->getCustomer())->getId();
                    string c_name = customers[searchCustomer(c_id)]->getName();
                    double bal = accounts[i]->getDeposit();
                    std::cout << std::fixed << std::showpoint;
                    std::cout << std::setprecision(2);
                    cout << id << " " << c_id << " " << c_name << " " << bal << endl;
                }
            }
        }
    }

}
void BankingSystem::showCustomer( const int customerId ){
    int index = searchCustomer(customerId);
    if( index == -1 ) { cout << "Customer " << customerId << " does not exist" << endl; }
    else{
        Customer* myCustomer = customers[index];
        int totalAccOfCustomer = 0;
        for(int i = 0; i < numOfAccounts; i++){
            if((accounts[i]->getCustomer())->getId() == customerId){
                totalAccOfCustomer = totalAccOfCustomer + 1;
            }
        }
        cout << "Customer id: " << customerId << " Customer name: " <<  myCustomer->getName() << " Number of accounts: " << totalAccOfCustomer << endl;
        if(totalAccOfCustomer != 0){
            cout << "Accounts of this customer:" << endl;
            cout << "Account id Branch id Branch name Balance" << endl;
            for(int i = 0; i < numOfAccounts; i++){
                if((accounts[i]->getCustomer())->getId()== customerId){
                    int id = accounts[i]->getId();
                    int b_id = (accounts[i]->getBranch())->getId();
                    string b_name = branches[searchBranch(b_id)]->getName();
                    double bal = accounts[i]->getDeposit();
                    std::cout << std::fixed << std::showpoint;
                    std::cout << std::setprecision(2);
                    cout << id << " " << b_id << " " << b_name << " " << bal << endl;
                }
            }
        }
    }

}

//=====================HELPER FUNCTIONS===========================
void BankingSystem::enlargeBranches(){
    MAX_BRANCHES = MAX_BRANCHES * 2;
    Branch** newArr = new Branch*[MAX_BRANCHES];
    for(int i = 0; i < numOfBranches; i++){
        newArr[i] = branches[i];
    }
    delete [] branches;
    branches = newArr;
}

int BankingSystem::searchBranch(int branchId){
    for(int i = 0; i < numOfBranches; i++){
        if( branches[i]->getId() == branchId) { return i; }
    }
    return -1;
}

void BankingSystem::enlargeCustomers(){
    MAX_CUSTOMERS = MAX_CUSTOMERS * 2;
    Customer** newArr = new Customer*[MAX_CUSTOMERS];
    for(int i = 0; i < numOfCustomers; i++){
        newArr[i] = customers[i];
    }
    delete [] customers;
    customers = newArr;
}

int BankingSystem::searchCustomer(int customerId){
    for(int i = 0; i < numOfCustomers; i++){
        if( customers[i]->getId() == customerId) { return i; }
    }
    return -1;
}

void BankingSystem::enlargeAccounts(){
    MAX_ACCOUNTS = MAX_ACCOUNTS * 2;
    Account** newArr = new Account*[MAX_ACCOUNTS];
    for(int i = 0; i < numOfAccounts; i++){
        newArr[i] = accounts[i];
    }
    delete [] accounts;
    accounts = newArr;
}

int BankingSystem::searchAccount(int accountId){
    for(int i = 0; i < numOfAccounts; i++){
        if( accounts[i]->getId() == accountId) { return i; }
    }
    return -1;
}
