#include <bits/stdc++.h>
using namespace std;
int minimumNumberOfSwaps(string& s) {
    // code here
    int oc = 0;
    int cc = 0;
    int fl = 0;
    int imb = 0;
    for(char c:s){
        if(c=='[') {
            oc++;
            if(imb>0){
                fl+=imb;
                imb--;
            }
        }
        else{
            cc++;
            imb = cc-oc;
        }
    }
    return fl;
}
int main(){
    string s = "[]][][";
    cout<<minimumNumberOfSwaps(s);
    return 0;
}