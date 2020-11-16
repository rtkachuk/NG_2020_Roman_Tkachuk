#include <iostream>
#include <random>

using namespace std;

int main()
{
	// srand used to set random number generator for our engine.
	//

	srand(time(0));

	// mapSize actually contain general map size
	// map - actual matrix array, which contain all required objects from map.
	//       this is our 'map'
	// playerMap - matrix array, which contain 'fog'. 'fog' - means hidden map from player.
	//             As player moves, playerMap will copy data from map array.
	// userAction - contain letter from user input. This letter means action, that player want to be done.
	// playerPox[X,Y] - contain player position for X and Y.
	//

	int mapSize = 10;
	char map[10][10];
	char playerMap[10][10];
	char userAction;
	int playerPosX = 0;
	int playerPosY = 0;
	int inventorySize = 10;
	char inventoryItems[10];
	int inventoryAmounts[10];

	// Right after program start, first point: generate our "world".
	// In this case: create double for loop (outer loop used for shifting by rows, and inner used to
	// work with data inside columns.
	//

	for (int row=0; row<mapSize; row++) {
		for (int col=0; col<mapSize; col++) {

			// Here we generating items inside our map

			// t -- tree
			// s -- stones
			// . -- fields
			// w -- water

			switch(rand()%20) {   // Hey, give me random number from 0 to 19 !
				case 1: map[row][col] = 't'; break; // If it will be 1, put a tree inside this cell!
				case 2: map[row][col] = 's'; break; // If 2 - put stone
				case 3: map[row][col] = 'w'; break; // 3 - water, please!
				default: map[row][col] = '.'; // Otherwise, filelds would be great!
			}

			// Player map in this case should contain only fog, and nothing else
			//

			playerMap[row][col] = '*';
		}
	}

	// Now, let's init our inventory, and fill it with empty values
	//

	for (int i=0; i<inventorySize; i++) {
		inventoryItems[i] = 0;
		inventoryAmounts[i] = 0;
	}

	// And, we ended up level generation in our map! So, let's do the 'engine' part, which basically contain infinite loop.
	// Each turn loop waiting for user input. And according to user input, the game will react.
	//

	while (true) {

		// First of all, clean screen before drawing anything
		//

		// for windows: system("cls");
		system("clear");

		// Next, in this loop we will show only player's map. So, according to player position, let's open cells aroung player. Basically, replace all '*' in 'playerMap'
		// with data from 'map' array
		//

		playerMap[playerPosY][playerPosX] = map[playerPosY][playerPosX];
		if (playerPosY+1 < mapSize) playerMap[playerPosY+1][playerPosX] = map[playerPosY+1][playerPosX];
		if (playerPosX+1 < mapSize) playerMap[playerPosY][playerPosX+1] = map[playerPosY][playerPosX+1];
		if (playerPosX+1 < mapSize && playerPosY+1 < mapSize) playerMap[playerPosY+1][playerPosX+1] = map[playerPosY+1][playerPosX+1];
		if (playerPosY-1 >= 0) playerMap[playerPosY-1][playerPosX] = map[playerPosY-1][playerPosX];
		if (playerPosX-1 >= 0) playerMap[playerPosY][playerPosX-1] = map[playerPosY][playerPosX-1];
		if (playerPosX-1 >= 0 && playerPosY-1 >= 0) playerMap[playerPosY-1][playerPosX-1] = map[playerPosY-1][playerPosX-1];
		if (playerPosY-1 >= 0 && playerPosX+1 < mapSize) playerMap[playerPosY-1][playerPosX+1] = map[playerPosY-1][playerPosX+1];
		if (playerPosY+1 < mapSize && playerPosX-1 >= 0) playerMap[playerPosY+1][playerPosX-1] = map[playerPosY+1][playerPosX-1];

		// Now, let's show our 'playerMap' to screen, and give our player at least some information of the surface.
		//

		for (int row=0; row<mapSize; row++) {
			for (int col=0; col<mapSize; col++) {

				// Well, if our player stands on this position - draw our player instead of
				// map contents
				//

				if (row == playerPosY && col == playerPosX)
					cout << "@";
				else

					// This is our 'video driver' which decides: how each item can be shown
					//

					switch (playerMap[row][col])
					{
						case 't': cout << "\e[32mt\e[39m"; break; // trees are green
						case 'w': cout << "\e[34m\e[5mw\e[39m\e[0m"; break; // water is blue and contain small animation
						case 's': cout << "\e[90ms\e[39m"; break; // stones are grey
						default: cout << playerMap[row][col]; // Otherwise - just show item as it is
					}
			}
			cout << endl;
		}

		// Next - read user input, and process it. Currently, we can process only 'wasd' keys
		//

		cout << ">";
		cin >> userAction;

		switch (userAction) {
			case 'w': if (playerPosY-1 >= 0) playerPosY--; break;
			case 's': if (playerPosY+1 < mapSize) playerPosY++; break;
			case 'a': if (playerPosX-1 >= 0) playerPosX--; break;
			case 'd': if (playerPosX+1 < mapSize) playerPosX++; break;
			case 'i': {
				system("clear");
				cout << "Inventory" << endl;
				cout << "======================================" << endl;
				for (int i=0; i<inventorySize; i++) {
					if (inventoryAmounts[i] != 0) {
						switch(inventoryItems[i]) {
							case 'a' : cout << "Hand axe x "; break;
							case 'p' : cout << "pills x "; break;
							default: cout << "UNKNOWN [" << inventoryItems[i] << "] x ";
						}
						cout << inventoryAmounts[i] << endl;
					}
				}
				cout << "======================================" << endl;
				cin.ignore();
				cin.get();

			} break;
			case 'q': return 0;
		}
	}
}
