//
//  Dungeon.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Dungeon_hpp
#define Dungeon_hpp

#include <stdio.h>
#include <vector>
#include "Room.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Passage.hpp"

class Dungeon {
public:
    void getDungeon(std::string _name, int _width, int _gameHeight);
    void addRoom(Room* room);
    void addCreature(Creature* creature);
    void addPassage(Passage* passage);
    void addItem(Item* item);
    
private:
    std::string name;
    int width;
    int gameHeight;

    std::vector<Room *> rooms;
    std::vector<Creature *> creatures;
    std::vector<Passage *> passages;
    std::vector<Item *> items;
        
};




#endif /* Dungeon_hpp */
