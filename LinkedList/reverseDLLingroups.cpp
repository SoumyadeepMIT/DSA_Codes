#include <bits/stdc++.h> 
using namespace std;
class Node {
 public:
    int data ;
    Node *next ;
    Node* prev;

    Node(int x) {
        data = x ;
        next = NULL ;
        prev = NULL;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* reverseDLLInGroups(Node* head, int k)
{	
    // Write your code here. 
	if(head == NULL) return head;
	Node* nh = NULL;
	Node* curr = head;
	Node* tail = NULL;
	while(curr){
		Node* gh = curr;
		Node* nex = NULL;
		Node* prev = NULL;
		int i=0;
		while(i<k && curr){
			nex = curr->next;
			curr->next = prev;
			curr->prev = nex;
			prev = curr;
			curr = nex;
			i++;
		}
		if(nh == NULL) nh = prev;
		if(tail!=NULL){
			tail->next = prev;
			prev->prev = tail;
		}
		tail = gh;
	}
	return nh;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head = reverseDLLInGroups(head, 2);
    printList(head);

    return 0;
}