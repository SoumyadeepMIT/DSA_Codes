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

Node* segregate(Node* head) {
    // code here
    Node* zh = NULL;
    Node* zt = NULL;
    Node* oh = NULL;
    Node* ot = NULL;
    Node* th = NULL;
    Node* tt = NULL;
    Node* curr = head;
    while(curr){
        if(curr->data == 0){
            if(zh==NULL){
                zh = new Node(0);
                zt = zh;
            }
            else{
                zt->next = new Node(0);
                zt = zt->next;
            }
        }
        else if(curr->data == 1){
            if(oh==NULL){
                oh = new Node(1);
                ot = oh;
            }
            else{
                ot->next = new Node(1);
                ot = ot->next;
            }
        }
        else if(curr->data == 2){
            if(th==NULL){
                th = new Node(2);
                tt = th;
            }
            else{
                tt->next = new Node(2);
                tt = tt->next;
            }
        }
        curr = curr->next;
    }
    if(zh==NULL){
        if(oh==NULL){
            if(th==NULL){
                return NULL;
            }
            else return th;
        }
        else{
            ot->next = th;
            return oh;
        }
    }
    else{
        if(oh==NULL){
            zt->next = th;
        }
        else{
            zt->next = oh;
            ot->next = th;
        }
        return zh;
    }
    return NULL;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(2);
    head = segregate(head);
    printList(head);
    return 0;
}