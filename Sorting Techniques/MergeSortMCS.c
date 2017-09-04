#include<stdio.h>
#include<malloc.h>

void mergeSort(int *array , int length_of_array);
void merge(int *array,int *leftArray,int leftSize, int *rightArray,int rightSize);

void main()
{
    int array[] = {12,6,13,52,23,32};
    int length_of_array;
    int i;

    length_of_array = sizeof(array)/sizeof(array[0]);

    mergeSort(array,length_of_array);

    for (i = 0; i < length_of_array; i++) {
        printf("%d->",array[i]);
    }
}


void mergeSort(int *array,int length_of_array)
{

    int mid , i, *leftArray , *rightArray;

    if(length_of_array<2)
        return; //base condition so it cannot be divided any further

    mid = length_of_array/2;



    leftArray = (int*)malloc(mid*sizeof(int));
    rightArray = (int*)malloc((length_of_array-mid)*sizeof(int));

    //now feed data into this subarrays
    for(i=0;i<mid;i++)
        leftArray[i] = array[i];

    for(i=mid;i<length_of_array;i++)
        rightArray[i-mid] = array[i];

    mergeSort(leftArray,mid);
    mergeSort(rightArray,length_of_array-mid);

    merge(array,leftArray,mid,rightArray,length_of_array-mid);

    free(leftArray);
    free(rightArray);


}

void merge(int *array , int *leftArray,int leftSize,int *rightArray,int rightSize)
{
    int i = 0, j = 0, k = 0;

    while(i < leftSize && j < rightSize)
    {
        if(leftArray[i] < rightArray[j])
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

    while(i < leftSize)
    {
        array[k] = leftArray[i];
        i = i + 1;
        k = k + 1;

    }

    while(j < rightSize)
    {
        array[k] = rightArray[j];
        j = j + 1;
        k = k + 1;

    }
}
