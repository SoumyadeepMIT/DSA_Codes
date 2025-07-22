#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
	// Write your code here.
	sort(nums.begin(),nums.end());
	return {nums[k-1], nums[n-k]};
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    vector<int> res = kthSmallLarge(nums,n,k);
    for(int i=0;i<2;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}