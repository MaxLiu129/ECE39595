#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

#include <string>


class Displayable{

public:
    Displayable();
    void setInvisible();
    void setVisible( );
    void setMaxHit(int _maxHit);
    void setHpMove(int _hpMoves);
    void setHp(int _Hp);
    void setType(char _t);
    void setIntValue(int _v);
    void SetPosX(int _posx);
    void setPosY(int _posy);
    void SetWidth(int _widx);
    void setHeight(int _heiy);

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
};

#endif /* DISPLAYABLE_H_ */
