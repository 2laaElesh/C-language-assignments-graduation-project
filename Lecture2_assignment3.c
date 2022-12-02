// Lec_2 assignment 3

#include <stdio.h>

void main(void){
	
	int a,b,c;
	
	printf("Enter number 1: ");
	scanf("%d",&a);
	
	printf("Enter number 2: ");
	scanf("%d",&b);
	
	printf("Enter number 3: ");
	scanf("%d",&c);
	
	
	if (a > b && a > c){
	printf("\nMaximum number is %d", a);}
		
	else if (b > a && b > c){
		
	printf("\nMaximum number is %d", b);}
	
	else if (c > a && c > b)
	{
	printf("\nMaximum number is %d", c);	
	}
}