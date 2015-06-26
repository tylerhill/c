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
void insertPolyNode(PListAddrTH, PNodeAddrTH);
void removePolyNode(PListAddrTH, int order);
void printList(PListTH);
void simplifyList(PListTH);
int getLength(PListhTH);
int gcdRecur(int, int);
FrPtr addFractionTH(FrPtr, FrPtr);
FrPtr reduceFractionTylerHill(FrPtr);
void menu(void);

int main() {
	menu();
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
  	return reduceFractionTylerHill(frPtr);
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
		printf("(%d/%d)x%d",  pNode->termAddr->coE.num, pNode->termAddr->coE.denom, pNode->termAddr->ex);
	} else {
		printf("\n\tAddress/Location: NULL\n");
	}
	
}

void printList(PListTH pList) {
	if (pList != 0) {
		while(pList->next != 0) {
			displayPListNodeTH(pList);
			printf(" + ");
			pList = pList->next;
		}
		displayPListNodeTH(pList);
	} else {
		printf("0");
	}
}

int getLength(PListTH pList) {
	int count = 0;
	if (pList != 0) {
		while(pList->next != 0) {
			count++;
			pList = pList->next;
		}
		count++;
	}
	return count;
}

void simplifyList(PListAddrTH pList) {
	int order = 0;
	int count;
	int i;
	int j;
	int dupeFlag = 0;
	FrPtr tmpCoE;
	PListTH tmpList;
	PTermAddrTH pTerm;

	tmpCoE = (FrPtr) malloc(sizeof(FrTH));	
	count = getLength(*pList);

	// IF COUNT > 2;
	
	tmpList = *pList;
	for (i = 0; i < count; i++) {
		if(tmpList->termAddr->ex > order) {
			order = tmpList->termAddr->ex;
		}
		tmpList = tmpList->next;
	}
	for (i = order; i >=0; i--) {
		dupeFlag = 0;
		tmpCoE = 0;
		tmpList = *pList;

		for (j = 0; j < count; j++) {
			if (tmpList->termAddr->ex == i) {
				if (tmpCoE == 0) {
					printf("\nnew");
					tmpCoE = &(tmpList->termAddr->coE);
				} else {
					printf("\nadd");
					dupeFlag = 1;
					tmpCoE = addFractionTH(tmpCoE,&(tmpList->termAddr->coE));
				}

			}
			if(tmpList->next != 0) {
				tmpList = tmpList->next;
			}
		}
		if (dupeFlag != 0) {
			printf("\n CoE for %d, : %d / %d", i, tmpCoE->num, tmpCoE->denom);
			insertPolyNode(pList, createPolyNode01TH(createTerm01TH(tmpCoE,i)));
		} else {
			printf("\nzero");
		}

		
		//if (tmpCoE > 0) {
		//	pTerm = createTerm01TH(tmpCoE, i);
		//}

	}
}

void insertPolyNode(PListAddrTH pList, PNodeAddrTH pNode) {
	printf("\nINSERT");
	if (pList == 0) {
		*pList = pNode;
	} else {
		pNode->next = *pList;
		*pList = pNode;
	}	
}

void removePolyNode(PListAddrTH pList, int order) {
	PNodeAddrTH nBefore;
	PNodeAddrTH tmp;
	if (*pList == 0) {
		printf("\n No Nodes to remove!");
	} else if ((*pList)->termAddr->ex == order) {
		tmp = *pList;
		*pList = (*pList)->next;
		free(tmp);
	} else {
		while ((*pList)->next != 0) {
			if ((*pList)->next->termAddr->ex == order) {
				nBefore = *pList;
				tmp = nBefore->next;
				nBefore->next = nBefore->next->next;
				free(tmp);
				return;
			} else {
				*pList = (*pList)->next;
			}
		}	
		printf("\nNo term of that order!");
		return;
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

FrPtr addFractionTH(FrPtr fr1, FrPtr fr2) {
	FrPtr frResult;
	frResult = (FrPtr) malloc(sizeof(FrTH));
	frResult->num = ((fr1->num) * (fr2->denom) + (fr1->denom) * (fr2->num));
	frResult->denom = ((fr1->denom) * (fr2->denom));
	return reduceFractionTylerHill(frResult);
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

void menu() {
	int option;
	int side;
	int order;
	PListTH leftList = 0;
	PListTH rightList = 0;
	PListTH resultList = 0;
	do {
		printf("\nPOLYNOMIAL OPERATIONS"\
			"\n1. Creating polynomials"\
			"\n2. Adding polynomials"\
			"\n3. Multiplying polynomials"\
			"\n4. Displaying polynomials"\
			"\n5. Clearing polynomials"\
			"\n6. Quit");
		printf("\nEnter the option (1 or 2): ");
		scanf("%d", &option);

			switch (option) {
			case 1:
				do {
					printf("\nInsert into left or right polynomial? (1 for left, 2 for right)");
					scanf("%d",&side);
				} while (side != 1 && side != 2);

				if (side==1) {
					insertPolyNode(&leftList,createPolyNodeTH());
				} else {
					insertPolyNode(&rightList,createPolyNodeTH());
				}
				break;
			case 2:
				simplifyList(&leftList);
				break;
			case 3:
				break;
			case 4:
				printf("\nLeft Poly Pointer: ");
				printList(leftList);
				printf("\n");
				printf("\nRight Poly Pointer: ");
				printList(rightList);
				printf("\n");
				printf("\nResult Poly Pointer: ");
				printList(resultList);
				printf("\n");
				break;
			case 5: 
				do {
					printf("\nRemove from left or right polynomial? (1 for left, 2 for right)");
					scanf("%d",&side);
				} while (side != 1 && side != 2);

				if (side==1) {
					printf("\nRemove which order term?");
					scanf("%d",&order);
					removePolyNode(&leftList,order);
				} else {
					printf("\nRemove which order term?");
					scanf("%d",&order);
					removePolyNode(&rightList,order);
				}
				break;
			case 6: 
				break;
			default:
				printf("\nWRONG OPTION ...\n");
			}
	} while (option != 6);
}
