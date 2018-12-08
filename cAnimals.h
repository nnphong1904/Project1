
#ifndef cAnimals_h
#define cAnimals_h
#include "Console.h"
class cAnimal {
protected:
	int mX, mY;
public:
	cAnimal() {
		mX = 0;
		mY = 0;
	}
	cAnimal(int x, int y) {
		mX = x;
		mY = y;
		
	}
	virtual int getX() {
		return mX;
	}
	virtual int getY() {
		return mY;
	}
	void updatePos(int x, int y) {
		mX = x;
		mY = y;
	}

	void deleteLeftObj();
	virtual void move();
	virtual void draw()= 0;
 };
class cDinausor : public cAnimal {
public:
	cDinausor() :cAnimal(){}
	cDinausor(int x, int y) :cAnimal(x, y) {
	}
	int getX() {
		return cAnimal::getX();
	}
	int getY() {
		return cAnimal::getY();
	}
	void move();
	void draw();
};
class cBird : public cAnimal {
public:
	
	cBird(int x, int y) : cAnimal(x, y) {}
	void move();
	void tell();
	void draw();
};
#endif // !cAnimals_h
