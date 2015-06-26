/**
* Program Name: cis27Spring2015TylerHillMenuSetup.c
* Discussion:
* Written by: Tyler Hill
* Date: 2015/01/29
*/


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// Prototypes

void menu(void);
int extractLargestEvenDigitTylerHill(int);


int main() {
	menu();

	return 0;
}

//Function Definitions

void menu() {
	int option;
	int curUsrInt;

	do {
		printf("MENU"\
			"\n1. Calling extractLargestEvenDigitTylerHill()"\
			"\n2. Quit");
		printf("\nEnter the option (1 or 2): ");

		scanf("%d", &option);

		switch (option) {
		case 1:
			printf("\nEnter the integer: ");
			scanf("%d", &curUsrInt);
			printf("Calling extractLargestEvenDigitTylerHill() ... \n");
			extractLargestEvenDigitTylerHill(curUsrInt);
			break;
		case 2:
			printf("\nGood work have fun goodbye \n");
			break;
		default:
			printf("\nWRONG OPTION ...\n");
		}
	} while (option != 2);
}


int extractLargestEvenDigitTylerHill(usrInt) {
	int lrgDgt = -1;
	int curDgt;
	int lrgCount = 0;
	int remainInt = usrInt;
	do {
		curDgt = remainInt % 10;
		if (curDgt < 0)
			curDgt = -curDgt;
		if (curDgt > lrgDgt && curDgt % 2 == 0)
			lrgDgt = curDgt;
		remainInt /= 10;
	} while (remainInt!=0); 

	remainInt = usrInt;
	do {
		curDgt = remainInt % 10;
		if (curDgt < 0)
			curDgt = -curDgt;
		if (curDgt == lrgDgt)
			lrgCount++;
		remainInt /= 10;
	} while (remainInt!=0);

	if (lrgDgt == -1) {
		printf("\nThere are no even digits.\n");	
		printf("\n");
	} else {
		printf("\n %d has",usrInt);
		printf("\n   - The largest even digit of %d",lrgDgt);
		printf("\n   - And the digit %d occurs %d time(s)\n",lrgDgt,lrgCount);
		printf("\n");
	}

	return lrgDgt;
}

void foo1() {
	int value;
	int digitAry[1];
	int* iPtr;

	value = 5;
	iPtr = &value;
	printf("\nValue stored in iPtr: %p\n", iPtr);

}
