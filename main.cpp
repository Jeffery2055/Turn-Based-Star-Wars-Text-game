#include <iostream>
#include "jedi.h"
#include "sith.h"

using namespace std;

int generateSith();
void game(starwars::Jedi, starwars::Sith);

int main(int argc, char* argv[])
{
    string jeditype;
    string name;
    int sithtype;

    cout << "Enter your Jedi's name: " << endl;
    getline(cin, name);

    cout << "Enter your jedi type, Guardian or Consular: " << endl;
    cin >> jeditype;

    if(jeditype == "Guardian" || jeditype == "guardian")
    {
        starwars::Guardian jedi1;
        
        jedi1.setName(name);

        jedi1.readToFile();

        jedi1.loadFromFile();

        sithtype = generateSith();
        if(sithtype == 1)
        {
            starwars::Acolyte sith1;
            cout << "\nJedi " << jedi1.getName() << " is confronted by a Sith Acolyte!" << endl;
            cout << "The Sith draws his lightsaber, what do you do? \n" << endl;
            game(jedi1, sith1);
        }
        else
        {
            starwars::Darth sith2;
            cout << "\nJedi " << jedi1.getName() << " is confronted by a Sith Lord!" << endl;
            cout << "The Sith draws his lightsaber, what do you do? \n" << endl;
            game(jedi1, sith2);
        }
    }
    else if(jeditype == "Consular" || jeditype == "consular")
    {

        starwars::Consular jedi2;

        jedi2.setName(name);

        jedi2.readToFile();
        jedi2.loadFromFile();

        sithtype = generateSith();
        if(sithtype == 0)
        {
            starwars::Acolyte sith1;
            cout << "\nJedi " << jedi2.getName() << " is confronted by a Sith Acolyte!" << endl;
            cout << "The Sith draws his lightsaber, what do you do? \n" << endl;
            game(jedi2, sith1);
        }
        else
        {
            starwars::Darth sith2;
            cout << "\nJedi " << jedi2.getName() << " is confronted by a Sith Lord!" << endl;
            cout << "The Sith draws his lightsaber, what do you do? \n" << endl;
            game(jedi2, sith2);
        }
    }

    // cout << jedi1.getName() << " " << jedi1.getHealth() << " " << jedi1.getSkill() << " " << jedi1.getForce() << endl;
    // cout << sith1.getName() << " " << sith1.getHealth() << " " << sith1.getSkill() << endl;

    return 0;
}

int generateSith()
{
    int randomNum;
    srand(time(0));

    randomNum = rand() % 2;
    // cout << "DEBUG: randomNum: " << randomNum << endl;
    return randomNum;
}

void game(starwars::Jedi jedi1, starwars::Sith sith1)
{
    char playerChoice;
    // char restart = 'Y';

    // while(restart == 'Y' || restart == 'y')
    // }
        while(jedi1 > 0 && sith1 > 0)
        {
            cout << jedi1;
            cout << " Force: " << jedi1.getForce() << endl;
            cout << sith1 << endl;
            cout << "Strike with lightsaber: L, Force Push: F" << endl;
            cin >> playerChoice;

            if(playerChoice == 'L' || playerChoice == 'l')
            {
                cout << "You strike with your lightsaber!\n" << endl;
                sith1 - jedi1.getAttack();
            }
            else if(playerChoice == 'F' || playerChoice == 'f')
            {
                cout << "You attack with a Force Push!\n" << endl;
                jedi1.useForce(25);
                sith1 - (jedi1.getAttack() + 10);
            }
            else
            {
                cout << "Invalid selection." << endl;
                continue;
            }
            if(sith1 > 0)
            {
                cout << "The Sith counterattacks with their lightsaber!\n" << endl;
                jedi1 - sith1.getAttack();
            }
        }

        if(jedi1.getHealth() <= 0)
        {
            cout << "Unfortunately the Sith acheived victory this day." << endl;
            // cout << "Would you like to try again? [Y/N]" << endl;
            // cin >> restart;
        }
        else if(sith1.getHealth() <= 0)
        {
            cout << "You bested the Sith! Excellent job." << endl;
            // cout << "Would you like to play again? [Y/N]" << endl;
            // cin >> restart;
        }
    // }
}