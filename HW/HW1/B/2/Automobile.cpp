#include <iostream>
#include <string>
#include "Automobile.h"

int Automobile::getID(){
    return id;
}

float Automobile::getMileage(){
    return mileage;
}

int Automobile::getmm(){
    return month;
}

int Automobile::getdd(){
    return date;
}

int Automobile::getyy(){
    return year;
}

Automobile::Automobile(int id_input, float mileage_input, int mm_input, int dd_input, int yy_input){
    id = id_input;
    mileage = mileage_input;
    month = mm_input;
    date = dd_input;
    year = yy_input;
}

std::string Automobile::printthings( ){
    std::string result = "the car's ID is:" + std::to_string (id) + "\n";
    result += "the car's mileage is:" + std::to_string(mileage) + "\n";
    result += "the car's last maintainance date is " + std::to_string(month)+"/"+std::to_string(date)+"/"+std::to_string(year) + "\n";
    return result;
}