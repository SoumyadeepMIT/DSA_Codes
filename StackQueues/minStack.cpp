#include <bits/stdc++.h>
using namespace std;
stack<int> aux;


bool isEmpty(stack<int>& s) {
    // Your code goes here
    if(s.empty()) return true;
    return false;
}

void push(stack<int>& s, int a) {
    // Your code goes here
    if(s.empty()){
        s.push(a);
        aux.push(a);
        return;
    }
    int v = min(a, s.top());
    s.push(a);
    aux.push(v);
}



int pop(stack<int>& s) {
    // Your code goes here
    if(isEmpty(s)) return -1;
    int t=s.top();
    s.pop();
    aux.pop();
    return t;
}

int getMin(stack<int>& s) {
    // Your code goes here
    if(isEmpty(s)) return -1;
    return aux.top();
}

int main(){
    stack<int> s;
    push(s, 10);
    cout<<getMin(s)<<endl;
    push(s, 5);
    cout<<getMin(s)<<endl;
    push(s, 20);
    cout<<getMin(s)<<endl;
    pop(s);
    cout<<getMin(s)<<endl;
    pop(s);
    cout<<getMin(s)<<endl;
    return 0;
}