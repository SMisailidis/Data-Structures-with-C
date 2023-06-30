/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a30f4
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>


#define NumberOfNodes 10  // Linked List Size Limit.
#define NilValue -1 // Value -1 indicates the end of the List.
#define StackLimit 5   // Stack Size Limit.


/* StackElementType as Structure */
typedef struct{
    int AM;
    float grade;
} ListElementType;

typedef int ListPointer; // The List pointer data type as int.
typedef int StackElementType;   // The Stack element data type as int.

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

/*################################# ADT MODIFIED FUNCTIONS ##################################*/
/* Linked List Functions */
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
/*###########################################################################################*/

/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
/* Stack Functions */
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
/*###########################################################################################*/

/*################################## MY NEW FUNCTIONS ##################################*/
void TraverseLinked(ListPointer List, NodeType Node[]);
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
/*######################################################################################*/

int main(){

    /* Variables Declarations */
    float min;
    int i=0;
    NodeType node[NumberOfNodes];
    ListPointer list, freePtr, predPtr;
    ListElementType student;
    StackType stack;
    StackElementType studentStack;



    /* qA - Storage Pool Initializations */
    InitializeStoragePool(node, &freePtr);

    /* qB - The List Creation */
    CreateList(&list);

    /* qC - Display Storage Pool */
    printf("---------------Question C--------------------\n");
    printf("--------------Storage pool------------------\n");
    printAll(list, freePtr, node);

    /* qD - Display The Linked List */
    printf("---------------Question D--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(list, node);

    /* qE - Data Input and Sorting */
    printf("---------------Question E--------------------\n");

    predPtr = NilValue;
    for(i=0;i<5;i++){
        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
        scanf("%d", &student.AM);
        printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
        scanf("%f", &student.grade);

        Insert(&list, node, &freePtr, predPtr, student);
;    }

    /* qF - Display Storage Pool */
    printf("---------------Question F--------------------\n");
    printf("--------------Storage pool------------------\n");
    printAll(list, freePtr, node);

    /* qG - Display The Linked List */
    printf("---------------Question G--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(list, node);

    /* qH - Empty or Not Empty Linked List */
    printf("---------------Question H--------------------\n");

    if(EmptyList(list))
        printf("Empty List\n");
    else
        printf("Not an Empty List\n");

    /* qI - Full or Not Full Linked List */
    printf("---------------Question I--------------------\n");

    if(FullList(freePtr))
        printf("Full List\n");
    else
        printf("Not a Full List\n");

    /* qJ -   */
    printf("---------------Question J--------------------\n");
    min = FindMins(list, node, &stack);
    printf("Min value=%.1f\n", min);
    printf("AM with min grade are: ");
    while(!EmptyStack(stack)){
        Pop(&stack, &studentStack);
        printf("%d ", studentStack);

    }
    printf("\n");

    /* qK - TraverseStack Results after qJ implementation  */
    printf("---------------Question K--------------------\n");
    TraverseStack(stack);

    /* qL - Display Storage Pool */
    printf("---------------Question L--------------------\n");
    printf("--------------Storage pool------------------\n");
    printAll(list, freePtr, node);

    /* qM - Display The Linked List */
    printf("---------------Question M--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(list, node);

    return 0;
} // END main()

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
