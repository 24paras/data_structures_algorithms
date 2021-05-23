#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int profitCutting(int L, vector<int> price, vector<vector<int> > &dp){

    
    for(int i=0; i<=L; i++){ dp[i][0] = 0; }
    for(int j=1; j<=L; j++){ dp[0][j] = 0; }

    for(int i=1; i<=L; i++){
        for(int j=1; j<=L; j++){
            if(i <= j){
                dp[i][j] = max(price[i-1]+dp[i][j-i], dp[i-1][j]);
                //printf("dp[%d][%d] is %d price[i-1] %d\n", i, j, dp[i][j], price[i-1]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[L][L];
}

int main(){

    int L, p;
    printf("Enter length of rod: ");
    scanf("%d", &L);
    vector<int> price;
    printf("Enter prices of cutting rod at each length: ");
    for(int i=0; i<L; i++){ scanf("%d", &p); price.push_back(p);}

    /* debug
    for(int j : price){
        printf("price: %d\n", j);
    }
    */

    vector<vector<int> > dp(L+1, vector<int>(L+1));
    printf("Max Profit to cut the rod is %d\n", profitCutting(L, price, dp));

    return 0;
}