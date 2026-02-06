#include <bits/stdc++.h>
using namespace std;
class myStack {
  public:
    int top;
    int cap;
    vector<int> st;
    myStack(int n) {
        // Define Data Structures
        top = -1;
        cap = n;
        st.assign(n, -1);
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top==-1) return true;
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(top==(cap-1)) return true;
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()) return;
        top++;
        st[top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()) return;
        st[top--] = -1;
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty()) return -1;
        return st[top];
    }
};

int main() {
    myStack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.peek() << endl; // Output: 30
    s.pop();
    cout << s.peek() << endl; // Output: 20
    return 0;
}