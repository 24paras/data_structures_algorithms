#include <iostream>
#include "helper_functions.h"
using namespace std;


/*
Property of no.s which are powers of 2: 
All the bits of the no. except the left most bit are 0.
If no. is not 0 or a power of 2, then it has more than 1 bit set
in it's binary representation.

So for a power of 2, x & (x-1) will be 0.
*/
bool isPowerof2(int x)
{
    return !(x & (x-1));
}

/*
The relationship between the bits of x and x-1.
the rightmost 1 and bits right to it are flipped, then by performing x&(x-1), and storing it in x
will reduce x to a number containing number of ones(in its binary form) less than the previous state of x
*/
int numOfones(int x)
{
    int n = 0;
    while(x != 0)
    {
        x = x & (x-1);
        n++;
    }
    return n;
}


void isIthBitSet(int x, int i)
{
    (x & (1<<i)) ? cout << "True\n" : cout << "False\n";
}

void possibleSubsets(char* arr, int n)
{
    for(int i=0; i< 1<<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i & 1<<j)
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}


// find the largest power of 2 greater than or equal to N
int largestPowerof2(int N)
{
    N = N| (N>>1);
    N = N| (N>>2);
    N = N| (N>>4);
    N = N| (N>>8);

    return (N+1)>>1;
}

// to return the rightmost 1th bit in number x
// return x ^ (x & (x-1)) 
/*
    x&(x-1) will have all bits same as x except for 
    the rightmost 1.
    Taking XOR will return the rightmost bit which was 1
*/