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
    std::string getDungeonName();
    int getDungeonWidth();
    int getDungeonHeight();
    //int getDungeonMessage();

    bool checkPos(int _x, int _y);

    std::vector<Room*> getRooms();
    std::vector<Passage*> getPassages();
    std::vector<Creature*> getCreatures();
    std::vector<Item*> getItems();

    void addItem2Pack(Item* _item);
    std::vector<Item*> getPackItems();
    
    Item* item_remove(std::vector<Item*> _pack_items, int index);
    void creature_remove(Creature* _creature);

    
private:
    std::string name;
    int width;
    int gameHeight;    

    std::vector<Room *> rooms;
    std::vector<Creature *> creatures;
    std::vector<Passage *> passages;
    std::vector<Item *> items;
    std::vector<Item *> pack_items;
};
#endif /* Dungeon_hpp */
