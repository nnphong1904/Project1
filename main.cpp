#include"cAnimals.h"
#include"cGame.h"
#include"Console.h"
//Old Version
/*char MOVE;
bool IS_RUNNING = true;
bool exitFlag = false;
bool IS_PAUSE = false;
cGame cg;
void exitGame(thread *t) {
	IS_RUNNING = false;
	t->join();
}
void subThread() {
	cg.drawGame();
	while (IS_RUNNING && cg.getPeople().isDead() == false) {
	  if (IS_PAUSE==false){
		cg.updatePosAnimal();
		if (cg.getPeople().isImpact(cg.getAnimal(), 6) == true) {
			exitFlag = true;
			GotoXY(45, 15);
			cout << "YOU ARE DEAD!!" << endl;
			GotoXY(45, 16);
			cout << "Press ENTER to exit." << endl;
		}
	  }
	  else {
		  while (IS_PAUSE){}
	  }
	}
}
*/
void main() {
	bool reset=false;

	FixConsoleWindow();
	do {
		startGame(reset,0);
	} while (reset);
	
	
	/*thread t1(subThread);
	int tmp;
	while (IS_RUNNING) {
		if (exitFlag == true) {
			cg.getPeople().updateState(false);
			exitGame(&t1);
			return;
		}
		if (!cg.getPeople().isDead())
			{
				tmp = toupper(_getch());

					if (tmp == 27) {
						exitGame(&t1);
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
						cg.updatePosPeople(MOVE);
				
			
			}
		}
	*/
	system("pause");
}