#include <bits/stdc++.h> 
using namespace std;
vector<double> getMedian(vector<int> &arr) {
    // code here
    priority_queue<int> lmax;
    priority_queue<int, vector<int>, greater<int>> rmin;
    vector<double> res;
    for(int i=0;i<arr.size();i++){
        lmax.push(arr[i]);
        int temp = lmax.top();
        lmax.pop();
        rmin.push(temp);
        while(rmin.size()>lmax.size()){
            temp = rmin.top();
            rmin.pop();
            lmax.push(temp);
        }
        if(lmax.size() == rmin.size()){
            res.push_back(((double)(lmax.top()) + rmin.top())/2.0);
        }
        else{
            res.push_back(lmax.top());
        }
    }
    return res;
}
int main(){
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> res = getMedian(arr);
    for(double n : res){
        cout<<n<<' ';
    }
    return 0;
}