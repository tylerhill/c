/*
 * Program Name: cis27Spring2015TylerHillLab2Ex1.c
 * Discussion:
 * Written by:   Tyler Hill
 * Date:         2015/02/11
 */

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void menu(void);
int* moveEvenDownTylerHill(int*, int);

int main() {
	printf("CIS 27 - Data Structures");
	printf("\nLaney College");
	printf("\nTyler Hill");
	printf("\n");
	printf("\nAssignment Information -- ");
	printf("\n  Assignment Number:  Lab 02,");
	printf("\n                      Coding Assignment -- Exercise #1");
	printf("\n  Written by:         Tyler Hill");
	printf("\n  Submitted Date:     2015/02/12");
	printf("\n");
	menu();
	return 0;
}


void menu() {
	int option;
	int curUsrInt;
	int size;
	int* aryPtr;
	int i;

	do {
		printf("\nMENU Lab 2 Ex 1"\
			"\n1. Calling moveEvenDownTylerHill()"\
			"\n2. Quit");
		printf("\nEnter the option (1 or 2): ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			printf("\nWhat is the size of the array?: ");
			scanf("%d",&size);
			aryPtr = (int*)malloc(size * sizeof(int));
			for(i = 0; i < size; i++) {
				printf("\nEnter value for index %d: ",i);
				scanf("%d", aryPtr + i);
			}
			printf("\nThe original array:");
			for(i = size - 1; i >= 0; i--) {
				printf("\nValue at element index %d : %d ", i, *(aryPtr + i));
			}
			printf("\n");
			printf("\nCalling moveEvenDownTylerHill() -- ");
			printf("\n");
			moveEvenDownTylerHill(aryPtr,size);
			printf("\nThe updated array:");
			for(i = size - 1; i >= 0; i--) {
				printf("\nValue at element index %d : %d ", i, *(aryPtr + i));
			}
			printf("\n");
			break;
		case 2:
			printf("\nGood work have fun goodbye \n");
			break;
		default:
			printf("\nWRONG OPTION ...\n");
		}
	} while (option != 2);
}

int* moveEvenDownTylerHill(int* usrAry, int usrSize) {
	int i;
	int j = 0;
	int temp;
	for(i = 0; i < usrSize; i++) {
		if(*(usrAry + i) % 2 == 0) {
			temp = *(usrAry + j);
			*(usrAry + j) = *(usrAry + i);
			*(usrAry + i) = temp;
			j++;
		}	
	}	
}
/*
 * CIS 27 - Data Structures
 * Laney College
 * Tyler Hill
 * 
 * Assignment Information --
 *   Assignment Number:  Lab 02,
 *                       Coding Assignment -- Exercise #1
 *   Written by:         Tyler Hill
 *   Submitted Date:     2015/02/12
 * 
 * MENU Lab 2 Ex 1
 * 1. Calling moveEvenDownTylerHill()
 * 2. Quit
 * Enter the option (1 or 2): 1
 * 
 * What is the size of the array?: 5
 * 
 * Enter value for index 0: -15
 * 
 * Enter value for index 1: 450
 * 
 * Enter value for index 2: 6
 * 
 * Enter value for index 3: -9
 * 
 * Enter value for index 4: 9
 * 
 * The original array:
 * Value at element index 4 : 9
 * Value at element index 3 : -9
 * Value at element index 2 : 6
 * Value at element index 1 : 450
 * Value at element index 0 : -15
 * 
 * Calling moveEvenDownTylerHill() --
 * 
 * The updated array:
 * Value at element index 4 : 9
 * Value at element index 3 : -9
 * Value at element index 2 : -15
 * Value at element index 1 : 6
 * Value at element index 0 : 450
 * 
 * MENU Lab 2 Ex 1
 * 1. Calling moveEvenDownTylerHill()
 * 2. Quit
 * Enter the option (1 or 2): 1
 * 
 * What is the size of the array?: 6
 * 
 * Enter value for index 0: 100
 * 
 * Enter value for index 1: -15
 * 
 * Enter value for index 2: 450
 * 
 * Enter value for index 3: 6
 * 
 * Enter value for index 4: -90
 * 
 * Enter value for index 5: 9
 * 
 * The original array:
 * Value at element index 5 : 9
 * Value at element index 4 : -90
 * Value at element index 3 : 6
 * Value at element index 2 : 450
 * Value at element index 1 : -15
 * Value at element index 0 : 100
 * 
 * Calling moveEvenDownTylerHill() --
 * 
 * The updated array:
 * Value at element index 5 : 9
 * Value at element index 4 : -15
 * Value at element index 3 : -90
 * Value at element index 2 : 6
 * Value at element index 1 : 450
 * Value at element index 0 : 100
 * 
 * MENU Lab 2 Ex 1
 * 1. Calling moveEvenDownTylerHill()
 * 2. Quit
 * Enter the option (1 or 2): 2
 */
