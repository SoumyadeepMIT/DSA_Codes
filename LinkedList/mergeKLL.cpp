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

Node* mergeTwo(Node* head1, Node* head2){
    if(head1==nullptr) return head2;
    if(head2==nullptr) return head1;
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    while(head1 && head2){
        if(head1->data<head2->data){
            curr->next = new Node(head1->data);
            curr = curr->next;
            head1 = head1->next;
        }
        else{
            curr->next = new Node(head2->data);
            curr = curr->next;
            head2 = head2->next;
        }
    }
    while(head1){
        curr->next = new Node(head1->data);
        curr = curr->next;
        head1 = head1->next;
    }
    while(head2){
        curr->next = new Node(head2->data);
        curr = curr->next;
        head2 = head2->next;
    }
    return dummy->next;
}
Node* mergeRecur(vector<Node* >& arr, int i, int j){
    if(i==j) return arr[i];
    int mid = i + (j-i)/2;
    Node* head1 = mergeRecur(arr,i,mid);
    Node* head2 = mergeRecur(arr,mid+1, j);
    return mergeTwo(head1, head2);
}
Node* mergeKLists(vector<Node*>& arr) {
    // code here
    return mergeRecur(arr, 0, arr.size()-1);
}

int main(){
    vector<Node*> arr(3);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    
    Node* head = mergeKLists(arr);

    printList(head);

    return 0;
}