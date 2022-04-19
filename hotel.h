#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <ctime>
#include <algorithm>                                // Included to carry out the random_shuffle function to determine the hotel room contents
using namespace std;

// Create a struct which deals with all the data for the Cecil Hotel
struct Hotel{

    int TotalFloor;
    int CurrentFloor;

    char *hotel = new char[TotalFloor * 3];           // Creates a dynamic array based on the user's input of TotalFloor
                                                      // Each Floor has 3 rooms/paths therefore is multiplied by 3

    // Prints out the hotel rooms for each floor for debugging and checking purposes
    void PrintHotel(){
        for (int i = 0; i < TotalFloor * 3; i++){
            if (i % 3 == 0 && i != 0){
                cout << endl;
            }
            cout << hotel[i] << " ";
        }
    }

    // Randomly generate the hotel, keeping in mind that all floors must have one fight, one empty room, and one treasure, with some exceptions
    void GenerateHotel(){
        srand(time(NULL));
        char room;
        int check;
        int counter = 0;
        char choices[3] = {'f', 'r', 't'};
        random_shuffle (&choices[0], &choices[3]);         // Randomly shuffle the three choices, f = fight, r = run (empty), t = treasure
        for (int k = CurrentFloor; k < TotalFloor * 3; k++){
            if (k % 3 == 0){
                random_shuffle (&choices[0], &choices[3]); // Shuffle again at the beginning of each floor
            }
            if (choices[counter] == 't'){                  // Designate the different kinds of treasures to each room
                check = rand() % 101 + 1;
                if (check < 24){                           // 23% chance for an attack treasure
                    hotel[k] = 'a';
                }
                else if (check >= 24 && check < 48){       // 24% chance for a defense treasure
                    hotel[k] = 'd';
                }
                else if (check >= 48 && check < 72){       // 24% chance for an evasion treasure
                    hotel[k] = 'e';
                }
                else{                                      // 29% chance for a health pack
                    hotel[k] = 'h';
                }
            }
            else{
                hotel[k] = choices[counter];
            }
            counter++;
            if (counter == 3){                             // Used to make sure no out of bounds index is taken
                counter = 0;
            }
            if (k/3 == TotalFloor/2){                      // Halfway down the hotel the user is guaranteed a healthpack
                hotel[k] = 'h';
            }
            if (k/3 == TotalFloor-1){                      // The final floor will always be  a fight
                hotel[k] = 'f';
            }
        }
    }
};

#endif
