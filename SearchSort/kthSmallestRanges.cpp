#include <bits/stdc++.h> 
using namespace std;
vector<int> kthSmallest(vector<vector<int>> &ranges, vector<int> &queries) {
	// Write your code here.
	sort(ranges.begin(), ranges.end());
	vector<pair<int,int>> merged;
	int curStart;
	int curEnd = -1;
	for(int i=0;i<ranges.size();i++){
		if(ranges[i][0]>curEnd){
			if(curEnd!=-1){
				merged.push_back({curStart, curEnd});
			}
			curStart = ranges[i][0];
		}
		curEnd = max(curEnd, ranges[i][1]);
	}
	merged.push_back({curStart, curEnd});
	int p = merged.size();
	vector<int> pref(p,-1);
	pref[0] = merged[0].second - merged[0].first + 1;
	for(int i=1;i<p;i++){
		pref[i] = pref[i-1] + merged[i].second - merged[i].first + 1;
	}
	vector<int> res;
	for(int k:queries){
		int i = lower_bound(pref.begin(),pref.end(), k) - pref.begin();
		if(i == pref.size()){
			res.push_back(-1);
			continue;
		}
		if(i==0){
			res.push_back(merged[0].first + k - 1);
		}
		else{
			int r = k - pref[i-1];
			res.push_back(merged[i].first + r - 1);
		}
	}
	return res;
}
int main(){
    vector<vector<int>> ranges = {{5, 7}, {6, 8}, {3, 6}, {10, 11}, {15, 15}};
    vector<int> queries = {4,2,8};
    vector<int> res = kthSmallest(ranges, queries);
    for(int n: res) cout<<n<<" ";
}