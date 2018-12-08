#ifndef Console_h
#define Console_h
#include <iostream>
#include <string> 
#include <Windows.h>
#include <thread>
#include <conio.h>
using namespace std;
void FixConsoleWindow();
void GotoXY(int x, int y);
void drawScreen();

#endif // !Console_h
