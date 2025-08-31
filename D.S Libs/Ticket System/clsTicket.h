#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;



class clsTicket
{
private:

	string _Prefix;
	string _DateTime;
	size_t _WaitingClients = 0;
	size_t _ExpectedServeTime = 0;

public:

	clsTicket(string Prefix, size_t WaitingClients = 0, size_t ExpectedServeTime = 0)
	{
		_Prefix = Prefix;
		_DateTime = clsDate::GetSystemDateTimeString();
		_WaitingClients = WaitingClients;
		_ExpectedServeTime = ExpectedServeTime;
	}


	string GetPrefix()
	{
		return _Prefix;
	}

	string GetDateTime()
	{
		return _DateTime;
	}

	size_t GetClientsToWait()
	{
		return _WaitingClients;
	}

	size_t GetExpectedServeTime()
	{
		return _ExpectedServeTime;
	}


	string GetWaitingTime()
	{
		return ((GetExpectedServeTime() == 0) ? "[Now]" : clsDate::MinutesToHours((float)GetExpectedServeTime()));

	}

	string GetWaitingClients()
	{
		return ((GetClientsToWait() == 0) ? "[Non]" : to_string(GetClientsToWait()));
	}


	static clsTicket GetEmptyTicket()
	{
		return clsTicket("", 0, 0);
	}

	bool IsEmptyTicket()
	{
		return (GetPrefix() == "" && GetClientsToWait() == 0 && GetExpectedServeTime() == 0);
	}


	void Print()
	{
		cout << "\n\t\t\t\t----------------------------------------------------\n\n";

		cout << clsUtil::Tabs(7) << " " + GetPrefix() << "\n\n";
		cout << clsUtil::Tabs(6) << GetDateTime() << "\n";
		cout << clsUtil::Tabs(5) << "         " + GetWaitingClients() << " Clients to Wait " << "\n\n";
		cout << clsUtil::Tabs(5) << "\t    Time to Wait \n" << clsUtil::Tabs(7) << GetWaitingTime() << "\n";

		cout << "\n\t\t\t\t----------------------------------------------------\n";
	}
};

