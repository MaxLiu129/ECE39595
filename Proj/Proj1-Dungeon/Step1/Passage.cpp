#include "Passage.hpp"

#include <string>

Passage::Passage(){
    std::cout << "Passage() called." << std::endl;
}

void Passage::setName(std::string _passageName) {
    passageName = _passageName;
    std::cout << "setName(std::string _passageName) called. passage name is \"" + passageName + "\"" << std::endl;
}


void Passage::setID(int _room1, int _room2){
    room1 = _room1;
    room2 = _room2;
    std::cout << "setID(int _room1, int _room2) called. Room1 id is " + std::to_string(_room1) + " Room2 id is " + std::to_string(_room2) << std::endl;
}
