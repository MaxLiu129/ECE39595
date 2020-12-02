//
//  Armor.cpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Armor.hpp"
#include <iostream>

Armor::Armor() {
    std::cout << "Armor constructed" << std::endl;

}
void Armor::setName(std::string _name) {
    name = _name;
    std::cout << "set name for Armor, name is \"" + _name + "\"" << std::endl;

}
void Armor::setID(int _room, int _serial) {
    room = _room;
    serial = _serial;
    std::cout << "Set ID for Armor, room num is " + std::to_string(_room) + " serial is " + std::to_string(_serial) << std::endl;

}
