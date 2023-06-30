#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define QueueLimit1 3
#define QueueLimit2 20

typedef char QueueElementType1[25];

typedef struct {
	int Front, Rear;
	QueueElementType1 Element[QueueLimit1];
} QueueType1;

typedef struct {
    int Front, Rear;
    QueueElementType1 name;
    int code;
    char phoneNumber[10];
}QueueElementType2;

typedef struct {

    int Front, Rear;
    QueueElementType2 Element[QueueLimit2];
}QueueType2;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType1 *Queue);
boolean EmptyQ(QueueType1 Queue);
boolean FullQ(QueueType1 Queue);
void RemoveQ(QueueType1 *Queue, QueueElementType1 *Item);
void AddQ(QueueType1 *Queue, QueueElementType1 Item);

void CreateWQ(QueueType2 *Queue);
boolean EmptyWQ(QueueType2 Queue);
boolean FullWQ(QueueType2 Queue);
void RemoveWQ(QueueType2 *Queue, QueueElementType2 *Item);
void AddWQ(QueueType2 *Queue, QueueElementType2 Item);

void newAppointment(int code, QueueType1 *Q, QueueType2 *waitingQ);
void showQ(QueueType1 Queue, int code);
void showWaitingQ(QueueType2 Queue);

int main()
{
    QueueType1 Q[6];
    QueueType2 waitingQ;

    int i;
    for(i=1;i<6;i++) {
        CreateQ(&Q[i]);
    }

    CreateWQ(&waitingQ);


    srand(54);

    char answer;
    do {
        int code = rand() % 5 + 1;

        newAppointment(code, &Q[code], &waitingQ);

        printf("Continue Y/N (Y=yes, N=No): ");
        do{
            scanf("%c",&answer);
        } while (toupper(answer)!='N' && toupper(answer)!='Y');
    }while(answer != 'N' && answer != 'n');

    for(i=1;i<6;i++){
        showQ(Q[i], i);
    }

    showWaitingQ(waitingQ);

    return 0;
}

void CreateQ(QueueType1 *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType1 Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType1 Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit1));
}

void RemoveQ(QueueType1 *Queue, QueueElementType1 *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		strcpy(*Item, Queue->Element[Queue->Front]);
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit1;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType1 *Queue, QueueElementType1 Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if (!FullQ(*Queue))
    {
        strcpy(Queue->Element[Queue->Rear], Item);
        Queue->Rear = (Queue->Rear + 1) % QueueLimit1;
    }
    else
    {
        printf("Full Queue\n");
    }
}

void CreateWQ(QueueType2 *Queue) {

	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyWQ(QueueType2 Queue) {

    return (Queue.Front == Queue.Rear);
}

boolean FullWQ(QueueType2 Queue) {

    return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit1));
}

void RemoveWQ(QueueType2 *Queue, QueueElementType2 *Item) {

    if(!EmptyWQ(*Queue))
	{
		*Item = Queue->Element[Queue->Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit1;
	}
	else
		printf("Empty Queue\n");
}

void AddWQ(QueueType2 *Queue, QueueElementType2 Item) {

    if (!FullWQ(*Queue))
    {
        Queue->Element[Queue->Rear] = Item;
        Queue->Rear = (Queue->Rear + 1) % QueueLimit1;
    }
    else
    {
        printf("Full Queue\n");
    }
}

void newAppointment(int code, QueueType1 *Q, QueueType2 *waitingQ) {

    boolean flag = FALSE;
    QueueElementType1 tempName;
    QueueElementType2 temp;

    printf("Give your name: ");
    scanf("%s", tempName);
    //gets(tempName); Errors
    if(!FullQ(*Q)) {
        AddQ(Q, tempName);
        printf("Successful appointment for clinic %d\n", code);
    }
    else {
        flag = TRUE;
    }

    if(flag) {
        printf("You are in a waiting list\n");
        printf("Give your phone number: ");
        scanf("%s", temp.phoneNumber);
        //gets(temp.phoneNumber); Errors
        temp.code = code;
        strcpy(temp.name, tempName);
        AddWQ(waitingQ, temp);
    }
}

void showQ(QueueType1 Queue, int code) {

    printf("\nAppointments of clinic %d\n",code);
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%s\n", Queue.Element[current]);
		  current = (current + 1) % QueueLimit1;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}

void showWaitingQ(QueueType2 Queue) {

    QueueElementType2 temp;
    int current;
	if (!EmptyWQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            temp = Queue.Element[current];
            printf("%s, %d, %s\n", temp.name, temp.code, temp.phoneNumber);
		  current = (current + 1) % QueueLimit1;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}
