#include <atomic> 
#include <thread>
#include <sstream>
#include "ObjectDisplayGrid.hpp"
#include "GridChar.h"
#include "KeyboardListener.hpp"

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

// grid properties
int WIDTH = 150;
int HEIGHT = 40;
int MESSAGES = 5;




void runDisplay(ObjectDisplayGrid* grid) {

    // loop over each step, doubling each time
    // stop loop if isRunning is swapped to false
    for (int step = 1; (isRunning && step < WIDTH / 2); step *= 2) {
        // write a message, but don't update yet
        grid->writeLine(1, "Step " + std::to_string(step));

        // print characters to the screen
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                char c;
                if (i % step == 0 && j % step == 0) {
                    c = 'X';
                }
                else {
                    c = '.';
                }
                grid->addObjectToDisplay(new GridChar(c), i, j);
            }
        }

        // update the grid
        grid->update();

        // wait a bit to rejoin
        // wait in a few steps to update faster on keypress
        for (int i = 0; (isRunning && i < 5); i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
        }
    }
}

int main(int argc, char* argv[]){

    std::string fileName = "./xmlFiles/wear.xml";
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
    //        filename = "./xmlfiles/" + ((std::string) argv[1]);
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
        //parser->parse(new File(filename), handler);
        
        ////start to deal with gird and movement.
        //    //run step 1's main to get xml information.

        //// create an initialize the object display grid
        //int WIDTH, HEIGHT, MESSAGES;
        ////update the dimension of the dungeon.
        //WIDTH = handler -> getWidth();
        //HEIGHT = handler -> getHEIGHT();
        //MESSAGES = handler -> getMESSAGES();

        //ObjectDisplayGrid grid(WIDTH, HEIGHT, MESSAGES);
        //ObjectDisplayGrid* pGrid = &grid;

        //// thread to wait for key press
        //KeyboardListener listener(pGrid);
        //std::thread keyboardThread(&KeyboardListener::run, &listener);

        //// thread to update display
        //std::thread displayThread(runDisplay, pGrid);

        //// wait for the keyboard thread to finish, then notify the display to stop
        //keyboardThread.join();
        //isRunning = false;

        //// wait for the display thread to finish
        //displayThread.join();
        
		delete parser;
		delete handler;
        /*
         * the above is a different form of 
         for (int i = 0; i < students.length; i++) {
            std::cout << students[i] << std::endl;
        }
        */
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