#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <class T>
class StackVector {
private:
	vector<T> buffer;
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