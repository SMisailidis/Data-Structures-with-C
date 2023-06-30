/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a6f3
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

/* Queue */
#define QueueLimit 10  // The Queue length limit.

typedef int QueueElementType;   // The Queue element data type as int.

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
    int Count;  // Count variable as queue index.
} QueueType;

typedef enum {FALSE, TRUE} boolean;

/*############################### ADT QUEUE MODIFIED FUNCTIONS ###############################*/
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
/*############################################################################################*/

/*##################################### MY NEW FUNCTIONS #####################################*/
void TraverseQ(QueueType Queue);
/*############################################################################################*/

int main(){

    /* Declarations and Variable Initializations */
    QueueType Queue;
    QueueElementType i, item;

    /* The Queue Creation */
    CreateQ(&Queue);

    /* Generate Data Values for the Queue */
    for(i=0; i<QueueLimit; i++){
        AddQ(&Queue, i);
    }

    /* Queue Implementations */
    printf("---a---\n");
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);

    printf("---b---\n");
    AddQ(&Queue, 25);
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front, Queue.Rear, Queue.Count);

    printf("---c---\n");
    RemoveQ(&Queue, &item);
    TraverseQ(Queue);
    printf("Removed item=%d Front=%d Rear=%d Count=%d\n", item, Queue.Front, Queue.Rear, Queue.Count);

    printf("---d---\n");
    AddQ(&Queue, 25);
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front, Queue.Rear, Queue.Count);

    printf("---e---\n");
    AddQ(&Queue, 25);
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front, Queue.Rear, Queue.Count);

    printf("---f---\n");
    while(!EmptyQ(Queue)){
        RemoveQ(&Queue, &item);
        TraverseQ(Queue);
        printf("Removed item=%d Front=%d Rear=%d Count=%d\n", item, Queue.Front, Queue.Rear, Queue.Count);
    }
    return 0;
} // END Main ()

void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Count==0);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return (Queue.Count==QueueLimit);
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
		Queue->Count -= 1;
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
		Queue ->Count += 1;
	}
	else
		printf("Full Queue\n");
}


void TraverseQ(QueueType Queue) {
	int current, i;
	if(EmptyQ(Queue))
        printf("Queue: Empty Queue");

    else{
	current = Queue.Front;
    printf("Queue: ");
	for(i=0; i<Queue.Count; i++) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
    }
	printf("\n");
}
