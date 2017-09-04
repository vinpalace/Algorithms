#include<stdio.h>


void quickSort(int array[], int start, int end);
int partition(int array[], int start, int end);
void swap(int x,int y);
void printArray(int array[], int length);

void main()

{

    int array[] = {5,7,1,3,9,10,16};
    int length = sizeof(array)/sizeof(array[0]);


    quickSort(array,0,length);

    int i;

    for(i = 0; i < length-1; i++)
    {
        printf("%d->",array[i]);
    }

}


void quickSort(int array[],int start,int end)
{

    int partitionIndex;

    if(start >= end)
        return;

    partitionIndex = partition(array,start,end);
    quickSort(array, start, partitionIndex - 1);
    quickSort(array, partitionIndex + 1, end);


}

int partition(int array[], int start, int end)
{
    int pivot;
    int i, temp , temp2;
    int partitionIndex;
    pivot = array[end];

    partitionIndex = start;

    for(i = start; i < end; i++)
    {
        if(array[i] <= pivot)
        {
            //swap(array[i],array[partitionIndex]);
            temp = array[i];
            array[i] = array[partitionIndex];
            array[partitionIndex] = temp;

            partitionIndex = partitionIndex + 1;
        }
    }

    //swap(array[partitionIndex],array[end]);

    temp = array[partitionIndex];
    array[partitionIndex] = array[end];
    array[end] = temp;

    return partitionIndex;

}

void swap(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void printArray(int array[],int length)
{
    int i;
    for (i = 0; i < length; i++) {
        printf("%d->",array[i]);
    }
}
