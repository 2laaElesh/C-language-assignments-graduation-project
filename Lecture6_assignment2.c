// Lec_6 assignment 2

#include <stdio.h>


int main()
{

    int x = 5,y = 10,z = 15;
    int * p = &x, *q = &y, *r = &z;
    printf("x= %d , y= %d , z= %d\n",x,y,z);
    printf("p= %p , q= %p , r= %p\n",p,q,r);
    printf("*p= %d ,*q= %d ,*r= %d \n",*p,*q,*r);
    printf("Swapping pointers :\n");
    r=p;
    p=q;
    q=r;
    printf("x= %d , y= %d , z= %d\n",x,y,z);
    printf("p= %p , q= %p , r= %p\n",p,q,r);
    printf("*p= %d ,*q= %d ,*r= %d \n",*p,*q,*r);

	return 0;
}
