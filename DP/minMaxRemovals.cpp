#include <bits/stdc++.h>
using namespace std;
int findInd(int key, int i, 
        int n, int k, vector<int>& arr)
{
    int start, end, mid, ind = -1;
    
    // Initialising start to i + 1
    start = i + 1;
    
    // Initialising end to n - 1
    end = n - 1;
    
    // Binary search implementation
    // to find the rightmost element
    // that satisfy the condition
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        
        // Check if the condition satisfies 
        if (arr[mid] - key <= k)
        {   
            
            // Store the position
            ind = mid;
            
            // Make start = mid + 1
            start = mid + 1;
        }
        else
        {
            // Make end = mid
            end = mid-1;
        }
    }
    
    // Return the rightmost position
    return ind;
}
int removals(vector<int>& arr, int k) {
    int n = arr.size();
    // Code here
        int i, j, ans = n - 1;

    // Sort the given array
    sort(arr.begin(), arr.end());
    
    // Iterate from 0 to n-1
    for (i = 0; i < n; i++)
    {
        
        // Find j such that 
        // arr[j] - arr[i] <= k
        j = findInd(arr[i], i, n, k, arr);
        
        // If there exist such j 
        // that satisfies the condition
        if (j != -1)
        {
            // Number of elements
            // to be removed for this
            // particular case is 
            // (j - i + 1)
            ans = min(ans, n - (j - i + 1));
        }
    }
    
    // Return answer
    return ans;
}
int main(){
    vector<int> arr = {1, 3, 4, 9, 10};
    int k = 2;
    cout << removals(arr, k) << endl;
    return 0;
}