#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


Node* dfs(Node* node, unordered_map<Node*, Node*>& um){
    if(!node) return NULL;
    if(um.find(node) != um.end()) return um[node];
    Node* newNod = new Node(node->val);
    um[node] = newNod;
    for(Node* neigh: node->neighbors){
        newNod->neighbors.push_back(dfs(neigh, um));
    }
    return newNod;
}
Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> um;
    Node* clone = dfs(node, um);
    return clone;
}

int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);
    Node* clone = cloneGraph(node1);
    cout << clone->val << endl;
    for(Node* neigh: clone->neighbors){
        cout << neigh->val << " ";
        for(Node* neigh2: neigh->neighbors){
            cout << neigh2->val << " ";
        }
        cout << endl;
    }
    return 0;
}