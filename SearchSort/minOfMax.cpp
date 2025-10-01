#include <bits/stdc++.h> 
using namespace std;
bool check(vector<int>& pos, int n, int c, int k){
	int i=1;
	int room = pos[0];
	c--;
	while(c>0 && i<n){
		if(pos[i]-room>=k){
			c--;
			room = pos[i];
		}
		i++;
	}
	return c<=0;
}
int chessTournament(vector<int> pos , int n ,  int c){
	// Write your code here
	sort(pos.begin(), pos.end());
	int l = 1;
	int r = pos[n-1];
	int res = 0;
	while(l<=r){
		int m = (l+r)/2;
		if(check(pos,n,c,m)){
			l=m+1;
			res = m;
		}
		else r = m-1;
	}
	return res;
}
int main(){
    vector<int> pos = {6,7,9,13,15,11};
    cout<<chessTournament(pos,pos.size(),4);
    return 0;
}