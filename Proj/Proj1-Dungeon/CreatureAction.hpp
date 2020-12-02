//
//  CreatureAction.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef CreatureAction_hpp
class Creature;

#define CreatureAction_hpp
#include "Action.hpp"
#include <stdio.h>
#include <queue>
//#include "ObjectDisplayGrid.hpp"
//#include "Dungeon.hpp"
class CreatureAction: public Action {
public:
    CreatureAction(Creature* owner);
    void setCreatureActionName(std::string _actions);
    std::string getCreatureActionName();
private:
    std::string action_name;

};
#endif /* CreatureAction_hpp */
