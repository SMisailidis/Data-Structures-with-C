//https://prnt.sc/14f8yfm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define StackLimit 100


typedef struct {

  int price;
  char size[2];
}boxT;

typedef boxT StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;


typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
boolean FullStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
void TraverseStack(StackType Stack);

 main() {

 boolean Found;
 boxT box;
 StackType stack;
 StackType tempS;

 int i;
 int quantity;
 char choice[2];

 CreateStack(&stack);
 CreateStack(&tempS);

 // Ερωτημα 1ο
 printf("Give number of items ");
scanf("%d", &quantity);

 // Ερωτημα 2ο
 printf("Give the items to store\n");
 for(i=0;i<quantity;i++)
 {
   printf("Give price ");
   scanf(" %d", &box.price);
   printf("Give size ");
   scanf(" %c", box.size);
   box.size[1] = '\0';

   Push(&stack, box);
 }

 // Ερωτημα 3ο
 printf("\nItems in the box");
 TraverseStack(stack);

 // Ερωτημα 4ο
 printf("What size do you want? ");
 scanf(" %c", choice);

 Found = FALSE;
 while(!EmptyStack(stack) && Found == FALSE)
 {
   Pop(&stack, &box);

   if(strcmp(box.size, choice)==0)
   {
     Found = TRUE;
   }
   else
   {
     Push(&tempS, box);
   }
 }

 if(Found)
 {
  printf("Found the size %s\n", choice);
 }
 else
 {
   printf("Not Found the size %s\n", choice);
 }

 // Ερωτημα 5ο
 printf("\nItems in the box");
 TraverseStack(stack);

 printf("Items out the box");
 TraverseStack(tempS);

 // Ερωτημα 6ο

 while(!EmptyStack(tempS))
 {
   Pop(&tempS, &box);
   Push(&stack, box);
 }

 // Ερωτημα 7ο
 printf("\nItems in the box");
 TraverseStack(stack);
 printf("Items out the box");
 TraverseStack(tempS);
 }


void CreateStack(StackType *Stack)
{
  Stack -> Top = -1;
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%s, %d\n",Stack.Element[i].size, Stack.Element[i].price);
    }
    printf("\n");
}

