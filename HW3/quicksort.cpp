#include<iostream>
 
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
  int  p = low;
  int pivot = arr[low];
 
  for(int i = low+1 ; i <= high ; i++)
    {
     
      if(arr[i] <= pivot)
        {
	  p++;
	  swap(arr[i], arr[p]);
        }
    }
 
  swap(arr[p], arr[low]);
 
  return p;  

}

 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout << "Sorted array: " << endl;
    printArray(arr, n);
    return 0;
}
