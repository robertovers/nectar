#ifndef SOYBEAN_CPP
#define SOYBEAN_CPP

#include "soybean.hpp"
#include <iostream>
#define GENDER 3

Soybean::~Soybean(){}

Soybean::Soybean(){
    gender=GENDER;
}

Soybean::Soybean(float x,float y): Plant(x,y){  
    gender=GENDER;
}

void Soybean::update(Environment env){
}

void Soybean::draw(sf::RenderWindow& window){
}
















#endif