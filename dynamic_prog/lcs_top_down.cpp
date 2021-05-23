#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2, int m, int n, vector<vector<int> >&dp){

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main(){

    string s1, s2;
    printf("Enter string s1: ");
    getline(cin, s1);
    printf("Enter string s2: ");
    getline(cin, s2);
    vector<vector<int> >dp(s1.size()+1, vector<int>(s2.size()+1));
    printf("length of the lcs is %d\n", lcs(s1, s2, s1.size(), s2.size(), dp));
}