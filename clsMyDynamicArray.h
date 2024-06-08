#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>

class clsMyDynamicArray
{

protected:

	int _size = 0;
	T* tempArray;

public:

	T* originalArray;

	clsMyDynamicArray(int  size = 0)
	{
		if (size < 0)
			size = 0;

		_size = size;

		originalArray = new T[_size];
	}

	~clsMyDynamicArray()
	{
		delete[] originalArray;
	}

	bool setItem(int index, T value)
	{
		if (index >= _size || index < 0)
		{
			return false;
		}

		originalArray[index] = value;

		return true;
	}

	bool isEmpty()
	{
		//return (_size == 0);
		return (_size == 0) ? true : false;
	}


	int size()
	{
		return _size;
	}


	void printList(string newline = "\n")
	{
		for (int i = 0; i < _size; i++)
		{
			cout << originalArray[i] << "  ";
		}

		cout << newline;
	}


	void reSize(int newSize)
	{
		if (newSize < 0)
			newSize = 0;

		tempArray = new T[newSize];

		//set original array size to the new which is here mean shrink the array if the condition is true.
		if (newSize < _size)
			_size = newSize;

		//copy the element of original array to the temp array until it's reach to the original size.
		for (int i = 0; i < _size; i++)
		{
			tempArray[i] = originalArray[i];
		}

		_size = newSize;

		delete[] originalArray;

		originalArray = tempArray;
	}


	T getItem(int index)
	{
		if (index >= _size || index < 0)
			return NULL;

		return originalArray[index];
	}

	void reverse()
	{
		for (int i = 0; i < _size / 2; i++)
		{
			T element = originalArray[i];
			originalArray[i] = originalArray[_size - 1 - i];
			originalArray[_size - 1 - i] = element;
		}
	}

	void clear()
	{
		reSize(0);
	}


	void deleteItemAt(int index)
	{
		if (index >= _size || index < 0)
			return;

		tempArray = new T[_size - 1];


		int counter = 0;

		for (int i = 0; i < _size; i++)
		{
			if (i != index)
			{
				tempArray[counter] = originalArray[i];

				counter++;
			}
		}

		delete[] originalArray;

		_size--;

		originalArray = tempArray;
	}


	void deleteFirstItem()
	{
		deleteItemAt(0);
	}

	void deleteLastItem()
	{
		deleteItemAt(_size - 1);
	}


	int find(T value)
	{
		for (int i = 0; i < _size; i++)
		{
			if (value == originalArray[i])
				return i;
		}

		return -1;
	}


	void deleteItem(T value)
	{
		deleteItemAt(find(value));
	}



	//void insertAt(int index, T value, bool insertAtEnd = false)
	//{
	//	if (index >= _size || index < 0)
	//		return;

	//	if (!insertAtEnd) 
	//	{
	//		tempArray = new T[++_size];

	//		for (int i = 0; i < index; i++)
	//		{
	//			tempArray[i] = originalArray[i];
	//		}

	//		tempArray[index] = value;

	//		for (int i = index + 1; i < _size; i++)
	//		{
	//			tempArray[i] = originalArray[i - 1];
	//		}
	//	}

	//	else 
	//	{
	//		tempArray = new T[_size];

	//		for (int i = 0; i < _size - 1; i++)
	//		{
	//			tempArray[i] = originalArray[i];
	//		}

	//		tempArray[index] = value;
	//	}
	//	delete[] originalArray;

	//	originalArray = tempArray;
	//}




	void insertAt(int index, T value)
	{
		if (index > _size || index < 0)
			return;

		tempArray = new T[++_size];

		for (int i = 0; i < index; i++)
		{
			tempArray[i] = originalArray[i];
		}

		tempArray[index] = value;

		for (int i = index + 1; i < _size; i++)
		{
			tempArray[i] = originalArray[i - 1];
		}

		delete[] originalArray;

		originalArray = tempArray;
	}

	void insertAtBeginning(T value)
	{
		insertAt(0, value);
	}

	void insertBefore(int index, T value)
	{
		//You don't need to decreament it because the insertAt by default insertBefore the index you send as arguments to the paramters.
		insertAt(index, value);
	}

	void insertAfter(int index, T value)
	{
		insertAt(++index, value);
	}

	void insertAtEnd(T value)
	{
		//++_size;

		insertAt(_size, value);
		//insertAt(++_size - 1, value, true);

	}
};

