#ifndef DUNGEONXMLHANDLER_H_
#define DUNGEONXMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Action.hpp"
#include "Armor.hpp"
#include "BlessCurseOwner.hpp"
#include "ChangeDisplayedType.hpp"
#include "Creature.hpp"
#include "CreatureAction.hpp"
#include "Displayable.hpp"
#include "DropPack.hpp"
#include "Dungeon.hpp"
#include "EndGame.hpp"
#include "Hallucinate.hpp"
#include "Item.hpp"
#include "ItemAction.hpp"
#include "Magic.hpp"
#include "Monster.hpp"
#include "ObjectDisplayGrid.hpp"
#include "Passage.hpp"
#include "Player.hpp"
#include "Remove.hpp"
#include "Room.hpp"
#include "Scroll.hpp"
#include "Structure.hpp"
#include "Sword.hpp"
#include "Teleport.hpp"
#include "UpdateDisplay.hpp"
#include "YouWin.hpp"

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/PlatformUtils.hpp>

class DungeonXMLHandler : public xercesc::DefaultHandler{
    private:
        int DEBUG = 1;
        std::string CLASSID = "DungeonXMLHandler";
        std::string data ;

        Dungeon* dungeonBeingparsed = NULL;
        ObjectDisplayGrid* odgBeingParsed = NULL;
        Room* roomBeingParsed = NULL;
        Passage* passageBeingParsed = NULL;
        Monster* monsterBeingParsed = NULL;
        Player* playerBeingParsed = NULL;
        Scroll* scrollBeingParsed = NULL;
        Sword* swordBeingParsed = NULL;
        Armor* armorBeingParsed = NULL;
        Action* actionBeingParsed = NULL;

        bool inPlayer = false;
        bool bvisible = false;
        bool bposX = false;
        bool bposY = false;
        bool bwidth = false;
        bool bheight = false;
        bool btype = false;
        bool bhp = false;
        bool bhpMoves = false;
        bool bmaxhit = false;
        bool bitemintval = false;
        bool bactionintval = false;
        bool bactionmessage = false;
        bool bactioncharval = false;

        //added for step2
        std::vector<Room> rooms;
        std::vector<Passage> passages;
        std::vector<Monster> monsters;
        //...

        int roomCount = 0;
        int passageCount = 0;
        int monsterCount = 0;
        //...

        int maxRoomCount = 0;
        int maxPassageCount = 0;
        int maxMonsterCount = 0;
        //...
        
        void addRoom(Room room);
        void addPassage(Passage passage);
        void addMonster(Monster monster);
        //further movement...(now is step2)
        //std::vector<Scroll>addScrolls();
        //std::vector<Sword>addSwords();
        //std::vector<Armor>addArmors();
    
    public:
        std::vector<Room>getRooms();
        std::vector<Passage>getPassages();
        std::vector<Monster>getMonsters();
        //more to go like above.
        
        
        void startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes);
        void endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName) ;
        void fatalError(const xercesc::SAXParseException&);
        void characters(const XMLCh * const ch, const XMLSize_t length);
        std::string toString();
        DungeonXMLHandler();

};



#endif /* DUNGEONXMLHANDLER_H_ */
