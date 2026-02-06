#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
  public:
    Node* head;
    Node* tail;
    int sz;
    int curr;
    unordered_map<int, Node*> um;
    LRUCache(int cap) {
        // code here
        sz = cap;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        curr = 0;
    }
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (um.find(key) == um.end()) return -1;
    
        Node* node = um[key];
        remove(node);
        insertAfterHead(node);
        return node->val;
    }

        
    void put(int key, int val) {
        if (um.find(key) != um.end()) {
            Node* node = um[key];
            node->val = val;
            remove(node);
            insertAfterHead(node);
            return;
        }
    
        if (curr == sz) {
            Node* lru = tail->prev;
            um.erase(lru->key);
            remove(lru);
            delete lru;
            curr--;
        }
    
        Node* node = new Node(key, val);
        insertAfterHead(node);
        um[key] = node;
        curr++;
    }

};

int main() {
    LRUCache cache(2); // Capacity of 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // Outputs 1

    cache.put(3, 3); // Evicts key 2
    cout << cache.get(2) << endl; // Outputs -1 (not found)

    cache.put(4, 4); // Evicts key 1
    cout << cache.get(1) << endl; // Outputs -1 (not found)
    cout << cache.get(3) << endl; // Outputs 3
    cout << cache.get(4) << endl; // Outputs 4

    return 0;
}