#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n; cin>>n; int v[n][n];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++) cin>>v[i][j];
	}
	int a[n];
	for(int i = 2; i<n; i++){
		a[i-2]=sqrt((long long)v[i][i-2]*v[i-1][i-2]/v[i][i-1]);
	}
	a[n-2]=sqrt((long long)v[n-1][n-2]*v[0][n-2]/v[n-1][0]);
	a[n-1]=sqrt((long long)v[n-1][0]*v[n-1][1]/v[1][0]);
	for(int i = 0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}