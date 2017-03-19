#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Character.h"

#define MapHeight 22
#define MapWidth 52

using namespace std;

class GameMap
{
public:
    string RawMap[2][MapHeight];

    GameMap()
    {
    }

};

class GameState
{
public:
    int CountDown;
    int Mana;
    int Card[4];
    GameMap Map;
    vector<Castle> MyCastle, OpsCastle;  // Ops = opponent's, [0] is main_castle, [1] is left_castle, [2] is right
    list<Warrior> MyWarrior, OpsWarrior;
    list<Priest> MyPriest, OpsPriest;

    /*
    read game map via cin
    */
    void readGameState();
    
    /*
    update characters potition and properties
    */
    void updateState(GameState *PreviousState);

    GameState()
    {
    	// initialize Castles
	    MyCastle.push_back(CastleModel[0]);
	    MyCastle.push_back(CastleModel[1]);
	    MyCastle.push_back(CastleModel[1]);
	    OpsCastle.push_back(CastleModel[0]);
	    OpsCastle.push_back(CastleModel[1]);
	    OpsCastle.push_back(CastleModel[1]);

	    MyCastle[0].Corner[0].X = 8;
	    MyCastle[0].Corner[0].Y = 3;
	    MyCastle[0].Corner[1].X = 13;
	    MyCastle[0].Corner[1].Y = 8;
	    
	    MyCastle[1].Corner[0].X = 3;
	    MyCastle[1].Corner[0].Y = 7;
	    MyCastle[1].Corner[1].X = 6;
	    MyCastle[1].Corner[1].Y = 10;
	    
	    MyCastle[2].Corner[0].X = 15;
	    MyCastle[2].Corner[0].Y = 7;
	    MyCastle[2].Corner[1].X = 18;
	    MyCastle[2].Corner[1].Y = 10;
	    
	    OpsCastle[0].Corner[0].X = 8;
	    OpsCastle[0].Corner[0].Y = 43;
	    OpsCastle[0].Corner[1].X = 13;
	    OpsCastle[0].Corner[1].Y = 48;
	    
	    // left castle, from opponent's sight
	    OpsCastle[1].Corner[0].X = 15;
	    OpsCastle[1].Corner[0].Y = 41;
	    OpsCastle[1].Corner[1].X = 18;
	    OpsCastle[1].Corner[1].Y = 44;
	    
	    OpsCastle[2].Corner[0].X = 3;
	    OpsCastle[2].Corner[0].Y = 41;
	    OpsCastle[2].Corner[1].X = 6;
	    OpsCastle[2].Corner[1].Y = 44;
	    // end initialize castle
    }
};

#endif
