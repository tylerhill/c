/*
* Program Name: cis27Spring2015TylerHillLab5Ex1.c
* Discussion:	Polynomial	
* Written by:   Tyler Hill
* Date:         2015/04/13
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct FractionTylerHill {
	int num;
	int denom;
};

typedef struct FractionTylerHill FrTH;
typedef FrTH* FrPtr;

struct PolyTermTylerHill {
	int ex;
	FrTH coE;
};

typedef struct PolyTermTylerHill PTermTH;
typedef struct PolyTermTylerHill* PTermAddrTH;

struct PolyListNodeTylerHill {
	PTermAddrTH termAddr;
	struct PolyListNodeTylerHill* next;
};

typedef struct PolyListNodeTylerHill PNodeTH;
typedef struct PolyListNodeTylerHill* PNodeAddrTH;
typedef struct PolyListNodeTylerHill* PListTH;
typedef PListTH* PListAddrTH;

FrPtr createFrTH(void);
void displayFrTylerHill(fr);
void displayPListNodeTH(PNodeAddrTH);
PTermAddrTH createTermTH(void);
PTermAddrTH createTerm01TH(FrPtr,int);
PNodeAddrTH createPolyNodeTH(void);
PNodeAddrTH createPolyNode01TH(PTermAddrTH);
int gcdRecur(int, int);
FrPtr reduceFractionTylerHill(FrPtr);

int main() {
	PNodeAddrTH pNode = createPolyNodeTH();
	displayPListNodeTH(pNode);

	scanf(" ");
	return 0;
}

FrPtr createFrTH() {
	FrPtr frPtr;
	frPtr = (FrPtr) malloc(sizeof(FrTH));
	printf("\nWhat is num?");
	scanf("%d", &frPtr->num);
	do {
		printf("\nWhat is the denominator?");
		printf("\nMUST BE NON-ZERO INTEGER: ");
  		scanf("%d", &frPtr->denom);
	} while (frPtr->denom == 0);
  	reduceFractionTylerHill(frPtr);
}

PTermAddrTH createTermTH() {
	FrPtr coE;
	int ex;
	printf("\nCOEFFICIENT: ");
	coE = createFrTH();
	do {
		printf("\nEXPONENT (MUST BE POSITIVE): ");
  		scanf("%d", &ex);
	} while (ex < 0);
	return createTerm01TH(coE,ex);
}

PTermAddrTH createTerm01TH (FrPtr coE, int ex) {
	PTermAddrTH pTerm = malloc(sizeof(PTermTH));
	pTerm->ex = ex;
	pTerm->coE = *coE;
	return pTerm;
}

PNodeAddrTH createPolyNodeTH() {
	PTermAddrTH pTerm;

	pTerm = createTermTH();
	return createPolyNode01TH(pTerm);

}

PNodeAddrTH createPolyNode01TH(PTermAddrTH pTerm) {
	PNodeAddrTH pNode;
	pNode = malloc(sizeof(PNodeTH));
	pNode->termAddr = pTerm;	
	pNode->next = 0;
	return pNode;
}

void displayFrTylerHill(FrPtr fr) {
	if (fr != 0) {
		printf("\n\tAddress/Location: %d", fr);
		printf("\n\tNumerator: %d", fr->num);
		printf("\n\tDenominator: %d\n", fr->denom);
	}
	else {
		printf("\n\tAddress/Location: NULL\n");
	}
}

void displayPListNodeTH(PNodeAddrTH pNode) {
	if (pNode != 0) {
		printf("\n\tAddress/Location: %d", pNode);
		printf("\n%d / %d x%d",  pNode->termAddr->coE.num, pNode->termAddr->coE.denom, pNode->termAddr->ex);
	} else {
		printf("\n\tAddress/Location: NULL\n");
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
