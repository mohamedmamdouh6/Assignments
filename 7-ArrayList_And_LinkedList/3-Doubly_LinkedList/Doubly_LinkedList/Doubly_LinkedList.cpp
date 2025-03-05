#include "Doubly_LinkedList.h"
// ------------- Constructors -------------
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = tail = nullptr;
	length = 0;
}
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(initializer_list<T> list)
{
	for (T item : list)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = item;
		if (!head)
		{
			head = tail =  newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}
}
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& copy)
{
	Node<T>* temp = copy.head;
	while (temp)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = temp->value;
		if (!head)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		temp = temp->next;
		length++;
	}
}
// -------------- Destructor --------------
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node<T>* temp = head;
	while (temp)
	{
		Node<T>* delNode = temp;
		temp = temp->next;
		delete delNode;
	}
}
// -------------- Insertion ---------------
template <class T>
void DoublyLinkedList<T>::insertFirst(T element)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = element;
	if (!head)
	{
		head = tail = newNode;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	length++;
}
template <class T>
void DoublyLinkedList<T>::insertEnd(T element)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = element;
	if (!head)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}
template <class T>
void DoublyLinkedList<T>::insertAt(int index, T element)
{
	if (index < 0 || index > length)
		throw out_of_range("Out Of Range!");
	Node<T>* newNode = new Node<T>;
	newNode->value = element;
	if (!head)
	{
		head = tail = newNode;
	}
	else if (index == 0)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if (index == length)
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	else
	{
		Node<T>* temp = nullptr;
		int check = (length - 1) - index;
		if (check < index)
		{
			temp = tail;
			while (check--)
			{
				temp = temp->prev;
			}
			newNode->next = temp;
			newNode->prev = temp->prev;
			temp->prev->next = newNode;
			temp->prev = newNode;
		}
		else
		{
			temp = head;
			while (index--)
			{
				temp = temp->next;
			} 
			newNode->next = temp;
			newNode->prev = temp->prev;
			temp->prev->next = newNode;
			temp->prev = newNode;
		}
	}
	length++;
}
// --------------- Erasing ----------------
template <class T>
void DoublyLinkedList<T>::eraseFirst()
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* delNode = head;
	head = head->next;
	head->prev = nullptr;
	delete delNode;
	length--;
}
template <class T>
void DoublyLinkedList<T>::eraseEnd()
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* delNode = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete delNode;
	length--;
}
template <class T>
void DoublyLinkedList<T>::eraseAt(int index)
{
	if (index < 0 || index > length - 1)
		throw out_of_range("Out Of Range!");
	Node<T>* delNode = nullptr;
	if (index == 0)
	{
		delNode = head;
		head = head->next;
		head->prev = nullptr;
	}
	else if (index == length - 1)
	{
		delNode = tail;
		tail = tail->prev;
		tail->next = nullptr;
	}
	else
	{
		Node<T>* temp = nullptr;
		int check = (length - 1) - index;
		if (check < index)
		{
			temp = tail;
			while (check--)
			{
				temp = temp->prev;
			}
			delNode = temp;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		else
		{
			temp = head;
			while (index--)
			{
				temp = temp->next;
			}
			delNode = temp;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
	}
	delete delNode;
	length--;
}
// ------------ List Operations -----------
template <class T>
T DoublyLinkedList<T>::getValue(int index)
{
	if (index < 0 || index > length - 1)
		throw out_of_range("Out Of Range!");
	if (index == 0)
	{
		return head->value;
	}
	else if (index == length - 1)
	{
		return tail->value;
	}
	else
	{
		Node<T>* temp = nullptr;
		int check = (length - 1) - index;
		if (check < index)
		{
			temp = tail;
			while (check--)
			{
				temp = temp->prev;
			}
			return temp->value;
		}
		else
		{
			temp = head;
			while (index--)
			{
				temp = temp->next;
			}
			return temp->value;
		}
	}
}
template <class T>
int DoublyLinkedList<T>::search(T element)
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* temp = head;
	int index = 0;
	while (temp)
	{
		if (temp->value == element)
			return index;
		temp = temp->next;
		index++;
	}
	return -1;
}
template <class T>
void DoublyLinkedList<T>::reverse()
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T> *left = head;
	Node<T>* right = tail;
	int half = 0;
	while (half != length/2)
	{
		T temp = left->value;
		left->value = right->value;
		right->value = temp;
		left = left->next;
		right = right->prev;
		half++;
	}
}
template <class T>
void DoublyLinkedList<T>::sort()
{
	if (!head)
		throw exception("List Is Empty!");
	int count = length;
	while (count--)
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
	}
}
template <class T>
void DoublyLinkedList<T>::merge(DoublyLinkedList<T>& list)
{
	if (!list.head)
		throw exception("List Is Empty!");
	Node<T>* temp = list.head;
	while (temp)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = temp->value;
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		temp = temp->next;
		length++;
	}
}
template <class T>
T DoublyLinkedList<T>::min()
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* temp = head;
	T min = temp->value;
	while (temp)
	{
		if (min > temp->value)
		{
			min = temp->value;
		}
		temp = temp->next;
	}
	return min;
}
template <class T>
T DoublyLinkedList<T>::max()
{
	if (!head)
		throw exception("List Is Empty!");
	Node<T>* temp = head;
	T max = temp->value;
	while (temp)
	{
		if (max < temp->value)
		{
			max = temp->value;
		}
		temp = temp->next;
	}
	return max;
}
template <class T>
int DoublyLinkedList<T>::count(T element)
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
void DoublyLinkedList<T>::display()
{
	Node<T>* temp = head;
	while(temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
template <class T>
void DoublyLinkedList<T>::displayReverse()
{
	Node<T>* temp = tail;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}
template <class T>
int DoublyLinkedList<T>::getLength()
{
	return length;
}
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
	if (!head)
		return true;
	else
		return false;
}
template <class T>
void DoublyLinkedList<T>::deleteList()
{
	while (head)
	{
		Node<T>* delNode = head;
		head = head->next;
		delete delNode;
		length--;
	}
}
// --------- Operator Overloading ---------
template<class T>
void DoublyLinkedList<T>::operator = (initializer_list<T> list)
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
	for (T item : list)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = item;
		if (!head)
			head = tail = newNode;
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		length++;
	}
}
template <class T>
void DoublyLinkedList<T>::operator = (const DoublyLinkedList<T>& copy)
{
	while (head)
	{
		Node<T>* delNode = head;
		head = head->next;
		delete delNode;
		length--;
	}
	Node<T>* temp = copy.head;
	while (temp)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = temp->value;
		if (!head)
			head = tail = newNode;
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		temp = temp->next;
		length++;
	}
}
// -------- Explicit Instantiation --------
template class DoublyLinkedList<int>;
template class DoublyLinkedList<char>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<string>;