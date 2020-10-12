//
//  UpdateDisplay.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "UpdateDisplay.hpp"
#include <iostream>

UpdateDisplay::UpdateDisplay(std::string _name, Creature* owner):CreatureAction(Creature **owner) {
    name = _name;
    std::cout << "Display updated" << std::endl;
}
