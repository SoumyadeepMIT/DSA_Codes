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

Node *reverse(Node *head) {
        // code here
    Node* curr = head;
    Node* nex = NULL;
    Node* prev = curr->prev;
    while(curr!=nullptr){
        nex = curr->next;
        curr->next = prev;
        curr->prev = nex;
        prev = curr;
        curr = nex;
    }
    return prev;
}

int main(){
    Node* head = new Node(3);
    head->prev = NULL;
    head->next = new Node(4);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;
    head = reverse(head);
    printList(head);
    return 0;
}