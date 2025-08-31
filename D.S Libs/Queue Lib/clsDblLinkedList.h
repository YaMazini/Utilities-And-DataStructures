#pragma once
#include <iostream>
using namespace std;


template<class T>
class clsDblLinkedList
{
public: class Node
{
public:
	Node* prev = NULL;
	Node* next = NULL;
	T value{};
};

protected:

	Node* _Head = NULL;
	size_t _Size = 0;

public:

	void SetHead(Node* Head)
	{
		_Head = Head;
	}
	Node* GetHead()
	{
		return _Head;
	}
	__declspec(property(get = GetHead, put = SetHead)) Node* Head;


	size_t Size()
	{
		return _Size;
	}


	bool IsEmpty()
	{
		return _Size == 0;
	}


	void InsertAtBeginning(T Value)
	{
		Node* New_Node = new Node();
		New_Node->value = Value;

		if (Head != NULL)
		{
			Head->prev = New_Node;
		}

		New_Node->prev = NULL;
		New_Node->next = Head;

		Head = New_Node;

		++_Size;
	}


	Node* Find(T Value)
	{
		if (Head == NULL)
		{
			return NULL;
		}

		Node* CurrentNode = Head;
		while (CurrentNode != NULL)
		{
			if (CurrentNode->value == Value)
			{
				return CurrentNode;
			}

			CurrentNode = CurrentNode->next;
		}

		return NULL;
	}


	void InsertAfter(Node*& AfterNode, T Value)
	{
		if (Head == NULL || AfterNode == NULL)
		{
			return;
		}

		Node* New_Node = new Node();
		New_Node->value = Value;

		New_Node->next = AfterNode->next;
		New_Node->prev = AfterNode;

		if (AfterNode->next != NULL)
		{
			AfterNode->next->prev = New_Node;
		}

		AfterNode->next = New_Node;

		++_Size;
	}


	void InsertAtEnd(T Value)
	{
		Node* New_Node = new Node();
		New_Node->value = Value;

		if (Head == NULL)
		{
			Head = New_Node;
			++_Size;
			return;
		}

		Node* CurrentNode = Head;
		while (CurrentNode->next != NULL)
		{
			CurrentNode = CurrentNode->next;
		}

		CurrentNode->next = New_Node;
		New_Node->prev = CurrentNode;

		++_Size;
	}


	void DeleteNode(Node*& NodeToDelete)
	{
		if (Head == NULL || NodeToDelete == NULL)
		{
			return;
		}

		if (Head == NodeToDelete)
		{
			Head = NodeToDelete->next;

			if (NodeToDelete->next != NULL)
			{
				NodeToDelete->next->prev = NULL;
			}

			--_Size;
			delete NodeToDelete;
			return;
		}

		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		else
		{
			NodeToDelete->prev->next = NULL;
		}

		delete NodeToDelete;
		--_Size;
	}


	void DeleteFirstNode()
	{
		if (Head == NULL)
		{
			return;
		}

		Node* FirstNode = Head;

		if (FirstNode->next != NULL)
		{
			FirstNode->next->prev = NULL;
		}

		Head = FirstNode->next;

		delete FirstNode;
		--_Size;
	}


	void DeleteLastNode()
	{
		if (Head == NULL)
		{
			return;
		}

		Node* CurrentNode = Head;

		if (CurrentNode->next == NULL)
		{
			Head = NULL;
			delete CurrentNode;
			--_Size;
			return;
		}

		while (CurrentNode->next != NULL)
		{
			CurrentNode = CurrentNode->next;
		}

		CurrentNode->prev->next = NULL;
		delete CurrentNode;
		--_Size;
	}


	Node* GetNode(size_t Index)
	{
		if (IsEmpty() || Index >= _Size)
			return NULL;

		Node* CurrentNode = Head;

		for (size_t i = 0; i < Index; i++)
		{
			CurrentNode = CurrentNode->next;
		}

		return CurrentNode;
	}


	T GetItem(size_t Index)
	{
		Node* CurrentNode = GetNode(Index);
		return (CurrentNode != NULL) ? CurrentNode->value : NULL;
	}


	bool InsertAfter(size_t Index, T Value)
	{
		Node* NodeToInsertAfter = GetNode(Index);

		if (NodeToInsertAfter != NULL)
		{
			InsertAfter(NodeToInsertAfter, Value);
			return true;
		}

		return false;
	}


	bool DeleteNode(size_t Index)
	{
		Node* NodeToDelete = GetNode(Index);

		if (NodeToDelete != NULL)
		{
			DeleteNode(NodeToDelete);
			return true;
		}

		return false;
	}


	bool UpdateItem(size_t Index, T Value)
	{
		Node* ItemToUpdate = GetNode(Index);

		if (ItemToUpdate != NULL)
		{
			ItemToUpdate->value = Value;
			return true;
		}

		return false;
	}


	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}


	void Reverse()
	{
		Node* CurrentNode = Head;
		Node* TempNode = NULL;

		while (CurrentNode != NULL)
		{
			TempNode = CurrentNode->prev;
			CurrentNode->prev = CurrentNode->next;
			CurrentNode->next = TempNode;

			CurrentNode = CurrentNode->prev;
		}

		if (TempNode != NULL)
		{
			Head = TempNode->prev;
		}
	}


	void PrintNodeDetails(Node* N1)
	{
		if (N1->prev == NULL)
		{
			cout << "NULL";
		}
		else
		{
			cout << N1->prev->value;
		}

		cout << " <--> " << N1->value << " <--> ";

		if (N1->next == NULL)
		{
			cout << "NULL";
		}
		else
		{
			cout << N1->next->value;
		}

		cout << "\n";
	}


	void PrintListDetails()
	{
		Node* CurrentNode = Head;

		if (CurrentNode == NULL)
		{
			cout << "\nList is empty! \n";
			return;
		}

		while (CurrentNode != NULL)
		{
			PrintNodeDetails(CurrentNode);
			CurrentNode = CurrentNode->next;
		}

		cout << "\n";
	}


	void PrintList()
	{
		Node* CurrentNode = Head;

		if (CurrentNode == NULL)
		{
			cout << "\nList is empty! \n";
			return;
		}

		cout << "\nNULL <--> ";

		while (CurrentNode != NULL)
		{
			cout << CurrentNode->value << " <--> ";
			CurrentNode = CurrentNode->next;
		}

		cout << "NULL \n\n";
	}
};
