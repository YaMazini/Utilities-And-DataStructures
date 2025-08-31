#pragma once
#include"clsDblLinkedList.h"



template<class T>
class clsMyQueue
{
protected:

	clsDblLinkedList<T> MyQueueList;

public:

	void push(T Item)
	{
		MyQueueList.InsertAtEnd(Item);
	}

	void pop()
	{
		MyQueueList.DeleteFirstNode();
	}


	bool IsEmpty()
	{
		return MyQueueList.IsEmpty();
	}

	size_t Size()
	{
		return MyQueueList.Size();
	}

	T front()
	{
		return MyQueueList.GetItem(0);
	}

	T back()
	{
		return MyQueueList.GetItem(Size() - 1);
	}


	T GetItem(size_t Index)
	{
		return MyQueueList.GetItem(Index);
	}

	void Reverse()
	{
		MyQueueList.Reverse();
	}

	bool UpdateItem(size_t Index, T Value)
	{
		return MyQueueList.UpdateItem(Index, Value);
	}

	void InsertAfter(size_t Index, T Value)
	{
		MyQueueList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		MyQueueList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		MyQueueList.InsertAtEnd(Value);
	}

	void Clear()
	{
		MyQueueList.Clear();
	}


	void Print()
	{
		if (MyQueueList.Head == NULL)
		{
			return;
		}

		typename clsDblLinkedList<T>::Node* TempNode = MyQueueList.Head;

		while (TempNode != NULL)
		{
			cout << TempNode->value << " ";
			TempNode = TempNode->next;
		}

		cout << "\n";
	}
};

