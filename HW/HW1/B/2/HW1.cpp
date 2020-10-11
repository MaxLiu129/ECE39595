#include <iostream>
#include <string>
#include "Automobile.h"

int main(int argc, char* argv[ ]) {
    Automobile* automobile1 = new Automobile(1,111,02,02,2020);
    std::cout << automobile1->printthings( );  

    Automobile* automobile2 = new Automobile(2,222,02,03,2021);
    std::cout << automobile2->printthings( );   
}
