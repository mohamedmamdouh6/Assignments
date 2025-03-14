#pragma once
#include <vector>
#include <iostream>
using namespace std;
template <class T>
class QueueVector {
private:
	vector<T> buffer;
public:
	void enQueue(T element)
	{
		buffer.push_back(element);
	}
	T deQueue()
	{
		T temp = buffer.front();
		buffer.erase(buffer.begin());
		return temp;
	}
	bool isEmpty()
	{
		return buffer.size() == 0;
	}
};