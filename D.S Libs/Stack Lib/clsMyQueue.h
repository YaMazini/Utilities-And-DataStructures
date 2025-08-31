#pragma once
#include"clsDblLinkedList.h"



template<class T>
class clsMyQueue
{
protected:

	clsDblLinkedList<T> MyList;

public:

	void push(T Item)
	{
		MyList.InsertAtEnd(Item);
	}

	void pop()
	{
		MyList.DeleteFirstNode();
	}


	bool IsEmpty()
	{
		return MyList.IsEmpty();
	}

	size_t Size()
	{
		return MyList.Size();
	}

	T front()
	{
		return MyList.GetItem(0);
	}

	T back()
	{
		return MyList.GetItem(Size() - 1);
	}


	T GetItem(size_t Index)
	{
		return MyList.GetItem(Index);
	}

	void Reverse()
	{
		MyList.Reverse();
	}

	bool UpdateItem(size_t Index, T Value)
	{
		return MyList.UpdateItem(Index, Value);
	}

	void InsertAfter(size_t Index, T Value)
	{
		MyList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		MyList.Clear();
	}


	void Print()
	{
		if (MyList.Head == NULL)
		{
			return;
		}

		typename clsDblLinkedList<T>::Node* TempNode = MyList.Head;

		while (TempNode != NULL)
		{
			cout << TempNode->value << " ";
			TempNode = TempNode->next;
		}

		cout << "\n";
	}
};

