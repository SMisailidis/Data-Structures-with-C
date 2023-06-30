#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 60

typedef struct{
    int Amka;
    int Afm;
    int Age;
} BinTreeElementType;        /*ο τύπος των στοιχείων του ΔΔΑ
                                        ενδεικτικά τύπου int */


typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void InorderTraversal(BinTreePointer Root);



int main(){

    BinTreePointer ARootUnder60;
    BinTreePointer ARootAbove60;
    BinTreePointer LocPtr;

    BinTreeElementType person;
    boolean found;
    char ch;
    int i;

    CreateBST(&ARootUnder60);
    CreateBST(&ARootAbove60);

    do{
        printf("Give AMKA? ");
        scanf("%d", &person.Amka);

        printf("Give AFM? ");
        scanf("%d", &person.Afm);

        printf("Give age? ");
        scanf("%d", &person.Age);

        if(person.Age <= LIMIT){
            BSTInsert(&ARootUnder60, person);
        }
        else{
            BSTInsert(&ARootAbove60, person);
        }

        printf("\nContinue Y/N: ");
        do{
            scanf("%c", &ch);
        }while(toupper(ch) != 'N' && toupper(ch) != 'Y');

    }while(toupper(ch) != 'N');

    printf("\nPeople with age less-equal %d\n", LIMIT);
    InorderTraversal(ARootUnder60);
    printf("\n");
    printf("\nPeople with age greater than %d\n", LIMIT);
    InorderTraversal(ARootAbove60);
    printf("\n");
    for(i=0;i<3;i++){
        printf("Give AMKA: ");
        scanf("%d", &person.Amka);

        printf("Give age: ");
        scanf("%d", &person.Age);

        if(person.Age <= LIMIT){
            BSTSearch(ARootUnder60, person, &found, &LocPtr);
        }
        else{
            BSTSearch(ARootAbove60, person, &found, &LocPtr);
        }

        if(found){
            if(person.Age == LocPtr->Data.Age)
                printf("The person with AMKA %d,AFM %d and age %d is in the catalogue\n", person.Amka, LocPtr->Data.Afm, LocPtr->Data.Age);
            else
                printf("The person with AMKA %d has age %d different from the person you are looking for\n", person.Amka, LocPtr->Data.Age);
        }
        else{
            printf("The person with AMKA %d and age %d is Unknown", person.Amka, person.Age);
        }
    }


    return 0;
}

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
        if (Item.Amka < LocPtr->Data.Amka)
            LocPtr = LocPtr ->LChild;
        else if (Item.Amka > LocPtr ->Data.Amka)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item.Amka);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data.Amka = Item.Amka;
        LocPtr ->Data.Afm = Item.Afm;
        LocPtr ->Data.Age = Item.Age;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.Amka < Parent ->Data.Amka)
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
        if (KeyValue.Amka < (*LocPtr)->Data.Amka)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue.Amka > (*LocPtr)->Data.Amka)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
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
        printf("(%d, %d, %d) ",Root->Data.Amka, Root->Data.Afm, Root->Data.Age);
        InorderTraversal(Root->RChild);
    }

}
