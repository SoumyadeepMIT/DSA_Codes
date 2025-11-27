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

long long multiplyTwoLists(Node *first, Node *second) {
        // code here
    long long num1 = 0,num2 = 0;
    int m = 1e9+7;
    while(first){
        num1 = (num1*10 + first->data)%m;
        first = first->next;
    }
    while(second){
        num2 = (num2*10 + second->data)%m;
        second = second->next;
    }
    return (num1*num2)%m;
}

int main(){
    Node* head1 = new Node(9);
    head1->next = new Node(4);
    head1->next->next = new Node(6);
    Node* head2 = new Node(8);
  	head2->next = new Node(4);
    cout << multiplyTwoLists(head1, head2) << endl;

    return 0;
}