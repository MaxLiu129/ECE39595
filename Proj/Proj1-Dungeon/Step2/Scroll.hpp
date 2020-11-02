//
//  Scroll.hpp
//  The dungeon
//
//  Created by zihan liu on 10/11/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Scroll_hpp
#define Scroll_hpp

#include <stdio.h>
#include "Item.hpp"
class Scroll: public Item {
public:
    Scroll(std::string _name);
    void setID(int _room, int _serial);
private:
    int room;
    int serial;
    std::string name;
};

#endif /* Scroll_hpp */
