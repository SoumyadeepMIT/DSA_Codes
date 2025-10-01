#include <bits/stdc++.h> 
using namespace std;
int findTheLargestElement(vector<int> &arr, int n) {
	// Write your code here.4
	if(n==1) return arr[0];
	int low = 0;
	int hi = n-1;
	if(arr[low]<arr[hi]) return arr[hi];
	while(low<=hi){
		int mid = low + (hi-low)/2;
		if(mid>0 && arr[mid-1]>arr[mid]) return arr[mid-1];
		if(mid<n-1 && arr[mid]>arr[mid+1]) return arr[mid];
		if(arr[mid]>arr[hi]) low = mid+1;
		else hi = mid-1;
	}
	return -1;
}
int main(){
    vector<int> arr = {4,5,1,2,3};
    cout<<findTheLargestElement(arr,arr.size());
    return 0;
}