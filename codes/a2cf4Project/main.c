#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;           /* � ����� ��� ��������� ��� ������������ ������
                                        ���������� ����� int */
typedef struct ListNode *ListPointer;   //� ����� ��� ������� ��� ���� �������
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

void concat_list(ListPointer List, ListPointer BList, ListPointer *FinalList);

int main(){

    int plhthosList=0;
    int plhthosBlist=0;
    int i;
    ListElementType item;
    ListPointer List, Blist, FinalList, predPtr=NULL;

    CreateList(&List);
    CreateList(&Blist);
    CreateList(&FinalList);

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
    scanf("%d", &plhthosList);

    for(i=0;i<plhthosList;i++){
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1: ");
        scanf("%d", &item);
        LinkedInsert(&List, item, predPtr);
    }

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
    scanf("%d", &plhthosBlist);

    for(i=0;i<plhthosBlist;i++){
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2: ");
        scanf("%d", &item);
        LinkedInsert(&Blist, item, predPtr);
    }

    printf("LISTA 1:\n");
    LinkedTraverse(List);

    printf("\nLISTA 2:\n");
    LinkedTraverse(Blist);

    concat_list(List, Blist, &FinalList);

    printf("\nSYNENWMENH LISTA:\n");
    LinkedTraverse(FinalList);


    return 0;
}

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
  ����������:  ��� �������� ������ List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� �� � ����������� ����� ����� ����.
  ����������: True �� � ����� ����� ���� ��� false �����������
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����,
                ��� �������� ��������� Item ��� ���� ������ PredPtr.
   ����������: ������� ���� �����, ��� �������� �� Item, ���� ����������� �����
                ���� ��� ��� ����� ��� �������������� ��� ��� PredPtr
                � ���� ����  ��� ������������ ������,
                �� � PredPtr ����� ���������(NULL).
  ����������:  ��� ������������� ����������� ����� �� ��� ����� ����� ���
                �� �������������� ��� ��� List.
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
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
   ����������: ��������� �� ����������� ����� ���
                ������������� ���� �������� ������� ��� ����.
   ����������: ��������� ��� �� ����� ��� ������������.
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

void concat_list(ListPointer List, ListPointer BList, ListPointer *FinalList){

    ListPointer currentList, currentBlist, predPtr;
    currentList = List;
    currentBlist = BList;
    predPtr = *FinalList;

    while(currentList != NULL){
        LinkedInsert(FinalList, currentList->Data, predPtr);
        currentList = currentList->Next;
    }

    while(currentBlist != NULL){
        LinkedInsert(FinalList, currentBlist->Data, predPtr);
        currentBlist = currentBlist->Next;
    }
}
