#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> trains){
    int n = trains.size();
    sort(trains.begin(), trains.end(), [](vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    });
    int res = 1;
    int le = trains[0][1];
    for(int i=1;i<n;i++){
        if(trains[i][0]>=le){
            res++;
            le = trains[i][1];
        }
    }
    return res;
}
int maxStop(int train, int plat, vector<vector<int>> &trains) {
    // code here
    unordered_map<int,vector<vector<int>>> um;
    for(int i=0;i<train;i++){
        um[trains[i][2]].push_back({trains[i][0], trains[i][1]});
    }
    int res = 0;
    for(int i=1;i<=plat;i++){
        if(um.find(i)!=um.end())
            res+=solve(um[i]);
    }
    return res;
}
int main()
{
    vector<vector<int>> arr = { {1000, 1030, 1},
                      {1010, 1020, 1},
                      {1025, 1040, 1},
                      {1130, 1145, 2},
                      {1130, 1140, 2}};
    cout << "Maximum Stopped Trains = "
         << maxStop(5,2,arr);
    return 0;
}