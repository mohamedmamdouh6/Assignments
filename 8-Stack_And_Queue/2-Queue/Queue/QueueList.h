#pragma once
#include <list>
#include <iostream>
using namespace std;
template <class T>
class QueueList {
private:
	list<T> buffer;
public:
	void enQueue(T element)
	{
		buffer.push_front(element);
	}
	T deQueue()
	{
		T temp = buffer.back();
		buffer.pop_back();
		return temp;
	}
	bool isEmpty()
	{
		return buffer.size() == 0;
	}
};