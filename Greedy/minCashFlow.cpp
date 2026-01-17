#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n) {
    // code here
    vector<int> person(n, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            person[i]-=transaction[i][j];
            person[j]+=transaction[i][j];
        }
    }
    priority_queue<pair<int,int>> debt,cred;
    for(int i=0;i<n;i++){
        if(person[i]<0){
            debt.push({abs(person[i]), i});
        }
        else if(person[i]>0){
            cred.push({person[i], i});
        }
    }
    vector<vector<int>> res(n,vector<int>(n,0));
    while(!debt.empty()){
        int dbId = debt.top().second;
        int dbam = debt.top().first;
        int crId = cred.top().second;
        int cram = cred.top().first;
        debt.pop();
        cred.pop();
        int tram = min(dbam,cram);
        res[dbId][crId] = tram;
        dbam -= tram;
        cram -= tram;
        if(dbam>0){
            debt.push({dbam,dbId});
        }
        if(cram>0){
            cred.push({cram,crId});
        }
    }
    return res;
}
int main() {
    int n = 3;
    vector<vector<int>> transaction = {
        {0, 1000, 2000},
        {0, 0, 5000},
        {0, 0, 0}};

    vector<vector<int>> result = minCashFlow(transaction, transaction.size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}