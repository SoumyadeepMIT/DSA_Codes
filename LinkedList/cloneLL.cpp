#include <bits/stdc++.h> 
using namespace std;
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data << "(";
        if (head->random)
            cout << head->random->data << ")";
        else
            cout << "null"
                 << ")";

        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

Node* cloneLinkedList(Node* head) {
        // code here
    unordered_map<Node*, Node*> um;
    Node* nh = NULL;
    Node* nt = NULL;
    Node* curr = head;
    while(curr){
        if(nh==NULL){
            nh = new Node(curr->data);
            nt = nh;
        }
        else{
            nt->next = new Node(curr->data);
            nt = nt->next;
        }
        um[curr] = nt;
        curr = curr->next;
    }
    curr = head;
    Node* ncurr = nh;
    while(curr){
        if(curr->random){
            ncurr->random = um[curr->random];
        }
        else{
            ncurr->random = NULL;
        }
        curr = curr->next;
        ncurr = ncurr->next;
    }
    return nh;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    Node *clonedList = cloneLinkedList(head);
    printList(clonedList);

    return 0;
}