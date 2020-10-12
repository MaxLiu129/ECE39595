#include "Room.hpp"

#include <string>

Room::Room(){
    std::cout << "Room::Room(std::string _roomName) called." << std::endl;
}

void Room::setId(int _room){
    room = _room;
    std::cout << "Room::setId(int _room) called" << std::endl;
}

void setCreature(Creature* _monster){
    //creatures[creatureCount++] = _monster;
    std::cout << "setCreature(Creature Monster) called." << std::endl;
}   
