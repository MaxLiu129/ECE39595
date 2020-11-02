#include <curses.h>
#include "curses.h"
#include <vector>
#include <iostream>
#include "ObjectDisplayGrid.hpp"
#ifdef _WIN32
	#include <windows.h>
#endif

// I am not certain about the threadsafety of ncurse methods.
// They appear to work just fine in my testing, but that is likely as it always sets the cursor position before writing

ObjectDisplayGrid::ObjectDisplayGrid(int _width, int _height, int _messages) : width(_width), height(_height+4), messages(_messages) {	
	// create the 2D array of grid characters
	// note if you want to write messages instead, ncurses
	//objectGrid = new GridChar**[width];
	objectGrid = new std::vector<char> * [width];
	for (int i = 0; i < width; i++) {
		objectGrid[i] = new std::vector<char>[height];
		for (int j = 0; j < height; j++) {
			objectGrid[i][j].push_back(NULL);
		}
	}

	// initialize ncurses

	// set command window size if running on windows, useful when running in Visual Studio
	// as far as I am aware, no way to do this on linux
	#ifdef _WIN32
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD size = { (short)width, (short)(height + messages) };
		SMALL_RECT DisplayArea = { 0, 0, (short)(size.X - 1), (short)(size.Y - 1) };
		SetConsoleScreenBufferSize(handle, size);
		SetConsoleWindowInfo(handle, TRUE, &DisplayArea);
	#endif
	
	// initializes ncurses
	initscr();
	// makes characters typed immediately available, instead of waiting for enter to be pressed
	cbreak(); 
	// stops typed characters from being shown, makes it easier to get keypresses
	noecho();
	// clears the screen to start
	clear();
}

ObjectDisplayGrid::~ObjectDisplayGrid() {
	// free memory from the dynamically sized object grid
	for (int i = 0; i < width; i++) {
		// delete all character objects in the grid
		// delete the column
		delete[] objectGrid[i];
	}
	// delete the array of columns
	delete[] objectGrid;
	objectGrid = NULL;

	// free ncurses data
	endwin();
}

void ObjectDisplayGrid::addObjectToDisplay(char ch, int x, int y) {
	// note grid objects start from 0,0 and go until width,height
	// x between 0 and width
	if ((0 <= x) && (x < width)) {
		// y between 0 and height
		if ((0 <= y) && (y < height)) {
			// add new character to the internal character list
			objectGrid[x][y].push_back(ch);
			// draws the character on the screen, note it is relative to 0,0 of the terminal
			mvaddch(y, x, ch);
		}
	}
}

void ObjectDisplayGrid::removeObjectToDisplay(int x, int y) {
	if ((0 <= x) && (x < width)) {
		// y between 0 and height
		if ((0 <= y) && (y < height)) {
			// remove new character to the internal character list
			objectGrid[x][y].pop_back();
			mvaddch(y, x, objectGrid[x][y].back());

		}
	}
}


void ObjectDisplayGrid::update() {
	// refreshes ncurses
	refresh();
}

void ObjectDisplayGrid::writeLine(int line, std::string message) {
	// messages start from 0, height and go until width,(height + messages)
	mvaddstr(height + line - 1, 0, message.c_str());     // this +1 is temp for step2
	// clear after what we wrote to EOL
	clrtoeol();
}

void ObjectDisplayGrid::writeTopLine(int line, std::string message) {
	// messages start from 0, height and go until width,(height + messages)
	mvaddstr(line - 1, 0, message.c_str());
	// clear after what we wrote to EOL
	clrtoeol();
}

void ObjectDisplayGrid::setTopMessageHeight(int _topHeight) {
    topHeight = _topHeight;
    std::cout << "Top message height set, it is " + std::to_string(_topHeight) << std::endl;
}

void ObjectDisplayGrid::setBotHeight(int _bottomHeight) {
    bottomHeight = _bottomHeight;
    std::cout << "Bottom Height set, it is " + std::to_string(_bottomHeight) << std::endl;
}

int ObjectDisplayGrid::getWidth(){return width;}
int ObjectDisplayGrid::getHeight(){return height;}
int ObjectDisplayGrid::getMessages(){return messages;}


void ObjectDisplayGrid::getObjectDisplayGrid(int _gameHeight, int _width, int _topHeight) {
 gameHeight = _gameHeight;
 width = _width;
 topHeight = _topHeight;
 std::cout << "Object Display Grid get, gameHeight is " + std::to_string(_gameHeight) + " width is " + std::to_string(_width) + " topHieght is " + std::to_string(_topHeight) << std::endl;
 }


