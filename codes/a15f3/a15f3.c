#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 10 //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

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
    QueueType queue;
    QueueElementType i, number;

    CreateQ(&queue);

    /******a******/
    printf("(a)\n");
    for(i=1;i<=QueueLimit;i++){
        if((i*3)%3==0){
            AddQ(&queue, i*3);
        }
    }
    TraverseQ(queue);



    /******b******/
    printf("(b)\n");
    do {
        printf("Give me a number:");
        scanf("%d", &number);

        if(number%3!=0){
            printf("Give a multiple of 3\n");
        }
    }while(number%3!=0);

    AddQ(&queue, number);
    TraverseQ(queue);

    /******c******/
    printf("(c)\n");
    RemoveQ(&queue, &number);
    TraverseQ(queue);
    printf("Removed item=%d\n", number);

    /******d******/
    printf("(d)\n");

    for(i=0;i<2;i++){

        do {
            printf("Give me a number:");
            scanf("%d", &number);

            if(number%3!=0){
                printf("Give a multiple of 3\n");
            }
        }while(number%3!=0);

        AddQ(&queue, number);
        TraverseQ(queue);
    }


    /******e******/
    printf("(e)\n");
    while(!EmptyQ(queue)){
        RemoveQ(&queue, &number);
        TraverseQ(queue);
        printf("Removed item=%d\n", number);
    }

    return 0;
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	//return (Queue.Front == Queue.Rear);
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	//return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
	return (Queue.Count == QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue->Count--;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue->Count++;
	}
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue) {
	int current;
	printf("Queue: ");
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    for(int i=0;i<Queue.Count;i++) {
            printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
	   printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);
    }
    else printf("Empty Queue\n");
}
