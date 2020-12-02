#include "Room.hpp"

#include <string>

Room::Room(int _room){
    room = _room;
    std::cout << "Room constructor, room id set to" + std::to_string(_room) << std::endl;
}

void Room::setCreature(Creature* _monster){
    //creatures.push_back(_monster);
    //std::cout << "set creature in room" << std::endl;
}   

bool Room::checkRoomPos(int _x, int _y) { // field x y.
    if (((Displayable::getPosX() + Displayable::getWidth() - 2) < _x) || (_x < Displayable::getPosX() + 1)) {
        return false; 
    }
    if (((Displayable::getPosY() + Displayable::getHeight() - 2) < _y) || (_y < Displayable::getPosY() + 1)){
        return false; 
    }

    return true;
}
