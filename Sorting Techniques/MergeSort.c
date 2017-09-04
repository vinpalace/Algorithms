#include<stdio.h>
#include<malloc.h>

void merge(int leftArray[],int rightArray[],int array[]);
void mergeSort(int array[],int mid);
int length(int array[]);
void printArray(int array[]);

void main()

{

    int array[] = {5,6,1,12,42,30};


    mergeSort(array,length(array));




}


void merge(int leftArray[],int rightArray[],int array[])
{
    int lengthRight = length(rightArray);
    int lengthLeft = length(leftArray);
    int i = 0,j = 0,k = 0;

    while(i<lengthLeft && j<lengthRight)
    {
        if(leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            k = k + 1;
            i = i + 1;
        }
        else
        {
            array[k] = rightArray[j];
            k = k + 1;
            j = j + 1;
        }
    }
    while(i < lengthLeft)
    {
        array[k] = leftArray[i];
        i = i + 1;
        k = k + 1;
    }

    while(j < lengthRight)
    {
        array[k] = rightArray[j];
        j = j + 1;
        k = k + 1;
    }
}

void mergeSort(int array[],int mid)
{
    int lengthArray;
    int i;
    int *leftArray,*rightArray;
    lengthArray = length(array);

    if(lengthArray<2)
        return;

    mid = lengthArray/2;

    leftArray = (int*)malloc(mid*sizeof(int));
    rightArray = (int*)malloc((lengthArray-mid)*sizeof(int));

    for (i = 0; i < mid; i++) {
        leftArray[i] = array[i];
    }
    for (i = 0; i < lengthArray; i++) {
        rightArray[i-mid] = array[i];
    }

    mergeSort(leftArray,mid);
    mergeSort(rightArray,mid);
    merge(leftArray,rightArray,array);

    printArray(array);
    printf("\n");
}

int length(int array[])
{
    int length_of_array = sizeof(array) / sizeof(array[0]);
    return length_of_array;
}


void printArray(int array[])
{
    int n = length(array);

    for (size_t i = 0; i < n; i++) {
        printf("%d->",array[i]);
    }
}
