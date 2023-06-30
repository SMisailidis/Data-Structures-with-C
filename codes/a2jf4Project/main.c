
#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
typedef struct ListNode *ListPointer;   //ο τύπος των δεικτών για τους κόμβους
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);

void insert_list_m_elements(ListPointer *List, int n);

int main(){

    int n=0;
    ListPointer List;

    CreateList(&List);

    int m=0, i;
    ListElementType item;
    ListPointer predptr = NULL;

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &m);

    for(i=0;i<m;i++){
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: ");
        scanf("%d", &item);
        LinkedInsert(&List, item, predptr);
    }

    printf("*********Arxiki lista************\n");
    LinkedTraverse(List);

    printf("\nDWSE TI THESI, META APO TIN OPOIA THA EISAXTHOUN TA STOIXEIA: ");
    scanf("%d", &n);

    insert_list_m_elements(&List, n);

    printf("*********Teliki lista************\n");
    LinkedTraverse(List);

    return 0;
}


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
   	 //   printf("%p\n",CurrPtr);
         while(CurrPtr!= NULL){
            printf("%d ", CurrPtr->Data);
            CurrPtr = CurrPtr->Next;
        }
   }
}

void insert_list_m_elements(ListPointer *List, int n){

    int m=0;
    int count=0;
    int i;
    ListElementType item;

    ListPointer curr = *List;
    ListPointer currTemp;

    if (EmptyList(*List)){
        printf("EMPTY LIST\n");
    }
    else{
        while(curr != NULL){
        count++;
        curr = curr ->Next;

        if(count == n-1){
           currTemp = curr;
        }
    }

    if(count < n || n<1){
        printf("ERROR\n");
    }
    else{
        printf("DWSE TO PLITHOS TWN STOIXEIWN POU THA EISAXTHOUN: ");
        scanf("%d",&m);
        for(i=0;i<m;i++){
            printf("DWSE TON ARI8MO GIA EISAGWGH STH LISTA: ");
            scanf("%d", &item);
            LinkedInsert(List, item, currTemp);

            currTemp = currTemp ->Next;
        }
    }

    }



}
