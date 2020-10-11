//
//  Player.hpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include "Creature.hpp"
#include "Item.hpp"

#include <stdio.h>

class Player: public Creature {
public:
    void setWeapon(Item _sword);
    void setArmor(Item _armor);
    Item sword = NULL;
    Item armor = NULL;
};

#endif /* Player_hpp */
