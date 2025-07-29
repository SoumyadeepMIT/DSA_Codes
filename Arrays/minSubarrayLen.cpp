#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) { 
    int n = nums.size();
    int res = INT_MAX;
    int l = 0;
    int r = 0;
    int sum = 0;
    while(r<n){
        sum+=nums[r];
        while(l<=r && sum>=target){
            res = min(res, r-l+1);
            sum-=nums[l];
            l++;
        }
        r++;
    }
    return res!=INT_MAX?res:0;
}

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout<<minSubArrayLen(target, nums);
}