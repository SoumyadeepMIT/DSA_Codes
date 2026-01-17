#include <bits/stdc++.h>
using namespace std;
int minPlatform(vector<int>& arr, vector<int>& dep) {
    // code here
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int res = 0;
    int cnt = 0;
    int j = 0;
    for(int i=0;i<n;i++){
        while(j<n && dep[j]<arr[i]){
            j++;
            cnt--;
        }
        cnt++;
        res = max(res, cnt);
    }
    return res;
}
int main() {
    vector<int> arr = {1000, 935, 1100};
    vector<int> dep = {1200, 1240, 1130};
    cout << minPlatform(arr, dep) << endl;
    return 0;
}