// Lec_2 assignment 1

#include <stdio.h>

void main(void)
{
	// Defining array of 10 numbers and using for loop to assign the values
	int arr[10];
	int i;
	
	for (i=0;i<10;i++)
	{
		printf("\nEnter number %d: ",i);
		scanf("%d",&arr[i]);
		
	}
	
	int value; // The value variable will be used in search 
	printf("\nEnter the value to search:");
	scanf( "%d",&value);
	
	// Assume that value does not exist in the array by defining a flag //
    int exist = 0; 
	
	// for loop is used to search for the value in all the elemtns of the array	
	
	for (i=0;i<10;i++)
	{
		if (value == arr[i])
		{
			exist= 1;
			break;}
	}
	// if the flag is 1 then the value exist
	if (exist == 1)
		{printf("Value exist at element number %d", i+1);}
	
	else 
	{printf("Value doesn't exist !");}

}
