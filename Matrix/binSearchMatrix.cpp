#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int l = 0;
    int r = matrix.size();
    int c = matrix[0].size();
    int h = r*c-1;
    while(l<=h){
        int mid = (l+h)/2;
        int i = mid / c;
        int j = mid % c;
        if(matrix[i][j] == target) return true;
        else if(matrix[i][j]<target) l = mid+1;
        else h = mid - 1;
    }
    return false;
}
int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    if(searchMatrix(matrix,3)) cout<<"Target present";
    else cout<<"Target not present";
}