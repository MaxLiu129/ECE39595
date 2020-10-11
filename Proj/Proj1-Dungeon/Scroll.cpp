//
//  Scroll.cpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Scroll.hpp"
#include <iostream>

Scroll::Scroll(std::string _name) {
    name = _name;
    std::cout << "Scroll constructed";
}

void Scroll::setID(int _room, int _serial) {
    room = _room;
    serial = _serial;
    std::cout << "Scroll ID set";

}
