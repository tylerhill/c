/*
* Program Name: cis27Spring2015TylerHillLab3Ex1.c
* Discussion:	struct Fraction
* Written by:   Tyler Hill
* Date:         2015/03/05
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct Fraction {
	int num;
	int denom;
};

typedef struct Fraction frac;
typedef struct Fraction* frPtr;

void menu(void);
frPtr createFractionTylerHill(void);
frPtr reduceFractionTylerHill(frPtr);
frPtr addFractionTylerHill(frPtr, frPtr);
frPtr subtractFractionTylerHill(frPtr, frPtr);
frPtr multiplyFractionTylerHill(frPtr, frPtr);
frPtr divideFractionTylerHill(frPtr, frPtr);
void displayFractionTylerHill(frPtr);
int gcdRecur(int,int);


int main() {
	printf("CIS 27 - Data Structures");
	printf("\nLaney College");
	printf("\nTyler Hill");
	printf("\n");
	printf("\nAssignment Information -- ");
	printf("\n  Assignment Number:  Lab 03,");
	printf("\n                      Coding Assignment -- Exercise #1");
	printf("\n  Written by:         Tyler Hill");
	printf("\n  Submitted Date:     2015/03/05");
	printf("\n");
	menu();
	return 0;
}


void menu() {
	int option;
	int frOption;
	frPtr lOp = 0;
	frPtr rOp = 0;
	
	do {
		printf("\n");
		printf("\nMENU : Fraction -- Tyler Hill"\
			"\n1. Creating/Updating"\
			"\n2. Adding"\
			"\n3. Subtracting"\
			"\n4. Multiplying"\
			"\n5. Dividing"\
			"\n6. Displaying"\
			"\n7. Quit");
		printf("\nEnter the option: ");
		scanf("%d", &option);

		switch (option) {
		case 1:
				do {
					printf("\nMENU : Creating/Updating"\
						"\n1. Left Operand"\
						"\n2. Right Operand"\
						"\n3. Both Operands"\
						"\n4. Displaying Current Operands"\
						"\n5. Return");
					printf("\nEnter the option: ");
					scanf("%d", &frOption);
					switch(frOption) {
						case 1:
							printf("\nLeft Operand: ");
							lOp = reduceFractionTylerHill(createFractionTylerHill());
							break;
						case 2:
							printf("\nRight Operand: ");
							rOp = reduceFractionTylerHill(createFractionTylerHill());
							break;
						case 3:
							printf("\nLeft Operand: ");
							lOp = reduceFractionTylerHill(createFractionTylerHill());
							printf("\nRight Operand: ");
							rOp = reduceFractionTylerHill(createFractionTylerHill());
							break;
						case 4:
							printf("\n");
							printf("\nLeft Operand:");
							displayFractionTylerHill(lOp);
							printf("\n");
							printf("\nRight Operand:");
							displayFractionTylerHill(rOp);
							break;
						case 5:
							break;
						default:
							printf("\nYou should not be in this class!\n");
					}
				} while (frOption != 5);
			break;
		case 2:
			if(lOp != 0 && rOp != 0) {	
				printf("\nAdding Fractions...");
				printf("\nRESULT:");
				displayFractionTylerHill(addFractionTylerHill(lOp,rOp));
			} else {
				printf("\nNot Allowed Yet - No Proper Data!");
			}
			break;
		case 3:
			if(lOp != 0 && rOp != 0) {	
				printf("\nSubtracting Fractions...");
				printf("\nRESULT:");
				displayFractionTylerHill(subtractFractionTylerHill(lOp,rOp));
			} else {
				printf("\nNot Allowed Yet - No Proper Data!");
			}
			break;
		case 4:
			if(lOp != 0 && rOp != 0) {	
				printf("\nMultiplying Fractions...");
				printf("\nRESULT:");
				displayFractionTylerHill(multiplyFractionTylerHill(lOp,rOp));
			} else {
				printf("\nNot Allowed Yet - No Proper Data!");
			}
			break;
		case 5:
			if(lOp != 0 && rOp != 0) {	
				if(rOp->num != 0) {
					printf("\nDividing Fractions...");
					printf("\nRESULT:");
					displayFractionTylerHill(divideFractionTylerHill(lOp,rOp));
				} else {
					printf("\nCannot divide by ZERO");
				}
			} else {
				printf("\nNot Allowed Yet - No Proper Data!");
			}
			break;
		case 6:
			printf("\n");
			printf("\nLeft Operand:");
			displayFractionTylerHill(lOp);
			printf("\n");
			printf("\nRight Operand:");
			displayFractionTylerHill(rOp);
			break;
		case 7:
			printf("\n\tFeel SOOOOO Great!");
			break;
		default:
			printf("\nYou should not be in this class!\n");
		}
	} while (option != 7);
}


frPtr createFractionTylerHill(void) {
	int num;
	int denom = 0;
	frPtr fr;
	printf("\nCreating Fraction");
	printf("\nWhat is the numerator: ");
	scanf("%d",&num);
	do {
	printf("\nWhat is the denominator?");
	printf("\nMUST BE NON-ZERO INTEGER: ");
	scanf("%d",&denom);
	} while (denom == 0);
	if (denom < 0) {
		denom = -denom;
		num = -num;
	}
	fr = (frPtr) malloc(sizeof(frac));
	fr->num = num;
	fr->denom = denom;
	return fr;
}

void displayFractionTylerHill(frPtr fr) {
	if(fr != 0) {
		printf("\n\tAddress/Location: %d",fr);
		printf("\n\tNumerator: %d",fr->num);
		printf("\n\tDenominator: %d\n",fr->denom);
	} else {
		printf("\n\tAddress/Location: NULL\n");
	}
}

int gcdRecur(int arg1, int arg2) {
	if(arg1 % arg2 == 0) {
		return arg2;
	} else {
		return gcdRecur(arg2, arg1 % arg2);
	}
}

frPtr reduceFractionTylerHill(frPtr fr) {
	int gcd = gcdRecur(fr->num, fr->denom);
	if (gcd < 0) {
		gcd = -gcd;
	}
	if (fr->denom < 0) {
		fr->denom = -fr->denom;
		fr->num = -fr->num;
	}
	fr->num = (fr->num)/gcd;
	fr->denom = (fr->denom)/gcd;
	return fr;
}

frPtr addFractionTylerHill(frPtr fr1, frPtr fr2) {
	frPtr frResult;
	frResult = (frPtr) malloc(sizeof(frac));
	frResult->num = ((fr1->num) * (fr2->denom) + (fr1->denom) * (fr2->num));
	frResult->denom = ((fr1->denom) * (fr2->denom));
	return reduceFractionTylerHill(frResult);
}
frPtr subtractFractionTylerHill(frPtr fr1, frPtr fr2) {
	frPtr frResult;
	frResult = (frPtr) malloc(sizeof(frac));
	frResult->num = ((fr1->num) * (fr2->denom) - (fr1->denom) * (fr2->num));
	frResult->denom = ((fr1->denom) * (fr2->denom));
	return reduceFractionTylerHill(frResult);
}
frPtr multiplyFractionTylerHill(frPtr fr1, frPtr fr2) {
	frPtr frResult;
	frResult = (frPtr) malloc(sizeof(frac));
	frResult->num = ((fr1->num) * (fr2->num));
	frResult->denom = ((fr1->denom) * (fr2->denom));
	return reduceFractionTylerHill(frResult);
}
frPtr divideFractionTylerHill(frPtr fr1, frPtr fr2) {
	frPtr frResult;
	frResult = (frPtr) malloc(sizeof(frac));
	frResult->num = ((fr1->num) * (fr2->denom));
	frResult->denom = ((fr1->denom) * (fr2->num));
	return reduceFractionTylerHill(frResult);
}
/*
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 4
 * 
 * Multiplying Fractions...
 * RESULT:
 *         Address/Location: 18379976
 *         Numerator: -4
 *         Denominator: 21
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 5
 * 
 * Dividing Fractions...
 * RESULT:
 *         Address/Location: 18380048
 *         Numerator: -27
 *         Denominator: 28
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 1
 * 
 * MENU : Creating/Updating
 * 1. Left Operand
 * 2. Right Operand
 * 3. Both Operands
 * 4. Displaying Current Operands
 * 5. Return
 * Enter the option: 3
 * 
 * Left Operand:
 * Creating Fraction
 * What is the numerator: 2
 * 
 * What is the denominator?
 * MUST BE NON-ZERO INTEGER: 11
 * 
 * Right Operand:
 * Creating Fraction
 * What is the numerator: 5
 * 
 * What is the denominator?
 * MUST BE NON-ZERO INTEGER: 101
 * 
 * MENU : Creating/Updating
 * 1. Left Operand
 * 2. Right Operand
 * 3. Both Operands
 * 4. Displaying Current Operands
 * 5. Return
 * Enter the option: 4
 * 
 * 
 * Left Operand:
 *         Address/Location: 18388128
 *         Numerator: 2
 *         Denominator: 11
 * 
 * 
 * Right Operand:
 *         Address/Location: 18388200
 *         Numerator: 5
 *         Denominator: 101
 * 
 * MENU : Creating/Updating
 * 1. Left Operand
 * 2. Right Operand
 * 3. Both Operands
 * 4. Displaying Current Operands
 * 5. Return
 * Enter the option: 5
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 2
 * 
 * Adding Fractions...
 * RESULT:
 *         Address/Location: 18388272
 *         Numerator: 257
 *         Denominator: 1111
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 3
 * 
 * Subtracting Fractions...
 * RESULT:
 *         Address/Location: 18388344
 *         Numerator: 147
 *         Denominator: 1111
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 4
 * 
 * Multiplying Fractions...
 * RESULT:
 *         Address/Location: 18388416
 *         Numerator: 10
 *         Denominator: 1111
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 5
 * 
 * Dividing Fractions...
 * RESULT:
 *         Address/Location: 18388488
 *         Numerator: 202
 *         Denominator: 55
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 1
 * 
 * MENU : Creating/Updating
 * 1. Left Operand
 * 2. Right Operand
 * 3. Both Operands
 * 4. Displaying Current Operands
 * 5. Return
 * Enter the option: 3
 * 
 * Left Operand:
 * Creating Fraction
 * What is the numerator: 6
 * 
 * What is the denominator?
 * MUST BE NON-ZERO INTEGER: 17
 * 
 * Right Operand:
 * Creating Fraction
 * What is the numerator: -8
 * 
 * What is the denominator?
 * MUST BE NON-ZERO INTEGER: 15
 * 
 * MENU : Creating/Updating
 * 1. Left Operand
 * 2. Right Operand
 * 3. Both Operands
 * 4. Displaying Current Operands
 * 5. Return
 * Enter the option: 4
 * 
 * 
 * Left Operand:
 *         Address/Location: 18388560
 *         Numerator: 6
 *         Denominator: 17
 * 
 * 
 * Right Operand:
 *         Address/Location: 18388632
 *         Numerator: -8
 *         Denominator: 15
 * 
 * MENU : Creating/Updating
 * 1. Left Operand
 * 2. Right Operand
 * 3. Both Operands
 * 4. Displaying Current Operands
 * 5. Return
 * Enter the option: 5
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 2
 * 
 * Adding Fractions...
 * RESULT:
 *         Address/Location: 18388704
 *         Numerator: -46
 *         Denominator: 255
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 3
 * 
 * Subtracting Fractions...
 * RESULT:
 *         Address/Location: 18388776
 *         Numerator: 226
 *         Denominator: 255
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 4
 * 
 * Multiplying Fractions...
 * RESULT:
 *         Address/Location: 18388848
 *         Numerator: -16
 *         Denominator: 85
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 5
 * 
 * Dividing Fractions...
 * RESULT:
 *         Address/Location: 18388920
 *         Numerator: -45
 *         Denominator: 68
 * 
 * 
 * MENU : Fraction -- Tyler Hill
 * 1. Creating/Updating
 * 2. Adding
 * 3. Subtracting
 * 4. Multiplying
 * 5. Dividing
 * 6. Displaying
 * 7. Quit
 * Enter the option: 7
 * 	Feel SOOOOO Great!
*/

/*
 * COMMENTS:
 * This was a very effective lab. My understanding of pointers and memory allocation is much clearer and faster now that I have completed the exercise. It was challenging, but certainly not overwhelming.
 */
