//
//  ItemAction.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef ItemAction_hpp
#define ItemAction_hpp

#include <stdio.h>
#include "Action.hpp"
class ItemAction: public Action {
public:
    ItemAction(Item owner);
};
#endif /* ItemAction_hpp */
