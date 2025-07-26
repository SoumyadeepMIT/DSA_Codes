#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &arr) {
    // code here
    int currMin = arr[0];
    int currMax = arr[0];
    int mp = arr[0];
    for(int i=1;i<arr.size();i++){
        int temp = max({arr[i], currMin*arr[i], currMax*arr[i]});
        currMin = min({arr[i], currMin*arr[i], currMax*arr[i]});
        currMax = temp;
        mp = max(currMax,mp);
    }
    return mp;
}

int main(){
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout<<maxProduct(arr);
}