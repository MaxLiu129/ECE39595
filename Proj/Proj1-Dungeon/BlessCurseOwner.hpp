//
//  BlessCurseOwner.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef BlessCurseOwner_hpp
#define BlessCurseOwner_hpp

#include <stdio.h>
#include "ItemAction.hpp"
#include "Creature.hpp"

class BlessCurseOwner: public ItemAction {
public:
    BlessCurseOwner(Item* owner);
};
#endif /* BlessCurseOwner_hpp */
