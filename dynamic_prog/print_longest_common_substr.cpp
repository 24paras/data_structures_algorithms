#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2, int m, int n, vector<vector<int> >&dp, int &row, int &col){

    int var = 0;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            //printf("i %d j %d s1[i-1] %c s2[j-1] %c\n", i,j,s1[i-1], s2[j-1]);
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                if(dp[i][j] > var){
                    row = i;
                    col = j;
                }
                var = max(var, dp[i][j]);
                
            }
            else {
                dp[i][j] = 0;
            }
             }
    }

    return var;
}

int main(){

    string s1, s2, res="";
    int row=0, col=0;
    printf("Enter string s1: ");
    getline(cin, s1);
    printf("Enter string s2: ");
    getline(cin, s2);
    vector<vector<int> >dp(s1.size()+1, vector<int>(s2.size()+1));
    printf("length of the lcs is %d\n", lcs(s1, s2, s1.size(), s2.size(), dp, row, col));
    while(row > 0 && col > 0 && dp[row][col] != 0) {
        res += s1[row-1];
        row--;
        col--;
    }
    reverse(res.begin(), res.end());
    printf("The longest common substr is %s\n", res.c_str());
}