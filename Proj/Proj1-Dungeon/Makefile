# suffix rules don't allow pre-requisites to be used and are deprecated for
# this reason.  The right way to do this is to use patterns.  The "%" pattern
# allows any file to be matched.
OBJS = main.o Action.o BlessCurseOwner.o ChangeDisplayedType.o Creature.o CreatureAction.o Displayable.o DropPack.o Dungeon.o EndGame.o Hallucinate.o ItemAction.o ObjectDisplayGrid.o Passage.o Remove.o Room.o Structure.o Teleport.o UpdateDisplay.o YouWin.o Player.o Monster.o Item.o Scroll.o Armor.o Sword.o DungeonXMLHandler.o GridChar.o KeyboardListener.o
CXX = g++
CXXFLAGS = -std=c++11 -g
EXECUTABLE = test

# Check if building on Windows or Linux
ifeq ($(OS),Windows_NT)
	# use PDCurses library archive when building on windows
	CURSES = lib\pdcurses.lib
	CXXFLAGS += -I./include
	# by running rm within cmd, it does not error on missing files
	RM=cmd /c del
	# Windows introduced the tar command that can make zip files
	ZIP=tar -acvf
else
	# use ncurses library when building on linux/mac
	# Linux install using "sudo apt-get install libncurses5-dev libncursesw5-dev"
	# Mac install using "brew install ncurses"
	CURSES=-lncurses
	# Have to include threads on linux
	CXXFLAGS = -std=c++11 -g -pthread
	INCLUDE = -I /usr/local/Cellar/xerces-c/3.2.3/include/
	LIBS = -L /usr/local/Cellar/xerces-c/3.2.3/lib/
	# running -f means it does not error on missing files
	RM=rm -f
	# Linux needs the zip command to do zip files, install using apt-get
	ZIP=zip
endif

.PHONY : run
run : $(EXECUTABLE)
	./$(EXECUTABLE) 


.PHONY : $(EXECUTABLE)
$(EXECUTABLE) :  $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS) $(INCLUDE) $(LIBS) -lxerces-c

%.o : %.c 
	$(CXX) $(CXXFLAGS) -c $@ $(INCLUDE) $(LIBS)

clean:
	$(RM) *.o
	$(RM) $(EXECUTABLE)
	$(RM) $(EXECUTABLE).exe
	$(RM) $(EXECUTABLE).zip

# Clean then build
rebuild: clean $(EXECUTABLE)
.PHONY: rebuild

# Create a zip file with all relevant files to build the project
ZIPFILES=$(SOURCES) $(HEADERS) Makefile lib/* include/* pdcurses.dll \
	PDCursesExample.sln PDCursesExample.vcxproj PDCursesExample.vcxproj.filters
zip: $(ZIPFILES)
	$(ZIP) $(EXECUTABLE).zip $(ZIPFILES)
.PHONY: zip
