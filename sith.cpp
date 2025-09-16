#include "sith.h"

starwars::Sith::Sith(string name, int health, int lightsaberSkill)
{
    setName(name);
    setHealth(health);
    setAttack(lightsaberSkill);
}

int starwars::Sith::getSkill()
{
    return getAttack();
}

void starwars::Sith::setSkill(int lightsaberSkill)
{
    setAttack(lightsaberSkill);
}

int starwars::Sith::attack()
{
    return getAttack();
}

void starwars::Sith::takeDamage(int damage)
{
    int health = getHealth();

    setHealth(health -= damage);
}

starwars::Acolyte::Acolyte(int health, int attack)
{
    setHealth(health);
    setAttack(attack);
}

starwars::Darth::Darth(int health, int attack)
{
    setHealth(health);
    setAttack(attack);
}