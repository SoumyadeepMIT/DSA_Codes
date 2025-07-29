#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>& A = nums1;
    vector<int>& B = nums2;
    int total = A.size() + B.size();
    int half = (total + 1) / 2;

    if (B.size() < A.size()) {
        swap(A, B);
    }

    int l = 0;
    int r = A.size();
    while (l <= r) {
        int i = (l + r) / 2;
        int j = half - i;

        int Aleft = i > 0 ? A[i - 1] : INT_MIN;
        int Aright = i < A.size() ? A[i] : INT_MAX;
        int Bleft = j > 0 ? B[j - 1] : INT_MIN;
        int Bright = j < B.size() ? B[j] : INT_MAX;

        if (Aleft <= Bright && Bleft <= Aright) {
            if (total % 2 != 0) {
                return max(Aleft, Bleft);
            }
            return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
        } else if (Aleft > Bright) {
            r = i - 1;
        } else {
            l = i + 1;
        }
    }
    return -1;
}
int main(){
    vector<int> nums1 = {2, 4, 6};
    vector<int> nums2 = {1, 3, 5};
    cout<<findMedianSortedArrays(nums1,nums2);
}