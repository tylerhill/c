/*
* Program Name: cis27Spring2015TylerHillLab4Ex1.c
* Discussion:	Fraction Linked-List
* Written by:   Tyler Hill
* Date:         2015/03/18
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct FractionTylerHill {
	int num;
	int denom;
};

typedef struct FractionTylerHill Frac;
typedef Frac* FrPtr;

struct FractionNodeTylerHill {
  	Frac fr;
  	struct FractionNodeTylerHill* next;
};

typedef struct FractionNodeTylerHill FracN;
typedef FracN* FrNAddr;
typedef FracN* FrNPtr;
typedef FracN* FrList;


void menu(void);
FrNPtr createFrNodeTylerHill(void);
FrPtr reduceFractionTylerHill(FrPtr);
void insertFirstTylerHill(FrList*,FrNPtr);
void insertAtTylerHill(FrList*,FrNPtr);
void appendTylerHill(FrList*,FrNPtr);
void displayFrNodeTylerHill(FrNPtr);
void displayListTylerHill(FrList);
int gcdRecur(int, int);

int main() {
	menu();
	return 0;
}

void menu() {
	int option;
	FrList list = 0;
	do {
		printf("\nMENU "\
			"\n1. Calling ()"\
			"\n2. Quit");
		printf("\nEnter the option (1 or 2): ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			insertFirstTylerHill(&list,createFrNodeTylerHill());
			break;
		case 2:
			displayListTylerHill(list);
			break;
		case 3:
			insertAtTylerHill(&list,createFrNodeTylerHill());
			break;
		case 4:
			appendTylerHill(&list,createFrNodeTylerHill());
			break;
		case 5:
			printf("\nGood work have fun goodbye \n");
			break;
		default:
			printf("\nWRONG OPTION ...\n");
		}
	} while (option != 5);
}



FrNPtr createFrNodeTylerHill() {
  FrNPtr frNPtr;
  frNPtr = (FrNPtr) malloc(sizeof(FracN));

  frNPtr->next = 0;
  printf("\nWhat is num?");
  scanf("%d", &frNPtr->fr.num);
  do {
		printf("\nWhat is the denominator?");
		printf("\nMUST BE NON-ZERO INTEGER: ");
  		scanf("%d", &frNPtr->fr.denom);
	} while (frNPtr->fr.denom == 0);
  reduceFractionTylerHill(&frNPtr->fr);
  return frNPtr;
}



void displayFrNodeTylerHill(FrNPtr frN) {
	if (frN != 0) {
		printf("\n\tAddress/Location: %d", frN);
		printf("\n\tNumerator: %d", frN->fr.num);
		printf("\n\tDenominator: %d\n", frN->fr.denom);
		printf("\n\tNext Fraction at: %d\n", frN->next);
	}
	else {
		printf("\n\tAddress/Location: NULL\n");
	}
}

void displayListTylerHill(FrList listAddr) {
	int count = 0;
	if (listAddr == 0) {
		printf("Empty!");
	} else {
		while (listAddr->next != 0) {
			printf("\nNode %d:",count);
			displayFrNodeTylerHill(listAddr);
			listAddr = listAddr->next;
			count++;
		}
		printf("\nNode %d:",count);
		displayFrNodeTylerHill(listAddr);
	}
}

void insertFirstTylerHill(FrList* listAddr, FrNPtr frN) {
		frN->next = *listAddr;
		*listAddr = frN;
}

void insertAtTylerHill(FrList* listAddr, FrNPtr frN) {
	int count = 0;
	int target;
	int i;
	FrList tmpFrN;
	tmpFrN = *listAddr;

	if(tmpFrN != 0) {
		while(tmpFrN->next != 0) {
			count++;
			tmpFrN = tmpFrN->next;
		}
		count++;
	}

	if(count != 0) {

		tmpFrN = *listAddr;	
		do {	
			printf("\nInsert after which node? (First node is node 0): ");
			scanf("%d",&target);
		} while (target >= count);

			for(i = 0; i < target; i++) {
				tmpFrN = tmpFrN->next;
			}
			frN->next = tmpFrN->next;
			tmpFrN->next = frN;
	} else {
		printf("\nNo index available for insert, beginning list with last node entered.");
		insertFirstTylerHill(listAddr,frN); 
	}
}
void appendTylerHill(FrList* listAddr, FrNPtr frN) {
	FrList tmpFrN;
	tmpFrN = *listAddr;

	if(tmpFrN != 0) {
		while(tmpFrN->next != 0) {
			tmpFrN = tmpFrN->next;
		}
		tmpFrN->next = frN;
	} else {
		insertFirstTylerHill(listAddr, frN);
	}
	
}

int gcdRecur(int arg1, int arg2) {
	if (arg1 % arg2 == 0) {
		return arg2;
	}
	else {
		return gcdRecur(arg2, arg1 % arg2);
	}
}

FrPtr reduceFractionTylerHill(FrPtr fr) {
	int gcd = gcdRecur(fr->num, fr->denom);
	if (gcd < 0) {
		gcd = -gcd;
	}
	if (fr->denom < 0) {
		fr->denom = -fr->denom;
		fr->num = -fr->num;
	}
	fr->num = (fr->num) / gcd;
	fr->denom = (fr->denom) / gcd;
	return fr;
}
