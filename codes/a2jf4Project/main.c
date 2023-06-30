
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

void insert_list_m_elements(ListPointer *List, int n);

int main(){

    int n=0;
    ListPointer List;

    CreateList(&List);

    int m=0, i;
    ListElementType item;
    ListPointer predptr = NULL;

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &m);

    for(i=0;i<m;i++){
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: ");
        scanf("%d", &item);
        LinkedInsert(&List, item, predptr);
    }

    printf("*********Arxiki lista************\n");
    LinkedTraverse(List);

    printf("\nDWSE TI THESI, META APO TIN OPOIA THA EISAXTHOUN TA STOIXEIA: ");
    scanf("%d", &n);

    insert_list_m_elements(&List, n);

    printf("*********Teliki lista************\n");
    LinkedTraverse(List);

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

void insert_list_m_elements(ListPointer *List, int n){

    int m=0;
    int count=0;
    int i;
    ListElementType item;

    ListPointer curr = *List;
    ListPointer currTemp;

    if (EmptyList(*List)){
        printf("EMPTY LIST\n");
    }
    else{
        while(curr != NULL){
        count++;
        curr = curr ->Next;

        if(count == n-1){
           currTemp = curr;
        }
    }

    if(count < n || n<1){
        printf("ERROR\n");
    }
    else{
        printf("DWSE TO PLITHOS TWN STOIXEIWN POU THA EISAXTHOUN: ");
        scanf("%d",&m);
        for(i=0;i<m;i++){
            printf("DWSE TON ARI8MO GIA EISAGWGH STH LISTA: ");
            scanf("%d", &item);
            LinkedInsert(List, item, currTemp);

            currTemp = currTemp ->Next;
        }
    }

    }



}
