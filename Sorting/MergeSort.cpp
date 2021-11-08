#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int a[n1];
    int b[n2]; // temporary arrays

    for (int i = 0; i < n1; i++)
    {
        a[i] = A[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = A[mid + 1 + i];
    }

    int i=0;
    int j=0;
    int k = low;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            A[k] = a[i];
            k++, i++;
        }
        else
        {
            A[k] = b[j];
            k++, j++;
        }
    }
    while (i < n1)
    {
        A[k] = a[i];
        k++, i++;
    }
    while (j < n2)
    {
        A[k] = b[j];
        k++, j++;
    }
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int A[] = {1, 4, 2, 5, 3};
    int n = 5;
    printArray(A, n);
    mergeSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}