#include <bits/stdc++.h>
using namespace std; 
int LRS(string & s) {
  // Write your code here.
  int n = s.length();
  int res = 0;
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i!=j && s[i-1]==s[j-1]){
        dp[i][j] = dp[i-1][j-1]+1;
      }
      else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
      res = max(res,dp[i][j]);
    }
  }
  return res;
}
int main(){
    string s = "abaacbc";
    cout<<LRS(s);
    return 0;
}