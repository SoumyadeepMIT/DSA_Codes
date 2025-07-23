#include<iostream>
#include<vector>
using namespace std;

int minJumps(vector<int>& arr) {
    // code here
    int maxp = 0;
    int currp = 0;
    int jumps = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        maxp = max(maxp,i+arr[i]);
        if(maxp>=n-1) return jumps+1;
        if(i==currp){
            if(i==maxp) return -1;
            currp = maxp;
            jumps++;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    
    cout << minJumps(arr);
    return 0;
}