//
//  EndGame.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef EndGame_hpp
#define EndGame_hpp

#include <stdio.h>
#include "CreatureAction.hpp"
#include "Creature.hpp"
class EndGame: public CreatureAction {
public:
    EndGame(std::string _name, Creature* owner);
private:
    std::string name;
};
#endif /* EndGame_hpp */
