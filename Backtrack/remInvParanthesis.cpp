#include <bits/stdc++.h>
using namespace std;
void gen(string s, int i, int oc, int cc, int rem, string curr, unordered_set<string>& exp, int& minRem) {

    if (rem > minRem) return;

    if (i == s.length()) {
        if (oc != cc) return;

        if (rem < minRem) {
            exp.clear();
            exp.insert(curr);
            minRem = rem;
        } else if (rem == minRem) {
            exp.insert(curr);
        }
        return;
    }

    if (s[i] != '(' && s[i] != ')') {
        gen(s, i+1, oc, cc, rem, curr + s[i], exp, minRem);
        return;
    }

    // option 1: remove parenthesis
    gen(s, i+1, oc, cc, rem + 1, curr, exp, minRem);

    // option 2: keep parenthesis
    if (s[i] == '(') {
        gen(s, i+1, oc + 1, cc, rem, curr + s[i], exp, minRem);
    } else {
        if (cc < oc) {
            gen(s, i+1, oc, cc + 1, rem, curr + s[i], exp, minRem);
        }
    }
}

vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> exp;
    int minRem = s.length();
    gen(s, 0, 0, 0, 0, "", exp, minRem);
    vector<string> res(exp.begin(), exp.end());
    return res;
}

int main() {
    string s = "(a)())()";
    vector<string> result = removeInvalidParentheses(s);
    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}