#pragma once
#include <iostream>
#include "clsMyDynamicArray.h"

template <class T>

class clsMyQueueArr
{

protected :

	//If You Want To Create Allocate Object With Parameterized Constructor On The Stack You Need To Use Member Intializer List To Instantiate It.
	clsMyDynamicArray <T> _array;

	//You Can Do This If you Want To Allocate The Object On The Heap But Do Not Forgot To Delete The Object In Destructor.
	//clsMyDynamicArray <T>* _arr = new clsMyDynamicArray<T>(0);


	/*  
		"Template classes have amazed me because 
		I recently discovered that when declaring an object of a template class 
		like this: clsMyDynamicArray<T> _array;, behind the scenes, 
		it automatically does this for us: clsMyDynamicArray<T> _array(0);.

		The template class has this amazing flexibility to do it without the developer's interference.
		It sends the arguments to the parameterized constructor and provides the default value of its type.
		In our case, the default value for the integer data type, which determines the size of the array, is 0.

		So, the template class implicitly sends 0 as an argument to the constructor's integer parameter to determine the size of the array,
		without us explicitly knowing or providing it. It creates and instantiates the object seamlessly.

		Let's all give a round of applause to templates and how they improve the development cycle, making it better and better."

	*/
	
public:




	//~clsMyQueueArr() 
	//{
	//	delete _arr;
	//}

	void push(T value)
	{
		_array.insertAtEnd(value);

		
		//_arr->insertAtEnd(value);
	}

	void pop()
	{
		_array.deleteFirstItem();
		//_arr->deleteFirstItem();
	}


	void print(string newLine = "\n")
	{
		_array.printList(newLine);

		//_arr->printList(newLine);
	}


	int size()
	{
		return _array.size();
	}

	bool isEmpty()
	{
		return _array.isEmpty();
	}

	T front()
	{
		return _array.getItem(0);
	}

	T back()
	{
		return _array.getItem(size() - 1);
	}

	T getItem(T value)
	{
		return _array.getItem(value);
	}

	void reverse()
	{
		_array.reverse();
	}


	void updateItem(int index, T value)
	{
		_array.setItem(index, value);
	}

	//This is has nothing to do with standard queue data structure
	void insertAfter(int index, T value)
	{
		_array.insertAfter(index, value);
	}

	//This is has nothing to do with standard queue data structur
	void insertAtFront(T value)
	{
		_array.insertAtBeginning(value);
	}

	//This is has nothing to do with standard queue data structure
	void insertAtBack(T value)
	{
		push(value);
	}

	void clear()
	{
		_array.clear();
	}
};

