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

Node* intersectPoint(Node* head1, Node* head2) {
    //  Code Here
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    if(!ptr1 || !ptr2) return NULL;
    while(ptr1 != ptr2){
        ptr1 = ptr1?ptr1->next:head2;
        ptr2 = ptr2?ptr2->next:head1;
    }
    return ptr1;
}

int main(){
    Node* head1 = new Node(2);
    head1->next = new Node(3);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(5);
    Node* head2 = new Node(10);
    head2->next = head1->next->next;
    Node* res = intersectPoint(head1, head2);
    cout<<res->data;
    return 0;
}