#include <bits/stdc++.h> 
using namespace std;
static int countSet(int n) {
    int res = 0;
    while (n != 0) {
        if (n & 1) res++;
        n = n >> 1;
    }
    return res;
}

static bool cmp(int a, int b) {
    int ca = countSet(a);
    int cb = countSet(b);
    return ca > cb;  // sort by decreasing set-bit count
}

void sortBySetBitCount(int arr[], int n) {
    stable_sort(arr, arr + n, cmp);
}

int main(){
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    sortBySetBitCount(arr, 9);
    for(int n:arr) cout<<n<<" ";
    return 0;
}