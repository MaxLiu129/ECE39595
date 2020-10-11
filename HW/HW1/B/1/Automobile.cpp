#include <iostream>
#include <string>
#include "Automobile.h"

int Automobile::getID(){
    return id;
}

float Automobile::getMileage(){
    return mileage;
}

std::string Automobile::getDate(){
    return maintainDate;
}

Automobile::Automobile(int id_input, float mileage_input, int mm_input, int dd_input, int yy_input){
    id = id_input;
    mileage = mileage_input;
    maintainDate = ""+std::to_string(mm_input)+"/"+std::to_string(dd_input)+"/"+std::to_string(yy_input);
}