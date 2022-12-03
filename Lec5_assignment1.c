// Lec_5 assignment 1

#include <stdio.h>

int main()
{

    int arr[10];

    for(int i=0; i < 10 ;i++){
        printf(" Enter the value of Array[%d] = ",i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe array cosists of:");

    for(int i=0; i < 10 ;i++){
        printf(" %d", arr[i]);

    }
    printf("\n");
    return 0;
}
