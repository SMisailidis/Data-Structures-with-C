//https://prnt.sc/14f8d7r

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

 #define megisto_plithos 201

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

boolean isPrime(stoixeio_synolou n);
void createPrimeSet(typos_synolou S, stoixeio_synolou first, stoixeio_synolou last);
void displaySet(typos_synolou S, stoixeio_synolou first, stoixeio_synolou last);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);


 main () {

 boolean d1 = FALSE;
 typos_synolou S;
 stoixeio_synolou first, last;


 do
 {
   do
   {
   printf("Dwse ton first akeraio arithmo(apo 0 mexri kai 200): ");
   scanf(" %d", &first);
   }while (first<2 || first>200);

   do
   {
   printf("Dwse ton last akeraio arithmo(apo 0 mexri kai 200): ");
   scanf(" %d", &last);
   }while (last<2 || last>200);


   if(first<last)
     d1 = TRUE;
   else
     d1 = FALSE;

 }while(d1 == FALSE);

  Dimiourgia(S);
  createPrimeSet(S, first, last);
  displaySet(S, first, last);


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

boolean isPrime(stoixeio_synolou n) {

  stoixeio_synolou i;
  stoixeio_synolou p=2;

  for(i=2;i<n-1;i++)
  {
      if(n % i== 0)
        p++;
  }

  if(p>2)
    return FALSE;
  else
    return TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}

void createPrimeSet(typos_synolou S, stoixeio_synolou first, stoixeio_synolou last){

 stoixeio_synolou i;


 for(i=first;i<last;i++)
 {
    if(isPrime(i))
     Eisagogi(i, S);
 }
}

void displaySet(typos_synolou S, stoixeio_synolou first, stoixeio_synolou last){

 stoixeio_synolou i;

 for(i=first;i<last;i++)
 {
     if(Melos(i, S))
        printf("%d ", i);
 }
}
