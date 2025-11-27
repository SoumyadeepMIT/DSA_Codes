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

Node* findIntersection(Node* head1, Node* head2) {
    // code goes here.
    Node* head = NULL;
    Node* temp = NULL;
    while(head1 && head2){
        if(head1->data == head2->data){
            Node* h = new Node(head1->data);
            if(head==NULL){
                head = h;
                temp = h;
            }
            else{
                temp->next = h;
                temp = temp->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->data < head2->data){
            head1 = head1->next;
        }
        else{
            head2 = head2->next;
        }
    }
    return head;
}

int main(){
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(5);
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    printList(findIntersection(head,head2));
    return 0;
}