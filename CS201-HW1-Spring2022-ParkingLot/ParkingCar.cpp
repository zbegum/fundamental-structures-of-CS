/*
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201 - HW-1
 *
 **/

#include "ParkingCar.h"

using namespace std;

ParkingCar::ParkingCar(){}

ParkingCar::ParkingCar(string loc, string carType, int plate){
    location = loc;
    type = carType.at(0);
    plateNum = plate;
}

ParkingCar::~ParkingCar(){}

int ParkingCar::getLocationRow(){
    return location.at(0) - 65;
}

int ParkingCar::getLocationColumn(){
    return location.at(1) - 49;
}

int ParkingCar::getPlateNumber(){
    return plateNum;
}

char ParkingCar::getCarType(){
    return type;
}

string ParkingCar::getCarLocation(){
    return location;
}

