#include <climits>

#include "Patient.h"

// Function to find the index of the Patient with the minimum years of Stay
int findMinStay(Patient arr[], int n)
{
    int minIndex = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i].LessThan(arr[minIndex]))
        {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to find the index of the Patient with the maximum years of Stay
int findMaxStay(Patient arr[], int n)
{
    int maxIndex = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i].GreaterThan(arr[maxIndex]))
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to find the index of the Patient with the second minimum years of Stay
int findSecondMinStay(Patient arr[], int n)
{
    int minIndex = findMinStay(arr, n);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;

    for (int i = 0; i < n; ++i)
    {
        if (i != minIndex)
        {
            if (arr[i].LessThan(arr[secondMinIndex]))
            {
                secondMinIndex = i;
            }
        }
    }
    return secondMinIndex;
}

// Function to find the index of the Patient with the second maximum years of Stay
int findSecondMaxStay(Patient arr[], int n)
{
    int maxIndex = findMaxStay(arr, n);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

    for (int i = 0; i < n; ++i)
    {
        if (i != maxIndex)
        {
            if (arr[i].GreaterThan(arr[secondMaxIndex]))
            {
                secondMaxIndex = i;
            }
        }
    }
    return secondMaxIndex;
}