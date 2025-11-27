#include <bits/stdc++.h> 
using namespace std;
class Node {
 public:
    int data ;
    Node *next ;
    Node* prev;

    Node(int x) {
        data = x ;
        next = NULL ;
        prev = NULL;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* rotateDLL(Node* head, int p) {

    Node* tail = head;


    while (tail->next) {
        tail = tail->next;
    }

    tail->next = head;
    head->prev = tail;
    for (int count = 1; count <= p; count++) {
        head = head->next;
        tail = tail->next;
    }

    tail->next = nullptr;
    head->prev = nullptr;

    return head;
}

int main() {
  
    Node* head = new Node(2);
    head->next = new Node(6);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    int p = 3;
    head = rotateDLL(head, p);
    printList(head);

    return 0;
}