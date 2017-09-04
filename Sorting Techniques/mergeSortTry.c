#include<stdio.h>
#include<malloc.h>

void mergeSort(int array[],int length);
void merge(int *leftArray,int *rightArray,int *array);

void main()
{

    int array[] = {5,6,1,8,9,7};
    int length_of_array;

    length_of_array = sizeof(array) / sizeof(array[0]);

    mergeSort(array,length_of_array);

    int i;

    for(i=0;i<length_of_array;i++)
    {
        printf("%d->",array[i]);
    }
}

void mergeSort(int array[],int length)
{

    if(length <  2)
        return;


    int mid;
    int i;

    mid = length/2;

    int *leftArray, *rightArray;

    leftArray = (int*)malloc(mid*sizeof(int));
    rightArray = (int*)malloc((length-mid)*sizeof(int));

    for(i=0;i<mid;i++)
        leftArray[i] = array[i];

    for(i=mid;i<length;i++)
        rightArray[i-mid] = array[i];


    mergeSort(leftArray, mid);
    mergeSort(rightArray, length-mid);

    merge(leftArray,rightArray,array);

}

void merge(int *leftArray,int *rightArray,int *array)
{
    int i,j,k;
    i = j = k = 0;

    int leftSize = sizeof(leftArray)/sizeof(leftArray[0]);
    int rightSize = sizeof(rightArray)/sizeof(rightArray[0]);

    while(i < leftSize && j < rightSize)
    {
        if(leftArray[i]<rightArray[j])
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

    while(i<leftSize)
    {
        array[k] = leftArray[i];
        k = k + 1;
        i = i + 1;

    }

    while(j<rightSize)
    {
        array[k]  = rightArray[j];
        k = k + 1;
        j = j + 1;

    }

}
