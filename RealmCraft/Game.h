#ifndef GAME_H
#define GAME_H
/***********************************************************************

Game class has been designed in such a way for operating as a sample 
executor of this role based game.
Game functionality has been implemented by - mainly - the current 
class methods and they are running to present its fow in some extend

************************************************************************/
#include <stdlib.h>
#include <sstream>

#include "Dragon.h"
#include "Exoskeleton.h"
#include "Spirit.h"
#include "FireSpell.h"
#include "IceSpell.h"
#include "Paladin.h"
#include "Sorcerer.h"
#include "Warrior.h"
#include "Armor.h"
#include "Potion.h"
#include "Weapon.h"
#include "Grid.h"

/******************************************

Game parameters values

******************************************/

//2 items from each monster class
#define NUMBER_OF_DRAGONS 2
#define NUMBER_OF_EXOSKELETON 2
#define NUMBER_OF_SPIRITS 2
//2 items from each spell class
#define NUMBER_OF_FIRESPELLS 2
#define NUMBER_OF_ICESPESLL 2
#define NUMBER_OF_LIGHTINGSPELL 2
//1 item from each hero class
#define NUMBER_OF_PALADINS 1
#define NUMBER_OF_SORCERERS 1
#define NUMBER_OF_WARRIORS 1
//1 item from each item class
#define NUMBER_OF_ARMOR 2
#define NUMBER_OF_WEAPON 2
#define NUMBER_OF_POTION 2
//6 market cell on the 2d virtual world
#define NUMBER_OF_MARKETS 2
//14 non accessible cells
#define NUMBER_OF_NONACCESSIBLE 14
//The virtual world's size is 10X10 
#define GRID_X 10
#define GRID_Y 10

using namespace std;

class Game{
	private:
		//virtual world grid
		Grid *grid;
		//array containing pointers to item objects
		Item **items;
		//array containing pointers to heros objects
		Hero **heros;
		//array containing pointers to monster objects
		Monster **monsters;
		//the total number of items
		int itemsCounter;
		//the total number of heros
		int heroCounter;
		//the total number of monsters
		int monsterCounter;
	public:
		//constructor
		Game();
		//initializes a game
		void initGame();
		//create a grid of size xXy with marketCell market cells and nonaccessiblecells non accessible cells
		void makeGrid(int x, int y, int marketCells, int nonaccessiblecells);
		//adding items (each parameters define how many from each type) and place then on the grid
		void addItems(int potionsNumber, int armorsNumber, int weaponsNumber);
		//adding heros (each parameters define how many from each type) and place then on the grid
		void addHeros(int warriorsNumber, int sorcerrerNumber, int paladinsNumber);
		//adding monsters (each parameters define how many from each type) and place then on the grid
		void addMonsters(int dragonsNumber, int exoskelletonNumber, int spiritsNumber);
		//delete all objects and exit
		void quitGame();
		//shows details about all grids cells
		void displayMap();
		//shows the contents of the square at x,y position
		void viewCellContents(int x, int y);
		//runs a round of a battle
		void battleRound(Monster *m, Hero *h, int attacker);
		//runs a sequence of battle rounds (max has set to 100 but a round should
		//when one of the two sides run out of health. If attacker is 2 then hero 
		//attacks against monster. If attacker is 1 then monster attacks against hero
		void allRoundsBattle(Monster *m, Hero *h, int attacker);
		//returns 1 if the battle has ended
		int endOfBattle(Monster *m, Hero *h);
		//check the status for all elements of the games and updates all
		//necessary values
		void checkNewStatus();
		//it performs a set of movements for all monsters and heros on the grid
		void makeMovementsForAll();
		//shows the stats about all game elements
		void viewAllStats();
};

#endif
