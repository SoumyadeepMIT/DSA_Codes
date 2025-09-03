#include <bits/stdc++.h> 
using namespace std;
string printSequence(string S) {
    // code here.
    vector<string> dp = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", 
    "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999",
    "9999"};
    string res = "";
    for(char c:S){
        if(c==' ')res+='0';
        else res+=dp[c-'A'];
    }
    return res;
}
int main(){
    string s ="HEY U";
    cout<<printSequence(s);
    return 0;
}