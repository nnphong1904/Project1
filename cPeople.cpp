#include "cPeople.h"
void cPeople::draw() {
	GotoXY(mX, mY);
	cout << "Y";
}
void cPeople::deleteOldObj() {
	GotoXY(mX, mY);
	cout << "_";
}
void cPeople::Up() {
	deleteOldObj();
	mY -= 1;
	GotoXY(mX, mY);
	draw();

}
void cPeople::Down() {
	deleteOldObj();
	mY += 1;
	GotoXY(mX, mY);
	draw();
}
void cPeople::Left() {
	deleteOldObj();
	mX -= 1;
	GotoXY(mX, mY);
	draw();
}
void cPeople::Right() {
	deleteOldObj();
	mX += 1;
	GotoXY(mX, mY);
	draw();
}
bool cPeople::isDead() {
	if (isAlive == true) return false;
	else return false;
}

bool cPeople::isImpact( cDinausor *x, int size) {
	for (int i = 0; i < size; i++) {
		if (this->mX==x[i].getX() && this->mY == x[i].getY()) return true;
	}
	return false;
}

void cPeople::Dead() {
	isAlive = false;
}
bool cPeople::isFinish() {
	if (mY == 0) return true;
	else return false;
}