#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Partition a set into two subsets such that the difference of subset sums is minimum
*/


// now following the bottom up approach
int subsetSum(vector<int> arr, int n, int sbsum, vector<vector<int> >&dp){
    /*
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
    */
   dp[0][0] = 1;
    for(int i=0; i<=n; i++){
       dp[i][0] = 1;
    }
    for(int j=1; j<=sbsum; j++){
       dp[0][j] = 0;
    }
   for(int i=1; i<=n; i++){
       for(int j=1; j<=sbsum; j++){

            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j-arr[i-1]]) || (dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
       }
   }
   return dp[n][sbsum];
}

int main()
{
    int n, e, arrsum = 0;
    int minDiff = INT_MAX;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    vector<int>arr;
    for(int i=0; i<n; i++) { scanf("%d", &e); arr.push_back(e); }
    for(auto i : arr) {arrsum += i;}
    vector<vector<int> >dp(n+1, vector<int>(arrsum+1, -1));
    subsetSum(arr, n, arrsum, dp);
    for(int i=0; i<=arrsum; i++){
        
        if(dp[n][i] == 1){
            minDiff = min(minDiff, abs(arrsum - 2*i));
        }   
    }
    
    printf("Min Subset sum Diff is %d\n", minDiff);
    
    return 0;
}