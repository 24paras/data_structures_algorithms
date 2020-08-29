#include <iostream>
#include <algorithm> // for swap
using namespace std;

void printArray(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return ;
}

int main()
{   
    std::ios::sync_with_stdio(false); // for faster input and output using cin and cout
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;
    int arr[size];
    cout << "Enter your array elements\n";
    for(int i=0; i<size; i++)
    {   
        cin >> arr[i];
    }

    //bubble sort
    
    for(int i=0; i<size; i++)
    {
        for(int j=size-1; j>0; j-- )
    	{
		    if(arr[j] < arr[j-1])
		    {	
			    swap(arr[j], arr[j-1]);
		    }
	    }
    
    }

   cout << "Array after sorting is: ";
   printArray(arr, size);	

   return 0;
}
