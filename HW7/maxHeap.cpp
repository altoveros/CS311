#include "maxHeap.h"
#include <iostream>
#include <string>

using namespace std;

MaxHeap::MaxHeap(int capacity)
{
  arr = new int[capacity]; 
  this->capacity = capacity;
  this->size = 0;    
  
}

void MaxHeap::swap(int *x, int *y)
{
   int temp = *x;
    *x = *y;
    *y = temp;
}

int MaxHeap::getSize()
{
  return size;
}
int MaxHeap::parent(int i)
{
   if(i % 2 == 0)
   {
       return (i / 2) - 1;
   }
   else
   {
       return ( i / 2);
   }
}
int MaxHeap::left(int i)
{
  int left = (2 * i+1);
  
  return left;
}
int MaxHeap::right(int i)
{
  int right = (2 * i+2);
  
  return right;
}
void MaxHeap::siftup(int i)
{
  while(i > 0 && arr[parent(i)] > arr[i])
        {       
        swap(&arr[i], &arr[parent(i)]);       
         i = parent(i);    
      }   

}
void MaxHeap::insert(int k)
{
  arr[size] = k; 
  siftup(size);
  size++;     
  for(int i = 0;i < size;i++)
  {
     cout << arr[i]<< " ";
  }
  cout << endl;
}
int MaxHeap::getMax()
{
  for(int i = 0;i < size;i++)
  {
     cout << arr[i] << " ";
  }
  cout << endl;
  return arr[0];        
}
bool MaxHeap::isLeaf(int i)
{
  if(i < size)
  {
      return false;
  }
    
  else
  {
    return true;
  }
}
void MaxHeap::siftdown(int i)
{
    int leftL = left(i);
    int rightL = right(i);
    
    if(isLeaf(leftL))
    {
       return;
    }
    
    int maxNum = i;
    if(arr[leftL] > arr[i])
    {
      maxNum = leftL;
    }
    
    if(!isLeaf(rightL) && (arr[rightL] > arr[maxNum]))
    {
      maxNum = rightL;
    }
    
    if(maxNum != i)
    {
      int temp = arr[i];
      arr[i] = arr[maxNum];
      arr[maxNum] = temp;
      siftdown(maxNum);
    }
}
int MaxHeap::extractMax()
{
   
  int max = arr[0];
  arr[0] = arr[size - 1];
 
  size--;
  
  siftdown(0);
  return max;
}
void MaxHeap::heapify(int *array, int len)
{
  arr = array;
  capacity = size = len;
  
  int half =  size / 2 -1;
  
  for(int i = half; i >= 0; i--)
    {
        siftdown(i);
    }
}
int MaxHeap::removeAt(int k)
{
  int x = arr[k];
  
  arr[k] = arr[size -1]; 
  size-- ;
  int p = parent(k);
  if(k == 0 || arr[k] < arr[p])
  {
     siftdown(k);
  }
  else
  {
   siftup(k);  
  }
    
  return x;   
}
