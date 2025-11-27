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

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
    vector<pair<int,int>> res;
    Node* curr = head;
    while(curr->next!=nullptr) curr = curr->next;
    Node* first = head;
    Node* last = curr;
    while(first->data<last->data){
        if(first->data + last->data == target) {
            res.push_back({first->data, last->data});
            first = first->next;
            last = last->prev;
        }
        else if(first->data + last->data <target) first = first->next;
        else last = last->prev;
    }
    return res;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;

    int target = 7;
    vector<pair<int, int>> pairs = findPairsWithGivenSum(head, target);

    if (pairs.empty()) {
        cout << "No pairs found." << endl;
    }
    else {
        for (auto &pair : pairs) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    return 0;
}