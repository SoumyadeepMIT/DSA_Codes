#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int calc(vector<int>& x, vector<int>& y, int m, int n){
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int i=m-2;
	int j = n-2;
	int h = 1, v = 1;
	int res = 0;
	while(i>=0 && j>=0){
		if(x[i]>=y[j]){
			res+=(x[i]*h);
			v++;
			i--;
		}
		else{
			res+=(y[j]*v);
			h++;
			j--;
		}
	}
	while(i>=0){
		res+=(x[i]*h);
        i--;
	}
	while(j>=0){
		res+=(y[j]*v);
        j--;
	}
	return res;
}
int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
		int m, n;
		cin>>m>>n;
		vector<int> x,y;
		for(int i=0;i<m-1;i++){
			int cost;
			cin>>cost;
			x.push_back(cost);
		}
		for(int j=0;j<n-1;j++){
			int cost;
			cin>>cost;
			y.push_back(cost);
		}
		cout<<calc(x,y,m,n)<<endl;
	}
	return 0;
}