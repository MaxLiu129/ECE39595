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
    void setWeapon(Item *sword);
    void setArmor(Item *armor);
    //void setName(std::string _name);
    //void setID(int _room, int _serial);
    //std::string getPlayerName();

private:
    Item* sword = NULL;
    Item* armor = NULL;
    //std::string name;
    //int room;
    //int serial;
};

#endif /* Player_hpp */
