#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int survive(int health, int armor){
	int t = 1;
	health+=3;
	armor+=2;
	while(1){
		if(health>5 && armor>10){
			health-=2;
			armor-=8;
			t+=2;
		}
		else if(health>20 && armor<=10){
			health-=17;
			armor+=7;
			t+=2;
		}
		else{
			return t;
		}
	}
	return -1;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int health, armor;
		cin>>health>>armor;
		cout<<survive(health, armor)<<endl;
	}
	return 0;
}