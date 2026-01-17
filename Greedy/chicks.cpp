#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int swaps(vector<int>& pos, vector<int>& vel, int n, int k, int b, int t){
	int res = 0;
	int swtn = 0;
	int poss = 0;
	for(int i=n-1;i>=0;i--){
		int maxDist = vel[i] * t;
		int remDist = b - pos[i];
		if(remDist>maxDist) swtn++;
		else{
			poss++;
			res+=swtn;
		}
		if(poss>=k) break;
	}
	if(poss>=k) return res;
	return -1;
}

int main() {
	// your code goes here
	int test;
	cin>>test;
	int cas = 1;
	while(test--){
		int n,k,b,t;
		cin>>n>>k>>b>>t;
		vector<int> pos;
		vector<int> vel;
		for(int i=0;i<n;i++){
			int num;
			cin>>num;
			pos.push_back(num);
		}
		for(int i=0;i<n;i++){
			int num;
			cin>>num;
			vel.push_back(num);
		}
		int res = swaps(pos, vel, n, k, b, t);
		if(res!=-1){
			cout<<"case #"<<cas<<": "<<res<<endl;
		}
		else{
			cout<<"case #"<<cas<<": IMPOSSIBLE"<<endl;
		}
		cas++;
	}
	return 0;
}