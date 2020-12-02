//
//  Teleport.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Teleport_hpp
#define Teleport_hpp
#include <stdio.h>
#include "CreatureAction.hpp"
#include "Creature.hpp"

class Teleport: public CreatureAction {
public:
    Teleport(std::string _name, Creature* owner);
    
private:
    std::string name;
};
#endif /* Teleport_hpp */
