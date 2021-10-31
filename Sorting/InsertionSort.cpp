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

void InsertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int arr[]={1,4,2,5,3};
    printArray(arr,5);
    InsertionSort(arr,5);
    printArray(arr,5);
    return 0;
}