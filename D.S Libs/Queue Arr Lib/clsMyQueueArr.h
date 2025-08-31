#pragma once
#include "clsDynamicArray.h"


template <class T>
class clsMyQueueArr
{
protected:

	clsDynamicArray <T> _MyArray;

public:

	void push(T Value)
	{
		_MyArray.InsertAtEnd(Value);
	}

	void pop()
	{
		_MyArray.DeleteFirstItem();
	}


	size_t Size()
	{
		return _MyArray.Size();
	}

	T front()
	{
		return _MyArray.GetItem(0);
	}

	T back()
	{
		return _MyArray.GetItem(Size() - 1);
	}

	T GetItem(size_t Index)
	{
		return _MyArray.GetItem(Index);
	}

	void UpdateItem(size_t Index, T Value)
	{
		_MyArray.SetItem(Index, Value);
	}


	void InsertAfter(size_t Index, T Value)
	{
		_MyArray.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_MyArray.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyArray.InsertAtEnd(Value);
	}


	void Reverse()
	{
		_MyArray.Reverse();
	}

	void Clear()
	{
		_MyArray.Clear();
	}


	void Print()
	{
		_MyArray.PrintArray();
	}
};

