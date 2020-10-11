#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include "Structure.hpp"
#include "Creature.hpp"

class Room:: public Structure{
    private:
        std::string roomName;
        int room;
        Creature Monster;
    public:
        void Room(std::string _roomName);
        void setId(int _room); 
        void setCreature(Creature Monster);
}

#endif /* ROOM_H_ */