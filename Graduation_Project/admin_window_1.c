#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "STD_Types.h"
#include "admin_window_2.h"
#include "client_window_2.h"



// Below the username and password that are used to access the admin window. Please make sure to use them correctly !

u32 admin_usernmae=54321;
u32 admin_password=1234;


// Below the declaration of all the global variables used in the program !

u32 random_bank_account_ID=1000000000;
u16 random_bank_account_Password=10000;


// Below the declaration of the global pointers which will be used with the linked list

struct node * head = NULL;
struct node *ptr;

// -------------------------------------------------------------------------------------------------------------------

// Below the implementation of Admin window function

void Admin_Window(void)
{
	u32 flag3=1; // Defining flag to exit while loop

	while(flag3){

		u32 user_name; // Defining username variable to check the admin's username
		u32 pass_word; // Defining password variable to check the admin's password

		u32 flagg=1; 	// Defining flag to exit while loop
		
		// Entering username and password to be able to choose from the Admin_Window actions
		printf("\nPlease be careful while entering the below information !!\n");

		printf("Enter the user name: ");
		scanf("%d",&user_name);
		empty_stdin(); // calling empty function to empty stdin
		
		printf("Enter Admin Window password: ");
		scanf("%d",&pass_word);
		empty_stdin(); // calling empty function to empty stdin
		
		
		// checking username and the password before opening the admin window
		if(user_name == admin_usernmae && pass_word == admin_password){  

		system("cls"); 
		// clearing the CMD screen 

		flag3=0; // Defining a floag to exit from loop

		while(flagg){ // a loop to stay inside the Admin Actions Window unless the flagg == 0

			printf("\nWelcome to the Admin Window !!\n");
			printf("********************************\n");
			printf("\nIn this window you can choose one of the following actions: \n");
			printf("\nCreate a new account by entering 1\n");
			printf("Open existing account by entering 2\n");
			printf("Exit the window by entering 3\n");

			printf("\nChoose an action: ");
			u16 admin_action=-1; // Defining a variable for admin action
			scanf("%d",&admin_action);
			
			empty_stdin();  // calling empty function to empty stdin


			switch (admin_action){ // Switch statement is used to check the action
						
				case 1:     
				// Admin option one is to Create one or more bank accounts in the runtime using the linked list
					
				system("cls"); // clearing the CMD screen 

				if (head == NULL){
					Add_first_account();}  // calling Add_first_account to create the first bank account
				else {
					Add_next_account();} // calling Add_next_account to create a new bank account
					
					ptr = head;
					printAccounts(ptr); // Calling printAccounts function to print the list of the bank accounts

				break;

				case 2:     
				// Admin option two is to Open an existing account and perform some actions on it

				system("cls");  // First, clearing the CMD screen 

				
				ptr =head; // Defining another copy of the head pointer to use it for searching through the linked list
				u32 search_account_id; // Defining a variable for the bank account id to search for it in the linked list
				printf("\nEnter a Bank Account ID to open: ");
				scanf("%ld",&search_account_id); // Taking the value of it from the user
				
				empty_stdin();   // calling empty function to empty stdin
						
				struct node * search = searchlist(ptr, search_account_id); // calling the search function to check for the ID-value
				
				if (search == NULL){ // if the ID doesn't exist the if statement will be executed and the program will return to the admin window
					printf("This bank account doesn't exist !\n");
					break;}
						
				
				u32 flag=1; // Defining a floag to exit from loop of the existing account actions

				while(flag){

					printf("\nYou can choose one of the following actions: \n");
					printf("\nMake a transaction by entering 1\n");
					printf("Change the account's status by entering 2\n");
					printf("Withdraw cash by entering 3\n");
					printf("Deposit in account by entering 4\n");
					printf("Return to the main menu by entering 5\n");

					printf("\nEnter an action: ");

					u32 exist_account_action=-1; // Defining a variable to let the user make an action on any existing account
					u32 second_account_ID; // Defining a variable to search through the linked list
					scanf("%d",&exist_account_action);
					
					empty_stdin();   // calling empty function to empty stdin

						switch (exist_account_action){ // Switch statement is used to check the exist account action

							case 1:     
							// Make a transaction between the current account and another one

							system("cls"); // First, clearing the CMD screen
							
							printf("\nEnter the second account's ID to search: ");
							scanf("%d",&second_account_ID);
							// Asking the user to enter the ID of the second account
							
							empty_stdin();  // calling empty function to empty stdin
							
							struct node * search_2 = searchlist(ptr, second_account_ID); 
							// Calling the search function to search for the second bank account ID
							
							if (search_2 == search) // checking if the the second account is the current account
							{printf("\nYou can't make a transaction in the same account !!\n");
							break;}
							
							else { Make_Transaction_Function(search , search_2); }
							// Calling make_transaction _function to transfer money between the 2 bank accounts

							break;

							case 2:     
							// Changing the account's status of the current bank account

							system("cls"); // clearing the CMD screen 
							
							Change_Account_Status_Function(search); 
							// Calling Change_Account_Status _function to change the status
							
							break;

							case 3:     
							//Withdrawing cash from the bank account

							system("cls");//Clearing CMD screen
							
							Withdraw_Cash_Function(search); 
							// Calling Withdraw_Cash_Function to withdraw cash from the bank account
							
							break;

							case 4:     
							//Deposit cash in the account
							
							system("cls"); // Clearing CMD screen
							
							Deposit_Cash_Function(search); 
							// Calling Deposit_Cash_Function to deposit cash in the bank account
							
							break;

							case 5:     
							// Exiting from the account and returning back to Admin window
							system("cls"); // Clearing CMD screen
							flag=0;
							break;

							default:
							printf("Wrong choice ! \n"); // In case if the user entered a wrong choice
							break;

						}


					}
					
					break;

				case 3:     
				// option three : Exit from Admin window and go back to the main window
				system("cls"); // Clearing CMD screen
				flagg=0;
				break;

				default:
				printf("Wrong choice ! \n");
				break;

				}

			}
		}


			else
			{printf("\nYou entered a wrong username or password\n");}
		}
	}



// The Add_first_account function in the linked list to add the first account

	void Add_first_account(void)
{
	struct node * bank_account=(struct node*)malloc(sizeof(struct node));
	bank_account -> previous = NULL;
	
	printf("\nEnter the accurate information of the first account below !\n");

	printf("Enter name: "); 
	// Taking name of the bank account owner from the user
	scanf(" %[^\n]%*c", bank_account -> bank_account_owner_name);
	fflush(stdin);
	
		while (strlen(bank_account -> bank_account_owner_name) > 40){
		printf("Name Exceeded the limit !!\n");
		printf("Enter name again: ");
		scanf(" %[^\n]%*c", bank_account -> bank_account_owner_name);
		fflush(stdin);}
		
	printf("Enter address: "); 
	// Taking address of the bank account owner from the user
	scanf(" %[^\n]%*c",bank_account -> bank_account_owner_address);
	fflush(stdin);
	
		while(strlen(bank_account -> bank_account_owner_address) >45){
		printf("Adress Exceeded the limit !!\n");
		printf("Enter adress again: ");
		scanf(" %[^\n]%*c", bank_account -> bank_account_owner_address);
		fflush(stdin);}
	
	printf("Enter national ID: "); 
	// Taking National ID of the bank account owner from the user
	scanf(" %[^\n]%*c", bank_account -> bank_account_owner_national_ID);
	fflush(stdin);
	
		while(strlen(bank_account -> bank_account_owner_national_ID) !=14){
		printf("National ID must consist of 14 digits !!\n");
		printf("Enter national ID again: ");
		scanf(" %[^\n]%*c", bank_account -> bank_account_owner_national_ID);
		fflush(stdin);}
	

	u32 age;
	printf("Age: ");
	// Taking age of the bank account owner from the user
	scanf(" %d",&age);
	
	empty_stdin(); // calling empty function to empty stdin

		while (age <= 0 || age > 100){
		// Checking if the user age is valid or not
	  
			printf("\nAge is not Valid !\n");
			printf("Age: ");
			scanf("%d",&age);
			empty_stdin(); 
			// calling empty function to empty stdin
	}
	
	bank_account -> bank_account_owner_age = age;
	
		if(age <21){ 
		// taking the guardian_ID from user when the owner is < 21 years old
		printf("Enter your guardian national ID: ");
		scanf(" %[^\n]%*c",bank_account -> bank_account_owner_guardian_ID);
		
		while(strlen(bank_account -> bank_account_owner_guardian_ID) !=14){
		printf("Guardian National ID must consist of 14 digits !!\n");
		printf("Enter national ID again: ");
		scanf(" %[^\n]%*c", bank_account -> bank_account_owner_guardian_ID);
		fflush(stdin);}}
		else{
        strcpy(bank_account -> bank_account_owner_guardian_ID, "0000000000000"); // This wil always represent that the age of the owner is > 21 years old
		}
		
	fflush(stdin);
	
	f64 balance;
	printf("Balance: "); 
	//Taking balance value of the bank account from the user
	
	scanf(" %lf",&balance);
	empty_stdin(); // calling empty function to empty stdin
	
		while (balance < 0){ // Cheking if the value is negative
			printf("Invalid value !!\n");
			printf("\nEnter the amount of money you want to add to the account: ");
			scanf("%lf",&balance);// Taking the value from the user
			empty_stdin(); // calling empty function to empty stdin				
			}
		bank_account -> bank_account_balance = balance;	

	fflush(stdin);

	
	bank_account -> bank_account_status= 1;
	fflush(stdin);
	bank_account -> bank_account_ID= random_bank_account_ID;
	fflush(stdin);
	bank_account -> bank_account_Password= random_bank_account_Password;
	fflush(stdin);

	bank_account -> next=NULL;
	head = bank_account;
	
	

}

// The Add_next_account function in the linked list to add any new account

	void Add_next_account(void)
{
	struct node *new_account,*tp;
	new_account=(struct node*)malloc(sizeof(struct node));

	new_account -> previous = NULL;
	
	printf("\nEnter the accurate information of the bank account below !\n");

	printf("Enter name: "); 
	// Taking name of the bank account owner from the user
	scanf(" %[^\n]%*c", new_account -> bank_account_owner_name);
	fflush(stdin);
	
		while (strlen(new_account -> bank_account_owner_name) > 40){
		printf("Name Exceeded the limit !!\n");
		printf("Enter name again: ");
		scanf(" %[^\n]%*c", new_account -> bank_account_owner_name);
		fflush(stdin);}
	
	printf("Enter address: "); 
	// Taking address of the bank account owner from the user
	scanf(" %[^\n]%*c",new_account -> bank_account_owner_address);
	fflush(stdin);
	
		while(strlen(new_account -> bank_account_owner_address) >45){
		printf("Adress Exceeded the limit !!\n");
		printf("Enter adress again: ");
		scanf(" %[^\n]%*c", new_account -> bank_account_owner_address);
		fflush(stdin);}
		
	
	printf("Enter national ID: "); 
	// Taking National ID of the bank account owner from the user
	scanf(" %[^\n]%*c", new_account -> bank_account_owner_national_ID);
	fflush(stdin);
	
		while(strlen(new_account -> bank_account_owner_national_ID) !=14){
		printf("National ID must consist of 14 digits !!\n");
		printf("Enter national ID again: ");
		scanf(" %[^\n]%*c", new_account -> bank_account_owner_national_ID);
		fflush(stdin);}

	u32 age;
	printf("Age: "); 
	scanf(" %d",&age);
	
	empty_stdin(); // calling empty function to empty stdin

		while (age <= 0 || age > 100){
		// Checking if the user age is valid or not
	  
			printf("\nAge is not Valid !\n");
			printf("Age: ");
			scanf("%d",&age);
			empty_stdin(); 
			// calling empty function to empty stdin
	}
	
	new_account -> bank_account_owner_age = age;
	
	if(age <21){ 
    // taking the guardian_ID from user when the owner is < 21 years old
		printf("Enter your guardian national ID: ");
    	scanf(" %[^\n]%*c",new_account -> bank_account_owner_guardian_ID);}
	else{
        strcpy(new_account -> bank_account_owner_guardian_ID, "0000000000000"); // This ID will always be displayed if age is > 21 years old
		}
		
	f64 balance;
	printf("Balance: "); 
	//Taking balance value of the bank account from the user
	scanf(" %lf",&balance);
	empty_stdin(); // calling empty function to empty stdin
	
	while (balance<0){ // Cheking if the value is negative
				printf("\nInvalid value !!\n");
				printf("Enter the amount of money you want to add to the account: ");
				scanf("%lf",&balance); // Taking the value from the user
				empty_stdin(); // calling empty function to empty stdin		
			}
		new_account -> bank_account_balance = balance;	

	fflush(stdin);

	
	new_account -> bank_account_status= 1;
	new_account -> bank_account_ID= ++random_bank_account_ID;
	new_account -> bank_account_Password= ++random_bank_account_Password;
	

	new_account -> next=NULL;

	tp= head;
	while(tp -> next != NULL){
        tp = tp -> next;
	}

	tp -> next = new_account;
	new_account -> previous=tp;

}


// searchlist function to search for a specific account

	struct node * searchlist(struct node *ptr, u32 search_account_ID){
	struct node *search = ptr;
	while(search!=NULL){
	if(search-> bank_account_ID == search_account_ID){
	printf("This Bank account exists\n");
	return search;}
	else{
	search= search->next;}
	}
	return NULL;
}


// printAccounts function to print the data of each created account

	void printAccounts(struct node *ptr){
    
	printf("\n==== List of created Bank Accounts ====\n");
	
	while(ptr != NULL){
	
	printf("\nBank Account Information:\n");
	printf("\n");
	printf("Name= %s",ptr -> bank_account_owner_name);
	printf("\n");
	printf("Adress= %s",ptr -> bank_account_owner_address);
	printf("\n");
	printf("National ID= %s\n",ptr -> bank_account_owner_national_ID);
	printf("Age= %d\n",ptr -> bank_account_owner_age);
	printf("Balance= %.4lf\n",ptr -> bank_account_balance);

	if (ptr -> bank_account_status == 1)
		{printf("Account Status= Active\n");}
	else if (ptr -> bank_account_status == 2)
		{printf("Account Status= Restricted\n");}
	else
		{printf("Account Status= Closed\n");}

	printf("Guardian National ID= %s\n",ptr -> bank_account_owner_guardian_ID);
	printf("Account ID= %ld\n",ptr -> bank_account_ID);
	printf("Account Password= %d\n",ptr -> bank_account_Password);
	
	printf("\n**************************************\n");

	ptr = ptr -> next;
	}

}


//simple helper-function to empty stdin to solve the problem of infinity loop when entering a string/char in an int variable

	void empty_stdin (void) 
{
    u32 c = getchar();

    while (c != '\n')
        c = getchar();
}


// Make_Transaction_Function is used to make a transaction between 2 bank accounts

	void Make_Transaction_Function(struct node *current, struct node *second){
	
	if (current -> bank_account_status == 1 && second -> bank_account_status ==1){ // Make sure that the accounts status is Active
											
		f64 cash_amount; // Defining a variable for the cash amount that the user want to transfer between the 2 accounts
		printf("\nEnter the amount of cash you want to transfer: ");
		scanf("%lf",&cash_amount); // Taking the value from the user
		empty_stdin(); // calling empty function to empty stdin
		

			if(cash_amount <= current -> bank_account_balance) // Checking if the cash amount is less or equal the current account balance

			{current -> bank_account_balance = current -> bank_account_balance - cash_amount; // if the condition is true the transaction will be done
				second -> bank_account_balance = second -> bank_account_balance + cash_amount;

				printf("Cash transfer was done successfully!\n");
				printf("Your current balance now= %.4lf\n",current -> bank_account_balance);}


			else
			{printf("Your account balance is not enough to complete this transaction!\n");} // if the condition is false the transaction will not be done
	}

	else
	{printf("The transaction can not be done because the status of one or both accounts  is not active\n");} // The accounts status was not Active

}


	// Change_Account_Status_Function is used to change the bank account status
	void Change_Account_Status_Function(struct node *current){
	
	// Printing the current state of the bank account
	if (current -> bank_account_status == 1){ 
		printf("Account Current Status: Active\n");}

	else if(current -> bank_account_status == 2){
		printf("Account Current Status= Restricted\n");}
								
	else{printf("Account Current Status= Closed\n");}
	
	
	printf("\nYou can change the current status by choosing one from the following : \n");
		printf("Make it Active by entering 1 \n");
		printf("Make it Restricted by entering 2 \n");
		printf("Make it Closed by entering 3 \n");
		
		// Asking the user to inter a value to change the bank account's state 
		
		u32 new_status; // Defining a variable to take the value from the user
		scanf("%d",&new_status);
		empty_stdin(); // calling empty function to empty stdin
		
		current -> bank_account_status = new_status;
		
		if (current -> bank_account_status == 1){ // If he enters 1 the account status will be changed to 1 and will be dispalyed as Active 
			printf("Bank Account Status changed successfully\n");
			printf("\nBank Account Status= Active\n");}
			
		else if(current -> bank_account_status == 2){ // If he enters 2 the account status will be changed to 2 and will be dispalyed as Restricted 
			printf("Bank Account Status changed successfully\n");
			printf("Bank Account Current Status= Restricted\n");}
			
		else if(current -> bank_account_status == 3){
			printf("Bank Account Status changed successfully\n");
			printf("Bank Account Current Status= Closed\n");} // If he enters 3 the account status will be changed to 2 and will be dispalyed as Closed
		else 
			{printf("Invalid choice !\n");}
		
		

			
	
}


	// Withdraw_Cash_Function is used to withdraw cash from the bank account
	void Withdraw_Cash_Function(struct node *current){
	
	if (current -> bank_account_status == 1){  // Make sure that the accounts status is Active
									
		f64 cash_amount_1; // Defining a variable of cash amount
		printf("Enter the amount of cash you want to withdraw: ");
		scanf("%lf",&cash_amount_1); // Asking the user to inter a value of the cash amount variable to withdraw form the account
		empty_stdin(); // calling empty function to empty stdin
		

			if(cash_amount_1 <= current -> bank_account_balance){ // Checking if the cash amount is less or equal the current account balance
									
				current -> bank_account_balance = (current -> bank_account_balance) - (cash_amount_1); // if the condition is true the withdraw will be made
				printf("Cash withdraw was done successfully!\n");
				printf("Your current balance now= %.4lf\n",current -> bank_account_balance);}
	
			else
			{printf("Your account balance is not enough to complete this withdraw!\n");} // if the condition is false the transaction will not be done
	}
	
	else if (current -> bank_account_status == 2)
		{printf("This action can not be done because your account status is Restricted!\n");} // If condition is false the bank account status Restricted will be displayed

	else
		{printf("This action can not be done because your account status is Closed!\n");}// If condition is false the bank account status Closed will be displayed
	
	
}


	// Deposit_Cash_Function is used to deposit cash in the bank account
	void Deposit_Cash_Function(struct node *current){
	
	if (current -> bank_account_status== 1){ // Make sure that the accounts status is Active
							
		f64 cash_amount_2; // Defining a variable of cash amount
		printf("Enter the amount of cash you want to deposit: ");
		scanf("%lf",&cash_amount_2); // Asking the user to inter a value of the cash amount to deposit in the account
		empty_stdin(); // calling empty function to empty stdin

		current -> bank_account_balance = current -> bank_account_balance + cash_amount_2; // adding the value of the cash amount to the balance

		printf("Cash deposit was done successfully!\n");
		printf("Your current balance now= %.4lf\n",current -> bank_account_balance);}

	else if (current -> bank_account_status == 2)
		{printf("This action can not be done because your account status is Restricted!\n");} // If condition is false the bank account status Restricted will be displayed

	else
		{printf("This action can not be done because your account status is Closed!\n");}// If condition is false the bank account status Closed will be displayed
	
	
}