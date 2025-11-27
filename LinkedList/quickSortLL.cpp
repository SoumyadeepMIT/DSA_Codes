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

Node* getTail(Node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both newHead and newEnd will be updated
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the pivot becomes new head
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        } else { 
            // Move nodes greater than pivot to end
            if (prev)
                prev->next = cur->next;

            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update new end to current last node
    (*newEnd) = tail;

    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    Node* pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is not the smallest element, recursively sort the left part
    if (newHead != pivot) {
        // Find the node before pivot to end left sublist
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for left list
        newHead = quickSortRecur(newHead, tmp);

        // Join the two lists
        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    // Recur for right sublist
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

Node* quickSort(Node* head) {
    Node* tail = getTail(head);
    return quickSortRecur(head, tail);
}

int main(){
    Node *head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head = quickSort(head);
    printList(head);
    return 0;
}