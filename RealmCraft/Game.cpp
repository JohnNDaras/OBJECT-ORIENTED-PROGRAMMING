#include "Game.h"

using namespace std;

Game::Game(){
	srand (time(NULL));
}
void Game::initGame(){
	cout << "Making Grid " << endl;
	makeGrid(GRID_X, GRID_Y, NUMBER_OF_MARKETS, NUMBER_OF_NONACCESSIBLE);
	
	cout << "Making Items " << endl;
	addItems(NUMBER_OF_POTION, NUMBER_OF_ARMOR, NUMBER_OF_WEAPON);
	
	cout << "Making Heros " << endl;
	addHeros(NUMBER_OF_WARRIORS, NUMBER_OF_SORCERERS, NUMBER_OF_PALADINS);
	
	cout << "Making Monsters " << endl;
	addMonsters(NUMBER_OF_DRAGONS, NUMBER_OF_EXOSKELETON, NUMBER_OF_SPIRITS);
	
	displayMap();
}
void Game::makeGrid(int x, int y, int marketCells, int nonaccessiblecells){
	int i;
	int tempx, tempy;
	Square *s;
	//Creating grid
	grid = new Grid(x, y);
	cout << "Adding Market Cells" << endl;
	//Creating market cells
	for (i = 0; i < marketCells; i++){
		tempx = rand() % x;
		tempy = rand() % y;
		s = grid->getContent(tempx, tempy);
		while ((s->getMarket()==1)){
			tempx = rand() % x;
			tempy = rand() % y;
			s = grid->getContent(tempx, tempy);
		}
		s->setMarket(1);
	}
	cout << "Adding Non Accessible Cells" << endl;
	//Creating non accessible cells
	for (i = 0; i < nonaccessiblecells; i++){
		tempx = rand() % x;
		tempy = rand() % y;
		s = grid->getContent(tempx, tempy);
		while ((s->getMarket()==1) || (s->getAccessible()==0)){
			tempx = rand() % x;
			tempy = rand() % y;
			s = grid->getContent(tempx, tempy);
		}
		s->setAccessible(0);
	}
}
void Game::addItems(int potionsNumber, int armorsNumber, int weaponsNumber){
	int i;
	itemsCounter = 0;
	items = new Item*[potionsNumber+armorsNumber+weaponsNumber];
	string s[3];
	s[0] = "agility";
	s[1] = "strength";
	s[2] = "dexterity";
	for (i=0;i<potionsNumber; i++){
		Potion *p;
		stringstream ts;
		ts << "POTION" << i;
		p = new Potion(ts.str(),10.0,(i+1)%5,s[i%3],25.0); 
		p->setPosition(grid->getContent(0,itemsCounter));
		items[itemsCounter++] = p;
	}
	
	for (i=0;i<armorsNumber; i++){
		Armor *a;
		stringstream ts;
		ts << "ARMOR" << i;
		a = new Armor(ts.str(),25.0,(i+1)%5,10);
		a->setPosition(grid->getContent(1,itemsCounter));
		items[itemsCounter++] = a;
	}
	
	for (i=0;i<weaponsNumber; i++){
		Weapon *w;
		stringstream ts;
		ts << "WEAPON" << i;
		w = new Weapon(ts.str(),30.0,(i+1)%5,10.0,i%2 + 1);
		w->setPosition(grid->getContent(2,itemsCounter));
		items[itemsCounter++] = w;
	}
}
void Game::addHeros(int warriorsNumber, int sorcerrerNumber, int paladinsNumber){
	int i;
	heroCounter = 0;
	heros = new Hero*[warriorsNumber+sorcerrerNumber+paladinsNumber];
	for (i=0;i<warriorsNumber; i++){
		Warrior *w;
		stringstream ts;
		ts << "WARRIOR" << i;
		w = new Warrior(ts.str(),0,100,100,50,50,50,50,50); 
		w->setPosition(grid->getContent(3,heroCounter));
		heros[heroCounter++] = w;
	}
	
	for (i=0;i<sorcerrerNumber; i++){
		Sorcerer *s;
		stringstream ts;
		ts << "SORCERER" << i;
		s = new Sorcerer(ts.str(),0,100,100,50,50,50,50,50); 
		s->setPosition(grid->getContent(4,heroCounter));
		heros[heroCounter++] = s;
	}
	
	for (i=0;i<paladinsNumber; i++){
		Paladin *p;
		stringstream ts;
		ts << "PALADIN" << i;
		p = new Paladin(ts.str(),0,100,100,50,50,50,50,50); 
		p->setPosition(grid->getContent(5,heroCounter));
		heros[heroCounter++] = p;
	}
}
void Game::addMonsters(int dragonsNumber, int exoskelletonNumber, int spiritsNumber){
	int i;
	monsterCounter = 0;
	monsters = new Monster*[dragonsNumber+exoskelletonNumber+exoskelletonNumber];
	for (i=0;i<dragonsNumber; i++){
		Dragon *d;
		stringstream ts;
		ts << "DRAGON" << i;
		d = new Dragon(ts.str(),0,100,50,50,50); 
		d->setPosition(grid->getContent(6,monsterCounter));
		monsters[monsterCounter++] = d;
	}
	
	for (i=0;i<exoskelletonNumber; i++){
		Exoskeleton *e;
		stringstream ts;
		ts << "EXO" << i;
		e = new Exoskeleton(ts.str(),0,100,50,50,50);
		e->setPosition(grid->getContent(8,monsterCounter)); 
		monsters[monsterCounter++] = e;
	}
	
	for (i=0;i<spiritsNumber; i++){
		Spirit *s;
		stringstream ts;
		ts << "SPIRIT" << i;
		s = new Spirit(ts.str(),0,100,50,50,50); 
		s->setPosition(grid->getContent(9,monsterCounter));
		monsters[monsterCounter++] = s;
	}
}
void Game::quitGame(){
	
}

void Game::displayMap(){
	int i,j;
	for (i=0;i<grid->getX();i++){
		for (j=0;j<grid->getY();j++){
			grid->getContent(i, j)->view();
			viewCellContents(i, j);
		}	
	}
}

void Game::viewCellContents(int x, int y){
	int i;
	cout << "Contents" << endl;
	for (i=0;i<itemsCounter;i++){
		if ((items[i]->getPosition()->getX() == x) && (items[i]->getPosition()->getY() == y)){
			cout << items[i]->getDescription();
		}
	}
	for (i=0;i<heroCounter;i++){
		
		if ((heros[i]->getPosition()->getX() == x) && (heros[i]->getPosition()->getY() == y)){
			cout << heros[i]->getName();
		}
	}
	for (i=0;i<monsterCounter;i++){
		
		if ((monsters[i]->getPosition()->getX() == x) && (monsters[i]->getPosition()->getY() == y)){
			cout << monsters[i]->getName();
		}
	}
	cout << endl << " - - - - - " << endl << endl;
}

void Game::allRoundsBattle(Monster *m, Hero *h, int attacker){
	int i;
	int maxRounds = 100;
	for (i=maxRounds;i>0;i--){
		battleRound(m,h,attacker);
		if (endOfBattle(m,h)){
			break;
		}
	}
}

int Game::endOfBattle(Monster *m, Hero *h){
	if ((m->getHealthPower()<=0) || (h->getHealthPower()<=0)){
		return 1;
	}
	else {
		return 0;
	}
}
/*
After a set of movements, check if there are pairs monster - hero on the same cell
If so then a battle occurs
*/
void Game::checkNewStatus(){
	int i,j;
	/*
	Check all pairs of monster - hero
	*/
	for (i=0;i<heroCounter;i++){
		for (j=0;j<monsterCounter;j++){
			if ((heros[i]->getPosition()->getX()==monsters[j]->getPosition()->getX())&&(heros[i]->getPosition()->getY()==monsters[j]->getPosition()->getY())){
				cout << "We have battle" << endl;
				allRoundsBattle(monsters[j], heros[i], rand()%2);
			}
		}
	}
}

void Game::battleRound(Monster *m, Hero *h, int attacker){
	int m_pos;
	int h_pos;
	//computing the posibilities for winning monster or hero
	//Monster Attack
	if (attacker == 1){
		m_pos = 10;
		h_pos = 0;
		if (m->getLevel() > h->getLevel()){
			m_pos +=15;
			h_pos +=5;
		}
		else {
			m_pos += 5;
			h_pos += 15;
		}
	}
	//Hero Attack
	else {
		m_pos = 0;
		h_pos = 10;
		if (m->getLevel() > h->getLevel()){
			m_pos +=15;
			h_pos +=5;
		}
		else {
			m_pos += 5;
			h_pos += 15;
		}
	}
	int x = rand()%70;
	m_pos = x;
	h_pos = 70-x;
	//MONSTER WINS
	if (m_pos > h_pos){
		//hero loses halh money
		h->setMoney(h->getMoney()/2);
		//hero loses health power depending on monster's level
		h->setHealthPower(h->getHealthPower()-m->getDamage());
	}
	else {
		//hero earns money depending on monster's level
		h->setMoney(h->getMoney()*(m->getLevel()+1)/5);
		//hero increases experience depending on monster's level
		h->setExperience(h->getExperience()*(m->getLevel()+1)/5);
		//monster loses health power depending on hero's strength
		m->setHealthPower(h->getHealthPower()-h->getStrength());
	}
	//both monster and hero regain the 10% of their health power
	if (m->getHealthPower()>=0){
		m->setHealthPower(m->getHealthPower()*1.1);
	}
	else {
		m->setHealthPower(10);
	}
	if (h->getHealthPower()>=0){
		h->setHealthPower(h->getHealthPower()*1.1);
	}
	else {
		h->setHealthPower(10);
	}
}

void Game::makeMovementsForAll(){
	int i;
	for (i=0;i<monsterCounter;i++){
		monsters[i]->move(rand()%4,grid);
	}
	for (i=0;i<heroCounter;i++){
		heros[i]->move(rand()%4,grid);
	}
}

void Game::viewAllStats(){
	int i;
	for (i=0;i<monsterCounter;i++){
		monsters[i]->displayMonsterStats();
	}
	for (i=0;i<heroCounter;i++){
		heros[i]->displayHeroStats();
	}
}
