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

void removeLoop(Node* head) {
    // code here
    if (head == nullptr || head->next ==nullptr)
        return;
    Node* slow = head;
    Node* fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while(fast && fast->next){
        if(slow == fast) break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow != fast) return;
    slow = head;
    if(slow == fast){
        while(fast->next!=slow) fast = fast->next;
    }
    else{
        while(fast->next != slow->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = nullptr;
    return;
}

void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
  
    head->next->next->next = head->next;

    removeLoop(head);
    printList(head);

    return 0;
}