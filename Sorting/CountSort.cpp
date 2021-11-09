#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maximum(int A[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
void countSort(int *A, int size)
{
    int max = maximum(A, size);

    //creating count array
    int *count = NULL;
    count = new int[max + 1]; //1 extra for 0

    //initializing count array with zero
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    //incrementing count array respectively
    for (int i = 0; i < size; i++)
    {
        (count[A[i]])++;
    }
    int i = 0; //counter for count array
    int j = 0; //counter for given array
    while (i <= max)
    {
        while ((count[i])--)
        {
            A[j++] = i;
        }
        i++;
    }
    delete count; //delete counter array
}

int main()
{
    int A[] = {1, 4, 2, 5, 3};
    int n = 5;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n);
    return 0;
}