#ifndef client_window_2_H
#define client_window_2_H

// Below the prototype of each function used in the Client_Window.c


void Client_Window(void); 


/* Client_Window function to display all the possible actions that client 
	can do in his own account in the linked list.
	
	Actions include the following: 

	1)Make a transaction
	2)Change the account's password
	3)Get cash
	4)Deposit in account
	5)Return to the main menu

	Regarding Action 1+2+3+4  ""searchlist function,Make_Transaction_Function,
	Change_Account_Status_Function,Withdraw_Cash_Function, and Deposit_Cash_Function
	are used to modify some features in a specific bank account ""


	Regarding Action 5 which is -- > Returning to the main menu 
	"" No function is used instead a switch case is ""

*/


//**************************************************************************************

void Change_Account_Password_Function(struct node *current);
	// Change_Account_Password_Function is used to change the bank account's password

//**************************************************************************************



#endif