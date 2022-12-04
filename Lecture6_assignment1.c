// Lec_6 assignment 1
#include <stdio.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}


int main()
{

    int array[]={5,8,1,2,9,10,22,63,48,25,56,32};
    int arrySize = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, arrySize);

    printf("Sorted array = ");
    for(int i=0;i< arrySize ;i++){
        printf("%d ",array[i]);
    }
    printf("\n");

	return 0;
}
