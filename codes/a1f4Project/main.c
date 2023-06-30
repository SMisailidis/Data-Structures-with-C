#include <stdio.h>
#include <stdlib.h>

#define NumberOfNodes 10    /*���� �������� ��� ������������ ������,
                            ���������� ������ ��� �� 50*/
#define NilValue -1          // ������ �������� ���� ������� �� ����� ��� ����.������

typedef int ListElementType; /*����� ��������� ��� �� �������� ��� ������������ ������,
                                ���������� ���������� � ����� int */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item,ListPointer *PredPtr);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main(){

    ListElementType num;
    int i;
    char ch;
    boolean found;
    NodeType storagePool[NumberOfNodes];
    ListPointer lList, predPtr, freePtr;


    //---a---
    InitializeStoragePool(storagePool, &freePtr);


    //---b---
    CreateList(&lList);

    //---c---
    printf("---------------Question C--------------------\n");
    printf("--------------Storage pool------------------\n");
    printAll(lList, freePtr, storagePool);

    //---d---
    printf("---------------Question D--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(lList, storagePool);

    //---e---
    printf("---------------Question E--------------------\n");
    printf("Give a number: ");
    scanf("%d", &num);
    found = Search(freePtr, lList, storagePool, num, &predPtr);
    Insert(&lList, storagePool, &freePtr, predPtr, num);
    printf("\nContinue Y/N: ");
    scanf(" %c", &ch);

    while(!FullList(freePtr)){
        if(ch == 'y' || ch == 'Y'){
            printf("Give a number: ");
            scanf("%d", &num);
            found = Search(freePtr, lList, storagePool, num, &predPtr);
            Insert(&lList, storagePool, &freePtr, predPtr, num);
            printf("\nContinue Y/N: ");
            scanf(" %c", &ch);
        }
        else break;
    }

    //---f---
    printf("---------------Question F--------------------\n");
    printf("--------------Storage pool------------------\n");
    printAll(lList, freePtr, storagePool);

    //---g---
    printf("---------------Question G--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(lList, storagePool);

    //---h---
    printf("---------------Question H--------------------\n");

    if(EmptyList(lList))
        printf("Empty List\n");
    else
        printf("Not an Empty List\n");

    //---i---
    printf("---------------Question I--------------------\n");

    if(FullList(freePtr))
        printf("Full List\n");
    else
        printf("Not a Full List\n");

    printf("---------------Question J--------------------\n");
    printf("-----------------Search for a number-----------------\n");

    for(i=0; i<2; i++){
        printf("Give a number ");
        scanf("%d", &num);
        found = Search(freePtr, lList, storagePool, num, &predPtr);

        if(found)
            printf("The number is in the list and its predecessor is in position %d\n",predPtr);
        else{
            printf("The number is not in the list\n");
        }
    }

    return 0;
}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* �������:   ��� ������ Node ��� ��� ������ FreePtr ��� ������� ����
                ����� ��������� �����.
  ����������: ����������� ��� ������ Node �� ����������� ����� ���������� ������
                ���� ���������� �������� ��� ������,
                ��� ����������� ��� ������ FreePtr .
  ����������: ��� ������������� ������ Node ��� ���
                ������ FreePtr ��� ������ ���������� ������
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;    /* ��� ����� �������� � ������� ������� ����� ��� ����� ��� ���������, ������� ���� �������� */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
   ����������: ���� (��������) ������ ��� ������� �� ���� �����
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* �������:    ���� ������ List ��� ������� �� ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ����.
   ����������: True �� � ����������� ����� ����� ���� ��� false �����������
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* �������:    ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ������.
   ����������: True �� � ���������������� ����� ������, false �����������
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* �������:   ��� ������ Node ��� ��� ������ FreePtr.
  ����������: ������ ���� "��������" ����� ��� ��� ������� � ������� P.
  ����������: ��� ������ P ��� ��� �������������  ������ FreePtr
                ��� ����������� ��� ����� ��������� �����
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* �������:    ��� ������ Node, ��� ���������� �� �������� ��� ���������� ������,
                ���� ������ TempPtr ��� ��� ������ FreePtr.
   ����������: ���������� ��� �������� ��� ����� ���� ����� ������� � TempPtr.
   ����������: ��� ������������� ������ Node ��� ��� ������ FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data = -1; /* ��� �������� ������, ��������� ��� �� ��������� ����
                        �������� �� ������������ ������ */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* �������:    ��� ����������� �����, ��� ������ Node, ��� ������ PredPtr ���
                ��� �������� Item.
  ����������: ������� ��� ����������� �����, �� ��� ����� ������, �� ��������
                Item ���� ��� ��� ����� ���� ����� ������� � ������� PredPtr.
  ����������: ��� ������������� ����������� �����, ��� ������������� ������ Node
                ��� ��� ������ FreePtr.
  ������:     ������ ������� ������, �� � ����������� ����� ����� ������
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* �������:   ��� ����������� ����� ��� ��� ������ PredPtr ��� �������
                ���� ����������� ����� ��� ����� ��� �� ���������.
  ����������: ��������� ��� �� ����������� �����, �� ��� ����� ����,
                ��� ����������� ����� ��� ����� ���� ����� ������� � PredPtr.
  ����������: ��� ������������� ����� ��� �� ������ FreePtr.
  ������:     ������ ����� ������, �� � ����������� ����� ����� ����
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* �������:    ��� ����������� �����.
   ����������: ����� �������� ��� ������������ ������, �� ��� ����� ����.
   ������:     ��������� ��� ��� �����������
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr){

    ListPointer Current;
    boolean stop, found;

	found = FALSE;
	stop = FALSE;

    *PredPtr = NilValue;

    if(!EmptyList(List))
	{

      Current = List;
      while(Current!=NilValue&&!stop)
	  {
          if(Node[Current].Data>=Item)
		  {
              stop = TRUE;
              if(Node[Current].Data==Item){
                    found = TRUE;
              }
          }
		  else
		  {
              *PredPtr = Current;
              Current = Node[Current].Next;
          }
       }
    }
	else found = FALSE;
    return found;
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}
