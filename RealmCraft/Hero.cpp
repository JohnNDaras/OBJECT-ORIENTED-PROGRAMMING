#include "Hero.h"

Hero::Hero():Living(){
	magicPower = 0;
	strength = 0;
	dexterity = 0;
	agility = 0;
	money = 0;
	experience = 0;
	//normal factors for abilities levels
	pc_hero[0] = 1.1;
	pc_hero[1] = 1.25;
	pc_hero[2] = 1.6;
	pc_hero[3] = 1.8;
	pc_hero[4] = 2.0;
	//increased factors for abilities levels
	pc_up[0] = 2.2;
	pc_up[1] = 2.5;
	pc_up[2] = 3.2;
	pc_up[3] = 3.6;
	pc_up[4] = 4.0;
	armor = NULL;
	potion = NULL;
	weapon = NULL;
}
Hero::Hero(string n, int l, double hp, double mp, double st, double de, double ag, double mo, double ex):Living(n, l ,hp){
	
	magicPower = mp;
	strength = st;
	dexterity = de;
	agility = ag;
	money = mo;
	experience = ex;
	pc_hero[0] = 1.1;
	pc_hero[1] = 1.25;
	pc_hero[2] = 1.6;
	pc_hero[3] = 1.8;
	pc_hero[4] = 2.0;
	pc_up[0] = 2.2;
	pc_up[1] = 2.5;
	pc_up[2] = 3.2;
	pc_up[3] = 3.6;
	pc_up[4] = 4.0;
	armor = NULL;
	potion = NULL;
	weapon = NULL;
}
void Hero::setMagicPower(double x){
	magicPower = x;
}
void Hero::setStrength(double x){
	strength = x;
}
void Hero::setDexterity(double x){
	dexterity = x;
}
void Hero::setAgility(double x){
	agility = x;
}
void Hero::setMoney(double x){
	money = x;
}
void Hero::setExperience(double x){
	experience = x;
	//change level if necessary
	levelUp();
}
double Hero::getMagicPower(){
	return magicPower;
}
double Hero::getStrength(){
	return strength;
}
double Hero::getDexterity(){
	return dexterity;
}
double Hero::getAgility(){
	return agility;
}
double Hero::getMoney(){
	return money;
}
double Hero::getExperience(){
	return experience;
}

void Hero::setArmor(Armor *a){
	armor = a;
}

void Hero::setWeapon(Weapon *w){
	weapon = w;
}
void Hero::setPotion(Potion *p){
	potion = p;
}
Armor *Hero::getArmor(){
	return armor;
}
Weapon *Hero::getWeapon(){
	return weapon;
}
Potion *Hero::getPotion(){
	return potion;
}
//level is computed depended on 
//experience value.
//there are 5 levels
void Hero::levelUp(){
	double pc = 0;
	int update = 0;
	if (experience > LEVEL_E){
		if (level < 5){
			update = 1;
		}
		level = 5;
	}
	else if (experience > LEVEL_D){
		if (level < 4){
			update = 1;
		}
		level = 4;
	}
	else if (experience > LEVEL_C){
		if (level < 3){
			update = 1;
		}
		level = 3;
	}
	else if (experience > LEVEL_B){
		if (level < 2){
			update = 1;
		}
		level = 2;
	}
	else if (experience > LEVEL_A){
		if (level < 1){
			update = 1;
		}
		level = 1;
	}
	if (update == 1){
		strength = pc_hero[level-1] * strength;
		dexterity = pc_hero[level-1] * dexterity;
		agility = pc_hero[level-1] * agility;
	}
}
//W is the direction
//G is the grid
//checking if movment is feasible and if so it is done
int Hero::move(int W, Grid *G){
	if (W == RIGHT){
		//Hero is allready to the RIGHT edge
		if (G->getX()==this->getPosition()->getX()){
			cout << "Right move rejected (RIGHT EDGE)" << endl;
			return 0;
		}
		else if (G->getContent(this->getPosition()->getX()+1, this->getPosition()->getY())->getAccessible()==0){
			cout << "Right move rejected (RESTRICTED LOCATION)" << endl;
			return 0;
		}
		else {
			this->setPosition(G->getContent(this->getPosition()->getX()+1, this->getPosition()->getY()));
			cout << "Moved Right" << endl;
			return 1;
		}
	}
	else if (W == LEFT){
		//Hero is allready to the LEFT edge
		if (this->getPosition()->getX()==0){
			cout << "Left move rejected (LEFT EDGE)" << endl;
			return 0;
		}
		//The down location is not accessible
		else if (G->getContent(this->getPosition()->getX()-1, this->getPosition()->getY())->getAccessible()==0){
			cout << "Left move rejected (RESTRICTED LOCATION)" << endl;
			return 0;
		}
		//move completed
		else {
			this->setPosition(G->getContent(this->getPosition()->getX()-1, this->getPosition()->getY()));
			cout << "Moved Left" << endl;
			return 1;
		}
	}
	else if (W == DOWN){
		//Hero is allready to the DOWN edge
		if (this->getPosition()->getY()==0){
			cout << "Down move rejected (DOWN EDGE)" << endl;
			return 0;
		}
		//The down location is not accessible
		else if (G->getContent(this->getPosition()->getX(), this->getPosition()->getY()-1)->getAccessible()==0){
			cout << "Down move rejected (RESTRICTED LOCATION)" << endl;
			return 0;
		}
		//move completed
		else {
			this->setPosition(G->getContent(this->getPosition()->getX(), this->getPosition()->getY()-1));
			cout << "Moved Down" << endl;
			return 1;
		}
	}
	else if (W == UP){
		//Hero is allready to the UP edge
		if (this->getPosition()->getY()==G->getY()){
			cout << "Up move rejected (DOWN EDGE)" << endl;
			return 0;
		}
		//The down location is not accessible
		else if (G->getContent(this->getPosition()->getX(), this->getPosition()->getY()+1)->getAccessible()==0){
			cout << "Up move rejected (RESTRICTED LOCATION)" << endl;
			return 0;
		}
		//move completed
		else {
			this->setPosition(G->getContent(this->getPosition()->getX(), this->getPosition()->getY()+1));
			cout << "Moved Up" << endl;
			return 1;
		}
	}
	return 1;
}

int Hero::buy(Item *i){
	//if hero is on a market cell and the item is on the same cell then he can make a buy request
	if ((this->getPosition()->getMarket() == 1)&&(getPosition()->getY()==i->getPosition()->getY())&&(getPosition()->getX()==i->getPosition()->getX())){
		//not enough momey to buy the item
		if (this->money<i->getPrice()){
			cout << "Not enough money to buy it" << endl;
			return 0;
		}
		//not for hero's current level
		else if (this->level<i->getLevel()){
			cout << "Higher level item" << endl;
			return 0;
		}
		//it bellongs to someone else
		else if (i->getOwner()!="-"){
			cout << "It belongs to someone" << endl;
			return 0;
		}
		//there is no problem to fulfill the buy request
		else {
			cout << "OK" << endl;
			this->money -= i->getPrice();
			i->setPrice(i->getPrice()/2);
			return 1;
		}
	}
	return 0;
}

int Hero::sell(Item *i){
	if (this->getPosition()->getMarket() == 1){
		if (name == i->getOwner()){
			money+i->getPrice();
			i->setPrice(2*i->getPrice());
			i->setOwner("-");
			return 1;
		}
		else {
			cout << "Error on owner" << endl;
			return 0;
		}
	}
	else {
		cout << "Hero must be on market area to sell" << endl;
		return 0;
	}
}
//printing items from the items set belonging to hero details 
void Hero::checkInventory(Item *items[], int size){
	int i;
	for (i=0;i<size;i++){
		items[i]->printDetails();
	}
}
//change armor and weapon
void Hero::equip(Armor *a, Weapon *w){
	if (a != NULL){
		armor = a;
	}
	if (w != NULL){
		weapon = w;
	}
}
//Use potion
void Hero::use(){
	if (potion != NULL){
		if (potion->getStatistic() == "agility"){
			agility+=potion->getAmount();
		}
		else if (potion->getStatistic() == "strength"){
			strength+=potion->getAmount();
		}
		else if (potion->getStatistic() == "dexterity"){
			dexterity+=potion->getAmount();
		}
	}
}
//searching armor by its name
void Hero::setArmorByName(string s, Armor *a[], int size){
	int i;
	for (i=0; i<size; i++){
		if ((a[i]->getDescription() == s) && (a[i]->getDescription() == this->name)){
			armor = a[i];
			break;
		}
	}
}
//searching weapon by its name
void Hero::setWeaponByName(string s, Weapon *w[], int size){
	int i;
	for (i=0; i<size; i++){
		if ((w[i]->getDescription() == s) && (w[i]->getDescription() == this->name)){
			weapon = w[i];
			break;
		}
	}
}
//searching potion by name
void Hero::setPotionByName(string s, Potion *p[], int size){
	int i;
	for (i=0; i<size; i++){
		if ((p[i]->getDescription() == s) && (p[i]->getDescription() == this->name)){
			potion = p[i];
			break;
		}
	}
}
//displays hero stats
void Hero::displayHeroStats(){
	displayStats();
	cout << "Magic:" << magicPower << endl;
	cout << "Strength:" << strength << endl;
	cout << "Dexterity" << dexterity << endl;
	cout << "Agility:" << agility << endl;
	cout << "Money:" << money << endl;
	cout << "Experience:" << experience << endl;
	
}
		
