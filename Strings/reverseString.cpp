#include <bits/stdc++.h>
using namespace std;
void reverseString(vector<char>& s) {
    int l = 0;
    int r = s.size() - 1;
    while(l<r){
        swap(s[l++],s[r--]);
    }
}
int main(){
    vector<char> s = {'H','a','n','n','a','h'};
    reverseString(s);
    for(char c:s)cout<<c;
}