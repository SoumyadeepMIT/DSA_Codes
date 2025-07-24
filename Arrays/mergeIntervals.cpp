#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        vector<int> last = res.back();
        if(last[1]>=intervals[i][0]){
            last[1] = max(last[1],intervals[i][1]);
            res.pop_back();
            res.push_back(last);
        }
        else{
            res.push_back(intervals[i]);
        }
    }
    return res;
}

int main(){
    vector<vector<int>> intervals = {{1,4}, {3,5}, {6,8}, {8,9}, {10,12}};
    vector<vector<int>> res = mergeIntervals(intervals);
    for(int i=0;i<res.size();i++){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    return 0;
}
