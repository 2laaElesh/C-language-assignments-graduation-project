// Lec_3 assignment 3

#include <stdio.h>

void main(void)
{
	// Defining number of rows and the iteration variables
    int rows;
	int i,j;
	 
	// Asking the user to enter number of rows
	
	printf("Please enter the hieght of the pyramid: ");
	scanf("%d",&rows);

    //Iterating through the rows 
    for(i=1; i<=rows; i++)
    { 
        // printing leading spaces 
        for(j=i; j<rows; j++)
        {
            printf(" ");
        }

        // Print star 
        for(j=1; j<=(2*i-1); j++)
        {
            printf("*");
        }

        //Move to next line 
        printf("\n");
    }

}