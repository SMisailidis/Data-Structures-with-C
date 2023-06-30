/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a2jf4
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType; // The List element data type as int.
typedef struct ListNode *ListPointer; // The List pointer data type as struct for Nodes.
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
/*###########################################################################################*/

/*#################################### MY NEW FUNCTIONS #####################################*/
void list_insertion(ListPointer *List, int list_range);
void LinkedTraverse(ListPointer List);
void insert_list_m_elements(ListPointer *List, int n);
/*###########################################################################################*/

int main(){

    /* Variables Declarations */
    ListPointer myList;
    int listRange, n;

    /* The Lists Creation */
    CreateList(&myList);

    /* User Input Data - List */
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &listRange);
    list_insertion(&myList, listRange);

    /* Display the Initial List */
    printf("*********Arxiki lista************ \n");
    LinkedTraverse(myList);
    if(listRange==0) return 0; // Display Empty List and then program stop the execution.

    /* User Input Index - For new List Data */
    printf("DWSE TI THESI, META APO TIN OPOIA THA EISAXTHOUN TA STOIXEIA: ");
    scanf("%d", &n);
    insert_list_m_elements(&myList, n);

    /* Display the Final List */
    printf("*********Teliki lista************ \n");
    LinkedTraverse(myList);

    return 0;
} // END main()

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

/*#################################### MY NEW FUNCTIONS #####################################*/
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
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void list_insertion(ListPointer *List, int list_range){
 	ListElementType Item;
    ListPointer PredPtr;

    PredPtr = NULL;

    if(list_range!=0){ // list_range == 0 means EMPTY LIST
        do{
            printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: "); scanf("%d", &Item);
            LinkedInsert(List, Item, PredPtr);

            list_range--;

        } while (list_range!=0);
    }
}

void insert_list_m_elements(ListPointer *List, int n){
 	ListElementType Item;
    ListPointer CurrPtr;
    int i, m;

    CurrPtr = *List;
    i = 1;

   if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else{
        while (CurrPtr->Next!=NULL && i<n){ // CurrPtr->Next == NULL, when we are next from the last node.
            CurrPtr = CurrPtr->Next; // update the next list index in CurrPtr.
            i++;
        }
        if (i<n || n<1)
            printf("ERROR\n");
        else{
            printf("DWSE TO PLITHOS TWN STOIXEIWN POU THA EISAXTHOUN: "); scanf("%d", &m);
            if (m>0){
                do{
                    printf("DWSE TON ARI8MO GIA EISAGWGH STH LISTA: "); scanf("%d", &Item);
                    LinkedInsert(List, Item, CurrPtr);
                    CurrPtr = CurrPtr->Next;
                    m--;
                } while (m!=0);

            }

        }
   }
}
/*###########################################################################################*/
