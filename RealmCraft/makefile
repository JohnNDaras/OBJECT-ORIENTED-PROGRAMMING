all: main.o Spell.o Item.o Weapon.o Armor.o Potion.o FireSpell.o IceSpell.o LightingSpell.o Living.o Hero.o Warrior.o Sorcerer.o Paladin.o Monster.o Dragon.o Exoskeleton.o Spirit.o Square.o Grid.o Game.o mygame


main.o: main.cpp
	g++ -c main.cpp -o main.o 

Spell.o: Spell.cpp
	g++ -c Spell.cpp -o Spell.o 

Item.o: Item.cpp
	g++ -c Item.cpp -o Item.o 

Weapon.o: Weapon.cpp
	g++ -c Weapon.cpp -o Weapon.o 

Armor.o: Armor.cpp
	g++ -c Armor.cpp -o Armor.o 

Potion.o: Potion.cpp
	g++ -c Potion.cpp -o Potion.o 

FireSpell.o: FireSpell.cpp
	g++ -c FireSpell.cpp -o FireSpell.o 

IceSpell.o: IceSpell.cpp
	g++ -c IceSpell.cpp -o IceSpell.o 

LightingSpell.o: LightingSpell.cpp
	g++ -c LightingSpell.cpp -o LightingSpell.o 

Living.o: Living.cpp
	g++ -c Living.cpp -o Living.o 

Hero.o: Hero.cpp
	g++ -c Hero.cpp -o Hero.o 

Warrior.o: Warrior.cpp
	g++ -c Warrior.cpp -o Warrior.o 

Sorcerer.o: Sorcerer.cpp
	g++ -c Sorcerer.cpp -o Sorcerer.o 

Paladin.o: Paladin.cpp
	g++ -c Paladin.cpp -o Paladin.o 

Monster.o: Monster.cpp
	g++ -c Monster.cpp -o Monster.o 

Dragon.o: Dragon.cpp
	g++ -c Dragon.cpp -o Dragon.o 

Exoskeleton.o: Exoskeleton.cpp
	g++ -c Exoskeleton.cpp -o Exoskeleton.o 

Spirit.o: Spirit.cpp
	g++ -c Spirit.cpp -o Spirit.o 

Square.o: Square.cpp
	g++ -c Square.cpp -o Square.o 

Grid.o: Grid.cpp
	g++ -c Grid.cpp -o Grid.o 

Game.o: Game.cpp
	g++ -c Game.cpp -o Game.o 




mygame: Spell.h  Spell.o Item.h  Item.o Weapon.h  Weapon.o Armor.h  Armor.o Potion.h  Potion.o FireSpell.h  FireSpell.o IceSpell.h  IceSpell.o LightingSpell.h LightingSpell.o Living.h Living.o Hero.h  Hero.o Warrior.h  Warrior.o Sorcerer.h  Sorcerer.o Paladin.h  Paladin.o Monster.h  Monster.o Dragon.h  Dragon.o Exoskeleton.h  Exoskeleton.o  Spirit.h  Spirit.o Square.h  Square.o Grid.h  Grid.o Game.h  Game.o  main.cpp
	g++ -o mygame Spell.o Item.o Weapon.o Armor.o Potion.o FireSpell.o IceSpell.o LightingSpell.o Living.o Hero.o Warrior.o Sorcerer.o Paladin.o Monster.o Dragon.o Exoskeleton.o  Spirit.o Square.o Grid.o Game.o  main.cpp 

	
splint:
	splint Spell.cpp Item.cpp Weapon.cpp Armor.cpp Potion.cpp FireSpell.cpp IceSpell.cpp LightingSpell.cpp Living.cpp Hero.cpp Warrior.cpp Sorcerer.cpp Paladin.cpp Monster.cpp Dragon.cpp Exoskeleton.cpp  Spirit.cpp Square.cpp Grid.cpp Game.cpp  
	
run:
	./mygame
	
clean:
	rm mygame *.o -f 
	
	
