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
        // To check if subset exists or not
        /*
        return dp[n][sbsum] = subsetSum(arr, n-1, sbsum-arr[n-1], dp) || subsetSum(arr, n-1, sbsum, dp);
        */
       // To count the num of subsets with sum = reqd subset sum
       return dp[n][sbsum] = subsetSum(arr, n-1, sbsum-arr[n-1], dp) + subsetSum(arr, n-1, sbsum, dp);
    }
    else {
        return dp[n][sbsum] = subsetSum(arr, n-1, sbsum, dp);
    }
}

int main()
{
    int n, e, sbsum;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    vector<int>arr;
    for(int i=0; i<n; i++) { scanf("%d", &e); arr.push_back(e); }
    printf("Enter subset sum: ");
    scanf("%d", &sbsum);
    vector<vector<int> >dp(n+1, vector<int>(sbsum+1, -1));

    /*
    if(subsetSum(arr, n, sbsum, dp) == 1)
        printf("Subset sum %d exists\n", sbsum);
    
    else
        printf("Subset sum does not exist\n");
    */

    printf("The no. of subsets with sbsum = %d are: %d", sbsum, subsetSum(arr, n, sbsum, dp));

    return 0;
}