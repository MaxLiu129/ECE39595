//
//  Teleport.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Teleport.hpp"
#include <iostream>

Teleport::Teleport(std::string _name, Creature* owner):CreatureAction(Creature *owner) {
    name = _name;
    std::cout << "Teleport";
}
