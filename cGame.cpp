#include"cGame.h"
cDinausor* cGame::getAnimal() {
	return akl;
}
cDinausor* cGame::getAnimal1() {
	return akl1;
}
cPeople cGame::getPeople() {
	return cn;
}
void cGame::drawGame() {
	drawScreen();
	cn.draw();
	int tmp = 0;
	for (int i = 0; i < 6; i++) {
		akl[i].updatePos(tmp, 6);
		akl1[i].updatePos(tmp, 4);
		tmp += 5;
	}
	
}
void cGame::updatePosPeople(char x) {
	switch (x)
	{
	case 'W':
		cn.Up();
		break;
	case 'S':
		cn.Down();
		break;
	case 'A':
		cn.Left();
		break;
	case 'D':
		cn.Right();
		break;
	default:
		break;
	}
}
void cGame::updatePosAnimal(){
	
		for (int i = 0; i < 6; i++) {
			akl[i].move();
		}

		for (int j = 0; j < 6; j++) {
			akl1[j].move();
		}
	
}
void subThread(cGame *cg, bool *IS_RUNNING, bool *IS_PAUSE, bool *exitFlag) {
		cg->drawGame();
	while (*IS_RUNNING && cg->getPeople().isDead() == false) {
		if (*IS_PAUSE == false) {
			cg->updatePosAnimal();
			if ((cg->getPeople().isImpact(cg->getAnimal(), 6) == true) || (cg->getPeople().isImpact(cg->getAnimal1(), 6) == true)) {
				*exitFlag = true;
				GotoXY(15, 15);
				cout << "YOU ARE DEAD!!" << endl;
				GotoXY(15, 16);
				cout << "PRESS ENTER ENTER" << endl;
				return ;
			}
		}
		else {
			while (*IS_PAUSE) {}
		}
	}
}
void cGame::exitGame(thread *t, bool &isRunning) {
	isRunning = false;
	t->join();
}

void cGame::run(bool &is_finish) {

	char MOVE;
	bool IS_RUNNING = true;
	bool exitFlag = false;
	bool IS_PAUSE = false;
	bool alive = true;
		thread t1(subThread,this,&IS_RUNNING,&IS_PAUSE,&exitFlag);
	int tmp;
	while (IS_RUNNING) {
		if (exitFlag == true) {
			exitGame(&t1, IS_RUNNING);			
			
		}
		if (!getPeople().isDead() && getPeople().isFinish()==false)
		{
			tmp = toupper(_getch());

			if (tmp == 27) {
				exitGame(&t1,IS_RUNNING);
			}
			if (tmp == 80) {
				if (IS_PAUSE == false) {

					IS_PAUSE = true;
					while (IS_PAUSE) {
						int tmp1 = toupper(_getch());
						if (tmp1 == 80) {
							IS_PAUSE = false;
							break;
						}
					}
				}
			}
			MOVE = tmp;
			updatePosPeople(MOVE);
		}
		else {
			is_finish = true;
			exitGame(&t1, IS_RUNNING);
		}
	}
}
void startGame(bool &reset, int lv) {
	system("cls");
	cGame cg;
	bool is_finish = false;
	cg.run(is_finish);
	if (is_finish == true) {
		GotoXY(15, 15);
		cout << "YOU WON LEVEL" << lv << endl;
		GotoXY(15, 16);
		cout << "PRESS 'n' TO CONTINUE" << endl;
		int tmp2;
		do {
			tmp2 = toupper(_getch());
		} while (tmp2 != 'N');
		if (tmp2 == 'N') {
			is_finish = false;
			startGame(reset, lv+1);
		}

	}
	else {
		system("cls");
		GotoXY(15, 15);
		cout << "PRESS Y TO PLAY AGAIN!!" << endl;
		GotoXY(15, 16);
		cout << "PRESS N TO EXIT!!" << endl;
		int tmp1;
		do {
			tmp1 = toupper(_getch());
			if (tmp1 == 'Y') {
				reset = true;
				break;
			}
			else if (tmp1 == 'N') {
				reset = false;
				break;
			}

		} while (tmp1 != 'y' && tmp1 != 'n');
	}
}