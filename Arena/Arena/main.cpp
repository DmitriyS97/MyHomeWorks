#include<iostream>
#include<string>
#include"character.h"
#include"inventory.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));	
	Character player, enemy;
	Character* ptr_player = &player;
	Character* ptr_enemy = &enemy;		
				
		/*Inventory inventory;
		ptr_player->setAtributes();
		cout << "Your fighter: \n";
		ptr_player->showInfo();
		cout << "Take equipment:" << endl;
		inventory.startEquip(ptr_player);
		system("cls");
		ptr_player->showInfo();
		cout << "Are you ready?\n";
		cout << "1 - Next 2 - Create new fighter"<<endl;	
	*/
	return 0;
}