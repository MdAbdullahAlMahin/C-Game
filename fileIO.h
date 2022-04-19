#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include "player.h"          // Included so that programs recognize MyPlayer data type so that stats can be stored
#include "hotel.h"           // Included so that programs recognize Hotel data type so that stats can be stored

using namespace std;

// Saves the game state
void SaveGame(string slot, MyPlayer x, Hotel h, int debug){
    ofstream fout;
    cout << "If a file in that slot exists, the old savegame will be erased!" <<endl;
    cout << "As this is a game based on random generation, the hotel when you load back the game may change" <<endl;
    string destination = "Savegame " + slot + ".txt";
    fout.open(destination.c_str());
    if (fout.fail()){
        cout << "Error saving game." << endl;
        return;
    }
    // Stores the values
    fout << debug << endl;
    fout << x.health << endl;
    fout << x.attack << endl;
    fout << x.defense << endl;
    fout << x.evasion << endl;
    fout << x.AttackMultiplier << endl;
    fout << x.DefenseMultiplier << endl;
    fout << x.EvasionMultiplier << endl;
    fout << h.CurrentFloor << endl;
    fout << h.TotalFloor << endl;
    cout << "Game Saved" << endl;
}

// Loads desired data
int LoadGame (string slot, MyPlayer &x, Hotel &h, int debug){
    ifstream fin;
    int counter = 0;
    cout << "Loading Savegame " << slot << endl;
    string destination = "Savegame " + slot + ".txt";
    fin.open(destination.c_str());
    if (fin.fail()){
        cout << "Error loading game." << endl;
        cout << "Savegame does not exist" << endl;
        return 1;                           // Returns 1 if error
    }
    double item;
    while (fin >> item){                   // Take all data as input
        // Items for different counters are stored in their correct places
        switch (counter){
        case 0 : {
            debug = item;
            break;
        }
        case 1 : {
            x.health = item;
            break;
        }
        case 2 : {
            x.attack = item;
            break;
        }
        case 3 : {
            x.defense = item;
            break;
        }
        case 4 : {
            x.evasion = item;
            break;
        }
        case 5 : {
            x.AttackMultiplier = item;
            break;
        }
        case 6 : {
            x.DefenseMultiplier = item;
            break;
        }
        case 7 : {
            x.EvasionMultiplier = item;
            break;
        }
        case 8 : {
            h.CurrentFloor = item;
            break;
        }
        case 9 : {
            h.TotalFloor = item;
            break;
        }
        }
        counter ++;
    }
    return 2;                   // Returns 2 if all okay
}

#endif
