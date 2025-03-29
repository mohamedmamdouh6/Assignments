#include <iostream>
using namespace std;
// Base CLass
class Pizza {
private:
	void makeDoughPizza()
	{
		cout << "Make " << getPizzaName() << " Dough Pizza" << endl;
	}
	void bakePizza()
	{
		cout << "Bake " << getPizzaName() << " Pizza" << endl;
	}
	void addToppings()
	{
		cout << "Adding toppings for " << getPizzaName() << " Pizza" << endl;
	}
protected:
	virtual const char* getPizzaName() = 0;
public:
	void makePizza()
	{
		makeDoughPizza();
		addToppings();
		bakePizza();
	}
};
// Derived Classes
class ChickenPizza : public Pizza {
protected:
	const char* getPizzaName()
	{
		return "Chicken";
	}
};
class CheesePizza : public Pizza {
protected:
	const char* getPizzaName()
	{
		return "Cheese";
	}
};
class BeefPizza : public Pizza {
protected:
	const char* getPizzaName()
	{
		return "Beef";
	}
};
void BuyPizza(Pizza* ptr)
{
	ptr->makePizza();
}
void PizzaShop()
{
	int choice;
	cout << "Type of Pizza Available:-" << endl
	    << "1. Chicken Pizza" << endl
		<< "2. Cheese Pizza" << endl
		<< "3. Beef Pizza" << endl;
	cout << "Which One: ";
	cin >> choice;
	while (choice < 1 || choice > 3)
	{
		cout << "Invalid Choice!" << endl;
		cout << "Enter Again: ";
		cin >> choice;
	}
	Pizza* pizza = NULL;
	switch (choice)
	{
	case 1:
		pizza = new ChickenPizza;
		break;
	case 2:
		pizza = new CheesePizza;
		break;
	case 3:
		pizza = new BeefPizza;
		break;
	default:
		cout << "Incorrect choice!" << endl;
	}
	if (pizza)
	{
		BuyPizza(pizza);
		delete pizza;
	}
}
void main()
{
	char again = 'y';
	while (again == 'y' || again == 'Y')
	{
		PizzaShop();
		cout << "Would you like to order Again? (Y/n): ";
		cin >> again;
	}
}