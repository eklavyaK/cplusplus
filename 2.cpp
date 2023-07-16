#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a,n) 42
#define debug(...) 42
#endif

const int N = 1e3;
int par[N], node[N][3], J[N][N], n, k, P = 0;
void calc(){
	for(int i=0;i<k;i++){
		vector<int> R;
		for(int j=0;j<n;j++) if(!par[J[i][j]]) R.push_back(J[i][j]);
		int sz = R.size();
		for(int j=0;j<sz-2;j++){
			if(node[R[j+1]][0]==min(R[j],R[j+2]) && node[R[j+1]][1]==max(R[j],R[j+2])) node[R[j+1]][2]++;
			else node[R[j+1]][0] = min(R[j],R[j+2]), node[R[j+1]][1] = max(R[j],R[j+2]), node[R[j+1]][2] = 1;
		}
	}
	for(int i=1;i<=n;i++) if(node[i][2]==k) par[node[i][0]] = par[node[i][1]] = i, P += 2;
}
void code(int TC){
	cin>>n>>k;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++) cin>>J[i][j];
	}
	for(int i=0;i<(n+1)/2;i++) calc();
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(!par[i]) q.push(i);
	}
	while(q.size()>2){
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		int c = q.front(); q.pop();
		par[a] = par[b] = c;
		q.push(c);
	}
	while(!q.empty()) par[q.front()] = -1, q.pop();
	for(int i=1;i<=n;i++) cout<<par[i]<<" ";cout<<endl;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}