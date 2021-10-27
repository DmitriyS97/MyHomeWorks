#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Product
{
	string name="";
	int price=0;
	int calorie=0;
};

struct Ingredient
{
	Product prod;
	int amount=0;
};

struct Dishes
{
	vector<Ingredient> ingredients;
	string name;
};

class Storage
{
public:
	Product prod1, prod2, prod3;
	Ingredient ingr1, ingr2, ingr3;
	vector<Ingredient> myIngr;	
	void setStorage()
	{
		prod1.name = "kolbasa";
		prod1.price = 4;
		prod1.calorie = 6;
		prod2.name = "kartoxa";
		prod2.price = 2;
		prod2.calorie = 3;
		prod3.name = "goroh";
		prod3.price = 1;
		prod3.calorie = 2;

		ingr1.prod = prod1;
		ingr1.amount = 100;
		ingr2.prod = prod2;
		ingr2.amount = 250;
		ingr3.prod = prod3;
		ingr3.amount = 100;

		myIngr.push_back(ingr1);
		myIngr.push_back(ingr2);
		myIngr.push_back(ingr3);
	}
	vector<Ingredient> getStorage()
	{
		return myIngr;
	}
	void showStorage()
	{
		for (int i = 0; i < myIngr.size(); i++)
		{
			cout << myIngr[i].prod.name << " price: " << myIngr[i].prod.price << " claories: " << myIngr[i].prod.calorie <<
				" amount: " << myIngr[i].amount << "gr \n";
		}
	}
};

class Recipe
{
public:	
	Storage products;
	void getDish(vector<Ingredient> myIngrads, vector<Ingredient> dishesIngrads)
	{
		int weight, price, kalor;
		
		
	}
	void showMenu()
	{
		cout << "1) Salat1: " << "kolbasa - 200gr, kartoxa - 500gr, gorox - 100gr\n";
		cout << "2) Salat2: " << "kolbasa - 500gr, kartoxa - 250gr\n";
		cout << "3) Salat3: " << "kolbasa - 100gr, gorox - 50gr\n";
	}

	void setMenu()
	{
		products.setStorage();
		Dishes dishes1, dishes2, dishes3;
		Ingredient ingr1, ingr2, ingr3;
		vector<Ingredient> a;
		ingr1.prod = products.prod1;
		ingr1.amount = 200;
		ingr2.prod = products.prod2;
		ingr2.amount = 500;
		ingr3.prod = products.prod3;
		ingr3.amount = 100;
		a.push_back(ingr1);
		a.push_back(ingr2);
		a.push_back(ingr3);
		dishes1.ingredients = a;
		dishes1.name = "Salat1";
		ingr1.amount = 500;
		ingr2.amount = 250;
		a.clear();
		a.push_back(ingr1);
		a.push_back(ingr2);
		dishes2.ingredients = a;
		dishes2.name = "Salat2";
		ingr1.amount = 100;
		ingr3.amount = 50;
		a.clear();
		a.push_back(ingr1);
		a.push_back(ingr3);
		dishes3.ingredients = a;
		dishes3.name = "Salat3";
		cout << "hi";
	}
};

int main()
{
	Storage sklad;
	Recipe recipes;	
	sklad.setStorage();

	sklad.showStorage();
	recipes.showMenu();
	recipes.setMenu();
	return 0;
}