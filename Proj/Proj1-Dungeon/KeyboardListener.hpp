#pragma once
#include "ObjectDisplayGrid.hpp"
#include "Dungeon.hpp"

class KeyboardListener {
private:
    /** Object display grid reference to write errors */
    ObjectDisplayGrid* grid;

    /** set to false to stop running the keyboard listener */
    bool running = false;
    //private because only use in cpp
    bool detect_monster(Dungeon* dungeon, char dir);

    // set to false if player dies
    bool alive = true;

    //for holding sword and wearing armor
    int defence_plus;
    int attack_plus;

    std::string armor_sign = "(a)";
    std::string sword_sign = "(w)";
    bool find_armor_flag = false;
    bool find_sword_flag = false;

    //indicate that the player is holding or wearing a sword or an armor.
    bool sword_holding = false;
    bool armor_wearing = false;
    
    bool while_flag = false;
    
    int hallucinate_count = -1;
    int compare_count = -1;

    //for wear(w) sec input/
    int input_w = 0;
    //for take out(t) sec input.
    int input_t = 0;
    //for read(r) scroll sec input.
    int input_r = 0;

public:
    /**
     * Creates a new keyboard listener, you can pass in extra objects here to interact with them during the game if you wish
     * @param grid  Object display grid reference
     */
    KeyboardListener(ObjectDisplayGrid* grid);
    int walkcount = 0;
    /**
     * Runs the keyboard listener in a thread
     */
    void run(Dungeon* dungeon, ObjectDisplayGrid* objectGrid);
    void print_pack(std::vector <Item*> items);
    //Hallucinate
    char hallucinate_display(Dungeon* dungeon, ObjectDisplayGrid* grid);
    void remove_hallucinate(Dungeon* dungeon, ObjectDisplayGrid* grid);

    void set_initial_defence(Dungeon* dungeon);
    void set_initial_attack(Dungeon* dungeon);
};

