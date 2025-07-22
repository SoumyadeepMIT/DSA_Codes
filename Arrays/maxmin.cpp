#include <iostream>
using namespace std;
int sumOfMaxMin(int arr[], int n){
	// Write your code here.
	int maxe = INT_MIN;
	int mine = INT_MAX;
	for(int i=0;i<n;i++){
		maxe = max(maxe, arr[i]);
		mine = min(mine, arr[i]);
	}
	return maxe + mine;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<sumOfMaxMin(arr,n)<<endl;
}