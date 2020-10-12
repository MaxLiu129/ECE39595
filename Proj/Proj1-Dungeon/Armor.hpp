//
//  Armor.hpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Armor_hpp
#define Armor_hpp

#include <stdio.h>
#include "Item.hpp"

class Armor: public Item {
public:
    Armor();
    void setName(std::string _name);
    void setID(int _room, int _serial);
private:
    std::string name;
    int room;
    int serial;
};
#endif /* Armor_hpp */
