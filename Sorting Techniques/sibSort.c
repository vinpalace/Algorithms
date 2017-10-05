#include<stdio.h>

void swap(int *a, int *b);
void printArray(int array[], int size);
int selectionSort(int array[], int size);
void bubbleSort(int array[], int size);
void insertionSort(int array[], int size);
void insertionSortGeeks(int array[], int size);

int main()
{
    int array[6] = {7,4,3,8,9,1};
    int size = sizeof(array) / sizeof(array[0]);

    selectionSort(array, size);
    printf("\n");
    bubbleSort(array, size);
    printf("\n");
    insertionSortGeeks(array, size);

}


int selectionSort(int array[], int size)
{
    int i,j;
    int minimum_element_index;

    for(i = 0; i < size; i++ )
    {
        minimum_element_index = i;

        for(j = i + 1; j < size; j++)
        {
            if(array[j] < array[minimum_element_index])
                minimum_element_index = j;
        }

        swap(&array[minimum_element_index], &array[i]);

    }
    printArray(array, size);

}

void bubbleSort(int array[], int size)
{

    int i, j;

    for(i = 0; i < size - 1; i++) //how many times bubbling must be done
    {
        for(j = 0; j < size - i - j; j++) //the actual bubbling
        {
            if(array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }

    printArray(array, size);
}

void insertionSort(int array[], int size)
{
    int value,hole,i;
    for(i = 1; i < size; i++)
    {
        value = array[i]; //create hole by taking out value
        hole = i; //mark position of hole

        //now shift all elements > the value to be inserted one position to right
        while(hole > 0 && array[hole - 1] > value)
        {
            array[hole] = array[hole] - 1;
            hole = hole - 1;
        }

        array[hole] = value;

    }

    printArray(array, size);
}

void insertionSortGeeks(int array[], int size)
{
    int i, key, j;
    for(i = 0; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        //move all elements of array one posi to right
        while(j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }

            array[j + 1] = key;
    }
    printArray(array, size);
}




void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[] , int size)
{
    int i;
    for(i = 0; i < size ; i++)
        printf("%d->",array[i]);
}
