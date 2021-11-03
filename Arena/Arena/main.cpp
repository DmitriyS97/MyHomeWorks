#include<iostream>
#include<string>
#include"character.h"
#include"inventory.h"
#include"functions.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Character player, enemy;
	Character* ptr_player = &player;
	Character* ptr_enemy = &enemy;
	Inventory inventory;

	ptr_player->setAtributes(false);	
	//ptr_player->showInfo();
	//inventory.startEquip(ptr_player);
	
	ptr_enemy->setAtributes(true);
	inventory.startEquip(ptr_enemy);	
	//ptr_enemy->showInfo();

	//showPlEnInfo(ptr_player, ptr_enemy);
	

	
	return 0;
}