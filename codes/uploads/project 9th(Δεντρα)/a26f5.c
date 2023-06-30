/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3

   Author: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios

   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Email: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a26f5
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int LINE_ID;
    int CODE_AM;
} BinTreeElementType;

typedef struct {
    int CODE_AM;
    char NAME[20];
    char LNAME[20];
    char SEX;
    float GRADE;
    int YEAR;
} Attributes;

typedef struct BinTreeNode *BinTreePointer;

typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


/*######################################### MODIFIED ADT FUNCTIONS #######################################*/
void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTInorder(BinTreePointer Root);
/*########################################################################################################*/

/*########################################### MY NEW FUNCTIONS ###########################################*/
int BuildBST(BinTreePointer *Root);
void writeNewStudents(BinTreePointer *Root, int *size);
void PrintStudent(int regNum);
void printStudentsWithGrade(float theGrade);
/*########################################################################################################*/


int main(){

    /* Variables Declarations and Initialization */
    BinTreePointer bstROOT, LocPtr;
    boolean regFound = FALSE;
    BinTreeElementType tmpCode;
    int getSize = 0;
    int checkGrades = 0;

    /* Creation: The Binary Search Tree */
    CreateBST(&bstROOT);

    /* Q1 */
    printf("Q1. Build BST from a file\n");
    getSize = BuildBST(&bstROOT);

    /* Q2 */
    printf("Q2. Print size and BST\n");
    printf("Size=%d\n",getSize);
    printf("Nodes of BST\n");
    RecBSTInorder(bstROOT);


    /* Q3. Write new students, update file and BST */
    printf("\nQ3. Write new students, update file and BST \n");
    writeNewStudents(&bstROOT, &getSize);

    /* Q4 */
    printf("Q4. Print size and BST\n");
    printf("Size=%d\n",getSize);
    printf("Nodes of BST\n");
    RecBSTInorder(bstROOT);

    /* Q5 */
    printf("\nQ5. Search for a student\n");
    printf("Give student's code? ");
    scanf("%d", &tmpCode.CODE_AM);

    RecBSTSearch(bstROOT, tmpCode, &regFound, &LocPtr);

    if (regFound==TRUE){
        PrintStudent(tmpCode.CODE_AM);
    }   else printf("The Registration with AM(%d) does not exists \n",tmpCode.CODE_AM);

    /* Q6 */
    printf("Q6. Print size and BST\n");
    printf("Size=%d\n",getSize);
    printf("Nodes of BST\n");
    RecBSTInorder(bstROOT);

    /* Q7 */
    printf("\nQ7. Print students with grades >= given grade\n");
    printf("Give the grade: ");
    scanf("%d", &checkGrades);
    printStudentsWithGrade(checkGrades);

    return 0;
}// END main()


/*######################################### MODIFIED ADT FUNCTIONS #######################################*/
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
        if (Item.CODE_AM < (*Root) ->Data.CODE_AM) // Changed.
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.CODE_AM > (*Root) ->Data.CODE_AM) // Changed.
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}


void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.CODE_AM < Root->Data.CODE_AM) // Changed.
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.CODE_AM > Root->Data.CODE_AM) // Changed.
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
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
        printf("(%d, %d), ",Root->Data.CODE_AM, Root->Data.LINE_ID); // Changed.
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}
/*########################################################################################################*/


/*########################################### MY NEW FUNCTIONS ###########################################*/
int BuildBST(BinTreePointer *Root){

    BinTreeElementType indexReg;
    Attributes theStudent;
    int lineCount = 0;
    int flag=0;

    FILE *studentData = NULL; // The creation of the File Pointer with NULL initialization.
    studentData = fopen("foitites.dat", "r"); //Students Database Read Only mode

    if(studentData == NULL){
        printf("...Student database does not exist...\n");
        return 0;
    }

    while(!feof(studentData)){

        flag = fscanf(studentData, "%d, %20[^, ], %20[^, ], %[^, ], %d, %f", &theStudent.CODE_AM,
                                                                          theStudent.NAME,
                                                                          theStudent.LNAME,
                                                                          &theStudent.SEX,
                                                                          &theStudent.YEAR,
                                                                          &theStudent.GRADE);
        if(flag==0){
            printf("DATABASE ERROR CHECK - LINE %d\n", lineCount);
            return -1;
        }

        if(flag!=-1){
            indexReg.LINE_ID = lineCount;
            indexReg.CODE_AM = theStudent.CODE_AM;
            RecBSTInsert(Root, indexReg);
            lineCount++;
            //printf("%d \n", flag);
        }
    }

    fclose(studentData);
    studentData = NULL;

    return lineCount;
}

void writeNewStudents(BinTreePointer *Root, int *size){

    Attributes theStudent;
    BinTreeElementType tmpCode;
    BinTreePointer LocPtr;
    boolean Found = FALSE;
    char ch = '-';

    FILE *studentData = NULL; // The creation of the File Pointer with NULL initialization.
    studentData = fopen("foitites.dat", "a"); //Students Database Write Only mode

    if(studentData == NULL){
        printf("...Student database does not exist...\n");
    }
    else {
        /* Insertion:Students Attributes */
    do {
        printf("Give student's AM? ");
        scanf("%d", &tmpCode.CODE_AM);

        RecBSTSearch(*Root, tmpCode, &Found, &LocPtr);

        if (Found==FALSE){

            theStudent.CODE_AM = tmpCode.CODE_AM;

            printf("Give student surname? ");
            scanf("%s", theStudent.LNAME);
            getchar();

            printf("Give student name? ");
            scanf("%s", theStudent.NAME);
            getchar();

            printf("Give student sex F/M? ");
            scanf("%c", &theStudent.SEX);
            getchar();

            printf("Give student's registration year? ");
            scanf("%d", &theStudent.YEAR);

            printf("Give student's grade? ");
            scanf("%f", &theStudent.GRADE);

            tmpCode.LINE_ID = (*size);
            RecBSTInsert(Root, tmpCode);

            (*size)++;

            printf("Size=%d\n", (*size));

            fprintf(studentData, "%d,%s,%s,%c,%d,%.1f\n", theStudent.CODE_AM,
                                                          theStudent.NAME,
                                                          theStudent.LNAME,
                                                          theStudent.SEX,
                                                          theStudent.YEAR,
                                                          theStudent.GRADE);

        } else printf("The Registration with AM(%d) already exists \n",tmpCode.CODE_AM);

        printf("\nContinue Y/N: ");
        do {
            scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');

    fclose(studentData);
    studentData = NULL;
    }


}

void PrintStudent(int regNum){

    Attributes theStudent;
    int lineCount = 0;
    int flag=0;

    FILE *studentData = NULL; // The creation of the File Pointer with NULL initialization.
    studentData = fopen("foitites.dat", "r"); //Students Database Read Only mode

    while(!feof(studentData)){

        flag = fscanf(studentData, "%d, %20[^, ], %20[^, ], %[^, ], %d, %f", &theStudent.CODE_AM,
                                                                          theStudent.NAME,
                                                                          theStudent.LNAME,
                                                                          &theStudent.SEX,
                                                                          &theStudent.YEAR,
                                                                          &theStudent.GRADE);
        if(flag==0){
            printf("DATABASE ERROR CHECK - LINE %d\n", lineCount);
            break;
        }

        if(flag!=-1){
            if(theStudent.CODE_AM == regNum){
                    printf("%d, %s, %s, %c, %d, %.1f\n", theStudent.CODE_AM,
                                                         theStudent.NAME,
                                                         theStudent.LNAME,
                                                         theStudent.SEX,
                                                         theStudent.YEAR,
                                                         theStudent.GRADE);
            break;
            }
            lineCount++;
        }
    }

    fclose(studentData);
    studentData = NULL;

}


void printStudentsWithGrade(float theGrade){

    Attributes theStudent;
    int lineCount = 0;
    int flag=0;

    FILE *studentData = NULL; // The creation of the File Pointer with NULL initialization.
    studentData = fopen("foitites.dat", "r"); //Students Database Read Only mode

    while(!feof(studentData)){

        flag = fscanf(studentData, "%d, %20[^, ], %20[^, ], %[^, ], %d, %f", &theStudent.CODE_AM,
                                                                          theStudent.NAME,
                                                                          theStudent.LNAME,
                                                                          &theStudent.SEX,
                                                                          &theStudent.YEAR,
                                                                          &theStudent.GRADE);
        if(flag==0){
            printf("DATABASE ERROR CHECK - LINE %d\n", lineCount);
            break;
        }

        if(flag!=-1){
            if(theStudent.GRADE >= theGrade){
                    printf("%d, %s, %s, %c, %d, %.1f\n", theStudent.CODE_AM,
                                                         theStudent.NAME,
                                                         theStudent.LNAME,
                                                         theStudent.SEX,
                                                         theStudent.YEAR,
                                                         theStudent.GRADE);
            }
            lineCount++;
        }
    }

    fclose(studentData);
    studentData = NULL;

}
/*########################################################################################################*/
