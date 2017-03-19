#include "GameState.h"

/*
read game map via cin
*/
void GameState::readGameState()
{
    cin >> CountDown >> Mana >> Card[0] >> Card[1] >> Card[2] >> Card[3];
     
    getline(cin, Map.RawMap[0][0]); // get \n of last input

    for(int t=0;t<2;t++)
        for(int i=0;i<MapHeight;i++)
            getline(cin, Map.RawMap[t][i]);
}

/*
update characters potition and properties
*/
void GameState::updateState(GameState *PreviousState)
{
    for(int i=1;i<21;i++) // 21 = MapHeight - 1
    {
        for(int j=1;j<51;j++) // 51 = MapWidth - 1
        {
            if(Map.RawMap[0][i][j] == ' ' || Map.RawMap[0][i][j] == '#') // if not accessible
                continue;
            
            // character found , ...
        }
    }
}
