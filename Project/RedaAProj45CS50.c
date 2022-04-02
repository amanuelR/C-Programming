//AMANUEL REDA
//PROJECT 4 & 5
//JULY, 22, 2019
//JULY, 18, 2019
//Aron Wlyess
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define MIN_VALUE 10
#define MAX_VALUE 99
#define FALSE 0
#define TRUE 1

void ARPoupulateArray(int [], int);
void ARPrintArray(int [], int);
void ARFindSumAvg(int [], int);
void ARFind_Max_Min(int [], int, int, int);
int ARSeqSearch(int [], int, int);
void ARCopyArray(int [], int [], int);
void ARBubbleSort(int [], int);
void ARmedian(int [], int);
void ARSelSort(int [], int);
void ARBinarySearch(int [], int, int, int);

int main()
{
    int arrayOne[ARRAY_SIZE];
    int arrayTwo[ARRAY_SIZE];

    printf("AMANUEL REDA - PROJECT 4 & 5.\n");

    //Populate array two with random numbers between 10 to 99
    ARPoupulateArray(arrayOne, ARRAY_SIZE);
    //Print elements of arrayOne
    printf("Array 1 Elements:\n");
    ARPrintArray(arrayOne, ARRAY_SIZE);

    //Print sum and average of arrayOne elements
    ARFindSumAvg(arrayOne, ARRAY_SIZE);
    //Find Max and min values, max and min index
    ARFind_Max_Min(arrayOne, ARRAY_SIZE, 0, 0);
    //Get random number as a search element
    int searchItem = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    //search searchItem in arrayOne by using sequential search
    printf("\nSequential search on Array 1 ==> ");
    int searchIndex = ARSeqSearch(arrayOne, ARRAY_SIZE, searchItem);
    if(searchIndex >= 0)
        printf("searched item %d is found at index %d.\n\n", searchItem, searchIndex);
    else
        printf("searched item %d is not found. \n\n", searchItem);
    //print arrayTwo and print the elements
    printf("Array 2 Elements:\n");
    ARCopyArray(arrayOne, arrayTwo, ARRAY_SIZE);
    //Sort arrayOne using Bubble sort
    printf("Array 1 Bubble sort:\n");
    ARBubbleSort(arrayOne, ARRAY_SIZE);
    //Find arrayOne median
    ARmedian(arrayOne, ARRAY_SIZE);
    //Sort arrayTwo using selection sort
    printf("Array 2 Selection sort:\n");
    ARSelSort(arrayTwo, ARRAY_SIZE);
    //search arrayTwo using binary search
    printf("Binary Search on Array 2 ==> ");
    ARBinarySearch(arrayTwo, 0 , ARRAY_SIZE, searchItem);
    printf("\n\n");

    printf("AMANUEL REDA - End of PROJECT 4 & 5.\n");
    return 0;
}
//*********************************************************************
void ARPoupulateArray(int sampleArray[], int size)
{
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    sampleArray[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    printf("\n\n");
}
//**********************************************************************
void ARPrintArray(int sampleArray[], int size)
{
    for(int k = 0; k < size; k++)
        printf("%d ",sampleArray[k]);
    printf("\n\n");
}
//**********************************************************************
void ARFindSumAvg(int sampleArray[], int size)
{
    float sum = 0;
    float Average = 0;
    for(int i = 0; i < size; i++)
    {
        //sum
        sum+= (float) sampleArray[i];
    }
    //Average
    Average = sum / size;

    printf("Sum : %.0f\n", sum);
    printf("Average : %.2f\n", Average);
}
//***************************************************************************
void ARFind_Max_Min(int sampleArray[], int size, int minIndex, int maxIndex)
{
    int min = sampleArray[0];
    int max = sampleArray[0];

    for(int k = 1; k < size; k++)
    {
        if(sampleArray[k] < min)
        {
            min = sampleArray[k];
            minIndex = k;
        }

        if(sampleArray[k] > max)
        {
           max = sampleArray[k];
           maxIndex = k;
        }

    }
    printf("\nMinimum Number: %d at Position %d\n", min, minIndex);
    printf("Maximum Number: %d at Position %d\n", max, maxIndex);
}
//****************************************************************************
int ARSeqSearch(int sampleArray[], int size, int searchItem)
{
    int searchIndex = -1;

    for(int i = 0; i < size && searchIndex == -1; i++)
        if(searchItem == sampleArray[i]) //does the searched item exists in the array?
           searchIndex = i;

    return searchIndex;
}
//****************************************************************************
void ARCopyArray(int sampleArray[], int array2[], int size)
{
    for (int i = 0; i < size ; i++)
        array2[i] = sampleArray[i];
    ARPrintArray(array2, ARRAY_SIZE);
}
//*****************************************************************************
void ARBubbleSort(int sampleArray[], int size)
{
    int sorted = FALSE;
    while(!sorted)
    {
        sorted = TRUE;
        for( int i = 0; i < size - 1; i++)
            if(sampleArray[i] > sampleArray[i + 1])
            {
                //Swap
                int temp = sampleArray[i];
                sampleArray[i] = sampleArray[i + 1];
                sampleArray[i + 1] = temp;
                sorted = FALSE;
            }
        for(int i = 0; i < size; i++)
            printf("%d ", sampleArray[i]);
        printf("\n");
    }
    printf("\n");
}
//*****************************************************************************
void ARmedian(int sampleArray [], int size)
{
    int med;

    if(size%2)//is size odd?
        med = sampleArray[size/2];
    else
        med = (sampleArray[size/2] + sampleArray[size/2 - 1])/2;

    printf("The median is %d.\n\n", med);
}
//*****************************************************************************
void ARSelSort(int sampleArray[], int size)
{
    int temp;
    int index;

    for (int row = size - 1; row > 0; row--)
    {
        index = 0;
        for (int col = 0; col <= row; col++)
            if (sampleArray[index] < sampleArray[col])
                index = col;
        //swap
        temp = sampleArray[row];
        sampleArray[row] = sampleArray[index];
        sampleArray[index] = temp;


        for(int col = 0; col < size; col++)
            printf("%d ", sampleArray[col]);   //print the sorted array elements
        printf("\n");
    }
    printf("\n");
}
//******************************************************************************
void ARBinarySearch(int sampleArray[], int first, int last, int searchItem)
{
    int mid;

    if(first <= last)
    {
        mid = (first + last)/2; //find the middle index of the array
        if(sampleArray [mid] == searchItem)
            printf("searched item %d is found at index %d.\n", searchItem, mid);
        else if(searchItem < sampleArray [mid])
            ARBinarySearch(sampleArray, first, mid-1, searchItem); //do the same thing recursively
        else
            ARBinarySearch(sampleArray, mid + 1, last, searchItem); //do the same thing recursively
    }
    else
        printf("searched item %d is not found. \n", searchItem);
}
