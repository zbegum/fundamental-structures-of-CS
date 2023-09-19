/**
* Title : Heaps and Priority Queues
* Author : Zeynep Begum Kara
* ID: 22003880
* Section : 1
* Assignment : 3
* Description : Wildlife simulation, each clock represents a time tick
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "Creature.h"

using namespace std;

//===========================================HELPER FUNCTION PROTOTYPES=========================================
void printCreatures(Creature** c, int num);
bool isAllDead(Creature** c, int num);
void calculateCoordinates(double x_i, double y_i, double x_p, double y_p, double h, double& x_f, double& y_f);
//=============================================================================================================

int main(int argc, char** args ) {

    string filename = args[1];
    ifstream input_file(filename);
    string line;
    if (!input_file.is_open()) {
        cout << "Could not open the file - '" << filename << "'" << endl;
    }
    else{
        //create creatures
        int numOfCreatures;
        getline(input_file, line);
        stringstream ss(line);
        ss >> numOfCreatures;
        Creature** creatures = new Creature*[numOfCreatures];

        int id;
        double x_coor;
        double y_coor;
        int health;
        char comma;

        for(int i = 0; i < numOfCreatures; i++){
            getline(input_file, line);
            stringstream ss(line);
            ss >> id >> comma >> x_coor >> comma >> y_coor >> comma >> health;
            creatures[i] = new Creature(id, x_coor, y_coor, health);
        }

        // sort creatures based on their ids
        for(int i = 1; i < numOfCreatures; i++){
            Creature* current = creatures[i];
            int j = i - 1;
            while(j >= 0 && creatures[j]->getId() > current->getId()){
                creatures[j + 1] = creatures[j];
                j--;
            }
            creatures[j + 1] = current;
        }

        PriorityQueue* foods = new PriorityQueue(0); // prioritizes minimum spawn time
        int foodQuality;
        int spawnTime;
        while(getline(input_file, line)){
            stringstream ss(line);
            ss >> id >> comma >> x_coor >> comma >> y_coor >> comma >> foodQuality >> comma >> spawnTime;
            Food newFood = {id, x_coor, y_coor, foodQuality, spawnTime};
            foods->enqueue(newFood);
        }

        PriorityQueue* currentFoods = new PriorityQueue(1); // prioritizes maximum quality

        int countClocks = 0;
        while(!isAllDead(creatures, numOfCreatures)){
          // cout << "==========================================" << endl;
          // cout << "CLOCK " << countClocks << endl;
          // cout << "==========================================" << endl;

            // print creatures
            printCreatures(creatures, numOfCreatures);

            // add available foods
            int i = 0;
            while(i < foods->getNumberOfNodes() && (foods->peek()).spawnTime == countClocks){
                Food temp;
                foods->dequeue(temp);
                currentFoods->enqueue(temp);
            }

            // solve fights
            for(int i = 0; i < numOfCreatures; i++){
                creatures[i]->killOthers(creatures, numOfCreatures);
            }

            // consume food
            Food bestFood;
            bool bestFoodChanged = false;
            do {
                if(currentFoods->getNumberOfNodes() != 0){
                    bestFoodChanged = false;
                    bestFood = currentFoods->peek();
                 // cout << "BEST FOOD IS: " << bestFood.id << endl;
                    for(int i = 0; i < numOfCreatures; i++){
                        if(creatures[i]->lookForFood(bestFood)) {
                            creatures[i]->consumeFood(bestFood);
                            currentFoods->dequeue(bestFood);
                        //  cout << "Creature " << creatures[i]->getId() << " ate " << bestFood.id << endl;
                            bestFoodChanged = true;
                            break;
                        }
                    }
                }
            } while (bestFoodChanged && currentFoods->getNumberOfNodes() != 0);

            // move
            if(currentFoods->getNumberOfNodes() != 0){
                double x_i;
                double y_i;
                double x_p;
                double y_p;
                double x_f;
                double y_f;
                int h;
                bestFood = currentFoods->peek();
                for(int i = 0; i < numOfCreatures; i++){
                    if(!creatures[i]->isDead()){
                        x_i = creatures[i]->getX();
                        y_i = creatures[i]->getY();
                        x_p = bestFood.x_coordinate;
                        y_p = bestFood.y_coordinate;
                        h = creatures[i]->getHealth();
                        calculateCoordinates(x_i, y_i, x_p, y_p, h, x_f, y_f);
                        creatures[i]->move(x_f, y_f);
                    }
                }
            }

            // decrease health and make them hungry
            for(int i = 0; i < numOfCreatures; i++){
                if(!creatures[i]->isDead()){
                    creatures[i]->decreaseHealth();
                    creatures[i]->setHunger(true);
                }
            }
            countClocks++;
        }

        delete foods;
        delete currentFoods;
        for(int i = 0; i < numOfCreatures; i++){
            delete creatures[i];
        }
        delete [] creatures;
    }
    return 0;
}


//==========================HELPER FUNCTIONS===========================
void printCreatures(Creature** c, int num){
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);
    for(int i = 0; i < num; i++){
        cout << "Creature " << c[i]->getId() << ": " << c[i]->getX() << ", " << c[i]->getY() << endl; //" --health: " << c[i]->getHealth();
   //   if(c[i]->isDead()){ cout << " -- DEAD -- " << endl; }
   //   else { cout << endl; }

    }

}

bool isAllDead(Creature** c, int num){
    for(int i = 0; i < num; i++){
        if (!c[i]->isDead()) {return false;}
    }
    return true;
}

void calculateCoordinates(double x_i, double y_i, double x_p, double y_p, double h, double& x_f, double& y_f) {
    double distance;
    if (h <= 10) { distance = 1; } // due to survival instincts
    else { distance = 10 / h; }

    // slope of the vertical line is undefined
    if (x_i == x_p) {
        x_f = x_i;
        y_f = y_i + distance;
    //  cout << "has moved " << distance << "units in y, and x has not changed. " << endl;
        return;
    }

    // calculate the slope of the line that passes from initial coordinates of creature and coordinates of best food
    double slope = (y_i - y_p) / (x_i - x_p);

    // calculate the x and y components of the distance in terms of difference
    double dx;
    double dy;

    dx = abs(distance * sqrt(1.0 / (1.0 + slope * slope)));
    dy = abs(slope * dx);

    // cout << "has moved " << dx << " units in x." << endl;
    // cout << "has moved " << dy << " units in y." << endl;

    // add or subtract components due to the relative positions
    if (x_i < x_p) { x_f = x_i + dx; }
    else { x_f = x_i - dx; }
    if (y_i < y_p) { y_f = y_i + dy; }
    else { y_f = y_i - dy; }
}
