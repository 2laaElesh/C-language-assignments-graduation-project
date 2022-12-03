// Lec_5 assignment 2
#include <stdio.h>


int main()
{

    int class1[10]={75,66,88,67,78,61,50,53,59,48};
    int class2[10]={42,36,77,74,82,91,58,64,43,93};
    int class3[10]={74,58,95,89,82,67,68,92,91,70};
    int max=0,min=100,sum=0,passed=0,failed=0;

    for(int i=0; i < 10 ;i++){
        if(class1[i]>max)
            max=class1[i];
        if(class2[i]>max)
            max=class2[i];
        if(class3[i]>max)
            max=class3[i];

        if(class1[i]<min)
            min=class1[i];
        if(class2[i]<min)
            min=class2[i];
        if(class3[i]<min)
            min=class3[i];

        if(class1[i]>=50)
            passed++;
        else failed++;
        if(class2[i]>=50)
            passed++;
        else failed++;
        if(class3[i]>=50)
            passed++;
        else failed++;

        sum+= class1[i]+class2[i]+class3[i];
    }

    printf("Number of passed students = %d \n",passed);
    printf("Number of failed students = %d \n",failed);
    printf("Highest grade = %d \n",max);
    printf("Lowest grade = %d \n",min);
    printf("Average grade = %d \n",sum/30);

    return 0;
}
