#include <iostream>
// Imports all other files as all of them contain code needed for the main game
#include "player.h"
#include "enemy.h"
#include "hotel.h"
#include "fileIO.h"
#include "fight.h"

using namespace std;

// Prints out text at the beginning of a new game
void NewGameText(){
    cout << "Welcome to the infamous Hotel Cecil.\nUnfortunately for you, the infamous Charles Manson has taken over the hotel and threatens to kill you.\n";
    cout << "You must now escape this nightmare.\nYou start at the top of the hotel, and must make your way down.\nHave fun! Hope something sinister doesn't happen to you.\n";
    cout << endl;
    cout << "You will have the choices of taking 3 ways each floor." << endl;
    cout << "One contains an enemy, one contains a treasure, the other has nothing." << endl;
    cout << "Make the right choices and you'll get out a safe man/woman." << endl;
}

int main(){
    MyPlayer player;
    Hotel Cecil;
    int t_floor; // stores total floors
    int floor = 0; // store current floor
    int player_cmd; // stores player commands (inside main menu)
    int cmd; // stores game commands (inside a running game)
    cout << "      Welcome to our game," << endl;
    cout << "    ESCAPE FROM HOTEL CECIL" << endl;
    cout << endl;
    cout << "1 : New Game" << endl << "2 : Load Game" << endl << "3 : Exit" << endl << endl;
    cout << "Enter Command : ";
    cin >> player_cmd;
    while (player_cmd != 1 && player_cmd != 2 && player_cmd != 3){  // input until desirable input
        cout << "Wrong command, please enter an integer between 1 and 3." << endl;
        cout << "Enter Command : ";
        cin >> player_cmd;
    }
    cout<< endl;
    int debug;  // check for debug mode, this will make the game very easy and allow a person to go over the game very fast to check for errors
    while (player_cmd != 3){  // run until user does not want to exit
        bool game_done = false; // a checking variable to see if game has been finished, then loop is broken
        if (player_cmd == 1){
            cout << "Starting new game. Please read Readme.txt for detailed explanation of features for our game." << endl;
            cout << "Turn debug mode on? Will make fights much more easier. input 0 for no, 1 for yes." << endl;
            cout << "Enter command : ";
            cin >> debug;
            while (debug != 0 && debug != 1){
                cout << "Enter again (0 or 1) : ";
                cin >> debug;
            }
            cout << endl;
            if (debug == 1){    // if 1 give player one shot kill abilities
                player.attack = 50;
            }
            cout << "Total Floors (Please enter a number between 5 and 15 for the best experience) : ";
            cin >> t_floor;
            cout << endl;
            while (t_floor < 5){ // input until desirable input
                cout << "Please enter a number at least above 5" << endl;
                cout << "Enter number of floors : ";
                cin >> t_floor;
            }
            Cecil.TotalFloor = t_floor;
            Cecil.GenerateHotel(); // Generates the random hotel
            Cecil.PrintHotel();
            NewGameText();
        }
        else if (player_cmd == 2){ // To load game
            cout << "Please make sure savegame exits, if no savegame exits, game will start as if newgame";
            cout << "Enter Slot (Must be between 1 and 3) : ";
            string slot;
            cin >> slot;
            while (slot != "1" && slot != "2" && slot != "3"){ // input until desirable input
                cout << "Wrong slot, please enter an integer between 1 and 3." << endl;
                cout << "Enter Slot : ";
                cin >> slot;
            }
            cout << endl;
            int check = LoadGame(slot, player, Cecil, debug); // loads game
            if (debug == 1){    // if 1 give player one shot kill abilities
                player.attack = 50;
            }
            t_floor = Cecil.TotalFloor; // returns current game to loaded game
            floor = Cecil.CurrentFloor;
            cout << "Total Floors : " << t_floor << endl;
            if (check == 1){ // if no save file exits, game will go on as if new game
                NewGameText();
            }
        }
        while (game_done == false){ // run a loop until game is completed, or user chooses exit
            cout << endl << "Current Floor : " << floor + 1 << endl << endl;
            cout << "1 : Path 1" << endl;
            cout << "2 : Path 2" << endl;
            cout << "3 : Path 3" << endl;
            cout << "4 : Save Game" << endl;
            cout << "5 : Exit to Main Menu" << endl << endl;
            cout << "Enter Command : ";
            cin >> cmd;
            while (cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd != 5){ // input until desirable input
                cout << "Wrong command, please enter an integer between 1 and 5." << endl;
                cout << "Enter Command : ";
                cin >> cmd;
            }
            cout << endl;
            if (cmd == 4){ // Save current game, do not progress forward in terms of floors
                cout << "Enter Slot (Must be between 1 and 3) : ";
                string slot;
                cin >> slot;
                while (slot != "1" && slot != "2" && slot != "3"){ // input until desirable input
                    cout << "Wrong slot, please enter an integer between 1 and 3." << endl;
                    cout << "Enter Slot : ";
                    cin >> slot;
                }
                Cecil.CurrentFloor = floor;
                SaveGame(slot, player, Cecil, debug);
                cout << endl;
            }
            else if (cmd == 5){ //Returns to main menu, does not go ahead in terms of floors, does not save current game
                game_done = true;
                break;
            }
            else{ // else, the corresponding action is done according to the input
                char situation = Cecil.hotel[floor * 3 + cmd - 1]; // to access a particular room, a further explanation is given in Readme.txt
                if (situation == 'h'){ // getting health treasure
                    floor ++; // progress floor only if command selected is for room and not save game or exit to main menu
                    player.HealUp();
                }
                else if (situation == 'a'){ // getting attack treasure
                    floor ++; // same as for case 'h'
                    player.cinAttack();
                    player.AttackBoost();
                }
                else if (situation == 'd'){ // getting defense treasure
                    floor ++; // same as for case 'h'
                    player.cinDefense();
                    player.DefenseBoost();
                }
                else if (situation == 'e'){ // getting evasion treasure
                floor ++; // same as for case 'h'
                    player.cinEvasion();
                    player.EvasionBoost();
                }
                else if (situation == 'f'){ // fight between player and enemy
                    floor ++; // same as for case 'h'
                    if (floor == t_floor){ // if final floor, boss fight
                        int check = fight(player, true);
                        if (check == 2){ // if enemy wins, game over
                            game_done = true;
                        }
                    }
                    else{
                        int check = fight(player, false); // else normal fight
                        if (check == 2){ // if enemy wins, game over
                            game_done = true;
                        }
                    }
                }
                else if (situation == 'r'){
                    floor ++; // same as for case 'h'
                    cout << "Lucky you! There is no one and nothing here, you move on safely." << endl;
                }
            }
            if (t_floor == floor && game_done == false){ // if pass through all floors then game is won
                cout << endl << "Congrats, you escaped away safely.\n\nReturning to Main Menu..." << endl << endl;
                game_done = true;
            }
            if (player.health <= 0){ // if health < 0, game lost
                cout << endl << "Charles Manson's goons chipped away at your health, causing you to fall, never to get up again.\n\n Returning to Main Menu..." << endl << endl;
                game_done = true;
            }
        }
        // Return to main menu and ask for input
        cout << "1 : New Game" << endl << "2 : Load Game" << endl << "3 : Exit" << endl << endl;
        cout << "Enter Command : ";
        cin >> player_cmd;
        while (player_cmd != 1 && player_cmd != 2 && player_cmd != 3){
            cout << "Wrong command, please enter an integer between 1 and 3." << endl;
            cout << "Enter Command : ";
            cin >> player_cmd;
        }
    }
    delete (Cecil.hotel); // free up dynamic memory
    cout << "Bye Bye" << endl;
return 0;
}
