#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int subsetSum(vector<int> arr, int n, int sbsum, vector<vector<int> >&dp){

    if(sbsum == 0)
        return 1;
    if(n == 0)
        return 0;
    
    if(dp[n][sbsum] != -1){
        return dp[n][sbsum];
    }

    if(arr[n-1] <= sbsum) {

        return dp[n][sbsum] = subsetSum(arr, n-1, sbsum-arr[n-1], dp) || subsetSum(arr, n-1, sbsum, dp);
    }
    else {
        return dp[n][sbsum] = subsetSum(arr, n-1, sbsum, dp);
    }
}

int main()
{
    int n, e, arrsum = 0;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    vector<int>arr;
    for(int i=0; i<n; i++) { scanf("%d", &e); arr.push_back(e); }
    for(auto i : arr) {arrsum += i;}
    if(arrsum%2 != 0)
        printf("Cannot partition this array with equal sum\n");
    else {
        vector<vector<int> >dp(n+1, vector<int>(arrsum/2+1, -1));
        if(subsetSum(arr, n, arrsum/2, dp) == 1)
            printf("We can partition this array with equal sums\n");
        else
            printf("Cannot partition this array with equal sum\n");
    }
    
    return 0;
}