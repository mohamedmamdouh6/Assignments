#include <iostream>
using namespace std;


void MakeTough(const char *type)
{
	cout << "Make " << type << " Tough Pizza" << endl;
}
void AddToppings(const char *type)
{
	cout << "Add " << type << " Toppings" << endl;
}
void BakePizza(const char *type)
{
	cout << "Bake " << type << " Pizza" << endl;
}
void MakeChickenPizza()
{
	MakeTough("Chicken");
	AddToppings("Chicken");
	BakePizza("Chicken");
}
void MakeCheesePizza()
{
	MakeTough("Cheese");
	AddToppings("Cheese");
	BakePizza("Cheese");
}
void MakeBeefPizza()
{
	MakeTough("Beef");
	AddToppings("Beef");
	BakePizza("Beef");
}
void BuyPizza(int choice)
{
	switch (choice)
	{
	case 1:
		MakeChickenPizza();
		break;
	case 2:
		MakeCheesePizza();
		break;
	case 3:
		MakeBeefPizza();
		break;
	}
}
void main()
{
	int choice;
	cout << "Menu: " << endl
		<< "1 for Chicken Pizza" << endl
		<< "2 for Cheese Pizza" << endl
		<< "3 for Beef Pizza" << endl
		<< "Which one: ";
	cin >> choice;
	while (choice > 3 || choice < 1)
	{
		cout << "Incorrect Choice!" << endl;
		cout << "Enter Again: ";
		cin >> choice;
	}
	BuyPizza(choice);
}