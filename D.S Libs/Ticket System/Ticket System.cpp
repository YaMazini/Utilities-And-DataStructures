
#include <iostream>
#include "clsQueueLine.h"

using namespace std;

int main()
{

    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);


    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();

    cout << "\nPay Bills Queue Info:\n";
    PayBillsQueue.PrintQueueInfo();

    PayBillsQueue.PrintTicketsInOrder();
    PayBillsQueue.PrintTicketsReversedOrder();


    PayBillsQueue.PrintTicket("A1");



    PayBillsQueue.PrintAllTickets();

    PayBillsQueue.ServeNextClient();
    PayBillsQueue.ServeNextClient();
    PayBillsQueue.ServeNextClient();
    PayBillsQueue.ServeNextClient();
    PayBillsQueue.ServeNextClient();
    
    cout << "\nPay Bills Queue After Serving One client\n";
    PayBillsQueue.PrintQueueInfo();



    cout << "\n\n\nSubscriptions Queue Info:\n";

    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();


    SubscriptionsQueue.PrintQueueInfo();

    SubscriptionsQueue.PrintTicketsInOrder();
    SubscriptionsQueue.PrintTicketsReversedOrder();

    SubscriptionsQueue.PrintAllTickets();

    SubscriptionsQueue.ServeNextClient();
    cout << "\nSubscriptions Queue After Serving One client\n\n";
    SubscriptionsQueue.PrintQueueInfo();


    return 0;
}

