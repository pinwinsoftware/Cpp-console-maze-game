#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <direct.h>

using namespace std;

char map[25][48];

bool LoadMapFromFile(const string& filename) { //Load level from text file
	ifstream file(filename);

	string line;
	int y = 0;
	while (getline(file, line) && y < 25) {
		for (int x = 0; x < 48; ++x) {
			map[y][x] = line[x];
		}
		y++;
	}

	return true;
}

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void positionxy(short x, short y) //get position
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };

	SetConsoleCursorPosition(hStdout, position);
}

void TextColor(int color)
{
	SetConsoleTextAttribute(h, color);
}

void DrawBoard() //Change color and ascii character
{
	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 48; x++) {
			positionxy(x, y);

			char tile = map[y][x];

			switch (tile) {
			case '#':
				TextColor(1);
				std::cout << char(219);
				break;
			case '1':
				TextColor(1);
				std::cout << char(176);
				break;
			case '4':
				TextColor(6);
				std::cout << char(176);
				break;
			case '5':
				TextColor(6);
				std::cout << char(177);
				break;
			case '6':
				TextColor(6);
				std::cout << char(178);
				break;
			default:
				TextColor(7);
				std::cout << ' ';
				break;
			}
		}
	}
}

void hideCursor() { //Hide Cursor
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cInfo;

	GetConsoleCursorInfo(hOut, &cInfo);
	cInfo.bVisible = false;
	SetConsoleCursorInfo(hOut, &cInfo);
}

int main()
{
	bool menu = true;
	bool Game = false;
	bool win = false;
	int Menuchange = 1;
	int Assistance = false;
	int Info = false;
	int Cheats = false;
	int CheaterMode = false;
	int Infochange = 0;
	int level = 0;
	int x = 1;
	int y = 23;

	hideCursor();

	while (menu) { //Main menu

		TextColor(7);
		positionxy(4, 2); cout << "Maze Ways";

		if (Menuchange == 1) {
			TextColor(1);
			positionxy(4, 4); cout << "Start game";
		}
		else {
			TextColor(7);
			positionxy(4, 4); cout << "Start game";
		}

		if (Menuchange == 2) {
			TextColor(1);
			positionxy(4, 6); cout << "Assistance";
		}
		else {
			TextColor(7);
			positionxy(4, 6); cout << "Assistance";
		}

		if (Menuchange == 3) {
			TextColor(1);
			positionxy(4, 8); cout << "Information";
		}
		else {
			TextColor(7);
			positionxy(4, 8); cout << "Information";
		}

		if (Menuchange == 4) {
			TextColor(1);
			positionxy(4, 10); cout << "Cheats";
		}
		else {
			TextColor(7);
			positionxy(4, 10); cout << "Cheats";
		}

		if (Menuchange == 5) {
			TextColor(1);
			positionxy(4, 12); cout << "Exit";
		}
		else {
			TextColor(7);
			positionxy(4, 12); cout << "Exit";
		}

		TextColor(7);
		positionxy(4, 21); cout << "(C) 2025 Larion Naumenko.";

		char MainMenu[25][48] = {
			"###############################################",
			"#                                             #",
			"#                    #   #  ###  ##### #####  #",
			"#                    ## ## #   #    #  #      #",
			"#                    # # # #####   #   #####  #",
			"#                    #   # #   #  #    #      #",
			"#                    #   # #   # ##### #####  #",
			"#                                             #",
			"#                    #   #  ###  #   #  ####  #",
			"#                    #   # #   #  # #  #      #",
			"#                    # # # #####   #    ###   #",
			"#                    # # # #   #   #       #  #",
			"#                     # #  #   #   #   ####   #",
			"#                                             #",
			"#                                             #",
			"#                                             #",
			"#                                             #",
			"#                                             #",
			"#                                             #",
			"#                                             #",
			"#                                             #",
			"#                                             #",
			"#                                             #",
			"#                                             #",
			"###############################################",
		};

		for (int y = 0; y < 25; y++) {
			for (int x = 0; x < 48; x++) {
				positionxy(x, y);

				char tile = MainMenu[y][x];

				switch (tile) {
				case '#':
					TextColor(1);
					std::cout << char(219);
					break;
				}
			}
		}

		if (GetAsyncKeyState(VK_UP)) { //Menu controls
			if (Menuchange > 1) {
				Menuchange--;
				Beep(750, 150);
			}
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (Menuchange < 5) {
				Menuchange++;
				Beep(750, 150);
			}
		}

		if (GetAsyncKeyState(VK_RETURN) && Menuchange == 1) { //Start game
				Game = true;
				break;
		}

		if (GetAsyncKeyState(VK_RETURN) && Menuchange == 2) { //Assistance
				Assistance = true;
				system("cls");
		}

		if (GetAsyncKeyState(VK_RETURN) && Menuchange == 3) { //Information
				Assistance = true;
				Info = true;
				system("cls");
		}

		if (GetAsyncKeyState(VK_RETURN) && Menuchange == 4) { //Cheats
				Sleep(1000);
				Cheats = true;
				system("cls");
		}

		if (GetAsyncKeyState(VK_RETURN) && Menuchange == 5) { //Exit
				exit(0);
		}

		while (Assistance) { //Assistance menu
			char AssistanceMenu[25][48] = {
				"###############################################",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"###############################################",
			};

			for (int y = 0; y < 25; y++) {
				for (int x = 0; x < 48; x++) {
					positionxy(x, y);

					char tile = AssistanceMenu[y][x];

					switch (tile) {
					case '#':
						TextColor(1);
						std::cout << char(219);
						break;
					}
				}
			}
			if (!Info) { //Information menu
				TextColor(7);
				positionxy(4, 2);
				cout << "Controls:";
				positionxy(4, 4);
				cout << "Move right: Right arrow";
				positionxy(4, 6);
				cout << "Move left: Left arrow";
				positionxy(4, 8);
				cout << "Move up: Top arrow";
				positionxy(4, 10);
				cout << "Move down: Bottom arrow";
				positionxy(4, 12);
				cout << "Escape: Return to main menu";
				positionxy(4, 21);
				cout << "(C) 2025 Larion Naumenko.";
			}
			else {
				if (Infochange == 1) {
					TextColor(1);
					positionxy(4, 2);
					cout << "Maze Ways is a command prompt game in";
				}
				else {
					TextColor(7);
					positionxy(4, 2);
					cout << "Maze Ways is a command prompt game in";
				}

				if (Infochange == 2) {
					TextColor(1);
					positionxy(4, 3);
					cout << "genre maze, written in C++. It has 10";
				}
				else {
					TextColor(7);
					positionxy(4, 3);
					cout << "genre maze, written in C++. It has 10";
				}

				if (Infochange == 3) {
					TextColor(1);
					positionxy(4, 4);
					cout << "different mazes where player must get";
				}
				else {
					TextColor(7);
					positionxy(4, 4);
					cout << "different mazes where player must get";
				}

				if (Infochange == 4) {
					TextColor(1);
					positionxy(4, 5);
					cout << "to the exit. More information here:  ";
				}
				else {
					TextColor(7);
					positionxy(4, 5);
					cout << "to the exit. More information here:  ";
				}

				if (Infochange == 5) {
					positionxy(4, 6);
					TextColor(1);
					cout << "https://pinwinsoftware.com/Maze-Ways/";
				}
				else {
					positionxy(4, 6);
					TextColor(9);
					cout << "https://pinwinsoftware.com/Maze-Ways/";
				}

				positionxy(4, 21);
				TextColor(7);
				cout << "(C) 2025 Larion Naumenko.";

				if (GetAsyncKeyState(VK_UP)) { //Information menu controls
					if (Infochange > 1) {
						Infochange--;
						Beep(750, 150);
					}
				}
				if (GetAsyncKeyState(VK_DOWN)) {
					if (Infochange < 5) {
						Infochange++;
						Beep(750, 150);
					}
				}
				if (GetAsyncKeyState(VK_RETURN) && Infochange == 5) {
					const char* url = "https://pinwinsoftware.com/Maze-Ways";
					ShellExecuteA(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
					Beep(500, 50);
					Beep(1000, 150);
				}
				else if (GetAsyncKeyState(VK_RETURN) && Infochange < 5) {
					Beep(250, 150);
				}
			}

			if (GetAsyncKeyState(VK_ESCAPE)) {
				Infochange = 0;
				Assistance = false;
				Info = false;
				system("cls");
				break;
			}
		}
		while (Cheats) { //Cheat activation menu
			char Cheatmenu[25][48] = {
				"###############################################",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"#                                             #",
				"###############################################",
			};

			for (int y = 0; y < 25; y++) {
				for (int x = 0; x < 48; x++) {
					positionxy(x, y);

					char tile = Cheatmenu[y][x];

					switch (tile) {
					case '#':
						TextColor(1);
						std::cout << char(219);
						break;
					}
				}
			}

			Menuchange = 0;

			TextColor(7);
			positionxy(4, 2);
			cout << "Enter an 8-digit code to activate cheats.";
			positionxy(4, 3);
			cout << "Type exit to return to the main menu.";
			positionxy(4, 21);
			cout << "(C) 2025 Larion Naumenko.";

			string diffi;

			positionxy(4, 5); //Output position

			cin >> diffi;

			if (diffi == "12345678") {
				positionxy(4, 5);
				cout << "        ";
				positionxy(1, 6);
				cout << "        ";
				positionxy(1, 8);
				cout << "        ";
				positionxy(1, 7);
				cout << "   ";
				positionxy(4, 7);
				cout << "Cheats are activated!";
				CheaterMode = true;
			}
			else if (diffi == "exit") {
				system("cls");
				Cheats = false;
				break;
			}
			else { //If the code is false
				for (int line = 4; line <= 20; ++line) { //Clears space for text entry
					for (int x = 1; x < 46; ++x) {
						positionxy(x, line);
						cout << " ";
					}
				}
				positionxy(4, 7);
				cout << "Wrong code!          ";
				CheaterMode = false;
			}
		}
	}
	if (level == 0) {
		LoadMapFromFile("levels/level1.txt");
	}

	DrawBoard();

	while (Game) { //Game

		positionxy(x, y); cout << " ";

		if (GetAsyncKeyState(VK_UP)) { //Player movement controls 
			if (map[y - 1][x] == ' ' || map[y - 1][x] == '2' || map[y - 1][x] == '3') {
				y--;
			}
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (map[y + 1][x] == ' ' || map[y + 1][x] == '2' || map[y + 1][x] == '3') {
				y++;
			}
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			if (map[y][x - 1] == ' ' || map[y][x - 1] == '2' || map[y][x - 1] == '3') {
				x--;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (map[y][x + 1] == ' ' || map[y][x + 1] == '2' || map[y][x + 1] == '3') {
				x++;
			}
		}

		if (map[y][x] == '2' || GetAsyncKeyState(VK_RETURN) && CheaterMode && level < 9) { //After completing the level
			system("color 1a"); //Flashing effect
			Sleep(50);
			system("color 2b");
			Sleep(50);
			system("color 3c");
			Sleep(50);
			system("color 4d");
			Sleep(50);
			system("color 5e");
			Sleep(50);
			system("color 6f");
			Sleep(50);
			system("COLOR 01");
			Beep(1750, 150);

			level++;

			x = 1; //Starting positions of levels

			if (level == 1) {
				y = 1;
			}
			if (level == 2) {
				y = 12;
			}
			if (level == 3) {
				y = 3;
			}
			if (level == 4) {
				y = 1;
			}
			if (level == 5) {
				y = 17;
			}
			if (level == 6) {
				y = 23;
			}
			if (level == 7) {
				y = 7;
			}
			if (level == 8) {
				y = 13;
			}
			if (level == 9) {
				y = 1;
			}

			string LevelFile = "levels/level" + to_string(level + 1) + ".txt"; //Load next level file

			if (LoadMapFromFile(LevelFile)) {
				DrawBoard();
			}
		}
		if (map[y][x] == '3' || GetAsyncKeyState(VK_RETURN) && CheaterMode && level == 9) { //If game finished
			system("color 1a");
			Sleep(50);
			system("color 2b");
			Sleep(50);
			system("color 3c");
			Sleep(50);
			system("color 4d");
			Sleep(50);
			system("color 5e");
			Sleep(50);
			system("color 6f");
			Sleep(50);
			system("COLOR 01");
			Beep(1750, 150);
			win = true;
			break;
		}

		positionxy(x, y); //Player position
		TextColor(6); //Player color
		std::cout << char(254); //Player symbol

		Sleep(100);
	}

	while (win) { //victory screen
		if (LoadMapFromFile("levels/win.txt")) {
			DrawBoard();
		}
	}

	return 0;
}