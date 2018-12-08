#include"Console.h"

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) &~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawScreen() {
	/*for (int i = 0; i < 50; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < 20; i++) {
		if (i != 5 && i != 10) {
			for (int j = 0; j < 50; j++)
			{
				if (j == 0)cout << "#";
				if (j == 48) cout << "#";
				cout << " ";
			}

		}
		else {
			for (int j = 0; j < 50; j++)
				cout << "#";
		}
		cout << endl;
	}
	for (int i = 0; i < 50; i++)
		cout << "#";
	cout << endl;*/
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 40; j++) {
			cout << "_";
		}
		cout << endl;
	}
}
