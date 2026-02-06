#include <bits/stdc++.h>
using namespace std;
class myQueue {

  public:
    int front;
    int size;
    int cap;
    vector<int> qu;
    myQueue(int n) {
        // Define Data Structures
        qu.assign(n,-1);
        cap = n;
        front = 0;
        size = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(size==0) return true;
        return false;
    }

    bool isFull() {
        // check if the queue is full
        if(size==cap) return true;
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()) return;
        int rear = (front+size) % cap;
        qu[rear] = x;
        size++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()) return;
        front=(front+1)%cap;
        size--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) return -1;
        return qu[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()) return -1;
        int rear = (front + size -1) % cap;
        return qu[rear];
    }
};
int main() {
    myQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.getFront() << endl; // Output: 10
    cout << q.getRear() << endl;  // Output: 30
    q.dequeue();
    cout << q.getFront() << endl; // Output: 20
    return 0;
}