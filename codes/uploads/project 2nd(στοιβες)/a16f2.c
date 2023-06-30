/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Author: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Email: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a16f2
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 100   // Stack total limit (total item inputs 100)

// StackElementType as Structure
typedef struct  {
    int price;
    char size; // S/M/L
} StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

/* Functions */
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

int main() {

    /* Variables */
    StackElementType AnItem;
    StackType AStack, tempStack;
    int numberOfItems, i;
    char searchSize;
    boolean found=FALSE;

    /* Creation: Item Stack and Temporary Stack */
    CreateStack(&AStack);
    CreateStack(&tempStack);

    /* Input: The total number of items */
    printf("Give number of items ");
    scanf("%d", &numberOfItems);

    /* Input Item Attributes: The size and the price */
    printf("Give the items to store\n");
    for(i=0; i<numberOfItems; i++){
        printf("Give price ");
        scanf("%d", &AnItem.price);
        getchar();
        printf("Give size ");
        scanf("%c", &AnItem.size);
        getchar();
        Push(&AStack, AnItem);
    }

    /* Output Items with Attributes */
    printf("Items in the box\n");
    TraverseStack(AStack);

    /* Search an Item by Size */
    printf("\nWhat size do you want? ");
    scanf("%c", &searchSize);
    getchar();
    while((!EmptyStack(AStack)) && (!found)) {
        Pop(&AStack, &AnItem);
        if(AnItem.size == searchSize)
            found = TRUE;
        else
            Push(&tempStack, AnItem);
    }
    if(found)
        printf("Found the size %c", searchSize);
    else
        printf("Not Found the size %c", searchSize);

    /* Implementation Q5 */
    printf("\nItems in the box\n");
    TraverseStack(AStack);
    printf("\nItems out of the box\n");
    TraverseStack(tempStack);

    /* Implementation Q6 */
    while(!EmptyStack(tempStack)) {
        Pop(&tempStack, &AnItem);
        Push(&AStack, AnItem);
    }

    /* Implementation Q7 */
    printf("\nItems in the box\n");
    TraverseStack(AStack);
    printf("\nItems out of the box\n");
    TraverseStack(tempStack);

    printf("\n");
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
void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("\n%c, %d", Stack.Element[i].size, Stack.Element[i].price);
    }
    printf("\n");
}
