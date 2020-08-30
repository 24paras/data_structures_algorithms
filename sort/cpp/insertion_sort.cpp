#include <iostream>
#include "helper.h"
#include "sort_functions.h"
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false); // for faster input and output using cin and cout
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    cout << "\nEnter array elements: ";
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }
    
    insertion_sort(arr, size);
    cout << "Array after sorting is: ";
    printArray(arr, size);

return 0;
}
