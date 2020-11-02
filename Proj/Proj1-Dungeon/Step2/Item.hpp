//
//  Item.hpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include "Displayable.hpp"
#include "Creature.hpp"

class Item: public Displayable {
public:
    void setOwner(Creature* owner);
    void setName(std::string _name);
    void setID(int _room, int _serial);
    std::string getName();

private:
    std::string name;
    int room;
    int serial;
};
#endif /* Item_hpp */
