#include "KeyboardListener.hpp"
// #include "Displayable.hpp"
#include <sstream>
#include <iostream>
#include <stdio.h>
#include "DungeonXMLHandler.hpp"
#include <stdbool.h>
#include <cstdlib>
#include <string>
KeyboardListener::KeyboardListener(ObjectDisplayGrid* _grid) : grid(_grid) {}


void KeyboardListener::set_initial_defence(Dungeon* dungeon) {
	//int count = 0;
	for (Item* item : dungeon->getPackItems()) {
		//count++;
		std::size_t found = item->getName().find("Armor");
		if ((found != std::string::npos)) {
			//add defence val into player.
			//defence_plus = item->getIntValue();
			armor_wearing = false;
			//input_w = count;
		}
	}
}

void KeyboardListener::set_initial_attack(Dungeon* dungeon) {
	//int count = 0;
	for (Item* item : dungeon->getPackItems()) {
		//count++;
		std::size_t found = item->getName().find("Sword");
		if ((found != std::string::npos)) {
			//add defence val into player.
			//attack_plus = item->getIntValue();
			sword_holding = false;
			//input_t = count;
		}
	}
}



//this function will check whether the item on a specific index is valid?
//if yes, return false/
bool check_item_name(std::vector <Item*> items, int input_w, std::string target) {
	std::size_t found;
	Item* item = items[input_w - 1];
	found = (item->getName().find(target));
	//in this case, it finds it
	if (found != std::string::npos) {
		return false;
	}
	return true;
}

void KeyboardListener::remove_hallucinate(Dungeon* dungeon, ObjectDisplayGrid* grid) {
	char c;
	int PlayerX, PlayerY;
	for (Creature* curr_creature : dungeon->getCreatures()) {
		if (curr_creature->getName() == "Player") {
			PlayerX = curr_creature->getPosX();
			PlayerY = curr_creature->getPosY();
		}
	}
	//draw rooms
	for (Room* room : dungeon->getRooms()) {
		for (int i = 0; i < room->Displayable::getWidth(); i++) {
			for (int j = 0; j < room->Displayable::getHeight(); j++) {
				//if (PlayerX != i + room->Displayable::getPosX() || PlayerY != j + room->Displayable::getPosY()){
					grid->removeObjectToDisplay((i + room->Displayable::getPosX()), (j + room->Displayable::getPosY()));
				//}		
            }
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
            if ((passage->getPassagePosXs())[i - 1] == (passage->getPassagePosXs())[i]) {
                //going vertical
                if ((passage->getPassagePosYs())[i - 1] > (passage->getPassagePosYs())[i]) {
                    for (int j = (passage->getPassagePosYs())[i]; j <= posY1; j++) {
                        grid->removeObjectToDisplay((passage->getPassagePosXs())[i - 1], j);
                    }
                }
                else {
                    for (int j = (passage->getPassagePosYs())[i - 1]; j <= (passage->getPassagePosYs())[i]; j++) {
                        grid->removeObjectToDisplay((passage->getPassagePosXs())[i - 1], j);
                    }
                }
            }
            else {
                //going x ------ x
             //determine dir
                if (posX1 > posX2) {
                    for (int j = posX2; j <= posX1; j++) {
                        grid->removeObjectToDisplay(j, posY2);
                    }
                }
                else {
                    for (int j = posX1; j <= posX2; j++) {
                        grid->removeObjectToDisplay(j, posY2);
                    }
                }
            }
        }
        grid->update();
    }

    //display creatures (player, monster, items)
    for (Creature* creature : dungeon->getCreatures()) {
        //creature_name = creature->getPlayerName();
        std::string monsterName = creature->getName();
        if (monsterName == "Troll") { grid->removeObjectToDisplay(creature->getPosX(), creature->getPosY()); }
        else if (monsterName == "Snake") { grid->removeObjectToDisplay(creature->getPosX(), creature->getPosY()); }
        else if (monsterName == "Hobgoblin") { grid->removeObjectToDisplay(creature->getPosX(), creature->getPosY()); }

        grid->update();
    }
    //display items(armor, scroll, sword)
    for (Item* item : dungeon->getItems()) {
        std::string itemName = item->getName();
        if(itemName == "Scroll"){ grid->removeObjectToDisplay(item->getPosX(), item->getPosY()); }
        if (std::string::npos != itemName.find("Armor")) { grid->removeObjectToDisplay( item->getPosX(), item->getPosY()); }
        if (std::string::npos != itemName.find("Sword")) { grid->removeObjectToDisplay( item->getPosX(), item->getPosY()); }
        grid->update();
    }
}

char KeyboardListener::hallucinate_display(Dungeon* dungeon, ObjectDisplayGrid* grid) {
    std::string random_string = "xk*&^%$#!()|}{"; //14
    std::string random_creature = "qweryuiop"; //9
    
	char room_char = random_string[rand() % 14];
    char space_char = random_string[rand() % 14];
    
	char psg_char = random_string[rand() % 14];
    char junction_char = random_string[rand() % 14];
    
	char creature_char = random_creature[rand() % 9];
    
	char item_char = random_string[rand() % 14];
    char c;
	int PlayerX, PlayerY;
	for (Creature* curr_creature : dungeon->getCreatures()) {
		if (curr_creature->getName() == "Player") {
			PlayerX = curr_creature->getPosX();
			PlayerY = curr_creature->getPosY();
		}
	}
    //draw rooms
    for (Room* room : dungeon->getRooms()) {
        for (int i = 0; i < room -> Displayable::getWidth(); i++) {
            for (int j = 0; j < room ->Displayable::getHeight(); j++) {
                if (i == 0 || j == 0 || i + 1 == room ->Displayable::getWidth() || j + 1 == room ->Displayable::getHeight()) {
                    c = room_char;
                }
                else {
					//if (PlayerX != i + room->Displayable::getPosX() || PlayerY != j + room->Displayable::getPosY()) {
						c = space_char;
					//}
                }
                grid->addObjectToDisplay(c, (i + room ->Displayable::getPosX()), (j + room ->Displayable::getPosY()));
            }
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
            if ((passage->getPassagePosXs())[i - 1] == (passage->getPassagePosXs())[i]) {
                //going vertical
                if ((passage->getPassagePosYs())[i - 1] > (passage->getPassagePosYs())[i]) {
                    for (int j = (passage->getPassagePosYs())[i]; j <= posY1; j++) {
                        if ((j == (passage->getPassagePosYs())[i - 1] && i == 1) || (j == (passage->getPassagePosYs())[i] && i == passage->getPassagePosXs().size() - 1)) {
                            c = psg_char;
                        }
                        else {
                            c = junction_char;
                        }
                        grid->addObjectToDisplay(c, (passage->getPassagePosXs())[i - 1], j);
                    }
                }
                else {
                    for (int j = (passage->getPassagePosYs())[i - 1]; j <= (passage->getPassagePosYs())[i]; j++) {
                        if ((j == (passage->getPassagePosYs())[i - 1] && i == 1) || (j == (passage->getPassagePosYs())[i] && i == passage->getPassagePosXs().size() - 1)) {
                            c = psg_char;
                        }
                        else {
                            c = junction_char;
                            
                        }
                        grid->addObjectToDisplay(c, (passage->getPassagePosXs())[i - 1], j);
                    }
                }
            }
            else {
                //going x ------ x
             //determine dir
                if (posX1 > posX2) {
                    for (int j = posX2; j <= posX1; j++) {
                        if ((j == posX1 && i == 1) || (j == posX2 && i == passage->getPassagePosXs().size() - 1)) {
                            c = psg_char;
                        }
                        else {
                            c = junction_char;
                        }
                        grid->addObjectToDisplay(c, j, posY2);
                    }
                }
                else {
                    for (int j = posX1; j <= posX2; j++) {
                        if ((j == posX1 && i == 1) || (j == posX2 && i == passage->getPassagePosXs().size() - 1)) {
                            c = psg_char;
                        }
                        else {
                            c = junction_char;
                        }
                        grid->addObjectToDisplay(c, j, posY2);
                    }
                }
            }
        }
        //grid->addObjectToDisplay(c, (i + passage->Displayable::getPosX()), (j + passage->Displayable::getPosY()));
        // update the grid
        grid->update();
		return room_char;
    }

    //display creatures (player, monster, items)
    for (Creature* creature : dungeon->getCreatures()) {
            //creature_name = creature->getPlayerName();
        std::string monsterName = creature->getName();
        if (monsterName == "Troll") { grid->addObjectToDisplay(creature_char, creature->getPosX(), creature->getPosY()); }
        else if (monsterName == "Snake") { grid->addObjectToDisplay(creature_char, creature->getPosX(), creature->getPosY()); }
        else if (monsterName == "Hobgoblin") { grid->addObjectToDisplay(creature_char, creature->getPosX(), creature->getPosY()); }
        grid->update();
    }
    //display items(armor, scroll, sword)
    for (Item* item : dungeon->getItems()) {
        std::string itemName = item->getName();
        if(itemName == "Scroll"){ grid->addObjectToDisplay(random_string[rand() % 15], item->getPosX(), item->getPosY()); }
        if (std::string::npos != itemName.find("Armor")) { grid->addObjectToDisplay(random_string[rand() % 15], item->getPosX(), item->getPosY()); }
        if (std::string::npos != itemName.find("Sword")) { grid->addObjectToDisplay(random_string[rand() % 15], item->getPosX(), item->getPosY()); }
        grid->update();
    }
}


//this function will check the availibity of input when trying to drop an item from the pack
bool check_index(int input_index, std::vector <Item*> items) {
	int index = 0;
	for (Item* item : items) {
		index++;
	}
	if (index >= input_index) { return false; } // it means the input is inside the index. which is ok
	return true;  // the input is outside the index, which is NOT ok.
}

//this function mainly print pack information everytime the pack is updated.
void KeyboardListener::print_pack(std::vector <Item*> pack_items) {
	std::string msg = "Pack: ";
	for (int i = 0; i < pack_items.size(); i++) {
		std::string itemName = pack_items[i]->getName();
		msg += std::to_string(i + 1) + ": " + itemName + " ";
	}
	grid->writeLine(0, (msg));
	grid->update();
}

bool KeyboardListener::detect_monster(Dungeon* dungeon, char dir) {
	
	int playerX, playerY;
	bool find_monster = false;
	Creature* player = NULL;
	for (Creature* creature : dungeon->getCreatures()) {
		if (creature->getName() == "Player") {
			playerX = creature->getPosX();
			playerY = creature->getPosY();
			player = creature;
		}
	}
	int tempX = 0, tempY = 0;
	switch (dir)
	{
	case 'h':
		tempX = 1;
		tempY = 0;
		break;
	case 'j':
		tempX = 0;
		tempY = -1;
		break;
	case 'k':
		tempX = 0;
		tempY = 1;
		break;
	case 'l':
		tempX = -1;
		tempY = 0;
		break;
	default:
		break;
	}
	Creature* curr_monster = NULL;
	for (Creature* creature : dungeon->getCreatures()) {
		if (creature->getName() != "Player") {
			if (playerX == creature->getPosX() + tempX && playerY == creature->getPosY() + tempY) {
				find_monster = true;
				curr_monster = creature;
			}
		}
	}
	if (!find_monster) {
		return false;
	}
	//start to fight
	int playerHp = player->getCreatureHp(), monsterHp = curr_monster->getCreatureHp();
	int playerMH = player->Displayable::getMaxHit();
	int monsterMH = curr_monster->Displayable::getMaxHit();
	std::string monsterName = curr_monster->getName();
	int playerDmg = rand() % (playerMH + 1);
	int monsterDmg = rand() % (monsterMH + 1);

	//player hits monster first
	int monsterRemain = monsterHp - playerDmg - attack_plus;
	curr_monster->setHp(monsterRemain);
	grid->writeLine(2, "Info: you hit " + std::to_string(playerDmg) + " to monster.");
	while (player->getHitQueue().empty() == false) {
		if (player->getHitQueue().front()->getCreatureActionName() == "DropPack") {
			//test if the item is being worn or held on pos 0
			std::size_t found = dungeon->getPackItems()[0]->getName().find(armor_sign);
			if (found != std::string::npos) {
				//it indicates that on Pos0 it is an armor being worn now.
				//drop the item.
				playerX = player->getPosX();
				playerY = player->getPosY();
				//remove player char on the grid. needs to be added back later.
				grid->removeObjectToDisplay(playerX, playerY);
				std::string itemName = (dungeon->getPackItems()[0])->getName();
				//test the item is an armor or a sword
				//if armor: delete the (a), turn armor_wearing to false.
				armor_wearing = false;
				//get the new name of the armor.
				//set Name back to pack_item
				((dungeon->getPackItems()).at(0))->	setName(((dungeon->getPackItems()[0])->	getName()).substr(0, (((dungeon->getPackItems()[0])->getName()).size() - armor_sign.size() - 1)));
				std::string actionmsg = player->getHitQueue().front()->getMessage();
				//print info:
				grid->writeLine(2, "Info: " + actionmsg);
				//clear the defence plus
				defence_plus = 0;
				// call item remove function
				Item* item_drop = dungeon->item_remove(dungeon->getPackItems(), 0);
				if (item_drop != NULL) {
					std::string itemName = item_drop->getName();
					item_drop->SetPosX(playerX);
					item_drop->setPosY(playerY);
					// print the item on the grid
					grid->addObjectToDisplay(']', playerX, playerY);
				}
				grid->addObjectToDisplay('@', playerX, playerY);
			}
			else{
				found = dungeon->getPackItems()[0]->getName().find(sword_sign);
				if (found != std::string::npos) {
					//it indicates that on Pos0 it is a sword being held now.
					sword_holding = false;
					//drop the item.
					playerX = player->getPosX();
					playerY = player->getPosY();
					//remove player char on the grid. needs to be added back later.
					grid->removeObjectToDisplay(playerX, playerY);
					std::string itemName = (dungeon->getPackItems()[0])->getName();
					//test the item is an armor or a sword
					//if armor: delete the (a), turn armor_wearing to false.
					armor_wearing = false;
					//get the new name of the sword.
					//set Name back to pack_item
					((dungeon->getPackItems()).at(0))->setName(((dungeon->getPackItems()[0])->getName()).substr(0, (((dungeon->getPackItems()[0])->getName()).size() - armor_sign.size() - 1)));
					std::string actionmsg = player->getHitQueue().front()->getMessage();
					//print info:
					grid->writeLine(2, "Info: " + actionmsg);
					//clear the defence plus
					attack_plus = 0;
					// call item remove function
					Item* item_drop = dungeon->item_remove(dungeon->getPackItems(), 0);
					if (item_drop != NULL) {
						std::string itemName = item_drop->getName();
						item_drop->SetPosX(playerX);
						item_drop->setPosY(playerY);
						// print the item on the grid
						grid->addObjectToDisplay(')', playerX, playerY);
					}
					grid->addObjectToDisplay('@', playerX, playerY);
				}
				else {
					//drop the item.
					playerX = player->getPosX();
					playerY = player->getPosY();
					//remove player char on the grid. needs to be added back later.
					grid->removeObjectToDisplay(playerX, playerY);
					std::string actionmsg = player->getHitQueue().front()->getMessage();
					//print info:
					grid->writeLine(2, "Info: " + actionmsg);
					// call item remove function
					Item* item_drop = dungeon->item_remove(dungeon->getPackItems(), 0);
					if (item_drop != NULL) {
						std::string itemName = item_drop->getName();
						item_drop->SetPosX(playerX);
						item_drop->setPosY(playerY);

						// print the item on the grid
						if (std::string::npos != itemName.find("Armor")) {
							//this is armor
							grid->addObjectToDisplay(']', playerX, playerY);
						}
						else if (std::string::npos != itemName.find("Sword")) {
							grid->addObjectToDisplay(')', playerX, playerY);
						}
						else if (std::string::npos != itemName.find("Scroll")) {
							grid->addObjectToDisplay('?', playerX, playerY);
						}
					}
					grid->addObjectToDisplay('@', playerX, playerY);
				}
			}
			

			//change the index of the item being worn or held
			input_w = input_w > 0 ? input_w-- : 0;
			input_t = input_t > 0 ? input_t-- : 0;
			
			player->removeHitAction();
		}
		else if (player->getHitQueue().front()->getCreatureActionName() == "EmptyPack") {
			
			armor_wearing = false;
			sword_holding = false;
			player->removeHitAction();
		}
	}
	
	if (monsterRemain > 0) {
		//if monster is alive, monster hits player
		int playerRemain = playerHp;
		if(monsterDmg > defence_plus){
			playerRemain = playerHp - monsterDmg + defence_plus;
		}
		player->setHp(playerRemain);
		grid->writeLine(3, "Info: monster hits " + std::to_string(monsterDmg)  + " to you.");
		grid->writeTopLine(0, ("HP: " + std::to_string(playerRemain) + "  Score: 0"));

		//monster does not die may excute hit action:
		//std::queue <CreatureAction*> hit_action_queue = curr_monster->getHitQueue();
		while (curr_monster->getHitQueue().empty() == false) {
			if (curr_monster->getHitQueue().front()->getCreatureActionName() == "Teleport") {
				//teleport the craeture to random location
				grid->removeObjectToDisplay(curr_monster->getPosX(), curr_monster->getPosY());
				int new_x = rand() % (dungeon->getDungeonWidth() + 1);
				int new_y = rand() % (dungeon->getDungeonHeight() + 1);

				while (dungeon->checkPos(new_x, new_y) == false) {
					new_x = rand() % (dungeon->getDungeonWidth() + 1);
					new_y = rand() % (dungeon->getDungeonHeight() + 1);
				}
				if (curr_monster->getName() == "Troll") { grid->addObjectToDisplay('T', new_x, new_y); }
				else if (curr_monster->getName() == "Snake") { grid->addObjectToDisplay('S', new_x, new_y); }
				else if (curr_monster->getName() == "Hobgoblin") { grid->addObjectToDisplay('H', new_x, new_y); }
				curr_monster->SetPosX(new_x);
				curr_monster->setPosY(new_y);
				
				curr_monster->removeHitAction();
			}
			
		}
		//std::queue <std::string> temp_actions = 
		if(playerRemain <= 0){
            char player_display;
			//std::queue <CreatureAction*> player_death_queue = player->getDeathQueue();
			while (player->getDeathQueue().empty() == false) {
				if (player->getDeathQueue().front()->getCreatureActionName() == "Remove") {
                    grid->removeObjectToDisplay(player->getPosX(), player->getPosY());
					player->removeDeathAction();
				}
				else if (player->getDeathQueue().front()->getCreatureActionName() == "YouWin") {
					grid->writeLine(3, "Info: " + player->getDeathQueue().front()->getMessage());
					player->removeDeathAction();
				}
                else if (player->getDeathQueue().front()->getCreatureActionName() == "ChangeDisplayedType"){
                    player_display = player->getDeathQueue().front()->getCharValue();
                    player->removeDeathAction();
                }
                else if (player->getDeathQueue().front()->getCreatureActionName() == "UpdateDisplay") {
                    grid->removeObjectToDisplay(player->getPosX(), player->getPosY());
                    grid->addObjectToDisplay(player_display, player->getPosX(), player->getPosY());
                    player->removeDeathAction();

                }
				
                else if (player->getDeathQueue().front()->getCreatureActionName() == "EndGame") {
                    grid->writeLine(3, "Info: " + player->getDeathQueue().front()->getMessage());
                    player->removeDeathAction();
                    alive = false;
                }
			}
			alive = false;
		}
	}
	else {
		//remove the monster
		//show death action of monster.
		//std::queue <CreatureAction*> monster_death_queue = curr_monster->getDeathQueue();

		while (curr_monster->getDeathQueue().empty() == false) {
			if (curr_monster->getDeathQueue().front()->getCreatureActionName() == "Remove") {
				grid->removeObjectToDisplay(playerX - tempX, playerY - tempY);
				curr_monster->SetPosX(-1);
				curr_monster->setPosY(-1);
				dungeon->creature_remove(curr_monster);
				curr_monster->removeDeathAction();
				grid->update();
			}
			else if (curr_monster->getDeathQueue().front()->getCreatureActionName() == "YouWin") {
				grid->writeLine(3, "Info: " + curr_monster->getDeathQueue().front()->getMessage());
				curr_monster->removeDeathAction();
				grid->update();
			}
		}
	}
	return true;
}

void KeyboardListener::run(Dungeon* dungeon, ObjectDisplayGrid* objectGrid) {
	//grid->writeLine(0, "Press 'x' to exit");
	running = true;

    
    
	int playerX = 0;
	int playerY = 0;

	//int have_item = 0;
	char input;
	//for Exit(E) sec input
	char input_E = 0;
	//for H sec input:
	char input_h = 0;
	//temp int val for sec input:(when the input is invalid, it can be stored to below var/)
	int temp_input = 0;
	//for drop(d) sec input
	int input_d = 0;

	char room_char;

	int player_read_X, player_read_Y;
	do {
		// wait for next input
		// lowercase so 'x' and 'X' are treated as the same
		//¡¾watch out: we are using both upper class and lower class now in final step!¡¿
		input = (getchar());

		switch (input) {
			// press e to exit
		case 'E':
			// print another msg for user to indicate if he really needs to exit
			// for now it is not printing [warning]
			grid->writeLine(2, "Info: Exit the game?");
			input_E = std::tolower(getchar());
			switch (input_E) {
			case 'y':
				running = false;
				break;
			default:
				grid->writeLine(2, "Info: Game resume.");
			}
			break;
		case 'i':
			print_pack(dungeon->getPackItems());
			break;
		case '?':
			//show the different commands in the info section of the display. 
			//This is the bottom message display area.
			grid->writeLine(2, "Info: Commands: ¡°h,l,k,j,i,?,H,c,d,p,R,T,w,E,0-9. H <cmd> for more info");
			break;
		case 'H':
			//show each command details.
			grid->writeLine(2, "Info: Please enter a command char.");
			grid->update();
			input_h = (getchar());
			//choose different thing
			if (input_h == '?') {
				grid->writeLine(2, "?: Show the different commands.");
			}
			else if (input_h == 'h') {
				grid->writeLine(2, "h: move left 1 space.");
			}
			else if (input_h == 'l') {
				grid->writeLine(2, "l: move right 1 space. Note that this is a lower case el, l, not an upper case i.");
			}
			else if (input_h == 'k') {
				grid->writeLine(2, "k: move up 1 space.");
			}
			else if (input_h == 'j') {
				grid->writeLine(2, "j: move down 1 space.");
			}
			else if (input_h == 'E') {
				grid->writeLine(2, "E: End game ¡®E¡¯ <Y | y>: end the game.");
			}
			else if (input_h == 'i') {
				grid->writeLine(2, "i: inventory -- show pack contents.");
			}
			else if (input_h == 'c') {
				grid->writeLine(2, "c: take off/change armor.");
			}
			else if (input_h == 'd') {
				grid->writeLine(2, "d: drop <item number> item from pack.");
			}
			else if (input_h == 'r') {
				grid->writeLine(2, "r <item in pack number>: read the scroll which is item number <item in pack number> in pack.");
			}
			else if (input_h == 'p') {
				grid->writeLine(2, "p: pick up item under player and put into the pack.");
			}
			else if (input_h == 't') {
				grid->writeLine(2, "t:Take out a weapon ¡®T¡¯ <integer>: take the sword identified by <integer> from the pack.");
			}
			else if (input_h == 'w') {
				grid->writeLine(2, "w: take out the armor which is item number <item number in pack> in the pack and put it on.");
			}
			else {
				grid->writeLine(2, "Info: invalid command input.");
			}
			input_h = 0;
			break;
		default:
			if (alive) {
				switch (input) {
					// handle wasd to control the player walk around.
					// 1. change PosX and PosY of the player, visibility of the ground and player
					// 2. When player hit the wall of the room, pop error and dont change anything.
					// 3. When player hit the road to another room
					case 'k':
						if (!detect_monster(dungeon, 'k')) {
							for (Creature* creature : dungeon->getCreatures()) {
								if (creature->getName() == "Player") {
									playerX = creature->getPosX();
									playerY = creature->getPosY() - 1;
									if (dungeon->checkPos(playerX, playerY) == true) {
                                        if (hallucinate_count > 0) {
											objectGrid->removeObjectToDisplay(playerX, playerY + 1);
                                            room_char = hallucinate_display(dungeon, grid);
                                            hallucinate_count--;
											grid->addObjectToDisplay(room_char, playerX, playerY + 1);

                                        }
                                        else if (hallucinate_count == 0){
                                            for (int i = 0; i < compare_count + 1; i++) {
                                                remove_hallucinate(dungeon, grid);
												grid->addObjectToDisplay('.', player_read_X, player_read_Y);
                                            }
                                            hallucinate_count = -1;
                                        }
										walkcount++;
										if (walkcount >= creature->getHpMoves()) {
											walkcount = 0;
											creature->setHp(1 + creature->getCreatureHp());
											grid->writeTopLine(0, ("HP: " + std::to_string(creature->getCreatureHp()) + "  Score: 0"));

										}
										objectGrid->addObjectToDisplay('@', playerX, playerY);
										creature->setPosY(playerY);
										objectGrid->removeObjectToDisplay(playerX, playerY + 1 );
										grid->writeLine(2, "Info: You moved up one time.");
									}
									else {
										grid->writeLine(2, "Info: You can not move up.");
									}
								}
							}
						}
						break;
					case 'j':
						if (!detect_monster(dungeon, 'j')) {
							for (Creature* creature : dungeon->getCreatures()) {
								if (creature->getName() == "Player") {
									playerX = creature->getPosX();
									playerY = creature->getPosY() + 1;
									if (dungeon->checkPos(playerX, playerY) == true) {
                                        if (hallucinate_count > 0) {
											objectGrid->removeObjectToDisplay(playerX, playerY - 1);
											room_char = hallucinate_display(dungeon, grid);
                                            hallucinate_count--;
											grid->addObjectToDisplay(room_char, playerX, playerY - 1);
                                        }
                                        else if (hallucinate_count == 0){
                                            for (int i = 0; i < compare_count + 1; i++) {
                                                remove_hallucinate(dungeon, grid);
												grid->addObjectToDisplay('.', player_read_X, player_read_Y);
                                            }
                                            hallucinate_count = -1;
                                        }
										walkcount++;
										if (walkcount >= creature->getHpMoves()) {
											walkcount = 0;
											creature->setHp(1 + creature->getCreatureHp());
											grid->writeTopLine(0, ("HP: " + std::to_string(creature->getCreatureHp()) + "  Score: 0"));

										}
										objectGrid->addObjectToDisplay('@', playerX, playerY);
										creature->setPosY(playerY);
										objectGrid->removeObjectToDisplay(playerX, playerY - 1);
										grid->writeLine(2, "Info: You moved down one time.");
									}
									else {
										grid->writeLine(2, "Info: You can not move down.");
									}
								}
							}
						}
						break;
					case 'h':
						if (!detect_monster(dungeon, 'h')) {

							for (Creature* creature : dungeon->getCreatures()) {
								if (creature->getName() == "Player") {
									playerX = creature->getPosX() - 1;
									playerY = creature->getPosY();
									if (dungeon->checkPos(playerX, playerY) == true) {
                                        if (hallucinate_count > 0) {
											objectGrid->removeObjectToDisplay(playerX + 1, playerY);
											room_char = hallucinate_display(dungeon, grid);
                                            hallucinate_count--;
											grid->addObjectToDisplay(room_char, playerX +1, playerY);
                                        }
                                        else if (hallucinate_count == 0){
                                            for (int i = 0; i < compare_count + 1; i++) {
                                                remove_hallucinate(dungeon, grid);
												grid->addObjectToDisplay('.', player_read_X, player_read_Y);
                                            }
                                            hallucinate_count = -1;
                                        }
										walkcount++;
										if (walkcount >= creature->getHpMoves()) {
											walkcount = 0;
											creature->setHp(1 + creature->getCreatureHp());
											grid->writeTopLine(0, ("HP: " + std::to_string(creature->getCreatureHp()) + "  Score: 0"));

										}
										//
										objectGrid->addObjectToDisplay('@', playerX, playerY);
										creature->SetPosX(playerX);
										objectGrid->removeObjectToDisplay(playerX + 1, playerY);
										grid->writeLine(2, "Info: You moved left one time.");
									}
									else {
										grid->writeLine(2, "Info: You can not move left.");
									}
								}
							}
						}
						break;
					case 'l':
						if (!detect_monster(dungeon, 'l')) {
							for (Creature* creature : dungeon->getCreatures()) {
								if (creature->getName() == "Player") {
									playerX = creature->getPosX() + 1;
									playerY = creature->getPosY();
									if (dungeon->checkPos(playerX, playerY) == true) {
                                        if (hallucinate_count > 0) {
											objectGrid->removeObjectToDisplay(playerX - 1, playerY);
                                            room_char = hallucinate_display(dungeon, grid);
                                            hallucinate_count--;
											grid->addObjectToDisplay(room_char, playerX - 1, playerY);
                                        }
                                        else if (hallucinate_count == 0){
                                            for (int i = 0; i < compare_count + 1; i++) {
                                                remove_hallucinate(dungeon, grid);
												grid->addObjectToDisplay('.', player_read_X, player_read_Y);
                                            }
                                            hallucinate_count = -1;
                                        }
										walkcount++;
										if (walkcount >= creature->getHpMoves()) {
											walkcount = 0;
											creature->setHp(1 + creature->getCreatureHp());
											grid->writeTopLine(0, ("HP: " + std::to_string(creature->getCreatureHp()) + "  Score: 0"));

										}
										objectGrid->addObjectToDisplay('@', playerX, playerY);
										creature->SetPosX(playerX);
										objectGrid->removeObjectToDisplay(playerX - 1, playerY);
										grid->writeLine(2, "Info: You moved right one time.");
									}
									else {
										grid->writeLine(2, "Info: You can not move right.");
									}
								}
							}
						}
						break;
					//read scroll.
					case 'r':
						int PlayerX, PlayerY;
						Creature* player;
						for (Creature* curr_creature : dungeon->getCreatures()) {
							if (curr_creature->getName() == "Player") {
								player = curr_creature;
								PlayerX = curr_creature->getPosX();
								PlayerY = curr_creature->getPosY();
							}
						}
						if ((dungeon->getPackItems()).empty()) {
							grid->writeLine(2, "Info: there is no item in your pack.");
						}
						else {
							grid->writeLine(2, "Info: Please enter the index of the scroll in your pack.");
							grid->update();
							temp_input = (int)(std::tolower(getchar())) - 48;
							//test the validation of the input integer.
							//tip: you have to check if the input is between 0 - 10, or the project would crash.
							while (!while_flag) {
								while_flag = true;
								if (temp_input <= 0 || temp_input >= 10) {
									grid->writeLine(2, "Info: invalid index input.usage: r<integer>. please enter a number.");
									grid->update();
									temp_input = (int)(std::tolower(getchar())) - 48;
									while_flag = false;
								}
								else if (check_index(temp_input, dungeon->getPackItems())) {
									grid->writeLine(2, "Info: invalid index input.usage: r<integer>. please enter another number.");
									grid->update();
									temp_input = (int)(std::tolower(getchar())) - 48;
									while_flag = false;
								}
								//check whether it is a scroll or not.
								else if (check_item_name(dungeon->getPackItems(), temp_input, "Scroll")) {
									grid->writeLine(2, "Info: the index you entered is not a Scroll. please enter another number");
									grid->update();
									temp_input = (int)(std::tolower(getchar())) - 48;
									while_flag = false;
								}
							}
							while_flag = false;
							//after the sec input is valid, store it into the var
							input_r = temp_input;

							//get the Scroll name:
							Item* scroll_to_read = (dungeon->getPackItems())[input_r - 1];
                            ItemAction* perform_action = scroll_to_read->getItemAction();
                            hallucinate_count = perform_action->getIntValue();
                            compare_count = perform_action->getIntValue();
                            if (perform_action->getItemActionName() == "Hallucinate") {
                                int compare_count = perform_action->getIntValue();
                                hallucinate_display(dungeon, grid);
                                grid->writeLine(3, "Info: You are now Hallucinated for " + std::to_string(compare_count)+" steps!");
								grid->removeObjectToDisplay(PlayerX, PlayerY);
								player_read_X = playerX;
								player_read_Y = playerY;
                            }
                            else if (perform_action->getItemActionName() == "BlessArmor") {
                                if (perform_action->getCharValue() == 'a' && armor_wearing == true) {
                                    Item* curr_armor = dungeon->getPackItems()[input_w-1];
									defence_plus += perform_action->getIntValue();
                                }
								else if (perform_action->getCharValue() == 'w' && sword_holding == true) {
									Item* curr_sword = dungeon->getPackItems()[input_t - 1];
									attack_plus += perform_action->getIntValue();
								}
                                else {
                                    grid->writeLine(2, "Info: scroll of cursing does nothing because " + scroll_to_read->getName() + " not being used when the object is not worn or wielded, and" + perform_action->getItemActionName() + std::to_string(perform_action->getIntValue()) + "taken from its effectiveness");
                                }
                            }
							std::string scroll_name = scroll_to_read->getItemAction()->getMessage();
							//print scroll msg
							grid->writeLine(2, "Info: " + scroll_name);
							grid->update();
							//get the object of the scroll(could be armor??)
							//get the updated data of the armor.
							defence_plus += scroll_to_read->getIntValue();
                            

							//remove the scroll from the game.
							Item* scroll_to_remove = dungeon -> item_remove(dungeon->getPackItems(), input_r - 1);
						}
						break;

					//wear armor
					case 'w':
						//test if there is any item in the pack.
						if ((dungeon->getPackItems()).empty()) {
							grid->writeLine(2, "Info: there is no item in your pack.");
						}
						//in this else case, there are items in pack.
						else {
							if (armor_wearing) {
								grid->writeLine(2, "Info: you are wearing an armor, you have to put it back or drop it before wear another one.");
							}
							else {
								//get the second index input from the user.
								temp_input = (int)(std::tolower(getchar())) - 48;
								//test the validation of the input integer.
								//tip: you have to check if the input is between 0 - 10, or the project would crash.
								while (!while_flag) {
									while_flag = true;
									if (temp_input <= 0 || temp_input >= 10) {
										grid->writeLine(2, "Info: invalid index input.usage: w<integer>. please enter a number.");
										grid->update();
										temp_input = (int)(std::tolower(getchar())) - 48;
										while_flag = false;
									}
									else if (check_index(temp_input, dungeon->getPackItems())) {
										grid->writeLine(2, "Info: invalid index input.usage: w<integer>. please enter another number.");
										grid->update();
										temp_input = (int)(std::tolower(getchar())) - 48;
										while_flag = false;
									}
									//check whether it is an armor or not.
									else if (check_item_name(dungeon->getPackItems(), temp_input, "Armor")) {
										grid->writeLine(2, "Info: the index you entered is not an Armor. please enter another number");
										grid->update();
										temp_input = (int)(std::tolower(getchar())) - 48;
										while_flag = false;
									}
								}
								while_flag = false;
								//after the sec input is valid, store it into the var
								input_w = temp_input;

								//get the armor name:
								Item* armor_to_wear = (dungeon->getPackItems())[input_w - 1];
								std::string armor_name = armor_to_wear->getName();
								grid->writeLine(2, "Info: You put on the " + armor_name);
								grid->update();
								//get the defence data of the armor.
								defence_plus = armor_to_wear->getIntValue();
								//add <a> to the inventory info part
								armor_name += " (a)";
								//set the armor name back to the items in the pack.
								(dungeon->getPackItems()).at(input_w - 1)->setName(armor_name);
								armor_wearing = true;
							}
						}
						break;
					//take off armor
					case 'c':
						//check if the player wearing an armor
						find_armor_flag = false;
						for (Item* item : dungeon->getPackItems()) {
							//if yes: delete the (a)
							std::size_t found_index = item->getName().find(armor_sign);
							if (found_index != std::string::npos) {
								//get the new name of the armor.
								//set Name back to pack_item
								(dungeon->getPackItems()).at(input_w - 1)->setName((item->getName()).substr(0, ((item->getName()).size() - armor_sign.size() - 1)));
							
								//print info:
								grid->writeLine(2, "Info: You took off the " + dungeon->getPackItems()[input_w - 1]->getName());
								//clear the defence plus
								defence_plus = 0;
								find_armor_flag = true;
							}
						}
						//if not: show error msg
						if (!find_armor_flag) {
							grid->writeLine(2, "Info: There is no armor being worn.");
						
						}
						find_armor_flag = false;
						armor_wearing = false;
						break;
					//take out weapon
					case 't':
						//test if there is any item in the pack.
						if ((dungeon->getPackItems()).empty()) {
							grid->writeLine(2, "Info: there is no item in your pack.");
						}
						//test if the player already holding a sword.

						//in this else case, there are items in pack.
						else {
							//get the second index input from the user.
							temp_input = (int)(std::tolower(getchar())) - 48;
							//test the validation of the input integer.
							if (sword_holding) {
								grid->writeLine(2, "Info: you are holding a sword, you have to drop it before take out another one.");
							}
							else{
								while (!while_flag) {
									while_flag = true;
									//tip: you have to check if the input is between 0 - 10, or the project would crash.
									if (temp_input <= 0 && temp_input >= 10) {
										grid->writeLine(2, "Info: invalid index input. usage: t<integer>. please enter a number.");
										grid->update();
										temp_input = (int)(std::tolower(getchar())) - 48;
										while_flag = false;
									}
									else if (check_index(temp_input, dungeon->getPackItems())) {
										grid->writeLine(2, "Info: invalid index input. usage: t<integer>. please enter another number.");
										grid->update();
										temp_input = (int)(std::tolower(getchar())) - 48;
										while_flag = false;
									}
									//check whether it is an sword or not.
									else if (check_item_name(dungeon->getPackItems(), temp_input, "Sword")) {
										grid->writeLine(2, "Info: the index you entered is not a Sword. please enter another number");
										grid->update();
										temp_input = (int)(std::tolower(getchar())) - 48;
										while_flag = false;
									}
								}
								while_flag = false;
								//after the sec input is valid, store it into the var
								input_t = temp_input;

								//get the sword name:
								Item* Sword_to_hold = (dungeon->getPackItems())[input_t - 1];
								std::string sword_name = Sword_to_hold->getName();
								grid->writeLine(2, "Info: You put on the " + sword_name);
								grid->update();
								//get the attack data of the sword.
								attack_plus = Sword_to_hold->getIntValue();
								//add <w> to the inventory info part
								sword_name += " (w)";
								//set the sword name back to the items in the pack.
								(dungeon->getPackItems()).at(input_t - 1)->setName(sword_name);
								sword_holding = true;
							}
						}
						break;
					//pick up an item.
					case 'p':
						for (Creature* creature : dungeon->getCreatures()) {
							if (creature->getName() == "Player") {
								playerX = creature->getPosX();
								playerY = creature->getPosY();
								for (Item* item : dungeon->getItems()) {
									//have_item = 0;
									if (item->getPosX() == playerX && item->getPosY() == playerY) {
										//have_item = 1;
										std::string itemName = item->getName();

										objectGrid->removeObjectToDisplay(playerX, playerY);
										objectGrid->removeObjectToDisplay(playerX, playerY);
										objectGrid->addObjectToDisplay('@', playerX, playerY);

										grid->writeLine(2, "Info: adding " + itemName + " to the pack.");
										item->SetPosX(-1);
										item->setPosY(-1);
										dungeon->addItem2Pack(item);
										break;
									}
								}
							}
						}
						break;
					//drop an item.
					case 'd':
						//test if there is any item in the pack.
						if ((dungeon->getPackItems()).empty()) {
							grid->writeLine(2, "Info: there is no item in your pack.");
						}
						//in this else case, there are items in pack.
						else {
							//get the second index input from the user.
							temp_input = (int)(std::tolower(getchar())) - 48;
							//test the validation of the input integer.
							while (check_index(temp_input, dungeon->getPackItems()) && temp_input > 0) {
								grid->writeLine(2, "Info: invalid index input.usage: d<integer>");
								grid->update();
								temp_input = (int)(std::tolower(getchar())) - 48;
							}
							//after the sec input is valid, store it into the var
							input_d = temp_input;
							grid->writeLine(2, "Info: ");
							grid->update();
							//start to remove the item from the pack/
							for (Creature* creature : dungeon->getCreatures()) {
								if (creature->getName() == "Player") {
									playerX = creature->getPosX();
									playerY = creature->getPosY();
									//remove player char on the grid. needs to be added back later.
									objectGrid->removeObjectToDisplay(playerX, playerY);

									std::string itemName = (dungeon->getPackItems()[input_d - 1])->getName();
									//test the item is an armor or a sword
										//if armor: delete the (a), turn armor_wearing to false.
									std::size_t found = itemName.find("Armor");
									if ((found != std::string::npos) && armor_wearing == true) {
										//get the new name of the armor.
										//set Name back to pack_item
										((dungeon->getPackItems()).at(input_w - 1))->\
											setName(((dungeon->getPackItems()[input_d - 1])->\
												getName()).substr(0, (((dungeon->getPackItems()[input_d - 1])->\
													getName()).size() - armor_sign.size() - 1)));

										//print info:
										grid->writeLine(2, "Info: You took off the " + dungeon->getPackItems()[input_w - 1]->getName());
										//clear the defence plus
										defence_plus = 0;
										find_armor_flag = true;
										armor_wearing = false;
									}

									//if sword: delete the (w), turn sword_holding to false.
									found = itemName.find("Sword");
									if ((found != std::string::npos) && sword_holding == true) {
										//get the new name of the sword.
										//set Name back to pack_item
										(dungeon->getPackItems()).at(input_t - 1)->\
											setName(((dungeon->getPackItems()[input_d - 1])->\
												getName()).substr(0, (((dungeon->getPackItems()[input_d - 1])->\
													getName()).size() - sword_sign.size() - 1)));

										//print info:
										grid->writeLine(2, "Info: You took off the " + dungeon->getPackItems()[input_t - 1]->getName());
										//clear the defence plus
										defence_plus = 0;
										find_armor_flag = true;
										sword_holding = false;
									}

									// call item remove function
									Item* item_drop = dungeon->item_remove(dungeon->getPackItems(), input_d - 1);
									if (item_drop != NULL) {
										std::string itemName = item_drop->getName();
										item_drop->SetPosX(playerX);
										item_drop->setPosY(playerY);

										// print the item on the grid
										if (std::string::npos != itemName.find("Armor")) {
											//this is armor
											objectGrid->addObjectToDisplay(']', playerX, playerY);
										}
										else if (std::string::npos != itemName.find("Sword")) {
											objectGrid->addObjectToDisplay(')', playerX, playerY);
										}
										else if (itemName == "Scroll") {
											objectGrid->addObjectToDisplay('?', playerX, playerY);
										}
									}
									objectGrid->addObjectToDisplay('@', playerX, playerY);
								}
							}
						}
						break;
					default:
						std::string message = "Unknown key '";
						message += input;
						grid->writeLine(2, message + "'");
						break;
				}
			}
			else {
				// C is not happy about appending a character to a string apparently
				std::string message = "Unknown key '";
				message += input;
				grid->writeLine(2, message + "'");
			}
		}
		//show inventory contents? (which is pack items???)
		grid->update();
	} while (running && input != EOF);
}
