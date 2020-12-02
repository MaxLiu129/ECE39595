//
//  Player.cpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Player.hpp"
#include <iostream>

void Player::setWeapon(Item* _sword) { // maybe to equip weapon
    swords.push_back(_sword);
}

void Player::setArmor(Item* _armor) {
    armors.push_back(_armor);
}

Item* Player::getWeapon() {
    return swords.back();
}

Item* Player::getArmor() {
    return armors.back();
}
