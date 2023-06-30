#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char BinTreeElementType[20];        /*� ����� ��� ��������� ��� ���
                                        ���������� ����� int */
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

void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE *fp);

int main(){

    BinTreePointer ARoot;

    FILE* fp1;
    FILE* fp2;

    fp1 = fopen("i112f5.txt", "r");

    fp2 = fopen("i111f5.txt", "r");

    CreateBST(&ARoot);
    CreateDictionary(&ARoot, fp1);
    printf("**********Dictionary*********\n");
    InorderTraversal(ARoot);

    printf("\n**********Not in Dictionary**********\n");
    printf("Number of words not in Dictionary: %d\n", SpellingCheck(ARoot, fp2));


    fclose(fp1);
    fclose(fp2);
    return 0;
}

void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
       if (strcmp(Item , LocPtr->Data)==-1)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item,LocPtr->Data)==1)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr->Data,Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item,Parent->Data)==-1)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue , (*LocPtr)->Data)==-1)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue , (*LocPtr)->Data)==1)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void InorderTraversal(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s\n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}

void CreateDictionary(BinTreePointer *Root, FILE *fp)
{
    BinTreeElementType Item;

        while (!feof(fp))
        {
            fscanf(fp,"%s",Item);
            BSTInsert(Root,Item);
        }
    fclose(fp);
}
int SpellingCheck(BinTreePointer Root, FILE *fp){

    boolean Found;
    BinTreePointer LocPtr;
    BinTreeElementType Item;
    int count=0;

    while(!feof(fp)){
        fscanf(fp,"%s",Item);
        BSTSearch(Root, Item, &Found, &LocPtr);
        if(!Found){
            printf("%s\n", Item);
            count++;
        }
    }
    fclose(fp);
    return count;
}
