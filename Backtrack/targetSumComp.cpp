#include <bits/stdc++.h>
using namespace std;
void gen(vector<vector<int>>& res, vector<int>& temp, vector<int>& arr, int target, int ind, int sum){
    if(sum == target){
        res.push_back(temp);
        return;
    }
    if(sum>target) return;
    for(int j = ind;j<arr.size();j++){
        temp.push_back(arr[j]);
        gen(res, temp, arr, target, j, sum+arr[j]);
        temp.pop_back();
    }
    return;
}
vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
    // code here
    vector<int> temp;
    vector<vector<int>> res;
    gen(res, temp, arr, target, 0, 0);
    return res;
}
int main(){
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = targetSumComb(arr, target);
    
    cout << "Combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}