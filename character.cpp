#include "character.h"

starwars::Character::Character(string name, int health)
{
    _name = name;
    _health = health;
}

void starwars::Character::setName(string name)
{
    _name = name;
}

void starwars::Character::setHealth(int health)
{
    _health = health;
}

void starwars::Character::setAttack(int attack)
{
    _attackPower = attack;
}

string starwars::Character::getName()
{
    return _name;
}

int starwars::Character::getHealth()
{
    return _health;
}

int starwars::Character::getAttack()
{
    return _attackPower;
}

int starwars::Character::operator+(int incHealth)
{
    _health = this->_health + incHealth;
    return _health;
}

int starwars::Character::operator-(int decHealth)
{
    _health = this->_health - decHealth;
    return _health;
}

ostream& starwars::operator<<(ostream& os, Character& character)
{
    os << character.getName() << " HP: " << character.getHealth() << " ATK: " << character.getAttack();
    return os;
}

bool starwars::Character::operator==(Character& sith)
{
    if(this->getHealth() == sith.getHealth()) return true;
    return false;
}

bool starwars::Character::operator!=(Character& sith)
{
    return !(*this == sith);
}

bool starwars::Character::operator<(int isDead)
{
    if(this->getHealth() < isDead) return true;
    return false;
}

bool starwars::Character::operator>(int isAlive)
{
    if(this->getHealth() > isAlive) return true;
    return false;
}