//
//  Sword.cpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Sword.hpp"
#include <iostream>
Sword::Sword(std::string _name) {
    name = _name;
    std::cout << "Sword constructed with name " + _name << std::endl;

}

void Sword::setID(int _room, int _serial) {
    room = _room;
    serial = _serial;
    std::cout << "Set ID for Sword in room " + std::to_string(_room) + " with ID" + std::to_string(_serial) << std::endl;

}
