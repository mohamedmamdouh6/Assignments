#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H
#include <iostream>
#include <string>
#include <initializer_list>
#include <exception>
using namespace std;
template <class T>
struct Node {
	T value;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
};
template <class T>
class DoublyLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int length = 0;
public:
	// Constructors
	DoublyLinkedList();
	DoublyLinkedList(initializer_list<T>);
	DoublyLinkedList(const DoublyLinkedList<T>&);
	// Destructor
	~DoublyLinkedList();
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
	void merge(DoublyLinkedList<T>&);
	T min();
	T max();
	int count(T);
	void display();
	void displayReverse();
	int getLength();
	bool isEmpty();
	void deleteList();
	// Operator OverLoading
	void operator = (initializer_list<T>);
	void operator = (const DoublyLinkedList<T>&);
};
#endif // DOUBLY_LINKEDLIST_H