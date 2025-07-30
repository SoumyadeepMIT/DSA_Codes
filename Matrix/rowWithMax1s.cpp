#include <bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>> &arr) {
    // code here
    int row = arr.size();
    int col = arr[0].size();
    int res = -1;
    int i=0,j=col-1;
    while(i<row && j>=0){
        if(arr[i][j]){
            j--;
            res=i;
        }
        else{
            i++;
        }
    }
    return res;
}
int main(){
    vector<vector<int>> arr = {{0, 0, 0, 1},
                                {0, 1, 1, 1},
                                {1, 1, 1, 1},
                                {0, 0, 0, 0}};
    cout<<rowWithMax1s(arr);
    return 0;
}