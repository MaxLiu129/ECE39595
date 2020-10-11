#ifndef DUNGEONXMLHANDLER_H_
#define DUNGEONXMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Displayable.hpp"
#include "Structure.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Magic.hpp"
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

        DisplayType displayType = null;
        StringBuilder data = null;

        const DisplayType ROOM;
        const DisplayType PASSAGE;
        const DisplayType MONSTER;
        const DisplayType PLAYER;
        const DisplayType SCROLL;
        const DisplayType SWORD;
        const DisplayType ARMOR;

        Dungeon dungeonBeingparsed = null;
        ObjectDisplayGrid odgBeingParsed = null;
        Room roomBeingParsed = null;
        Passage passageBeingParsed = null;
        Monster monsterBeingParsed = null;
        Player playerBeingParsed = null;
        Scroll scrollBeingParsed = null;
        Sword swordBeingParsed = null;
        Armor armorBeingParsed = null;
        Action actionBeingParsed = null;

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

        void addStudent(Student student);
    
    public:
        void startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes);
        void endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName) ;
        void fatalError(const xercesc::SAXParseException&);
        void characters(const XMLCh * const ch, const XMLSize_t length) ;
        std::string toString();
        DungeonXMLHandler();

};

const DisplayType Displaytype::ROOM = ROOM;
const DisplayType Displaytype::PASSAGE = PASSAGE;
const DisplayType Displaytype::MONSTER = MONSTER;
const DisplayType Displaytype::PLAYER = PLAYER;
const DisplayType Displaytype::SCROLL = SCROLL;
const DisplayType Displaytype::SWORD = SWORD;
const DisplayType Displaytype::ARMOR = ARMOR;





#endif /* DUNGEONXMLHANDLER_H_ */