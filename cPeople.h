#include "cAnimals.h"
#include "cVehicle.h"
#include "Console.h"	
#ifndef cPeople_h
#define cPeople_h
class cPeople {
private:
	int mX, mY;
	bool isAlive; //dead or live
public:
	cPeople() {
		mX = 9;
		mY = 9;
		isAlive = true;
	}
	void draw();
	void deleteOldObj();
	void Up();
	void Down();
	void Left();
	void Right();
	bool isImpact(cDinausor *x, int size);
	bool isFinish();
	/*bool isImpact(const cAnimal *&x);
	bool isFinish();*/
	int getX() {
		return mX;
	}
	int getY() { return mY; }
	bool isDead();
	void Dead();
 };
#endif // !cPeople_h
