#include <iostream>
#include <queue>
#include <stack>
#include "clsTicket.h"
using namespace std;

class clsQueueLine
{
private:

	queue<clsTicket> _qTickets;

	string _Prefix;
	size_t _AvgServeTime = 0;

	size_t _TotalTickets = 0;

	string _GetNewPrefix()
	{
		string Alpha = clsUtil::ExtractAlpha(_Prefix);
		int Digit = clsUtil::ExtractDigits(_Prefix);

		return Alpha + to_string(Digit + _TotalTickets + 1);
	}

	stack<string> _GetPrefexesInStack()
	{
		stack<string> stkPrefexes;

		if (_qTickets.empty())
			stkPrefexes;

		queue<clsTicket> qTempTickets = _qTickets;

		while (!qTempTickets.empty())
		{
			stkPrefexes.push(qTempTickets.front().GetPrefix());
			qTempTickets.pop();
		}

		return stkPrefexes;
	}

	bool _NoTickets()
	{
		return (_qTickets.empty() && _TotalTickets == 0);
	}

	bool _IsServed()
	{
		return (_TotalTickets == _ServedClients());
	}

	size_t _WaitingClients()
	{
		return _qTickets.size();
	}

	size_t _ServedClients()
	{
		return _TotalTickets - _WaitingClients();
	}


public:

	clsQueueLine(string Prefix, size_t AvgServeTime)
	{
		_Prefix = Prefix;
		_AvgServeTime = AvgServeTime;
	}

	clsTicket Find(string Prefix)
	{
		if (Prefix == "" || _NoTickets())
			return clsTicket::GetEmptyTicket();

		queue <clsTicket> qTempTickets = _qTickets;
		clsTicket Ticket = clsTicket::GetEmptyTicket();

		while (!qTempTickets.empty())
		{
			Ticket = qTempTickets.front();

			if (Ticket.GetPrefix() == Prefix)
				return Ticket;

			qTempTickets.pop();
		}
		
		return clsTicket::GetEmptyTicket();
	}


	void IssueTicket()
	{
		size_t TimeToWait = _WaitingClients() * _AvgServeTime;

		_qTickets.push(clsTicket(_GetNewPrefix(), _WaitingClients(), TimeToWait));

		_TotalTickets++;
	}

	bool ServeNextClient()
	{
		if (_qTickets.empty() || _ServedClients() == _TotalTickets)
			return false;

		_qTickets.pop();

		return true;
	}


	void PrintTicket(string Prefix)
	{
		clsTicket Ticket = Find(Prefix);

		if (Ticket.IsEmptyTicket())
		{
			cout << "\n Ticket with ["<< Prefix << "] is not found ! \n\n";
			return;
		}

		cout << "\n\t\t\t\t\t       [" << Prefix <<  "] Ticket is found !\n";

		Ticket.Print();
	}

	void PrintQueueInfo()
	{
		if (_NoTickets())
		{
			cout << "\n There is not Tickets :-|";
			return;
		}

		cout << "\t\t\t\t----------------------------------------------------\n\n";

		cout << clsUtil::Tabs(6) << "     Queue Info \n\n";

		cout << "\t\t\t\t----------------------------------------------------\n\n";

		cout << clsUtil::Tabs(6) << " Prefix         " << _Prefix << "\n";
		cout << clsUtil::Tabs(6) << " Total Tickets   " << _TotalTickets << "\n";
		cout << clsUtil::Tabs(6) << " Served Clients  " << _ServedClients() << "\n";
		cout << clsUtil::Tabs(6) << " Waiting Clients " << _WaitingClients() << "\n";

		cout << "\n\t\t\t\t----------------------------------------------------\n";


		if (_IsServed())
		{
			cout << "\n" << clsUtil::Tabs(5) << "      All Clients are Served! \n";
		}
	}

	void PrintTicketsInOrder()
	{
		if (_qTickets.empty())
		{
			cout << "\nThere is not tickets :-| \n";
			return;
		}

		queue<clsTicket> qTempTickets = _qTickets;

		cout << "\n\n Tickets: ";

		while (!qTempTickets.empty())
		{
			cout << qTempTickets.front().GetPrefix() << " <-- ";
			qTempTickets.pop();
		}

		cout << "\n";
	}

	void PrintTicketsReversedOrder()
	{
		if (_qTickets.empty())
		{
			cout << "\nThere is no tickets :-| \n";
			return;
		}

		stack<string> stckPrefexes = _GetPrefexesInStack();

		cout << "\n\n Tickets: ";

		while (!stckPrefexes.empty())
		{
			cout << stckPrefexes.top() << " --> ";
			stckPrefexes.pop();
		}

		cout << "\n\n\n\n";
	}

	void PrintAllTickets()
	{
		if (_NoTickets())
		{
			cout << "\n There is not Tickets :-|";
			return;
		}

		queue<clsTicket> TempTickets = _qTickets;

		cout << "\t\t\t\t----------------------------------------------------\n\n";

		cout << clsUtil::Tabs(6) << "      Tickets \n";

		while (!TempTickets.empty())
		{
			TempTickets.front().Print();
			TempTickets.pop();
		}

		if (_IsServed())
		{
			cout << "\n All Clients Served ! \n";
		}

		cout << "\n";
	}
};