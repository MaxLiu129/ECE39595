//
//  ObjectDisplayGrid.hpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#ifndef ObjectDisplayGrid_hpp
#define ObjectDisplayGrid_hpp

#include <stdio.h>
//#include <xercesc/sax2/SAX2XMLReader.hpp>
//#include <xercesc/sax2/XMLReaderFactory.hpp>
//#include <xercesc/sax2/DefaultHandler.hpp>
//#include <xercesc/util/XMLString.hpp>
//#include <xercesc/sax2/Attributes.hpp>
//#include <xercesc/util/XMLUni.hpp>
//#include <xercesc/util/PlatformUtils.hpp>
#include <stdio.h>

class ObjectDisplayGrid {
public:
    void getObjectDisplayGrid(int _gameHeight, int _width, int _topHeight);
    
    void setTopMessageHeight(int _topHeight);
    
    void setBotHeight(int _bottomHeight);
private:
    int gameHeight;
    int width;
    int topHeight;
    int bottomHeight;
        
};

#endif /* ObjectDisplayGrid_hpp */
