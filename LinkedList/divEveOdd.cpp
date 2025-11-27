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

Node* divide(Node* head) {
        // code here
    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* temp = dummy;
    Node* prev = dummy;
    Node* curr = head;
    bool f = false;
    while(curr){
        if(curr->data%2==0 && !f){
            temp = curr;
            prev = curr;
            curr = curr->next;
            continue;
        }
        if(curr->data%2==0 && f){
            prev->next = curr->next;
            Node* nex = temp->next;
            temp->next = curr;
            curr->next = nex;
            temp = curr;
            curr = prev->next;
        }
        else{
            f = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy->next;
}

int main(){
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = new Node(11);

    cout << "Original Linked list: ";
    printList(head);

    head = divide(head);

    cout << "\nModified Linked list: ";
    printList(head);

    return 0;
}