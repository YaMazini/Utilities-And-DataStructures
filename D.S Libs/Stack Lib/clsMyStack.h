#pragma once
#include "clsMyQueue.h"


template<class T>
class clsMyStack : public clsMyQueue<T>
{
public:

	void push(T Value)
	{
		clsMyQueue<T>::MyList.InsertAtBeginning(Value);
	}

	T Top()
	{
		return clsMyQueue<T>::front();
	}

	T Bottom()
	{
		return clsMyQueue<T>::back();
	}

	void InsertAtTop(T Value)
	{
		clsMyQueue<T>::InsertAtFront(Value);
	}

	void InsertAtBottom(T Value)
	{
		clsMyQueue<T>::InsertAtBack(Value);
	}

};

