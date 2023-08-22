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
	int n; cin >> n;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; i++){
		int l, r; cin >> l >> r;
		v[i] = {l, r};
	}
	sort(v.begin(), v.end());
	vector<pair<int,int>> s;
	for(int i = 0; i < n; i++){
		int c = i;
		while(i + 1 < n  && v[i + 1].ff <= v[c].ss) i = i + 1, s.push_back({v[i].ff, v[i].ss});
	}
	n = s.size();
	for(int i = 1; i < n; i++){
		if(s[i].ff <= s[i - 1].ss){
			cout << "NO" << endl;
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