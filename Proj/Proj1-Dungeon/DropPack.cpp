//
//  DropPack.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "DropPack.hpp"
#include <iostream>

DropPack::DropPack(std::string _name, Creature* owner): CreatureAction(*owner) {
    name = _name;
    std::cout << "DropPack" << std::endl;
}
