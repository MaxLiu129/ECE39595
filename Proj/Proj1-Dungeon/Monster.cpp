//
//  Monster.cpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Monster.hpp"
#include <iostream>

Monster::Monster() {
    std::cout << "Monster construced" << std::endl;

}

void Monster::setID(int _room, int _serial) {
    room = _room;
    serial = _serial;
    std::cout << "ID set for the monster" << std::endl;
}

void Monster::setName(std::string _name) {
    name = _name;
    std::cout << "set name for the monster" << std::endl;
}

