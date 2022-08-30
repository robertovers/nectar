#ifndef PLANT_CPP
#define PLANT_CPP

#include "plant.hpp"
#define INITIAL_POLLINATION_STATUS false;
#define DEFAULT_GENDER 0;

Plant::~Plant(){}

Plant::Plant(int x, int y) : Location(x, y) {
    pollinated=INITIAL_POLLINATION_STATUS;
    gender = 0;
}

void Plant::pollinate(){
    pollinated=true;
}

#endif