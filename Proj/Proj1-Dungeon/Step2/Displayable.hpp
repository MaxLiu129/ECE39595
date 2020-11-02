#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

#include <string>
#include <vector>

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
    virtual void SetPosX(int _posx);
    virtual void setPosY(int _posy);
    void SetWidth(int _widx);
    void setHeight(int _heiy);

    int getPosX();
    int getPosY();
    int getWidth();
    int getHeight();

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
