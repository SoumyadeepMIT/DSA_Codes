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

Node* split(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        if(fast) slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = nullptr;
    return temp;
}
Node* merge(Node* first, Node* sec){
    Node* res = NULL;
    Node* temp = NULL;
    while(first && sec){
        if(first->data<sec->data){
            if(res == NULL){
                res = new Node(first->data);
                temp = res;
            }
            else{
                temp->next = new Node(first->data);
                temp = temp->next;
            }
            first = first->next;
        }
        else{
            if(res == NULL){
                res = new Node(sec->data);
                temp = res;
            }
            else{
                temp->next = new Node(sec->data);
                temp = temp->next;
            }
            sec = sec->next;
        }
    }
    while(first){
        if(res == NULL){
            res = new Node(first->data);
            temp = res;
        }
        else{
            temp->next = new Node(first->data);
            temp = temp->next;
        }
        first = first->next;
    }
    while(sec){
        if(res == NULL){
            res = new Node(sec->data);
            temp = res;
        }
        else{
            temp->next = new Node(sec->data);
            temp = temp->next;
        }
        sec = sec->next;
    }
    return res;
}
Node* mergeSort(Node* head) {
    // code here
    if(!head || head->next == nullptr) return head;
    Node* sec = split(head);
    head = mergeSort(head);
    sec = mergeSort(sec);
    return merge(head, sec);
}

int main(){
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head = mergeSort(head);
    printList(head);
    return 0;
}