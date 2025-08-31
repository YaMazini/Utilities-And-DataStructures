#pragma once
#include "clsMyQueueArr.h"

template<typename T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:

	using clsMyQueueArr<T>::_MyArray;

	void push(T Value)
	{
		_MyArray.InsertAtBeginning(Value);
	}

	T Top()
	{
		return this->front();
	}

	T Bottom()
	{
		return this->back();
	}

	void InsertAtTop(T Value)
	{
		_MyArray.InsertAtBeginning(Value);
	}

	void InsertAtBottom(T Value)
	{
		_MyArray.InsertAtEnd(Value);
	}

};

