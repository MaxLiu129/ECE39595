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
#include "Creature.hpp"

class DropPack: public CreatureAction {
public:
    typedef Creature super;
    DropPack(std::string _name, Creature* owner);
    
private:
    std::string name;
};
#endif /* DropPack_hpp */
