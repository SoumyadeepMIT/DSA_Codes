#include <bits/stdc++.h>
using namespace std;
int pageFaults(int n, int c, int pages[]) {
    // code here
    vector<int> mem;
    int res = 0;
    for(int i=0; i<n;i++){
        auto it = find(mem.begin(), mem.end(), pages[i]);
        if(it == mem.end()){
            res++;
            if(mem.size() == c){
                mem.erase(mem.begin());
            }
            mem.push_back(pages[i]);
        }
        else{
            mem.erase(it);
            mem.push_back(pages[i]);
        }
    }
    return res;
}
int main(){
    int n = 9, c= 4;
    int pages[] = {5, 0, 1, 3, 2, 4, 1, 0, 5};
    cout<<pageFaults(n, c, pages);
}