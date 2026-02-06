#include <bits/stdc++.h>
using namespace std;
class kStacks {

    // main array to store elements
    int *arr;
    vector<int> top;
    vector<int> next;
    int fs;

  public:
    kStacks(int n, int k) {
        // initialize data structures for k stacks
        fs = 0;
        arr = new int[n];
        top.assign(k, -1);
        next.assign(n,-1);
        for(int i=0;i<n-1;i++){
            next[i] = i+1;
        }
    }

    void push(int x, int i) {
        // push element x into stack i
        if(fs == -1) return;
        
        //Find the freespot
        int ind = fs;
        
        //update the free spot
        fs = next[ind];
        
        //assign value to the index
        arr[ind] = x;
        
        //Update the next top for that index
        next[ind] = top[i];
        
        //assign the top of that stack the new index
        top[i] = ind;
        return;
    }

    int pop(int i) {
        // pop element from stack i
        if(top[i] == -1) return -1;
        
        //Get the top index
        int ind = top[i];
        
        //Update the top of stack to the next top stored in that index
        top[i] = next[ind];
        
        //Get the value
        int x = arr[ind];
        
        next[ind] = fs;
        
        fs = ind;
        return x;
    }
};

int main(){
    kStacks ks(10, 3);
    ks.push(15, 2);
    ks.push(45, 2);
    cout<<ks.pop(2)<<endl;
    cout<<ks.pop(2)<<endl;
    return 0;
}