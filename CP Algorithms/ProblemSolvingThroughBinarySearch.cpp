#include<bits/stdc++.h>
/*Using binary search method to solve the problem.

The problem statement:-------> https://codeforces.com/contest/1623/problem/C

This method is very efficient when we want a fixed value from a array after manipulating is dynamically.*/

using namespace std;

int a[200001],n;
bool possibility(int x){
	vector<int> v(a,a+n);
	for(int i=n-1;i>=2;i--){
		if(v[i]<x) return false;
		int k = min(a[i],v[i]-x)/3;
		v[i-1]+=k;v[i-2]+=k*2;      //Here we're manipulating the array to know that it is possible to have x as minimum
	}
	return v[0]>=x & v[1]>=x;      //If it's possible to get x as minimum then we increase the value of mid variable
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.precision(28);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0){
		cin>>n;
		for(int i = 0; i<n; i++)cin>>a[i];
		int l = 0,r=*max_element(a,a+n); //Here we have taken the value of max element because value of ans cannot be more than max value.
		while(l<r){
			int mid = l+(r-l+1)/2;
			if(possibility(mid))l=mid;
			else r=mid-1;
		}
		cout<<l<<endl;
	}
	return 0;
}