#include<bits/stdc++.h>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
    int MID = 0;
	if(startIndex>lastIndex)
	    return false;
	else
	{
		MID=(startIndex+lastIndex)/2;
		if(array[MID]==element)
	        return true;
		else if(array[MID]>element)
		    binarySearchReacursive(array, startIndex, MID-1, element);
		else
		    binarySearchReacursive(array, MID+1, lastIndex, element);
    }
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
  int MID=0;
  while(startIndex<=lastIndex)
  {
    MID=(startIndex+lastIndex)/2;
    if(array[MID]==element)
    {  
        return true;
    } 
    else if(array[MID] < element)
    startIndex=MID+1;
    else if(array[MID] > element)
    lastIndex=MID-1;
  }
   if(startIndex>lastIndex)
   return false;
}

int main()
{
  int size=0,X=0;
  bool result_it = false, result_rec = false;
  try
  {
      cout<<"Enter the no. of elements in Array::  ";
      cin>>size;
      if(size<1)
      throw "Invalid Size!!!";
  }
  catch(const char *str)
  {
    cout<<str;
  }
  int *arr = new int[size];
  cout<<"Enter the elements in the Array::  "<<endl;
  for(int i=0; i<size; i++)
  cin>>arr[i];
  sort(arr, arr+size);
  cout<<"Enter the element to be searched: ";
  cin>>X;
  result_it = binarySearchIterative(arr, 0, size-1, X);
  result_rec = binarySearchReacursive(arr, 0, size-1, X);
  if(result_it == true)
    cout<<X<<" is found in the given Array through Iteration....!"<<endl;
  else
    cout<<X<<" is not found in the given Array through Iteration....!"<<endl;
  if(result_rec)
    cout<<X<<" is found in the given Array through Recursion....!"<<endl;
  else
    cout<<X<<" is not found in the given Array through Recursion....!"<<endl;
  delete[] arr;
  return 0;
}
