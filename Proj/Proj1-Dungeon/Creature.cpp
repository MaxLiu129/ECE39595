#include "displayable.hpp"
#include "CreatureAction.hpp"
#include <string>

class Creature::Creature(){
    std::cout << "Creature() called" << std::endl;
}

class Creature::setHp(int _h){
    h = _h;
    std::cout << "Creature::setHp(int _h) called, h is set to " + Integer.toString(h) << std::endl;
}

class Creature::setHpMoves(int _hpm){
    hpm = _hpm;
    std::cout << "Creature::setHpMoves(int _hpm) called, hpm is set to " + Integer.toString(hpm) << std::endl;
}

class Creature::setDeathAction(CreatureAction da){
    deathAction = da;
    std::cout << "Creature::setDeathAction(CreatureAction da) called" << std::endl;
}

class Creature::setHitAction(CreatureAction ha){
    hitAction = ha;
    std::cout << "Creature::setHitAction(CreatureAction ha) called, room is set to " + Integer.toString(room) << std::endl;
}