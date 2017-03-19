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

// store them in vector for convenience
vector<Castle> CastleModel;
vector<Warrior> WarriorModel;
vector<Priest> PriestModel;


/*
this function is for special initialization rule
*/
void initialize()
{
}

int main()
{
    // initialize
    readCharactersData();

    // initialize();
    
    // end initialize

    GameState* MyCurrentState = new GameState(), OpsCurrentState;
    GameState* MyPrevState, OpsPrevState;
    MyCurrentState->readGameState();

    while(1)
    {
        delete MyPrevState;
        MyPrevState = MyCurrentState;
        MyCurrentState = new GameState();
        MyCurrentState->readGameState();
        MyCurrentState->updateState(MyPrevState);
    

        // !! remember to add OpsState transfer
    }
    return 0;
}
