#include<stdio.h>
#define MAX 6

void SelectionSort(int array[]);
void swap(int *a,int *b);
void printArray(int array[]);

void main()
{
    int array[] = {8,3,7,5,4,2};
    SelectionSort(array);


}

void SelectionSort(int array[])
{
    //Finding the minimum element

    int i,j,minimum_number_index;

    for(i=0;i<MAX-1;i++)
    {

        minimum_number_index = i;

        for(j=i+1;j<MAX;j++)
        {
            if(array[j]<array[minimum_number_index])
            {

                minimum_number_index = j;
            }

        }

        swap(&array[minimum_number_index] , &array[i]);
    }
printArray(array);
}


void swap(int *a,int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

}

void printArray(int array[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("%d->",array[i]);
    }
}
