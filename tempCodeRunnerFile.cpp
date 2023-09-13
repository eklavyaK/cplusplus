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





void code(int TC){
	int n, k; cin >> n >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(k == 1){
		for(int i = 1; i <= n; i++){
			if(a[i] != i){
				cout << "NO" << endl;
				return;
			}
		}
		cout << "YES" << endl;
		return;
	}
	vector<int> done(n + 1);
	bool ans = 0;
	for(int i = 1; i <= n; i++){
		if(done[i]) continue;
		int l = i, f = i;
		for(int j = 1; j <= k; j++){
			if(done[l]){
				if(done[l] == i){
					cout << "NO" << endl;
					return;
				}
				else break;
			}
			if(j != k) done[l] = i;
			f = l;
			l = a[l];
		}
		debug(l, f, i);
		if(l == i) done[f] = i;
		debug(done);
	}
	for(int i = 1; i <= n; i++){
		if(!done[i]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	cout.precision(30);
	int TT = 1; cin >> TT;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}