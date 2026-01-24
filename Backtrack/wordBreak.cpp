#include <bits/stdc++.h>
using namespace std;

void gen(unordered_set<string>& us, string& s,vector<string>& res, string fin, string curr, int i){
    if(i == s.length()-1){
        curr+=s[i];
        if(us.find(curr)!=us.end()){
            fin+=curr;
            res.push_back(fin);
        }
        return;
    }
    curr+=s[i];
    if(us.find(curr)!=us.end()){
        gen(us, s, res, fin+curr+" ", "", i+1);
    }
    gen(us, s, res, fin, curr, i+1);
    return;
}
vector<string> wordBreak(vector<string>& dict, string& s) {
    // code here
    unordered_set<string> us(dict.begin(), dict.end());
    vector<string> res;
    gen(us, s, res, "", "", 0);
    return res;
}

int main() {
    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
    string s = "catsanddog";
    vector<string> result = wordBreak(dict, s);
    for (const string& sentence : result) {
        cout << sentence << endl;
    }
    return 0;
}