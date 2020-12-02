#include "DungeonXMLHandler.hpp"
#include <iostream> 
#include <sstream>
#include <string>
int case_insensitive_match(std::string s1, std::string s2) {
    //convert s1 and s2 into lower case strings
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower); //std overloads tolower, ::tolower is the definition in the global namespace
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if (s1.compare(s2) == 0)
        return 1;
    return 0;
}

inline std::string boolToString(bool booleanValue) {
    return booleanValue ? "true" : "false";
}

std::string xmlChToString(const XMLCh* xmlChName, int length = -1) {
    //Xerces Parses file into XMLCh* string. So use Transcode to allocate a char* buffer
    char* chStarName = xercesc::XMLString::transcode(xmlChName);
    if (length == -1) {
        std::string StrName(chStarName);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
    else {
        std::string StrName(chStarName, 0, length);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }

}

const XMLCh* getXMLChAttributeFromString(const xercesc::Attributes& attributes, const char* strGet) {
    XMLCh* xmlChGet = xercesc::XMLString::transcode(strGet);
    const XMLCh* xmlChAttr = attributes.getValue(xmlChGet);
    xercesc::XMLString::release((&xmlChGet));
    return xmlChAttr;
}

DungeonXMLHandler::DungeonXMLHandler() {

}

Dungeon* DungeonXMLHandler::getDungeon() {
    return dungeonBeingparsed;
}

ObjectDisplayGrid* DungeonXMLHandler::getOdg() {
    return odg;
}


void DungeonXMLHandler::startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes) {

    char* qNameStr = xercesc::XMLString::transcode(qName);
    if (DEBUG > 1) {
        std::cout << CLASSID << ".startElement qName: " << qNameStr << std::endl;
    }
    if (case_insensitive_match(qNameStr, "Dungeon")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int width = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "width")));
        int gameHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "gameHeight")));
        int topHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "topHeight")));
        int bottomHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "bottomHeight")));


        parse_list.push_back("dungeon");
        dungeonBeingparsed = new Dungeon();
        dungeonBeingparsed->getDungeon(name, width, gameHeight);

        odg = new ObjectDisplayGrid(width, gameHeight, topHeight);
        odg->getObjectDisplayGrid(gameHeight, width, topHeight);
        odg->setBotHeight(bottomHeight);

    }
    else if (case_insensitive_match(qNameStr, "Rooms")) {
        parse_list.push_back("Rooms");
    }
    else if (case_insensitive_match(qNameStr, "Room")) {
        int id = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        roomBeingParsed = new Room(id);
        parse_list.push_back("room");

    }
    else if (case_insensitive_match(qNameStr, "Passages")) {
        parse_list.push_back("Passages");
    }
    else if (case_insensitive_match(qNameStr, "Passage")) {
        int room1 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room1")));
        int room2 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room2")));
        passageBeingParsed = new Passage();
        passageBeingParsed->setID(room1, room2);
        parse_list.push_back("passage");

    }
    else if (case_insensitive_match(qNameStr, "Monster")) {
        monsterBeingParsed = new Monster();
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        monsterBeingParsed->Creature::setID(room, serial);
        monsterBeingParsed->Creature::setName(name);
        parse_list.push_back("monster");

    }
    else if (case_insensitive_match(qNameStr, "Player")) {
        playerBeingParsed = new Player();
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(getXMLChAttributeFromString(attributes, "room"));
        int serial = std::stoi(getXMLChAttributeFromString(attributes, "serial"));
        playerBeingParsed->Creature::setID(room, serial);
        playerBeingParsed->Creature::setName(name);
        inPlayer = true;
        parse_list.push_back("player");

    }
    else if (case_insensitive_match(qNameStr, "Scroll")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        scrollBeingParsed = new Scroll(name);
        scrollBeingParsed->Item::setID(room, serial);
        scrollBeingParsed->Item::setName(name);
        parse_list.push_back("scroll");

    }
    else if (case_insensitive_match(qNameStr, "Sword")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        swordBeingParsed = new Sword(name);
        swordBeingParsed->Item::setID(room, serial);
        swordBeingParsed->Item::setName(name);

        parse_list.push_back("sword");

    }
    else if (case_insensitive_match(qNameStr, "Armor")) {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
        armorBeingParsed = new Armor();
        armorBeingParsed->Item::setID(room, serial);
        armorBeingParsed->Item::setName(name);

        
        parse_list.push_back("armor");
        

    }
    else if (case_insensitive_match(qNameStr, "CreatureAction") || case_insensitive_match(qNameStr, "ItemAction")) {
        //this gonna be long
        Creature* temp_owner = NULL;
        Item* item_owner = NULL;
        if (parse_list.back() == "player") {
            temp_owner = playerBeingParsed;
            actionBeingParsed = new CreatureAction(temp_owner);
            parse_list.push_back("creatureAction");
        }
        else if (parse_list.back() == "monster") {
            temp_owner = monsterBeingParsed;
            actionBeingParsed = new CreatureAction(temp_owner);
            parse_list.push_back("creatureAction");
        }
        else {
            if (parse_list.back() == "scroll") {
                item_owner = scrollBeingParsed;
            }
            else if (parse_list.back() == "sword") {
                item_owner = swordBeingParsed;
            }
            else {
                item_owner = armorBeingParsed;
            }
            actionBeingParsed = new ItemAction(item_owner);
            parse_list.push_back("itemAction");
        }

        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        std::string type = xmlChToString(getXMLChAttributeFromString(attributes, "type"));
        if (type.compare("death") == 0) {
            bdeath = true;
            if (name.compare("Remove") == 0) {

                ((CreatureAction*)actionBeingParsed)->setCreatureActionName("Remove");
            }
            else if (name.compare("YouWin") == 0) {
                ((CreatureAction*)actionBeingParsed)->setCreatureActionName("YouWin");
            }
            else if (name.compare("EndGame") == 0) {
                parse_list.pop_back();
                if (parse_list.back() == "player") {
                    ((CreatureAction*)actionBeingParsed)->setCreatureActionName("EndGame");
                }
                parse_list.push_back("CreatureAction");
            }
            else if (name.compare("UpdateDisplay") == 0) {
                ((CreatureAction*)actionBeingParsed)->setCreatureActionName("UpdateDisplay");
            }
            else if (name.compare("ChangeDisplayedType") == 0) {
                ((CreatureAction*)actionBeingParsed)->setCreatureActionName("ChangeDisplayedType");
            }
        }
        else if (type.compare("hit") == 0) {
            bhit = true;
            if (name.compare("Teleport") == 0) {
                ((CreatureAction*)actionBeingParsed)->setCreatureActionName("Teleport");
            }
            else if (name.compare("DropPack") == 0) {
                parse_list.pop_back();
                if (parse_list.back() == "player") {
                    ((CreatureAction*)actionBeingParsed)->setCreatureActionName("DropPack");
                }
                parse_list.push_back("CreatureAction");
            }
        }
        else if (type.compare("item") == 0) {
            if (name.compare("Hallucinate") == 0) {
                ((ItemAction*)actionBeingParsed)->setItemActionName("Hallucinate");
            }
            else if (name.compare("BlessArmor") == 0) {
                ((ItemAction*)actionBeingParsed)->setItemActionName("BlessArmor");
            }
        }



        if (name.compare("EmptyPack") == 0) {
            parse_list.pop_back();
            if (parse_list.back() == "player") {
                ((CreatureAction*)actionBeingParsed)->setCreatureActionName("EmptyPack");
            }
            parse_list.push_back("CreatureAction");
        }
        else {
            std::cout << "Unknown action: " + name << std::endl;
        }

    }
    else if (case_insensitive_match(qNameStr, "visible")) {
        bvisible = true;
    }
    else if (case_insensitive_match(qNameStr, "posX")) {
        bposX = true;
    }
    else if (case_insensitive_match(qNameStr, "posY")) {
        bposY = true;
    }
    else if (case_insensitive_match(qNameStr, "width")) {
        bwidth = true;
    }
    else if (case_insensitive_match(qNameStr, "height")) {
        bheight = true;
    }
    else if (case_insensitive_match(qNameStr, "type")) {
        btype = true;
    }
    else if (case_insensitive_match(qNameStr, "hp")) {
        bhp = true;
    }
    else if (case_insensitive_match(qNameStr, "maxhit")) {
        bmaxhit = true;
    }
    else if (case_insensitive_match(qNameStr, "hpMoves")) {
        bhpMoves = true;
    }
    else if (case_insensitive_match(qNameStr, "ItemIntValue")) {
        bitemintval = true;
    }
    else if (case_insensitive_match(qNameStr, "actionIntValue")) {
        bactionintval = true;
    }
    else if (case_insensitive_match(qNameStr, "actionMessage")) {
        bactionmessage = true;
    }
    else if (case_insensitive_match(qNameStr, "actionCharValue")) {
        bactioncharval = true;
    }
    else {
        std::cout << "Unknown qname" << std::endl;
    }

    xercesc::XMLString::release(&qNameStr);
}


void DungeonXMLHandler::fatalError(const xercesc::SAXParseException& exception)
{
    char* message = xercesc::XMLString::transcode(exception.getMessage());
    std::cout << "Fatal Error: " << message
        << " at line: " << exception.getLineNumber()
        << std::endl;
    xercesc::XMLString::release(&message);
}

void DungeonXMLHandler::endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName) {
    char* qNameStr = xercesc::XMLString::transcode(qName);
    if (bvisible) {
        if (std::stoi(data) == 1) {
            if (parse_list.back() == "room") {
                roomBeingParsed->setVisible();
            }
            else if (parse_list.back() == "passage") {
                passageBeingParsed->setVisible();
            }
            else if (parse_list.back() == "monster") {
                monsterBeingParsed->setVisible();
            }
            else if (parse_list.back() == "player") {
                playerBeingParsed->setVisible();
            }
            else if (parse_list.back() == "scroll") {
                scrollBeingParsed->setVisible();
            }
            else if (parse_list.back() == "sword") {
                swordBeingParsed->setVisible();
            }
            else if (parse_list.back() == "armor") {
                armorBeingParsed->setVisible();
            }
        }
        else {
            if (parse_list.back() == "room") {
                roomBeingParsed->setInvisible();
            }
            else if (parse_list.back() == "passage") {
                passageBeingParsed->setInvisible();
            }
            else if (parse_list.back() == "monster") {
                monsterBeingParsed->setInvisible();
            }
            else if (parse_list.back() == "player") {
                playerBeingParsed->setInvisible();
            }
            else if (parse_list.back() == "scroll") {
                scrollBeingParsed->setInvisible();
            }
            else if (parse_list.back() == "sword") {
                swordBeingParsed->setInvisible();
            }
            else if (parse_list.back() == "armor") {
                armorBeingParsed->setInvisible();
            }
        }
        bvisible = false;
    }
    else if (bposX) {
        int x = std::stoi(data);
        if (parse_list.back() == "room") {
            roomBeingParsed->SetPosX(x);
        }
        else if (parse_list.back() == "passage") {
            passageBeingParsed->SetPosX(x);
            passageBeingParsed->addPosX(x);
        }
        else if (parse_list.back() == "monster") {
            monsterBeingParsed->SetPosX(x + roomBeingParsed->getPosX());
        }
        else if (parse_list.back() == "player") {
            playerBeingParsed->SetPosX(x + roomBeingParsed->getPosX());
        }
        else if (parse_list.back() == "scroll") {
            scrollBeingParsed->SetPosX(x + roomBeingParsed->getPosX());
        }
        else if (parse_list.back() == "sword") {
            swordBeingParsed->SetPosX(x + roomBeingParsed->getPosX());
        }
        else if (parse_list.back() == "armor") {
            armorBeingParsed->SetPosX(x + roomBeingParsed->getPosX());
        }
        bposX = false;
    }
    else if (bposY) {
        int x = std::stoi(data);
        if (parse_list.back() == "room") {
            roomBeingParsed->setPosY(x);
        }
        else if (parse_list.back() == "passage") {
            passageBeingParsed->setPosY(x);
            passageBeingParsed->addPosY(x);
        }
        else if (parse_list.back() == "monster") {
            monsterBeingParsed->setPosY(x + roomBeingParsed->getPosY());
        }
        else if (parse_list.back() == "player") {
            playerBeingParsed->setPosY(x + roomBeingParsed->getPosY());
        }
        else if (parse_list.back() == "scroll") {
            scrollBeingParsed->setPosY(x + roomBeingParsed->getPosY());
        }
        else if (parse_list.back() == "sword") {
            swordBeingParsed->setPosY(x + roomBeingParsed->getPosY());
        }
        else if (parse_list.back() == "armor") {
            armorBeingParsed->setPosY(x + roomBeingParsed->getPosY());
        }
        bposY = false;
    }
    else if (bwidth) {
        int x = std::stoi(data);
        if (parse_list.back() == "room") {
            roomBeingParsed->SetWidth(x);
        }
        else if (parse_list.back() == "passage") {
            passageBeingParsed->SetWidth(x);
        }
        bwidth = false;
    }
    else if (bheight) {
        int x = std::stoi(data);
        if (parse_list.back() == "room") {
            roomBeingParsed->setHeight(x);
        }
        else if (parse_list.back() == "passage") {
            passageBeingParsed->setHeight(x);
        }
        bheight = false;
    }
    else if (btype) {
        std::string type = (data);
        char t = type[0];
        monsterBeingParsed->setType(t);
        btype = false;
    }
    else if (bhp) {
        int x = std::stoi(data);
        if (parse_list.back() == "monster") {
            monsterBeingParsed->setHp(x);
        }
        else if (parse_list.back() == "player") {
            playerBeingParsed->setHp(x);
        }
        bhp = false;
    }
    else if (bmaxhit) {
        int x = std::stoi(data);
        if (parse_list.back() == "monster") {
            monsterBeingParsed->setMaxHit(x);
        }
        else if (parse_list.back() == "player") {
            playerBeingParsed->setMaxHit(x);
        }
        bmaxhit = false;
    }
    else if (bhpMoves) {
        int x = std::stoi(data);
        if (parse_list.back() == "monster") {
            monsterBeingParsed->setHpMoves(x);
        }
        else if (parse_list.back() == "player") {
            playerBeingParsed->setHpMoves(x);
        }
        bhpMoves = false;
    }
    else if (bitemintval) {
        int x = std::stoi(data);
        if (parse_list.back() == "scroll") {
            scrollBeingParsed->setIntValue(x);
        }
        else if (parse_list.back() == "sword") {
            swordBeingParsed->setIntValue(x);
        }
        else if (parse_list.back() == "armor") {
            armorBeingParsed->setIntValue(x);
        }
        bitemintval = false;
    }
    else if (bactionintval) {
        int x = std::stoi(data);
        actionBeingParsed->setIntValue(x);
        bactionintval = false;
    }
    else if (bactionmessage) {
        actionBeingParsed->setMessage(data);
        bactionmessage = false;
    }
    else if (bactioncharval) {
        std::string foo = data;
        char val = foo[0];
        actionBeingParsed->setCharValue(val);
        bactioncharval = false;
    }
    if (case_insensitive_match(qNameStr, "Dungeon")) {
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "Rooms")) {
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "Passages")) {
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "Room")) {
        dungeonBeingparsed->addRoom(roomBeingParsed);
        roomBeingParsed = NULL;
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "Passage")) {
        dungeonBeingparsed->addPassage(passageBeingParsed);
        passageBeingParsed = NULL;
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "Monster")) {
        roomBeingParsed->setCreature(monsterBeingParsed);
        dungeonBeingparsed->addCreature(monsterBeingParsed);
        monsterBeingParsed = NULL;
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "Player")) {
        roomBeingParsed->setCreature(playerBeingParsed);
        dungeonBeingparsed->addCreature(playerBeingParsed);
        playerBeingParsed = NULL;
        inPlayer = false;
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "Scroll")) {
        if (inPlayer) {
            scrollBeingParsed->setOwner(playerBeingParsed);
        }
        dungeonBeingparsed->addItem(scrollBeingParsed);
        scrollBeingParsed = NULL;
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "Sword")) {
        if (inPlayer) {
            swordBeingParsed->setOwner(playerBeingParsed);
            playerBeingParsed->setWeapon(swordBeingParsed);
            dungeonBeingparsed->addItem2Pack((Item*)swordBeingParsed);
        }
        else {
            dungeonBeingparsed->addItem(swordBeingParsed);
        }
        swordBeingParsed = NULL;
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "Armor")) {
        if (inPlayer) {
            armorBeingParsed->setOwner(playerBeingParsed);
            playerBeingParsed->setArmor(armorBeingParsed);
            dungeonBeingparsed->addItem2Pack((Item*)armorBeingParsed);
        }
        else {
            dungeonBeingparsed->addItem(armorBeingParsed);
        }
        armorBeingParsed = NULL;
        parse_list.pop_back();
    }
    else if (case_insensitive_match(qNameStr, "CreatureAction")) {
        parse_list.pop_back();
        if (parse_list.back() == "player") {
            if (bhit) {
                playerBeingParsed->addHitAction((CreatureAction*)actionBeingParsed);
                bhit = false;
            }
            else if (bdeath) {
                playerBeingParsed->addDeathAction((CreatureAction*)actionBeingParsed);
                bdeath = false;
            }
        }
        else if (parse_list.back() == "monster") {
            if (bhit) {
                monsterBeingParsed->addHitAction((CreatureAction*)actionBeingParsed);
                bhit = false;
            }
            else if (bdeath) {
                monsterBeingParsed->addDeathAction((CreatureAction*)actionBeingParsed);
                bdeath = false;
            }
        }
        actionBeingParsed = NULL;
    }
    else if (case_insensitive_match(qNameStr, "ItemAction")) {
        parse_list.pop_back();
        if (parse_list.back() == "scroll") {
            scrollBeingParsed->setItemAction((ItemAction*)actionBeingParsed);
        }

        actionBeingParsed = NULL;
    }
}

void DungeonXMLHandler::characters(const XMLCh* const ch, const XMLSize_t length) {
    data = xmlChToString(ch, (int)length);
    if (DEBUG > 1) {
        std::cout << CLASSID + ".characters: " << data << std::endl;
        std::cout.flush();
    }
}
