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

//void Player::setID(int _room, int _serial) {
//    room = _room;
//    serial = _serial;
//    std::cout << "ID set for the Player, room is " + std::to_string(_room) + "serial is: " + std::to_string(_serial) << std::endl;
//}
//
//void Player::setName(std::string _name) {
//    name = _name;
//    std::cout << "set name for the Player, name is: \"" + _name + "\"" << std::endl;
//}
//
//std::string Player::getPlayerName() {
//    return name;
//}
