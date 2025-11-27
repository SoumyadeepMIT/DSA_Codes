#include <bits/stdc++.h> 
using namespace std;
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};


void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* reverse(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head->next;
    Node* prev = head;
    prev->next = nullptr; 
    while(temp) {
        Node* nex = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nex;
    }
    return prev;
}

Node* addOne(Node* head) {
    head = reverse(head);
    int c = 1; 
    Node* temp = head;
    Node* prev = nullptr;
    while(temp) {
        int v = temp->data;
        temp->data = (v + c) % 10; 
        c = (v + c) / 10;
        prev = temp;
        temp = temp->next;
    }
    if(c == 1) {
        Node* h = new Node(c);
        prev->next = h;
    }
    head = reverse(head);
    return head;
}

int main(){
    Node *head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
    head = addOne(head);
    printList(head);
    return 0;
}