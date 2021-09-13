#include <iostream>
using namespace std;

class myArray
{
public:
    int *total_size = new int;
    int *used_size = new int;
    int *arr = new int[*total_size];
    myArray(void);
    void printArray(myArray);
    void insert(myArray);
    void deletion(myArray);
};

//Array creation
myArray::myArray(void)
{
    int t_size, u_size;
    cout << "Enter total size and size you want to use:";
    cin >> t_size >> u_size;

    *total_size = t_size;
    *used_size = u_size;

    cout << "Enter the array space separated" << endl;
    for (int i = 0; i < *used_size; i++)
    {
        cin >> arr[i];
    }
}

//Array print
void myArray::printArray(myArray a)
{
    cout << "Array:";
    for (int i = 0; i < *a.used_size; i++)
    {
        cout << a.arr[i] << " ";
    }
    cout << endl;
}

//Insertion in Array
void myArray::insert(myArray a)
{
    a.printArray(a);
    int x;
    cout << "Enter number to insert:";
    cin >> x;
    if (*a.total_size > *a.used_size)
    {
        a.arr[*(a.used_size)] = x;
        //    *a.used_size=*a.used_size+1;
    }
    else
    {
        int *temp = new int[*(a.total_size)];
        for (int i = 0; i < *a.total_size; i++)
        {
            temp[i] = a.arr[i];
        }
        ++(*(a.total_size));
        a.arr = new int[*(a.total_size)];
        for (int i = 0; i < *a.total_size - 1; i++)
        {
            a.arr[i] = temp[i];
        }
        a.arr[(*(a.total_size))-1] = x;
        delete temp;
    }
    ++(*(a.used_size));
}
//Deletion in array
void myArray::deletion(myArray a)
{
    int index;
    cout << "Enter the index of element you want to delete :";
    cin >> index;
    for (int i = index; i < *a.used_size - 1; i++)
    {
        a.arr[i] = a.arr[i + 1];
    }
    a.arr[*a.used_size - 1] = NULL;
    --(*(a.used_size));
}

int main()
{
    myArray ar;
    ar.printArray(ar);
    ar.insert(ar);
    ar.printArray(ar);
    ar.insert(ar);
    ar.printArray(ar);
    ar.deletion(ar);
    ar.printArray(ar);
    return 0;
}