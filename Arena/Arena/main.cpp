#include<iostream>
#include<string>


using namespace std;
int getRandomNumber(int min, int max)
{	
	return rand() % (max - min + 1) + min;
}
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

class Character
{	
public:
	Weapon weapon;
	Shield shield;
	Armor armor;
	int strenght = getRandomNumber(10,20);
	int dexterity = getRandomNumber(10, 20);
	int HP = getRandomNumber(150, 250);
	int stamina = getRandomNumber(90, 120);	
	int dodge = getRandomNumber(5, 20);	
	int defens = 0;
	
	void showInfo()
	{
		cout << "Attributes:" << endl;
		cout <<"Strengt: "<< strenght << endl;
		cout << "Dexterity: " << dexterity << endl;
		cout << "HP: " << HP << endl;
		cout << "stamina: " << stamina << endl;
		cout << "dodge: " << dodge << endl;
		cout << "defens: " << defens << endl<<endl;
		cout << "Equipment:"<< endl;
		cout << "Weapon " << weapon.name << " damage: " << weapon.min_damage << "-" << weapon.max_damage << endl;
		cout <<"Shield: "<< shield.name << " Armor: " << armor.name << endl << endl;
	}
};
class Inventory
{
public:
	void startEquip(Character* ptrCharInv)
	{
		getWeapon(ptrCharInv);
		getShield(ptrCharInv);
		getArmor(ptrCharInv);
		ptrCharInv->defens = ptrCharInv->shield.defens + ptrCharInv->armor.defense;
	}
private:
	void getWeapon(Character* ptrCharInv)
	{
		cout << "Choose weapon:\n";
		cout << "1) Sword (damage: 7, stamina: -5, accurcy: 80)\n";
		cout << "2) Dagger (damage: 5, stamina: -2, accurcy: 95)\n";
		int answer=0;
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
	void getShield(Character* ptrCharInv)
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
	void getArmor(Character* ptrCharInv)
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
};

int main()
{
	srand(static_cast<unsigned int>(time(0)));	
	bool check = false;
	while (check == false)
	{
		system("cls");
		Character player;
		Character* ptr_player = &player;
		Inventory inventory;
		cout << "Your fighter: \n";
		ptr_player->showInfo();
		cout << "Take equipment:" << endl;
		inventory.startEquip(ptr_player);
		system("cls");
		ptr_player->showInfo();
		cout << "Are you ready?\n";
		cout << "1 - Next 2 - Create new fighter"<<endl;
		int answer=0;
		cin >> answer;
		if (answer == 1) check = true;
		if (answer == 2) check = false;
	}
	
	return 0;
}