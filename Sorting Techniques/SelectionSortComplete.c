#include<stdio.h>


void SelectionSort(int array[],int length_of_array);
void swap(int *a,int *b);
void printArray(int array[],int length_of_array);

void main()
{
    int array[] = {3,7,4,2,1,4,3};

    int length_of_array;
    length_of_array = sizeof(array)/sizeof(array[0]);

    SelectionSort(array,length_of_array);


}

void SelectionSort(int array[],int length_of_array)
{

    int i,j,minimum_number_index;


    for(i=0;i<length_of_array-1;i++)
    {

        minimum_number_index = i;

        for(j=i+1;j<length_of_array;j++)
        {
            if(array[j]<array[minimum_number_index])
                minimum_number_index = j;

        }

        swap(&array[minimum_number_index],&array[i]);
    }
printArray(array,length_of_array);

}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void printArray(int array[],int length_of_array)
{
    int i;
    for(i=0;i<length_of_array;i++)
    {
        printf("%d->",array[i]);
    }
}
