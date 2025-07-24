#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &arr) 
{
    int n = arr.size() - 1;
    int sum = 0;
    for(int i:arr){
        sum+=i;
    }
    int tot = n*(n+1)/2;
    return sum - tot;
}


int main(){
    vector<int> arr = {6, 3, 1, 5, 4, 3, 2};
    cout<<findDuplicate(arr);
}