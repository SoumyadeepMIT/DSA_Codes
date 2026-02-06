#include <bits/stdc++.h>
using namespace std;
class StackQueue{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
};

void StackQueue::push(int B) 
{
    s1.push(B);
}

int StackQueue::pop() {
    if(s1.empty()) return -1;
    if(s1.size()==1){
        int x = s1.top();
        s1.pop();
        return x;
    }
    while(s1.size()>1){
        s2.push(s1.top());
        s1.pop();
    }
    int x = s1.top();
    s1.pop();
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return x;
}

int main() {
    StackQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl; // Outputs 1
    q.push(4);
    cout << q.pop() << endl; // Outputs 2
    cout << q.pop() << endl; // Outputs 3
    cout << q.pop() << endl; // Outputs 4
    cout << q.pop() << endl; // Outputs -1 (queue is empty)
    return 0;
}