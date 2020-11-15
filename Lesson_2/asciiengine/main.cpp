#include <iostream>
#include <random>

using namespace std;

int main()
{
	srand(time(0));
	int mapSize = 10;
	char map[10][10];
	char playerMap[10][10];
	char userAction;
	int playerPosX = 0;
	int playerPosY = 0;

	for (int row=0; row<mapSize; row++) {
		for (int col=0; col<mapSize; col++) {
			// t -- tree
			// s -- stones
			// . -- fields
			// w -- water

			switch(rand()%20) {
				case 1: map[row][col] = 't'; break;
				case 2: map[row][col] = 's'; break;
				case 3: map[row][col] = 'w'; break;
				default: map[row][col] = '.';
			}
			playerMap[row][col] = '*';
		}
	}

	while (true) {
		// for windows: system("cls");
		system("clear");

		playerMap[playerPosY][playerPosX] = map[playerPosY][playerPosX];
		if (playerPosY+1 < mapSize) playerMap[playerPosY+1][playerPosX] = map[playerPosY+1][playerPosX];
		if (playerPosX+1 < mapSize) playerMap[playerPosY][playerPosX+1] = map[playerPosY][playerPosX+1];
		if (playerPosX+1 < mapSize && playerPosY+1 < mapSize) playerMap[playerPosY+1][playerPosX+1] = map[playerPosY+1][playerPosX+1];
		if (playerPosY-1 < mapSize) playerMap[playerPosY-1][playerPosX] = map[playerPosY-1][playerPosX];
		if (playerPosX-1 < mapSize) playerMap[playerPosY][playerPosX-1] = map[playerPosY][playerPosX-1];
		if (playerPosX-1 < mapSize && playerPosY-1 < mapSize) playerMap[playerPosY-1][playerPosX-1] = map[playerPosY-1][playerPosX-1];
		if (playerPosX-1 < mapSize && playerPosY+1 < mapSize) playerMap[playerPosY-1][playerPosX+1] = map[playerPosY-1][playerPosX+1];
		if (playerPosX+1 < mapSize && playerPosY-1 < mapSize) playerMap[playerPosY+1][playerPosX-1] = map[playerPosY+1][playerPosX-1];

		for (int row=0; row<mapSize; row++) {
			for (int col=0; col<mapSize; col++) {
				if (row == playerPosY && col == playerPosX)
					cout << "@";
				else
					switch (playerMap[row][col])
					{
						case 't': cout << "\e[32mt\e[39m"; break;
						case 'w': cout << "\e[34m\e[5mw\e[39m\e[0m"; break;
						case 's': cout << "\e[90ms\e[39m"; break;
						default: cout << playerMap[row][col];
					}
			}
			cout << endl;
		}
		cout << ">";
		cin >> userAction;

		switch (userAction) {
			case 'w': playerPosY--; break;
			case 's': playerPosY++; break;
			case 'a': playerPosX--; break;
			case 'd': playerPosX++; break;
		}
	}
}
