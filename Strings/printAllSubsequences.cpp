#include <bits/stdc++.h> 
using namespace std;
void gen(string str,vector<string>& res, string cur,int i){
	if(i==str.length()){
		if(cur.length()>0) res.push_back(cur);
		return;
	}
	gen(str,res,cur+str[i],i+1);
	gen(str,res,cur,i+1);
}
vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> res;
	gen(str,res,"",0);
	return res;
}

int main(){
    string str = "abc";
    vector<string> res = subsequences(str);
    for(string s:res) cout<<s<<" ";
    return 0;
}