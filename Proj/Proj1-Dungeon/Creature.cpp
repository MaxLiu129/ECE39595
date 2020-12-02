
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

int Creature::getHpMoves() {
    return hpm;
}

CreatureAction* Creature::getHitAction() {
    return hitAction;
}

CreatureAction* Creature::getDeathAction() {
    return deathAction;
}

void Creature::addDeathAction(CreatureAction* _deathAction) {
    death_queue.push(_deathAction);
}
void Creature::addHitAction(CreatureAction* _hitAction) {
    hit_queue.push(_hitAction);
}

std::queue <CreatureAction*> Creature::getDeathQueue() {
    return death_queue;
}
std::queue <CreatureAction*> Creature::getHitQueue() {
    return hit_queue;
}

void Creature::removeHitAction() {
    hit_queue.pop();
}

void Creature::removeDeathAction() {
    death_queue.pop();
}

