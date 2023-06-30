/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a1f4
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10  // Linked List Size Limit.
#define NilValue -1 // Value -1 indicates the end of the List.

typedef int ListElementType; // The List element data type as int.
typedef int ListPointer; // The List pointer data type as int.

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
/*######################################################################################*/

/*################################## MY NEW FUNCTIONS ##################################*/
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
boolean Search(ListPointer List, NodeType Node[NumberOfNodes],
               ListElementType Item, ListPointer *PredPtr);
/*######################################################################################*/

int main(){

    /* Variables Declarations */
    ListPointer myList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;
    ListElementType itemList;
    boolean found;
    char ch = '-';
    int i;

    /* qA - Storage Pool Initializations */
    InitializeStoragePool(Node, &FreePtr);

    /* qB - The List Creation */
    CreateList(&myList);

    /* qC - Display Storage Pool */
    printf("---------------Question C--------------------\n");
    printAll(myList, FreePtr, Node);

    /* qD - Display The Linked List */
    printf("---------------Question D--------------------\n");
    TraverseLinked(myList, Node);

    /* qE - Data Input and Sorting */
    printf("---------------Question E--------------------\n");
	do{
        printf("Give a number: ");
        scanf("%d", &itemList);

        PredPtr = NilValue;
        found = Search(myList, Node, itemList, &PredPtr);
        Insert(&myList, Node, &FreePtr, PredPtr, itemList);

        printf("\nContinue Y/N: ");
        do{
            scanf("%c",&ch);
        } while (toupper(ch)!='N' && toupper(ch)!='Y');
    } while (toupper(ch)!='N');

    /* qF - Display Storage Pool */
    printf("---------------Question F--------------------\n");
    printAll(myList, FreePtr, Node);

    /* qG - Display The Linked List */
    printf("---------------Question G--------------------\n");
    TraverseLinked(myList, Node);

    /* qH - Empty or Not Empty Linked List */
    printf("---------------Question H--------------------\n");
    printf(EmptyList(myList) ? "Empty List\n" : "Not an Empty List\n");

    /* qI - Full or Not Full Linked List */
    printf("---------------Question I--------------------\n");
    printf(FullList(FreePtr) ? "Full List\n" : "Not a Full List\n");

    /* qJ - Searching Values in Linked List */
    printf("---------------Question J--------------------\n");
    printf("-----------------Search for a number-----------------\n");
    for(i=0;i<2;i++){
    printf("Give a number ");
    scanf("%d",&itemList);
    found = Search(myList, Node, itemList, &PredPtr);
    printf(found ? "The number is in the list and its predecessor is in position %d\n" : "The number is not in the list\n",PredPtr);
    }

    return 0;
} // END main()

/*############################### DO NOT CHANGE THE FUNCTIONS ###############################*/
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
/*###########################################################################################*/


/*#################################### MY NEW FUNCTIONS #####################################*/
void TraverseLinked(ListPointer List, NodeType Node[])
/* �������:    ��� ����������� �����.
   ����������: ����� �������� ��� ������������ ������, �� ��� ����� ����.
   ������:     ��������� ��� ��� �����������
*/
{
  ListPointer CurrPtr;
  printf("--------------Linked list--------------------\n");

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d ->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]){
    int i;
    printf("--------------Storage pool------------------\n");
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}

// pdf: 4_Lists_Stacks_Queues (typo): ListPointer FreePtr, is not important.
boolean Search(ListPointer List, NodeType Node[NumberOfNodes],
ListElementType Item, ListPointer *PredPtr){

    ListPointer CurrPtr;
    boolean stop_flag = FALSE;
    boolean found_flag = FALSE;

    CurrPtr = List;
    *PredPtr = NilValue;

    if(!EmptyList(List)){

      CurrPtr = List;
      *PredPtr = NilValue;

      while(CurrPtr != NilValue && !stop_flag){
          if(Node[CurrPtr].Data>=Item){
              stop_flag = TRUE;
              found_flag = (Node[CurrPtr].Data==Item);
          } else {
              *PredPtr = CurrPtr;
              CurrPtr = Node[CurrPtr].Next;
          }
       }
    } else found_flag = FALSE;

    return found_flag;
}
/*###########################################################################################*/
