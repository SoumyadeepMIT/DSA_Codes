#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void help(vector<int>& arr, vector<int>& inorder,int i){
    int n = arr.size();
    if(i >= n) return;
    help(arr, inorder, 2*i+1);
    inorder.push_back(arr[i]);
    help(arr, inorder, 2*i+2);
}
int minSwaps(vector<int>& arr) {
    vector<int> inorder;
    help(arr, inorder, 0);
    vector<pair<int, int>> t(inorder.size());
    int ans = 0;
    
    for (int i = 0; i < inorder.size(); i++)
        t[i] = {inorder[i], i};
    
    
    sort(t.begin(), t.end());
    
    for (int i = 0; i < t.size(); i++) {
        if (i == t[i].second)
            continue;
        
        else {
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }
        
        if (i != t[i].second)
            --i;  
        
        ans++;
    }
    
    return ans;
}

int main(){
    vector<int> arr = { 5, 6, 7, 8, 9, 10, 11 };
    cout << minSwaps(arr) << endl;
}