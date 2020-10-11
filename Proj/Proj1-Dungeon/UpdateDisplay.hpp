//
//  UpdateDisplay.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef UpdateDisplay_hpp
#define UpdateDisplay_hpp

#include <stdio.h>
#include "CreatureAction.hpp"
class UpdateDisplay: public CreatureAction {
public:
    UpdateDisplay(std::string _name, Creature _owner);
    std::string name;
    Creature owner;
};

#endif /* UpdateDisplay_hpp */
