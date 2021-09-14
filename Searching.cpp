#include <iostream>
using namespace std;

bool isSorted(int arr[],int size)
{
    bool sorted = true;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            sorted = false;
            break;
        }
    }
    return sorted;
}


void linearSearch(int arr[],int size)
{
    int x;
    cout << "Enter elemrnt to Liner search: ";
    cin >> x;
    int count = -1;
    cout << "Index of element:";
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            ++count;
            cout << i << " ";
        }
    }
    if (count == -1)
    {
        cout << count;
    }
    cout << endl;
}

void binarySearch(int arr[],int size)
{
    int x;
    cout << "Enter element to binary search: ";
    cin >> x;
    if (isSorted(arr,size))
    {
        cout << "Element index: ";
        int output = -1;
        int high, low, mid;
        low = 0;
        high = size - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] == x)
            {
                output = mid;
                break;
            }
            else if (arr[mid]<x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << output << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }
}


int main()
{
    int size;
    cout << "Enter size of array:";
    cin >> size;

    int arr[size];
    cout << "Enter a array (space separated):" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout<<endl;
    linearSearch(arr,size);
    binarySearch(arr,size);

    return 0;
}