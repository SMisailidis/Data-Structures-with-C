#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define megisto_plithos 1001


typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

boolean isFibonacci(stoixeio_synolou n,typos_synolou S);
boolean Melos(stoixeio_synolou n,typos_synolou S);
void createFibonacciSet(stoixeio_synolou threshold,typos_synolou S);
void displayset(typos_synolou S, int max);
void Dimiourgia(typos_synolou S);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);




main() {

 typos_synolou S;
 stoixeio_synolou number, max;
 boolean d;


 Dimiourgia(S);

  do
   {
   printf("Dwse to megistoarithmo. ");
   scanf(" %d", &max);
   }while (max<2 || max>1000);

   createFibonacciSet(max, S);
   displayset(S, max);

  do{
    printf("Enter number to check: ");
    scanf("%d", &number);


    if(number>=0)
    {
      d = isFibonacci(number, S);
      if(d)
        printf("Fibonacci!\n");
      else
        printf("Not Fibonacci...\n");
    }
  }while(number>=0);
}

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i <megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou n, typos_synolou S)
{
  return S[n];
}


boolean isFibonacci(int n,typos_synolou S){

  if(Melos(n,S))
    return TRUE;
  else
    return FALSE;
}

void createFibonacciSet(int threshold, typos_synolou S){

 stoixeio_synolou i=1;
 stoixeio_synolou sum;
 stoixeio_synolou temp1=1;
 stoixeio_synolou temp2=0;

 do{
    i++;
    Eisagogi(temp2, S);
    sum = temp1 + temp2;
    temp2 = temp1;
    temp1 = sum;
 }while(sum <= threshold);

  Eisagogi(temp2, S);
}

void displayset(typos_synolou S, int max)
{
	stoixeio_synolou i;

	for (i=0;i <max;i++)
	{
      if(Melos(i,S))
       printf("%d ",i);
	}
	printf("\n");
}
