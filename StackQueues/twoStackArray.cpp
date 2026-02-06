#include <bits/stdc++.h>
using namespace std;
class twoStacks {
  public:
    vector<int> tst;
    int t1;
    int t2;
    int cap;
    twoStacks() {
        cap = 100;
        tst.assign(cap, -1);
        t1 = -1;
        t2 = cap;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(t1>=t2-1) return;
        t1++;
        tst[t1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(t1>=t2-1) return;
        t2--;
        tst[t2] = x;
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        // code here
        if(t1<0) return -1;
        int x = tst[t1];
        t1--;
        return x;
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(t2>=cap) return -1;
        int x = tst[t2];
        t2++;
        return x;
    }
};

int main() {
    twoStacks ts;
    ts.push1(10);
    ts.push2(20);
    ts.push1(30);
    ts.push2(40);
    cout << ts.pop1() << endl; // Output: 30
    cout << ts.pop2() << endl; // Output: 40
    return 0;
}
