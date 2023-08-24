#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a, n) 42
#define debug(...) 42
#endif


const int N = 2005;

vector<vector<int>> T(N);
vector<int> mark(N), I(N);

int qry(int u, int v){
	cout << "? " << u << " " << v << endl << flush;
	cin >> u; return u;
}

void remove(int u, int p){
	mark[u] = 1;
	for(auto v : T[u]) if(v != p && !mark[v]) remove(v, u);
}

void code(int TC){
	int n; cin >> n;
	int mxI = 0, uI = 0, edges = 0, rt = 1;
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
		I[u] += 1, I[v] += 1;
		if(I[u] > mxI) mxI = I[u], uI = u;
		if(I[v] > mxI) mxI = I[v], uI = v;
		edges = edges + 1;
	}
	while(true){
		if(edges == 0){
			cout << "! " << rt << endl << flush;
			return;
		}
		else if(edges == 1){
			for(auto u : T[rt]){
				rt = qry(rt, u);
			}
			edges = 0;
		}
		else{
			rt = qry(T[uI][0], T[uI][1]);
			if(rt != uI) remove(uI, rt);
			else remove(T[uI][0], rt), remove(T[uI][1], rt);
			I.assign(N, 0);
			mxI = 0, uI = 0, edges = 0;
			vector<vector<int>> newT(N);
			for(int i = 1; i <= n; i++){
				for(int j = 0; j < T[i].size(); j++){
					if(mark[T[i][j]] || T[i][j] < i) continue;
					debug(T[i][j], i);
					newT[T[i][j]].push_back(i);
					newT[i].push_back(T[i][j]);
					I[i] += 1, I[T[i][j]] += 1;
					if(I[i] > mxI) mxI = I[i], uI = i;
					if(I[T[i][j]] > mxI) mxI = I[T[i][j]], uI = T[i][j];
					edges = edges + 1;
				}
			}
			T = newT;
		}
	}
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	int TT = 1;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}