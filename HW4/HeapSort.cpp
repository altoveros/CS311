#include <iostream>
using namespace std;

// NAME: Ian Altoveros
// ID: 004203990


void heapify(int arr[], int n, int i) 
{ 
  int largest = i; 
  int l = 2*i + 1; 
  int r = 2*i + 2; 
  
  
  if (l < n && arr[l] > arr[largest]) 
    largest = l; 
  
  
  if (r < n && arr[r] > arr[largest]) 
    largest = r; 
  
  
  if (largest != i) 
    { 
      swap(arr[i], arr[largest]); 
  
   
      heapify(arr, n, largest); 
    } 
} 



void heapSort(int a[], int n)
{

  for(int k = n/2 - 1; k >= 0; k--)
    {
      heapify(a, n, k);
    }


  //for (int i = n - 1; i >= 0; i--)
    //{
      //swap(a[0], a[i]);
     // heapify(a, i, 0);
    //}
}


void printArray(int arr[], int n) 
{ 
  for (int i = 0; i < n; i++) 
    {
      cout << arr[i] << " "; 
    }

  cout << "\n"; 
} 
  


int main() 
{ 
  int arr[] = {22, 1, 33, 25, 46, 37}; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  
  heapSort(arr, n); 
  
  cout << "Sorted array is \n"; 
  printArray(arr, n); 
} 
