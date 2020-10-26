//
//  Player.cpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Player.hpp"
#include <iostream>

void Player::setWeapon(Item* _sword) {
    sword = _sword;
    std::cout << "set sword" << std::endl;
}

void Player::setArmor(Item* _armor) {
    armor = _armor;
    std::cout << "set armor" << std::endl;
}
