//
//  Remove.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Remove_hpp
#define Remove_hpp
#include "CreatureAction.hpp"
#include <stdio.h>
#include "Creature.hpp"
class Remove: public CreatureAction {
public:
    Remove(std::string _name, Creature* owner);
    
private:
    std::string name;

};

#endif /* Remove_hpp */
