#include<stdio.h>

void BubbleSort(int array[] , int length_of_array);
void swap(int *a,int *b);
void printArray(int array[], int length_of_array);


void main()
{
    int array[] = {5,6,1,3,7,8,12};

    int length_of_array = sizeof(array)/sizeof(array[0]);

    BubbleSort(array,length_of_array);

    printArray(array,length_of_array);


}

void BubbleSort(int array[],int length_of_array)
{
    int i,j;

    for(i=0;i<length_of_array;i++)
    {
        for(j=0;j<length_of_array-i-1;j++) //n-i-1 reduces the limit value of j
        {
            if(array[j]>array[j+1])
            {
                swap(&array[j],&array[j+1]);
            }
        }
    }
}

void swap (int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void printArray(int array[],int length_of_array)
{
    int i;

    for(i=0;i < length_of_array ;i++)
    {
        printf("%d->",array[i]);
    }

    printf("CLOSED\n");
}
