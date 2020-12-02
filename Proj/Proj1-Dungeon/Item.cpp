//
//  Item.cpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Item.hpp"
#include <iostream>

void Item::setOwner(Creature* _owner) {
    //owner =_owner;
    std::cout << "owner set" << std::endl;
}

void Item::setName(std::string _name) {
    name = _name;
}
void Item::setID(int _room, int _serial) {
    room = _room;
    serial = _serial;
}
std::string Item::getName() {
    return name;
}

void Item::setItemAction(ItemAction* _itemaction) {
    stored_action = _itemaction;
}
ItemAction* Item::getItemAction() {
    return stored_action;
}
