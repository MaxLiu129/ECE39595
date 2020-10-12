//
//  Hallucinate.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Hallucinate.hpp"
#include <iostream>

Hallucinate::Hallucinate(Item* owner):ItemAction(Item *owner) {
    std::cout << "Bless Curse Owner constructed" << std::endl;
}
