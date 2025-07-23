#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b) {
    // code here
    vector<int> res;
    unordered_set<int> us;
    for(int n:a) us.insert(n);
    for(int n:b) us.insert(n);
    for(int n:us) res.push_back(n);
    return res;
}

int main() {

    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = findUnion(a, b);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}