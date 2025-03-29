#pragma once
#include <iostream>
#include <exception>
using namespace std;
template <class T>
struct Node {
	T value;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
	Node(T element)
	{
		this->value = element;
		this->left = this->right = nullptr;
	}
};
template <class T>
class BST {
private:
	Node<T>* root = nullptr;
	int size = 0;
	void addRInternal(Node<T>* temp, T element)
	{
		if (temp->value == element)
			throw exception("Element Already Exists!");
		else if (temp->value > element)
		{
			if (!temp->left)
				temp->left = new Node<T>(element);
			else
				addRInternal(temp->left, element);
		}
		else
		{
			if (!temp->right)
				temp->right = new Node<T>(element);
			else
				addRInternal(temp->right, element);
		}
		
	}
	bool isExistRInternal(Node<T>* temp, T element)
	{
		if (!temp)
			return false;
		else if (temp->value == element)
			return true;
		else if (temp->value > element)
			isExistRInternal(temp->left, element);
		else
			isExistRInternal(temp->right, element);
	}
	void del(Node<T>* temp)
	{
		if (temp)
		{
			del(temp->right);
			del(temp->left);
			delete temp;
		}
	}
	void printR(Node<T>* temp)
	{
		if (temp)
		{
			cout << temp->value << " ";
			printR(temp->left);
			printR(temp->right);
		}
	}
public:
	~BST()
	{
		del(root);
	}
	void addI(T element)
	{
		if (!root)
		{
			root = new Node<T>(element);
		}
		else
		{
			Node<T>* temp = root;
			while (temp)
			{
				if (temp->value == element)
					throw exception("Element Already Exists!");
				else if (temp->value > element)
				{
					if (!temp->left)
					{
						temp->left = new Node<T>(element);
						break;
					}
					else
						temp = temp->left;
				}
				else
				{
					if (!temp->right)
					{
						temp->right = new Node<T>(element);
						break;
					}
					else
						temp = temp->right;
				}
			}
		}
		size++;
	}
	bool isExistI(T element)
	{
		Node<T>* temp = root;
		while (temp)
		{
			if (temp->value == element)
				return true;
			else if (temp->value > element)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return false;
	}
	void addR(T element)
	{
		if (!root)
			root = new Node<T>(element);
		else
			addRInternal(root, element);
		size++;
	}
	bool isExistR(T element)
	{
		return isExistRInternal(root, element);
	}
	void print()
	{
		printR(root);
		cout << endl;
	}
};
