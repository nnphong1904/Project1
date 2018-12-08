#include "cAnimals.h"
void cAnimal::move() {
		deleteLeftObj(); 
		mX += 1;
		if (mX == 39) mX = 1;
		GotoXY(mX, mY);
		draw();		
		Sleep(10);
	
}
void cAnimal::deleteLeftObj() {
	GotoXY(mX, mY);
	cout << "_";
}
void cDinausor::draw() {
	cout << "D";
}
void cDinausor::move() {
	cAnimal::move();
}
void cBird::draw() {
	cout << "B";
}
void cBird::move() {
	cAnimal::move();
}