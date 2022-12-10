#ifndef admin_window_2_H
#define admin_window_2_H


// Defining the struct node which contains all the bank account information datatypes 

	struct node{

	u8 bank_account_owner_name[40];
	u8 bank_account_owner_address[45];
	u8 bank_account_owner_national_ID[15];
	u16 bank_account_owner_age;
	u8 bank_account_owner_guardian_ID[15];

	u16 bank_account_status;
	f64 bank_account_balance;
	u32 bank_account_ID;
	u16 bank_account_Password;

	struct node *previous;
	struct node *next;

};

// -----------------------------------------------------------------------------------


// Below the prototype of each function used in the Admin_window.c


	void Admin_Window(void); 
	/*Admin_window function to display all the possible actions that 
		admin can do in any account in the linked list.
		
	Actions include the following: 
	1)Creating a new account
	2) Opening existing account
	3)  Exiting the window to go back to the main menu.
	
	Regarding Action 1 which is -- > Creating a new account 
	""Add_first_account, Add_next_account, 
	and printAccounts functions are used to create any 
	number of bank accounts""

	Regarding Action 2 which is -- >  Opening existing account
		Actions include the following: 
		1)Make a transaction 
		2)Change the account's status
		3)Withdraw cash
		4)Deposit in account
		5)Return to the main menu 
		""searchlist function,Make_Transaction_Function,Change_Account_Status_Function,
		Withdraw_Cash_Function, and Deposit_Cash_Functionis are used to modify 
		some features in a specific bank account""

	Regarding Action 3 which is -- > Exiting the window to go back 
	to the main menu "" No function is used instead a switch case is "" */

//**************************************************************************************

	void Add_first_account(void);
	// Add_first_account function to add the first bank account in the linked list 

//**************************************************************************************

	void Add_next_account(void); 
	// Add_next_account function to add any new account to the linked list specifically at the end

//**************************************************************************************

	struct node * searchlist(struct node *ptr, u32 search_account_ID);
	// searchlist function to search for a specific bank account in the linked list

//**************************************************************************************

	void printAccounts(struct node *ptr);
	// printAccounts function to print all the  bank accounts information after creation 

//**************************************************************************************

	void empty_stdin (void);
	/*  simple helper-function to empty stdin to solve the problem of infinity loop when 
	entering a string/char in an int variable*/
	
//**************************************************************************************

	void Make_Transaction_Function(struct node *current,struct node *second);
	// Make_Transaction_Function is used to make a transaction between 2 bank accounts

//**************************************************************************************

	void Change_Account_Status_Function(struct node *current);
	// Change_Account_Status_Function is used to change the bank account status
	
//**************************************************************************************

	void Withdraw_Cash_Function(struct node *current);
	// Withdraw_Cash_Function is used to withdraw cash from the bank account

//**************************************************************************************

	void Deposit_Cash_Function(struct node *current);
	// Deposit_Cash_Function is used to deposit cash in the bank account

// -------------------------------------------------------------------------------------





#endif