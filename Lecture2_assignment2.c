// Lec_2 assignment 2

#include <stdio.h>

void main(void){
	
	int ID=2296;
	char password[]= "87_452-351@45";
	char user_name []="Ahmed Khaled";
	
	int id;
	char ps[14];
	int c;
	
	printf("Enter your ID: ");
	scanf("%d",&id);
	
	if(id == ID)
	{printf("Valid ID\n");
	printf("Enter your password: ");
	scanf("%s",&ps);
		
		for (int i=0;i<14;i++)
		{if (ps[i] == password[i])
		{c = 1;
		break;}
		else 
		{c=0;
		break;}}
		
		if (c==1)
		{printf("Correct Password\n");
		printf("User name: %s",user_name);}
		
		else
		{printf("Incorrect Password\n");}
	}
	else 
	{printf("Incorrect ID !");}
}