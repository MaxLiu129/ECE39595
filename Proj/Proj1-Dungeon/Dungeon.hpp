//
//  Dungeon.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef Dungeon_hpp
#define Dungeon_hpp

//#include <xercesc/sax2/SAX2XMLReader.hpp>
//#include <xercesc/sax2/XMLReaderFactory.hpp>
//#include <xercesc/sax2/DefaultHandler.hpp>
//#include <xercesc/util/XMLString.hpp>
//#include <xercesc/sax2/Attributes.hpp>
//#include <xercesc/util/XMLUni.hpp>
//#include <xercesc/util/PlatformUtils.hpp>
#include <stdio.h>
#include <vector>
#include "Room.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Passage.hpp"
class Dungeon {
public:
    virtual void getDungeon(std::string& _name, int _width, int _gameHeight);
    virtual void addRoom(Room* room);
    virtual void addCreature(Creature* creature);
    virtual void addPassage(Passage* passage);
    virtual void addItem(Item* item);
    
    std::string name;
    int width;
    int gameHeight;
    
    std::vector<Room*> rooms = new std::vector<Room*>();
    std::vector<Creature*> creatures = new std::vector<Creature*>();
    std::vector<Passage*> passages = new std::vector<Passage*>();
    std::vector<Item*> items = new std::vector<Item*>();
    
private:
    
};




#endif /* Dungeon_hpp */
