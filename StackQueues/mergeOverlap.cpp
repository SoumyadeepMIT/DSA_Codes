#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    // Code here
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0]<b[0];
    });
    vector<vector<int>> res;
    res.push_back(arr[0]);
    int s=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i][0]>res[s][1]){
            res.push_back(arr[i]);
            s++;
        }
        else{
            res[s][1] = max(res[s][1],arr[i][1]);
        }
    }
    return res;
}
int main(){
    vector<vector<int>> arr = {{1,3},{2,4},{6,10},{9,10},{15,18}};
    vector<vector<int>> merged = mergeOverlap(arr);
    cout << "Merged intervals are:\n";
    for(const auto& interval : merged){
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}