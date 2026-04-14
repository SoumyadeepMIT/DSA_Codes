#include <bits/stdc++.h>
using namespace std;
int check(vector<int>& temp){
    int n = temp.size();
    unordered_map<int,int> um;
    int sum = 0;
    int res = 0;
    for(int i=0;i<n;i++){
        sum+=temp[i];
        if(sum==0){
            res = i+1;
        }
        else{
            if(um.find(sum)!=um.end()){
                int j = um[sum];
                res =max(res,i-j);
            }
            else{
                um[sum] = i;
            }
        }
    }
    return res;
}
int zeroSumSubmat(vector<vector<int>>& mat) {
    // Code Here
    int r = mat.size();
    int c = mat[0].size();
    int ma = 0;
    for(int i=0;i<r;i++){
        vector<int> temp(c, 0);
        for(int j=i;j<r;j++){
            for(int k=0;k<c;k++){
                temp[k]+=mat[j][k];
            }
            int wid = check(temp);
            int hei = j-i+1;
            ma = max(ma, hei*wid);
        }
    }
    return ma;
}
int main(){
    vector<vector<int>> mat = {{9, 7, 16, 5}, {1, -6, -7, 3}, {1, 8, 7, 9}, {7, -2, 0, 10}};
    cout<<zeroSumSubmat(mat)<<endl;
    return 0;
}