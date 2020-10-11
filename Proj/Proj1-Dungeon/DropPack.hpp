//
//  DropPack.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef DropPack_hpp
#define DropPack_hpp

#include <stdio.h>
#include "CreatureAction.hpp"
class DropPack: public CreatureAction {
public:
    DropPack(std::string _name, Creature _owner);
    std::string name;
    Creature owner;
};
#endif /* DropPack_hpp */
