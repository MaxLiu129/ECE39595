#include "Room.hpp"

#include <string>

Room::Room(int _room){
    room = _room;
    std::cout << "Room constructor, room id set to" + std::to_string(_room) << std::endl;
}

void Room::setCreature(Creature* _monster){
    //creatures[creatureCount++] = _monster;
    std::cout << "set creature in room" << std::endl;
}   
