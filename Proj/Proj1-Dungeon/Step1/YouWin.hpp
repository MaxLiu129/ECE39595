//
//  YouWin.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef YouWin_hpp
#define YouWin_hpp

#include <stdio.h>
#include "CreatureAction.hpp"
#include "Creature.hpp"

class YouWin: public CreatureAction {
public:
    YouWin(std::string _name, Creature *owner);
    std::string name;
};
#endif /* YouWin_hpp */
