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
bool isCircular(Node *head) {
        // Your code here
    if(!head) return true;
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        if(slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
int main(){
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next = head;
    bool res = isCircular(head);
    if(res) cout<<"Circular";
    else cout<<"Not circular";
    return 0;
}