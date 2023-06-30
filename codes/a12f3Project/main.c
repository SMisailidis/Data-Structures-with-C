#include <stdio.h>


#define QueueLimit 4

typedef struct {
    int Arrival, Stay, Start, End;
} QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void ReadCustomer(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);
void TraverseQ(char message[], QueueType Queue);


int main(){

    QueueType waitingQueue, serviceQueue;
    int i;

    CreateQ(&waitingQueue);
    CreateQ(&serviceQueue);


    for(i=1;i<QueueLimit;i++){
        printf("Give: arrival time,stay time for client %d: ", i);
        ReadCustomer(&waitingQueue);
    }

    TraverseQ("Waiting Queue", waitingQueue);
    serviceQueue = TimesInQueue(&waitingQueue);

    TraverseQ("Waiting Queue", waitingQueue);
    TraverseQ("Service Queue", serviceQueue);

    return 0;
}


void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
}


boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == Queue.Rear);
}


boolean FullQ(QueueType Queue)
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}


void RemoveQ(QueueType *Queue, QueueElementType *Item)
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
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}


void ReadCustomer(QueueType *Queue)
{
    QueueElementType tmpCustomer;

    tmpCustomer.Start = -1;
    tmpCustomer.End = -1;
    scanf("%d,%d", &tmpCustomer.Arrival, &tmpCustomer.Stay);

    AddQ(Queue, tmpCustomer);
}


QueueType TimesInQueue(QueueType *Queue)
{
    int earliestStart, currentStart, currentEnd;
    earliestStart = currentStart = currentEnd = 0;

    QueueType QueueServiced;
    QueueElementType CurrentCust;

    CreateQ(&QueueServiced);

    while ( !EmptyQ(*Queue) ){
        RemoveQ(Queue, &CurrentCust);

        if ( CurrentCust.Arrival > earliestStart ){
            currentStart = CurrentCust.Arrival;
        }

        else{
            currentStart = earliestStart;
        }

        currentEnd = currentStart + CurrentCust.Stay;
        earliestStart = currentEnd;
        CurrentCust.Start = currentStart;
        CurrentCust.End = currentEnd;

        AddQ(&QueueServiced, CurrentCust);
    }

    return QueueServiced;
}


void TraverseQ(char message[], QueueType Queue)
{
    int current, i;

    i=0;
    if ( !EmptyQ(Queue) ){
        printf("%s\n", message);

        current = Queue.Front;
        printf("Client \t\tStart\tEnd\tArrival\tStay\n");

        while ( current != Queue.Rear ){

            printf("Client %d \t%d\t%d\t%d\t%d\n", i+1, Queue.Element[i].Start, Queue.Element[i].End, Queue.Element[i].Arrival, Queue.Element[i].Stay);
            current = (current + 1) % QueueLimit;
            i++;
        }
    }
    else printf("\n%s is empty\n", message);
}

