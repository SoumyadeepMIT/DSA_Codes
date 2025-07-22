#include <iostream>
#include <vector>
using namespace std;

void segregateElements(vector<int>& arr) {
    // Your code goes here
    vector<int> temp;
    for(int n:arr){
        if(n>=0) temp.push_back(n);
    }
    for(int n:arr){
        if(n<0) temp.push_back(n);
    }
    for(int i=0;i<temp.size();i++) arr[i] = temp[i];
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    segregateElements(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}