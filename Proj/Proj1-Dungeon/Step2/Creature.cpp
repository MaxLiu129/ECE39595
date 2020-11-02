
#include "Creature.hpp"
#include <string>
#include <iostream>

Creature::Creature() {
    std::cout << "Creature() called" << std::endl;
}

void Creature::setHp(int _h){
    h = _h;
    std::cout << "Creature::setHp(int _h) called, h is set to " + std::to_string(h) << std::endl;
}

void Creature::setHpMoves(int _hpm){
    hpm = _hpm;
    std::cout << "Creature::setHpMoves(int _hpm) called, hpm is set to " + std::to_string(hpm) << std::endl;
}

void Creature::setDeathAction(CreatureAction* da){
    deathAction = da;
    std::cout << "Creature::setDeathAction(CreatureAction da) called" << std::endl;
}

void Creature::setHitAction(CreatureAction* ha){
    hitAction = ha;
    std::cout << "Creature::setHitAction(CreatureAction ha) called" << std::endl;
}

void Creature::setName(std::string _name) {
    name = _name;
}
void Creature::setID(int _room, int _serial) {
    room = _room;
    serial = _serial;
}
std::string Creature::getName() {
    return name;
}
int Creature::getCreatureHp() {
    return h;
}

