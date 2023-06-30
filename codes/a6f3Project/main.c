#include <stdio.h>
#include <stdlib.h>

/* Queue */
#define QueueLimit 10  //�� ���� �������� ��� �����

typedef int QueueElementType;   /* � ����� ��������� ��� ��������� ��� �����
                                  ���������� ����� int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
    int Count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void TraverseQ(QueueType Queue);


int main()
{
    QueueType Queue;
    QueueElementType i, removedItem;

    CreateQ(&Queue);

    //--a--//
    printf("---a---\n");
    for(i=0; i<QueueLimit; i++){
        AddQ(&Queue, i);
    }
    printf("Queue: ");
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);


    //--b--//
    printf("---b---\n");
    AddQ(&Queue, 25);
    printf("\nQueue: ");
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front, Queue.Rear, Queue.Count);

    //--c--//
    printf("---c---\n");
    RemoveQ(&Queue, &removedItem);
    printf("Queue: ");
    TraverseQ(Queue);
    printf("Removed item=%d Front=%d Rear=%d Count=%d\n", removedItem, Queue.Front, Queue.Rear, Queue.Count);

    //--d--//
    printf("---d---\n");
    AddQ(&Queue, 25);
    printf("Queue: ");
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front, Queue.Rear, Queue.Count);

    //--e--//
    printf("---e---\n");
    AddQ(&Queue, 25);
    printf("\nQueue: ");
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front, Queue.Rear, Queue.Count);

    //--f--//
    printf("---f---\n");
    while(!EmptyQ(Queue)){
        RemoveQ(&Queue, &removedItem);
        printf("Queue: ");
        TraverseQ(Queue);
        printf("Removed item=%d Front=%d Rear=%d Count=%d\n", removedItem, Queue.Front, Queue.Rear, Queue.Count);
    }
    return 0;
}

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
		printf("Full Queue");
}


void TraverseQ(QueueType Queue) {
	int current, i;

	if(EmptyQ(Queue))
        printf("Empty Queue");
	current = Queue.Front;
	for(i=0; i<Queue.Count; i++) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}
