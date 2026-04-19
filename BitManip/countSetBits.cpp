#include <bits/stdc++.h>
using namespace std;
int setBits(int n) {
    // Write Your Code here
    int c = 0;
    while(n!=0){
        if(n&1) c++;
        n = n>>1;
    }
    return c;
}
int main() {
    int n = 6;
    cout << setBits(n) << endl;
    return 0;
}