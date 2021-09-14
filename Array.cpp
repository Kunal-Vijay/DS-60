#include <iostream>
using namespace std;
class myArray
{
  public:
    int *total_size = new int;
    int *used_size = new int;
    int *arr = new int[*total_size];
    myArray(void);
    void printArray();
    void insert();
    void deletion();
};
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

void myArray::printArray()
{
  cout << "Array:";
  for (int i = 0; i < *used_size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

//Insertion in Array
void myArray::insert()
{
  int x;
  cout << "Enter number to insert:";
  cin >> x;
  if (*total_size > *used_size)
  {
    arr[*(used_size)] = x;
    *used_size=*used_size+1;
  cout <<"\n used size :" ;
  }
  else
  {
    int *temp = new int[*(total_size)];
    for (int i = 0; i < *total_size; i++)
    {
      temp[i] = arr[i];
    }
    ++(*(total_size));
    arr = new int[*(total_size)];
    for (int i = 0; i < *total_size - 1; i++)
    {
      arr[i] = temp[i];
    }
    arr[(*(total_size))-1] = x;
    delete temp;
  }
  ++(*(used_size));
}
//Deletion in array
void myArray::deletion()
{
  int index;
  cout << "Enter the index of element you want to delete :";
  cin >> index;
  for (int i = index; i < *used_size - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  arr[*used_size - 1] = NULL;
  --(*(used_size));
}

int main()
{
  myArray ar;
  ar.printArray();
  ar.insert();
  ar.printArray();
  ar.insert();
  ar.printArray();
  ar.deletion();
  ar.printArray();
  return 0;
}