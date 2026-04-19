#include <bits/stdc++.h>
using namespace std;
int findPosition(int n) {
    // code here
    int pos = 1;
    while(n!=0){
        if((n&1)){
            if(n>>1) return -1;
            else return pos;
        }
        pos++;
        n>>=1;
    }
    return -1;
}
int main() {
    int n = 16;
    cout << findPosition(n) << endl;
    return 0;
}