#include <iostream>

// Name: IAN ALTOVEROS
// Stucent ID: 004203990


using namespace std;

void swap(int *x, int* y)
{
  int temp = *x;
  *x = *y;
  *y = temp; 

}

void bubbleSort(int arr[], int a)
{
  int i,j;
  bool swapped;

  for(int i =0; i < a-1; i++)
    {
      swapped = false;
      for(int j = 0; j < a-i-1; j++)
	{
	  if(arr[j] > arr[j+1])
	    {
	      swap(&arr[j], &arr[j+1]);
	      swapped = true;
	    }
	}
      if(swapped == false)
	{
	  break;
	}
    }

}

void selectionSort(int arr[], int a)
{
  int i,j, min;

  for(int i = 0; i < a-1; i++)
    {
      min = i;
      for(j = i+1; j < a; j++)
	{
	  if(arr[j] < arr[min])
	    {
	      min = j;
	      
	      swap(&arr[min], &arr[i]);
	    }

	  
	}
    }
}

void insertionSort(int arr[], int a)
{
  int i, k, key;

  for(int i = 1; i < a; i++)
    {
      key = arr[i];
      k = i - 1;

      while(k >= 0 && arr[k] > key)
	{
	  arr[k+1] = arr[k];
	  k = k - 1;
	}
      arr[k+1] = key;
    }
}


int part(int arr[], int low, int high)
{
  int midpoint = arr[high];
  int i = (low - 1);

  for(int j = low; j <= high - 1; j++)
    {
      if(arr[j] <= midpoint)
	{
	  i++;
	  swap(&arr[i], &arr[j]);
	}
    }
  swap(&arr[i+1], &arr[high]);
  return (i+1);
}


void quickSort(int arr[], int low, int high)
{
  if(low < high)
    {
      int pi = part(arr, low, high);

      quickSort(arr,low, pi-1);
      quickSort(arr, pi+1, high);
    }
}


void merge(int arr[], int l, int m, int r)
{
  int i,j,k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for(int i =0; i < n1; i++)
    {
      L[i] = arr[l + i];
    }
  for(int j = 0; j < n2; j++)
    {
      R[j] = arr[m+ 1 + j];
    }



  
  i = 0; 
  j = 0; 
  k = l; 
  while (i < n1 && j < n2) 
    { 
      if (L[i] <= R[j]) 
	{ 
	arr[k] = L[i]; 
	i++; 
	} 
      else
	{ 
	  arr[k] = R[j]; 
	  j++; 
	} 
    k++; 
    } 
  
  
  
  while (i < n1) 
    { 
      arr[k] = L[i]; 
      i++; 
      k++; 
    } 
  
  
  while (j < n2) 
    { 
      arr[k] = R[j]; 
      j++; 
      k++; 
    } 
} 

  


void mergeSort(int arr[], int l, int r) 
{ 
  if (l < r) 
    { 
  
  
      int m = l+(r-l)/2; 
  
  
      mergeSort(arr, l, m); 
      mergeSort(arr, m+1, r); 
  
      merge(arr, l, m, r); 
    } 
} 

void printArray(int A[], int size) 
{ 
  int i; 
  for (i = 0; i < size; i++) 
    {
      cout << A[i] << " , ";
    } 
  cout << endl;
} 

int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, arr_size);

  mergeSort(arr, 0, arr_size-1);
  printArray(arr, arr_size);
}
