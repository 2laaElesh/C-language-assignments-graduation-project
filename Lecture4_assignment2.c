// Lec_4 assignment 2


int add(int,int);
int sub(int,int);
int mul(int,int);
float divide(float,float);
int and(int,int);
int or(int,int);
int not(int);
int xor(int,int);
int reminder(int,int);
int increment(int);
int decrement(int);


#include <stdio.h>

void main(void){
	
	int operation_id;
	
	int a;
	int b;
	int result;
		
	
	printf("Enter the Operation Id (from 1 - 11) ");
	scanf("%d",&operation_id);
	
	switch (operation_id){
		
	case 1:
		
		printf("Enter number 1: ");
		scanf("%d",&a);
		
		printf("Enter number 2: ");
		scanf("%d",&b);
		
		result=add(a,b);
		
		printf("Addition= %d",result);
		break;
		
	case 2:
		
		printf("Enter number 1: ");
		scanf("%d",&a);
		
		printf("Enter number 2: ");
		scanf("%d",&b);
		
		result=sub(a,b);
		
		printf("Substraction= %d",result);
		break;
		
	case 3:
		
		printf("Enter number 1: ");
		scanf("%d",&a);
		
		printf("Enter number 2: ");
		scanf("%d",&b);
		
		result=mul(a,b);
		
		printf("Multiplication= %d",result);
		break;
		
	case 4:
		
		printf("Enter number 1: ");
		scanf("%d",&a);
		
		printf("Enter number 2: ");
		scanf("%d",&b);
		
		result=divide(a,b);
		
		printf("Division= %d",result);
		break;
		
	case 5:

		printf("Enter number 1: ");
		scanf("%d",&a);
		
		printf("Enter number 2: ");
		scanf("%d",&b);
		
		result=and(a,b);
		
		printf("Anding= %d",result);
		break;
		
	case 6:
		
		printf("Enter number 1: ");
		scanf("%d",&a);
		
		printf("Enter number 2: ");
		scanf("%d",&b);
		
		result=or(a,b);
		
		printf("Oring= %d",result);
		break;
		
	case 7:
		
		printf("Enter number 1: ");
		scanf("%d",&a);
		
		result=not(a);
		
		printf("Not= %d",result);
		break;
		
	case 8:
		
		printf("Enter number 1: ");
		scanf("%d",&a);
		
		printf("Enter number 2: ");
		scanf("%d",&b);
		
		result=xor(a,b);
		
		printf("XOR= %d",result);
		break;
		
	case 9:
		
		printf("Enter number 1: ");
		scanf("%d",&a);
		
		printf("Enter number 2: ");
		scanf("%d",&b);
		
		result=reminder(a,b);
		
		printf("Reminder= %d",result);
		break;
		
	case 10:

		printf("Enter number 1: ");
		scanf("%d",&a);
		
		result=increment(a);
		
		printf("Increment= %d",result);
		break;
		
	case 11:
		
		printf("Enter number 1: ");
		scanf("%d",&a);
		
		result=decrement(a);
		
		printf("Decrement= %d",result);
		break;
		
	}
	
		
}


int add(int a,int b){

return(a+b);	
}
int sub(int a,int b){

return(a-b);	
}
int mul(int a,int b){

return (a*b);
}
float divide(float a,float b){
	return(a/b);
}
int and(int a,int b){
	return (a&b);
}
int or(int a,int b){
	return (a|b);
}
int not(int a){
	return (~a);
}
int xor(int a,int b){
	return (a^b);
}
int reminder(int a,int b){
	return (a%b);
}
int increment(int a){
	return (++a);
}
int decrement(int a){
	
	return (--a);
}
