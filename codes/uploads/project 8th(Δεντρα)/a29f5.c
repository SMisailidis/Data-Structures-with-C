/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a29f5
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int amka_value;
    int afm_value;
    int age_value;

} BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

/*######################################### MODIFIED ADT FUNCTIONS #######################################*/
void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
/*########################################################################################################*/

/*########################################### MY NEW FUNCTIONS ###########################################*/
void InorderTraversal(BinTreePointer Root);
/*########################################################################################################*/

int main(){

    /* Variables Declarations and Initialization */
    /*Notes: rootCategoryA for <=60 age Group and rootCategoryB for >=60 age group */
    BinTreePointer rootCategoryA, rootCategoryB, LocPtr;
    BinTreeElementType personAttributes = {.amka_value=999,
                                           .afm_value=999,
                                           .age_value=999};
    boolean Found;
    char ch;
    int i;

    /* Creation: The Binary Search Tree */
    CreateBST(&rootCategoryA); // <=60
    CreateBST(&rootCategoryB); // >60

    /* Attributes Data Input */
	do{
        printf("Give AMKA? ");
        scanf("%d", &personAttributes.amka_value);
        printf("Give AFM? ");
        scanf("%d", &personAttributes.afm_value);
        printf("Give age? ");
        scanf("%d", &personAttributes.age_value);

        if (personAttributes.age_value<=60)
            BSTInsert(&rootCategoryA, personAttributes);
        else
            BSTInsert(&rootCategoryB, personAttributes);

        printf("\nContinue Y/N: ");
        do{
            scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');

    /* Display Results by Categories */
    printf("\nPeople with age less-equal 60\n");
    InorderTraversal(rootCategoryA);

    printf("\n\nPeople with age greater than 60\n");
    InorderTraversal(rootCategoryB);

/*-------------------------------------------------------------------------------------------------------------------*/

    /* Search Specific Person with AMKA and AGE attributes */
    for (i=1;i<=3;i++){
            printf("\nGive AMKA: ");
            scanf("%d", &personAttributes.amka_value);
            printf("Give age: ");
            scanf("%d", &personAttributes.age_value);

            if (personAttributes.age_value<=60)
                BSTSearch(rootCategoryA, personAttributes, &Found, &LocPtr);
            else
                BSTSearch(rootCategoryB, personAttributes, &Found, &LocPtr);

            if (Found==TRUE){
                if (LocPtr->Data.age_value==personAttributes.age_value)
                    printf("The person with AMKA %d, AFM %d and age %d is in the catalogue ",LocPtr->Data.amka_value,
                                                                                                LocPtr->Data.afm_value,
                                                                                                LocPtr->Data.age_value);
                    else
                        printf("The person with AMKA %d has age %d different from the person you are looking for ",LocPtr->Data.amka_value,
                                                                                                                       LocPtr->Data.age_value);

            } else printf("The person with AMKA %d and age %d is Unknown ", personAttributes.amka_value , personAttributes.age_value);

    } //END For-Loop

    return 0;

} // END main()


/*######################################### MODIFIED ADT FUNCTIONS #######################################*/
void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.amka_value < LocPtr->Data.amka_value) // Changed.
            LocPtr = LocPtr ->LChild;
        else if (Item.amka_value > LocPtr ->Data.amka_value) // Changed.
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item.amka_value);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));

        LocPtr ->Data = Item; // DO NOT CHANGE.

        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.amka_value < Parent ->Data.amka_value) // Changed.
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue.amka_value < (*LocPtr)->Data.amka_value) // Changed.
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue.amka_value > (*LocPtr)->Data.amka_value) // Changed.
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}
/*########################################################################################################*/

/*########################################### MY NEW FUNCTIONS ###########################################*/
void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d, %d, %d) ",Root->Data.amka_value,
                               Root->Data.afm_value,
                               Root->Data.age_value);
        InorderTraversal(Root->RChild);
    }
}
/*########################################################################################################*/
