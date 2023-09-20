/*
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201 - HW-1
 *
 **/

#ifndef PARKINGCAR_H
#define PARKINGCAR_H

#include <string>
using namespace std;

// Declare my classes
class ParkingSystem;
class ParkingLot;

class ParkingCar
{
public:
     ParkingCar();
     ParkingCar(string loc, string carType, int plate);
    ~ParkingCar();

    int getLocationRow();
    int getLocationColumn();
    int getPlateNumber();
    char getCarType();
    string getCarLocation();

private:
    char type;
    int plateNum;
    string location;
};

#endif // PARKINGCAR_H
