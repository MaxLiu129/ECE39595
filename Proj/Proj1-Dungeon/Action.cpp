//
//  Action.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Action.hpp"
#include <iostream>

void Action::setMessage(std::string _msg) {
    msg = _msg;
    std::cout << "setMessage" << std::endl;
}

void Action::setIntValue(int _v) {
    v = _v;
    std::cout << "setIntValue" << std::endl;
}

void Action::setCharValue(char _c) {
    c = _c;
    std::cout << "setCharValue" << std::endl;
}
