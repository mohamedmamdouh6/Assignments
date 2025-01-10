#include <iostream>
using namespace std;

// Abstract CLass
class Pizza {
private:
	void makeToughPizza()
	{
		cout << "Make " << getPizzaName() << " Tough Pizza" << endl;
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
		makeToughPizza();
		addToppings();
		bakePizza();
	}
};

// Derived Classes
class ChickenPizza : public Pizza {
private:
	virtual const char* getPizzaName()
	{
		return "Chicken";
	}
};
class CheesePizza : public Pizza {
private:
	virtual const char* getPizzaName()
	{
		return "Cheese";
	}
};
class BeefPizza : public Pizza {
private:
	virtual const char* getPizzaName()
	{
		return "Beef";
	}
};

void BuyPizza(Pizza* ptr)
{
	ptr->makePizza();
}
void PizzaShop(Pizza *pizza, int choice)
{
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
	int choice;
	cout << "Choose: " << endl
		<< "1. Chicken Pizza" << endl
		<< "2. Cheese Pizza" << endl
		<< "3. Beef Pizza" << endl;
	cin >> choice;
	Pizza* pizza = NULL;
	PizzaShop(pizza, choice);


	

}