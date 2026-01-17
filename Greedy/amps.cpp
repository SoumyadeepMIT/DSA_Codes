#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> pos(vector<int>& amps, int n, int ones ){
	sort(amps.begin(), amps.end(), greater<int>());
	vector<int> res;
	for(int i=0;i<ones;i++) res.push_back(1);
	if((n-ones)==2 && amps[0]==3 && amps[1]==2){
		res.push_back(2);
		res.push_back(3);
		return res;
	}
	for(int i=0;i<(n-ones);i++){
		res.push_back(amps[i]);
	}
	return res;
}

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> amps;
		int ones = 0;
		for(int i=0;i<n;i++){
			int num;
			cin>>num;
			if(num==1) ones++;
			amps.push_back(num);
		}
		vector<int> res = pos(amps, n, ones);
		for(int i=0;i<n;i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}