#pragma once
#include "character.h"
#include<string>

struct Weapon
{
	string name = "Hands";
	int min_damage = 1;
	int max_damage = 1;
	int staminaCost = 1;
	int accurcy = 100;
};
struct Armor
{
	string name = "Nothing";
	int defense = 0;
};
struct Shield
{
	string name = "Nothing";
	int defens = 0;
};
class Inventory
{
public:
	void startEquip(Character* ptrCharInv);
	
private:
	void getWeapon(Character* ptrCharInv);	
	void getShield(Character* ptrCharInv);	
	void getArmor(Character* ptrCharInv);	
};
