// Lec_1 assignment 2

#include <stdio.h>

void main(void)
{
	 defining 3 integer variables
	
	int a,b,c; 
	
	printf("Enter number 1: "); 
	scanf("%d",&a); // assigning variable a to the user input
	
	printf("\nEnter number 2: ");
	scanf("%d",&b); // assigning variable b to the user input
	
	printf("\nEnter number 3: ");
	scanf("%d",&c); // assigning variable c to the user input
	
	// printing variables in reversed order
	
	printf("\nNumber 3: %d\n",c); // printing variable c 
	printf("\nNumber 2: %d\n",b); // printing variable b 
	printf("\nNumber 1: %d\n",a); // printing variable a 
	
}