/**
* Title : Heaps and Priority Queues
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 3
* Description : A creature from wildlife simulation
*/

#include "PriorityQueue.h"

class Creature{
public:
    Creature();
    Creature(int id, double x_coordinate, double y_coordinate, int health);

    void killOthers(Creature** arr, int size);
    bool lookForFood(Food& bestFood);
    void consumeFood(Food& bestFood);
    void move(const double& x, const double& y);
    bool isDead();

    int getId();
    double getX();
    double getY();
    int getHealth();
    void setHealth(int health);
    void decreaseHealth();
    bool isHungry();
    void setHunger(bool hungry);


private:
    int id;
    double x_coordinate;
    double y_coordinate;
    int health;
    bool hungry;

};

