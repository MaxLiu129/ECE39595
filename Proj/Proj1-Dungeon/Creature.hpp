#ifndef CREATURE_H_
#define CREATURE_H_


class CreatureAction;
#include <string>
#include "Displayable.hpp"
#include "CreatureAction.hpp"


class Creature: public Displayable {
public:
    Creature();
    void setHp(int _h);
    void setHpMoves(int _hpm);
    void setDeathAction(CreatureAction* da);
    void setHitAction(CreatureAction* ha);
    
private:
    int h;
    int hpm;
    CreatureAction* deathAction;
    CreatureAction* hitAction;
};

#endif /* CREATURE_H_ */
