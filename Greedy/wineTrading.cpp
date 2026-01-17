#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long int calc(vector<int>& arr, int n){
	long long int res = 0;
	long long int pref = 0;
	for(int i=0;i<n;i++){
		pref+=arr[i];
		res+=abs(pref);
	}
	return res;
}

int main() {
	// your code goes here
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		vector<int> arr;
		for(int i=0;i<n;i++){
			int wine;
			cin>>wine;
			arr.push_back(wine);
		}
		cout<<calc(arr,n)<<endl;
	}
	return 0;
}