#include <iostream>
#include <vector>
#include <string>

using namespace std;
void reverseArray(vector<int> &arr , int m) {
    // Write your code here
    int r=arr.size() - 1;
    int l = m+1;
    while(l<r){
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
        l++;
        r--;
    }       	
}

int main(){
    vector<int> arr;
    int m;
    int n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    reverseArray(arr, m);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;

}