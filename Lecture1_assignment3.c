// Lec_1 assignment 3

#include <stdio.h>

void main(void)
{
	// defining 2 integer variables
	
	int a,b; 
	
	printf("\nEnter number 1: "); 
	scanf("%d",&a); // assigning variable a to the user input
	
	printf("\nEnter number 2: ");
	scanf("%d",&b); // assigning variable b to the user input
	
	
	printf("\nNumber 3: %d\n",a+b); // printing the addition of a and b 
	printf("\nNumber 2: %d\n",a-b); // printing substraction of a and b 
	printf("\nNumber 1: %d\n",a&b); // printing the anding of a and b 
	printf("\nNumber 1: %d\n",a|b);// printing the oring of a and b 
	printf("\nNumber 1: %d\n",a^b);// printing the xoring of a and b 
	
}