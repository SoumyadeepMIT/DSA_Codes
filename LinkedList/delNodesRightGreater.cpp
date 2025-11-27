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

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        Node* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}
Node *compute(Node *head) {
    // your code goes here
    if(head==NULL || head->next == NULL) return head;
    head = reverse(head);
    int mv = head->data;
    Node* curr = head->next;
    Node* prev = head;
    while(curr){
        if(curr->data<mv){
            prev->next = curr->next;
            curr = curr->next;
        }
        else{
            prev = curr;
            mv = curr->data;
            curr = curr->next;
        }
    }
    head = reverse(head);
    return head;
}

int main(){
    Node* head = new Node(12); 
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(3);

    head = compute(head);

    printList(head);

    return 0;
}