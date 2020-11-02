#include "DungeonXMLHandler.hpp"
#include <iostream> 
#include <sstream>
int case_insensitive_match(std::string s1, std::string s2) {
    //convert s1 and s2 into lower case strings
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower); //std overloads tolower, ::tolower is the definition in the global namespace
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if(s1.compare(s2) == 0)
        return 1;
    return 0;
}

inline std::string boolToString(bool booleanValue){
    return booleanValue ? "true": "false";
}

std::string xmlChToString(const XMLCh* xmlChName, int length = -1){
    //Xerces Parses file into XMLCh* string. So use Transcode to allocate a char* buffer
    char * chStarName = xercesc::XMLString::transcode(xmlChName); 
    if(length == -1){
        std::string StrName(chStarName);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
    else{
        std::string StrName(chStarName,0,length);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }

}

const XMLCh* getXMLChAttributeFromString(const xercesc::Attributes& attributes, const char * strGet){
    XMLCh * xmlChGet = xercesc::XMLString::transcode(strGet);
    const XMLCh * xmlChAttr = attributes.getValue(xmlChGet);
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


void DungeonXMLHandler::startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes){

        char * qNameStr = xercesc::XMLString::transcode(qName);
        if (DEBUG > 1) {
            std::cout << CLASSID << ".startElement qName: " << qNameStr << std::endl;
        }
        if (case_insensitive_match(qNameStr, "Dungeon")){
            dungeonBeingparsed = new Dungeon();      //dbp = Dungeon Being Parsed


            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int width = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"width")));
            int gameHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"gameHeight")));
            int topHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"topHeight")));
            int bottomHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"bottomHeight")));
            odgBeingParsed = new ObjectDisplayGrid(width, gameHeight, topHeight);   //obp = odg Being Parsed
            dungeonBeingparsed->getDungeon(name, width, gameHeight);
            odgBeingParsed->getObjectDisplayGrid(gameHeight, width, topHeight);
            odgBeingParsed->setBotHeight(bottomHeight);

            odg = new ObjectDisplayGrid(width, gameHeight, topHeight);
            odg->getObjectDisplayGrid(gameHeight, width, topHeight);
            odg->setBotHeight(bottomHeight);
        }
        else if(case_insensitive_match(qNameStr, "Rooms")){}
        else if(case_insensitive_match(qNameStr, "Room")){
            int id = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            roomBeingParsed = new Room(id);

            //new_room = new Room(id);

        }
        else if(case_insensitive_match(qNameStr, "Passages")){}
        else if(case_insensitive_match(qNameStr, "Passage")){
            int room1 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room1")));
            int room2 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room2")));
            passageBeingParsed = new Passage();
            passageBeingParsed->setID(room1, room2);

        }
        else if(case_insensitive_match(qNameStr, "Monster")){
            monsterBeingParsed = new Monster();
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
            monsterBeingParsed->Creature::setID(room, serial);
            monsterBeingParsed->Creature::setName(name);
        }
        else if(case_insensitive_match(qNameStr, "Player")){
            playerBeingParsed = new Player();
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
            int room = std::stoi(getXMLChAttributeFromString(attributes, "room"));
            int serial = std::stoi(getXMLChAttributeFromString(attributes, "serial"));
            playerBeingParsed->Creature::setID(room, serial);
            playerBeingParsed->Creature::setName(name);
            inPlayer = true;
        }
        else if(case_insensitive_match(qNameStr, "Scroll")){
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
            scrollBeingParsed = new Scroll(name);
            scrollBeingParsed->Item::setID(room, serial);
            scrollBeingParsed->Item::setName(name);
        }
        else if(case_insensitive_match(qNameStr, "Sword")){
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
            swordBeingParsed = new Sword(name);
            swordBeingParsed->setID(room, serial);
            swordBeingParsed->Item::setName(name);
        }
        else if(case_insensitive_match(qNameStr, "Armor")){
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));
            armorBeingParsed = new Armor();
            armorBeingParsed->setID(room, serial);
            armorBeingParsed->Item::setName(name);
        }
        else if (case_insensitive_match(qNameStr, "CreatureAction") || case_insensitive_match(qNameStr, "ItemAction")) {
            //this gonna be long
            Creature* temp_owner = NULL;
            Item* item_owner = NULL;
            if (playerBeingParsed != NULL) {
                temp_owner = playerBeingParsed;
                actionBeingParsed = new CreatureAction(temp_owner);
            }
            else if (monsterBeingParsed != NULL){
                temp_owner = monsterBeingParsed;
                actionBeingParsed = new CreatureAction(temp_owner);
            }
            else {
                if (scrollBeingParsed != NULL) {
                    item_owner = scrollBeingParsed;

                }
                else if (swordBeingParsed != NULL) {
                    item_owner = swordBeingParsed;
                }
                else {
                    item_owner = armorBeingParsed;
                }
                actionBeingParsed = new ItemAction(item_owner);
            }

            std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
            std::string type = xmlChToString(getXMLChAttributeFromString(attributes, "type"));
            if (name.compare("ChangeDisplayedType") == 0) {}
            else if (name.compare("DropPack") == 0) {}
            else if (name.compare("EndGame") == 0) {}
            else if (name.compare("Remove") == 0) {}
            else if (name.compare("Teleport") == 0) {}
            else if (name.compare("UpdateDisplay") == 0) {}
            else if (name.compare("YouWin") == 0) {}
            else if (name.compare("Hallucinate") == 0) {}
            else if (name.compare("BlessCurseOwner") == 0) {}
            else if (name.compare("BlessArmor") == 0) {}
            else {
                std::cout << "Unknown action: " + name << std::endl;
            }
            if (type.compare("death") == 0) {
                CreatureAction* ca = (CreatureAction*)actionBeingParsed;
                    temp_owner -> setDeathAction(ca);
            }
            else if (type.compare("hit") == 0) {
                CreatureAction* ca = (CreatureAction*)actionBeingParsed;
                    temp_owner->setDeathAction(ca);
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

        //data = new StringBuilder();
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
            if(std::stoi(data) == 1){
                if (roomBeingParsed != NULL) {
                    roomBeingParsed->setVisible();
                } else if (passageBeingParsed != NULL) {
                    passageBeingParsed->setVisible();
                } else if (monsterBeingParsed != NULL) {
                    monsterBeingParsed->setVisible();
                } else if (playerBeingParsed != NULL) {
                    playerBeingParsed->setVisible();
                } else if (scrollBeingParsed != NULL) {
                    scrollBeingParsed->setVisible();
                } else if (swordBeingParsed != NULL) {
                    swordBeingParsed->setVisible();
                } else if (armorBeingParsed != NULL) {
                    armorBeingParsed->setVisible();
                }
            } 
            else {
                if (roomBeingParsed != NULL) {
                    roomBeingParsed->setInvisible();
                } else if (passageBeingParsed != NULL) {
                    passageBeingParsed->setInvisible();
                } else if (monsterBeingParsed != NULL) {
                    monsterBeingParsed->setInvisible();
                } else if (playerBeingParsed != NULL) {
                    playerBeingParsed->setInvisible();
                } else if (scrollBeingParsed != NULL) {
                    scrollBeingParsed->setInvisible();
                } else if (swordBeingParsed != NULL) {
                    swordBeingParsed->setInvisible();
                } else if (armorBeingParsed != NULL) {
                    armorBeingParsed->setInvisible();
                }
            }   
            bvisible = false;
        } 
        else if (bposX) {
            int x = std::stoi(data);
            if (roomBeingParsed != NULL && monsterBeingParsed == NULL && playerBeingParsed == NULL && scrollBeingParsed == NULL && swordBeingParsed == NULL && armorBeingParsed == NULL) {
                roomBeingParsed->Displayable::SetPosX(x);
            } else if (passageBeingParsed != NULL) {
                passageBeingParsed->Displayable::SetPosX(x);
                passageBeingParsed->addPosX(x);
            } else if (monsterBeingParsed != NULL) {
                monsterBeingParsed->Displayable::SetPosX(x + roomBeingParsed->getPosX());
            } else if (playerBeingParsed != NULL && swordBeingParsed == NULL && armorBeingParsed == NULL) {
                playerBeingParsed->Displayable::SetPosX(x + roomBeingParsed->getPosX());
            } else if (scrollBeingParsed != NULL) {
                scrollBeingParsed->Displayable::SetPosX(x + roomBeingParsed->getPosX());
            } else if (swordBeingParsed != NULL) {
                swordBeingParsed->Displayable::SetPosX(x + roomBeingParsed->getPosX());
            } else if (armorBeingParsed != NULL) {
                armorBeingParsed->Displayable::SetPosX(x + roomBeingParsed->getPosX());
            }            
            bposX = false;
        } else if (bposY) {
            int x = std::stoi(data);
            if (roomBeingParsed != NULL && monsterBeingParsed == NULL && playerBeingParsed == NULL && scrollBeingParsed == NULL && swordBeingParsed == NULL && armorBeingParsed == NULL) {
                roomBeingParsed->Displayable::setPosY(x);
            } else if (passageBeingParsed != NULL) {
                passageBeingParsed->Displayable::setPosY(x);
                passageBeingParsed->addPosY(x);
            } else if (monsterBeingParsed != NULL) {
                monsterBeingParsed->Displayable::setPosY(x + roomBeingParsed->getPosY());
            } else if (playerBeingParsed != NULL) {
                playerBeingParsed->Displayable::setPosY(x + roomBeingParsed->getPosY());
            } else if (scrollBeingParsed != NULL) {
                scrollBeingParsed->Displayable::setPosY(x + roomBeingParsed->getPosY());
            } else if (swordBeingParsed != NULL) {
                swordBeingParsed->Displayable::setPosY(x + roomBeingParsed->getPosY());
            } else if (armorBeingParsed != NULL) {
                armorBeingParsed->Displayable::setPosY(x + roomBeingParsed->getPosY());
            }                
            bposY = false;
        } else if (bwidth) {
            int x = std::stoi(data);
            if (roomBeingParsed != NULL) {
                roomBeingParsed->SetWidth(x);
            } else if (passageBeingParsed != NULL) {
                passageBeingParsed->SetWidth(x);
            } 
            bwidth = false;
        } else if (bheight) {
            int x = std::stoi(data);
            if (roomBeingParsed != NULL) {
                roomBeingParsed->setHeight(x);
            } else if (passageBeingParsed != NULL) {
                passageBeingParsed->setHeight(x);
            }
            bheight = false;
        } else if (btype) {
            std::string type = (data);
            char t = type[0];
            monsterBeingParsed->setType(t);
            btype = false;
        } else if (bhp) {
            int x = std::stoi(data);
            if (monsterBeingParsed != NULL) {
                monsterBeingParsed->setHp(x);
            } else if (playerBeingParsed != NULL) {
                playerBeingParsed->setHp(x);
            }
            bhp = false;
        } else if (bmaxhit) {
            int x = std::stoi(data);
            if (monsterBeingParsed != NULL) {
                monsterBeingParsed->setMaxHit(x);
            } else if (playerBeingParsed != NULL) {
                playerBeingParsed->setMaxHit(x);
            }
            bmaxhit = false;
        } else if (bhpMoves) {
            int x = std::stoi(data);
            if (monsterBeingParsed != NULL) {
                monsterBeingParsed->setHpMoves(x);
            } else if (playerBeingParsed != NULL) {
                playerBeingParsed->setHpMoves(x);
            }
            bhpMoves = false;
        } else if (bitemintval) {
            int x = std::stoi(data);
            if (scrollBeingParsed != NULL) {
                scrollBeingParsed->setIntValue(x);
            } else if (swordBeingParsed != NULL) {
                swordBeingParsed->setIntValue(x);
            } else if (armorBeingParsed != NULL) {
                armorBeingParsed->setIntValue(x);
            }  
            bitemintval = false;
        } else if (bactionintval) {
            int x = std::stoi(data);
            actionBeingParsed->setIntValue(x);
            bactionintval = false;
        } else if (bactionmessage) {
            std::string message = (data);
            actionBeingParsed->setMessage(message);
            bactionmessage = false;
        } else if (bactioncharval) {
            std::string foo = data;
            char val = foo[0];
            actionBeingParsed->setCharValue(val);
            bactioncharval = false;
        }
        if (case_insensitive_match(qNameStr, "Dungeon")) {
            odgBeingParsed = NULL;
        } else if (case_insensitive_match(qNameStr, "Rooms") || case_insensitive_match(qNameStr, "Passages")) {
        } else if (case_insensitive_match(qNameStr, "Room")) {
            dungeonBeingparsed->addRoom(roomBeingParsed);
            roomBeingParsed = NULL;
        } else if (case_insensitive_match(qNameStr, "Passage")) {
            dungeonBeingparsed->addPassage(passageBeingParsed);
            passageBeingParsed = NULL;
        } else if (case_insensitive_match(qNameStr, "Monster")) {
            roomBeingParsed->setCreature(monsterBeingParsed);
            dungeonBeingparsed->addCreature(monsterBeingParsed);
            monsterBeingParsed = NULL;
        } else if (case_insensitive_match(qNameStr, "Player")) {
            roomBeingParsed->setCreature(playerBeingParsed);
            dungeonBeingparsed->addCreature(playerBeingParsed);
            playerBeingParsed = NULL;
            inPlayer = false;
        } 
        else if (case_insensitive_match(qNameStr, "Scroll")) {
            if (inPlayer) {
                scrollBeingParsed->setOwner(playerBeingParsed);
            }
            dungeonBeingparsed->addItem(scrollBeingParsed);
            scrollBeingParsed = NULL;
        } else if (case_insensitive_match(qNameStr, "Sword")) {
            if (inPlayer) {
                swordBeingParsed->setOwner(playerBeingParsed);
                playerBeingParsed->setWeapon(swordBeingParsed);
            }
            dungeonBeingparsed->addItem(swordBeingParsed);
            swordBeingParsed = NULL;
        } else if (case_insensitive_match(qNameStr, "Armor")) {
            if (inPlayer) {
                armorBeingParsed->setOwner(playerBeingParsed);
                playerBeingParsed->setWeapon(armorBeingParsed);
            }
            dungeonBeingparsed->addItem(armorBeingParsed);
            armorBeingParsed = NULL;
        } else if (case_insensitive_match(qNameStr, "CreatureAction") || case_insensitive_match(qNameStr, "ItemAction")) {
            actionBeingParsed = NULL;
        }
    }

void DungeonXMLHandler::characters(const XMLCh * const ch, const XMLSize_t length) {
        data = xmlChToString(ch,(int)length) ;
        if (DEBUG > 1) {
            std::cout << CLASSID + ".characters: " << data << std::endl;
            std::cout.flush();
        }
}

