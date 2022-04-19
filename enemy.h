#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <cmath>                                       // cmath included to carry out log function
using namespace std;

// Create a struct "Enemy" which will handle all data relevant to enemies who come to kill you.
struct Enemy{
        double health = 40;
        double attack = 3;                             // The damage an enemy does per successful hit
        double defense = 3;                            // Used to determine whether an attack from the user will hit the enemy (can be increase during a fight)
        double evasion = 15;                           // Used to determine whether an attack from the user will hit the enemy

        // Increases the defense stat if the enemy chooses this for their turn
        void Defend(){
            defense += 3;
        }

        // Formula to determine the co-efficient which will determine the likelihood of a user attack hitting the enemy
        // Please check Readme for formulae
        double DefenseQuoficient(){
            double ln = log(defense);
            double term1 = (evasion / 10) + ln;
            double result = evasion + term1;
            return result;
        }
};

#endif
