/**
* Title : Heaps and Priority Queues
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 3
* Description : Implementation of creature
*/

#include "Creature.h"
#include <cmath>
#include <iostream>
using namespace std;

Creature::Creature(){}

Creature::Creature(int id, double x_coordinate, double y_coordinate, int health){
    this->id = id;
    this->x_coordinate = x_coordinate;
    this->y_coordinate = y_coordinate;
    this->health = health;
    hungry = true;
}

void Creature::killOthers(Creature** arr, int size){
    for (int i = 0; i < size; i++) {
        if ((arr[i]->getId() != id) && !arr[i]->isDead()) {
            double distance = sqrt(pow(x_coordinate - arr[i]->getX(), 2) + pow(y_coordinate - arr[i]->getY(), 2));
            if (distance < 2 && arr[i]->getHealth() <= health) {
                arr[i]->setHealth(0);
                // cout << "****somebody died**** : " << id << " killed " <<  arr[i]->id << endl;
            }
        }
    }
}

bool Creature::lookForFood(Food& bestFood){
    if(!hungry) {return false;}
    if(this->isDead()) {return false;}
    else{
        double distance = sqrt(pow(x_coordinate - bestFood.x_coordinate, 2) + pow(y_coordinate - bestFood.y_coordinate, 2));
        if (distance < 1) { return true; }
        return false;
    }
}

void Creature::consumeFood(Food& bestFood){
    health = health + bestFood.quality;
    hungry = false;
}

void Creature::move(const double& x, const double& y){
    x_coordinate = x;
    y_coordinate = y;
}

bool Creature::isDead(){
    return health == 0;
}

int Creature::getId(){
    return id;
}

double Creature::getX(){
    return x_coordinate;
}

double Creature::getY(){
    return y_coordinate;
}

int Creature::getHealth(){
    return health;
}

void Creature::setHealth(int health){
    this->health = health;
}

void Creature::decreaseHealth(){
    if(!this->isDead())
        health--;
}

bool Creature::isHungry(){
    return hungry;
}

void Creature::setHunger(bool hungry){
    this->hungry = hungry;
}
