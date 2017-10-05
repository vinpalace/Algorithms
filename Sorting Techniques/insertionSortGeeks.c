#include<stdio.h>


void printArray(int array[] , int size);
void insertionSort(int array[], int size);

void main()
{
    int array[] = {9,6,4,1,7,1,12};
    int size = sizeof(array) / sizeof(array[0]);

    insertionSort(array, size);

    printArray(array, size);
}


void insertionSort(int array[], int size)
{
    int i, key, j;

    for(i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;


    }


}

void printArray(int array[], int size)
{
    int i = 0;

    for(i = 0; i < size; i++)
        printf("%d->", array[i]);
}
