#include <iostream>
using namespace std;

class Pizza {
private:
	void addToppings()
	{
		cout << "Add " << getPizzaName() << " Toppings" << endl;
	}
	void bakePizza()
	{
		cout << "Bake " << getPizzaName() << " Pizza" << endl;
	}
protected:
	virtual const char* getPizzaName() = 0;
	virtual void makeDough() = 0;
public:
	void makePizza()
	{
		makeDough();
		addToppings();
		bakePizza();
	}
};

// StuffedCrust
class StuffedCrust : public Pizza {
	void makeDough()
	{
		cout << "Make Stuffed Crust Dough for " << getPizzaName() << " Pizza" << endl;
	}
};
// StuffedCrust: Chicken, Beef, Cheese
class StuffedChicken : public StuffedCrust {
	const char* getPizzaName()
	{
		return "Chicken";
	}
};
class StuffedBeef : public StuffedCrust {
	const char* getPizzaName()
	{
		return "Beef";
	}
};
class StuffedCheese : public StuffedCrust {
	const char* getPizzaName()
	{
		return "Cheese";
	}
};

// Normal
class Normal : public Pizza {
	void makeDough()
	{
		cout << "Make Dough for " << getPizzaName() << " Pizza" << endl;
	}
};
// Normal: Chicken, Beef, Cheese
class NormalChicken : public Normal {
	const char* getPizzaName()
	{
		return "Chicken";
	}
};
class NormalBeef : public Normal {
	const char* getPizzaName()
	{
		return "Beef";
	}
};
class NormalCheese : public Normal {
	const char* getPizzaName()
	{
		return "Cheese";
	}
};
// Buy Pizza 
void BuyPizza(Pizza* ptr)
{
	ptr->makePizza();
}
// Pizza Menu 
void PizzaMenu()
{
	cout << "1: Chicken Normal Dough" << endl
		<< "2: Beef Normal Dough" << endl
		<< "3: Cheese Normal Dough" << endl
		<< "4: Chicken Stuffed Crust" << endl
		<< "5: Beef Stuffed Crust" << endl
		<< "6: Cheese Stuffed Crust" << endl;
}
// Pizza Shop
void PizzaShop()
{
	cout << "Welcome To Pizza Shop:- " << endl;
	PizzaMenu();
	cout << "Which One: ";
	int choice;
	cin >> choice;
	while (choice > 6 || choice < 1)
	{
		PizzaMenu();
		cout << "Invalid Choice" << endl;
		cout << "Enter Again Please: ";
		cin >> choice;
	}
	Pizza* pizza = nullptr;
	switch (choice)
	{
	case 1:
		pizza = new NormalChicken;
		break;
	case 2:
		pizza = new NormalBeef;
		break;
	case 3:
		pizza = new NormalCheese;
		break;
	case 4:
		pizza = new StuffedChicken;
		break;
	case 5:
		pizza = new StuffedBeef;
		break;
	case 6:
		pizza = new StuffedCheese;
		break;
	}
	if (pizza) 
	{
		BuyPizza(pizza);
		delete pizza;
	}
}
// Main 
void main()
{
	char again = 'y';
	while (again == 'y' || again == 'Y')
	{
		PizzaShop();
		cout << "Would You Like To Order Again? (Y/n): ";
		cin >> again;
	}
}