#include "cPeople.h"
#include "cAnimals.h"
#include "cPeople.h"
#include "Console.h"
#ifndef cGame_h
#define cGame_h
class cGame {
private:
//	cTruck *axt;
//	cCar *axh;
	cDinausor *akl;
	cDinausor *akl1;
	cBird *ac;
	cPeople cn;
public:
	cGame() {
		akl = new cDinausor[6];
		akl1 = new cDinausor[6];
		//ac = new cBird;
	}
	// chuan bi du lieu cho tat ca doi tuong
	void drawGame(); //Thuc hien ve tro choi ra man hinh sau khi co du lieu
	cPeople getPeople();//lay thong tin nguoi 
	//cVehicle* getVehicle();//Lay danh sach xe
	cDinausor* getAnimal();//lay danh sach thu
	cDinausor* getAnimal1();
	//void pauseGame(bool &x);
	/*void resetGame(); //thuc hien thiet lap lai toan bo du lieu luc dau
	void exitGame(); //thuc hien thoat thread
	void loadGame();
	void saveGame();
	void pauseGame();*/
	//void resumeGame(bool &x);
	void updatePosPeople(char x); //thuc hien dieu khien di chuyen cua cPeople
	//void updatePosVehicle(); //Thuc hien cho truck & car di chuyen 
	void updatePosAnimal();	//Thuc hien cho dinausor & bird di chuyen
	/*-----------------------------------------------------*/
	void run(bool &is_finish);

	void exitGame(thread *t, bool &isRunning);
	
 };
void startGame(bool &reset, int lv);
void subThread(cGame *cg, bool *IS_RUNNING, bool *IS_PAUSE, bool *exitFlag);
#endif // !cGame_h

