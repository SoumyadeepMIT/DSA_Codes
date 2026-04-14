#include <bits/stdc++.h>
using namespace std;
int maxSubstring(string s) {
    // Your code goes here
    int n = s.length();
    int f = (s[0]=='0')?1:-1;
    int mu = f;
    int res= f;
    for(int i=1;i<n;i++){
        f = (s[i] == '0')? 1:-1;
        mu = max(f, mu + f);
        res = max(res, mu);
    }
    return res;
}
int main() {
    string s = "110001111";
    cout << maxSubstring(s) << endl;
    return 0;
}