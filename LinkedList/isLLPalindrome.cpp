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

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        Node* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}
bool isPalindrome(Node *head) {
    //  code here
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secHead = reverse(slow->next);
    slow->next = nullptr;
    while(head && secHead){
        if(head->data != secHead->data) return false;
        head = head->next;
        secHead = secHead->next;
    }
    return true;
}

int main(){
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(3);
    if(isPalindrome(head)) cout<<"Palindrome";
    else cout<<"Not Palindrome";
    return 0;
}