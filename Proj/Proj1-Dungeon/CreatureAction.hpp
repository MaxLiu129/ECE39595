//
//  CreatureAction.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

class Creature;
#ifndef CreatureAction_hpp
#define CreatureAction_hpp
#include "Action.hpp"
#include <stdio.h>
class CreatureAction: public Action {
public:
    CreatureAction(Creature* owner);
};
#endif /* CreatureAction_hpp */
