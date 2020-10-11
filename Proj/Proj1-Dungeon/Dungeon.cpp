//
//  Dungeon.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//
//#include <xercesc/sax2/SAX2XMLReader.hpp>
//#include <xercesc/sax2/XMLReaderFactory.hpp>
//#include <xercesc/sax2/DefaultHandler.hpp>
//#include <xercesc/util/XMLString.hpp>
//#include <xercesc/sax2/Attributes.hpp>
//#include <xercesc/util/XMLUni.hpp>
//#include <xercesc/util/PlatformUtils.hpp>

#include "Dungeon.hpp"
#include <stdio.h>
#include <iostream>

void Dungeon::getDungeon(std::string& _name, int _width, int _gameHeight) {
    name = _name;
    width = _width;
    gameHeight = _gameHeight;
    std::cout << "Dungeon setting:" + _name + " " + std::to_string(_width) + " " +  std::to_string(_gameHeight);
}

void Dungeon::addRoom(Room room) {
    rooms.push_back(room);
    std::cout << "Dungeon: new room added";
}

void Dungeon::addCreature(Creature creature) {
    creatures.push_back(creature);
    std::cout << "Dungeon: new creature added";
}

void Dungeon::addPassage(Passage passage) {
    passages.push_back(passage);
    std::cout << "Dungeon: new passag added";
}

void Dungeon::addRItem(Item item) {
    items.push_back(item);
    std::cout << "Dungeon: new item added";
}

