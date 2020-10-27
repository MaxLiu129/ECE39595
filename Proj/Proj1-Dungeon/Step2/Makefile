# suffix rules don't allow pre-requisites to be used and are deprecated for
# this reason.  The right way to do this is to use patterns.  The "%" pattern
# allows any file to be matched.
OBJS = main.o Action.o BlessCurseOwner.o ChangeDisplayedType.o Creature.o CreatureAction.o Displayable.o DropPack.o Dungeon.o EndGame.o Hallucinate.o ItemAction.o ObjectDisplayGrid.o Passage.o Remove.o Room.o Structure.o Teleport.o UpdateDisplay.o YouWin.o Player.o Monster.o Item.o Scroll.o Armor.o Sword.o DungeonXMLHandler.o
CXX = g++ 
INCLUDE = -I /usr/local/Cellar/xerces-c/3.2.3/include/
LIBS = -L /usr/local/Cellar/xerces-c/3.2.3/lib/
CXXFLAGS = -std=c++11 -Wall -g 
EXECUTABLE = test

.PHONY : run
run : $(EXECUTABLE)
	./$(EXECUTABLE) 


.PHONY : $(EXECUTABLE)
$(EXECUTABLE) :  $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS) $(INCLUDE) $(LIBS) -lxerces-c

%.o : %.c 
	$(CXX) $(CXXFLAGS) -c $@ $(INCLUDE) $(LIBS)

clean :
	rm $(EXECUTABLE) ${OBJS} 
