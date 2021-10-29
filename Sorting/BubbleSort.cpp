#include <bits/stdc++.h>
using namespace std;

void printArray(int*arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[]={1,4,2,5,3};
    printArray(arr,5);
    bubbleSort(arr,5);
    printArray(arr,5);
    return 0;
}