#include <bits/stdc++.h>
using namespace std;
void rearrangeQueue(queue<int> &q) {
    // code here
    queue<int> fq;
    queue<int> sq;
    int n = q.size();
    for(int i=0;i<(n/2);i++){
        fq.push(q.front());
        q.pop();
    }
    while(!q.empty()){
        sq.push(q.front());
        q.pop();
    }
    for(int i=0;i<(n/2);i++){
        q.push(fq.front());
        fq.pop();
        q.push(sq.front());
        sq.pop();
    }
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    rearrangeQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}