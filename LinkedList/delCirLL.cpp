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
    cout<<head->data<<" ";
    Node* temp = head->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* deleteNode(Node* head, int key) {
    // code here
    Node* curr = head->next;
    Node* prev = head;
    while(curr!=head){
        if(curr->data==key){
            prev->next = curr->next;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    if(head->data == key){
        prev->next = head->next;
        head = head->next;
    }
    return head;
}
int main(){
    Node* head = new Node(10);
    head->next = new Node(9);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = head;
    head = deleteNode(head, 8);
    printList(head);
    return 0;
}