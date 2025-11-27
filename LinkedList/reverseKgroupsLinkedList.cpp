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

Node *reverseKGroup(Node *head, int k) {
    // code here
    if(!head) return head;
    Node* newHead = NULL;
    Node* temp = head;
    Node* tail = NULL;
    while(temp){
        Node* curHead = temp;
        Node* prev = NULL;
        Node* nex = NULL;
        int c = 0;
        while(temp && c<k){
            nex = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nex;
            c++;
        }
        if(!newHead) newHead = prev;
        if(tail) tail->next = prev;
        tail = curHead;
    }
    return newHead;
}
int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = reverseKGroup(head, 3);
    printList(head);
    return 0;
}