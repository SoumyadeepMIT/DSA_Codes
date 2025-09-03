#include <bits/stdc++.h>
using namespace std;
void rec(int i,vector<vector<string>>& list, vector<vector<string>>& res, vector<string>& temp){
    if(i==list.size()){
        res.push_back(temp);
        return;
    }
    for(string s:list[i]){
        temp.push_back(s);
        rec(i+1,list,res,temp);
        temp.pop_back();
    }
    return;
}
vector<vector<string>> sentences(vector<vector<string>>& list) {
    // Write your code here
    vector<vector<string>> res;
    vector<string> temp;
    rec(0,list,res,temp);
    return res;
}
int main(){
    vector<vector<string>> list = {{"you", "we"},
     {"have", "are"}};
    vector<vector<string>> res = sentences(list);
    for(vector<string> temp:res){
        for(string s:temp) cout<<s<<" ";
        cout<<endl;
    }
    return 0;
}