#include <bits/stdc++.h>
using namespace std;
vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
    vector<vector<int>> meet;
    for(int i=0;i<N;i++){
        meet.push_back({S[i],F[i], i+1});
    }
    sort(meet.begin(), meet.end(), [](vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    });
    vector<int> res;
    res.push_back(meet[0][2]);
    int le = meet[0][1];
    for(int i=1;i<N;i++){
        if(meet[i][0]>le){
            res.push_back(meet[i][2]);
            le = meet[i][1];
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main() {
    vector<int> start = { 1, 3, 0, 5, 8, 5 };
    vector<int> end = { 2, 4, 6, 7, 9, 9 };

    vector<int> res = maxMeetings(start.size(), start, end);
  	for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}