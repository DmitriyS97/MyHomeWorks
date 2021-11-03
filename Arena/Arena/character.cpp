#include<iostream>
#include"character.h"
using namespace std;

void Character::setAtributes(bool isBot)
{
	bot = isBot;
	strenght = getRandomNumber(10, 20);
	dexterity = getRandomNumber(10, 20);
	HP = getRandomNumber(150, 250);
	stamina = getRandomNumber(90, 120);
	dodge = getRandomNumber(5, 20);
	defens = 0;
}
void Character::showInfo()
{
	cout << "Attributes:" << endl;
	cout << "Strengt: " << strenght << endl;
	cout << "Dexterity: " << dexterity << endl;
	cout << "HP: " << HP << endl;
	cout << "stamina: " << stamina << endl;
	cout << "dodge: " << dodge << endl;
	cout << "defens: " << defens << endl << endl;
	cout << "Equipment:" << endl;
	cout << "Weapon " << weapon.name << " damage: " << weapon.min_damage << "-" << weapon.max_damage << endl;
	cout << "Shield: " << shield.name << " Armor: " << armor.name << endl << endl;	
}

