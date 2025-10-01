#include <bits/stdc++.h> 
using namespace std;
vector<int> calc(vector<int>& arr, int power){
	int sum = 0;
	int c = 0;
	for(int n: arr){
		if(n>power) break;
		sum+=n;
		c++;
	}
	return {c, sum};
}
int main(){
	int n, q;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	cin>>q;
	vector<int> powers;
	for(int i=0;i<q;i++){
		int p;
		cin>>p;
		powers.push_back(p);
	}
	for(int p:powers){
		vector<int> res = calc(arr,p);
		cout<<res[0]<<" "<<res[1]<<"\n";
	}
	return 0;
}
