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
void insMenu(FrList*);
void remMenu(FrList*);
FrNPtr createFrNodeTylerHill(void);
FrPtr reduceFractionTylerHill(FrPtr);
void insertFirstTylerHill(FrList*,FrNPtr);
void insertAtTylerHill(FrList*,FrNPtr);
void appendTylerHill(FrList*,FrNPtr);
void removeFirstTylerHill(FrList*);
void removeAtTylerHill(FrList*);
void removeLastTylerHill(FrList*);
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
		printf("\nLINKED LIST MENU: Fraction"\
			"\n1. Displaying current list"\
			"\n2. Inserting"\
			"\n3. Removing"\
			"\n4. Quit");
		printf("\nEnter the option (1 or 2): ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			displayListTylerHill(list);
			break;
		case 2:
			insMenu(&list);
			break;
		case 3:
			remMenu(&list);
			break;
		case 4:
			printf("\nGood work have fun goodbye \n");
			break;
		default:
			printf("\nWRONG OPTION ...\n");
		}
	} while (option != 4);
}

void insMenu(FrList* list) {
	int subOpt;
		do {
			printf("\nINSERTING");
			printf("\n1. First Node");
			printf("\n2. N-Th Node");
			printf("\n3. Last Node");
			printf("\n4. Displaying");
			printf("\n5. Quit");
			printf("\nEnter Option: ");
			scanf("%d", &subOpt);
			switch(subOpt) {
			case 1:
				insertFirstTylerHill(list,createFrNodeTylerHill());
				break;
			case 2:
				insertAtTylerHill(list,createFrNodeTylerHill());
				break;
			case 3:
				appendTylerHill(list,createFrNodeTylerHill());
				break;
			case 4:
				displayListTylerHill(*list);
				break;
			case 5:
				break;
			default:
				printf("\nWRONG OPTION ...\n");
			}
		} while (subOpt != 5);
}

void remMenu(FrList* list) {
	int subOpt;
		do {
			printf("\nREMOVING");
			printf("\nEnter Option: ");
			printf("\n1. First Node");
			printf("\n2. N-Th Node");
			printf("\n3. Last Node");
			printf("\n4. Displaying");
			printf("\n5. Quit");
			printf("\nEnter Option: ");
			scanf("%d", &subOpt);
			switch(subOpt) {
			case 1:
				removeFirstTylerHill(list);
				break;
			case 2:
				removeAtTylerHill(list);
				break;
			case 3:
				removeLastTylerHill(list);
				break;
			case 4:
				displayListTylerHill(*list);
				break;
			case 5:
				break;
			default:
				printf("\nWRONG OPTION ...\n");
			}
		} while (subOpt != 5);
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
			printf("\nThere are %d nodes.",count);
			printf("\nInsert after which node? (FIRST NODE IS 0): ");
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
void removeFirstTylerHill(FrList* listAddr) {
	FrList tmpFrN;
	tmpFrN = *listAddr;
	*listAddr = (*listAddr)->next;
	free(tmpFrN);
}

void removeAtTylerHill(FrList* listAddr) {
	int target;
	int count = 0;
	int i;
	FrNPtr trgFrN;
	FrList tmpFrN;
	tmpFrN = *listAddr;
	
	if(tmpFrN != 0) {
		while(tmpFrN->next != 0) {
			count++;
			tmpFrN = tmpFrN->next;
		}
		count++;
	}

	tmpFrN = *listAddr;

        if (count == 0 ) {
		printf("\nCANNOT REMOVE FROM EMPTY LIST");
	} else if (count == 1) {
		removeFirstTylerHill(listAddr);
	} else {

		do {	
			printf("\nThere are %d nodes.",count);
			printf("\nRemove which node? (FIRST NODE IS 0): ");
			scanf("%d",&target);
		} while (target >= count);
		if (target == 0) {
			removeFirstTylerHill(listAddr);
		} else {
			for(i = 0; i < (target-1); i++) {
				tmpFrN = tmpFrN->next;
			}
			trgFrN = tmpFrN->next;	
			tmpFrN->next = tmpFrN->next->next;
			free(trgFrN);
		}
	}
}

void removeLastTylerHill(FrList* listAddr) {
	int count = 0;
	int i;
	FrNPtr trgFrN;
	FrList tmpFrN;
	tmpFrN = *listAddr;
	
	if(tmpFrN != 0) {
		while(tmpFrN->next != 0) {
			count++;
			tmpFrN = tmpFrN->next;
		}
		count++;
	}

	tmpFrN = *listAddr;

        if (count == 0) {
		printf("\nCANNOT REMOVE FROM EMPTY LIST");
	} else if (count == 1) {
		removeFirstTylerHill(listAddr);
	} else {
		for(i = 0; i < (count - 2); i++) {
			tmpFrN = tmpFrN->next;
		}
		trgFrN = tmpFrN->next;
		tmpFrN->next = 0;
		free(trgFrN);
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
