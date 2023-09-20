/*
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201 - HW-1
 *
 **/

#include "ParkingCar.h"
#include "ParkingLot.h"
#include "ParkingSystem.h"

#include <iostream>
using namespace std;

ParkingSystem::ParkingSystem(){
    numOfLots = 0;
    lotSystem = new ParkingLot[numOfLots];
}

ParkingSystem::~ParkingSystem(){
   for(int i = 0; i < numOfLots; i++)
       delete[] lotSystem[i].cars;;

   for(int i = 0; i < numOfLots; i++){
        for(int j = 0; j < lotSystem[i].rows; j++)
            delete[] lotSystem[i].arr[j];
    }

    for(int i = 0; i < numOfLots; i++)
        delete[] lotSystem[i].arr;

    delete [] lotSystem;
}

void ParkingSystem::createLot(int id, int rows, int columns){
    int isUnique = true;
    for(int i = 0; i < numOfLots; i++){
        if(id == lotSystem[i].lotID){
            isUnique = false;
        }
    }
    if (!isUnique){
        cout << "Cannot create the parking lot " << id << ", a lot with this ID already exists" << endl;
    }
    else {
        ParkingLot* q = new ParkingLot(id, rows, columns);
        if(q->arr == NULL){
            cout << "Cannot create the parking lot " << id << ", dimensions exceed acceptable bounds" << endl;
        }
        else{
            enlargeSystem();
            lotSystem[numOfLots - 1] = *q;
            cout << "Parking lot with ID " << id <<", and dimensions (" << rows << "," << columns << ") has been added to the system" << endl;
        }
        delete q;

    }
}

void ParkingSystem::removeLot(int id){
    int searchedLotIndex = -1;
    for (int i = 0; i < numOfLots; i++){
        if(lotSystem[i].lotID == id){
            searchedLotIndex = i;
        }
    }

    if(searchedLotIndex == -1){
        cout << "Lot " << id <<" is not in the system" <<endl;

    }
    else{
        reduceSystem(searchedLotIndex);
        cout << "Lot " << id << " has been successfully removed from the system" << endl;
    }
}

void ParkingSystem::listLots(){
    if (numOfLots == 0) {cout << "No lots to list" << endl;}
    for(int i = 0; i < numOfLots; i++){
        cout << "ID: " << lotSystem[i].lotID << ", Dim: (" << lotSystem[i].rows << "," << lotSystem[i].columns
        << "), number of empty parking spaces: " << lotSystem[i].freeSpace << endl;
    }
}

void ParkingSystem::parkCar(int lotId, string location, string carType, int plateNumber){
    int indexLot = -1;
    bool isUnique = true;
    for (int i = 0; i < numOfLots; i++){
        //find lot
        if(lotSystem[i].lotID == lotId){
            indexLot = i;
        }
        //check plate number
        for(int k = 0; k < lotSystem[i].numOfCars; k++){
            if(lotSystem[i].cars[k].getPlateNumber() == plateNumber){
                isUnique = false;
            }
        }
    }
    if (indexLot == -1){
        cout << "Lot " << lotId << " is not in the system" << endl;
    }
    else{
        if(isUnique){
            lotSystem[indexLot].addCar(location, carType, plateNumber);
        }
        else{
            cout << "Cannot park -- Plate number already exists:";
            findCar(plateNumber);
        }
    }
}

void ParkingSystem::lotContents (int id){
    for (int i = 0; i < numOfLots; i++){
        if(lotSystem[i].lotID == id){
            cout << "ID: " << lotSystem[i].lotID << ", (" << lotSystem[i].rows << "," << lotSystem[i].columns << "), empty slots: " << lotSystem[i].freeSpace << ", parked cars: ";
            for (int j = 0; j < lotSystem[i].numOfCars; j++){
               cout << lotSystem[i].cars[j].getPlateNumber() << " ";
            }
            if (lotSystem[i].numOfCars == 0) {cout << "no cars yet";}
            cout << endl;
            cout << endl;
            lotSystem[i].displayLot();
        }
    }
}

void ParkingSystem::findCar(int plateNumber){
    bool isFound = false;
     for(int i = 0; i < numOfLots; i++){
        for(int j = 0; j < lotSystem[i].numOfCars; j++){
            if ( lotSystem[i].cars[j].getPlateNumber() == plateNumber){
                isFound = true;
                if(lotSystem[i].cars[j].getCarType() == 'a'){
                    cout <<"Light-duty car with number plate ";
                }
                else{
                     cout <<"Heavy-duty car with number plate ";
                }
                cout << plateNumber << " is at location " <<  lotSystem[i].cars[j].getCarLocation() << ", lot " << lotSystem[i].lotID << endl;
            }
        }
     }
     if (!isFound){
        cout << "The car with number plate " << plateNumber << " is not in the system" << endl;
     }
}

void ParkingSystem::removeCar(int plateNumber){
    bool doesExist = false;
    int whichLot;
    int whichCar;
    char type;
    string loc;
    for(int i = 0; i < numOfLots; i++){
        for(int j = 0; j < lotSystem[i].numOfCars; j++){
            if ( lotSystem[i].cars[j].getPlateNumber() == plateNumber){
                doesExist = true;
                whichLot = i;
                whichCar = j;
                type = lotSystem[i].cars[j].getCarType();
                loc = lotSystem[i].cars[j].getCarLocation();
            }
        }
    }
    if(!doesExist){
        cout << "The car with number plate " << plateNumber <<" is not in the system" <<endl;
    }
    else{
        ParkingCar* tempArr = new ParkingCar[lotSystem[whichLot].numOfCars - 1];
        for(int i = 0; i < whichCar ; i++){
            tempArr[i] = lotSystem[whichLot].cars[i];
        }

        for(int i = whichCar; i + 1 < lotSystem[whichLot].numOfCars ; i++){
            tempArr[i] = lotSystem[whichLot].cars[i + 1];
        }
        lotSystem[whichLot].numOfCars--;
        lotSystem[whichLot].freeSpace++;
        delete [] lotSystem[whichLot].cars;
        lotSystem[whichLot].cars = tempArr;

        if (type == 'a'){
            cout <<"Light-duty car with number plate ";
            lotSystem[whichLot].updateSlot(loc, '+');
        }
        else{
            cout <<"Heavy-duty car with number plate ";
            lotSystem[whichLot].freeSpace++;
            lotSystem[whichLot].updateSlotB(loc, '+');

        }
        cout << plateNumber << " car has been removed from slot " <<  loc << ", lot " << lotSystem[whichLot].lotID << endl;

    }

}

void ParkingSystem::enlargeSystem() {
        ParkingLot* newArr = new ParkingLot[numOfLots + 1];
        for(int i = 0; i < numOfLots; i++){
            newArr[i] = lotSystem[i];
        }
        numOfLots++;
        delete [] lotSystem;
        lotSystem = newArr;
    }

void ParkingSystem::reduceSystem(int removedLotIndex) {
        ParkingLot* newArr = new ParkingLot[numOfLots - 1];
        int j = 0;
        for(int i = 0; i < numOfLots; i++){
            if(i != removedLotIndex) {
                newArr[j] = lotSystem[i];
                j++;
            }
        }

        delete[] lotSystem[removedLotIndex].cars;

        for(int j = 0; j < lotSystem[removedLotIndex].rows; j++){
            delete[] lotSystem[removedLotIndex].arr[j];
        }

        delete[] lotSystem[removedLotIndex].arr;

        numOfLots--;
        delete [] lotSystem;
        lotSystem = newArr;
    }
