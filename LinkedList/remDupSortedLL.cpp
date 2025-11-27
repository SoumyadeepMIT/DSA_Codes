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

Node* removeDuplicates(Node* head) {
    // code here
    if(head->next == NULL) return head;
    Node* temp = head->next;
    Node* prev = head;
    while(temp){
        if(temp->data==prev->data){
            prev->next = temp->next;
        }
        else{
            prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    Node *head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head = removeDuplicates(head);
    printList(head);
    return 0;
}