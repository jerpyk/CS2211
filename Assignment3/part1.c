/*Program Name: part1.c
Program Description: The program receives an array of integers of specified
size from the user and uses various functions to display the array. 
Author: Eunsung Kim, 251275156*/
#include <stdio.h>

// function to print out array elements and positions in order
void arrPos(int arr[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (i == arrayLength - 1)
            printf("[%d] = %d\n", i, arr[i]);
        else
            printf("[%d] = %d, ", i, arr[i]);
    }
}
// function to print out array elemnts and positions in reverse order
void revArrPos(int arr[], int arrayLength)
{
    for (int i = arrayLength - 1; i >= 0; i--)
    {
        if (i == 0)
            printf("[%d] = %d\n", i, arr[i]);
        else
            printf("[%d] = %d, ", i, arr[i]);
    }
}
// function to print out even array elements
void evenElem(int arr[], int arrayLength)
{
    int evenCount = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        // if the number is even, print it out
        if (arr[i] % 2 == 0)
        {
            if (evenCount > 0)
                printf(", [%d] = %d", i, arr[i]);
            else
                printf("[%d] = %d", i, arr[i]);

            evenCount++;
        }
    }
    printf("\n");
}
// function to return the sum of all array values
int arrSum(int arr[], int arrayLength)
{
    int sum = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        sum += arr[i];
    }
    return sum;
}
// function that sorts the given array arr using selection sort,
// and prints them out in an ascending order
void ascendArr(int arr[], int arrayLength)
{
    // make a clone array
    int newArr[arrayLength];
    for (int i = 0; i < arrayLength; i++) {
        newArr[i] = arr[i];
    }
    // begin at first element, iterate through second last element
    for (int i = 0; i < arrayLength - 1; i++)
    {
        // set smallest value index to current index
        int min = i;
        // begin at the beginning of unsorted array, until the last element
        for (int j = i + 1; j < arrayLength; j++)
        {
            // compare to the minimum to find the minimum
            if (newArr[j] < newArr[min])
                min = j;
        }
        // switch the values of ith element and the minimum element
        int temp = newArr[i];
        newArr[i] = newArr[min];
        newArr[min] = temp;
    }
    // print them in ascending order
    for (int i = 0; i < arrayLength; i++)
    {
        if (i == arrayLength - 1)
            printf("[%d] = %d\n", i, newArr[i]);
        else
            printf("[%d] = %d, ", i, newArr[i]);
    }
}
// function that swaps the first and last elements position and prints them out
void swapFirstLast(int arr[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        if (i == 0) 
            printf("[%d] = %d, ", arrayLength - 1, arr[arrayLength - 1]);
        else if (i == arrayLength - 1)
            printf("[%d] = %d\n", 0, arr[0]);
        else
            printf("[%d] = %d, ", i, arr[i]);
    }
}

// main function for output
int main()
{
    int n;
    printf("Please enter the number of integers to process: ");

    do
    {
        scanf(" %d", &n);
        // error handling with wrong input size
        if (n < 5 || n > 12)
        {
            printf("Invalid array size, try again: ");
        }
    } while (n < 5 || n > 12);
    int arr[n];
    
    printf("\tThere is enough room in your array for %d integers (%d bytes)\n", n, sizeof(arr));
    printf("\nPlease enter your integers separated by spaces: ");
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    // get integer input of specfied number of integers
    for (int i = 0; i < arrLength; i++)
    {
        scanf(" %d", &arr[i]);
    }
    // Part 1: print out the indices and values of the array elements in order
    printf("\nPart 1:\n\tYour array is: ");
    arrPos(arr, arrLength);
    // Part 2: print out the indices and values of the array elements in reverse order
    printf("\nPart 2: \n\tYour array in reverese is: ");
    revArrPos(arr, arrLength);
    // Part 3: print out the indices and values of the even values array elements
    printf("\nPart 3: \n\tThe even elements in the array is: ");
    evenElem(arr, arrLength);
    // Part 4: print out the sum of array element values
    printf("\nPart 4: \n\tThe sum of all values in your array is: %d\n", arrSum(arr, arrLength));
    // Part 5: print out the array elements in ascending value order
    printf("\nPart 5: \n\tYour array in sorted order is: ");
    ascendArr(arr, arrLength);
    // Part 6: print put array elements first and last element position swapped
    printf("\nPart 6: \n\tYour array with first and last element switched is: ");
    swapFirstLast(arr, arrLength);
    return 0;
}