/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a2cf4
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;    // The List element data type as int.
typedef struct ListNode *ListPointer;   // The List pointer data type as struct for Nodes.

typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;

/*############################### DO NOT CHANGE THE FUNCTIONS ###############################*/
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
/*###########################################################################################*/

/*#################################### MY NEW FUNCTIONS #####################################*/
void concat_list(ListPointer AList, ListPointer BList, ListPointer *FinalList);
/*###########################################################################################*/

int main()
{
    /* Variables Declarations */
    ListPointer alist, blist, finalList;
    ListPointer predPtr=NULL;
    ListElementType item;
    int pl, i;

    /* The Lists Creation */
    CreateList(&alist);
    CreateList(&blist);
    CreateList(&finalList);

    /* User Input - List 1 Data */
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
    scanf("%d", &pl);

    for(i=0; i<pl; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1: ");
        scanf("%d", &item);
        LinkedInsert(&alist, item, predPtr);
    }

     /* User Input - List 2 Data */
     printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
     scanf("%d", &pl);

    for(i=0; i<pl; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2: ");
        scanf("%d", &item);
        LinkedInsert(&blist, item, predPtr);
    }

    /* Display List 1 */
    printf("LISTA 1:\n");
    LinkedTraverse(alist);

    /* Display List 2 */
    printf("LISTA 2:\n");
    LinkedTraverse(blist);

    /* Concatenate  List 1 and List 2 to a Final List*/
    concat_list(alist, blist, &finalList);
    printf("SYNENWMENH LISTA:\n");
    LinkedTraverse(finalList);
}

/*#################################### MY NEW FUNCTIONS #####################################*/
void concat_list(ListPointer AList, ListPointer BList, ListPointer *FinalList)
{
    ListPointer currPtr, predPtr;

    predPtr=NULL;

    currPtr = AList;
    while(currPtr!=NULL)
    {
        LinkedInsert(FinalList, currPtr->Data, predPtr);
        currPtr = currPtr->Next;
    }

    currPtr = BList;
    while(currPtr!=NULL)
    {
        LinkedInsert(FinalList, currPtr->Data, predPtr);
        currPtr = currPtr->Next;
    }
}
/*###########################################################################################*/

/*############################### DO NOT CHANGE THE FUNCTIONS ###############################*/
void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
  Επιστρέφει:  Τον μηδενικό δείκτη List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
  Επιστρέφει: True αν η λίστα είναι κενή και false διαφορετικά
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο,
                ένα στοιχείο δεδομένων Item και έναν δείκτη PredPtr.
   Λειτουργία: Εισάγει έναν κόμβο, που περιέχει το Item, στην συνδεδεμένη λίστα
                μετά από τον κόμβο που δεικτοδοτείται από τον PredPtr
                ή στην αρχή  της συνδεδεμένης λίστας,
                αν ο PredPtr είναι μηδενικός(NULL).
  Επιστρέφει:  Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο της
                να δεικτοδοτείται από τον List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}
/*###########################################################################################*/


void LinkedTraverse(ListPointer List)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
   Λειτουργία: Διασχίζει τη συνδεδεμένη λίστα και
                επεξεργάζεται κάθε δεδομένο ακριβώς μια φορά.
   Επιστρέφει: Εξαρτάται από το είδος της επεξεργασίας.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;

         while ( CurrPtr!=NULL )
        {
             printf("%d ", (*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");

}
