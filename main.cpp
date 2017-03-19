#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include "Character.h"
#include "GameState.h"
#include "GameAI.h"
#include "Miscellaneous.h"

using namespace std;

string __AuxiliaryMap[MapHeight];

// store them in vector for convenience
vector<Castle> CastleModel;
vector<Warrior> WarriorModel;
vector<Priest> PriestModel;

vector<Castle> MyCastle, OpsCastle; // Ops = opponent's, [0] is main_castle, [1] is left_castle, [2] is right
vector<Warrior> MyWarrior, OpsWarrior;
vector<Priest> MyPriest, OpsPriest;

GameState CurrentState;

/*
this function is for special initialization rule
*/
void initialize()
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

    // initialize auxiliary map
    ifstream fin("./AuxiliaryMap.data");
    for(int i=0;i<MapHeight;i++)
        getline(fin, __AuxiliaryMap[i]);
    // end initialize auxiliary map
    for(int i=0;i<MapHeight;i++)
        cout << __AuxiliaryMap[i] << endl;
    fin.close();
}

int main()
{
    // initialize
    readCharactersData(CastleModel, WarriorModel, PriestModel);
    initialize();
    // end initialize

    GameState PreviousState;
    CurrentState.readGameState();
    
    // CurrentState.updateState(&PreviousState, MyCastle, OpsCastle, MyWarrior, OpsWarrior, MyPriest, OpsPriest);

    while(1)
    {
        PreviousState = CurrentState;
        CurrentState.readGameState();

    } 
    return 0;
}
