/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a17f2
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define StackLimit 20   // Stack Total Limit (total inputs 20).

typedef int StackElementType;    // StackElementType as int.

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
/*######################################################################################*/

/*################################## MY NEW FUNCTIONS ##################################*/
void TraverseStack(StackType Stack);
StackType CopyStack(StackType *s1);
/*######################################################################################*/


int main(){

    /* Declarations and Variable Initializations */
    StackType s1, s2;   // The s1 and s2 Stack.
    StackElementType i; // The Stack items as StackElementType.

    /* The Stack s1 Creation */
    CreateStack(&s1);

    /* Generate Data Values for the Stack s1 */
    for(i=0;i<StackLimit;i++)
        Push(&s1, i);

    /* Display the s1 Stack */
    printf("Stack s1\n");
    TraverseStack(s1);

    /* CopyStack Function Implementation, Copy s1 to s2 */
    s2 = CopyStack(&s1);

    /* After CopyStack Function Implementation */
    printf("After copying s1 to s2\n");

    /* Display s1 and s2 after Copying Process */
    printf("Stack s1\n");
    TraverseStack(s1);

    printf("Stack s2\n");
    TraverseStack(s2);

    return 0;
} // END main()

/*############################### DO NOT CHANGE THE FUNCTIONS ###############################*/
void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται:    Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}
/*###########################################################################################*/


/*#################################### MY NEW FUNCTIONS #####################################*/
/* Display all Elements of a Stack 0-TOP */
void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

/* Create and Return a Copy of Given Stack */
StackType CopyStack(StackType *s1){

    StackElementType t;
    StackType s2, s3;

    CreateStack(&s2);
    CreateStack(&s3);

    while(!EmptyStack(*s1)){
        Pop(s1, &t);
        Push(&s3, t);
    }

    while(!EmptyStack(s3)){
        Pop(&s3, &t);
        Push(s1, t);
        Push(&s2, t);
    }

    return s2;
}
/*###########################################################################################*/
