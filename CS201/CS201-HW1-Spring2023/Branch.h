/**
* Title : Banking System
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 2
* Assignment : 1
* Description : Representation of a Branch
*/

#include <string>
#include <iostream>

using namespace std;


class Branch {
    private:
        string name;
        int id;

    public:
        Branch();
        Branch( int branchId, string branchName );
        ~Branch();
        void setName( string branchName );
        string getName();
        int getId();
};
