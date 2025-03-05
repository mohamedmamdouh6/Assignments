#include "LinkedList.h"
// ----------- Constructors -------------
template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	length = 0;
}
template <class T>
LinkedList<T>::LinkedList(initializer_list<T> list)
{
	Node<T>* temp = nullptr;
	for (T item : list)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = item;
		if (!head)
		{
			head = newNode;
			temp = head;
		}
		else
		{
			temp->next = newNode;
			temp = newNode;
		}
		length++;
	}
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy)
{
	Node<T>* temp = copy.head;
	Node<T>* prevNode = nullptr;
	while (temp)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = temp->value;
		if (!head)
		{
			head = newNode;
			prevNode = head;
		}
		else
		{
			prevNode->next = newNode;
			prevNode = newNode;
		}
		temp = temp->next;
	}
	length = copy.length;
}
// ------------ Destructor --------------
template <class T>
LinkedList<T>::~LinkedList()
{
	while (head)
	{
		Node<T>* delNode = head;
		head = head->next;
		delete delNode;
	}
}
// ---------- Functionalities -----------
// Insertion
template <class T>
void LinkedList<T>::insertFirst(T element)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = element;
	if (head)
		newNode->next = head;
	head = newNode;
	length++;
}
template <class T>
void LinkedList<T>::insertEnd(T element)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = element;
	if (!head)
	{
		head = newNode;
	}
	else
	{
		Node<T>* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	length++;
}
template <class T>
void LinkedList<T>::insertAt(int index, T element)
{
	if (index < 0 || index > length)
		throw out_of_range("Out Of Range!");
	Node<T>* newNode = new Node<T>;
	newNode->value = element;
	if (!head)
		head = newNode;
	else
	{
		Node<T>* temp = head;
		int count = 0;
		while (count < index - 1)
		{
			temp = temp->next;
			count++;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	length++;
}
// Erasing
template <class T>
void LinkedList<T>::eraseFirst()
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* delNode = head;
	head = head->next;
	delete delNode;
	length--;
}
template <class T>
void LinkedList<T>::eraseEnd()
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* temp = head;
	while (temp->next->next)// 1 2 3
		temp = temp->next;
	Node<T>* delNode = temp->next->next;
	temp->next = nullptr;
	delete delNode;
	length--;
}
template <class T>
void LinkedList<T>::eraseAt(int index)
{
	if (index < 0 || index >= length)
		throw out_of_range("Out Of Range!");
	if (index == 0)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		int count = 0;
		Node<T>* temp = head;
		while (count != index - 1)
		{
			temp = temp->next;
			count++;
		}
		Node<T>* delNode = temp->next;
		temp->next = temp->next->next;// 1 2 3 4
		delete delNode;
	}
	length--;
}
// List Operations
template <class T>
T LinkedList<T>::getValue(int index)
{
	if (index < 0 || index >= length)
		throw out_of_range("Out Of Range!");
	Node<T>* temp = head;
	while (index--)
		temp = temp->next;
	return temp->value;
}
template <class T>
int LinkedList<T>::search(T element)
{
	if (length == 0)
		throw exception("List Is Empty!");
	Node<T>* temp = head;
	int index = 0;
	while (temp)
	{
		if (element == temp->value)
			return index;
		temp = temp->next;
		index++;
	}
	return -1;
}
template <class T>
void LinkedList<T>::reverse()
{
	if (length == 0)
		throw exception("List Is Empty!");
	Node<T>* previous = nullptr;
	Node<T>* current = head;
	Node<T>* after;
	while (current)
	{
		after = current->next;
		current->next = previous;
		previous = current;
		current = after;
	}
	head = previous;
}
template <class T>
void LinkedList<T>::sort()
{
	if (length == 0)
		throw exception("List Is Empty!");
	int count = length;
	while (count)
	{
		Node<T>* temp = head;
		while (temp->next)
		{
			if (temp->value > temp->next->value)
			{
				T t = temp->value;
				temp->value = temp->next->value;
				temp->next->value = t;
			}
			temp = temp->next;
		}
		count--;
	}
}
template <class T>
void LinkedList<T>::merge(LinkedList<T>& list)
{
	if (!list.head)
		throw exception("List Is Empty!");
	Node<T>* temp = list.head;
	Node<T>* nextNode = head;
	while (nextNode->next)
		nextNode = nextNode->next;
	while (temp)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = temp->value;
		nextNode->next = newNode;
		nextNode = newNode;
		temp = temp->next;
	}
	length += list.length;
}
template <class T>
T LinkedList<T>::min()
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* temp = head;
	T min = temp->value;
	while (temp)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return min;
}
template <class T>
T LinkedList<T>::max()
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* temp = head;
	T max = temp->value;
	while (temp)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return max;
}
template <class T>
int LinkedList<T>::count(T element)
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* temp = head;
	int count = 0;
	while (temp)
	{
		if (element == temp->value)
			count++;
		temp = temp->next;
	}
	return count;
}
template <class T>
void LinkedList<T>::display()
{
	Node<T>* temp = head;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
template <class T>
int LinkedList<T>::getLength()
{
	return length;
}
template <class T>
bool LinkedList<T>::isEmpty()
{
	if (!head)
		return true;
	else
		return false;
}
template <class T>
void LinkedList<T>::deleteList()
{
	while (head)
	{
		Node<T>* delNode = head;
		head = head->next;
		delete delNode;
	}
}
// ------- Operator OverLoading ---------
template <class T>
void LinkedList<T>::operator = (initializer_list<T> list)
{
	if (list.size() == 0)
		throw exception("Initializer List Is Empty!");
	while (head)
	{
		Node<T>* delNode = head;
		head = head->next;
		delete delNode;
		length--;
	}
	Node<T>* temp = nullptr;
	for (T item : list)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = item;
		if (!head)
			head = temp =  newNode;
		else
		{
			temp->next = newNode;
			temp = newNode;
		}
		length++;
	}
}
template <class T>
void LinkedList<T>::operator = (const LinkedList<T>& copy)
{
	while (head)
	{
		Node<T>* delNode = head;
		head = head->next;
		delete delNode;
		length--;
	}
	Node<T>* temp = copy.head;
	Node<T>* prev = nullptr;
	while (temp)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = temp->value;
		if (!head)
		{
			head = prev = newNode;
		}
		else
		{
			prev->next = newNode;
			prev = newNode;
		}
		temp = temp->next;
		length++;
	}
}
// ------ Explicit Instantiation --------
template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<char>;
template class LinkedList<double>;
template class LinkedList<string>;