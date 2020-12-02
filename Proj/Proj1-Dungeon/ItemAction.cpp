//
//  ItemAction.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "ItemAction.hpp"
#include <iostream>

ItemAction::ItemAction(Item* owner) {
    std::cout << "Item action constructed" << std::endl;
}

void ItemAction::setItemActionName(std::string _actions) {
    action_name = _actions;
}
std::string ItemAction::getItemActionName() {
    return action_name;
}