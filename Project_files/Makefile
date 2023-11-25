########################################################################
####################### Makefile Template ##############################
########################################################################
# all: compile link

# compile:
# 	g++ -c main.cpp -I"D:\Studia\Projekt c++\SFML\SFML-2.6.1\include"

# link:
# 	g++ main.o -o game -L"D:\Studia\Projekt c++\SFML\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system

# main.cpp:
#  	g++ -c main.cpp -I"D:\Studia\Projekt c++\SFML\SFML-2.6.1\include"


# Trying to do STATIC
# g++ -c main.cpp -I"D:\Studia\Projekt c++\SFML\SFML-2.6.1\include" -DSFML_STATIC
# g++ main.o -o game -L"D:\Studia\Projekt c++\SFML\SFML-2.6.1\lib" 
# -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows
# Combined (working in cmd):
# g++ -c main.cpp -I"D:\Studia\Projekt c++\SFML\SFML-2.6.1\include" -DSFML_STATIC -o game 
# -L"D:\Studia\Projekt c++\SFML\SFML-2.6.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

# Compiler settings - Can be customized.

# !!! write your SFML/include path below:
SFMLincl_dir="D:\Studia\Projekt c++\SFML\SFML-2.6.1\include"
# !!! write your SFML/lib path below:
SFMLlib_dir="D:\Studia\Projekt c++\SFML\SFML-2.6.1\lib"

CC = g++
CXXFLAGS = -std=c++11 -Wall -g -I$(SFMLincl_dir) -DSFML_STATIC
LDFLAGS = -L$(SFMLlib_dir) -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows


# Makefile settings - Can be customized.
APPNAME = Game
EXT = .cpp
SRCDIR = ../Project_files
OBJDIR = ../Project_files

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME)

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)