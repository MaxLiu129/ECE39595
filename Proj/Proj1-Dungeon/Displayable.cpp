#include "Displayable.hpp"

//#include "Structure.hpp"
//#include "creature.hpp"
//#include "item.hpp"
//#include "magic.hpp"
#include <string>


void displayable::Displayable() {
    std::cout << "Displayable() called." << std::endl;
}

void displayable::setInvisible() {
    std::cout << "setInvisible() called." << std::endl;
}

void displayable::setVisible( ) {
    std::cout << "setVisible( ) called." << std::endl;
}

void displayable::setMaxHit(int _maxHit) {
    maxHit = _maxHit;
    std::cout << "setMaxHit(int _maxHit) called, maxHit is set to " + Integer.toString(maxHit) << std::endl;
     
}

void displayable::setHpMove(int _hpMoves) {
    hpMoves = _hpMoves;
    std::cout << "setHpMove(int _hpMoves) called, hpMoves is set to " + Integer.toString(hpMoves)  << std::endl;
}

void displayable::setHp(int _Hp) {
    Hp = _Hp;
    std::cout << "setHp(int _Hp) called, Hp is set to " + Integer.toString(Hp) << std::endl;
}

void displayable::setType(char _t) {
    t = _t;
    std::cout << "setType(char _t) called, t is set to " + Integer.toString(t) << std::endl;
}

void displayable::setIntValue(int _v) {
    v = _v;
    std::cout << "setIntValue(int _v) called, v is set to " + Integer.toString(v) << std::endl;
}

void displayable::SetPosX(int _x) {
    PosX = _x;
    std::cout << "setPosX(int _x) called, PosX is set to " + Integer.toString(PosX) << std::endl;
}

void displayable::setPosY(int _y) {
    PosY = _y;
    std::cout << "setPosY(int _y) called, PosY is set to " + Integer.toString(PosY) << std::endl;
}

void displayable::SetWidth(int _x) {
    WidthX = _x;
    std::cout << "setWidth(int _x) called, WidthX is set to " + Integer.toString(WidthX) << std::endl;
}

void displayable::setHeight(int _y) {
    HeightY = _y;
    std::cout << "setHeight(int _y) called, HeightY is set to " + Integer.toString(HeightY)<< std::endl;
}


