#include <bits/stdc++.h>
using namespace std;

bool equalPartition(vector<int> &arr)
{
    // code here
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 != 0)
        return false;
    sum = sum / 2;
    int n = arr.size();
    vector<bool> prev(sum + 1, false);
    vector<bool> curr(sum + 1);
    prev[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] > j)
            {
                curr[j] = prev[j];
            }
            else
            {
                curr[j] = prev[j - arr[i - 1]] || prev[j];
            }
        }
        prev = curr;
    }
    return prev[sum];
}

int main() {
    vector<int> arr = {1, 5, 11, 5};
    if (equalPartition(arr)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }
    return 0;
}