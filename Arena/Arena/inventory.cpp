#include<iostream>
#include"inventory.h"

using namespace std;

void Inventory::startEquip(Character* ptrCharInv)
{
	getWeapon(ptrCharInv);
	getShield(ptrCharInv);
	getArmor(ptrCharInv);
	ptrCharInv->defens = ptrCharInv->shield.defens + ptrCharInv->armor.defense;
}
void Inventory::getWeapon(Character* ptrCharInv)
{
	cout << "Choose weapon:\n";
	cout << "1) Sword (damage: 7, stamina: -5, accurcy: 80)\n";
	cout << "2) Dagger (damage: 5, stamina: -2, accurcy: 95)\n";
	int answer = 0;
	while (answer == 0)
	{
		cin >> answer;
		if (answer == 1)
		{
			ptrCharInv->weapon.name = "Sword";
			ptrCharInv->weapon.min_damage = 5;
			ptrCharInv->weapon.max_damage = 10;
			ptrCharInv->weapon.accurcy = 80;
			ptrCharInv->weapon.staminaCost = 5;
			return;
		}
		else if (answer == 2)
		{
			ptrCharInv->weapon.name = "Dagger";
			ptrCharInv->weapon.min_damage = 3;
			ptrCharInv->weapon.max_damage = 7;
			ptrCharInv->weapon.accurcy = 95;
			ptrCharInv->weapon.staminaCost = 2;
			return;
		}
		else
		{
			cout << "Inncorect nomber. Try againg\n";
			answer = 0;
		}
	}
}
void Inventory::getShield(Character* ptrCharInv)
{
	cout << "Choose shield:\n";
	cout << "1) Shield (defens: +5)\n";
	cout << "2) Dont take)\n";
	int answer = 0;
	while (answer == 0)
	{
		cin >> answer;
		if (answer == 1)
		{
			ptrCharInv->shield.name = "Shield";
			ptrCharInv->shield.defens = 5;
			return;
		}
		else if (answer == 2)
		{
			return;
		}
		else
		{
			cout << "Inncorect nomber. Try againg\n";
			answer = 0;
		}
	}
}
void Inventory::getArmor(Character* ptrCharInv)
{
	cout << "Choose armor:\n";
	cout << "1) Light Armor (defens: +5)\n";
	cout << "2) Medium Armor (defens: +10)\n";
	cout << "3) Heavy Armor (defens: +15)\n";
	int answer = 0;
	while (answer == 0)
	{
		cin >> answer;
		if (answer == 1)
		{
			ptrCharInv->armor.name = "Light Armor";
			ptrCharInv->armor.defense = 5;
			return;
		}
		else if (answer == 2)
		{
			ptrCharInv->armor.name = "Medium Armor";
			ptrCharInv->armor.defense = 10;
			return;
		}
		else if (answer == 3)
		{
			ptrCharInv->armor.name = "Heavy Armor";
			ptrCharInv->armor.defense = 15;
			return;
		}
		else
		{
			cout << "Inncorect nomber. Try againg\n";
			answer = 0;
		}
	}
}