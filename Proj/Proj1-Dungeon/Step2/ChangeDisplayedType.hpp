//
//  ChangeDisplayedType.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef ChangeDisplayedType_hpp
#define ChangeDisplayedType_hpp

#include <stdio.h>
#include "CreatureAction.hpp"
#include "Creature.hpp"

class ChangeDisplayedType: public CreatureAction {
public:
    ChangeDisplayedType(std::string _name, Creature* owner);
    
private:
    std::string name;
};
#endif /* ChangeDisplayedType_hpp */
