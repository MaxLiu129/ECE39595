#include <iostream>
#include <string>
#include "Automobile.h"

int main(int argc, char* argv[ ]) {
    Automobile* automobile1 = new Automobile(1,111,02,02,2020);
    printf("%s:","The car ID is:");
    std::cout << std::to_string(automobile1->getID()) << "\n";
    printf("%s:","The car mileage is:");
    std::cout << std::to_string(automobile1->getMileage()) << "\n";
    printf("%s:","The car last maintainance date is:");
    std::cout << (automobile1->getDate()) << "\n";

    Automobile* automobile2 = new Automobile(2,222,02,03,2021);
    printf("%s:","The car ID is:");
    std::cout << std::to_string(automobile2->getID()) << "\n";
    printf("%s:","The car mileage is:");
    std::cout << std::to_string(automobile2->getMileage()) << "\n";
    printf("%s:","The car last maintainance date is:");
    std::cout << (automobile2->getDate()) << "\n";    
}
