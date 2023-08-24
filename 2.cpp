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


const int N = 1e6 + 5;

vector<pair<int, pair<int,int>>> pos(N);

void code(int TC){
	int n, m, dx, dy; cin >> n >> m >> dx >> dy;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		for(int j = -2; j <= 2; j++){
			pos[(((x * dy - y * dx) % n) + n) % n].ff += 1;
			pos[(((x * dy - y * dx) % n) + n) % n].ss  = {x, y};
		}
	}
	int mx = 0, ansx = 0, ansy = 0;
	for(auto [c, coor] : pos){
		if(c > mx) mx = c, ansx = coor.ff, ansy = coor.ss;
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