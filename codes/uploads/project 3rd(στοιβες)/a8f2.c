/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a8f2
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define StackLimit 100  // Stack Total Limit (total inputs 100).

typedef char StackElementType;  // StackElementType as char.

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
/*######################################################################################*/


int main(){

    /* Declarations and Variable Initializations */
    StackType charStack; // Character Stack.
    StackElementType charItem;  // Characters as Stack Items.
    char ch = '-';
    boolean valid = TRUE;
    boolean flag = FALSE;
    /*  */

    /* Creation: Character Stack and Reverse Character Stack */
    CreateStack(&charStack);

    /* Input: The First Character for the Alphanumeric */
    printf("Enter string:\n");
    scanf("%c", &ch);
    getchar();
    if(ch == '#') return 0;

	do{
        /* */
        if(flag == TRUE){
            if(!EmptyStack(charStack))
                Pop(&charStack, &charItem);
            else
                charItem = '-';

            if(charItem == ch)
                valid = TRUE;
            else {
                valid = FALSE;
                break; // Important Break
            }
        }
        /* */

        /* */
        if(ch != 'C' && flag != TRUE){
            charItem = ch;
            Push(&charStack, charItem);
        } else
            flag = TRUE;
        /* */

        /* Input: The Next Character for the Alphanumeric and Validation Checks */
        scanf("%c", &ch);
        getchar();
        if(ch == '#' && !EmptyStack(charStack) && flag == FALSE)
            valid = FALSE;
          else if (ch == '#' && !EmptyStack(charStack) && flag == TRUE)
            valid = FALSE;
          else if (ch == '#' && EmptyStack(charStack) && flag == TRUE)
            break;
        /* */

    } while (valid == TRUE);

    printf(valid ? "TRUE\n" : "FALSE\n");

    return 0;
} // END main()


/*############################### DO NOT CHANGE THE FUNCTIONS ###############################*/
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
/*###########################################################################################*/
