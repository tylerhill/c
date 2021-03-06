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
FrList createFrNodeTylerHill(void);
FrPtr reduceFractionTylerHill(FrPtr);
void insertFirstTylerHill(FrList*);
void insertAtTylerHill(FrList*);
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
			insertFirstTylerHill(&list);
			break;
		case 2:
			displayListTylerHill(list);
			break;
		case 3:
			insertAtTylerHill(list);
			break;
		case 4:
			printf("\nGood work have fun goodbye \n");
			break;
		default:
			printf("\nWRONG OPTION ...\n");
		}
	} while (option != 4);
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
	if (listAddr == 0) {
		printf("Empty!");
	} else {
		while (listAddr->next != 0) {
			displayFrNodeTylerHill(listAddr);
			listAddr = listAddr->next;
		}
		displayFrNodeTylerHill(listAddr);
	}
}

void insertFirstTylerHill(FrList* listAddr) {
	FrNPtr frN;
	frN = createFrNodeTylerHill();
		frN->next = *listAddr;
		*listAddr = frN;
}

void insertAtTylerHill(FrList listAddr) {
	int count = 0;
	int target;
	int i;
	FrNPtr frN;
	frN = createFrNodeTylerHill();
	FrNPtr tmpFrN;
		printf("\nInsert at what position?\n");
		scanf("%d",&target);
	for(i = 0; i < target; i++) {
		listAddr = listAddr->next;
	}
	tmpFrN = listAddr->next;
	listAddr->next = frN;
	frN->next = tmpFrN;

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
