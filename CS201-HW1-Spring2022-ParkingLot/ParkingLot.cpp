/*
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201 - HW-1
 *
 **/

#include "ParkingCar.h"
#include "ParkingLot.h"

#include <iostream>
using namespace std;

ParkingLot::ParkingLot(){}

ParkingLot::ParkingLot(int id, int rowNum, int colNum){
        lotID = id;
        rows = rowNum;
        columns = colNum;
        numOfCars = 0;
        freeSpace = rowNum * colNum;

        if(0 < rows && rows < 13 && 0 < columns && columns < 13){
            cars = new ParkingCar[numOfCars];
            arr = new char*[rows];
            for (int i = 0; i < rows; i++){
                arr[i] = new char[columns];
            }
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    arr[i][j] = '+';
                }
            }
        }

        else {
            arr = NULL;
        }
}

ParkingLot::~ParkingLot(){}

void ParkingLot::displayLot(){
        cout << "   ";
        for (int i = 1; i <= columns; i++){
            cout << i << "  ";
        }
        cout << endl;

        for(int i = 0; i < rows; i++){
            cout << (char)(i + 65) << "  ";
            for (int j = 0; j < columns; j++){
                cout << arr[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
}

void ParkingLot::addCar(string location, string carType, int plate){
        ParkingCar* carAdded = new ParkingCar(location, carType, plate);
        if(carType[0] == 97){ //type a
            //control slots
            if( arr[carAdded->getLocationRow()][carAdded->getLocationColumn()] == '+'){
                arr[carAdded->getLocationRow()][carAdded->getLocationColumn()] = 'a'; //update char

                ParkingCar* tempArr = new ParkingCar[numOfCars + 1]; //add car list
                for(int i = 0; i < numOfCars; i++){
                    tempArr[i] = cars[i];
                }
                numOfCars++;
                delete [] cars;
                cars = tempArr;
                cars[numOfCars - 1] = *carAdded;

                cout << "Light-duty car with number plate " << plate <<" has been parked at location " << location << ", lot " << lotID << endl;
                freeSpace--;
            }
            else{
                cout << "Cannot park light-duty car with number plate " << plate << " at location " << location << ", already occupied" << endl;
            }
        }
        else{ //type b
             //control slots
            if(carAdded->getLocationRow() == 0){
                cout << "Cannot park heavy-duty car with number plate " << plate << " at location " << location << ", not enough space" << endl;
            }
            else if(arr[carAdded->getLocationRow()][carAdded->getLocationColumn()] == '+' &&  arr[carAdded->getLocationRow() - 1][carAdded->getLocationColumn()] == '+'){
                arr[carAdded->getLocationRow()][carAdded->getLocationColumn()] = 'b'; //update char
                arr[carAdded->getLocationRow() - 1][carAdded->getLocationColumn()] = 'b'; //update char


                ParkingCar* tempArr = new ParkingCar[numOfCars + 1];
                for(int i = 0; i < numOfCars; i++){
                    tempArr[i] = cars[i];
                }
                numOfCars++;
                delete [] cars;
                cars = tempArr;
                cars[numOfCars - 1] = *carAdded;

                cout << "Heavy-duty car with number plate " << plate <<" has been parked at location " << location << " lot " << lotID << endl;
                freeSpace -= 2;
            }
            else{
                cout << "Cannot park heavy-duty car with number plate " << plate << " at location " << location << ", already occupied" << endl;

            }
        }
        delete carAdded;
}

void ParkingLot::updateSlot(string loc, char ch){
        arr[loc.at(0) - 65][loc.at(1) - 49] = ch;
}

void ParkingLot::updateSlotB(string loc, char ch){
        arr[loc.at(0) - 66][loc.at(1) - 49] = ch;
        arr[loc.at(0) - 65][loc.at(1) - 49] = ch;

}
