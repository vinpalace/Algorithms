#include<stdio.h>

void main()
{
    int array[] = {6,8,1,5,9,21,12};


}


void mergeSort(int array[], int mid)
{
    int *leftArray, *rightArray;

    length_of_array = sizeof(array) / sizeof(array[0]);

    mid = length_of_array / 2;

    leftArray = (int*)malloc(sizeof(mid*sizeof(int)));
    rightArray = (int*)malloc(sizeof((length_of_array-mid)*sizeof(int)));


    for(i = 0; i < mid; i++)
    {
        leftArray[i] = array[i];
    }

    for(i = mid; i < length_of_array; i++)
    {
        rightArray[i-mid] = array[i];
    }


    mergeSort(array, mid);
    mergeSort(array, length_of_array-mid);

    merge(leftArray,rightArray);


}

void merge(int array[], int *leftArray, int lLength, int *rightArray, int rLength)
{
    int i = 0, j = 0;
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


void insertionSort()
{

}

void quickSort()
{

}

void selectionSort()
{

}

void bubbleSort()
{

}
