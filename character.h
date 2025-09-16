#pragma once
#include <iostream>

using namespace std;

namespace starwars
{
    class Character
    {
        private:
        string _name;
        int _health;
        int _attackPower;
        
        public:
        Character(string = "Unknown", int = 100);
        virtual void takeDamage(int damage) = 0;

        void setName(string);
        void setHealth(int);
        void setAttack(int);

        string getName();
        int getHealth();
        int getAttack();

        int operator+(int);
        int operator-(int);
        friend ostream& operator<<(ostream&, Character&);
        bool operator==(Character&);
        bool operator!=(Character&);
        bool operator<(int);
        bool operator>(int);
    };
}