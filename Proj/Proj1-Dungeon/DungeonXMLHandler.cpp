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

std::vector<Student> DungeonXMLHandler::getStudents() {
    return students;
}

DungeonXMLHandler::DungeonXMLHandler() {

}

void DungeonXMLHandler::startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes){

        char * qNameStr = xercesc::XMLString::transcode(qName);
        if (DEBUG > 1) {
            std::cout << CLASSID << ".startElement qName: " << qNameStr << std::endl;
        }
        if (case_insensitive_match(qNameStr, "Dungeon")){
            dungeonBeingparsed = new Dungoen();      //dbp = Dungeon Being Parsed
            odgBeingParsed = new ObjectDisplayGrid();   //obp = odg Being Parsed

            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));;
            int width = std::stoi(attributes.getValue("width"));
            int gameHeight = std::stoi(attributes.getValue("gameHeight"));
            int topHeight = std::stoi(attributes.getValue("topHeight"));
            int bottomHeight = std::stoi(attributes.getValue("bottomHeight"));

            dungeonBeingparsed.getDungeon(name, width, gameHeight);
            odgBeingParsed.getObjectDisplayGrid(gameHeight, width, topHeight);
            odgBeingParsed.setbottomHeight(bottomHeight);
        }
        else if(case_insensitive_match(qNameStr, "Rooms")){}
        else if(case_insensitive_match(qNameStr, "Room")){
            int id = std::stoi(attributes.getValue("room"));
            roomBeingParsed = new Room(std::stoi(id));
            displayType = DisaplayType.ROOM;
        }
        else if(case_insensitive_match(qNameStr, "Passages")){}
        else if(case_insensitive_match(qNameStr, "Passage")){
            int room1 = std::stoi(attributes.getValue("room1"));
            int room2 = std::stoi(attributes.getValue("room2"));
            passageBeingParsed = new Passage();
            passageBeingParsed.setID(room1, room2);
            displayType = DisplayType.PASSAGE; 
        }
        else if(case_insensitive_match(qNameStr, "Monster")){
            monsterBeingParsed = new Monster();
            String name = attributes.getValue("name");
            int room = std::stoi(attributes.getValue("room"));
            int serial = std::stoi(attributes.getValue("serial"));
            monsterBeingParsed.setID(room, serial);
            monsterBeingParsed.setName(name);
            displayType = DisplayType.MONSTER;
        }
        else if(case_insensitive_match(qNameStr, "Player")){
            playerBeingParsed = new Player();
            displayType = DisplayType.PLAYER;
            inPlayer = true; 
        }
        else if(case_insensitive_match(qNameStr, "Scroll")){
            String name = attributes.getValue("name");
            int room = std::stoi(attributes.getValue("room"));
            int serial = std::stoi(attributes.getValue("serial"));
            scrollBeingParsed = new Scroll(name);
            scrollBeingParsed.setID(room, serial);
            displayType = DisplayType.SCROLL;
        }
        else if(case_insensitive_match(qNameStr, "Sword")){
            String name = attributes.getValue("name");
            int room = std::stoi(attributes.getValue("room"));
            int serial = std::stoi(attributes.getValue("serial"));
            swordBeingParsed = new Sword(name);
            swordBeingParsed.setID(room, serial);
            displayType = DisplayType.SWORD;
        }
        else if(case_insensitive_match(qNameStr, "Armor")){
            String name = attributes.getValue("name");
            int room = Integer.parseInt(attributes.getValue("room"));
            int serial = Integer.parseInt(attributes.getValue("serial"));
            armorBeingParsed = new Armor(name);
            armorBeingParsed.setID(room, serial);
            displayType = DisplayType.ARMOR;
        }
        else if(case_insensitive_match(qNameStr, "CreatureAction") || case_insensitive_match(qNameStr, "ItemAction") ){
            //this gonna be long
            String name = attributes.getValue("name");
            String type = attributes.getValue("type");

            switch (name) {
                case "ChangeDisplayedType" :
                    if (displayType == DisplayType.MONSTER) {
                        actionBeingParsed = new ChangeDisplayedType(type, monsterBeingParsed);
                    } else {
                        actionBeingParsed = new ChangeDisplayedType(type, playerBeingParsed);
                    }
                    break;
                case "DropPack" :
                    if (displayType == DisplayType.MONSTER) {
                        actionBeingParsed = new DropPack(type, monsterBeingParsed);
                    } else {
                        actionBeingParsed = new DropPack(type, playerBeingParsed);
                    }                    
                    break;
                case "EndGame" :
                    if (displayType == DisplayType.MONSTER) {
                        actionBeingParsed = new EndGame(type, monsterBeingParsed);
                    } else {
                        actionBeingParsed = new EndGame(type, playerBeingParsed);
                    }                    
                    break;
                case "Remove" :
                    if (displayType == DisplayType.MONSTER) {
                        actionBeingParsed = new Remove(type, monsterBeingParsed);
                    } else {
                        actionBeingParsed = new Remove(type, playerBeingParsed);
                    }                    
                    break;
                case "Teleport" :
                    if (displayType == DisplayType.MONSTER) {
                        actionBeingParsed = new Teleport(type, monsterBeingParsed);
                    } else {
                        actionBeingParsed = new Teleport(type, playerBeingParsed);
                    }                    
                    break;
                case "UpdateDisplay" :
                    if (displayType == DisplayType.MONSTER) {
                        actionBeingParsed = new UpdateDisplay(type, monsterBeingParsed);
                    } else {
                        actionBeingParsed = new UpdateDisplay(type, playerBeingParsed);
                    }                    
                    break;
                case "YouWin" :
                    if (displayType == DisplayType.MONSTER) {
                        actionBeingParsed = new YouWin(type, monsterBeingParsed);
                    } else {
                        actionBeingParsed = new YouWin(type, playerBeingParsed);
                    }                    
                    break;
                case "Hallucinate" :
                    if (displayType == DisplayType.ARMOR) {
                        actionBeingParsed = new Hallucinate(armorBeingParsed);
                    } else if (displayType == DisplayType.SCROLL) {
                        actionBeingParsed = new Hallucinate(scrollBeingParsed);
                    } else {
                        actionBeingParsed = new Hallucinate(swordBeingParsed);
                    }
                    break;
                case "BlessCurseOwner" :
                    if (displayType == DisplayType.ARMOR) {
                        actionBeingParsed = new BlessCurseOwner(armorBeingParsed);
                    } else if (displayType == DisplayType.SCROLL) {
                        actionBeingParsed = new BlessCurseOwner(scrollBeingParsed);
                    } else {
                        actionBeingParsed = new BlessCurseOwner(swordBeingParsed);
                    }
                    break;
                case "BlessArmor" :
                    if (displayType == DisplayType.ARMOR) {
                        actionBeingParsed = new BlessArmor(armorBeingParsed);
                    } else if (displayType == DisplayType.SCROLL) {
                        actionBeingParsed = new BlessArmor(scrollBeingParsed);
                    } else {
                        actionBeingParsed = new BlessArmor(swordBeingParsed);
                    }
                    break;
                default: 
                    std::cout << "Unknown action: " + name << std::endl;
                    break;
        }
        } else if (qName.equalsIgnoreCase("visible")) {
            bvisible = true;
        } else if (qName.equalsIgnoreCase("posX")) {
            bposX = true;
        } else if (qName.equalsIgnoreCase("posY")) {
            bposY = true;
        } else if (qName.equalsIgnoreCase("width")) {
            bwidth = true;
        } else if (qName.equalsIgnoreCase("height")) {
            bheight = true;
        } else if (qName.equalsIgnoreCase("type")) {
            btype = true;
        } else if (qName.equalsIgnoreCase("hp")) {
            bhp = true;
        } else if (qName.equalsIgnoreCase("maxhit")) {
            bmaxhit = true;
        } else if (qName.equalsIgnoreCase("hpMoves")) {
            bhpMoves = true;
        } else if (qName.equalsIgnoreCase("ItemIntValue")) {
            bitemintval = true;
        } else if (qName.equalsIgnoreCase("actionIntValue")) {
            bactionintval = true;
        } else if (qName.equalsIgnoreCase("actionMessage")) {
            bactionmessage = true;
        } else if (qName.equalsIgnoreCase("actionCharValue")) {
            bactioncharval = true;
        } else {
            std::cout << "Unknown qname: " + qName << std::endl;
        }

        data = new StringBuilder();
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

void endElement(String uri, String localName, String qName){
        if (bvisible) {
            if (std::stoi(std::to_string(data)) == 1) {
                if (displayType == DisplayType.ROOM) {
                    roomBeingParsed.setVisible();
                } else if (displayType == DisplayType.PASSAGE) {
                    passageBeingParsed.setVisible();
                } else if (displayType == DisplayType.MONSTER) {
                    monsterBeingParsed.setVisible();
                } else if (displayType == DisplayType.PLAYER) {
                    playerBeingParsed.setVisible();
                } else if (displayType == DisplayType.SCROLL) {
                    scrollBeingParsed.setVisible();
                } else if (displayType == DisplayType.SWORD) {
                    swordBeingParsed.setVisible();
                } else if (displayType == DisplayType.ARMOR) {
                    armorBeingParsed.setVisible();
                }
            } else {
                if (displayType == DisplayType.ROOM) {
                    roomBeingParsed.setInvisible();
                } else if (displayType == DisplayType.PASSAGE) {
                    passageBeingParsed.setInvisible();
                } else if (displayType == DisplayType.MONSTER) {
                    monsterBeingParsed.setInvisible();
                } else if (displayType == DisplayType.PLAYER) {
                    playerBeingParsed.setInvisible();
                } else if (displayType == DisplayType.SCROLL) {
                    scrollBeingParsed.setInvisible();
                } else if (displayType == DisplayType.SWORD) {
                    swordBeingParsed.setInvisible();
                } else if (displayType == DisplayType.ARMOR) {
                    armorBeingParsed.setInvisible();
                }
            }   
            bvisible = false;
        } else if (bposX) {
            int x = std::stoi(std::to_string(data));
            if (displayType == DisplayType.ROOM) {
                roomBeingParsed.setPosX(x);
            } else if (displayType == DisplayType.PASSAGE) {
                passageBeingParsed.setPosX(x);
            } else if (displayType == DisplayType.MONSTER) {
                monsterBeingParsed.setPosX(x);
            } else if (displayType == DisplayType.PLAYER) {
                playerBeingParsed.setPosX(x);
            } else if (displayType == DisplayType.SCROLL) {
                scrollBeingParsed.setPosX(x);
            } else if (displayType == DisplayType.SWORD) {
                swordBeingParsed.setPosX(x);
            } else if (displayType == DisplayType.ARMOR) {
                armorBeingParsed.setPosX(x);
            }            
            bposX = false;
        } else if (bposY) {
            int x = std::stoi(std::to_string(data));
            if (displayType == DisplayType.ROOM) {
                roomBeingParsed.setPosY(x);
            } else if (displayType == DisplayType.PASSAGE) {
                passageBeingParsed.setPosY(x);
            } else if (displayType == DisplayType.MONSTER) {
                monsterBeingParsed.setPosY(x);
            } else if (displayType == DisplayType.PLAYER) {
                playerBeingParsed.setPosY(x);
            } else if (displayType == DisplayType.SCROLL) {
                scrollBeingParsed.setPosY(x);
            } else if (displayType == DisplayType.SWORD) {
                swordBeingParsed.setPosY(x);
            } else if (displayType == DisplayType.ARMOR) {
                armorBeingParsed.setPosY(x);
            }                
            bposY = false;
        } else if (bwidth) {
            int x = std::stoi(std::to_string(data));
            if (displayType == DisplayType.ROOM) {
                roomBeingParsed.setWidth(x);
            } else if (displayType == DisplayType.PASSAGE) {
                passageBeingParsed.setWidth(x);
            } 
            bwidth = false;
        } else if (bheight) {
            int x = std::stoi(std::to_string(data));
            if (displayType == DisplayType.ROOM) {
                roomBeingParsed.setHeight(x);
            } else if (displayType == DisplayType.PASSAGE) {
                passageBeingParsed.setHeight(x);
            }
            bheight = false;
        } else if (btype) {
            String type = (std::to_string(data));
            char t = type[0];
            monsterBeingParsed.setType(t);
            btype = false;
        } else if (bhp) {
            int x = std::stoi(std::to_string(data));
            if (displayType == DisplayType.MONSTER) {
                monsterBeingParsed.setHp(x);
            } else if (displayType == DisplayType.PLAYER) {
                playerBeingParsed.setHp(x);
            }
            bhp = false;
        } else if (bmaxhit) {
            int x = std::stoi(std::to_string(data));
            if (displayType == DisplayType.MONSTER) {
                monsterBeingParsed.setMaxHit(x);
            } else if (displayType == DisplayType.PLAYER) {
                playerBeingParsed.setMaxHit(x);
            }
            bmaxhit = false;
        } else if (bhpMoves) {
            int x = std::stoi(std::to_string(data));
            if (displayType == DisplayType.MONSTER) {
                monsterBeingParsed.setHpMoves(x);
            } else if (displayType == DisplayType.PLAYER) {
                playerBeingParsed.setHpMoves(x);
            }
            bhpMoves = false;
        } else if (bitemintval) {
            int x = std::stoi(std::to_string(data));
            if (displayType == DisplayType.SCROLL) {
                scrollBeingParsed.setIntValue(x);
            } else if (displayType == DisplayType.SWORD) {
                swordBeingParsed.setIntValue(x);
            } else if (displayType == DisplayType.ARMOR) {
                armorBeingParsed.setIntValue(x);
            }  
            bitemintval = false;
        } else if (bactionintval) {
            int x = std::stoi(std::to_string(data));
            actionBeingParsed.setIntValue(x);
            bactionintval = false;
        } else if (bactionmessage) {
            String message = (std::to_string(data));
            actionBeingParsed.setMessage(message);
            bactionmessage = false;
        } else if (bactioncharval) {
            String foo = std::to_string(data);
            char val = foo[0];
            actionBeingParsed.setCharValue(val);
            bactioncharval = false;
        }
    
        if (qName.equalsIgnoreCase("Dungeon")) {
            dungeonBeingparsed = null;
            odgBeingParsed = null;
        } else if (qName.equalsIgnoreCase("Rooms") || qName.equalsIgnoreCase("Passages")) {
        } else if (qName.equalsIgnoreCase("Room")) {
            dungeonBeingparsed.addRoom(roomBeingParsed);
            roomBeingParsed = null;
            displayType = null;
        } else if (qName.equalsIgnoreCase("Passage")) {
            dungeonBeingparsed.addPassage(passageBeingParsed);
            passageBeingParsed = null;
            displayType = null;
        } else if (qName.equalsIgnoreCase("Monster")) {
            roomBeingParsed.setCreature(monsterBeingParsed);
            dungeonBeingparsed.addCreature(monsterBeingParsed);
            monsterBeingParsed = null;
            displayType = null;
        } else if (qName.equalsIgnoreCase("Player")) {
            roomBeingParsed.setCreature(playerBeingParsed);
            dungeonBeingparsed.addCreature(playerBeingParsed);
            playerBeingParsed = null;
            displayType = null;           
            inPlayer = false; 
        } 
        else if (qName.equalsIgnoreCase("Scroll")) {
            if (inPlayer) {
                scrollBeingParsed.setOwner(playerBeingParsed);
            }
            dungeonBeingparsed.addItem(scrollBeingParsed);
            scrollBeingParsed = null;
            displayType = null;
        } else if (qName.equalsIgnoreCase("Sword")) {
            if (inPlayer) {
                swordBeingParsed.setOwner(playerBeingParsed);
                playerBeingParsed.setWeapon(swordBeingParsed);
            }
            dungeonBeingparsed.addItem(swordBeingParsed);
            swordBeingParsed = null;
            displayType = null;
        } else if (qName.equalsIgnoreCase("Armor")) {
            if (inPlayer) {
                armorBeingParsed.setOwner(playerBeingParsed);
                playerBeingParsed.setWeapon(armorBeingParsed);
            }
            dungeonBeingparsed.addItem(armorBeingParsed);
            armorBeingParsed = null;
            displayType = null;
        } else if (qName.equalsIgnoreCase("CreatureAction") || qName.equalsIgnoreCase("ItemAction")) {
            actionBeingParsed = null;
        }
    }