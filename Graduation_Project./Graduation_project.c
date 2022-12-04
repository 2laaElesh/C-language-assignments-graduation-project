#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "STD_Types.h"

// Below the declaration of all the global variables used in the program !

u32 random_bank_account_ID=1000000000;
u16 random_bank_account_Password=10000;
u32 automatic_bank_account_balance=75000;

// Below the username and password that are used to access the admin window. make sure to use them correctly !

u32 admin_usernmae=54321;
u32 admin_password=1234;


// Defining the struct node which contains all the account information data variables 
struct node{

	u8 bank_account_owner_name[40];
	u8 bank_account_owner_address[45];
	u8 bank_account_owner_national_ID[15];
	u16 bank_account_owner_age;
	u8 bank_account_owner_guardian_ID[15];

	u16 bank_account_status;
	u32 bank_account_balance;
	u32 bank_account_ID;
	u16 bank_account_Password;

	struct node *previous;
	struct node *next;

};

struct node * head = NULL;
struct node *ptr;


// Below the prototype of each used function

struct node * Add_first_account(struct node * ,u8 [40],u8 [45], u8 [15], u16, u8 [15], u32, u16, u32, u16); // Add first account function in the linked list 
struct node * Add_next_account(struct node * ,u8 [40],u8 [45], u8 [15], u16, u8 [15], u32, u16, u32, u16); // Add next account function in the linked list 
struct node * createlist( struct node *); // create list function in the linked list
struct node * searchlist(struct node *ptr, u32 search_account_ID); // search list function for the linked list
void printAccounts(struct node *ptr); // print account function for each account created in the linked list 

void Admin_Window(void); // Admin window function
void Client_Window(void); // Client window function


// Below the main function

int main(void){


printf("\nWelcome To ITI Bank System !!\n");
printf("********************************\n");

printf("\nOur system consists of two windows:\n");
printf("\n");
printf("The first one is \"Admin window\" and you can choose it by entering 1\n");
printf("The second one is \"Client window\" and you can choose it by entering 2\n");

printf("\nIf you just want to exit enter 0.\n");
printf("-------------------------------------------------------------------\n");


while(1){

	printf("\nChoose a window by entering (1) for admin and (2) for client and (0) for exit: ");

	u32 window_choice; // defining window choice variable to take it as an input from the user
	scanf("%d",&window_choice);


	switch (window_choice){
		
		case 1:
		Admin_Window(); // calling Admin Window Function
		break;

		case 2:
		Client_Window(); // calling Client Window Function
		break;

		case 0:
		return 0; // exiting the program

		default:
		printf("Wrong choice !\n"); // printing wrong choice if the input is not in any of the previous cases
		break;}
}
return 0;
}


// Below the implementation of functions dealing with struct

struct node * Add_first_account(struct node * head, u8 name[40],u8 address[45],u8 national_ID[15] ,u16 age,u8 guardian_ID[15],u32 balance,u16 status,u32 accID,u16 accPassword)
{

	struct node * temp=(struct node*)malloc(sizeof(struct node));
	temp -> previous = NULL;

	strcpy(temp->bank_account_owner_name, name);
	strcpy(temp->bank_account_owner_address, address);
   	strcpy(temp->bank_account_owner_national_ID, national_ID);
	temp -> bank_account_owner_age = age;
	strcpy(temp->bank_account_owner_guardian_ID, guardian_ID);
	temp -> bank_account_balance = balance;
	temp -> bank_account_status= status;
	temp -> bank_account_ID= random_bank_account_ID;
	temp -> bank_account_Password= random_bank_account_Password;

	temp -> next=NULL;

	head = temp;
	return head;

}

struct node * Add_next_account(struct node * head ,u8 name[40],u8 address[45],u8 national_ID[15],u16 age,u8 guardian_ID[15],u32 balance,u16 status,u32 accID,u16 accPassword)
{
	struct node *temp,*tp;
	temp=(struct node*)malloc(sizeof(struct node));

	temp -> previous = NULL;

	strcpy(temp->bank_account_owner_name, name);
	strcpy(temp->bank_account_owner_address, address);
    	strcpy(temp->bank_account_owner_national_ID, national_ID);
	temp -> bank_account_owner_age = age;
	strcpy(temp->bank_account_owner_guardian_ID, guardian_ID);
	temp -> bank_account_balance = balance;
	temp -> bank_account_status= status;
	temp -> bank_account_ID= ++random_bank_account_ID;
	temp -> bank_account_Password= ++random_bank_account_Password;

	temp -> next=NULL;

	tp= head;
	while(tp -> next != NULL){
        tp = tp -> next;
	}

	tp -> next = temp;
	temp -> previous=tp;

	return head;
}

struct node * createlist(struct node * head){
	
	u32 n,j;
	u8 name[40];
	u8 address[45];
	u8 national_ID[15];
	u16 age;
	u8 guardian_ID[15];
	u16 status = 1;
	u32 balance=automatic_bank_account_balance;
	u32 accID;
	u16 accPassword;


	printf("\nEnter the number of accounts that you want to add: ");
	scanf("%d",&n);

	if (n==0)
	return head;

	printf("\nEnter the accurate information of the first account below !\n");

	printf("Enter name: ");
	scanf(" %[^\n]%*c",&name);

	printf("Enter national ID: ");
	scanf(" %[^\n]%*c",&national_ID);

	printf("Enter address: ");
	scanf(" %[^\n]%*c",&address);

	printf("Age: ");
	scanf("%d",&age);

    while (age <=0 || age>100){
   	 
	printf("\nAge is not Valid !\n");
	printf("\nAge: ");
	scanf("%d",&age);}

	if(age <21){
    
	printf("Enter your guardian national ID: ");
    	scanf(" %[^\n]%*c",&guardian_ID);}
	else{
        strcpy(guardian_ID, "0000000000000");}


	head = Add_first_account(head, name, address, national_ID , age, guardian_ID , balance , status , accID, accPassword);

	for (j=1;j<n;j++)
	{
	printf("\nEnter the accurate information for the next account below !\n");

	printf("Enter name: ");
	scanf(" %[^\n]%*c",&name);

	printf("Enter national ID: ");
	scanf(" %[^\n]%*c",&national_ID);

	printf("Enter address: ");
	scanf(" %[^\n]%*c",&address);

	printf("Age: ");
	scanf("%d",&age);

	while (age <=0 || age>100){
    	
	printf("\nAge is not Valid !\n");
	printf("\nAge: ");
	scanf("%d",&age);}

	if(age <21){
    	printf("Enter your guardian national ID: ");
    	scanf(" %[^\n]%*c",&guardian_ID);}
	else{
        strcpy(guardian_ID, "0000000000000");}


	head = Add_next_account(head,name,address,national_ID,age,guardian_ID,balance, status, accID,accPassword);

	}

	return head;
}

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

void printAccounts(struct node *ptr){

	while(ptr != NULL){
	
	printf("\nAccounts Informtion: \n");
	printf("Name= %s",ptr -> bank_account_owner_name);
	printf("\n");
	printf("Adress= %s",ptr -> bank_account_owner_address);
	printf("\nNational ID= %ld\n",ptr -> bank_account_owner_national_ID);
	printf("Age= %d\n",ptr -> bank_account_owner_age);
	printf("Balance= %d\n",ptr -> bank_account_balance);

	if (ptr -> bank_account_status == 1)
		{printf("Account Status= Active\n");}
	else if (ptr -> bank_account_status == 2)
		{printf("Account Status= Restricted\n");}
	else
		{printf("Account Status= Closed\n");}

	printf("Guardian National ID= %s\n",ptr -> bank_account_owner_guardian_ID);
	printf("Account ID= %ld\n",ptr -> bank_account_ID);
	printf("Account Password= %d\n",ptr -> bank_account_Password);

	ptr = ptr -> next;
	}

}


// Below the implementation of Admin window function

void Admin_Window(void)
{
	u32 flag3=1; // Defining flag to exit while loop

	while(flag3){

		u32 user_name; // Defining username variable to check the admin's username
		u32 pass_word; // Defining password variable to check the admin's password

		u32 flagg=1;

		printf("Please be careful while entering the below information !!");

		printf("\nEnter the user name: ");
		scanf("%d",&user_name);

		printf("Enter your password: ");
		scanf("%d",&pass_word);


		if(user_name == admin_usernmae && pass_word == admin_password){  // check the username and the password before opening the admin window

		system("cls"); // clearing the CMD screen 

		flag3=0;

		while(flagg){

			printf("\nWelcome to the Admin Window !!\n");
			printf("********************************\n");
			printf("\nIn this window you can choose one of the following actions: \n");
			printf("\nCreate a new account by entering 1\n");
			printf("Open existing account by entering 2\n");
			printf("Exit the window by entering 3\n");

			printf("\nChoose an action: ");
			u16 admin_action; // Defining a variable for admin actions
			scanf("%d",&admin_action);

			switch (admin_action){
						
				case 1:     // option one : Create one or more account in the runtime using the linked list
					
				system("cls"); // clearing the CMD screen 

				head=createlist(head);
				ptr = head;
				printAccounts(ptr);
				break;

				case 2:     // option two : Open existing account and make some actions

				system("cls");

				ptr =head;
				u32 search_account_id;
				printf("\nEnter a Baank Account ID to open: ");
				scanf("%d",&search_account_id);
				struct node * search = searchlist(ptr, search_account_id);

				u32 flag=0;

				while(flag==0){

					printf("\nYou can choose one of the following actions: \n");
					printf("\nMake a transaction by entering 1\n");
					printf("Change the account's status by entering 2\n");
					printf("Withdraw cash by entering 3\n");
					printf("Deposit in account by entering 4\n");
					printf("Return to the main menu by entering 5\n");

					printf("\nEnter an action: ");

					u32 exist_account_action; // Defining a variable to let the user make an action on any existing account
					u32 second_account_ID; // Defining a variable to search through the linked list
					scanf("%d",&exist_account_action);


						switch (exist_account_action){

							case 1:     // Make a transaction between the opened account and another account

							system("cls"); // clearing the CMD screen 

							printf("\nEnter the second account's ID to search: ");
							scanf("%d",&second_account_ID);
							struct node * search_2 = searchlist(ptr, second_account_ID);

							if (search -> bank_account_status == 1 && search_2 -> bank_account_status ==1){
											
								u32 cash_amount;
								printf("Enter the amount of cash you want to transfer: ");
								scanf("%d",&cash_amount);

									if(cash_amount <= search -> bank_account_balance)

									{search -> bank_account_balance = search -> bank_account_balance - cash_amount;
									search_2 -> bank_account_balance = search_2 -> bank_account_balance + cash_amount;

									printf("Cash withdraw was done successfully!\n");
									printf("Your current balance now= %d\n",search -> bank_account_balance);}


									else
									{printf("Your account balance is not enough to complete this withdraw!\n");}
									}

									else
									{printf("The transaction can not be dont because the status of one or both accounts not active\n");}

									break;

							case 2:     // Change the account's status of the opened account

							system("cls"); // clearing the CMD screen 

								if (search -> bank_account_status == 1){
								printf("Account Status: Active\n");}

								else if(search -> bank_account_status == 2){
								printf("Account Current Status= Restricted\n");}
								else{printf("Account Current Status= Closed\n");}

								printf("\nYou can change the current status by choosing one from the following : \n");
								printf("Make it Active by entering 1 \n");
								printf("Make it Restricted by entering 2 \n");
								printf("Make it Closed by entering 3 \n");

								u32 new_status;
								scanf("%d",&new_status);
								search -> bank_account_status = new_status;
								printf("\nBank Account Status changed successfully\n");

								if (search -> bank_account_status == 1){
									printf("\nBank Account Status= Active\n");}
								else if(search -> bank_account_status == 2){
									printf("Bank Account Current Status= Restricted\n");}
								else{printf("Bank Account Current Status= Closed\n");}
								break;

							case 3:     //Withdraw cash from the account

							system("cls"); //Clearing CMD screen

								if (search -> bank_account_status == 1){
									
								u32 cash_amount_1;
								printf("Enter the amount of cash you want to withdraw: ");
								scanf("%d",&cash_amount_1);

								if(cash_amount_1 <= search -> bank_account_balance){
									
								search -> bank_account_balance = search -> bank_account_balance - cash_amount_1;
								printf("Cash withdraw was done successfully!\n");
								printf("Your current balance now= %d\n",search -> bank_account_balance);}

								else
								{printf("Your account balance is not enough to complete this withdraw!\n");}
								}
								else if (search -> bank_account_status == 2)
								{printf("This action can not be done because your account status is Restricted!\n");}

								else
								{printf("This action can not be done because your account status is Closed!\n");}
								break;

							case 4:     //Deposit cash in the account

							system("cls"); // Clearing CMD screen

							if (search -> bank_account_status= 1){
							
							u32 cash_amount_2;
							printf("Enter the amount of cash you want to deposit: ");
							scanf("%d",&cash_amount_2);

						        search -> bank_account_balance = search -> bank_account_balance + cash_amount_2;

							printf("Cash deposit was done successfully!\n");
							printf("Your current balance now= %d\n",search -> bank_account_balance);}

							else if (search -> bank_account_status == 2)
							{printf("This action can not be done because your account status is Restricted!\n");}

							else
							{printf("This action can not be done because your account status is Closed!\n");}
							break;

							case 5:     // Exiting from the account and returning back to Admin window
							flag=1;
							break;

							default:
							printf("Wrong choice ! \n"); // In case if the user entered a wrong choice
							break;

						}


					}

				case 3:     // option three : Exit from Admin window and back to the main window
				flagg=0;
				break;

				default:
				printf("Wrong choice ! \n");
				break;

				}

			}
		}


			else
			{printf("You entered a wrong username or password\n");}
	}
}


// Below the implementation of Client window function

void Client_Window(void){

	u32 flag4=1; // Defining a flag to exit from the while loop

	while(flag4){

		printf("Enter your Bank Account ID: "); 
		u32 client_bank_account_ID; // Defining the bank account ID variable
		scanf("%d",&client_bank_account_ID);
		printf("Enter your Bank Account Password: ");
		u32 client_bank_account_Password; // Defining the bank account password variable
		scanf("%d",&client_bank_account_Password);

			ptr =head;
			struct node * search = searchlist(ptr, client_bank_account_ID); // searching for the account using the ID

			u32 client_bank_account_ID_2; // defining a variable to search inside the linked list
			
			int flag2=1; // Defining a flag to exit while loop

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
				u32 client_action; // defining a variable to choose from the client window actions
				scanf("%d",&client_action);


				switch (client_action){

				case 1:     // option one : Make a transaction to another account

				system("cls"); // Clearing CMD screen

				printf("\nEnter the second account's ID to search: ");
				scanf("%d",&client_bank_account_ID_2);
				
				struct node * search_2 = searchlist(ptr, client_bank_account_ID_2);

				if (search -> bank_account_status == 1 && search_2 -> bank_account_status == 1){

					u32 cash_amount_3;
					printf("Enter the amount of cash you want to transfer: ");
					scanf("%d",&cash_amount_3);

					if(cash_amount_3 <= search -> bank_account_balance){
					search -> bank_account_balance = search -> bank_account_balance - cash_amount_3;
					search_2 -> bank_account_balance = search_2 -> bank_account_balance + cash_amount_3;

					printf("Cash withdraw was done successfully!\n");
					printf("Your current balance now= %d\n",search -> bank_account_balance);}

					else
					{printf("Your account balance is not enough to complete this withdraw!\n");}}

					else
					{printf("The transaction can not be dont because the status of one or both accounts is not active\n");}

					break;

				case 2:     // option two: Change the account's password

				system("cls"); // clearing CMD screen

					if (search -> bank_account_status == 1){

					u32 new_bank_account_password;

					printf("\nEnter the new password: ");
					scanf("%d",&new_bank_account_password);

					search -> bank_account_Password = new_bank_account_password;

					printf("Your Account Password was changed successfuly!\n");}

					else if (search -> bank_account_status == 2)
					{printf("This action can not be done because your account status is Restricted!\n");}

					else
					{printf("This action can not be done because your account status is Closed!\n");}

					break;

				case 3:     // option three: Get cash

				system("cls"); // Clearing CMD screen

				if (search -> bank_account_status == 1){

					u32 cash_amount_4;
					printf("Enter the amount of cash you want to withdraw: ");
					scanf("%d",&cash_amount_4);

						if(cash_amount_4 <= search -> bank_account_balance){

							search -> bank_account_balance = search -> bank_account_balance - cash_amount_4;

							printf("Cash withdraw was done successfully!\n");
							printf("Your current balance now= %d\n",search -> bank_account_balance);}

						else
						{printf("Your account balance is not enough to complete this withdraw!\n");}}

						else if (search -> bank_account_status == 2)
						{printf("This action can not be done because your account status is Restricted!\n");}

						else
						{printf("This action can not be done because your account status is Closed!\n");}

				break;

				case 4:     // option four: Deposit in account

				system("cls"); // Clearing CMD screen

					if (search -> bank_account_status == 1){

						u32 cash_amount_5;
						printf("Enter the amount of cash you want to deposit: ");
						scanf("%d",&cash_amount_5);

						search -> bank_account_balance = search -> bank_account_balance + cash_amount_5;

						printf("Cash deposit was done successfully!\n");
						printf("Your current balance now= %d\n",search -> bank_account_balance);}

					else if (search -> bank_account_status == 2)
					{printf("This action can not be done because your account status is Restricted!\n");}

					else
					{printf("This action can not be done because your account status is Closed!\n");}

					break;

				case 5:     // option five : Exit the client window and return to the main window

				system("cls"); // Clearing CMD screen

					flag2=0;
					printf("The system is exiting from the client window");
					break;

				default:
				printf("Wrong choice ! \n");
				printf("The system is shutting down ! \n");
				break;

			}
		}

	}
}

		else
			{printf("You entered a wrong username or password\n");}
		}
}
