#pragma once
#include"inventory.h"
#include"functions.h"

class Character
{
public:
	Weapon weapon;
	Shield shield;
	Armor armor;
	int strenght;
	int dexterity;
	int HP;
	int stamina;
	int dodge;
	int defens;	
	bool bot;

	void setAtributes(bool isBot);
	void showInfo();	
};
