#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArray(int*arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={1,4,2,5,3};
    printArray(arr,5);
    SelectionSort(arr,5);
    printArray(arr,5);
    return 0;
}