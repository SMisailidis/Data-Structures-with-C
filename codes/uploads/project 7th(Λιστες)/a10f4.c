/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a10f4
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>


typedef int StackElementType;

typedef struct StackNode *StackPointer;

typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
/*######################################################################################*/

/*################################## MY NEW FUNCTIONS ##################################*/
void TraverseStack(StackPointer Stack);
/*######################################################################################*/

int main(){

    /* Variables Declarations and Initialization */
    StackPointer stack, tempS;
    StackElementType item, count;
    int i;

    /* The creation of myStackA and myStackB */
    CreateStack(&stack);
    CreateStack(&tempS);

    /* The total number of user inputs */
    printf("PLITHOS STOIXEIWN: ");
    scanf("%d", &count);
    for(i=0;i<count;i++){
        printf("DWSE TO %do STOIXEIO: ", i+1);
        scanf("%d", &item);
        Push(&stack, item);
    }

    /* Display myStackA */
    printf("*********1i stoiva***********\n");
    TraverseStack(stack);

    /* Exchange data values between myStackA and myStackB */
    for(i=0;i<count;i++){
        Pop(&stack, &item);
        Push(&tempS, item);
    }

    /* Display myStackB */
    printf("*********2i stoiva***********\n");
    TraverseStack(tempS);

    return 0;
}

/*############################### DO NOT CHANGE THE FUNCTIONS ###############################*/
void CreateStack(StackPointer *Stack)
/* ����������: ���������� ��� ���� ����������� ������.
   ����������: ��� ���� ����������� ������, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ���
                ������ Stack ��� ��� �������� Item.
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item.
   ����������: ��� ������������� ����������� ������
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack.
   ����������: ������� ��� ��� ������ ��� ������������ �������,
                �� � ������ ��� ����� ����, �� �������� Item.
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item.
   ������:     ������ ����� �������, �� � ����������� ������ ����� ����
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
/*###########################################################################################*/

/*#################################### MY NEW FUNCTIONS #####################################*/
void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
/*###########################################################################################*/
