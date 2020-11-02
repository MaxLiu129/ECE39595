//
//  DropPack.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef DropPack_hpp
#define DropPack_hpp

class Creature;
#include <stdio.h>
#include "CreatureAction.hpp"
#include "Creature.hpp"

class DropPack: public CreatureAction {
public:
    DropPack(std::string _name, Creature* owner);
    
private:
    std::string name;
};
#endif /* DropPack_hpp */
