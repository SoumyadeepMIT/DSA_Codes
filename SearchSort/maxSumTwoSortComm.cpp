#include <bits/stdc++.h> 
using namespace std;
int maximiseSum(vector<int>& arr1, vector<int>& arr2, int n, int m) {
	// Write your code here,
	int i=0;
	int j=0;
	int res = 0;
	int s1 = 0, s2=0;
	while(i<arr1.size() && j<arr2.size()){
		if(arr1[i]<arr2[j]){
			s1+=arr1[i];
			i++;
		}
		else if(arr1[i]>arr2[j]){
			s2+=arr2[j];
			j++;
		}
		else{
			res+=max(s1,s2);
			res+=arr1[i];
			i++;
			j++;
			s1=0;
			s2=0;
		}
	}
	while(i<arr1.size()){
		s1+=arr1[i++];
	}
	while(j<arr2.size()){
		s2+=arr2[j++];
	}
	res += max(s1,s2);
	return res;
}
int main(){
    vector<int> arr1 = {1, 5, 10, 15, 20};
    vector<int> arr2 = {2, 4, 5, 9, 15};
    cout<<maximiseSum(arr1,arr2, arr1.size(), arr2.size());
    return 0;
}