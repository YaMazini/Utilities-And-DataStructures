#pragma once
#include <iostream>
using namespace std;


template<class T>
class clsDynamicArray
{
protected:

	size_t _Size = 0;
	T* _OriginalArr = NULL;

	void Swap(T& A, T& B)
	{
		T Temp = A;
		A = B;
		B = Temp;
	}


public:

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;


		_Size = (size_t)Size;
		_OriginalArr = new T[_Size];
	}


	size_t Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	bool IsValid(size_t Index)
	{
		return !(IsEmpty() && Index > _Size);
	}


	bool SetItem(size_t Index, T Value)
	{
		if (!IsValid(Index))
		{
			return false;
		}

		_OriginalArr[Index] = Value;
		return true;
	}

	T GetItem(size_t Index)
	{
		return _OriginalArr[Index];
	}

	int Find(T Value)
	{
		if (IsEmpty())
			return -1;

		for (size_t i = 0; i < _Size - 1; i++)
		{
			if (_OriginalArr[i] == Value)
				return i;
		}

		return -1;
	}


	bool Resize(int NewSize)
	{
		if (NewSize == _Size)
		{
			return false;
		}

		if (NewSize < 0)
		{
			NewSize = 0;
		}

		T* TempArr = new T[NewSize];
		size_t Steps = (_Size > NewSize) ? NewSize : _Size;

		for (size_t i = 0; i < Steps; i++)
		{
			TempArr[i] = _OriginalArr[i];
		}

		delete[] _OriginalArr;
		_Size = NewSize;
		_OriginalArr = TempArr;

		return true;
	}

	bool DeleteItemAt(size_t Index)
	{
		if (!IsValid(Index))
			return false;

		T* TempArr = new T[_Size - 1];
		int Counter = 0;

		for (size_t i = 0; i < _Size; i++)
		{
			if (i != Index)
			{
				TempArr[Counter] = _OriginalArr[i];
				Counter++;
			}
		}

		delete[] _OriginalArr;
		_Size--;
		_OriginalArr = TempArr;

		return true;
	}

	bool DeleteFirstItem()
	{
		return DeleteItemAt(0);
	}

	bool DeleteLastItem()
	{
		return DeleteItemAt(_Size - 1);
	}

	bool DeleteItem(T Value)
	{
		int Index = Find(Value);

		if (Index == -1)
			return false;

		return DeleteItemAt(Index);
	}


	bool InsertAt(size_t Index, T Value) {

		if (!IsValid(Index))
		{
			return false;
		}

		_Size++;
		T* TempArray = new T[_Size];

		for (size_t i = 0; i < Index; i++)
		{
			TempArray[i] = _OriginalArr[i];
		}

		TempArray[Index] = Value;

		for (size_t i = Index; i < _Size - 1; i++)
		{
			TempArray[i + 1] = _OriginalArr[i];
		}

		delete[] _OriginalArr;
		_OriginalArr = TempArray;
		return true;

	}

	bool InsertAtBeginning(T Value)
	{
		return InsertAt(0, Value);
	}

	bool InsertBefore(size_t Index, T Value)
	{
		if (Index < 1)
			return InsertAt(0, Value);

		return InsertAt(Index - 1, Value);
	}

	bool InsertAfter(size_t Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size - 1, Value);

		return InsertAt(Index + 1, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}


	void Reverse()
	{
		size_t Steps = _Size / 2;

		for (size_t i = 0; i < Steps; i++)
		{
			Swap(_OriginalArr[i], _OriginalArr[_Size - i - 1]);
		}
	}

	void Clear()
	{
		_Size = 0;
		delete[] _OriginalArr;
		_OriginalArr = new T[0];
	}

	void PrintArray()
	{
		if (IsEmpty())
		{
			cout << "\nList is empty! \n";
			return;
		}

		for (size_t i = 0; i < _Size; i++)
		{
			cout << _OriginalArr[i] << " ";
		}

		cout << "\n";
	}


	~clsDynamicArray()
	{
		delete[] _OriginalArr;
	}
};
