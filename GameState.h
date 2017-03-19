#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <iostream>
#include <string>
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

/*
use auxiliary map (i.e. only castle and barrier) , so that we can know whether RawMap[i][j] is available
*/
extern string __AuxiliaryMap[MapHeight];

class GameState
{
public:
    int CountDown;
    int Mana;
    int Card[4];
    GameMap Map;

    /*
    read game map via cin
    */
    void readGameState();
    
    /*
    update characters potition and properties
    */
    void updateState(GameState *PreviousState,
      vector<Castle> &MyCastle, vector<Castle> &OpsCastle, vector<Warrior> &MyWarrior, vector<Warrior> &OpsWarrior,
      vector<Priest> &MyPriest, vector<Priest> &OpsPriest);
};

#endif
