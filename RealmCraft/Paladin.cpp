#include "Paladin.h"

Paladin::Paladin():Hero(){
	

	pc_warrior[0] = 2.2;
	pc_warrior[1] = 2.5;
	pc_warrior[2] = 3.2;
	pc_warrior[3] = 3.6;
	pc_warrior[4] = 4.0;
	
}
Paladin::Paladin(string n, int l, double hp, double mp, double st, double de, double ag, double mo, double ex):Hero(n, l ,hp, mp, st,de,ag,mo,ex){
	

	pc_warrior[0] = 2.2;
	pc_warrior[1] = 2.5;
	pc_warrior[2] = 3.2;
	pc_warrior[3] = 3.6;
	pc_warrior[4] = 4.0;
}

void Paladin::levelUp(){
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
		strength = pc_up[level-1] * strength;
		dexterity = pc_up[level-1] * dexterity;
		agility = pc_hero[level-1] * agility;
	}
}
