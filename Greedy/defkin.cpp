#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calcArea(int w, int h, vector<int>& posx, vector<int>& posy){
	int nx = posx.size();
	int ny = posy.size();
	if(nx==0) return w*h;
	sort(posx.begin(), posx.end());
	sort(posy.begin(), posy.end());
	int mw = max(posx[0]-1, w-posx[nx-1]);
	int my = max(posy[0]-1, h - posy[ny-1]);
	for(int i=1;i<nx;i++){
		mw = max(posx[i]-posx[i-1]-1, mw);
	}
	for(int i=1;i<ny;i++){
		my = max(posy[i]-posy[i-1]-1, my);
	}
	return mw*my;
}
int main() {
	// your code goes here
    int t;
	cin>>t;
	while(t--){
        int w,n,h;
		cin>>w>>h>>n;
		vector<int> posx;
		vector<int> posy;
		while(n--){
            int x,y;
			cin>>x>>y;
			posx.push_back(x);
			posy.push_back(y);
		}
		cout<<calcArea(w,h,posx,posy)<<endl;
	}
	return 0;
}