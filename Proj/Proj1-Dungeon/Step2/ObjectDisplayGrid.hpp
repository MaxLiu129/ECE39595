//
//  ObjectDisplayGrid.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef ObjectDisplayGrid_hpp
#define ObjectDisplayGrid_hpp

#include <stdio.h>
//#include <xercesc/sax2/SAX2XMLReader.hpp>
//#include <xercesc/sax2/XMLReaderFactory.hpp>
//#include <xercesc/sax2/DefaultHandler.hpp>
//#include <xercesc/util/XMLString.hpp>
//#include <xercesc/sax2/Attributes.hpp>
//#include <xercesc/util/XMLUni.hpp>
//#include <xercesc/util/PlatformUtils.hpp>
#include <stdio.h>
#include <vector>
#include <string>
#include "Displayable.hpp"
//#include "GridChar.h"


class ObjectDisplayGrid {
private:
    /** Keeps track of the characters on the screen */
    std::vector <char> ** objectGrid;
    //GridChar*** objectGrid;
    /** Keeps track of the consoles width and height */
    int height, width;

    /** Number of lines for message writing */
    int messages;
    //are we using these?
    int topHeight;
    int bottomHeight;
    int gameHeight;

public:
    /**
     * Creates a new display grid using the given parameters and initializes ncurses.
     * Screen height will be grid height + messages
     * @param width     Screen width
     * @param height    Grid height
     * @param messages  Number of lines to reserve in the message area
     */
    ObjectDisplayGrid(int width, int height, int messages);

    /** Object deconstructor, to delete the grid character matrix and free ncurses data */
    ~ObjectDisplayGrid();

    /**
     * Refreshes the grid display
     */
    virtual void update();

    /**
     * Adds an object to the display grid
     * @param ch  Object to display
     * @param x   X position
     * @param y   Y position
     */
    virtual void addObjectToDisplay(char ch, int x, int y);
    virtual void removeObjectToDisplay(int x, int y);
    /**
     * Writes a line of text to the screen at the given line relative to the bottom
     * @param line    line number
     * @param message message to write
     * @param update  If true, immediately updates the screen
     */
    virtual void writeLine(int line, std::string message);
    virtual void writeTopLine(int line, std::string message);
    virtual int getWidth();
    virtual int getHeight();
    virtual int getMessages();
   
    void setTopMessageHeight(int _topHeight);
    
    void setBotHeight(int _bottomHeight);
    void getObjectDisplayGrid(int _gameHeight, int _width, int _topHeight);

};

#endif /* ObjectDisplayGrid_hpp */
