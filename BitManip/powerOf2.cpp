#include <bits/stdc++.h>
using namespace std;
bool isPowerofTwo(int n) {
    // code here
    return (n>0) && ((n&(n-1)) == 0);
}
int main() {
    int n = 16;
    cout << isPowerofTwo(n) << endl;
    return 0;
}