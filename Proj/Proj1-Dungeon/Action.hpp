//
//  Action.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Action_hpp
#define Action_hpp

#include <stdio.h>
#include <string>

class Action {
public:
    void setMessage(std::string msg);
    void setIntValue(int v);
    void setCharValue(char c);
};

#endif /* Action_hpp */
