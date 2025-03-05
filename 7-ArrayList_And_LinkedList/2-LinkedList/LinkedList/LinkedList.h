#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
#include <exception>
#include <initializer_list>
using namespace std;
template <class T>
struct Node {
	T value;
	Node<T>* next = nullptr;
};
template <class T>
class LinkedList {
private:
	Node<T>* head;
	int length;
public:
	// -------- Constructors ---------
	LinkedList();
	LinkedList(initializer_list<T>);
	LinkedList(const LinkedList<T>&);
	// --------- Destructor ----------
	~LinkedList();
	// ------- Functionalities -------
	// Insertion
	void insertFirst(T);
	void insertEnd(T);
	void insertAt(int, T);
	// Erasing
	void eraseFirst();
	void eraseEnd();
	void eraseAt(int);
	// List Operations
	T getValue(int);
	int search(T);
	void reverse();
	void sort();
	void merge(LinkedList<T>&);
	T min();
	T max();
	int count(T);
	void display();
	int getLength();
	bool isEmpty();
	void deleteList();
	// Operator Overloading
	void operator = (initializer_list<T>);
	void operator = (const LinkedList<T>&);
};
#endif // LINKEDLIST_H