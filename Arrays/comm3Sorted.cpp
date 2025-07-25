#include <bits/stdc++.h>
using namespace std;
vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,vector<int> &arr3) {
    // Code Here
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();
    int i=0,j=0,k=0;
    vector<int> res;
    while(i<n1 && j<n2 && k<n3){
        if(arr1[i]==arr2[j] && arr1[i]==arr3[k]){
            int temp = arr1[i];
            while(i<n1 && arr1[i]==temp) i++;
            while(j<n2 && arr2[j]==temp) j++;
            while(k<n3 && arr3[k]==temp) k++;
            res.push_back(temp);
        }
        else if (min({arr1[i], arr2[j], arr3[k]}) == arr1[i]) i++;
        else if (min({arr1[i], arr2[j], arr3[k]}) == arr2[j]) j++;
        else k++;
    }
    return res;
}

int main(){
    vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};
    vector<int> res = commonElements(arr1,arr2,arr3);
    for(int n: res) cout<<n<<" "; 
}