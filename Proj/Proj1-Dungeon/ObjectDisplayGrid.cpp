//
//  ObjectDisplayGrid.cpp
//  The dungeon
//
//  Created by zihan liu on 10/10/20.
//  Copyright © 2020 zihan liu. All rights reserved.
//

#include "ObjectDisplayGrid.hpp"
//#include <xercesc/sax2/SAX2XMLReader.hpp>
//#include <xercesc/sax2/XMLReaderFactory.hpp>
//#include <xercesc/sax2/DefaultHandler.hpp>
//#include <xercesc/util/XMLString.hpp>
//#include <xercesc/sax2/Attributes.hpp>
//#include <xercesc/util/XMLUni.hpp>
//#include <xercesc/util/PlatformUtils.hpp>
#include <stdio.h>
#include <iostream>

void ObjectDisplayGrid::getObjectDisplayGrid(int _gameHeight, int _width, int _topHeight) {
    gameHeight = _gameHeight;
    width = _width;
    topHeight = _topHeight;
    std::cout << "Object Display Grid get";
}

void ObjectDisplayGrid::setTopMessageHeight(int _topHeight) {
    topHeight = _topHeight;
    std::cout << "Top message height set";
}

void ObjectDisplayGrid::setBotHeight(int _bottomHeight) {
    bottomHeight = _bottomHeight;
    std::cout << "Bottom Height set";
}
