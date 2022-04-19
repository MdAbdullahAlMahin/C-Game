#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>                                    // Included to carry out log function
using namespace std;

// Create a struct to handle all players stats
struct MyPlayer{
        double health = 100;
        double attack = 5;                         // Base attack of player - the damage the player does to enemy on a successful hit
        double defense = 5;                        // Parameter to determine the likelihood of a hit landing on the player (can be increase during a fight)
        double evasion = 20;                       // Parameter to determine the likelihood of a hit landing on the player
        int AttackMultiplier = 0;                  // A parameter to record how many attack treasures received
        int DefenseMultiplier = 0;                 // A parameter to record how many defense treasures received
        int EvasionMultiplier = 0;                 // A parameter to record how many evasion treasures received

        // Increase the number of attack treasures received by 1
        void cinAttack(){
            AttackMultiplier += 1;
        }

        // Increase the number of defense treasures received by 1
        void cinDefense(){
            DefenseMultiplier += 1;
        }

        // Increase the number of evasion treasures received by 1
        void cinEvasion(){
            EvasionMultiplier += 1;
        }

        //////////////////////////////////////////////////
        // Contains the formula for boosting attack, defense, and evasion, based on the treasure received
        // Please check Readme for formulae
        double Multiplier(char x){
            double ans;
            switch(x){
                case 'a' : {
                    double m = 0.8;
                    double c = 5;
                    ans = (m * AttackMultiplier) + c;
                    break;
                }
                case 'd' : {
                    double m = 0.8;
                    double c = 5;
                    ans = (m * DefenseMultiplier) + c;
                    break;
                }
                case 'e' : {
                    double m = 1.8;
                    double c = 20;
                    ans = (m * EvasionMultiplier) + c;
                    break;
                }
            }
            return ans;
        }
        ////////////////////////////////////////////////

        // Increase health if health treasure is received
        void HealUp(){
            cout << "You gain 10 Health." << endl;
            health += 10;
        }

        // Boost attack if an attack treasure is received
        void AttackBoost(){
            cout << "You got a weapon, boosting your attack." << endl;
            attack = Multiplier('a');                                   // Carries out the formula and returns the new attack
        }

        // Boost defense if a defense treasure is received
        void DefenseBoost(){
            cout << "You found armor, boosting your defense." << endl;
            defense = Multiplier('d');                                  // Carries out the formula and returns the new defense
        }

        // Boost evasion if an evasion treasure is received
        void EvasionBoost(){
            cout << "You found nice shoes, Damn Daniel! It boosted your evasion." << endl;
            evasion = Multiplier('e');                                  // Carries out the formula and returns the new evasion
        }

        // Formula to determine the co-efficient which will determine the likelihood of an enemy attack hitting the user
        // Please check Readme for formulae
        double DefenseQuoficient(){
            double ln = log(defense);
            double term1 = (evasion / 8) + ln;
            double result = evasion + term1;
            return result;
        }

};

#endif
