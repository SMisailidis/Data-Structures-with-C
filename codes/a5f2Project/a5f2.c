#include <stdio.h>
#include <stdlib.h>

#define StackLimit 15


typedef int StackElementType;

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

    StackElementType x, i, n, temp;
    StackType Stack, tempS;

    CreateStack(&Stack);

    for(i=0;i<StackLimit;i++)
    {
      Push(&Stack, i*10);
    }
    TraverseStack(Stack);

    printf("Give nth element (n<=%d) ", (Stack.Top-1)/2);
    scanf("%d", &n);

    //Ερωτημα a)

    Pop(&Stack, &x);
    Pop(&Stack, &x);

    printf("\nQuestion a: x=%d\n", x);

    TraverseStack(Stack);


    //Ερωτημα b)

    Pop(&Stack, &temp);
    Pop(&Stack, &x);

    Push(&Stack, x);
    Push(&Stack, temp);

    printf("\nQuestion b: x=%d\n", x);
    TraverseStack(Stack);


    //Ερωτημα c)

    for(i=0;i<n;i++)
        Pop(&Stack, &x);

    printf("\nQuestion c: x=%d\n", x);
    TraverseStack(Stack);


    //Ερωτημα d)

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

   //Ερωτημα e)

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


   //Ερωτημα f)


   while(Stack.Top >= 2)//Διοτι το 1ο στοιχειο ειναι απο την θεση 0
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

    //Ερωτημα g)

    while(!EmptyStack(Stack))
        Pop(&Stack, &x);

    printf("\nQuestion g: x=%d\n", x);
    TraverseStack(Stack);
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
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
