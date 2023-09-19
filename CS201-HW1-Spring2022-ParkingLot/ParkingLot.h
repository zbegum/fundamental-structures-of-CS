/*
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201 - HW-1
 *
 **/

#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <iostream>
using namespace std;

// Declare my classes
class ParkingSystem;
class ParkingCar;

class ParkingLot
{
public:
    ParkingLot();
    ParkingLot(int id, int rowNum, int colNum );
    ~ParkingLot();

    void displayLot();
    void addCar(string location, string carType, int plate);
    void updateSlot(string loc, char ch);
    void updateSlotB(string loc, char ch);

    int lotID;
    int rows;
    int columns;
    char **arr;
    int numOfCars;
    ParkingCar *cars;
    int freeSpace;
};

#endif // PARKINGLOT_H

