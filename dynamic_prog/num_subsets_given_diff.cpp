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
                dp[i][j] = (dp[i-1][j-arr[i-1]]) + (dp[i-1][j]);
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
    int n, e, arrsum = 0, diff = 0;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    vector<int>arr;
    for(int i=0; i<n; i++) { scanf("%d", &e); arr.push_back(e); }
    for(int i : arr) {arrsum += i;}
    printf("Enter the Diff for which the no. of subsets to be checked: ");
    scanf("%d", &diff);
    int temp_sum = (diff+arrsum)/2; 
    vector<vector<int> >dp(n+1, vector<int>(temp_sum+1, -1));   
    printf("No. of Subsets with given Diff %d is %d\n", diff, subsetSum(arr, n, temp_sum, dp));
    
    return 0;
}