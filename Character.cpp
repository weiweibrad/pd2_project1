#include "Character.h"

void CharacterBasis::attackEnemy(CharacterBasis* enemy)
{
    enemy->HP -= Attack;
    if(enemy->HP <= 0)
    {
        enemy->die();
    }
}

void Priest::headTeammate(CharacterBasis* healee)
{
    healee->HP += Attack;
}

void CharacterBasis::die()
{
    // !! whether remove from map?
    delete this;
}

/*
store character data in a file for flexibility
5 copies of the same code, only change target object
*/
void readCharactersData(vector<Castle> &CastleModel, vector<Warrior> &WarriorModel, vector<Priest> &PriestModel)
{
    ifstream fin("./Characters.data");
    string name, str;
    int id, cost, speed, attack, range, hp;
    while(fin >> name && name != "#")
    {
        fin >> id;
        fin >> str >> cost;
        fin >> str >> speed;
        fin >> str >> attack;
        fin >> str >> range;
        fin >> str >> hp;
        CastleModel.push_back((Castle){name, id, cost, speed, attack, range, hp});
    }
    while(fin >> name && name != "#")
    {
        fin >> id;
        fin >> str >> cost;
        fin >> str >> speed;
        fin >> str >> attack;
        fin >> str >> range;
        fin >> str >> hp;
        WarriorModel.push_back((Warrior){name, id, cost, speed, attack, range, hp});
    }
    while(fin >> name && name != "#")
    {
        fin >> id;
        fin >> str >> cost;
        fin >> str >> speed;
        fin >> str >> attack;
        fin >> str >> range;
        fin >> str >> hp;
        PriestModel.push_back((Priest){name, id, cost, speed, attack, range, hp});
    }
    fin.close();
}
