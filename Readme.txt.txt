# ENGG1340-Group-92
This repository is used to house all the files of our group project for the course ENGG1340
Group: 92
Members: 1) Md Abdullah Al Mahin, UID: 3035767528,
	    Contribution : About 50 percent
         2) Antara Fairooz Hasan, UID: 3035831276,
            Contribution : About 50 percent
Note: The game files were created on Windows and therefore the github contributions page may not be accurate.
         
Description: 
	An original, action-based game that we're calling 'Escape from Hotel Cecil' . 

        The user is a tourist staying at the Hotel Cecil in the mid 1960's. He is abruptly awoken at the dead of one fateful night to learn that the hotel has been taken                
	over by Charle's Manson's villainous cult, and he was the only customer left behind during the evacuation. He must find his way out through the dangerous lair that              
	Manson and his followers have woven through the building.

        Charles, the evil genius, has scattered his henchmen throughout the building, and posted his strongest, most brutal guard at the gates. 
        You, the user, start at your penthouse suite at the very top, and have to maneuver your descent through the secret in-room ladders that lead from one room to any
        other room on the floor below it, as the elevators and main stairs have been barred. If you encounter a henchman in the process,
        you have to stay and fight. A gift may or may not be waiting for you in any given room.
        If you are skilled and fortunate enough to get to the bottom, you must kill the guard to escape!
	
	At each level, there are three paths the player may take. One leads to a treasure, which gives the player an advantage in combat.
	Another room may have a guard waiting to lunge at you, and begin a fight to the death.
	The third room contains nothing, you move on, at least you didn't have to fight anyone!
	This rule may have some exceptions though, the hotel staff were kind enough to leave medical kits in all rooms around halfway down the hotel.
	And at the bottom, regardless of the room you choose, you are met by the cunning and fearsome team leader, and must get through him to escape.

	*Our game also has a so called "debug" mode, where the player gains godly strength and can fight off most enemies with one blow. 
	 This mode is for quickly checking the game and cannot be said to be part of the core gameplay.
	     
List of Features:
	1) Generation of random sets of events:
		The hotel, even though it has some set of laws to abide, is generated in a random manner in a sense.
		The probabilites and likelihoods of attack hit or misses, or if the player can escape away are all based on random number generation.

	2) Data Structures for storing game status:
		A dynamic array was used to store the different randomized outputs in the different floors of the hotel.
		Three structs MyPlayer, Enemy, and Hotel, were used to store information about the player, the enemy, and the hotel respectively.
	
	3) Dynamic Memory Managment:
		A dynamic array was used to store the hotel data so that the user could define the size of the hotel.

	4) File IO:
		An entire header file was made for loading and storing the game status. A save game and load game option are available in the game.

	5) Program Codes in Multiple Files:
		There are a total of 6 files each with integral codes.

	6) Misc:
		Debug mode allows fast checking of the game.
		The game has branching lines, giving the user great choice in what to do at a particular moment.

More Information about the Codes in different files:
	1) player.h and enenmy.h:
		The DefenseQuotient() function makes use of a common algorithm to determine the liklihood of an attack on the player or the enemy missing.
		The formula is as follows: 
			Given d = defense, e = evasion, p = parameter, 
			result = ln(d) + e + e/p.
			for enemy, p = 10, and p = 8 for the player.
			The value of p is arbitrary and is set by us following some testing.
	2) player.h:
		The formula for boosting attack, defense, or evasion is as follows:
			result = m * multiplier + c,
			where m is an arbitrarry value set by us (0.8 for attack and defense and 1.8 for evasion)
			c is the original value of the variable (5 for attack and defense, 20 for evasion)
			and multiplier is the respective multiplier.
	3) hotel.h:
		There is a function, PrintHotel(), inside the struct. This was used for debugging and checking purposes.

Compilation Intructions:
	Testing was done on the academy server.
	A Makefile has been made for ease of access should any changes be made.
	The game can also be directly complied using the code : g++ -pedantic-errors -std=c++11 game.cpp -o game
	and the running the code : ./game
	"./game" can also be run as is as there is already a executable file in the repository. 

		
		     



