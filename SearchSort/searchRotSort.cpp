#include <bits/stdc++.h> 
using namespace std;
int search(vector<int>& nums, int target) {
    int r = nums.size()-1;
    int l = 0;
    while(l<=r){
        int m = (l+r)/2;
        if(nums[m]==target) return m;
        else if(nums[m]>=nums[l]){
            if(target>=nums[l] && target<nums[m]) r=m-1;
            else l=m+1;
        }
        else{
            if(target>nums[m] && target<=nums[r]) l=m+1;
            else r = m-1;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout<<search(nums,target);
}