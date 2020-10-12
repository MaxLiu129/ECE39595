//
//  Hallucinate.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Hallucinate_hpp
#define Hallucinate_hpp

#include <stdio.h>
#include "ItemAction.hpp"
#include "Creature.hpp"
class Hallucinate: public ItemAction {
public:
    Hallucinate(Item* owner);
};
#endif /* Hallucinate_hpp */
