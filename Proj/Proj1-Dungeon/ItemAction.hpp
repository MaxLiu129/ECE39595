//
//  ItemAction.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef ItemAction_hpp
#define ItemAction_hpp

class Item;
#include <stdio.h>
#include "Action.hpp"
#include "Item.hpp"
class ItemAction: public Action {
public:
    ItemAction(Item* owner);
    void setItemActionName(std::string _actions);
    std::string getItemActionName();

private:
    std::string action_name;

};
#endif /* ItemAction_hpp */
