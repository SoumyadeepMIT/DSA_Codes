#include <bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n)
{
   //   Write your code here
   int c0 = 0;
   int c1 = 0;
   int c2 = 0;
   for(int i=0;i<n;i++){
      if(arr[i]==0) c0++;
      else if(arr[i] == 1)c1++;
      else c2++;
   }
   for(int i=0;i<n;i++){
      if(c0>0){
         arr[i] = 0;
         c0--;
      }
      else if(c1>0){
         arr[i] = 1;
         c1--;
      }
      else if(c2>0){
         arr[i] = 2;
         c2--;
      }
   }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort012(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}