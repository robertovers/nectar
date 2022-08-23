#ifndef PLANT_CPP
#define PLANT_CPP

#include "plant.hpp"
#define INITIAL_POLLINATION_STATUS false;

Plant::~Plant(){}

Plant::Plant(){
    pollinated=INITIAL_POLLINATION_STATUS;
}

Plant::Plant(float x, float y): Agent(x,y){
    pollinated=INITIAL_POLLINATION_STATUS;
}

void Plant::pollinate(){
    pollinated=true;
}

#endif