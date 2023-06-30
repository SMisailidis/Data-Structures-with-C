/*
   ----------------------------------------------------------------------------------------------
   Team Name: CyberPunks <3
   Authors: Leontief Marios, Misailidis Savvas, Taouktsis Xenofon, Xenodochidis Dimitrios Georgios
   Academic UOM ID: iis21026, ics21166, dai19312, it1559
   Emails: iis21026@uom.edu.gr, ics2166@uom.edu.gr, dai19312@uom.edu.gr, it1559@uom.edu.gr
   ----------------------------------------------------------------------------------------------
   Project Name: a4f6
   Course: Domes Dedomenwn
   ----------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HMax 9              /*     �� ������� ��� ������ HashTable
                                ���������� ��� �� 5 */
#define VMax 30             /*�� ������� ��� ������,
                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

typedef struct{
    char phone[11];
    int code;
} ListElementType;  /*����� ��������� ��� �� �������� ��� ������
                               * ���������� ����� int */
typedef char KeyType[32];

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // ������� ������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // D������� �� ��� �������� ���������
    int StackPtr;           // ������� ���� ��� ����� �������� ���� ��� ������ List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

/*############################# DO NOT CHANGE THE FUNCTIONS ############################*/
void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
/*######################################################################################*/

/*########################################### MY NEW FUNCTIONS #########################*/
int findAverage(KeyType s);
void BuildHashList(HashListType *HList);
void Search_HashList_By_Subject(HashListType HList, int code);
void PrintPinakes(HashListType HList);
void Print_HashList(HashListType HList);
/*######################################################################################*/

int main(){

    HashListType HList;
    ListElm AnItem;
    KeyType AKey;
    int Loc, Pred;
    char surname[20];
    char ch;
    int code;

    //.1
    printf("1. Create HashList\n");
    BuildHashList(&HList);
    PrintPinakes(HList);

    //.2
    printf("2. Insert new teacher\n");
    do{
        printf ("Enter teacher's name: ");
        scanf("%s", AnItem.RecKey);
        printf("Enter teacher's surname: ");
        scanf("%s", surname);
        strcat(AnItem.RecKey," ");
        strcat(AnItem.RecKey, surname);
        printf("Enter teacher's phone: ");
        scanf("%s", AnItem.Data.phone);

        printf("Enter teacher code: ");
        scanf("%d",&AnItem.Data.code);
        AddRec(&HList,AnItem);
        printf ("\nContinue Y/N: ");
        do{
            scanf("%c", &ch);
        }while(toupper(ch) != 'N' && toupper(ch) != 'Y');
    }while(toupper(ch) != 'N');;
    PrintPinakes(HList);

    //.3
    printf("3. Delete a teacher\n");
    printf("Enter teacher's name: ");
    scanf("%s", AKey);
    printf("Enter teacher's surname: ");
    scanf("%s", surname);
    strcat(AKey," ");
    strcat(AKey, surname);

    DeleteRec(&HList,AKey);
    PrintPinakes(HList);

    //.4
    printf("4. Search for a teacher\n");
    printf("Enter teacher's name: ");
    scanf("%s", AKey);
    printf("Enter teacher's surname: ");
    scanf("%s", surname);
    strcat(AKey," ");
    strcat(AKey, surname);
    SearchHashList(HList,AKey,&Loc,&Pred);
    if(Loc!=-1)
        printf("[%s,%s,%d]\n",HList.List[Loc].RecKey, HList.List[Loc].Data.phone, HList.List[Loc].Data.code);
    else
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s\n",AKey);

    //.5
    printf("\n5. Search by subject\n");
    printf("Enter code: ");
    scanf("%d",&code);
    printf("List of teachers with subject code %d:\n",code);
    Search_HashList_By_Subject(HList,code);


    return 0;
}


void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //���������� ��� ������� ��� ��������� ������ ��� ����� HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

int HashKey(KeyType Key)
/* �������:    ��� ���� Key ���� ��������.
   ����������: ������� ��� ���� ��������������� HValue ��� �� ������ Key.
   ����������: ��� ���� ��������������� HValue
*/
{
	/*�� ��������� ��� �� KeyType ��� ����� ��������
	�� ������ �� ������������ ��������� �� ������ �� ������*/
	int avg;
    avg=findAverage(Key);
	return avg%HMax;
}

boolean FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ���� �������� ���������.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ��� ������������
                �������� ���� ��������
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey,KeyArg) == 0)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}

void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}

int findAverage(KeyType s){

    char first,last;

    first=toupper(s[0]);
    last=toupper(s[strlen(s)-1] );


    return ((first-64)+(last-64))/2;
}

void BuildHashList(HashListType *HList){

    ListElm AnItem;
    FILE *fp;
    int nscan;
    char termch,surname[20];

    CreateHashList(HList);

    fp=fopen("i4f6.txt","r");
    if (fp == NULL)
        printf("Can't open i4f6.txt\n");
    else{
        while (TRUE){
            nscan = fscanf(fp,"%32[^,],%20[^,],%11[^,],%d%c ",AnItem.RecKey,surname,AnItem.Data.phone,&AnItem.Data.code,&termch);

            if (nscan == EOF) break;
            if (nscan != 5 || termch != '\n') {printf("Improper file format\n"); break;}
            else{
                strcat(AnItem.RecKey," ");
                strcat(AnItem.RecKey, surname);
                AddRec(HList,AnItem);
            }
        }
    }

    fclose(fp);
}

void Search_HashList_By_Subject(HashListType HList, int code){

    int i,Sublndex;

    for(i=0;i<HMax;i++){
        Sublndex=HList.HashTable[i];
        while(Sublndex!=EndOfList){
            if(HList.List[Sublndex].Data.code==code){
                printf("%d:[%s,%s,%d]\n",Sublndex, HList.List[Sublndex].RecKey, HList.List[Sublndex].Data.phone, HList.List[Sublndex].Data.code);
            }
        Sublndex=HList.List[Sublndex].Link;
        }
    }
}

void PrintPinakes(HashListType HList){

    int i;

	printf("Hash table\n");

	for (i=0; i<HMax;i++){
        printf("%d,",HList.HashTable[i]);
	}

	printf("\nHash List\n");

    for (i=0;i<HList.Size;i++){
        printf("%d) %s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
    }

	printf("\n");
}


void Print_HashList(HashListType HList){

    int i, SubIndex;

    printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
    printf("========================================\n");
    printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");

    for (i=0; i<HMax;i++){
        printf("%d| %d\n",i,HList.HashTable[i]);
    }

    printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");

    for (i=0; i<HMax;i++){
        SubIndex = HList.HashTable[i];
        while ( SubIndex != EndOfList ){
            //printf("[%d, %d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data,HList.List[SubIndex].Link);
            printf("[%s, %s, %d]\n",HList.List[SubIndex].RecKey, HList.List[SubIndex].Data.phone, HList.List[SubIndex].Data.code);
            printf(" -> ");

            SubIndex = HList.List[SubIndex].Link;
        } //* while *)
        printf("TELOS % dHS YPO-LISTAS\n", i);
    }

    printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
    SubIndex = HList.StackPtr;

    while ( SubIndex != EndOfList ){
        printf("%d <= ",SubIndex);
        SubIndex = HList.List[SubIndex].Link;
    }

    printf("TELOS\n");
    printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
    printf("========================================\n");
}
