#include <bits/stdc++.h>
using namespace std;
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // Write your code here
    unordered_map<int,int> um;
    int n = mat.size();
    for(int i=0;i<n;i++){
        unordered_set<int> us;
        for(int num:mat[i]) us.insert(num);
        for(int num:us) um[num]++;
    }
    vector<int> res;
    for(auto it: um){
        if(it.second == n) res.push_back(it.first);
    }
    return res;
}
int main()
{
    vector<vector<int>> mat = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };

    vector<int> res = findCommonElements(mat);
    for(int n:res) cout<<n<<" ";
    return 0;
}