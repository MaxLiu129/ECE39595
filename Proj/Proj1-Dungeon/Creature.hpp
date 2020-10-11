#ifndef CREATURE_H_
#define CREATURE_H_

#include <string>
#include "Displayable.hpp"
#include "CreatureAction.hpp"

class Creature:: public displayable{
    private:
        int h;
        int hpm;
        CreatureAction deathAction;
        CreatureAction hitAction;

    public:
        void Creature();
        void setHp(int _h); 
        void setHpMoves(int _hpm);
        void setDeathAction(CreatureAction da);
        void setHitAction(CreatureAction ha);
}

#endif /* CREATURE_H_ */