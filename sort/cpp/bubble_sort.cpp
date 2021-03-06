#include <iostream>
#include <algorithm> // for swap
#include "helper.h" // printArray()
#include "sort_functions.h"
using namespace std;

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
    
   bubble_sort(arr, size);
   cout << "Array after sorting is: ";
   printArray(arr, size);	

   return 0;
}
