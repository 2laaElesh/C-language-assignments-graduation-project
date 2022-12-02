// Lec_4 assignment 1

 int max_num(int,int,int,int);
 
 int min_num(int,int,int,int);

#include <stdio.h>

void main (void)
{
	
	
	// defining 4 integer variables
	
	int a,b,c,d; 
	
	// defining max and min variabkes to print the results
	int max;
	int min;
	
	printf("\nEnter the value of the first number: ");
	scanf("%d",&a);
	
	printf("\n");
	
	printf("Enter the value of the second number: ");
	scanf("%d",&b);
	
	printf("\n");
	
	printf("Enter the value of the third number: ");
	scanf("%d",&c);
	
	printf("\n");
	
	printf("Enter the value of the fourth number: ");
	scanf("%d",&d);
	
	printf("\n");
	
	max=max_num(a,b,c,d);
	min=min_num(a,b,c,d);
	
	printf("The maximum number= %d\n",max);
	printf("The minimum number= %d\n",min);
	
	
}



int max_num(int a, int b, int c, int d){
	
	int max;
	
	if (a>b && a>c && a>d)
	max=a;
	else if (b>a && b>c && b>d)
	max=b;
	else if (c>a && c>b && c>d)
	max=c;
	else if (d>a && d>b && d>c)
	max=d;
	else
	printf("Numbers are equal!");

	return max;
}
 
int min_num(int a, int b, int c, int d){
	 
	 int min;
	
	if (a<b && a<c && a<d)
	min=a;
	else if (b<a && b<c && b<d)
	min=b;
	else if (c<a && c<b && c<d)
	min=c;
	else if (d<a && d<b && d<c)
	min=d;
	else
	printf("Numbers are equal!");

	return min;
	
 }