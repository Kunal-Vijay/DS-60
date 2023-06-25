#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e)
{
    int size=e - s + 1;
    int merged[size];
    int idx1 = s;
    int idx2 = mid + 1;
    int i = 0;
    while (idx1 <= mid && idx2 <= e)
    {
        if (arr[idx1] <= arr[idx2])
        {
            merged[i++] = arr[idx1++];
        }
        else
        {
            merged[i++] = arr[idx2++];
        }
    }
    while (idx1 <= mid)
    {
        merged[i++] = arr[idx1++];
    }
    while (idx2 <= e)
    {
        merged[i++] = arr[idx2++];
    }

    for (int i = 0, j = s; i < size; j++, i++)
    {
        arr[j] = merged[i];
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main()
{
    int arr[] = {6, 3, 9, 5, 2, 8};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}