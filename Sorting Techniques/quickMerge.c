#include<stdio.h>
#include<stdlib.h>

int partition(int array[], int start, int end);
void swap(int *a, int *b);
void merge(int *array, int *leftArray, int a, int *rightArray, int b);
void mergeSort(int array[], int size);


void quickSort(int array[], int start, int end)
{
    int partitionIndex;

    if(start >= end)
        return;
    partitionIndex = partition(array,start, end);

    quickSort(array, start, partitionIndex - 1);
    quickSort(array, partitionIndex + 1, end);
}

int partition(int array[], int start, int end)
{
    int pivot;
    int i;
    int partitionIndex;
    pivot = array[end];
    partitionIndex = start;

    for(i = start; i < end; i++)
    {
        if(array[i] <= pivot)
        {
            swap(&array[partitionIndex], &array[i]);
            partitionIndex++;
        }
    }

    swap(&array[partitionIndex], &array[end]);

    return partitionIndex;

}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
    int array[] = {5,8,1,3,9,11,6,2};

    int size = sizeof(array)/ sizeof(array[0]);
    //quickSort(array, 0, size);
    mergeSort(array, size);

    int i;

    for(i = 0; i < size; i++)
        printf("%d->",array[i]);
}


void mergeSort(int array[], int size)
{
    if(size < 2)
        return;


    int mid ,i;


    mid = size / 2;

    int *leftArray, *rightArray;

    leftArray = (int*)malloc(mid * sizeof(int));
    rightArray = (int*)malloc((size - mid) * sizeof(int));

    for(i = 0; i < mid; i++)
        leftArray[i] = array[i];

    for(i = mid; i < size; i++)
        rightArray[i - mid] = array[i];


    mergeSort(leftArray, mid);
    mergeSort(rightArray, size - mid);

    merge(array, leftArray, mid, rightArray, size - mid);


}

void merge(int *array, int *leftArray, int leftSize, int *rightArray, int rightSize)
{

    int i, j, k;
    i = j = k = 0;

    while(i < leftSize && j < rightSize)
    {
        if(leftArray[i] < rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
            k++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
            k++;
        }

    }

    while(i < leftSize)
    {
        array[k] = leftArray[i];
        k++;
        i++;
    }

    while(j < rightSize)
    {
        array[k] = rightArray[j];
        k++;
        j++;
    }
}

void selectionSort(int array[], int size)
{
    int i, minimum_element_index;

    for(i = 0; i < size; i++)
    {
        minimum_element_index = i;

        for(j = 0; i < size; i++)
        {
            if(array[j] < array[minimum_element_index])
                minimum_element_index = j;
        }

        swap(&array[minimum_element_index], &array[j]);
    }

    printArray(array, size);
}



void bubbleSort(int array[], int size)
{
    for(i = 0; i < size; i++)
    {
        for(j = i; j < size; j++)
        {
            if(array[j + 1] > array[j])
                swap(&array[j], &array[j + 1]);
        }
    }

    printArray(array[], size);
}

void insertionSort(int array[], int size)
{
    int i, key, j;

    for(i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        //we move lements to right
        while(j >= 0 && array[j] > key)
    {
            array[j + 1] = array[j];
            j = j - 1;
    }

    array[j + 1] = key;
}

}


void printArray(int array[],int length_of_array)
{
    int i;
    for(i=0;i<length_of_array;i++)
    {
        printf("%d->",array[i]);
    }
}
