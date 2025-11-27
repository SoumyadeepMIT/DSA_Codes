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

Node *moveToFront(Node *head) {
    // code here
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head->next;
    Node* prev = head;
    while(temp->next){
        prev = temp;
        temp=temp->next;
    }
    temp->next = head;
    head = temp;
    prev->next = nullptr;
    return head;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = moveToFront(head);
    printList(head);
    return 0;
}