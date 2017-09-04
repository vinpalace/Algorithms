#include<stdio.h>

void insertionSort(int array[], int length_of_array);
void printArray(int array[],int length_of_array);
void main()
{
    int array[] = {5,7,1,3,41,37,42,9};

    int length_of_array = sizeof(array)/sizeof(array[0]);

    insertionSort(array,length_of_array);
}

void insertionSort(int array[],int length_of_array)
{
int i,hole , value;
for(i=1;i<length_of_array;i++)
{
    value = array[i];
    hole = i;

    while(hole>0 && array[hole-1]>value)
    {
        array[hole] = array[hole - 1];
        hole = hole - 1;
    }

    array[hole] = value;
}

printArray(array,length_of_array);

}


void printArray(int array[],int length_of_array)
{
    int i;

    for (size_t i = 0; i < length_of_array; i++) {
        printf("%d->",array[i]);
    }
}
