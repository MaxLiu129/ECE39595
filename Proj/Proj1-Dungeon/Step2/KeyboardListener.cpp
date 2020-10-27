#include "KeyboardListener.hpp"
// #include "Displayable.hpp"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(ObjectDisplayGrid* _grid) : grid(_grid) {}

void KeyboardListener::run() {
	grid->writeLine(0, "Press 'x' to exit");
	running = true;
	char input;
	do {
		// wait for next input
		// lowercase so 'x' and 'X' are treated as the same
		input = std::tolower(getchar());

		switch (input) {
		// press X to stop
		case 'x':
			running = false;
			grid->writeLine(2, "Exiting...");
			break;
        // handle wasd to control the player walk around.
        // 1. change PosX and PosY of the player, visibility of the ground and player
        // 2. When player hit the wall of the room, pop error and dont change anything.
        // 3. When player hit the road to another room
		case 'w':
            //the player should go up one grid.
            //determine if the player would hit the wall.
			
            //update PosX and PosY
			grid->writeLine(2, "You moved up one time.");
			break;
		default:
			// C is not happy about appending a character to a string apparently
			std::string message = "Unknown key '";
			message += input;
			grid->writeLine(2, message + "'");
			break;
		}
		grid->update();
	} while (running && input != EOF);
}