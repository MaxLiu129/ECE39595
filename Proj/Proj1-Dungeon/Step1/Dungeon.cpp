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
    std::cout << "Dungeon setting: name is: " + _name + " width is: " + std::to_string(_width) + "gameHeight is: " +  std::to_string(_gameHeight) << std::endl;
}

void Dungeon::addRoom(Room* room) {
    rooms.push_back(room);
    std::cout << "Dungeon: new room added" << std::endl;
}

void Dungeon::addCreature(Creature* creature) {
    creatures.push_back(creature);
    std::cout << "Dungeon: new creature added" << std::endl;
}

void Dungeon::addPassage(Passage* passage) {
    passages.push_back(passage);
    std::cout << "Dungeon: new passag added" << std::endl;
}

void Dungeon::addItem(Item* item) {
    items.push_back(item);
    std::cout << "Dungeon: new item added" << std::endl;
}

