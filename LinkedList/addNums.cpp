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

Node* reverse(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head->next;
    Node* prev = head;
    prev->next = nullptr; 
    while(temp) {
        Node* nex = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nex;
    }
    return prev;
}

Node* addTwoLists(Node* head1, Node* head2) {
    // code here
    while(head1 && head1->data == 0) head1 = head1->next;
    while(head2 && head2->data == 0) head2 = head2->next;
    if(!head1) return head2;
    if(!head2) return head1;
    head1 = reverse(head1);
    head2 = reverse(head2);
    Node* res = NULL;
    Node* prev = NULL;
    int c = 0;
    while(head1 && head2){
        int sum = head1->data + head2->data + c;
        res = new Node(sum%10);
        c = sum/10;
        res->next = prev;
        prev = res;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1){
        int sum = head1->data + c;
        res = new Node(sum%10);
        c = sum/10;
        res->next = prev;
        prev = res;
        head1 = head1->next;
    }
    while(head2){
        int sum = head2->data + c;
        res = new Node(sum%10);
        c = sum/10;
        res->next = prev;
        prev = res;
        head2 = head2->next;
    }
    if(c>=1){
        res = new Node(c);
        res->next = prev;
    }
    return res;
}

int main(){
    Node *head = new Node(3);
    head->next = new Node(9);
    head->next->next = new Node(9);
    Node* head2 = new Node(9);
    head2->next = new Node(9);
    head = addTwoLists(head, head2);
    printList(head);
    return 0;
}