//
//  Remove.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Remove.hpp"
#include <iostream>

Remove::Remove(std::string _name, Creature* owner):CreatureAction(owner) {
    name = _name;
    std::cout << "Removed name, it is \"" + _name + "\""<< std::endl;
}
