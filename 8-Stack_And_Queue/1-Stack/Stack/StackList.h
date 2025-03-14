#pragma once
#include <iostream>
#include <list>
using namespace std;
template <class T>
class StackList {
private:
	list<T> buffer;
public:
	void push(T element)
	{
		buffer.push_back(element);
	}
	T pop()
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