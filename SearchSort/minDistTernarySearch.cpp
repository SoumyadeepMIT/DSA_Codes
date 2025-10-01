#include <bits/stdc++.h> 
using namespace std;
double find(int a,int b,int c, double x, vector<vector<int>> &points){
	double y = a*x+c;
	y = -y/b;
	double sum = 0;
	for(vector<int> point: points){
		sum += sqrt((x-point[0])*(x-point[0]) + (y-point[1])*(y-point[1]));
	}
	return sum;
}
double optimumDistance(int a, int b, int c, vector<vector<int>> &points, int n){
	// Write your code here
	double low = -1e6;
	double hi = 1e6;
	while((hi-low)>1e-6){
		double mid1 = low + (hi-low)/3;
		double mid2 = hi - (hi-low)/3;
		double d1 = find(a,b,c,mid1,points);
		double d2 = find(a,b,c,mid2,points);
		if(d1<d2) hi=mid2;
		else low = mid1;
	}
	double x = (low + hi)/2;
	return find(a,b,c,x, points);
}
int main(){
    int a = 3, b = 2, c = 5;
    vector<vector<int>> points = {{1 ,-1},{2, 3},{4, 4},{5 ,-1},{3, 2}};
    cout<<optimumDistance(a,b,c,points,points.size());
    return 0;
}