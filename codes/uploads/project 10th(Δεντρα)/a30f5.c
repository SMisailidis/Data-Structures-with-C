/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a30f5
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define  MaxElements 50         // The maximum number of Heap elements.

typedef float HeapElementType;    // The Heap Data type.

typedef  struct {
     HeapElementType key;
} HeapNode;                     // The Heap Tree Node.

typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

/*######################################### MODIFIED ADT FUNCTIONS #######################################*/
//Min Heap Modifications
void CreateMinHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMinHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMinHeap(HeapType *Heap, HeapNode *Item);
/*########################################################################################################*/

/*########################################### MY NEW FUNCTIONS ###########################################*/
void PrintHeap(HeapType Heap);
/*########################################################################################################*/

int main(){

    /* Variables Declarations and Initialization */
    HeapType theHeap;
    HeapNode heapItem;
    int m;
    FILE *transData = NULL; // The creation of the File Pointer with NULL initialization.
    int flag = 0; //To check valid data entries in dataset.
    int lineCount = 1; // The first line of data entry in the file.

    /* Read Transactions Database */
    transData = fopen("transactions.txt", "r");

    if(transData == NULL){
        printf("...Transactions database file does not exist...\n");
        return -1;
    }

    /* Create the Min Heap */
    CreateMinHeap(&theHeap);

    /* Input Max Data Range to Check */
    printf("Give m: ");
    scanf("%d", &m);

    /* Data Processing with Min Heap Functions */
    while(!feof(transData)){

        flag = fscanf(transData, "%f", &heapItem.key);

        /* Check Error Data Entry */
        if(flag==0){
            printf("DATABASE ERROR - CHECK DATA ENTRY IN LINE %d\n", lineCount);
            printf("VALID DATA ENTRY ONLY: float values\n");
            return -1;
        }

        InsertMinHeap(&theHeap, heapItem);

        if(theHeap.Size > m) DeleteMinHeap(&theHeap, &heapItem);

        lineCount++;
    }

    /* Close the File and NULL the File Pointer */
    fclose(transData);
    transData = NULL;

    /* Display Min Heap Transactions Array */
    PrintHeap(theHeap);

    /* Sort and Display Min Heap Transactions Array */
    printf("Transactions\n");
    while(!EmptyHeap(theHeap)){
        DeleteMinHeap(&theHeap, &heapItem);
        printf("%.2f ",heapItem.key);
    }

    return 0;
}// END main()


/*######################################### MODIFIED ADT FUNCTIONS #######################################*/
void CreateMinHeap(HeapType *Heap)
/* Λειτουργία: Δημιουργεί ένα κενό σωρό.
   Επιστρέφει: Ένα κενό σωρό
*/
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ελέγχει αν ο σωρός είναι κενός.
   Επιστρέφει: TRUE αν ο σωρός είναι κενός, FALSE διαφορετικά
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό.
   Λειτουργία: Ελέγχει αν ο σωρός είναι γεμάτος.
   Επιστρέφει: TRUE αν ο σωρός είναι γεμάτος, FALSE διαφορετικά
*/
{
  return (Heap.Size==MaxElements);
}

void InsertMinHeap(HeapType *Heap, HeapNode Item)
/*  Δέχεται:    Ένα σωρό Heap και ένα στοιχείο δεδομένου Item .
    Λειτουργία: Εισάγει το στοιχείο Item στο σωρό, αν ο σωρός δεν είναι γεμάτος.
    Επιστρέφει: Τον τροποποιημένο σωρό.
    Έξοδος:     Μήνυμα γεμάτου σωρού αν ο σωρός είναι γεμάτος
*/
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key < Heap->Element[hole/2].key) //Changed: Original for Max Heap >
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMinHeap(HeapType *Heap, HeapNode *Item)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ανακτά και διαγράφει το μεγαλύτερο στοιχείο του σωρού.
   Επιστρέφει: Το μεγαλύτερο στοιχείο Item του σωρού και τον τροποποιημένο σωρό
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
                if ((*Heap).Element[child].key > (*Heap).Element[child+1].key) //Changed: Original for Max Heap <
                    child++;
            if (last.key <= (*Heap).Element[child].key) // Changed: Original for Max Heap >=
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
/*########################################################################################################*/


/*########################################### MY NEW FUNCTIONS ###########################################*/
void PrintHeap(HeapType Heap)
{
    int i;
    printf("Data Structure size =%d \n",Heap.Size);
     for (i=1; i<=Heap.Size;i++)
        printf("%.2f ",Heap.Element[i].key);
    printf(" \n");
}
/*########################################################################################################*/

