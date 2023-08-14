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
	int n, m; cin >> n >> m;
	vector<int> ans(n), s(n);
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> s[i] >> v[i].ff, v[i].ss = i;
	sort(v.begin(), v.end());
	int l = 1;
	for(int i = 0; i < n; i++){
		if(v[i].ff == 2) break;
		if(l > m){
			cout << -1 << endl;
			return;
		}
		else ans[v[i].ss] = l, l += s[v[i].ss];
	}
	int r = l + 1;
	for(int i = 0; i < n; i++){
		if(v[i].ff == 1) continue;
		if(l < r){
			if(l > m || l + (v[i].ss - 1) * 2){
				cout << -1 << endl;
				return;
			}
		}
		else if(r < l){
			if(r > m){
				cout << -1 << endl;
				return;
			}
		}
	}
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int TT = 1; cin >> TT;
	for (int TC = 1; TC <= TT; TC++) 
		code(TC);
	return 0;
}