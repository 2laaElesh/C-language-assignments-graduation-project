// Lec_1 assignment 1

#include <stdio.h>

void main(void)
{
	// Defining number of rows and the iteration variables
    int rows=6;
	int i,j;
	 


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
