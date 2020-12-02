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

std::vector<int> Passage::getPassagePosXs() {
    return passagePosXs;
}
std::vector<int> Passage::getPassagePosYs() {
    return passagePosYs;
}
void Passage::addPosX(int _posX) {
    passagePosXs.push_back(_posX);
}
void Passage::addPosY(int _posY) {
    passagePosYs.push_back(_posY);
}

bool Passage::checkPassagePos(int _x, int _y, int x1, int x2, int y1, int y2) {
    if (x2 == x1 && _x == x1) {
        if (y1 < y2) {
            if (_y >= y1 && _y <= y2) {
                return true;
            }
        }
        else {
            if (_y <= y1 && _y >= y2) {
                return true;
            }
        }
    }
    if (y2 == y1 && _y == y1) {
        if (x1 < x2) {
            if (_x >= x1 && _x <= x2) {
                return true;
            }
        }
        else {
            if (_x <= x1 && _x >= x2) {
                return true;
            }
        }
    }
    return false;
}
