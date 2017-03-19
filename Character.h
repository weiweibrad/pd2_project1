#ifndef __CHARACTERS_H__
#define __CHARACTERS_H__

#include <fstream>
#include <vector>
#include <string>
#include "Miscellaneous.h"

using namespace std;

class CharacterBasis
{
public:
    string Name;
    int ID;
    int Cost;
    int Speed;
    int Attack;
    int Range;
    int HP;
    Point Position;
    int OrderID; // for distinguishing same ID's character, e.g. 2 sgrams, first's OrderID=1, second's = 2
    CharacterBasis(string _Name, int _ID, int _Cost, int _Speed, int _Attack, int _Range, int _HP)
    {
        Name = _Name;
        ID = _ID;
        Cost = _Cost;
        Speed = _Speed;
        Attack = _Attack;
        Range = _Range;
        HP = _HP;
    }
    ~CharacterBasis()
    {
    }

    void attackEnemy(CharacterBasis* enemy);

    void die();
};



class Castle : public CharacterBasis
{
public:
    Castle(string _Name, int _ID, int _Cost, int _Speed, int _Attack, int _Range, int _HP) : CharacterBasis(_Name, _ID, _Cost, _Speed, _Attack, _Range, _HP)
    {
    }
    ~Castle()
    {
    }

    Point Corner[2];
};



class Warrior : public CharacterBasis
{
public:
    Warrior(string _Name, int _ID, int _Cost, int _Speed, int _Attack, int _Range, int _HP) : CharacterBasis(_Name, _ID, _Cost, _Speed, _Attack, _Range, _HP)
    {
    }
    ~Warrior()
    {
    }
};



class Priest : public CharacterBasis
{
public:
    Priest(string _Name, int _ID, int _Cost, int _Speed, int _Attack, int _Range, int _HP) : CharacterBasis(_Name, _ID, _Cost, _Speed, _Attack, _Range, _HP)
    {
    }
    ~Priest()
    {
    }

    void headTeammate(CharacterBasis* healee);
};



/*
store character data in a file for flexibility
5 copies of the same code, only change target object
*/
void readCharactersData(vector<Castle> &CastleModel, vector<Warrior> &WarriorModel, vector<Priest> &PriestModel);

#endif
