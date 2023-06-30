#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fullname[20];
    char phone[10];
    int specialty;
} EmployeeRecord;

typedef EmployeeRecord BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

void BuildBST(BinTreePointer *Root);
void RecBSTSearchBySubject(BinTreePointer Root, int code);

int main()
{

    BinTreePointer ARoot;
    int code;
    boolean found;
    BinTreePointer LocPtr;
    BinTreeElementType EmpRec;

    CreateBST(&ARoot);

    //1
    BuildBST(&ARoot);

    //2
    RecBSTInorder(ARoot);

    //3
    printf("\n");
    for (int i=0;i<2;i++) {
        printf("Give teacher full name: ");
        fflush(stdin);
        gets(EmpRec.fullname);

        printf("Give teacher phone number: ");
        fflush(stdin);
        gets(EmpRec.phone);

        printf("Give teacher code: ");
        scanf("%d", &EmpRec.specialty);

        RecBSTInsert(&ARoot, EmpRec);
        printf("\n");
    }

    //4
    printf("Give teacher full name to search: ");
    fflush(stdin);
    gets(EmpRec.fullname);
    RecBSTSearch(ARoot, EmpRec, &found, &LocPtr);

    if(found == TRUE){
        printf("%s, %s, %d\n", LocPtr->Data.fullname, LocPtr->Data.phone, LocPtr->Data.specialty);
    }

    //5
    printf("\nGive code to search: ");
    scanf("%d", &code);
    RecBSTSearchBySubject(ARoot, code);

    //6
    printf("\nGive teacher full name to delete: ");
    fflush(stdin);
    gets(EmpRec.fullname);
    RecBSTDelete(&ARoot, EmpRec);

    //7
    printf("\nPrint teachers data\n");
    RecBSTInorder(ARoot);

    return 0;
}

void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if(strcmp(Item.fullname, (*Root) ->Data.fullname) < 0)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if(strcmp(Item.fullname, (*Root) ->Data.fullname) > 0)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else {
        if (strcmp(KeyValue.fullname, Root->Data.fullname) < 0)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
        if (strcmp(KeyValue.fullname, Root->Data.fullname) > 0)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
    }
}


void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ����� ������ �� KeyValue �� �� ������ *)
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
         //* ��������� ���������� ��� ����� ��� �������� ��� ���� KeyValue ��� �������� ���
          if (strcmp(KeyValue.fullname, (*Root)->Data.fullname) < 0)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* �������� ��������� *
          else
            if (strcmp(KeyValue.fullname, (*Root)->Data.fullname) > 0)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ����  ��������� *
            else                                       //* TO KeyValue ������� �������� ��� ������ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ��� ���� �������� ����� *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ���� �������� �����, ���� ��� ���� *)
                        free(TempPtr);
                   }
                   else                               //* ���� 2 ������ *)
                   {
                        //* ������ ��� INORDER �������� ��� *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ���������� ��� �������� ��� ����� ��� ����������
                        ��� ���������� ��� �������� ��� �������� ������ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("%s,%s,%d\n",Root->Data.fullname, Root->Data.phone, Root->Data.specialty);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ��������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        printf("%s,%s,%d\n",Root->Data.fullname, Root->Data.phone, Root->Data.specialty);
       // printf("L");
        RecBSTPreorder(Root->LChild);
      //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
      //  printf("L");
        RecBSTPostorder(Root->LChild);
     //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("%s,%s,%d\n",Root->Data.fullname, Root->Data.phone, Root->Data.specialty);
    }
   // printf("U");
}

void BuildBST(BinTreePointer *Root) {
    FILE *fp;
    int nscan;
    int line = 0;
    BinTreeElementType EmpRec;

    fp = fopen("I14F5.TXT", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    else{
        while (TRUE) {
            nscan = fscanf(fp, "%[^,],%10s,%d\n", EmpRec.fullname, EmpRec.phone, &EmpRec.specialty);

            if ( nscan == EOF )
                break;
            line++;


            if (nscan != 3)
            {
                printf("Improper file format %d\n", line);
                exit(1);
            }

            RecBSTInsert(Root, EmpRec);
        }
    }
}

void RecBSTSearchBySubject(BinTreePointer Root, int code) {
    if (BSTEmpty(Root)) {
        return;
    }
    RecBSTSearchBySubject(Root->LChild, code);
    if (Root->Data.specialty == code) {
        printf("%s, %s, %d\n", Root->Data.fullname, Root->Data.phone, Root->Data.specialty);
    }
    RecBSTSearchBySubject(Root->RChild, code);
}

