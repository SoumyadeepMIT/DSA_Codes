#include <bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s) {
    // Code here
    int n = s.length();
    vector<string> res;
    for(int i=1;i<=(1<<n);i++){
        string sub = "";
        for(int j=0;j<n;j++){
            if(i&(1<<j)) sub+=s[j];
        }
        res.push_back(sub);
    }
    sort(res.begin(), res.end());
    return res;
}
int main() {
    string s = "abc";
    vector<string> res = AllPossibleStrings(s);
    for (const auto& str : res) {
        cout << str << endl;
    }
    return 0;
}