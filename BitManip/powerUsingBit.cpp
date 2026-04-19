#include <bits/stdc++.h>
using namespace std;
int square(int n) {
    // code here
    if(n<0) n=-n;
    int temp = n;
    int res = 0;
    for(int i=31;i>=0;i--){
        if(temp>=(1LL<<i)){
            res += (n<<i);
            temp -= (1<<i);
        }
    }
    return res;
}
int main() {
    int n = 5;
    cout << square(n) << endl;
    return 0;
}