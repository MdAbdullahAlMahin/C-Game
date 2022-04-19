#ifndef FIGHT_H
#define FIGHT_H

#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include "player.h"                 // Included so that programs recognize MyPlayer data type so that stats can be stored
#include "enemy.h"                  // Included so that programs recognize Enemy data type so that stats can be stored

using namespace std;

// Goes over a fight between an enemy and player p
int fight(MyPlayer &p, bool boss){              // For the final floor, it is a boss fight, the boss parameter is used to tell the program it is a boss fight
    Enemy enemy;
    if (boss == true){                                  // Bosses have better stats
        enemy.health += 35;
        enemy.attack += 2;
        enemy.defense += 2;
    }
    double return_defense = p.defense;          // In case the player boosts hid defense,
                                                // this variable is used to store the original one
                                                // so that it can be returned to that value at the end of the program
    cout << "A cult member stops you in your tracks! You begin a fight." << endl;
    int counter = 0;
    int check, player_cmd;
    while (p.health > 0 && enemy.health > 0){   // While loop until player or enemy dies
        cout << endl;
        cout << "Enemy Health : " << fixed << setprecision(2) << enemy.health << endl;
        cout << "Player Health : " << fixed << setprecision(2) << p.health << endl << endl;
        srand(time(NULL));
        check = rand() % 101 + 1;
        if (counter % 2 == 0){                  // For differentiating player and enemy turns
            cout << "Players turn, Please make a choice:"<<endl;
            cout << "1 : Attack" << endl << "2 : Defend" << endl << "3 : Try to Escape" << endl;
            cout << "Input : ";
            cin >> player_cmd;
            while (player_cmd != 1 && player_cmd != 2 && player_cmd != 3){   // Take input until player gives an acceptable input
                cout << "Wrong input, please enter an integer between 1 and 3." << endl;
                cout << "Input : ";
                cin >> player_cmd;
            }
            switch (player_cmd){
                case (1) :{
                    double enemy_dq = enemy.DefenseQuoficient();    // Find out the parameter determining likelihood of hit for miss
                    if (check > enemy_dq){                          // If random generated number between 0 to 100 is greater than parameter it is a hit
                        enemy.health -= p.attack;
                        cout << "Attack hits and you do " << setprecision(2) << p.attack << " damage to your enemy!" << endl;
                        if (enemy.health <= 0){
                            cout << "Your enemy dies! You move on safe." << endl;
                            return 1;                               // Returns 1 if player wins
                        }
                    }
                    else{
                        cout << "You trip and miss your attack!" << endl;
                    }
                    break;
                }
                case (2) : {
                    if (p.defense <= 38){                          // Boosts defense if it is less than a set value
                        p.defense += 2;
                        cout << "Defense boosted by 2!" <<endl;
                    }
                    else{
                        cout << "Cannot brace anymore, please select another option next time." << endl;
                    }
                    break;
                }
                case (3) : {                                         // Tries to escape, escaping is harder in a fight
                    if (check > p.evasion + 15){
                        cout << "Escaped safely";
                        return 3;                                   // Returns 3 if escaped away safely
                    }
                    else if (check > p.evasion + 5){                // Sometimes there may be some damage even if player escapes
                        cout << "You escape, but your enemy grazes you with his weapon, and you take 5 damage" << endl;
                        p.health -= 5;
                        return 3;
                    }
                    else{
                        cout << "Failed to escape" << endl;
                    }
                    break;
                }

            }
            counter ++;                             // Increase counter at the end of the turn to alternate between player and enemy
        }
        else if (counter % 2 != 0){                 // Enemy turn
            srand (time(NULL));
            cout << "Enemy's turn." << endl;
            int enemy_check = rand() % 101 + 1;
            if (enemy_check < 30){                  // 29% of the time enemy tends to brace
                if (enemy.defense <= 23){           // Braces only if defense below a certain number
                    cout << "Your enemy braced himself. His defense was raised by 2" << endl;
                    enemy.defense += 2;
                }
                else{                               // Else just attacks
                    double player_dq = p.DefenseQuoficient();   // Determines parameter which likelihood of an attack hitting the player
                    if (check > player_dq){                     // Hits if generated number > parameter
                        p.health -= enemy.attack;
                        cout << "Your enemy attacks you, and you take " << enemy.attack << " damage!" << endl;
                        if (p.health <= 0){
                            cout << "You die, Game Over." << endl;
                            return 2;                           // Returns 2 if enemy wins and player dies
                        }
                    }
                }
            }
            else {                              // 71% of time attacks
                double player_dq = p.DefenseQuoficient();
                if (check > player_dq){
                    p.health -= enemy.attack;
                    cout << "Your enemy attacks you, and you take " << enemy.attack << " damage!" << endl;
                    if (p.health <= 0){
                        cout << "You die, Game Over." << endl;
                        return 2;
                    }
                }
            }
            counter++;
        }
    }
}

#endif
