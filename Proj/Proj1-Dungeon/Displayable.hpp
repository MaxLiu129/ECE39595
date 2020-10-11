#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

#include <string>

class displayable{
    private:
        int maxHit;
        int hpMoves;
        int Hp;
        char t;
        int v;
        int PosX;
        int PosY;
        int WidthX;
        int HeightY;

    public:
        void displayable::Displayable();
        void displayable::setInvisible();
        void displayable::setVisible( );
        void displayable::setMaxHit(int _maxHit);
        void displayable::setHpMove(int _hpMoves);
        void displayable::setHp(int _Hp);
        void displayable::setType(char _t);
        void displayable::setIntValue(int _v);
        void displayable::SetPosX(int x);
        void displayable::setPosY(int y);
        void displayable::SetWidth(int x);
        void displayable::setHeight(int y);
}

#endif /* DISPLAYABLE_H_ */