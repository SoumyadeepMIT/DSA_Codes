#include <bits/stdc++.h> 
using namespace std;
class Node {
 public:
    int data ;
    Node *next ;
    Node* bottom;

    Node(int x) {
        data = x ;
        next = NULL ;
        bottom = NULL;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->bottom;
    }
}

struct mycomp{
    bool operator()(Node* a, Node* b){
        return a->data>b->data;
    }
};
Node *flatten(Node *root) {
    // code here
    priority_queue<Node*, vector<Node*>, mycomp> pq;
    Node* head = NULL;
    Node* tail = NULL;
    while(root!=NULL){
        pq.push(root);
        root = root->next;
    }
    while(!pq.empty()){
        auto minNode = pq.top();
        pq.pop();
        if(head==NULL){
            head = minNode;
            tail = minNode;
        }
        else{
            tail->bottom = minNode;
            tail = tail->bottom;
        }
        if(minNode->bottom){
            pq.push(minNode->bottom);
            minNode->bottom = NULL;
        }
    }
    return head;
}

int main(){
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    head = flatten(head);

    printList(head);
    return 0;
}