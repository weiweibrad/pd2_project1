CC = g++
HFILE = Miscellaneous.h   Character.h   GameState.h   GameAI.h
CFILE = Miscellaneous.cpp Character.cpp GameState.cpp GameAI.cpp main.cpp
OUTFILE = main

main: $(HFILE) $(CFILE)
	$(CC) $(CFILE) -o $(OUTFILE) --std=c++11
