#include <bits/stdc++.h> 
using namespace std;
bool match(string wild, string pattern) {
    // code here
    int n = wild.length();
    int m = pattern.length();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        if(wild[i-1]=='*'){
            dp[i][0] = dp[i-1][0];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(wild[i-1]==pattern[j-1] || wild[i-1]=='?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(wild[i-1]=='*'){
                dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
int main(){
    string wild = "ge?ks*";
    string pattern = "geeksforgeeks";
    if(match(wild,pattern)) cout<<"Yes";
    else cout<<"No";
    return 0;
}