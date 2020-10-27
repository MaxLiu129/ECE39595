#ifndef PASSAGE_H_
#define PASSAGE_H_

#include "Structure.hpp"
#include <string>

class Passage: public Structure {
private:
    std::string passageName;
	int room1;
    int room2;
    

public:
    Passage();
    void setName(std::string _passageName);
    void setID(int _room1, int _room2);
};


#endif /* PASSAGE_H_ */

