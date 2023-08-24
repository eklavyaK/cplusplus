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
	int n, m, dx, dy; cin >> n >> m >> dx >> dy;
	vector<int> c(n);
	vector<pair<int,int>> p(n);
	vector<int> mod(n);
	for(int i = 0; i < n; i++){
		mod[(i * dx) % n] = i * dy % n;
	}
	for(int j = 0; j < m; j++){
		int x, y; cin >> x >> y;
		c[((y - mod[x]) % n + n) % n] += 1;
		p[((y - mod[x]) % n + n) % n] = {x, y};
	}
	int mx = 0, ansx = 0, ansy = 0;
	for(int i = 0; i < n; i++){
		if(c[i] > mx) mx = c[i], ansx = p[i].ff, ansy = p[i].ss;
	}
	cout << ansx << " " << ansy << endl;
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