#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{   
    for(int j=1; j<size; j++)
    {
        int key = arr[j];
        int i=j-1;
        while(i>=0 && arr[i]>key)
        {
           arr[i+1]=arr[i];
           i=i-1;
        }
        arr[i+1]=key;
    }

return ;
}

void bubble_sort(int arr[], int size)
{
    //bubble sort
    
    for(int i=0; i<size; i++)
    {
        for(int j=size-1; j>i; j--)
    	{
		    if(arr[j] < arr[j-1])
		    {	
			    swap(arr[j], arr[j-1]);
		    }
	    }
    
    }
return ;
}
