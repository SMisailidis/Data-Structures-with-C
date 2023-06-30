#include <stdio.h>
#include <stdlib.h>

#define  MaxElements 8          //�� ������� ������ ��� ��������� ��� �����

typedef char  HeapElementType;    //� ����� ��������� ��� ��������� ��� �����
typedef  struct {
     HeapElementType key;
     //int Data;                // ����������� ����� ��� �� ����������� �������� ���� ������
} HeapNode;


typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMaxHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMaxHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMaxHeap(HeapType *Heap, HeapNode *Item);

void PrintHeap(HeapType Heap);
boolean Search(HeapType Heap, HeapElementType ArgKey, int *left, int *right);

int main()
{
    HeapType AHeap;
    HeapNode AnItem;
    HeapElementType ArgKey;
    int left, right;

    CreateMaxHeap(&AHeap);

    for(int i=0;i<MaxElements;i++) {
        printf("Enter a letter : ");
        fflush(stdin);
        scanf("%c", &AnItem.key);
        InsertMaxHeap(&AHeap, AnItem);
    }
    PrintHeap(AHeap);

    for(int i=0;i<4;i++){
        printf("Enter a letter : ");
        fflush(stdin);
        scanf("%c", &ArgKey);

        if(Search(AHeap, ArgKey, &left, &right)) {
            printf("L=%d, R=%d\n", left, right);
            printf("%c %c\n", AHeap.Element[left].key, AHeap.Element[right].key);
        }
        else{
            printf("Not found\n");
        }
    }

    return 0;
}

void CreateMaxHeap(HeapType *Heap)
/* ����������: ���������� ��� ���� ����.
   ����������: ��� ���� ����
*/
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
/* �������:    ��� ���� Heap.
   ����������: ������� �� � ����� ����� �����.
   ����������: TRUE �� � ����� ����� �����, FALSE �����������
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* �������:    ��� ����.
   ����������: ������� �� � ����� ����� �������.
   ����������: TRUE �� � ����� ����� �������, FALSE �����������
*/
{
  return (Heap.Size==MaxElements);
}

void InsertMaxHeap(HeapType *Heap, HeapNode Item)
/*  �������:    ��� ���� Heap ��� ��� �������� ��������� Item .
    ����������: ������� �� �������� Item ��� ����, �� � ����� ��� ����� �������.
    ����������: ��� ������������� ����.
    ������:     ������ ������� ����� �� � ����� ����� �������
*/
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key > Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMaxHeap(HeapType *Heap, HeapNode *Item)
/* �������:    ��� ���� Heap.
   ����������: ������ ��� ��������� �� ���������� �������� ��� �����.
   ����������: �� ���������� �������� Item ��� ����� ��� ��� ������������� ����
*/
{
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        *Item=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child<=(*Heap).Size && !done)
        {
            if (child<(*Heap).Size)
                if ((*Heap).Element[child].key < (*Heap).Element[child+1].key)
                    child++;
            if (last.key >= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}

void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("Size=%d \n",Heap.Size);
     printf("N   L   R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%c, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%c, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%c \n",Heap.Element[r].key);
         else printf("\n");
     }
     printf("Heap array\n");
     for (i=1; i<=Heap.Size;i++)
        printf("%c ",Heap.Element[i].key);
    printf(" \n");
}

boolean Search(HeapType Heap, HeapElementType ArgKey, int *left, int *right) {
    int current = 1; // Start from the root node

    while (current <= Heap.Size) {
        if (Heap.Element[current].key != ArgKey) {
            current++; // Move to the next node
        } else {
            // Update left and right values
            *left = current * 2;
            *right = (current * 2) + 1;

            // Check if left and right values are within the heap size
            if (*left > Heap.Size) {
                *left = -1; // Invalid value
            }
            if (*right > Heap.Size) {
                *right = -1; // Invalid value
            }

            return TRUE; // Key found
        }
    }

    return FALSE; // Key not found
}
