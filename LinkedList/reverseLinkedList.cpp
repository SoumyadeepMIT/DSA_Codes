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
Node* reverseList(Node* head) {
        // code here
    Node* newHead = NULL;
    Node* temp = head;
    while(temp){
        Node* h = new Node(temp->data);
        h->next = newHead;
        newHead = h;
        temp = temp->next;
    }
    return newHead;
}

void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = reverseList(head);
    printList(head);
    return 0;
}