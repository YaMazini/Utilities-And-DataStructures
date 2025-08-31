#pragma once
#include <iostream>
#include <stack>
using namespace std;


class clsMyString
{
private:

	stack <string> _UndoWords;
	stack <string> _RedoWords;
	string _Value = "";

public:

	void SetValue(string Value)
	{
		_UndoWords.push(_Value);
		_Value = Value;
		
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	void Undo()
	{
		if (!_UndoWords.empty())
		{
			_RedoWords.push(_Value);
			_Value = _UndoWords.top();
			_UndoWords.pop();
		}
	}

	void Redo()
	{
		if (!_RedoWords.empty())
		{
			_UndoWords.push(_Value);
			_Value = _RedoWords.top();
			_RedoWords.pop();
		}
	}
};

