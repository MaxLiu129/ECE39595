#ifndef CREATURE_H_
#define CREATURE_H_


class CreatureAction;
#include <string>
#include "Displayable.hpp"
#include "CreatureAction.hpp"
#include <vector>
#include <queue>

class Creature: public Displayable {
public:
    Creature();
    void setHp(int _h);
    void setHpMoves(int _hpm);
    void setDeathAction(CreatureAction* da);
    CreatureAction* getDeathAction();
    void setHitAction(CreatureAction* ha);
    CreatureAction* getHitAction();
    void setName(std::string _name);
    void setID(int _room, int _serial);
    std::string getName();
    int getCreatureHp();
    int getHpMoves();

    void addDeathAction(CreatureAction* _deathAction);
    void addHitAction(CreatureAction* _hitAction);

    void removeHitAction();
    void removeDeathAction();


    std::queue <CreatureAction*> getDeathQueue();
    std::queue <CreatureAction*> getHitQueue();



private:
    int h;
    int hpm;
    CreatureAction* deathAction;
    CreatureAction* hitAction;
    std::string name;
    int room;
    int serial;
    std::queue <CreatureAction*> death_queue;
    std::queue <CreatureAction*> hit_queue;

};

#endif /* CREATURE_H_ */
