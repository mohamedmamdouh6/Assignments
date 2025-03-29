#include "BST.h"
#include <iostream>
using namespace std;
void main()
{
	// Tree 1
	BST<int> a;
	a.addI(50);
	a.addI(48);
	a.addI(70);
	a.addI(30);
	a.addI(65);
	a.addI(90);
	a.addI(20);
	a.addI(32);
	a.addI(67);
	a.addI(98);
	a.addI(15);
	a.addI(25);
	a.addI(31);
	a.addI(35);
	a.addI(66);
	a.addI(69);
	a.addI(94);
	a.addI(99);
	cout << a.isExistI(99) << endl;
	cout << a.isExistI(101) << endl;
	a.print();
	// Tree 2
	BST<int> b;
	b.addR(50);
	b.addR(48);
	b.addR(70);
	b.addR(30);
	b.addR(65);
	b.addR(90);
	b.addR(20);
	b.addR(32);
	b.addR(67);
	b.addR(98);
	b.addR(15);
	b.addR(25);
	b.addR(31);
	b.addR(35);
	b.addR(66);
	b.addR(69);
	b.addR(94);
	b.addR(99);
	cout << b.isExistR(99) << endl;
	cout << b.isExistR(101) << endl;
	b.print();
}