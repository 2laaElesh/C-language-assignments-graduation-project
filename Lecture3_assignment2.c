// Lec_3 assignment 2

#include <stdio.h>

void main(void){
	
	// defining data in variables
	int Ahmed_password= 7788;
	char Ahmed_user_name []="Ahmed";
	
	
	int Amr_password= 5566;
	char Amr_user_name []="Amr";
	
	
	int Wael_password= 1122;
	char Wael_user_name []="Wael";
	
	// Defining user_input variables id and password
	int id;
	int ps;

	
	printf("Enter your ID: ");
	scanf("%d",&id);
	
	// switching over the input variable id
	
	switch (id){
		
		// case Ahmed
		case 1234:
		
			for (int i=0;i<3;i++){
			
			printf("\nPlease Enter your password: ");
			scanf("%d",&ps);
		
			if (ps == Ahmed_password) // if password is right print walcome message
			{printf("Welcome Ahmed");
			break;}
		
			else if (i==2 && ps != Ahmed_password) // if statement when the password is wrong for 3 times
			printf("\nIncorrect password for 3 times, No more tries!");
		
			else
			{printf("Try again\n");}} // if the password was wrong in the first and second time
		
			break; 
			
			// case Amr
			case 5678:
	
			for (int i=0;i<3;i++){
			
			printf("\nPlease Enter your password: ");
			scanf("%d",&ps);
		
			if (ps == Amr_password) // if password is right print walcome message
			{printf("Welcome Amr"); 
			break;}
		
			else if (i==2 && ps != Amr_password) // if statement when the password is wrong for 3 times
			printf("\nIncorrect password for 3 times, No more tries!");
		
			else
			{printf("Try again\n");}} // if the password was wrong in the first and second time
			
			break;
			
			// case Wael
	
			case 9870:
		
			for (int i=0;i<3;i++){
			
			printf("\nPlease Enter your password: "); 
			scanf("%d",&ps);
		
			if (ps == Wael_password)
			{printf("Welcome Wael"); // if password is right print walcome message
			break;}
		
			else if (i==2 && ps != Wael_password) // if statement when the password is wrong for 3 times
			printf("\nIncorrect password for 3 times, No more tries!");
		
			else
			{printf("Try again\n");}} // if the password was wrong in the first and second time
			
			break;
		
			default: printf("You are not registered !"); // the default case
			break;
	
}
	
		
}