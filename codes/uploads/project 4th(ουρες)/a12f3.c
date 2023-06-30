/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a12f3
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 4  // The Queue length limit (3 indices (Customers) and 1 Empty Space) .

/* QueueElementType as Structure */
typedef struct{
    int customerArrival;
    int customerStay;
    int serviceStart;
    int serviceEnd;
}QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
/*######################################################################################*/

/*################################## MY NEW FUNCTIONS ##################################*/
void TraverseQ(char QueueTitle[], QueueType Queue); // Function #3.
void ReadCustomer(QueueType *Queue); // Function #1.
QueueType TimesInQueue(QueueType *Queue); // Function #2.
/*######################################################################################*/


int main(){

    /* Declarations and Variable Initializations */
    QueueType waitingQueue, serviceQueue;
    int i;

    /* Waiting and Service Queues Creation */
    CreateQ(&waitingQueue);
    CreateQ(&serviceQueue);

    /* Input Customers Time Data in waitingQueue */
    for(i=1;i<QueueLimit;i++){
        printf("Give: arrival time,stay time for client %d: ", i);
        ReadCustomer(&waitingQueue);
    }

    /* Display Customers Waiting Queue */
    TraverseQ("Waiting Queue", waitingQueue);

    /* Customer Service Implementations on Waiting Queue  */
    serviceQueue = TimesInQueue(&waitingQueue);

    /* Display Waiting Queue After Customer Service */
    TraverseQ("Waiting Queue", waitingQueue);

    /* Display Customers Service Queue */
    TraverseQ("Service Queue", serviceQueue);

    return 0;
} // END main()


/*############################### DO NOT CHANGE THE FUNCTIONS ###############################*/
void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}
/*###########################################################################################*/


/*#################################### MY NEW FUNCTIONS #####################################*/
/* Function #3 */
void TraverseQ(char QueueTitle[], QueueType Queue) {
	int current;
	int customerID = 0;

    if(!EmptyQ(Queue)){

        printf(QueueTitle);

        current = Queue.Front;
        printf("\nClient  \t\tStart\tEnd\tArrival\tStay\n");

        while (current != Queue.Rear) {
            customerID++;
            printf("Client %d  \t\t%d\t%d\t%d\t%d\n",customerID, Queue.Element[current].serviceStart,
                   Queue.Element[current].serviceEnd, Queue.Element[current].customerArrival,
                   Queue.Element[current].customerStay);

            current = (current + 1) % QueueLimit;
        }

    } else printf("\n%s is empty\n", QueueTitle);

}

/* Function #1 */
void ReadCustomer(QueueType *Queue){

    QueueElementType customerData;

    scanf("%d,%d", &customerData.customerArrival, &customerData.customerStay);
    customerData.serviceStart = -1;
    customerData.serviceEnd = -1;

    AddQ(Queue,customerData);

}

/* Function #2 */
QueueType TimesInQueue(QueueType *Queue){

    int serviceTimeStart = 0; // Service Time START.
    int currentCustomerServiceStart = 0; // Service Time START of Current Customer.
    int currentCustomerServiceEnd = 0; //  Service Time END of Current Customer.

    QueueType QueueServiced;
    QueueElementType CurrentCust;

    CreateQ(&QueueServiced);

    while(!EmptyQ(*Queue)){

        RemoveQ(Queue, &CurrentCust);

        if(CurrentCust.customerArrival > serviceTimeStart)
            currentCustomerServiceStart = CurrentCust.customerArrival;
        else
            currentCustomerServiceStart = serviceTimeStart;

        currentCustomerServiceEnd = currentCustomerServiceStart + CurrentCust.customerStay;

        serviceTimeStart = currentCustomerServiceEnd;

        CurrentCust.serviceStart = currentCustomerServiceStart;
        CurrentCust.serviceEnd = currentCustomerServiceEnd;

        AddQ(&QueueServiced,CurrentCust);

    }

    return QueueServiced;
}
