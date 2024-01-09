#include <iostream>
#include "Game.h"

int main(int argc, char** argv) {
	int i;
	//constructing a new game
	Game *G = new Game();
	//initialize game
	G->initGame();
	//running sample for 10 rounds
	for (i=0;i<10;i++){
		//all elements move
		G->makeMovementsForAll();
		//a new status of the game has been formed
		G->checkNewStatus();
		//viewing game stats after the new status completed
		G->viewAllStats();
	}	
	return 0;
}
