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

Node *removeDuplicates(Node *head) {
        // your code goes here
    if(head->next == NULL) return head;
    unordered_map<int,Node*> um;
    Node* prev = head;
    Node* temp = head->next;
    um[prev->data] = prev;
    while(temp){
        if(um.find(temp->data)!=um.end()){
            prev->next = temp->next;
        }
        else{
            prev = temp;
            um[temp->data] = temp;
        }
        temp=temp->next;
    }
    return head;
}
 
int main(){
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head = removeDuplicates(head);
    printList(head);
    return 0;
}