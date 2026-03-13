#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int, vector<int>>& um, unordered_map<int,int>& intime, unordered_map<int,int>& outtime, unordered_map<int, bool>& vis, int& time, int nod){
	vis[nod] = true;
	intime[nod] = time++;
	for(int nei: um[nod]){
		if(!vis[nei]){
			dfs(um, intime, outtime, vis, time, nei);
		}
	}
	outtime[nod] = time++;
}
bool check(unordered_map<int, int>& intime, unordered_map<int, int>& outtime, int x, int y){
	if(intime[x]<intime[y] && outtime[x]>outtime[y]) return true;
	return false;
}
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	unordered_map<int, vector<int>> um;
	for(int i=0;i<num-1;i++){
		int a, b;
		cin>>a>>b;
		um[a].push_back(b);
		um[b].push_back(a);
	}
	unordered_map<int,int> intime;
	unordered_map<int,int> outtime;
	unordered_map<int, bool> vis;
	int time = 0;
	dfs(um, intime, outtime, vis, time, 1);
	int queries;
	cin>>queries;
	for(int i=0;i<queries;i++){
		int d,x,y;
		cin>>d>>x>>y;
		if(d==0){
			if(check(intime, outtime, x, y)){
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
		}
		else{
			if(check(intime, outtime, y, x)){
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}