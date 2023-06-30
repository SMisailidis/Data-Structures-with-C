/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a11f5
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_SIZE 50

typedef char BinTreeElementType[MAX_CHAR_SIZE]; // Char array.

typedef struct BinTreeNode *BinTreePointer;

 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};

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
void CreateDictionary(BinTreePointer *Root, FILE *fp);
void InorderTraversal(BinTreePointer Root);
int SpellingCheck(BinTreePointer Root, FILE *fp);
/*########################################################################################################*/


int main(){

    /* Variables Declarations and Initialization */
    FILE *dicData = NULL; // The creation of the File Pointer with NULL initialization.
    FILE *spellCheckingData = NULL;
    BinTreePointer bstROOT;
    int notFoundCount = 0;

    /* Dictionary and Spell Checking file data with Read Only mode */
    dicData = fopen("i112f5.txt", "r");
    spellCheckingData = fopen("i111f5.txt", "r");

    /* File Check ERROR Message */
    if(dicData == NULL){
        printf("Dictionary file data does not exist\n");
        return -1;
    } else if (spellCheckingData == NULL){
        printf("Spell Checking file data does not exist\n");
        return -1;
    }

    /* Creation: The Binary Search Tree */
    CreateBST(&bstROOT);

    /* Creation: The Dictionary */
    CreateDictionary(&bstROOT, dicData);

    /* Display Dictionary Data */
    printf("**********Dictionary**********\n");
    InorderTraversal(bstROOT);
    fclose(dicData); // Close File.

    /* Spelling Check */
    printf("\n**********Not in Dictionary**********\n");
    notFoundCount = SpellingCheck(bstROOT,spellCheckingData);
    printf("Number of words not in Dictionary: %d\n",notFoundCount);
    fclose(spellCheckingData); // Close File.

    /* Final Act:  Set Pointers to NULL  */
    dicData = NULL;
    spellCheckingData = NULL;

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
        if (strcmp(Item, LocPtr->Data)<0) // Changed [string1 < string2].
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item, LocPtr->Data)>0) // Changed [string1 > string2].
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE; // [string1 = string2]
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item); // Changed.
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr ->Data, Item); // Changed.
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item , Parent->Data)<0) // Changed [string1 < string2].
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
        if (strcmp(KeyValue , (*LocPtr)->Data)<0)   // Changed [string1 < string2]
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue , (*LocPtr)->Data)>0) // Changed [string1 > string2]
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}
/*########################################################################################################*/


/*########################################### MY NEW FUNCTIONS ###########################################*/
void CreateDictionary(BinTreePointer *Root, FILE *fp){

    BinTreeElementType stringItem;

    while(!feof(fp)){
	    fscanf(fp,"%s",stringItem);
        BSTInsert(Root, stringItem);
    }
 }

void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s\n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}

int SpellingCheck(BinTreePointer Root, FILE *fp){

    BinTreeElementType stringItem;
    BinTreePointer LocPtr;
    boolean Found;
    int getCount = 0;

    while(!feof(fp)){
	    fscanf(fp,"%s",stringItem);
        BSTSearch(Root, stringItem, &Found, &LocPtr);
        if (!(Found)){
            printf("%s\n",stringItem);
            getCount++;
        }
    }

    return getCount;
}
/*########################################################################################################*/

