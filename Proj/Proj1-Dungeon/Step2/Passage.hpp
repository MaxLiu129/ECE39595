#ifndef PASSAGE_H_
#define PASSAGE_H_

#include "Structure.hpp"
#include <string>


class Passage: public Structure {
private:
    std::string passageName;
	int room1;
    int room2;
    std::vector<int> passagePosXs;
    std::vector<int> passagePosYs;

public:
    Passage();
    void setName(std::string _passageName);
    void setID(int _room1, int _room2);
    std::vector<int> getPassagePosXs();
    std::vector<int> getPassagePosYs();
    void addPosX(int _posX);
    void addPosY(int _posY);
    bool checkPassagePos(int _x, int _y, int x1, int x2, int y1, int y2);
};


#endif /* PASSAGE_H_ */

