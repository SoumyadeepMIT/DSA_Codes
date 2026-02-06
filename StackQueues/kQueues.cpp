#include <bits/stdc++.h>
using namespace std;
class kQueues {
    vector<int> arr;
    vector<int> front;
    vector<int> rear;
    vector<int> next;
    int fs;
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        arr.assign(n, -1);
        front.assign(k,-1);
        rear.assign(k,-1);
        next.assign(n, -1);
        for(int i=0;i<n-1;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        fs = 0;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        if(fs == -1) return;
        int ind = fs;
        fs = next[ind];
        if(front[i] == -1){
            front[i] = ind;
        }
        else{
            next[rear[i]] = ind;
        }
        next[ind] = -1;
        rear[i] = ind;
        arr[ind] = x;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if(front[i] == -1) return -1;
        int ind = front[i];
        front[i] = next[ind];
        next[ind] = fs;
        fs = ind;
        return arr[ind];
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return front[i] == -1;
    }

    bool isFull() {
        // check if array is full
        return fs == -1;
    }
};

int main() {
    int n = 10, k = 3;
    kQueues q(n, k);

    q.enqueue(15, 0);
    q.enqueue(45, 0);

    q.enqueue(17, 1);
    q.enqueue(49, 1);
    q.enqueue(39, 1);

    q.enqueue(11, 2);
    q.enqueue(9, 2);
    q.enqueue(7, 2);

    cout << "Dequeued element from queue 0 is " << q.dequeue(0) << endl;
    cout << "Dequeued element from queue 1 is " << q.dequeue(1) << endl;
    cout << "Dequeued element from queue 2 is " << q.dequeue(2) << endl;

    return 0;
}