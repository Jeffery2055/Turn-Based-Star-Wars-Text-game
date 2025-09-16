#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "character.h"

using namespace std;

namespace starwars
{
    class Jedi : public Character
    {
        private:
            int _forcePower;
        public:
            Jedi(string = "Unkown Jedi", int = 100, int = 50, int = 75);

            int getSkill();
            int getForce();

            void setSkill(int);
            void setForce(int);

            int attack();
            int useForce(int);
            void takeDamage(int);

            void readToFile();
            void loadFromFile();
    };
    
    class Guardian : public Jedi
    {
        public:
        Guardian(int = 150, int = 70);
    };

    class Consular : public Jedi
    {
        public:
        Consular(int = 100, int = 120);
    };
}