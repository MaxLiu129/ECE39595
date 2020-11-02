#include "KeyboardListener.hpp"
// #include "Displayable.hpp"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(ObjectDisplayGrid* _grid) : grid(_grid) {}

void KeyboardListener::run(Dungeon* dungeon, ObjectDisplayGrid* objectGrid) {
	//grid->writeLine(0, "Press 'x' to exit");
	running = true;
	char input;
	int topLinesReserved = 2;   // save 2 lines on the top of the win console to display hp and core.
	do {
		// wait for next input
		// lowercase so 'x' and 'X' are treated as the same
		input = std::tolower(getchar());

		switch (input) {
		// press X to stop
		case 'x':
			running = false;
			//grid->writeLine(2, "Exiting...");
			break;
			
        // handle wasd to control the player walk around.
        // 1. change PosX and PosY of the player, visibility of the ground and player
        // 2. When player hit the wall of the room, pop error and dont change anything.
        // 3. When player hit the road to another room
		case 'w':
			for (Creature* creature : dungeon->getCreatures()) {
				if (creature->getName() == "Player") {
					int playerX = creature->getPosX();
					int playerY = creature->getPosY() - 1;
					if (dungeon->checkPos(playerX, playerY) == true) {
						objectGrid->addObjectToDisplay('@', playerX, playerY+ topLinesReserved);
						creature->setPosY(playerY);
						objectGrid->removeObjectToDisplay(playerX, playerY + 1 + topLinesReserved);
						grid->writeLine(2, "Info: You moved up one time.");
					}
					else {
						grid->writeLine(2, "Info: You can not move up.");
					}
				}
			}
			break;
		case 's':
			for (Creature* creature : dungeon->getCreatures()) {
				if (creature->getName() == "Player") {
					int playerX = creature->getPosX();
					int playerY = creature->getPosY() + 1;
					if (dungeon->checkPos(playerX, playerY) == true) {
						objectGrid->addObjectToDisplay('@', playerX, playerY+ topLinesReserved);
						creature->setPosY(playerY);
						objectGrid->removeObjectToDisplay(playerX, playerY - 1+ topLinesReserved);
						grid->writeLine(2, "Info: You moved down one time.");
					}
					else {
						grid->writeLine(2, "Info: You can not move down.");
					}
				}
			}
			break;
		case 'a':
			for (Creature* creature : dungeon->getCreatures()) {
				if (creature->getName() == "Player") {
					int playerX = creature->getPosX()-1;
					int playerY = creature->getPosY();
					if (dungeon->checkPos(playerX, playerY) == true) {
						objectGrid->addObjectToDisplay('@', playerX, playerY + topLinesReserved);
						creature->SetPosX(playerX);
						objectGrid->removeObjectToDisplay(playerX + 1, playerY + topLinesReserved);
						grid->writeLine(2, "Info: You moved left one time.");
					}
					else {
						grid->writeLine(2, "Info: You can not move left.");
					}
				}
			}
			break;
		case 'd':
			for (Creature* creature : dungeon->getCreatures()) {
				if (creature->getName() == "Player") {
					int playerX = creature->getPosX() + 1;
					int playerY = creature->getPosY();
					if (dungeon->checkPos(playerX, playerY) == true) {
						objectGrid->addObjectToDisplay('@', playerX, playerY + topLinesReserved);
						creature->SetPosX(playerX);
						objectGrid->removeObjectToDisplay(playerX - 1, playerY + topLinesReserved);
						grid->writeLine(2, "Info: You moved right one time.");
					}
					else {
						grid->writeLine(2, "Info: You can not move right.");
					}
				}
			}
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
