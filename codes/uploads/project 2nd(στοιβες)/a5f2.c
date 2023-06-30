/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Author: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Email: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a5f2
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define StackLimit 15 // �� ���� ��� �������� ��� �������.


typedef int StackElementType; // � ����� ��� ��������� ��� ������� �� int.

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

/* Functions */
void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
boolean FullStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
void TraverseStack(StackType Stack);

int main() {

    /* Variables */
    StackElementType x, i, n, temp;
    StackType Stack, tempS;

    /* The Stack Creation */
    CreateStack(&Stack);

    /* Generate Data Values for the Stack */
    for(i=0;i<StackLimit;i++)
    {
      Push(&Stack, i*10);
    }

    /* Display the Stack */
    TraverseStack(Stack);

     /* The nth element User Input */
    printf("Give nth element (n<=%d) ", (Stack.Top-1)/2);
    scanf("%d", &n);

    //������� a)

    Pop(&Stack, &x);
    Pop(&Stack, &x);

    printf("\nQuestion a: x=%d\n", x);

    TraverseStack(Stack);


    //������� b)

    Pop(&Stack, &temp);
    Pop(&Stack, &x);

    Push(&Stack, x);
    Push(&Stack, temp);

    printf("\nQuestion b: x=%d\n", x);
    TraverseStack(Stack);


    //������� c)

    for(i=0;i<n;i++)
        Pop(&Stack, &x);

    printf("\nQuestion c: x=%d\n", x);
    TraverseStack(Stack);


    //������� d)

    CreateStack(&tempS);

    for(i=0;i<n;i++)
    {
        Pop(&Stack, &x);
        Push(&tempS, x);
    }

    printf("\nQuestion d: x=%d\n", x);
    while(!EmptyStack(tempS))
    {
        Pop(&tempS, &x);
        Push(&Stack, x);
    }

    TraverseStack(Stack);

   //������� e)

   while(!EmptyStack(Stack))
   {
        Pop(&Stack, &x);
        Push(&tempS, x);
   }
    printf("\nQuestion e: x=%d\n", x);


   while(!EmptyStack(tempS))
   {
        Pop(&tempS, &x);
        Push(&Stack, x);
   }

    TraverseStack(Stack);


   //������� f)


   while(Stack.Top >= 2)//����� �� 1� �������� ����� ��� ��� ���� 0
   {
        Pop(&Stack, &x);
        Push(&tempS, x);
   }
    printf("\nQuestion f: x=%d\n", x);

   while(!EmptyStack(tempS))
   {
        Pop(&tempS, &x);
        Push(&Stack, x);
   }
    TraverseStack(Stack);

    //������� g)

    while(!EmptyStack(Stack))
        Pop(&Stack, &x);

    printf("\nQuestion g: x=%d\n", x);
    TraverseStack(Stack);


    return 0;
    system("PAUSE");
}


void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
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

/* ��������� �� STOIXEIA ��� ������� ��� �� ���� 0-TOP */
 void TraverseStack(StackType Stack){
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
