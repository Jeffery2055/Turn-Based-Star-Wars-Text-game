#include "jedi.h"

starwars::Jedi::Jedi(string name, int health, int lightsaberSkill, int forcePower)
{
    setName(name);
    setHealth(health);
    setAttack(lightsaberSkill);
    _forcePower = forcePower;
}

int starwars::Jedi::getSkill()
{
    return getAttack();
}

int starwars::Jedi::getForce()
{
    return _forcePower;
}

void starwars::Jedi::setSkill(int lightsaberSkill)
{
    setAttack(lightsaberSkill);
}

void starwars::Jedi::setForce(int forcePower)
{
    _forcePower = forcePower;
}

int starwars::Jedi::attack()
{
    return getAttack();
}

int starwars::Jedi::useForce(int power)
{
    _forcePower -= power;
    return _forcePower;
}

void starwars::Jedi::takeDamage(int damage)
{
    int health = getHealth();

    setHealth(health -= damage);
}

starwars::Guardian::Guardian(int health, int skill)
{
    setHealth(health);
    setSkill(skill);
}

starwars::Consular::Consular(int health, int force)
{
    setHealth(health);
    setForce(force);
}

void starwars::Jedi::readToFile()
{
    ofstream fout;
    fout.open("jedi.txt");

    fout << getName()  << ", " << getHealth() << ", " << getAttack() << ", " << _forcePower << endl;

    fout.close();
}

void starwars::Jedi::loadFromFile()
{
    ifstream fin;
    istringstream iss;
    string token;
    string inLine;
    int tokenCounter = 0;
    fin.open("jedi.txt");

    iss.str(inLine);
    while(getline(iss, token, ','))
    {
        tokenCounter++;
        if(tokenCounter == 1)
        {
            setName(token);
        }
        else if(tokenCounter == 2)
        {
            setHealth(stoi(token));
        }
        else if(tokenCounter == 3)
        {
            setAttack(stoi(token));
        }
        else if(tokenCounter == 4)
        {
            _forcePower = stoi(token);
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }

    fin.close();
}