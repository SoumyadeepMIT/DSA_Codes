#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    vector<int> res;
    for(int i=k;i<arr.size();i++) res.push_back(arr[i]);
    for(int i=0;i<k;i++) res.push_back(arr[i]);
    return res;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int k = 2;
    vector<int> res = rotateArray(arr,k);
    for(int n:res){
        cout<<n<<" ";
    }
}