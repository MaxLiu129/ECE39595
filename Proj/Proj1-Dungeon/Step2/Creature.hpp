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
    void setName(std::string _name);
    void setID(int _room, int _serial);
    std::string getName();
    int getCreatureHp();

private:
    int h;
    int hpm;
    CreatureAction* deathAction;
    CreatureAction* hitAction;
    std::string name;
    int room;
    int serial;
};

#endif /* CREATURE_H_ */
