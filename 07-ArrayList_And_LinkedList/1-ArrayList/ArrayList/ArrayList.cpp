#include "ArrayList.h"
// ------------- Private Functionalities --------------
template <class T>
void ArrayList<T>::resizeArr()
{
	T* temp = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = buffer[i];
	}
	delete[] buffer;
	buffer = temp;
	capacity++;
}
// ------------------- Constructors -------------------
template <class T>
ArrayList<T>::ArrayList(int capacity)
{
	if (capacity < 0)
		throw out_of_range("Out Of Range!");
	this->capacity = capacity;
	buffer = new T[capacity];
	size = 0;
}
template <class T>
ArrayList<T>::ArrayList(initializer_list<T> list)
{
	size = capacity = list.size();
	buffer = new T[size];
	int i = 0;
	for (T element : list)
	{
		buffer[i++] = element;
	}
}
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& copy)
{
	this->size = copy.size;
	this->capacity = copy.capacity;
	buffer = new T[size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = copy.buffer[i];
	}
}
// -------------------- Destructor --------------------
template <class T>
ArrayList<T>::~ArrayList()
{
	delete[] buffer;
}
// -------------------- Operations --------------------
// Pushing
template <class T>
void ArrayList<T>::pushBack(T value)
{
	if (size == capacity)
		resizeArr();
	buffer[size++] = value;
}
template <class T>
void ArrayList<T>::pushFront(T value)
{
	T* temp = nullptr;
	if (size == capacity)
	{
		temp = new T[size + 1];
		capacity++;
	}
	else
		temp = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		temp[i + 1] = buffer[i];
	}
	delete[] buffer;
	buffer = temp;
	buffer[0] = value;
	size++;
}
template <class T>
void ArrayList<T>::pushAt(int index, T value)
{
	if (index > capacity || index < 0)
		throw out_of_range("Out Of Range!");
	if (size == capacity)
		resizeArr();
	if (size == 0)
		buffer[0] = value;
	else
	{
		for (int i = size; i >= index; i--)// 1 2 3  
		{
			buffer[i] = buffer[i - 1];
		}
		buffer[index] = value;
	}
	size++;
}
// Popping
template <class T>
void ArrayList<T>::popBack()
{
	if (size == 0)
		throw out_of_range("Out Of Range!");
	size--;
}
template <class T>
void ArrayList<T>::popFront()
{
	if (size == 0)
		throw out_of_range("Out Of Range!");
	for (int i = 1; i < size; i++)
	{
		buffer[i - 1] = buffer[i];
	}
	size--;
}
template <class T>
void ArrayList<T>::popAt(int index)
{
	if (size == 0 || index < 0 || index >= size)
		throw out_of_range("Out Of Range!");
	for (int i = index + 1; i < size; i++)
	{
		buffer[i - 1] = buffer[i];
	}
	size--;
}
// List Operations
template <class T>
int ArrayList<T>::search(T value)
{
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] == value)
			return i;
	}
	return -1;
}
template <class T>
void ArrayList<T>::sort()
{
	if (size == 0)
		throw exception("List Is Empty!");
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = size - 1; j >= 0; j--)// 4 2 6 1
		{
			if (buffer[i] > buffer[j])
			{
				T temp = buffer[j];
				buffer[j] = buffer[i];
				buffer[i] = temp;
			}
		}
	}
}
template <class T>
void ArrayList<T>::reverse()
{
	if (size == 0)
		throw exception("List Is Empty!");
	T* temp = new T[size];
	int index = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		temp[index++] = buffer[i];
	}
	delete[] buffer;
	buffer = temp;
}
template <class T>
void ArrayList<T>::merge(ArrayList<T> list)
{
	if (list.isEmpty())
		throw exception("List Is Empty!");
	if (capacity < list.size + size)
	{
		int newSize = list.size + size;
		T* temp = new T[newSize];
		int index = 0;
		for (int i = 0; i < newSize; i++)
		{
			if (i < size)
				temp[i] = buffer[i];
			else
				temp[i] = list.buffer[index++];
		}
		delete[] buffer;
		buffer = temp;
		size = newSize;
	}
	else
	{
		for (int i = 0; i < list.size; i++)
		{
			buffer[size++] = list.buffer[i];
		}
	}
}
template <class T>
void ArrayList<T>::resize(int newCapacity)
{
	if (newCapacity <= size || newCapacity == capacity)
		throw invalid_argument("Invalid Capacity!");
	T* temp = new T[newCapacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = buffer[i];
	}
	delete[] buffer;
	buffer = temp;
	capacity = newCapacity;
}
template <class T>
void ArrayList<T>::shrinkToFit()
{
	T* temp = new T[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = buffer[i];
	}
	delete[] buffer;
	buffer = temp;
	capacity = size;
}
template <class T>
T ArrayList<T>::min()
{
	if (size == 0)
		throw exception("List Is Empty");
	T temp = buffer[0];
	for (int i = 0; i < size; i++)
	{
		if (temp > buffer[i])
		{
			temp = buffer[i];
		}
	}
	return temp;
}
template <class T>
T ArrayList<T>::max()
{
	if (size == 0)
		throw exception("List Is Empty");
	T temp = buffer[0];
	for (int i = 0; i < size; i++)
	{
		if (temp < buffer[i])
		{
			temp = buffer[i];
		}
	}
	return temp;
}
template <class T>
int ArrayList<T>::count(T value)
{
	if (size == 0)
		throw exception("List Is Empty!");
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (value == buffer[i])
			count++;
	}
	return count;
}
// --------------- Operator Overloading ---------------
template <class T>
T* ArrayList<T>::operator = (initializer_list <T> list)
{
	delete[] buffer;
	buffer = new T[list.size()];
	int i = 0;
	for (T element : list)
	{
		buffer[i++] = element;
	}
	size = capacity = list.size();
	return buffer;
}
template <class T>
T* ArrayList<T>::operator = (ArrayList<T> list)
{
	if (list.isEmpty())
		throw exception("List Is Empty!");
	delete[] buffer;
	buffer = new T[list.size];
	for (int i = 0; i < list.size; i++)
	{
		buffer[i] = list.buffer[i];
	}
	return buffer;
}
template <class T>
T& ArrayList<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
		throw out_of_range("Out Of Range!");
	return buffer[index];
}
// -------------- Other Functionalities ---------------
template <class T>
void ArrayList<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << buffer[i] << " ";
	}
	cout << endl;
}
template <class T>
int ArrayList<T>::getSize()
{
	return size;
}
template <class T>
int ArrayList<T>::getCapacity()
{
	return capacity;
}
template <class T>
bool ArrayList<T>::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}
// -------------- Explicit Instantiation --------------
template class ArrayList<int>;
template class ArrayList<float>;
template class ArrayList<char>;
template class ArrayList<double>;
template class ArrayList<string>;