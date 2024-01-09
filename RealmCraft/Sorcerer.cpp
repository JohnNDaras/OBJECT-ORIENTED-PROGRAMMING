#include "Sorcerer.h"

Sorcerer::Sorcerer():Hero(){
	
	magicPower = 0;
	strength = 0;
	dexterity = 0;
	agility = 0;
	money = 0;
	experience = 0;
}
Sorcerer::Sorcerer(string n, int l, double hp, double mp, double st, double de, double ag, double mo, double ex):Hero(n, l ,hp,mp,st,de,ag,mo,ex){
	
	magicPower = mp;
	strength = st;
	dexterity = de;
	agility = ag;
	money = mo;
	experience = ex;
}

void Sorcerer::levelUp(){
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
		dexterity = pc_up[level-1] * dexterity;
		agility = pc_up[level-1] * agility;
	}
}
