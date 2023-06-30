#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 21  //�� ���� �������� ��� �����

typedef int QueueElementType;   /* � ����� ��������� ��� ��������� ��� �����
                                  ���������� ����� int */

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

void GetNthElementValueA (QueueType *Q, int n, QueueElementType *item);
void GetNthElementValueB (QueueType Q, int n, QueueElementType *item);
void TraverseQ(QueueType Queue);

int main()
{
    QueueElementType item, i;
    QueueType AQueue;
    int n;

    CreateQ(&AQueue);

    for(i=1;i<QueueLimit;i++){
        AddQ(&AQueue, i*5);
    }

    TraverseQ(AQueue);

    do {
        printf("Dwse n: ");
        scanf("%d", &n);
    }while(n > AQueue.Rear - AQueue.Front);

    GetNthElementValueA(&AQueue, n, &item);
    printf("%d\n", item);

    GetNthElementValueB(AQueue, n, &item);
    printf("%d\n", item);

    TraverseQ(AQueue);

    return 0;
}

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
		printf("Empty Queue\n");
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
		printf("Full Queue\n");
}

void GetNthElementValueA(QueueType *Q, int n, QueueElementType *item) {

    QueueType tempQ;
    QueueElementType tempI;

    CreateQ(&tempQ);

    for(int i=1;i<=n;i++){
        RemoveQ(Q, &tempI);
        AddQ(&tempQ, tempI);
    }
    *item = tempI;

    while(!EmptyQ(*Q)){
        RemoveQ(Q, &tempI);
        AddQ(&tempQ, tempI);
    }

    while(!EmptyQ(tempQ)) {
        RemoveQ(&tempQ, &tempI);
        AddQ(Q, tempI);
    }
}

void GetNthElementValueB(QueueType Q, int n, QueueElementType *item) {

    int index = n-1;

    *item = Q.Element[(Q.Front + index) % QueueLimit];
}

void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}
