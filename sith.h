#pragma once
#include <iostream>
#include "character.h"

using namespace std;

namespace starwars
{
    class Sith : public Character
    {
        public:
            Sith(string = "Unknown Sith", int = 120, int = 60);

            int getSkill();

            void setSkill(int);

            int attack();
            void takeDamage(int);
    };

    class Acolyte : public Sith
    {
        public:
        Acolyte(int = 80, int = 40);
    };

    class Darth : public Sith
    {
        public:
        Darth(int = 200, int = 100);
    };
}