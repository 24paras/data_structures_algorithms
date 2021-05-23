#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int knapsack(vector<int>w, vector<int>v, int W, int n, vector<vector<int> > dp)
{
    printf("capacity: %d size: %d \n", W, n);
    // base condition
    if(W == 0 || n == 0)
    {
        return 0;
    }

    if(dp[n][W] != -1)
    {
        return dp[n][W];
    }
    
    if(w[n-1] <= W)
    {
        return dp[n][W] = max(v[n-1] + knapsack(w, v, W-w[n-1], n-1, dp), 
                              knapsack(w, v, W, n-1, dp));
    }
    else
    {
        return dp[n][W] = knapsack(w, v, W, n-1, dp);
    }
}

int main(){

    int W, n;
    vector<int>weights, values;
    printf("Enter the capacity of the bag W: ");
    scanf("%d", &W);
    printf("Enter the num of items: ");
    scanf("%d", &n);
    printf("Enter the weights list\n");
    for(int i=0; i<n; i++)
    {
        int w;
        scanf("%d", &w);
        weights.push_back(w);
    }
    printf("Enter the values list\n");
     for(int i=0; i<n; i++)
    {
        int v;
        scanf("%d", &v);
        values.push_back(v);
    }

    /*
    for(auto j : weights)
    {
        printf("weights: %d\n", j);
    }
    */
    vector<int> v1(W+1, -1);
    vector<vector<int> > dp(n+1, v1);
    printf(" Knapsack problem: Max Profit is %d\n", knapsack(weights, values, W, n, dp)); 

    return 0;
}