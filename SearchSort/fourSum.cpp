#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> fourSum(vector<int> &arr, int target) {
    // code here
    sort(arr.begin(),arr.end());
    vector<vector<int>> res;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum==target){
                    res.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])k++;
                    while(l<n-1 && arr[l]==arr[l+1]) l--;
                }
                else if(sum<target) k++;
                else l--;
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {10, 2, 3, 4, 5, 7, 8};
    int target = 23;
    vector<vector<int>> res = fourSum(arr,target);
    for(vector<int> r: res){
        cout<<r[0]<<" "<<r[1]<<" "<<r[2]<<" "<<r[3]<<endl;
    }
    return 0;
}