//Shell
#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
    int n = a.size();
    int m = b.size();
    int gap = ((n+m)/2)+((n+m)%2);
    while(gap>0){
        int left = 0;
        int right = left + gap;
        while(right<=(n+m-1)){
            if(left<n && right>=n){
                if(a[left]>b[right-n]){
                    swap(a[left],b[right-n]);
                }
            }
            else if(right<n){
                if(a[left]>a[right]) swap(a[left],a[right]);
            }
            else{
                if(b[left-n]>b[right-n]) swap(b[left-n],b[right-n]);
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap = (gap/2) + (gap%2);
    }
}

int main() {
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a, b);

    for (int ele: a)
        cout << ele << " ";
    cout << "\n";
    for (int ele: b)
        cout << ele << " ";
    return 0;
}