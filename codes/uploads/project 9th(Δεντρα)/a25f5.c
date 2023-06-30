/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3

   Author: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios

   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Email: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a25f5
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;

/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTInorder(BinTreePointer Root);
/*######################################################################################*/

/*################################## MY NEW FUNCTIONS ##################################*/
int CountLeaves(BinTreePointer Root);
/*######################################################################################*/

int main(){

    /* Variables Declarations and Initialization */
    BinTreePointer myRoot;
    BinTreeElementType rootItem;
    char ch = '-';
    int numberLeaves = 0;

    /* Creation: The Binary Search Tree */
    CreateBST(&myRoot);

    /* Insertion: Numbers in the Tree */
    do {
        printf("Enter a number for insertion in the Tree: ");
        scanf("%d", &rootItem);
        RecBSTInsert(&myRoot, rootItem);
        printf("Continue Y/N: ");
        do {
            scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');

    /* Display Tree Results */
    printf("Elements of BST\n");
    RecBSTInorder(myRoot);

    /* Calculate and Display the Leaves of Tree */
    numberLeaves = CountLeaves(myRoot);
    printf("\nNumber of leaves %d\n", numberLeaves);

    return 0;

}// END main()


/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("%d ",Root->Data);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}
/*######################################################################################*/

/*################################## MY NEW FUNCTIONS ##################################*/
int CountLeaves(BinTreePointer Root){

  if(Root == NULL) return 0;

  if(Root->LChild == NULL && Root->RChild == NULL ){
    return 1;
  } else return CountLeaves(Root->LChild) + CountLeaves(Root->RChild);
}
/*######################################################################################*/
