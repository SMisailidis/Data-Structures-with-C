#include <stdio.h>
#include <stdlib.h>


#define NumberOfNodes 10
#define NilValue -1
#define StackLimit 5



typedef struct{
    int AM;
    float grade;
} ListElementType;

typedef int ListPointer;
typedef int StackElementType;

typedef struct{
    int Top;
    StackElementType Element[StackLimit];
} StackType;

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
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

void TraverseLinked(ListPointer List, NodeType Node[]);
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);


int main(){


    float min;
    int i=0;
    NodeType node[NumberOfNodes];
    ListPointer list, freePtr, predPtr;
    ListElementType student;
    StackType stack;
    StackElementType studentStack;

    //---a---
    InitializeStoragePool(node, &freePtr);

    //---b---
    CreateList(&list);

    //---c---
    printf("Question C\n");
    printf("Storage pool\n");
    printAll(list, freePtr, node);

    //---d---
    printf("Question D\n");
    printf("Linked list\n");
    TraverseLinked(list, node);

    //---e---
    printf("Question E\n");

    predPtr = NilValue;
    for(i=0;i<5;i++){
        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
        scanf("%d", &student.AM);
        printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
        scanf("%f", &student.grade);

        Insert(&list, node, &freePtr, predPtr, student);
;    }

    //---f---
    printf("Question F\n");
    printf("Storage pool\n");
    printAll(list, freePtr, node);

    //---g---
    printf("Question G\n");
    printf("Linked list\n");
    TraverseLinked(list, node);

    //---h---
    printf("Question H\n");

    if(EmptyList(list))
        printf("Empty List\n");
    else
        printf("Not an Empty List\n");

   //---i---
    printf("Question I\n");

    if(FullList(freePtr))
        printf("Full List\n");
    else
        printf("Not a Full List\n");

    //---j---
    printf("Question J\n");
    min = FindMins(list, node, &stack);
    printf("Min value=%.1f\n", min);
    printf("AM with min grade are: ");
    while(!EmptyStack(stack)){
        Pop(&stack, &studentStack);
        printf("%d ", studentStack);

    }
    printf("\n");

    //---k---
    printf("Question K\n");
    TraverseStack(stack);

    //---l---
    printf("Question L\n");
    printf("Storage pool\n");
    printAll(list, freePtr, node);

    //---m---
    printf("Question M\n");
    printf("Linked list\n");
    TraverseLinked(list, node);

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
        Node[i].Data.AM=-1;
        Node[i].Data.grade=-1.0;   /* ��� ����� �������� � ������� ������� ����� ��� ����� ��� ���������, ������� ���� �������� */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.AM=-1;
    Node[i].Data.grade=-1.0;
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
          printf("(%d:<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.AM, Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack){

    ListPointer CurrPtr;
    StackElementType studentAM, item;
    float min;

    CreateStack(Stack);

    if(!EmptyList(List)){
        CurrPtr = List;
        min = Node[CurrPtr].Data.grade;

        while(CurrPtr != NilValue){
            if(Node[CurrPtr].Data.grade <= min){
                if(Node[CurrPtr].Data.grade < min){
                    while(!EmptyStack(*Stack)){
                        Pop(Stack, &item);
                    }
                    min = Node[CurrPtr].Data.grade;
                }
                studentAM = Node[CurrPtr].Data.AM;
                Push(Stack, studentAM);
            }
            CurrPtr = Node[CurrPtr].Next;
        }
    }

    return min;
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ", i, Node[i].Data.AM, Node[i].Data.grade, Node[i].Next);
    printf("\n");
}

boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
