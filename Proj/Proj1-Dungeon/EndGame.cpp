//
//  EndGame.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "EndGame.hpp"
#include <iostream>

EndGame::EndGame(std::string _name, Creature* owner):CreatureAction(owner) {
    name = _name;
    std::cout << "End game with name \"" + _name + "\""<< std::endl;
}
