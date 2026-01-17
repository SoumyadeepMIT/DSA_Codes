#include <bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> &start, vector<int> &finish) {
    // code here
    int n = start.size();
    vector<vector<int>> sched;
    for(int i=0;i<n;i++){
        sched.push_back({start[i], finish[i]});
    }
    sort(sched.begin(), sched.end(), [](vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    });
    int res = 1;
    int le = sched[0][1];
    for(int i=1;i<n;i++){
        if(sched[i][0]>le){ 
            res++;
            le = sched[i][1];
        }
    }
    return res;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(start, finish);
    return 0;
}