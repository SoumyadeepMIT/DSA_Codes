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

Node *sortedDll(Node *head, int k)
{
    // Write your code here
    Node* curr = head->next;
    int key = curr->data;
    while(curr){
        int key = curr->data;
        Node* back = curr->prev;
        while(back && back->data>key){
            back->next->data = back->data;
            back = back->prev;
        }
        if(back==NULL) head->data = key;
        else back->next->data = key;
        curr=curr->next;
    }
    return head;
}

int main(){
    Node *head = new Node(6);
    head->next = new Node(5);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    int k = 4;
    head = sortedDll(head, k);
    printList(head);
    return 0;
}