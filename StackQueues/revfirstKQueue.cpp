#include <bits/stdc++.h>
using namespace std;
void rev(queue<int>& q, int k, int n){
    if(n==k) return;
    int x = q.front();
    q.pop();
    rev(q, k, n+1);
    q.push(x);
}
queue<int> reverseFirstK(queue<int> q, int k) {
    // code here
    int n = q.size();
    if(n<k) return q;
    rev(q,k,0);
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    queue<int> result = reverseFirstK(q, k);

    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    return 0;
}