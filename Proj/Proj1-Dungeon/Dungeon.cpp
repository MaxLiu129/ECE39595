//
//  Dungeon.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "Dungeon.hpp"
#include <stdio.h>
#include <iostream>

void Dungeon::getDungeon(std::string _name, int _width, int _gameHeight) {
    name = _name;
    width = _width;
    gameHeight = _gameHeight;
    std::cout << "Dungeon setting:" + _name + " " + std::to_string(_width) + " " +  std::to_string(_gameHeight) << std::endl;
}

void Dungeon::addRoom(Room* room) {
    rooms[roomCount++] = room;
    std::cout << "Dungeon: new room added" << std::endl;
}

void Dungeon::addCreature(Creature* creature) {
    creatures[creatureCount++] = creature;
    std::cout << "Dungeon: new creature added" << std::endl;
}

void Dungeon::addPassage(Passage* passage) {
    passages[passageCount++] = passage;
    std::cout << "Dungeon: new passag added" << std::endl;
}

void Dungeon::addItem(Item* item) {
    items[itemCount++] = item;
    std::cout << "Dungeon: new item added" << std::endl;
}

