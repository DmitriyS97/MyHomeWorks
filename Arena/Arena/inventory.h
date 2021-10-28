#pragma once
#include <string>

struct Weapon
{
	std::string name = "Hands";
	int min_damage = 1;
	int max_damage = 1;
	int staminaCost = 1;
	int accurcy = 100;
};

struct Armor
{
	std::string name = "Nothing";
	int defense = 0;
};

struct Shield
{
	std::string name = "Nothing";
	int defens = 0;
};

class Character;
class Inventory
{
public:
	void startEquip(Character* ptrCharInv);
	
private:
	void getWeapon(Character* ptrCharInv);	
	void getShield(Character* ptrCharInv);	
	void getArmor(Character* ptrCharInv);	
};
