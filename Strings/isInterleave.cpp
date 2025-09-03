#include <bits/stdc++.h> 
using namespace std;
bool solve(string a, string b, string c,int na,int nb,int nc,vector<vector<int>>& dp){
	if(na==0 && nb==0 && nc==0) return true;
	if((na+nb)!=nc) return false;
	if(dp[na][nb]!=-1) return dp[na][nb];
	if(na>0 && nb>0 && nc>0 && a[na-1]==b[nb-1] && a[na-1]==c[nc-1]){
		return dp[na][nb] = solve(a,b,c,na-1,nb,nc-1,dp) || solve(a,b,c,na,nb-1,nc-1,dp);
	}
	if(na>0 && nc>0 && a[na-1]==c[nc-1]){
		return dp[na][nb] = solve(a,b,c,na-1,nb,nc-1,dp);
	}
	if(nb>0 && nc>0 && b[nb-1] == c[nc-1]){
		return dp[na][nb] = solve(a,b,c,na,nb-1,nc-1,dp);
	}
	return dp[na][nb] = false;
}
bool isInterleave(string a, string b, string c){
	//Your code goes here
	int na = a.length();
	int nb = b.length();
	int nc = c.length();
	if((na+nb)!=nc) return false;
	vector<vector<int>> dp(na+1,vector<int>(nb+1,-1));
	return solve(a,b,c,na,nb,nc,dp);
}
int main(){
    string A = "aab", B = "abc", C = "aaabbc";
    if(isInterleave(A,B,C)){
        cout<<"C is interleave";
    }
    else cout<<"Not an interleave";
    return 0;

}