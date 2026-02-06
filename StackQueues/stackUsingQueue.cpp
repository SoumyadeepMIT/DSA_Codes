#include <bits/stdc++.h>
using namespace std;
class myStack {
    queue<int> q;

  public:

    void push(int x) {
        // Inserts an element x at the top of the stack
        q.push(x);
    }

    void pop() {
        // Removes an element from the top of the stack
        if(q.empty()) return;
        if(q.size() == 1){
            q.pop();
            return;
        }
        queue<int> qu;
        while(q.size()>1){
            qu.push(q.front());
            q.pop();
        }
        q.pop();
        q = qu;
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(q.empty()) return -1;
        return q.back();
    }

    int size() {
        // Returns the current size of the stack
        return q.size();
    }
};
int main() {
    myStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top element: " << st.top() << endl; // Should print 30
    cout << "Stack size: " << st.size() << endl; // Should print 3
    st.pop();
    cout << "Top element after pop: " << st.top() << endl; // Should print 20
    cout << "Stack size after pop: " << st.size() << endl; // Should print 2
    return 0;
}