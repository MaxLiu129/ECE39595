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
    std::cout << "setMaxHit(int _maxHit) called" << std::endl;
     
}

void Displayable::setHpMove(int _hpMoves) {
    hpMoves = _hpMoves;
    std::cout << "setHpMove(int _hpMoves) called"  << std::endl;
}

void Displayable::setHp(int _Hp) {
    Hp = _Hp;
    std::cout << "setHp(int _Hp) called, Hp is set to " << std::endl;
}

void Displayable::setType(char _t) {
    t = _t;
    std::cout << "setType(char _t) called, t is set to" << std::endl;
}

void Displayable::setIntValue(int _v) {
    v = _v;
    std::cout << "setIntValue(int _v) called" << std::endl;
}

void Displayable::SetPosX(int _posx) {
    PosX = _posx;
    std::cout << "setPosX(int _x) called" << std::endl;
}

void Displayable::setPosY(int _posy) {
    PosY = _posy;
    std::cout << "setPosY(int _y) called" << std::endl;
}

void Displayable::SetWidth(int _widx) {
    WidthX = _widx;
    std::cout << "setWidth(int _x) called" << std::endl;
}

void Displayable::setHeight(int _heiy) {
    HeightY = _heiy;
    std::cout << "setHeight(int _y) called" << std::endl;
}


