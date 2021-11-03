#include"functions.h"
#include<iostream>
#include<iomanip>

using namespace std;
int getRandomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
void showPlEnInfo(Character* player, Character* enemy)
{
	cout << left << setw(20) << "Your fighter: " << left << setw(6) << "|" << "Enemy fighter:" << endl;
	cout << "Strengt "<< left << setw(12) << player->strenght << left << setw(6) << "|" << "Strengt " << enemy->strenght << endl;
	cout << "Dexterity " << left << setw(10) << player->dexterity << left << setw(6) << "|" << "Dexterity " << enemy->dexterity << endl;
	cout << "HP " << left << setw(17) << player->HP << right << left << setw(6) << "|" << "HP " << enemy->HP << endl;
	cout << "Stamina " << left << setw(16) << player->stamina << left << setw(6) << "|" << "Stamina " << enemy->stamina << endl;
	cout << "Defens " << left << setw(16) << player->defens << left << setw(6) << "|" << "Defens " << enemy->defens << endl;
	cout << "Dodge " << left << setw(16) << player->dodge << left << setw(6) << "|"<< "Dodge " << enemy->dodge << endl;
	cout << "Damage " << player->weapon.min_damage<<"-"<< left << setw(16)<<player->weapon.max_damage << left << setw(6) << "|"
		<< "Damage " << enemy->weapon.min_damage << "-" << enemy->weapon.max_damage<<endl;

	for (int i = 0; i < 10; i++)
	{
		
	}
}