#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>
#include <string>;
#include <initializer_list>
#include <exception>
using namespace std;
template <class T>
class ArrayList {
private:
	T* buffer;
	int size;
	int capacity;
	void resizeArr();
public:
	// ------------ Constructors -------------
	ArrayList(int capacity = 2);
	ArrayList(initializer_list<T>);
	ArrayList(const ArrayList<T>&);
	// ------------- Destructor --------------
	~ArrayList();
	// ------------- Operations --------------
	// Pushing
	void pushBack(T);
	void pushFront(T);
	void pushAt(int, T);
	// Popping
	void popBack();
	void popFront();
	void popAt(int);
	// List Operations
	int search(T);
	void sort();
	void reverse();
	void merge(ArrayList<T>);
	void resize(int);
	void shrinkToFit();
	T min();
	T max();
	int count(T);
	// --------- Operator Overloading --------
	T* operator = (initializer_list<T>);
	T* operator = (ArrayList<T>);
	T& operator [] (int);
	// -------- Other Functionalities --------
	void print();
	int getSize();
	int getCapacity();
	bool isEmpty();
};
#endif // ARRAYLIST_H