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
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

pair<Node *, Node *> splitList(struct Node *head) {
        // code here
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=head && fast->next!=head){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* sechead = slow->next;
    slow->next = head;
    Node* temp = sechead;
    while(temp->next!=head) temp=temp->next;
    temp->next = sechead;
    return {head, sechead};
}
int main(){
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = new Node(10);
    head->next->next->next->next= head;
    pair<Node*, Node*> p = splitList(head);
    printList(p.first);
    printList(p.second);
    return 0;
}