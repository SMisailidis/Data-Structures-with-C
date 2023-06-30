/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a16f4
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

/* QueueElementType as Structure */
typedef struct{
    int code;
    int priority;
}QueueElementType;

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

/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
/*######################################################################################*/

/*################################## MY NEW FUNCTIONS ##################################*/
void insert_prot(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
/*######################################################################################*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    /* Variables Declarations and Initialization */
    QueueType myQueue;
    QueueElementType itemQueue;
    int numberOfInputs, countNum=1;;

    /* Queue creation */
    CreateQ(&myQueue);

    /* The total number of user inputs */
    printf("DWSE TO PLITHOS: ");
    scanf("%d", &numberOfInputs);

    /* Queue data input values */
    if(numberOfInputs > 0){
        do{
            printf("DWSE TON KODIKO TOU %dou KOMVOU: ", countNum);
            scanf("%d", &itemQueue.code);

            printf("DWSE TO VATHMO PROTERAIOTITAS TOU %dou KOMVOU: ", countNum);
            scanf("%d", &itemQueue.priority);

            insert_prot(&myQueue, itemQueue);

            countNum++;
        } while(countNum<=numberOfInputs);
    }


    /* Display Queue */
    TraverseQ(myQueue);

    return 0;
}



/*############################### DO NOT CHANGE THE FUNCTIONS ###############################*/
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
/*###########################################################################################*/

/*#################################### MY NEW FUNCTIONS #####################################*/
void insert_prot(QueueType *Queue, QueueElementType Item){
	QueuePointer TempPtr;
    QueuePointer CurrPtr;
    QueuePointer PredPtr;
    boolean flag;

    TempPtr = (QueuePointer)malloc(sizeof(struct QueueNode));

    TempPtr->Data = Item;
    TempPtr->Next = NULL;


    if (Queue->Front==NULL){   /* If Queue is Empty */
        Queue->Front = TempPtr; /* Update Queue Front Index with new NODE. */
        Queue->Rear = TempPtr; /* Update Queue Rear Index with new NODE. */

    } else {
        CurrPtr = Queue->Front; /* Initialize CurrPtr at Queue Front. */
        PredPtr = Queue->Front; /* Initialize PredPtr at Queue Front. */
        flag = FALSE; /* Check Input Flag, TRUE is data input. */

        if(CurrPtr->Data.priority > TempPtr->Data.priority){
            Queue->Front = TempPtr; /* Update Queue Front Index with new NODE. */
            TempPtr->Next = CurrPtr; /* Update new NODE Next index with Current Node. */

        } else {
            while(CurrPtr!=NULL && flag != TRUE){
                if(CurrPtr->Data.priority > TempPtr->Data.priority){
                    PredPtr->Next = TempPtr; /* Update Predecessor Node Next index with new Node. */
                    TempPtr->Next = CurrPtr; /* Update new NODE Next index with Current Node. */
                    flag = TRUE;
                }
                PredPtr = CurrPtr;
                CurrPtr = CurrPtr->Next;
            }
            if(flag==FALSE){
                PredPtr->Next = TempPtr; /* Update Predecessor Node Next index with new Node. */
                Queue->Rear = TempPtr; /* Update Queue Rear Index with new NODE. */
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
             printf("%d ", CurrPtr->Data.priority);
      	     printf("%d \n", CurrPtr->Data.code);

             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
/*###########################################################################################*/
