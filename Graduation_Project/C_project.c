#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "STD_Types.h"
#include "admin_window_2.h"
#include "client_window_2.h"

// Below the declaration of the global pointers which will be used with the linked list

extern struct node * head;
extern struct node *ptr;

// ------------------------------------------------------------------------------------


// Below the main function

int main(void){

u16 main_flag=1;

while(main_flag){
	

printf("\nWelcome To ITI Bank System !!\n");
printf("********************************\n");

printf("\nOur system consists of two windows:\n");
printf("\n");
printf("The first one is \"Admin window\" and you can choose it by entering 1\n");
printf("The second one is \"Client window\" and you can choose it by entering 2\n");

printf("\nIf you just want to exit enter 0.\n");
printf("-------------------------------------------------------------------\n");



	
	printf("\n");
	printf("Choose a window by entering (1) for admin and (2) for client and (0) for exit: ");

	u32 window_choice=-1; // defining window choice variable to take it as an input from the user
	scanf("%d",&window_choice);
	
	empty_stdin(); // calling empty function to empty stdin


	switch (window_choice){
		
		case 1:
		Admin_Window(); // calling Admin Window Function
		break;

		case 2:
		Client_Window(); // calling Client Window Function
		break;

		case 0:
		main_flag=0; // exiting the program
		break;

		default:
		printf("Wrong choice !\n"); // printing wrong choice if the input is not in any of the previous cases
		break;}
}

free(head);
free(ptr);

return 0;
}



