#include<bits/stdc++.h>
using namespace std;
int checkMirrorTree(int n, int e, int A[], int B[]) {
    // code here
    unordered_map<int, stack<int>> um;
    for(int i=0;i<2*e;i+=2){
        um[A[i]].push(A[i+1]);
    }
    for(int i=0;i<2*e;i+=2){
        if(um[B[i]].top()!=B[i+1]){
            return 0;
        }
        um[B[i]].pop();
    }
    return 1;
}
int main(){
    int n = 3, e = 2;
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 3, 1, 2};

    if (checkMirrorTree(n, e, A, B))
        cout << "1";
    else
        cout << "0";

    return 0;
}