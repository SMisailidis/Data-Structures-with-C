#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    int prot;
} QueueElementType;           /*ο τύπος των στοιχείων της συνδεδεμένης ουράς
                                        ενδεικτικά τύπου int*/
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void insert_prot(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);



int main(){

    QueueType queue;
    QueueElementType item;
    int i, count=0;


    CreateQ(&queue);

    printf("DWSE TO PLITHOS: ");
    scanf("%d", &count);

    for(i=0;i<count;i++){
        printf("DWSE TON KODIKO TOU %dou KOMVOU: ", i+1);
        scanf("%d", &item.data);

        printf("DWSE TO VATHMO PROTERAIOTITAS TOU %dou KOMVOU: ", i+1);
        scanf("%d", &item.prot);

        insert_prot(&queue, item);
    }

    TraverseQ(queue);

    return 0;
}

void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void insert_prot(QueueType *Queue, QueueElementType Item)
{
    QueuePointer CurrPtr, TempPtr, PredPtr;
    boolean flag;

    TempPtr = (QueuePointer) malloc(sizeof(struct QueueNode));

    TempPtr -> Data.data = Item.data;
    TempPtr -> Data.prot = Item.prot;
    TempPtr -> Next = NULL;

    if (Queue -> Front == NULL)
    {
        Queue -> Front = TempPtr;
        Queue -> Rear = TempPtr;
    }
    else
    {
        CurrPtr = PredPtr = Queue -> Front;
        flag = FALSE;

        if (CurrPtr -> Data.prot > Item.prot)
        {
            Queue -> Front = TempPtr;
            TempPtr -> Next = CurrPtr;
        }
        else
        {
            while (CurrPtr != NULL && flag != TRUE)
            {
                if (CurrPtr -> Data.prot > Item.prot)
                {
                    PredPtr -> Next = TempPtr;
                    TempPtr -> Next = CurrPtr;
                    flag = TRUE;
                }

                PredPtr = CurrPtr;
                CurrPtr = CurrPtr -> Next;
            }

            if (!flag)
            {
                PredPtr -> Next = TempPtr;
                Queue -> Rear = TempPtr;
            }
        }
    }
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   printf("----------Priority Queue-------------\n");
   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %d\n", CurrPtr->Data.prot, CurrPtr->Data.data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
