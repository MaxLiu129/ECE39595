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

std::string Dungeon::getDungeonName() {
    return name;
}
int Dungeon::getDungeonWidth() {
    return width;
}
int Dungeon::getDungeonHeight() {
    return gameHeight;

}
std::vector<Room*> Dungeon::getRooms() {
    return rooms;
}
std::vector<Passage*> Dungeon::getPassages() {
    return passages;
}
std::vector<Creature*> Dungeon::getCreatures() {
    return creatures;
}
std::vector<Item*> Dungeon::getItems() {
    return items;
}

//check position

bool Dungeon::checkPos(int _x, int _y) {
    for (Room* room : rooms) {
        if (room -> checkRoomPos(_x, _y)) {
            return true;
        }
    }
    for (Passage* passage : passages) {
        for (int i = 1; i < passage->getPassagePosXs().size(); i++) {
            int posX1 = (passage->getPassagePosXs())[i - 1];
            int posX2 = (passage->getPassagePosXs())[i];
            int posY1 = (passage->getPassagePosYs())[i - 1];
            int posY2 = (passage->getPassagePosYs())[i];
            if (passage->checkPassagePos(_x, _y, posX1, posX2, posY1, posY2)) {
                return true;
            }
        }
    }
    return false;
}

