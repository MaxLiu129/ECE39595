#include "Displayable.hpp"

//#include "Structure.hpp"
//#include "creature.hpp"
//#include "item.hpp"
//#include "magic.hpp"
#include <string>
#include <iostream>

Displayable::Displayable() {
    std::cout << "Displayable() called." << std::endl;
}

void Displayable::setInvisible() {
    std::cout << "setInvisible() called." << std::endl;
}

void Displayable::setVisible( ) {
    std::cout << "setVisible( ) called." << std::endl;
}

void Displayable::setMaxHit(int _maxHit) {
    maxHit = _maxHit;
    std::cout << "setMaxHit(int _maxHit) called, maxHit is " + std::to_string(_maxHit) << std::endl;
}

void Displayable::setHpMove(int _hpMoves) {
    hpMoves = _hpMoves;
    std::cout << "setHpMove(int _hpMoves) called, hpMoves is " + std::to_string(_hpMoves) << std::endl;
}

void Displayable::setHp(int _Hp) {
    Hp = _Hp;
    std::cout << "setHp(int _Hp) called, Hp is set to " + std::to_string(_Hp) << std::endl;
}

void Displayable::setType(char _t) {
    t = _t;
    std::cout << "setType(char _t) called, t is set to " + std::to_string(_t) << std::endl;
}

void Displayable::setIntValue(int _v) {
    v = _v;
    std::cout << "setIntValue(int _v) called, v is set to " + std::to_string(_v) << std::endl;
}

void Displayable::SetPosX(int _posx) {
    PosX = _posx;
    std::cout << "setPosX(int _x), PosX is " + std::to_string(_posx) << std::endl;
}

void Displayable::setPosY(int _posy) {
    PosY = _posy;
    std::cout << "setPosY(int _y), PosY is " + std::to_string(_posy) << std::endl;
}

void Displayable::SetWidth(int _widx) {
    WidthX = _widx;
    std::cout << "setWidth(int _x), WidthX is " + std::to_string(_widx) << std::endl;
}

void Displayable::setHeight(int _heiy) {
    HeightY = _heiy;
    std::cout << "setHeight(int _y), HeightY is " + std::to_string(_heiy) << std::endl;
}

int Displayable::getPosX() {
    return PosX;
}
int Displayable::getPosY() {
    return PosY;
}
int Displayable::getWidth() {
    return WidthX;
}
int Displayable::getHeight() {
    return HeightY;
}

int Displayable::getMaxHit() {
    return maxHit;
}

int Displayable::getIntValue() {
    return v;
}