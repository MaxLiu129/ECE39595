#include <atomic> 
#include <thread>
#include <sstream>
#include <iostream>
#include "ObjectDisplayGrid.hpp"
//#include "GridChar.h"
#include "KeyboardListener.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include "DungeonXMLHandler.hpp"
#include <exception>

// set to false when done running
std::atomic_bool isRunning(true);

void runDisplay(ObjectDisplayGrid* grid, Dungeon* dungeon) {
    // stop loop if isRunning is swapped to false
    char c;
    int topLinesRevered = 2;
    int hp = 0;
    //print HP and core
    grid->writeLine(0, ("Pack:"));
    grid->writeLine(2, ("Info:"));
    for (Creature* creature : dungeon->getCreatures()) {
        if (creature->getName() == "Player") {
            hp = creature->getCreatureHp();
        }
    }
    
    grid->writeTopLine(1, ("HP: " + std::to_string(hp) + "  core: 0")); // core = 0 for now(step2)
    //draw rooms
    for (Room* room : dungeon->getRooms()) {
        for (int i = 0; i < room -> Displayable::getWidth(); i++) {
            for (int j = 0; j < room ->Displayable::getHeight(); j++) {
                if (i == 0 || j == 0 || i + 1 == room ->Displayable::getWidth() || j + 1 == room ->Displayable::getHeight()) {
                    c = 'X';
                }
                else {
                    c = '.';
                }
                grid->addObjectToDisplay(c, (i + room ->Displayable::getPosX()), (j + room ->Displayable::getPosY() + topLinesRevered));
            }
            //std::cout << room->getPosX() << std::endl;
        }
        // update the grid
        grid->update();
        

    }
    //passage
    for (Passage* passage : dungeon->getPassages()) {
        //check passage direction before
        // x1 x2, y1, y2
        // x1 ---- x2, y1 ------y2
        for (int i = 1; i < passage->getPassagePosXs().size(); i++) {
            int posX1 = (passage->getPassagePosXs())[i - 1];
            int posX2 = (passage->getPassagePosXs())[i];
            int posY1 = (passage->getPassagePosYs())[i - 1];
            int posY2 = (passage->getPassagePosYs())[i];
            // wether x----x, or y ----y
            if (posX1 == posX2) {
                //going vertical
                if (posY1 > posY2) {
                    for (int j = posY2; j <= posY1; j++) {
                        if ((j == posY1 && i == 1) || (j == posY2 && i == passage->getPassagePosXs().size() - 1)) {
                            c = '+';
                        }
                        else {
                            c = '#';
                        }
                        grid->addObjectToDisplay(c, posX1, j + topLinesRevered);
                    }
                }
                else {
                    for (int j = posY1; j <= posY2; j++) {
                        if ((j == posY1 && i == 1) || (j == posY2 && i == passage->getPassagePosXs().size() - 1)) {
                            c = '+';
                        }
                        else {
                            c = '#';
                            
                        }
                        grid->addObjectToDisplay(c, posX1, j + topLinesRevered);
                    }
                }
            }
            else {
                //going x ------ x
             //determine dir
                if (posX1 > posX2) {
                    for (int j = posX2; j <= posX1; j++) {
                        if ((j == posX1 && i == 1) || (j == posX2 && i == passage->getPassagePosXs().size() - 1)) {
                            c = '+';
                        }
                        else {
                            c = '#';
                        }
                        grid->addObjectToDisplay(c, j, posY2 + topLinesRevered);
                    }
                }
                else {
                    for (int j = posX1; j <= posX2; j++) {
                        if ((j == posX1 && i == 1) || (j == posX2 && i == passage->getPassagePosXs().size() - 1)) {
                            c = '+';
                        }
                        else {
                            c = '#';
                        }
                        grid->addObjectToDisplay(c, j, posY2 + topLinesRevered);
                    }
                }
            }
        }
        //grid->addObjectToDisplay(c, (i + passage->Displayable::getPosX()), (j + passage->Displayable::getPosY()));
        // update the grid
        grid->update();
    }

    //display creatures (player, monster, items)
    for (Creature* creature : dungeon->getCreatures()) {
        if (creature ->getName() == "Player") {
            grid->addObjectToDisplay('@', creature->getPosX(), creature->getPosY() + topLinesRevered);
        }
        else {
            //creature_name = creature->getPlayerName();
            std::string monsterName = creature->getName();
            if (monsterName == "Troll") { grid->addObjectToDisplay('T', creature->getPosX(), creature->getPosY() + topLinesRevered); }
            else if (monsterName == "Snake") { grid->addObjectToDisplay('S', creature->getPosX(), creature->getPosY() + topLinesRevered); }
            else if (monsterName == "Hobgoblin") { grid->addObjectToDisplay('H', creature->getPosX(), creature->getPosY() + topLinesRevered); }
        }

        grid->update();
        //not needed for step2
        // wait a bit to rejoin
        // wait in a few steps to update faster on keypress
        //for (int i = 0; (isRunning && i < 5); i++) {
        //    std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //}
    }
    //display items(armor, scroll, sword)
    for (Item* item : dungeon->getItems()) {
        std::string itemName = item->getName();
        if(itemName == "Scroll"){ grid->addObjectToDisplay('?', item->getPosX(), item->getPosY() + topLinesRevered); }
        if (std::string::npos != itemName.find("Armor")) { grid->addObjectToDisplay(']', item->getPosX(), item->getPosY() + topLinesRevered); }
        if (std::string::npos != itemName.find("Sword")) { grid->addObjectToDisplay(')', item->getPosX(), item->getPosY() + topLinesRevered); }
        grid->update();
    }
}

void testOdg(ObjectDisplayGrid* odg, Dungeon* dungeon) {
    int WIDTH, HEIGHT, MESSAGES;
    
    
    WIDTH = dungeon->getDungeonWidth();
    HEIGHT = dungeon->getDungeonHeight();
    MESSAGES = odg->getMessages();
    
    std::string dungeonName = dungeon->getDungeonName();

    // thread to wait for key press
    KeyboardListener listener(odg);
    std::thread keyboardThread(&KeyboardListener::run, &listener, dungeon, odg);

    // thread to update display
    std::thread displayThread(runDisplay, odg, dungeon);

    // wait for the keyboard thread to finish, then notify the display to stop
    keyboardThread.join();
    isRunning = false;

    // wait for the display thread to finish
    displayThread.join();


}

int main(int argc, char* argv[]){

    std::string fileName = "./xmlFiles/badScroll.xml";
    try{
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Error during initialization! :\n";
        std::cout << "Exception message is: \n"
             << message << "\n";
        xercesc::XMLString::release(&message);
        return 1;
    }
    //switch (argc) {
    //    case 2:
    //        fileName = "./xmlfiles/" + ((std::string) argv[1]);
    //        break;
    //    default:
    //        std::cout << "c++ test <xmlfilename>" << std::endl;
    //}
    xercesc::SAX2XMLReader* parser = xercesc::XMLReaderFactory::createXMLReader();

    try {
        DungeonXMLHandler* handler = new DungeonXMLHandler();
        parser->setContentHandler(handler);
        parser->setErrorHandler(handler);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, true);
        XMLCh * fileNameXMLEnc = xercesc::XMLString::transcode(fileName.c_str()); //Encode string as UTF-16, but transcode needs casting as const char * (not std::string)
        parser->parse(fileNameXMLEnc);
        xercesc::XMLString::release(&fileNameXMLEnc);

        //start to deal with gird and movement.
            //run step 1's main to get xml information.
        Dungeon* new_dungeon = handler -> getDungeon();
        ObjectDisplayGrid* new_odg = handler -> getOdg();

        testOdg(new_odg, new_dungeon);
        
		delete parser;
		delete handler;
        
    } catch (const xercesc::XMLException& toCatch) {
            char* message = xercesc::XMLString::transcode(toCatch.getMessage());
            std::cout << "Exception message is: \n"
                 << message << "\n";
            xercesc::XMLString::release(&message);
            return -1;
    }
    catch (const xercesc::SAXParseException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Exception message is: \n"
             << message << "\n";
        xercesc::XMLString::release(&message);
        return -1;
    }
	catch(std::exception& e){
	    std::cout << e.what() << '\n';
	}
	catch(...){
        std::cout << "Unexpected Exception \n" ;
        return -1;
	}
    xercesc::XMLPlatformUtils::Terminate(); //valgrind will say there's memory errors if not included
	return 0;
}
