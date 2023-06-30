/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Author: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Email: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a5f2
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define StackLimit 15 // Το όριο του μεγέθους της στοίβας.


typedef int StackElementType; // Ο τύπος των στοιχείων της στοίβας ως int.

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

/* Functions */
void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
boolean FullStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
void TraverseStack(StackType Stack);

int main() {

    /* Variables */
    StackElementType x, i, n, temp;
    StackType Stack, tempS;

    /* The Stack Creation */
    CreateStack(&Stack);

    /* Generate Data Values for the Stack */
    for(i=0;i<StackLimit;i++)
    {
      Push(&Stack, i*10);
    }

    /* Display the Stack */
    TraverseStack(Stack);

     /* The nth element User Input */
    printf("Give nth element (n<=%d) ", (Stack.Top-1)/2);
    scanf("%d", &n);

    //Ερωτημα a)

    Pop(&Stack, &x);
    Pop(&Stack, &x);

    printf("\nQuestion a: x=%d\n", x);

    TraverseStack(Stack);


    //Ερωτημα b)

    Pop(&Stack, &temp);
    Pop(&Stack, &x);

    Push(&Stack, x);
    Push(&Stack, temp);

    printf("\nQuestion b: x=%d\n", x);
    TraverseStack(Stack);


    //Ερωτημα c)

    for(i=0;i<n;i++)
        Pop(&Stack, &x);

    printf("\nQuestion c: x=%d\n", x);
    TraverseStack(Stack);


    //Ερωτημα d)

    CreateStack(&tempS);

    for(i=0;i<n;i++)
    {
        Pop(&Stack, &x);
        Push(&tempS, x);
    }

    printf("\nQuestion d: x=%d\n", x);
    while(!EmptyStack(tempS))
    {
        Pop(&tempS, &x);
        Push(&Stack, x);
    }

    TraverseStack(Stack);

   //Ερωτημα e)

   while(!EmptyStack(Stack))
   {
        Pop(&Stack, &x);
        Push(&tempS, x);
   }
    printf("\nQuestion e: x=%d\n", x);


   while(!EmptyStack(tempS))
   {
        Pop(&tempS, &x);
        Push(&Stack, x);
   }

    TraverseStack(Stack);


   //Ερωτημα f)


   while(Stack.Top >= 2)//Διοτι το 1ο στοιχειο ειναι απο την θεση 0
   {
        Pop(&Stack, &x);
        Push(&tempS, x);
   }
    printf("\nQuestion f: x=%d\n", x);

   while(!EmptyStack(tempS))
   {
        Pop(&tempS, &x);
        Push(&Stack, x);
   }
    TraverseStack(Stack);

    //Ερωτημα g)

    while(!EmptyStack(Stack))
        Pop(&Stack, &x);

    printf("\nQuestion g: x=%d\n", x);
    TraverseStack(Stack);


    return 0;
    system("PAUSE");
}


void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

/* ΕΜΦΑΝΙΖΕΙ ΤΑ STOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ 0-TOP */
 void TraverseStack(StackType Stack){
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
