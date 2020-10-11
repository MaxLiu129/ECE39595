//
//  Sword.hpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Sword_hpp
#define Sword_hpp

#include <stdio.h>
#include "Item.hpp"

class Sword: public Item {
    Sword(std::string _name);
    void setID(int _room, int _serial);
    
    std::string name;
    int room;
    int serial;
}
#endif /* Sword_hpp */
