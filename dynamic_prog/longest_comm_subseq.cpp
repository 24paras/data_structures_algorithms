#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int lcs(string s1, string s2, int n, int m, vector<vector<int> >&dp){
    
    if(n == 0 || m == 0){
        return 0;
    }

    if(dp[n][m] != -1)
        return dp[n][m];

    if(s1[n-1] == s2[m-1]){
        return dp[n][m] = (1+lcs(s1, s2, n-1, m-1, dp));
    }
    else {
        return dp[n][m] = max(lcs(s1, s2, n, m-1, dp), lcs(s1, s2, n-1, m, dp));
    }
}

int main(){


    string s1, s2;
    printf("Enter string s1: ");
    getline(cin, s1);
    printf("Enter string s2: ");
    getline(cin, s2);
    vector<vector<int> >dp(s1.size()+1, vector<int>(s2.size()+1, -1));
    printf("length of the lcs is %d\n", lcs(s1, s2, s1.size(), s2.size(), dp));
    /* debug
    for(int i=0; i<s1.size()+1; i++){
        for(int j=0; j<s2.size()+1; j++){
            printf(" i %d j %d dp %d\n", i, j, dp[i][j]);
        }
    }
    */


}