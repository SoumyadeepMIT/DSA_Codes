#include <bits/stdc++.h>
using namespace std;
int transform(string a, string b) {
    // code here.
    int n = a.length();
    int m = b.length();
    unordered_map<char,int> freq;
    for(char c:a){
        freq[c]++;
    }
    for(char c:b) freq[c]--;
    for(auto it: freq){
        if(it.second!=0)return -1;
    }
    int i=n-1;
    int j=m-1;
    int res = 0;
    while(i>=0 && j>=0){
        while(i>=0 && a[i]!=b[j]){
            res++;
            i--;
        }
        i--;
        j--;
    }
    return res;
}
int main(){
    string a = "GeeksForGeeks";
    string b = "ForGeeksGeeks";
    cout<<transform(a,b);
    return 0;
}