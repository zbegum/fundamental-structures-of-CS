/*
 *  Zeynep Begum Kara
 *  ID: 22003880
 *  CS201 - HW-1
 *
 **/

#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include <iostream>

using namespace std;

// Declare my classes
class ParkingSystem;
class ParkingLot;
class ParkingSlot;

class ParkingSystem
{
public:
    ParkingSystem();
    ~ParkingSystem();

    void createLot(int id, int rows, int columns);
    void removeLot(int id);
    void listLots();
    void lotContents(int id);
    void parkCar(int lotId, string location, string carType, int plateNumber);
    void findCar(int plateNumber);
    void removeCar(int plateNumber);
    void resizeSystem();
    void enlargeSystem();
    void reduceSystem(int seachedLotIndex);

private:
    int numOfLots; //size of lotSystem arr
    ParkingLot *lotSystem;
};

#endif // PARKINGSYSTEM_H
