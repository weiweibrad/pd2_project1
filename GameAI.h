#ifndef __GAMEAI_H__
#define __GAMEAI_H__

#include "Character.h"
#include "GameState.h"
#include "Miscellaneous.h"

/*
alpha-beta pruning
*/
int abPruning(GameState *MyState, GameState *OpsState, int CountDown, int alpha, int beta);

#endif
