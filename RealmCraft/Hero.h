#ifndef HERO_H
#define HERO_H

#define LEVEL_A 10
#define LEVEL_B 20
#define LEVEL_C 40
#define LEVEL_D 70
#define LEVEL_E 100



#include <iostream>
#include <string>


#include "Square.h"
#include "Grid.h"
#include "Living.h"
#include "Item.h"

#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"

using namespace std;

class Hero : public Living{
	protected :
		double pc_hero[5];
		double pc_up[5];
		double magicPower;
		double strength;
		double dexterity;
		double agility;
		double money;
		double experience;
		Armor *armor;
		Weapon *weapon;
		Potion *potion;
	public :
		Hero();
		Hero(string n, int l, double hp, double mp, double st, double de, double ag, double mo, double ex);
		void setMagicPower(double x);
		void setStrength(double x);
		void setDexterity(double x);
		void setAgility(double x);
		void setMoney(double x);
		void setExperience(double x);
		void setArmor(Armor *a);
		void setWeapon(Weapon *w);
		void setPotion(Potion *p);
		
		void setArmorByName(string s, Armor *a[], int size);
		void setWeaponByName(string s, Weapon *w[], int size);
		void setPotionByName(string s, Potion *p[], int size);
		
		double getMagicPower();
		double getStrength();
		double getDexterity();
		double getAgility();
		double getMoney();
		double getExperience();
		Armor *getArmor();
		Weapon *getWeapon();
		Potion *getPotion();
		void levelUp();
	
		//buying the i item
		int buy(Item *i);
		//selling the i item
		int sell(Item *i);
		//printing items from the items set belonging to hero details 
		void checkInventory(Item *items[], int size);
		//change armor and weapon
		void equip(Armor *a, Weapon *w);
		//Use potion
		void use();
		//making W movement in G grid
		int move(int W, Grid *G);
		
		void displayHeroStats();
	};

#endif
