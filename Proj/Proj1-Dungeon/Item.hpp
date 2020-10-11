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

class Item: public displayable {
public:
    void setOwner(Creature _owner);
    Creature owner;
}
#endif /* Item_hpp */
