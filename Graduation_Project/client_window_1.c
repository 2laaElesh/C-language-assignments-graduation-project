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


// Below the implementation of Client window function

void Client_Window(void){

		u32 flag4=1; // Defining a flag to exit from the while loop

		while(flag4){
			
		printf("Enter your Bank Account ID: "); 
		u32 client_bank_account_ID; // Defining the bank account ID variable
		scanf("%d",&client_bank_account_ID);
		empty_stdin(); // calling empty function to empty stdin

		ptr =head;
		struct node * search = searchlist(ptr, client_bank_account_ID); // searching for the account using the ID
			
		if (search == NULL){ // if statement is used to check if the bank account exists in the list or not / search function found the bank account
			printf("This bank account doesn't exist !\n");
			break;} // this break will return the user to the main function
			
					
		else {
		
			
		u32 flag2=1; // Defining a flag to exit while loop
			
			printf("Enter your Bank Account Password: ");
			u32 client_bank_account_Password; // Defining the bank account password variable
			scanf("%d",&client_bank_account_Password);
		
			empty_stdin();   // calling empty function to empty stdin

			if( client_bank_account_ID == search -> bank_account_ID && client_bank_account_Password == search -> bank_account_Password){  // check of the account's data
			flag4=0;

			system("cls"); // Clearing CMD screen

				
				while(flag2){
				{
					printf("\nWelcome to the Client Window !!\n");
					printf("********************************\n");
					printf("\nIn this window you can choose one of the following actions: \n");
					printf("\nMake a transaction by entering 1\n");
					printf("Change the account's password by entering 2\n");
					printf("Get cash by entering 3\n");
					printf("Deposit in account by entering 4\n");
					printf("Return to the main menu by entering 5\n");


				printf("\nChoose an action: ");
				u32 client_action=-1; // defining a variable to choose from the client window actions
				scanf("%d",&client_action);
				
				empty_stdin(); // calling empty function to empty stdin


				switch (client_action){

				case 1:     
				// option one : Make a transaction to another account

					system("cls"); 
					// First, clearing the CMD screen
					
					u32 client_bank_account_ID_2; // defining a variable to search inside the linked list
				
					printf("\nEnter the second account's ID to search: ");
					scanf("%d",&client_bank_account_ID_2);
					// Asking the user to enter the ID of the second account
					
					empty_stdin(); // calling empty function to empty stdin
				
					struct node * search_2 = searchlist(ptr, client_bank_account_ID_2);
					// Calling the search function to search for the second bank account ID
					
					if (search_2 == NULL){
					printf("This bank account doesn't exist !\n");
					break;}
					
					else if (search_2 == search)
						{printf("\nYou can't make a transaction in the same account !!\n"); // checking tat the second account is not the current one
						break;}
						
					else { Make_Transaction_Function(search , search_2); }
					// Calling make_transaction _function to transfer money between the 2 bank accounts
					
					break;

				case 2:     
				// option two: Change the account's password

					system("cls"); 
					// clearing CMD screen
				
					Change_Account_Password_Function(search); 
					// Calling Change_Account_Password_Function to change the password of the bank account

					break;

				case 3:     
				// option three: Get cash

					system("cls"); 
					// Clearing CMD screen
				
					Withdraw_Cash_Function(search); 
					// Calling Withdraw_Cash_Function to withdraw cash from the bank account

					break;

				case 4:     
				// option four: Deposit in account

					system("cls"); 
					// Clearing CMD screen

					Deposit_Cash_Function(search); 
					// Calling Deposit_Cash_Function to deposit cash in the bank account

					break;

				case 5:     
				// option five : Exit the client window and return to the main window

					system("cls"); // Clearing CMD screen

					flag2=0;
					break;

				default:
				printf("Wrong choice ! \n");
				break;

			}
		}

	}
}
			

		else
			{printf("You entered a wrong password\n");}
		
		
		}	
}
}



// Change_Account_Password_Function is used to change the bank account status
	void Change_Account_Password_Function(struct node *current){
		
		if (current -> bank_account_status == 1){ // Checking the current status of the bank account

			u32 new_bank_account_password; // Defining a variable to take the new password from the user

			printf("\nEnter the new password: ");
			scanf("%d",&new_bank_account_password);

			current -> bank_account_Password = new_bank_account_password; // If condition is true the password will be changed

			printf("Your Account Password was changed successfuly!\n");}

		else if (current -> bank_account_status == 2)
			{printf("This action can not be done because your account status is Restricted!\n");} // If condition is false the bank account status Restricted will be displayed

		else
			{printf("This action can not be done because your account status is Closed!\n");}// If condition is false the bank account status Closed will be displayed
		
	
}




