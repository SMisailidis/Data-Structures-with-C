#include <stdio.h>
#include <stdlib.h>


#define StackLimit 80

typedef char StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);





int main()
{

  boolean d=TRUE;
  StackElementType x, ch;
  StackType stack, tempS;
  int p=0;

  printf("Enter string:\n");

  CreateStack(&stack);
  CreateStack(&tempS);




  while(!FullStack(stack)){

        scanf("%c", &ch);
        getchar();

        if(p == 0 && ch == '#'){
            return 0;
        }
        if(ch != 'C'){
            if(ch != '#'){
                Push(&stack, ch);
                p++;
            }
            else{
                d = FALSE;
                break;
            }
        }
        else{
            break;
        }
  }

  while(ch != '#'){

        scanf("%c", &ch);
        getchar();
        if (ch != '#'){
            if(!EmptyStack(stack)){
                Pop(&stack, &x);
                p --;
            }
            if(x != ch || ch == '#'){
                d = FALSE;
                break;
            }
        }
        else{
            break;
        }
  }
  if(d && p == 0){
    printf("TRUE");
  }
  else{
    printf("FALSE");
  }








    return 0;
}


void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������:    ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������:    ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������:    ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������:     ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������:    ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:     ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}
