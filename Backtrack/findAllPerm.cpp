#include <bits/stdc++.h>
using namespace std;
void gen(string s, unordered_set<string>& res,int ind){
    if(ind == s.length()) {
        res.insert(s);
        return;
    }
    for(int i=ind;i<s.length();i++){
        swap(s[i], s[ind]);
        gen(s, res, ind+1);
        swap(s[i], s[ind]);
    }
    return;
}
vector<string> findPermutation(string &s) {
    // Code here there
    unordered_set<string> res;
    gen(s, res, 0);
    vector<string> ans(res.begin(), res.end());
    return ans;
}
int main() {
    string s = "ABC";
    vector<string> permutations = findPermutation(s);
    cout << "All unique permutations of the string are:\n";
    for (const string& perm : permutations) {
        cout << perm << endl;
    }
    return 0;
}