#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include "Structure.hpp"
#include "Creature.hpp"
#include <vector>

class Room: public Structure{
    private:
        int room;
    public:
        Room();
        void setId(int _room); 
        void setCreature(Creature* _monster);
};

#endif /* ROOM_H_ */
