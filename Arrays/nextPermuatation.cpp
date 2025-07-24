#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n-1;
    while(i>0 && nums[i]<=nums[i-1])i--;
    if(i>0){
        int j = n-1;
        while(j>i){
            if(nums[j]>nums[i-1]){
                break;
            }
            j--;
        }
        swap(nums[i-1],nums[j]);
    }
    reverse(nums.begin() + i, nums.end());
}
int main(){
    vector<int> nums = {1,5,4,3,2};
    nextPermutation(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}